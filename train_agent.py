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

from matplotlib import pyplot as plt


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


import matplotlib.pyplot as plt
import numpy as np
import torch
from torch.distributions import Normal

# Add this to your existing imports
from stable_baselines3.common.callbacks import BaseCallback


# Create a custom callback for plotting action distributions
class PlotActionDistributionCallback(BaseCallback):
    """
    Callback for plotting the actor's action probability distribution periodically.
    """

    def __init__(self, check_freq=1000, plot_dir="action_plots", verbose=1):
        super().__init__(verbose)
        self.check_freq = check_freq
        self.plot_dir = plot_dir
        os.makedirs(plot_dir, exist_ok=True)

    def _init_callback(self) -> None:
        pass

    def _on_step(self) -> bool:
        if self.n_calls % self.check_freq == 0:
            # Access the underlying environment through the wrappers
            # For VecEnv, we need to access the first environment
            env = self.model.env

            device = next(self.model.actor.parameters()).device

            # Navigate through potential wrappers to get the base environment
            if hasattr(env, "venv"):
                env = env.venv
            if hasattr(env, "envs"):
                # Get the first environment from the DummyVecEnv
                env = env.envs[0]

            # Navigate through Monitor wrapper if present
            if hasattr(env, "env"):
                env = env.env

            # Now we should have the ForestEnv instance
            if hasattr(env, "get_observation"):
                obs = env.get_observation()
            else:
                # If we can't access the method directly, try another approach
                # Use reset to get a valid observation
                if hasattr(self.model.env, "reset"):
                    obs, _ = self.model.env.reset()
                    obs = obs[0]  # Get observation from batch
                else:
                    print("Could not access observation, skipping plot")
                    return True

            # Convert to tensor for the policy
            obs_tensor = torch.FloatTensor(obs).unsqueeze(0).to(device)

            # Get normalized observation if VecNormalize is used
            if hasattr(self.model.env, "normalize_obs") and callable(
                self.model.env.normalize_obs
            ):
                obs_normalized = self.model.env.normalize_obs(np.array([obs]))
                obs_tensor = torch.FloatTensor(obs_normalized)

            # Access the actor model (policy network)
            actor = self.model.actor

            # Call the actor to get the action distribution parameters
            with torch.no_grad():
                # Get mean and log_std from the actor's forward pass
                mean_actions, log_std, kwargs = actor.get_action_dist_params(obs_tensor)

                # Convert to numpy for plotting
                mean_actions = mean_actions.cpu().detach().numpy()[0]
                std_actions = torch.exp(log_std).cpu().detach().numpy()[0]

            # Get species names from the environment
            if hasattr(env, "species_names"):
                species_names = env.species_names
            else:
                # Default to generic labels if species_names not available
                species_names = [
                    f"Species {i}" for i in range(32)
                ]  # Using 32 as default from your code

            # Plot the action distribution
            self.plot_action_distribution(
                mean_actions,
                std_actions,
                iteration=self.n_calls,
                species_names=species_names,
            )

            # Also create a plot showing environment state and action distribution
            self.plot_state_and_action(
                obs,
                mean_actions,
                std_actions,
                iteration=self.n_calls,
                species_names=species_names,
            )

        return True

    def plot_action_distribution(self, mean, std, iteration, species_names):
        """Plot the action probability distribution for each action dimension"""
        action_dim = len(mean)
        action_names = ["X Position", "Y Position", f"Species Selection"]

        # Create figure with subplots for each action dimension
        fig, axs = plt.subplots(1, action_dim, figsize=(15, 5))

        # If there's only one action dimension, make axs a list
        if action_dim == 1:
            axs = [axs]

        # Plot the distribution for each action dimension
        for i in range(action_dim):
            mu = mean[i]
            sigma = std[i]

            # Create x values for plotting
            x = np.linspace(-1, 1, 1000)

            # Calculate the PDF values
            pdf = (
                1
                / (sigma * np.sqrt(2 * np.pi))
                * np.exp(-((x - mu) ** 2) / (2 * sigma**2))
                if sigma > 0
                else np.zeros_like(x)
            )

            # Normalize PDF so it's visible in the plot
            if np.sum(pdf) > 0:
                pdf = pdf / np.max(pdf)

            # Plot PDF
            axs[i].plot(x, pdf)
            axs[i].axvline(x=mu, color="r", linestyle="--", label=f"Mean: {mu:.2f}")

            # Fill area within one standard deviation
            axs[i].fill_between(
                x,
                0,
                pdf,
                where=((x >= mu - sigma) & (x <= mu + sigma)),
                alpha=0.3,
                color="g",
                label=f"Std: {sigma:.2f}",
            )

            # Special case for species action dimension
            if i == 2:
                # Add ticks for species
                num_species = len(species_names)
                ticks = np.linspace(-1, 1, num_species)
                axs[i].set_xticks(ticks)

                # Only show a subset of species names if there are too many
                if num_species > 10:
                    # Show only first and last few species, with ellipsis in the middle
                    labels = [
                        species_names[0],
                        species_names[1],
                        species_names[2],
                        "...",
                        species_names[-3],
                        species_names[-2],
                        species_names[-1],
                    ]
                    tick_indices = [
                        0,
                        1,
                        2,
                        num_species // 2,
                        num_species - 3,
                        num_species - 2,
                        num_species - 1,
                    ]
                    axs[i].set_xticks([ticks[idx] for idx in tick_indices])
                    axs[i].set_xticklabels(labels, rotation=45)
                else:
                    axs[i].set_xticklabels(species_names, rotation=45)

            # Set title and labels
            axs[i].set_title(action_names[i])
            axs[i].set_xlabel("Action Value")
            axs[i].set_ylabel("Probability Density")
            axs[i].legend()
            axs[i].grid(True)

        plt.suptitle(f"SAC Policy Action Distribution (Iteration {iteration})")
        plt.tight_layout()

        # Save the figure
        plt.savefig(f"{self.plot_dir}/action_dist_{iteration}.png")
        plt.close()

    def plot_state_and_action(self, obs, mean, std, iteration, species_names):
        """Create a plot showing both environment state and action distribution"""
        fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(15, 5))

        # Plot environment observation
        im = ax1.imshow(obs[:, :, 0], cmap="viridis")
        ax1.set_title(f"Environment State (Iteration {iteration})")
        fig.colorbar(im, ax=ax1, label="Species/Keepout")

        # Plot action distribution as bar chart
        action_names = ["X Position", "Y Position", "Species"]
        ax2.bar(action_names, mean, yerr=std, capsize=10)
        ax2.set_title("Current SAC Action Distribution")
        ax2.set_ylim(-1.1, 1.1)
        ax2.grid(True)

        plt.tight_layout()
        plt.savefig(f"{self.plot_dir}/state_action_{iteration}.png")
        plt.close()


class EvalForestCallback(BaseCallback):
    """
    Callback for evaluating the deterministic actions periodically
    """

    def __init__(self, check_freq=1000, verbose=1):
        super().__init__(verbose)
        self.check_freq = check_freq

    def _init_callback(self) -> None:
        pass

    def _on_step(self) -> bool:
        if self.n_calls % self.check_freq == 0:
            print("TESTING AGENT")
            test_agent(self.model, self.model.env, num_episodes=3)

        return True


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
    plot_dir = "action_plots/"
    os.makedirs(save_dir, exist_ok=True)
    os.makedirs(plot_dir, exist_ok=True)

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
    # vec_env = VecNormalize(vec_env, norm_obs=True, norm_reward=False)

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
        "device": "cpu",
        "policy_kwargs": dict(net_arch=[64, 64]),  # Smaller network
    }

    # Create the SAC agent
    model = SAC("MlpPolicy", vec_env, **sac_params)
    # model = SAC.load("sac_direct_checkpoints/best_model.zip", env=vec_env)

    # Set up callbacks
    # 1. Callback for saving the best model
    save_callback = SaveOnBestTrainingRewardCallback(
        check_freq=1000, log_dir=save_dir, verbose=1
    )

    # 2. Callback for plotting action distributions
    plot_callback = PlotActionDistributionCallback(
        check_freq=100, plot_dir=plot_dir, verbose=1
    )

    eval_callback = EvalForestCallback(check_freq=10, verbose=1)

    # Combine callbacks
    from stable_baselines3.common.callbacks import CallbackList

    callbacks = CallbackList([save_callback, plot_callback, eval_callback])

    # Train the agent
    total_timesteps = 30000
    print(f"Training SAC agent for {total_timesteps} timesteps...")

    try:
        model.learn(
            total_timesteps=total_timesteps, callback=callbacks, progress_bar=True
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

    # Setup directory for test plots
    test_plot_dir = "test_action_plots/"
    os.makedirs(test_plot_dir, exist_ok=True)

    device = next(model.actor.parameters()).device

    for episode in trange(num_episodes):
        obs = test_env.reset()
        done = [False]  # Initialize as a list for compatibility with newer SB3 versions
        total_reward = 0
        steps = 0

        while not done[0]:
            # Get raw observation for plotting
            # Navigate through wrappers to get the base environment
            base_env = test_env.envs[0]
            while hasattr(base_env, "env"):
                base_env = base_env.env

            # Now we should have the ForestEnv instance
            raw_obs = base_env.get_observation()

            # Get action from the model
            action, _ = model.predict(obs, deterministic=True)

            # Access the actor model to get distribution parameters
            with torch.no_grad():
                # Create observation tensor
                obs_tensor = torch.FloatTensor(obs).to(device)

                # Get distribution parameters
                mean_actions, log_std, _ = model.actor.get_action_dist_params(
                    obs_tensor
                )

                mean_actions = mean_actions.cpu().detach().numpy()[0]
                std_actions = torch.exp(log_std).cpu().detach().numpy()[0]

            # Plot action distribution every 10 steps
            if steps % 10 == 0:
                plot_action_distribution(
                    mean_actions,
                    std_actions,
                    iteration=steps,
                    species_names=base_env.species_names,
                    plot_dir=test_plot_dir,
                    episode=episode,
                )

                plot_state_and_action(
                    raw_obs,
                    mean_actions,
                    std_actions,
                    iteration=steps,
                    species_names=base_env.species_names,
                    plot_dir=test_plot_dir,
                    episode=episode,
                )

            # Take step in environment
            print(action)
            next_obs, reward, done, info = test_env.step(action)
            obs = next_obs
            total_reward += reward[0]  # Reward is a 1D array because of vectorized env
            steps += 1

        print(f"Episode {episode+1}: Total Reward: {total_reward}, Steps: {steps}")

    print("Testing completed!")


# Helper functions for test_agent
def plot_action_distribution(mean, std, iteration, species_names, plot_dir, episode):
    """Plot the action probability distribution for each action dimension"""
    action_dim = len(mean)
    action_names = ["X Position", "Y Position", "Species Selection"]

    # Create figure with subplots for each action dimension
    fig, axs = plt.subplots(1, action_dim, figsize=(15, 5))

    # If there's only one action dimension, make axs a list
    if action_dim == 1:
        axs = [axs]

    # Plot the distribution for each action dimension
    for i in range(action_dim):
        mu = mean[i]
        sigma = std[i]

        # Create x values for plotting
        x = np.linspace(-1, 1, 1000)

        # Calculate the PDF values
        pdf = (
            1 / (sigma * np.sqrt(2 * np.pi)) * np.exp(-((x - mu) ** 2) / (2 * sigma**2))
            if sigma > 0
            else np.zeros_like(x)
        )

        # Normalize PDF so it's visible in the plot
        if np.sum(pdf) > 0:
            pdf = pdf / np.max(pdf)

        # Plot PDF
        axs[i].plot(x, pdf)
        axs[i].axvline(x=mu, color="r", linestyle="--", label=f"Mean: {mu:.2f}")

        # Fill area within one standard deviation
        axs[i].fill_between(
            x,
            0,
            pdf,
            where=((x >= mu - sigma) & (x <= mu + sigma)),
            alpha=0.3,
            color="g",
            label=f"Std: {sigma:.2f}",
        )

        # Special case for species action dimension
        if i == 2:
            # Add ticks for species
            num_species = len(species_names)
            ticks = np.linspace(-1, 1, num_species)
            axs[i].set_xticks(ticks)

            # Only show a subset of species names if there are too many
            if num_species > 10:
                # Show only first and last few species, with ellipsis in the middle
                labels = [
                    species_names[0],
                    species_names[1],
                    species_names[2],
                    "...",
                    species_names[-3],
                    species_names[-2],
                    species_names[-1],
                ]
                tick_indices = [
                    0,
                    1,
                    2,
                    num_species // 2,
                    num_species - 3,
                    num_species - 2,
                    num_species - 1,
                ]
                axs[i].set_xticks([ticks[idx] for idx in tick_indices])
                axs[i].set_xticklabels(labels, rotation=45)
            else:
                axs[i].set_xticklabels(species_names, rotation=45)

        # Set title and labels
        axs[i].set_title(action_names[i])
        axs[i].set_xlabel("Action Value")
        axs[i].set_ylabel("Probability Density")
        axs[i].legend()
        axs[i].grid(True)

    plt.suptitle(
        f"SAC Policy Action Distribution (Episode {episode+1}, Step {iteration})"
    )
    plt.tight_layout()

    # Save the figure
    plt.savefig(f"{plot_dir}/ep{episode+1}_action_dist_{iteration}.png")
    plt.close()


def plot_state_and_action(obs, mean, std, iteration, species_names, plot_dir, episode):
    """Create a plot showing both environment state and action distribution"""
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(15, 5))

    # Plot environment observation
    im = ax1.imshow(obs[:, :, 0], cmap="viridis")
    ax1.set_title(f"Environment State (Episode {episode+1}, Step {iteration})")
    fig.colorbar(im, ax=ax1, label="Species/Keepout")

    # Plot action distribution as bar chart
    action_names = ["X Position", "Y Position", "Species"]
    ax2.bar(action_names, mean, yerr=std, capsize=10)
    ax2.set_title("Current SAC Action Distribution")
    ax2.set_ylim(-1.1, 1.1)
    ax2.grid(True)

    plt.tight_layout()
    plt.savefig(f"{plot_dir}/ep{episode+1}_state_action_{iteration}.png")
    plt.close()


if __name__ == "__main__":
    # Train the agent
    model, vec_env = train_sac_agent()

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
