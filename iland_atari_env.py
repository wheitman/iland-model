import gymnasium as gym
from gymnasium import spaces
import pygame
import numpy as np
import pandas as pd

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


def shortname_to_color(shortname: str) -> tuple[int, int, int]:
    """
    Convert a shortname to a color using a simple hash function.
    """
    # Use a simple hash function to convert the shortname to an integer
    hash_value = hash(shortname) % 256
    # Map the hash value to a random shade of green
    return (
        int(hash_value / 10),
        hash_value,
        int(hash_value / 10),
    )  # RGB format (R, G, B)


class Seedling:
    cluster_df = pd.read_csv("pca_species_clusters.csv")

    def __init__(self, cluster: int, x, y):
        self.cluster = cluster
        self.x = x
        self.y = y

        species_in_cluster = Seedling.cluster_df[
            Seedling.cluster_df["cluster"] == cluster
        ]

        # Randomly select a species from the cluster
        self.species = species_in_cluster.sample(n=1, random_state=64).iloc[0][
            "shortName"
        ]
        self.color = shortname_to_color(self.species)


class GridWorldEnv(gym.Env):
    metadata = {"render_modes": ["human", "rgb_array"], "render_fps": 4}

    def __init__(self, render_mode=None, size=10, num_seedlings=10):
        self.size = size  # The size of the square grid
        self.window_size = 512  # The size of the PyGame window
        self.num_seedlings = num_seedlings  # The number of seedlings to plant

        self.seedlings: list[Seedling] = []

        # Observations are images representing the grid, including seedlings and the agent
        self.observation_space = spaces.Box(
            0, 255, (self.size, self.size, 3), dtype=np.uint8
        )

        # We have 10 actions, corresponding to "right", "up", "left", "down", and plant species 4-9
        self.action_space = spaces.Discrete(10)

        """
        The following dictionary maps abstract actions from `self.action_space` to 
        the direction we will walk in if that action is taken.
        I.e. 0 corresponds to "right", 1 to "up" etc.
        """
        self._action_to_direction = {
            0: np.array([1, 0]),
            1: np.array([0, 1]),
            2: np.array([-1, 0]),
            3: np.array([0, -1]),
        }

        assert render_mode is None or render_mode in self.metadata["render_modes"]
        self.render_mode = render_mode

        """
        If human-rendering is used, `self.window` will be a reference
        to the window that we draw to. `self.clock` will be a clock that is used
        to ensure that the environment is rendered at the correct framerate in
        human-mode. They will remain `None` until human-mode is used for the
        first time.
        """
        self.window = None
        self.clock = None

    def _get_obs(self):
        obs = np.zeros((self.size, self.size, 3), dtype=np.uint8)

        return obs

    def _get_info(self):
        return {
            "seedlings": self.seedlings,
        }

    def reset(self, seed=None, options=None):
        # We need the following line to seed self.np_random
        super().reset(seed=seed)

        # Choose the agent's location uniformly at random
        self._agent_location = self.np_random.integers(0, self.size, size=2, dtype=int)

        observation = self._get_obs()
        info = self._get_info()

        if self.render_mode == "human":
            self._render_frame()

        return observation, info

    def step(self, action):

        if action <= 3:
            # Map the action (element of {0,1,2,3}) to the direction we walk in
            direction = self._action_to_direction[action]
            # We use `np.clip` to make sure we don't leave the grid
            self._agent_location = np.clip(
                self._agent_location + direction, 0, self.size - 1
            )
        else:
            # Check if a seedling is already occupying the location
            for seedling in self.seedlings:
                if (
                    seedling.x == self._agent_location[0]
                    and seedling.y == self._agent_location[1]
                ):
                    return self._get_obs(), 0, False, False, self._get_info()
            # Plant a seedling
            # The action is an integer between 4 and 9, which we can use to index the species
            self.seedlings.append(Seedling(action - 4, *self._agent_location))

        # An episode is done iff the agent has planted the max seedlings
        terminated = len(self.seedlings) >= self.num_seedlings
        reward = 1 if terminated else 0  # Binary sparse rewards
        observation = self._get_obs()
        info = self._get_info()

        if self.render_mode == "human":
            self._render_frame()

        return observation, reward, terminated, False, info

    def render(self):
        if self.render_mode == "rgb_array":
            return self._render_frame()

    def _render_frame(self):
        if self.window is None and self.render_mode == "human":
            pygame.init()
            pygame.display.init()
            self.window = pygame.display.set_mode((self.window_size, self.window_size))
        if self.clock is None and self.render_mode == "human":
            self.clock = pygame.time.Clock()

        canvas = pygame.Surface((self.window_size, self.window_size))
        canvas.fill((255, 255, 255))
        pix_square_size = (
            self.window_size / self.size
        )  # The size of a single grid square in pixels

        # Now we draw the seedlings
        for seedling in self.seedlings:
            pygame.draw.circle(
                canvas,
                seedling.color,
                np.asarray([seedling.x + 0.5, seedling.y + 0.5]) * pix_square_size,
                pix_square_size / 3,
            )

        # Now we draw the agent
        pygame.draw.circle(
            canvas,
            (0, 0, 255),
            (self._agent_location + 0.5) * pix_square_size,
            pix_square_size / 3,
        )

        # Finally, add some gridlines
        for x in range(self.size + 1):
            pygame.draw.line(
                canvas,
                0,
                (0, pix_square_size * x),
                (self.window_size, pix_square_size * x),
                width=3,
            )
            pygame.draw.line(
                canvas,
                0,
                (pix_square_size * x, 0),
                (pix_square_size * x, self.window_size),
                width=3,
            )

        if self.render_mode == "human":
            # The following line copies our drawings from `canvas` to the visible window
            self.window.blit(canvas, canvas.get_rect())
            pygame.event.pump()
            pygame.display.update()

            # We need to ensure that human-rendering occurs at the predefined framerate.
            # The following line will automatically add a delay to keep the framerate stable.
            self.clock.tick(self.metadata["render_fps"])
        else:  # rgb_array
            return np.transpose(
                np.array(pygame.surfarray.pixels3d(canvas)), axes=(1, 0, 2)
            )

    def close(self):
        if self.window is not None:
            pygame.display.quit()
            pygame.quit()


def get_action_from_keyboard_input():
    """
    Get action from keyboard input.
    """
    action = None

    while action is None:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                action = None
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_DOWN:
                    action = 1  # Down
                elif event.key == pygame.K_UP:
                    action = 3  # Up
                elif event.key == pygame.K_LEFT:
                    action = 2  # Left
                elif event.key == pygame.K_RIGHT:
                    action = 0  # Right
                elif event.key == pygame.K_4:
                    action = 4
                elif event.key == pygame.K_5:
                    action = 5
                elif event.key == pygame.K_6:
                    action = 6
                elif event.key == pygame.K_7:
                    action = 7
                elif event.key == pygame.K_8:
                    action = 8
                elif event.key == pygame.K_9:
                    action = 9

    return action


if __name__ == "__main__":
    env = GridWorldEnv(render_mode="human", size=10)
    obs, info = env.reset()
    done = False
    while not done:
        action = env.action_space.sample()
        action = get_action_from_keyboard_input()
        obs, reward, done, _, info = env.step(action)
        print(f"Action: {action}, Obs: {obs}, Reward: {reward}, Info: {info}")
