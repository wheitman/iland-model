from stable_baselines3.common.env_checker import check_env
from forest_env import ForestEnv
import random
import os
import gymnasium as gym
import numpy as np
import torch
from stable_baselines3 import PPO
from stable_baselines3.common.env_util import make_vec_env
from stable_baselines3.common.callbacks import BaseCallback
from stable_baselines3.common.monitor import Monitor
from stable_baselines3.common.vec_env import DummyVecEnv
from stable_baselines3.common.env_util import make_vec_env
from stable_baselines3.common.results_plotter import load_results, ts2xy
from tqdm import trange


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

shortnames = shortnames[::10]  # Take every 10th name for a smaller set


def set_all_seeds(seed):
    """Set all seeds for reproducibility"""
    # Python's built-in random module
    random.seed(seed)

    # NumPy
    np.random.seed(seed)

    # Gymnasium (if using)
    gym.utils.seeding.np_random(seed)

    # PyTorch (if using)
    if "torch" in globals():
        torch.manual_seed(seed)
        torch.cuda.manual_seed(seed)
        torch.cuda.manual_seed_all(seed)  # For multi-GPU
        torch.backends.cudnn.deterministic = True
        torch.backends.cudnn.benchmark = False

    # Environment variables (used by some libraries)
    os.environ["PYTHONHASHSEED"] = str(seed)


set_all_seeds(64)
env = ForestEnv(species_names=shortnames, render_mode="human")

obs, _ = env.reset()
env.render()

check_env(env, warn=True)

# Hardcoded method
# for step in trange(30, unit="steps"):
#     # print(f"Step {step + 1}")
#     obs, reward, terminated, truncated, info = env.step(
#         [random.uniform(-1, 1), random.uniform(-1, 1), random.uniform(-1, 1)]
#     )
#     done = terminated or truncated

#     # print(reward)

#     # print("obs=", obs, "reward=", reward, "done=", done)
#     env.render()
#     if done:
#         print("Goal reached!", "reward=", reward)
#         break


class SaveOnBestTrainingRewardCallback(BaseCallback):
    """
    Callback for saving a model (the check is done every ``check_freq`` steps)
    based on the training reward (in practice, we recommend using ``EvalCallback``).

    :param check_freq: (int)
    :param log_dir: (str) Path to the folder where the model will be saved.
      It must contains the file created by the ``Monitor`` wrapper.
    :param verbose: (int)
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

                # New best model, you could save the agent here
                if mean_reward > self.best_mean_reward:
                    self.best_mean_reward = mean_reward
                    # Example for saving best model
                    if self.verbose > 0:
                        print("Saving new best model at {} timesteps".format(x[-1]))
                        print("Saving new best model to {}.zip".format(self.save_path))
                    self.model.save(self.save_path)

        return True


save_dir = "baseline_checkpoints/"
callback = SaveOnBestTrainingRewardCallback(check_freq=100, log_dir=save_dir, verbose=1)
os.makedirs(save_dir, exist_ok=True)

print("Training the agent...")
model = PPO("MlpPolicy", env, verbose=1)
# model = PPO.load(f"{save_dir}/best_model.zip", env=env)


vec_env = make_vec_env(
    ForestEnv, n_envs=1, env_kwargs={"species_names": shortnames}, monitor_dir=save_dir
)


model.set_env(vec_env)

model.learn(50000, progress_bar=True, callback=callback)

# model = PPO("MlpPolicy", vec_env, verbose=1).learn(
#     50000, progress_bar=True, callback=callback
# )
# model.save(os.path.join(save_dir, "ppo_forest"))
