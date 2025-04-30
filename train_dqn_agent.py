import random
from stable_baselines3 import A2C, PPO
from sb3_contrib import QRDQN
from stable_baselines3.common.vec_env import DummyVecEnv, SubprocVecEnv
import ale_py
from iland_atari_env import ForestEnv
from stable_baselines3.common.env_checker import check_env
from stable_baselines3.common.callbacks import BaseCallback, CheckpointCallback
from stable_baselines3.common.evaluation import evaluate_policy
from stable_baselines3.common.callbacks import EvalCallback
import numpy as np
import os
from multiprocessing import freeze_support


# Define environment creation function
def make_env(render_mode, num_seedlings, size, process_index):
    """
    Creates a function that will initialize an environment with specified parameters
    """

    def _init():
        env = ForestEnv(
            render_mode=render_mode,
            num_seedlings=num_seedlings,
            size=size,
            process_index=process_index,
        )
        return env

    return _init


def main():
    # Set all random seeds for reproducibility
    seed = 64
    np.random.seed(seed)
    os.environ["PYTHONHASHSEED"] = str(seed)
    os.environ["SEED"] = str(seed)
    random.seed(seed)

    # Number of parallel environments
    num_envs = 16  # Adjust based on your CPU cores

    # Create a list of environment creation functions
    env_fns = [make_env(None, 100, 40, i) for i in range(num_envs)]

    # Create vectorized environment (SubprocVecEnv for true parallelism)
    print("Creating parallel forest environments...")
    env = SubprocVecEnv(env_fns)

    # Create an evaluation environment (single env is sufficient for evaluation)
    eval_env = ForestEnv(
        render_mode="human",
        num_seedlings=100,
        size=40,
        process_index=num_envs,  # Use a different process index than training envs
    )
    eval_env = DummyVecEnv([lambda: eval_env])  # Wrap in VecEnv for compatibility

    # Create the callback that will periodically evaluate and save the best model
    eval_callback = EvalCallback(
        eval_env,
        best_model_save_path="./best_model",
        log_path="./eval_logs/",
        eval_freq=10000 // num_envs,  # Adjust frequency based on number of environments
        deterministic=True,
        render=True,
        n_eval_episodes=1,
        verbose=1,
    )

    # Set up model with vectorized environment
    # policy_kwargs = dict(n_quantiles=200)
    # model = QRDQN(
    #     "CnnPolicy",
    #     env,
    #     policy_kwargs=policy_kwargs,
    #     verbose=1,
    #     tensorboard_log="./qrdqn_iland_tensorboard/",
    # )

    model = PPO(
        "CnnPolicy",
        env,
        verbose=1,
        tensorboard_log="./ppo_iland_tensorboard/",
    )

    model = PPO.load(
        "./best_model/best_model",
        env=env,
    )

    model.learn(
        total_timesteps=10_000_000,
        progress_bar=True,
        log_interval=100,
        callback=eval_callback,
    )


if __name__ == "__main__":
    freeze_support()  # For Windows support
    main()
