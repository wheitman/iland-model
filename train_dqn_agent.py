from stable_baselines3 import A2C
from sb3_contrib import QRDQN
from stable_baselines3.common.env_util import make_atari_env
from stable_baselines3.common.vec_env import VecFrameStack
import ale_py
from iland_atari_env import ForestEnv
from stable_baselines3.common.env_checker import check_env
from stable_baselines3.common.callbacks import BaseCallback, CheckpointCallback
from stable_baselines3.common.evaluation import evaluate_policy
from stable_baselines3.common.callbacks import EvalCallback

# Create environment
print("Creating forest environment...")
env = ForestEnv(
    render_mode="human",  # Can be "human" for visualization
    num_seedlings=100,  # Number of seedlings to plant per episode
    size=40,  # Size of the grid
)

check_env(env)  # Check if the environment is valid

# Create an evaluation environment
eval_env = ForestEnv(
    render_mode=None,  # No rendering for evaluation to speed up
    num_seedlings=100,
    size=40,
)

# Create the callback that will periodically evaluate and save the best model
eval_callback = EvalCallback(
    eval_env,
    best_model_save_path="./best_model",
    log_path="./eval_logs/",
    eval_freq=10000,  # Evaluate every 10000 steps
    deterministic=True,
    render=False,
    n_eval_episodes=5,
    verbose=1,
)

policy_kwargs = dict(n_quantiles=200)
model = QRDQN(
    "CnnPolicy",
    env,
    policy_kwargs=policy_kwargs,
    verbose=1,
    tensorboard_log="./qrdqn_iland_tensorboard/",
)
# model = A2C("CnnPolicy", env, verbose=1, tensorboard_log="./a2c_pong_tensorboard/")
model.learn(
    total_timesteps=10_000_000,
    progress_bar=True,
    log_interval=10,
    callback=eval_callback,
)
