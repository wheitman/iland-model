"""
Simplified SAC training script with direct hyperparameters (no optimization).
Use this if the Optuna optimization is freezing.
"""

from stable_baselines3.common.env_checker import check_env
from tqdm import trange
from forest_env import ForestEnv
import os
import numpy as np
import torch
from stable_baselines3 import SAC
from stable_baselines3.common.callbacks import BaseCallback
from stable_baselines3.common.monitor import Monitor
from stable_baselines3.common.vec_env import DummyVecEnv, VecNormalize
from stable_baselines3.common.results_plotter import load_results, ts2xy
from stable_baselines3.common.env_util import make_vec_env
import random


# Set list of tree species names
shortnames = [
    "abal",
    "acca",
    "acpl",
    "acps",
    "algl",
    "alin",
    "alvi",
    "bepe",
    "cabe",
    "casa",
    "coav",
    "fasy",
    "frex",
    "lade",
    "piab",
    "pice",
    "pimu",
    "pini",
    "pisy",
    "poni",
    "potr",
    "psme",
    "qupe",
    "qupu",
    "quro",
    "rops",
    "saca",
    "soar",
    "soau",
    "tico",
    "tipl",
    "ulgl",
]
# shortnames = shortnames[::10]  # Take every 10th name for a smaller set


def set_all_seeds(seed):
    """Set all seeds for reproducibility"""
    random.seed(seed)
    np.random.seed(seed)
    torch.manual_seed(seed)
    torch.cuda.manual_seed(seed)
    torch.backends.cudnn.deterministic = True
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
        if self.save_path is not None:
            os.makedirs(self.save_path, exist_ok=True)

    def _on_step(self) -> bool:
        if self.n_calls % self.check_freq == 0:
            x, y = ts2xy(load_results(self.log_dir), "timesteps")
            if len(x) > 0:
                mean_reward = np.mean(y[-100:])
                if self.verbose > 0:
                    print(f"Num timesteps: {self.num_timesteps}")
                    print(
                        f"Best mean reward: {self.best_mean_reward:.2f} - Last mean reward: {mean_reward:.2f}"
                    )

                # New best model, save it
                if mean_reward > self.best_mean_reward:
                    self.best_mean_reward = mean_reward
                    if self.verbose > 0:
                        print(f"Saving new best model to {self.save_path}")
                    self.model.save(self.save_path)

        return True


def train_sac_agent():
    """Train an SAC agent with direct hyperparameters."""
    # Set seed for reproducibility
    set_all_seeds(42)

    # Create directories
    save_dir = "sac_direct_checkpoints/"
    os.makedirs(save_dir, exist_ok=True)

    # Create and wrap the environment
    env = ForestEnv(species_names=shortnames, num_seedlings=300)

    # Check the environment
    check_env(env, warn=True)

    env.reset()

    # Create vectorized environment with monitoring
    vec_env = make_vec_env(
        ForestEnv,
        n_envs=1,
        env_kwargs={"species_names": shortnames, "num_seedlings": 300},
        monitor_dir=save_dir,
    )

    # Normalize observations (not rewards since it might make learning unstable)
    vec_env = VecNormalize(vec_env, norm_obs=True, norm_reward=False)

    # Define SAC hyperparameters
    # These are conservative settings to prevent freezing
    sac_params = {
        "learning_rate": 3e-4,
        "buffer_size": 10000,  # Smaller buffer to prevent memory issues
        "learning_starts": 100,
        "batch_size": 64,
        "tau": 0.005,  # Soft update coefficient
        "gamma": 0.99,  # Discount factor
        "train_freq": 1,
        "gradient_steps": 1,  # Only 1 gradient step per step to speed up training
        "ent_coef": "auto",  # Automatic entropy tuning
        "verbose": 1,
        "device": "auto",
        "policy_kwargs": dict(net_arch=[64, 64]),  # Smaller network
    }

    # Create the SAC agent
    model = SAC("MlpPolicy", vec_env, **sac_params)
    # model = SAC.load("sac_direct_checkpoints/best_model.zip", env=vec_env)

    # Set up callback for saving the best model
    callback = SaveOnBestTrainingRewardCallback(
        check_freq=1000, log_dir=save_dir, verbose=1
    )

    # Train the agent
    total_timesteps = 30000
    print(f"Training SAC agent for {total_timesteps} timesteps...")

    try:
        model.learn(
            total_timesteps=total_timesteps, callback=callback, progress_bar=False
        )
        print("Training completed successfully!")
    except Exception as e:
        print(f"Training was interrupted: {str(e)}")

    # Save the final model
    final_model_path = os.path.join(save_dir, "final_model")
    model.save(final_model_path)

    # Save the VecNormalize statistics
    vec_env.save(os.path.join(save_dir, "vec_normalize.pkl"))

    print(f"Training completed. Final model saved to {final_model_path}")
    return model, vec_env


def test_agent(model, env, num_episodes=3):
    """Test the trained agent for a few episodes."""
    # Create a new environment for testing with rendering
    test_env = ForestEnv(species_names=shortnames, render_mode="human")
    test_env = DummyVecEnv([lambda: test_env])

    # Load the normalization parameters
    test_env = VecNormalize.load(
        os.path.join("sac_direct_checkpoints/", "vec_normalize.pkl"), test_env
    )
    test_env.training = False  # Don't update normalization statistics during testing
    test_env.norm_reward = False  # Don't normalize rewards

    for episode in trange(num_episodes):
        obs = test_env.reset()
        done = False
        total_reward = 0
        steps = 0

        while not done:
            action, _ = model.predict(obs, deterministic=True)
            print(action)
            obs, reward, done, info = test_env.step(action)
            total_reward += reward[0]  # Reward is a 1D array because of vectorized env
            steps += 1

            # Check if we're at the end of an episode
            if done[0]:
                break

        print(f"Episode {episode+1}: Total Reward: {total_reward}, Steps: {steps}")

    print("Testing completed!")


if __name__ == "__main__":
    # Train the agent
    # model, vec_env = train_sac_agent()

    save_dir = "sac_direct_checkpoints/"

    vec_env = make_vec_env(
        ForestEnv,
        n_envs=1,
        env_kwargs={"species_names": shortnames},
        monitor_dir=save_dir,
    )

    # Normalize observations (not rewards since it might make learning unstable)
    vec_env = VecNormalize(vec_env, norm_obs=True, norm_reward=False)

    model = SAC.load("sac_direct_checkpoints/best_model.zip", env=vec_env)

    # Test the trained agent
    print("Testing the trained agent...")
    test_agent(model, vec_env)
