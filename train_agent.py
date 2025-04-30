"""
train_rl.py - Script to train a reinforcement learning policy for optimal forest planting
"""

import os
import numpy as np
from stable_baselines3 import PPO
from stable_baselines3.common.vec_env import DummyVecEnv
from stable_baselines3.common.monitor import Monitor
from stable_baselines3.common.callbacks import BaseCallback, CheckpointCallback
from stable_baselines3.common.logger import configure
from stable_baselines3.common.env_checker import check_env

from forest_env import ForestEnv
from matplotlib import pyplot as plt


# Define a callback for logging additional metrics
class TensorboardCallback(BaseCallback):
    def __init__(self, verbose=0):
        super(TensorboardCallback, self).__init__(verbose)

    def _on_step(self) -> bool:
        # Log additional info when episode completes
        if self.locals.get("dones") and any(self.locals.get("dones")):
            self.logger.record(
                "environment/total_carbon",
                self.locals.get("infos")[0].get("total_carbon", 0),
            )
            self.logger.record(
                "environment/planted_seedlings",
                self.locals.get("infos")[0].get("planted_seedlings", 0),
            )
            # Can add more custom metrics here
        return True


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


def main():
    # Define tree species names
    species_names = shortnames  # Example species

    # Set up paths for logging and model saving
    log_dir = "logs/"
    os.makedirs(log_dir, exist_ok=True)

    model_dir = "models/"
    os.makedirs(model_dir, exist_ok=True)

    # Configure logger
    logger = configure(log_dir, ["tensorboard", "stdout"])

    # Create environment
    print("Creating forest environment...")
    env = ForestEnv(
        species_names=species_names,
        render_mode="console",  # Can be "human" for visualization
        years=10,  # Simulation years
        num_seedlings=300,  # Number of seedlings to plant per episode
        grid_size=100,  # Size of the grid
    )

    check_env(env)  # Check if the environment is valid

    # Wrap environment for logging
    env = Monitor(env, log_dir)

    # Vectorize environment (required by Stable Baselines)
    vec_env = DummyVecEnv([lambda: env])

    # Create checkpoint callback for saving models during training
    checkpoint_callback = CheckpointCallback(
        save_freq=1000,  # Save every 1000 steps
        save_path=model_dir,
        name_prefix="forest_model",
        save_replay_buffer=True,
        save_vecnormalize=True,
    )

    # Create custom callback for additional logging
    tensorboard_callback = TensorboardCallback()

    # Create and train the model
    print("Creating and training the model...")

    # Define custom feature extractor for our observation
    from stable_baselines3.common.torch_layers import BaseFeaturesExtractor
    import torch as th
    import torch.nn as nn
    import gymnasium as gym

    class CustomCNN(BaseFeaturesExtractor):
        """
        Custom CNN feature extractor for the forest environment.

        This extractor handles discrete values in the observation (0, 1, 2+)
        rather than typical normalized image pixels.
        """

        def __init__(self, observation_space: gym.spaces.Box, features_dim: int = 256):
            super(CustomCNN, self).__init__(observation_space, features_dim)

            # Extract observation shape
            n_input_channels = observation_space.shape[2]

            # CNN architecture
            self.cnn = nn.Sequential(
                nn.Conv2d(n_input_channels, 32, kernel_size=5, stride=2, padding=2),
                nn.ReLU(),
                nn.Conv2d(32, 64, kernel_size=3, stride=2, padding=1),
                nn.ReLU(),
                nn.Conv2d(64, 128, kernel_size=3, stride=1, padding=1),
                nn.ReLU(),
                nn.Conv2d(128, 128, kernel_size=3, stride=1, padding=1),
                nn.ReLU(),
                nn.Flatten(),
            )

            # Compute shape by doing one forward pass
            with th.no_grad():
                # Create a dummy input
                dummy_input = th.zeros(1, *observation_space.shape)
                # Transpose to channel-first format (PyTorch's expected format)
                dummy_input = dummy_input.permute(0, 3, 1, 2)
                n_flatten = self.cnn(dummy_input).shape[1]

            self.linear = nn.Sequential(nn.Linear(n_flatten, features_dim), nn.ReLU())

        # Fix the normalization in the CNN
        def forward(self, observations: th.Tensor) -> th.Tensor:
            # Permute for PyTorch (batch, channel, height, width)
            observations = observations.permute(0, 3, 1, 2)

            # Normalize species channel and keep distance channel as is
            species_channel = observations[:, 0:1, :, :].float() / (
                len(species_names) + 2
            )
            distance_channel = observations[
                :, 1:2, :, :
            ]  # Already normalized to [0, 1]

            # Combine the channels
            normalized_obs = th.cat([species_channel, distance_channel], dim=1)

            # Pass through CNN
            features = self.cnn(normalized_obs)

            # Pass through final linear layer
            return self.linear(features)

    # Create model

    model = PPO(
        "CnnPolicy",
        vec_env,
        verbose=1,
        tensorboard_log=log_dir,
        learning_rate=3e-4,
        n_steps=1024,  # Reduced for better sample efficiency
        batch_size=128,  # Increased for more stable learning
        n_epochs=5,  # Reduced to prevent overfitting
        gamma=0.99,
        gae_lambda=0.95,
        clip_range=0.2,
        ent_coef=0.01,  # Add some exploration bonus
        vf_coef=0.5,
        max_grad_norm=0.5,
        device="auto",
        policy_kwargs={
            "features_extractor_class": CustomCNN,
            "features_extractor_kwargs": {"features_dim": 256},
            "normalize_images": False,
            # Deeper network for better pattern recognition
            "net_arch": [256, 256, 128],
        },
    )

    model = PPO.load(
        os.path.join("models", "forest_model_68000_steps.zip"), env=vec_env
    )
    print("LOADED MODEL")

    # Train the model
    # total_timesteps = 300000  # Total number of simulation steps
    # print(f"Training for {total_timesteps} timesteps...")
    # model.learn(
    #     total_timesteps=total_timesteps,
    #     callback=[checkpoint_callback, tensorboard_callback],
    #     tb_log_name="forest_rl",
    #     progress_bar=True,
    # )

    # Save the final model
    # final_model_path = os.path.join(model_dir, "final_forest_model")
    # model.save(final_model_path)
    # print(f"Training completed. Final model saved to {final_model_path}")

    # Test the trained model

    for j in range(10):
        print("Testing the trained model...")
        obs = vec_env.reset()
        cumulative_reward = 0
        seedlings = []

        plt.figure()

        for i in range(300):  # Plant all seedlings
            action, _states = model.predict(obs, deterministic=False)

            if len(action) == 1:
                action = action[0]

            print(action)

            # Normalize action from [-1, 1] to grid coordinates and species
            x_norm = (action[0] + 1) / 2  # Convert from [-1, 1] to [0, 1]
            y_norm = (action[1] + 1) / 2  # Convert from [-1, 1] to [0, 1]

            # Convert to grid coordinates
            x = x_norm * 100
            y = y_norm * 100

            # Convert species index from [-1, 1] to [0, len(species_names)-1]
            species_norm = (action[2] + 1) / 2  # Convert from [-1, 1] to [0, 1]
            species_idx = int(species_norm * (len(species_names) - 1))

            # Round to ensure it's a valid index
            species_idx = max(0, min(species_idx, len(species_names) - 1))

            # Check if the planting location is valid (within keepout mask)

            grid_x = int(min(max(0, x), 100 - 1))
            grid_y = int(min(max(0, y), 100 - 1))
            if grid_x < 0 or grid_x >= 100 or grid_y < 0 or grid_y >= 100:
                continue

            seedlings.append([grid_x, grid_y, species_names[species_idx]])
            plt.scatter(x, y, label=species_names[species_idx])

            obs, rewards, dones, info = vec_env.step([action])
            cumulative_reward += rewards[0]
            vec_env.render()

            print(
                f"Step {i+1}: Reward = {rewards[0]:.2f}, Total Carbon = {info[0].get('total_carbon', 0):.2f} kg"
            )

            if dones[0]:
                print(
                    f"Episode done! Final carbon: {info[0].get('total_carbon', 0):.2f} kg"
                )
                break

        print(
            f"Testing completed for step {j}. Cumulative reward: {cumulative_reward:.2f}"
        )

        plt.legend()
        plt.title(
            f"Seedlings planted in episode {j}. Total carbon: {cumulative_reward:.2f} kg/year"
        )
        plt.savefig(f"seedlings_episode_{j}.png")

    # Close environment
    vec_env.close()


if __name__ == "__main__":
    main()
