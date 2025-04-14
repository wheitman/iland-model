from stable_baselines3.common.env_checker import check_env
from forest_env import ForestEnv
import random
import os
import gymnasium as gym
import numpy as np
import torch
import optuna
from stable_baselines3 import SAC
from stable_baselines3.common.env_util import make_vec_env
from stable_baselines3.common.callbacks import BaseCallback, EvalCallback
from stable_baselines3.common.monitor import Monitor
from stable_baselines3.common.vec_env import DummyVecEnv, VecNormalize
from stable_baselines3.common.results_plotter import load_results, ts2xy
from stable_baselines3.common.noise import NormalActionNoise
from typing import Dict, Any, Union
from tqdm import trange


shortnames = [
    "abal", "acca", "acpl", "acps", "algl", "alin", "alvi", "bepe",
    "cabe", "casa", "coav", "fasy", "frex", "lade", "piab", "pice",
    "pimu", "pini", "pisy", "poni", "potr", "psme", "qupe", "qupu",
    "quro", "rops", "saca", "soar", "soau", "tico", "tipl", "ulgl",
]

# Take every 10th name for a smaller set
shortnames = shortnames[::10]


def set_all_seeds(seed):
    """Set all seeds for reproducibility"""
    # Python's built-in random module
    random.seed(seed)

    # NumPy
    np.random.seed(seed)

    # Gymnasium
    gym.utils.seeding.np_random(seed)

    # PyTorch
    torch.manual_seed(seed)
    torch.cuda.manual_seed(seed)
    torch.cuda.manual_seed_all(seed)  # For multi-GPU
    torch.backends.cudnn.deterministic = True
    torch.backends.cudnn.benchmark = False

    # Environment variables
    os.environ["PYTHONHASHSEED"] = str(seed)


class SaveOnBestTrainingRewardCallback(BaseCallback):
    """
    Callback for saving a model based on the training reward.
    """
    def __init__(self, check_freq, log_dir, verbose=1):
        super().__init__(verbose)
        self.check_freq = check_freq
        self.log_dir = log_dir
        self.save_path = os.path.join(log_dir, "best_model")
        self.best_mean_reward = -np.inf

    def _init_callback(self) -> None:
        # Create folder if needed
        if self.save_path is not None:
            os.makedirs(self.save_path, exist_ok=True)

    def _on_step(self) -> bool:
        if self.n_calls % self.check_freq == 0:
            # Retrieve training reward
            x, y = ts2xy(load_results(self.log_dir), "timesteps")
            if len(x) > 0:
                # Mean training reward over the last 100 episodes
                mean_reward = np.mean(y[-100:])
                if self.verbose > 0:
                    print(
                        "Best mean reward: {:.2f} - Last mean reward per episode: {:.2f}".format(
                            self.best_mean_reward, mean_reward
                        )
                    )

                # New best model, save it
                if mean_reward > self.best_mean_reward:
                    self.best_mean_reward = mean_reward
                    if self.verbose > 0:
                        print("Saving new best model at {} timesteps".format(x[-1]))
                        print("Saving new best model to {}.zip".format(self.save_path))
                    self.model.save(self.save_path)

        return True


class TrialEvalCallback(EvalCallback):
    """
    Callback used for evaluating and reporting a trial during optimization.
    """
    def __init__(
        self,
        eval_env,
        trial,
        n_eval_episodes=5,
        eval_freq=100,
        deterministic=True,
        verbose=0,
    ):
        super().__init__(
            eval_env=eval_env,
            n_eval_episodes=n_eval_episodes,
            eval_freq=eval_freq,
            deterministic=deterministic,
            verbose=verbose,
        )
        self.trial = trial
        self.eval_idx = 0
        self.is_pruned = False

    def _on_step(self) -> bool:
        if self.eval_freq > 0 and self.n_calls % self.eval_freq == 0:
            super()._on_step()
            self.eval_idx += 1
            # Report intermediate objective value to Optuna
            self.trial.report(self.last_mean_reward, self.eval_idx)
            # Prune trial if needed
            if self.trial.should_prune():
                self.is_pruned = True
                return False
        return True


def sample_sac_params(trial: optuna.Trial) -> Dict[str, Any]:
    """
    Sampler for SAC hyperparameters with more conservative ranges
    suited for computationally expensive environments.
    """
    # Hyperparameters to tune with narrower, more conservative ranges
    learning_rate = trial.suggest_float("learning_rate", 1e-4, 5e-4, log=True)
    buffer_size = trial.suggest_int("buffer_size", 5000, 50000)  # Much smaller buffer
    learning_starts = trial.suggest_int("learning_starts", 10, 200)  # Start learning earlier
    batch_size = trial.suggest_int("batch_size", 64, 256)
    tau = trial.suggest_float("tau", 0.002, 0.05, log=True)
    gamma = trial.suggest_float("gamma", 0.95, 0.995)  # Narrower discount factor range
    
    # Reduce train_freq and gradient_steps to prevent freezing
    train_freq = trial.suggest_int("train_freq", 1, 4)
    gradient_steps = trial.suggest_int("gradient_steps", 1, 3)
    
    # Simpler network architecture choices
    net_arch_type = trial.suggest_categorical("net_arch", ["small"])
    net_arch = {
        "small": [64, 64],
        "medium": [128, 128],
    }[net_arch_type]
    
    # Simplify by not using action noise in initial trials
    use_action_noise = False  # trial.suggest_categorical("use_action_noise", [False])
    action_noise = None
    
    # Auto entropy coefficient (True) or fixed value (False)
    auto_ent_coef = trial.suggest_categorical("auto_ent_coef", [True, False])
    ent_coef = "auto" if auto_ent_coef else trial.suggest_float("ent_coef", 0.01, 0.2, log=True)
    
    return {
        "learning_rate": learning_rate,
        "buffer_size": buffer_size,
        "learning_starts": learning_starts,
        "batch_size": batch_size,
        "tau": tau,
        "gamma": gamma,
        "train_freq": train_freq,
        "gradient_steps": gradient_steps,
        "action_noise": action_noise,
        "ent_coef": ent_coef,
        "policy_kwargs": dict(net_arch=net_arch),
    }


def objective(trial):
    """Objective function for Optuna optimization."""
    # Set seed for reproducibility
    set_all_seeds(64)
    
    # Sample hyperparameters with more conservative ranges
    kwargs = sample_sac_params(trial)
    
    # Limit buffer size to prevent memory issues
    kwargs["buffer_size"] = min(kwargs["buffer_size"], 100000)
    
    # Create the base environment
    env = ForestEnv(species_names=shortnames)
    
    # Wrap with Monitor first
    env = Monitor(env)
    
    # Create vectorized environment
    vec_env = DummyVecEnv([lambda: env])
    
    # Apply normalization to the vectorized environment
    vec_env = VecNormalize(vec_env, norm_obs=True, norm_reward=False)
    
    # Create the model
    model = SAC("MlpPolicy", vec_env, verbose=1, **kwargs)
    
    # Use a less frequent evaluation to reduce computational overhead
    eval_freq = 500  # Less frequent evaluation
    
    # Create simple trial evaluation callback
    class SimpleTrialCallback(BaseCallback):
        def __init__(self, trial, eval_freq=500, verbose=1):
            super().__init__(verbose)
            self.trial = trial
            self.eval_freq = eval_freq
            self.last_mean_reward = -float('inf')
            self.eval_idx = 0
            
        def _on_step(self):
            # Only evaluate every eval_freq steps
            if self.n_calls % self.eval_freq == 0:
                self.eval_idx += 1
                # Get current mean reward from monitor
                x, y = ts2xy(load_results(model.env.unwrapped.monitor.dir), "timesteps")
                if len(y) > 0:
                    self.last_mean_reward = np.mean(y[-10:])
                    # Report to Optuna
                    self.trial.report(self.last_mean_reward, self.eval_idx)
                    if self.verbose > 0:
                        print(f"Step {self.n_calls}, Mean reward: {self.last_mean_reward:.2f}")
                    # Check if we should prune
                    if self.trial.should_prune():
                        return False
            return True
    
    eval_callback = SimpleTrialCallback(trial=trial, eval_freq=eval_freq, verbose=1)
    
    try:
        # Train with fewer timesteps for faster trials
        model.learn(total_timesteps=2000, callback=eval_callback, progress_bar=True)
        
        # Free memory
        model.env.close()
        
        # Run explicit garbage collection
        import gc
        gc.collect()
        
        return eval_callback.last_mean_reward
        
    except (AssertionError, ValueError, Exception) as e:
        # Catch more exceptions including timeouts
        print(f"Error during training: {e}")
        
        # Make sure to close the environment
        try:
            model.env.close()
        except:
            pass
            
        # Run explicit garbage collection
        import gc
        gc.collect()
        
        return float("-inf")



def optimize_agent():
    """Optimize the agent using Optuna with settings for debugging freezing issues."""
    study_name = "sac-forest-study"
    
    # Use in-memory storage for debugging to avoid SQLite issues
    try:
        # Create the study with simpler configuration
        study = optuna.create_study(
            direction="maximize",
            sampler=optuna.samplers.TPESampler(seed=64),
            pruner=optuna.pruners.MedianPruner(n_startup_trials=2, n_warmup_steps=5),
        )
        
        # Add a timeout per trial to prevent infinite hanging
        timeout_per_trial = 300  # 5 minutes max per trial
        
        # Run fewer trials for debugging
        n_trials = 5
        
        print(f"Starting optimization with {n_trials} trials, {timeout_per_trial}s timeout per trial")
        
        # Use a shorter global timeout as well
        study.optimize(
            objective, 
            n_trials=n_trials, 
            timeout=1200,  # 20 minutes global timeout
            catch=(Exception,),  # Catch all exceptions to prevent crashes
        )
        
    except KeyboardInterrupt:
        print("Optimization interrupted by user.")
    except Exception as e:
        print(f"Optimization failed with error: {e}")
    
    # Check if we have any completed trials
    if len(study.trials) == 0:
        print("No trials completed. Using default parameters.")
        return {
            "learning_rate": 3e-4,
            "buffer_size": 10000,
            "learning_starts": 100,
            "batch_size": 64,
            "tau": 0.005,
            "gamma": 0.99,
            "train_freq": 1,
            "gradient_steps": 1,
            "ent_coef": "auto",
            "policy_kwargs": dict(net_arch=[64, 64]),
        }
    
    print("Number of finished trials:", len(study.trials))
    
    print("Best trial:")
    trial = study.best_trial
    
    print(f"  Value: {trial.value}")
    print("  Params: ")
    for key, value in trial.params.items():
        print(f"    {key}: {value}")
    
    return trial.params


def train_best_agent(best_params):
    """Train an agent with the best hyperparameters."""
    # Set seed for reproducibility
    set_all_seeds(64)
    
    # Prepare the environment
    save_dir = "sac_checkpoints/"
    os.makedirs(save_dir, exist_ok=True)
    
    # Create vectorized environment
    vec_env = make_vec_env(
        ForestEnv, 
        n_envs=1, 
        env_kwargs={"species_names": shortnames}, 
        monitor_dir=save_dir
    )
    
    # Normalize observations
    vec_env = VecNormalize(vec_env, norm_obs=True, norm_reward=False)
    
    # Convert parameters
    params = best_params.copy()
    
    # Handle action noise
    if "use_action_noise" in params and params["use_action_noise"]:
        action_noise_type = params.pop("action_noise_type", "normal")
        action_noise_std = params.pop("action_noise_std", 0.1)
        action_noise_kwargs = {
            "sigma": action_noise_std * np.ones(3),  # 3 is the action dimension
            "mean": np.zeros(3),
        }
        if action_noise_type == "normal":
            params["action_noise"] = NormalActionNoise(**action_noise_kwargs)
        # else:
        #     params["action_noise"] = OrnsteinUhlenbeckActionNoise(**action_noise_kwargs)
    else:
        params.pop("use_action_noise", None)
        params.pop("action_noise_type", None)
        params.pop("action_noise_std", None)
        params["action_noise"] = None
    
    # Convert net_arch string to actual network architecture
    if "net_arch" in params:
        net_arch_type = params.pop("net_arch")
        net_arch = {
            "small": [64, 64],
            "medium": [256, 256],
        }[net_arch_type]
        params["policy_kwargs"] = dict(net_arch=net_arch)
    
    # Create the model
    model = SAC("MlpPolicy", vec_env, verbose=1, **params)
    
    # Create callback for saving best model
    callback = SaveOnBestTrainingRewardCallback(check_freq=100, log_dir=save_dir, verbose=1)
    
    # Train the model
    model.learn(total_timesteps=50000, progress_bar=True, callback=callback)
    
    # Save the final model
    model.save(os.path.join(save_dir, "sac_forest_final"))
    
    # Also save the vectorized environment statistics
    vec_env.save(os.path.join(save_dir, "vec_normalize.pkl"))
    
    return model, vec_env


def test_agent(model, env, num_episodes=5):
    """Test the trained agent for a few episodes."""
    for episode in range(num_episodes):
        obs, _ = env.reset()
        done = False
        total_reward = 0
        steps = 0
        
        while not done:
            action, _ = model.predict(obs, deterministic=True)
            obs, reward, terminated, truncated, _ = env.step(action)
            done = terminated or truncated
            total_reward += reward
            steps += 1
            env.render()
        
        print(f"Episode {episode+1}: Total Reward: {total_reward}, Steps: {steps}")


if __name__ == "__main__":
    # First optimize hyperparameters
    print("Optimizing hyperparameters...")
    best_params = optimize_agent()
    
    # Then train with the best hyperparameters
    print("\nTraining with best hyperparameters...")
    model, vec_env = train_best_agent(best_params)
    
    # Test the trained agent
    print("\nTesting the trained agent...")
    test_env = ForestEnv(species_names=shortnames, render_mode="human")
    test_agent(model, test_env)
    