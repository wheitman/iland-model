import shutil
import gymnasium as gym
from gymnasium import spaces
import pygame
import numpy as np
import pandas as pd
import subprocess
import os
import sqlite3
import xml.etree.ElementTree as ET

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


def read_table(db_path="output.sqlite", table_name="stand") -> pd.DataFrame:
    """
    Read the contents of the 'stand' table from the SQLite database file.

    Args:
        db_path (str): Path to the SQLite database file
        table_name (str): Name of the table to read

    Returns:
        DataFrame: Contents of the 'stand' table
    """
    # Check if the file exists
    if not os.path.isfile(db_path):
        print(f"Error: Database file '{db_path}' not found.")
        return None

    try:
        # Connect to SQLite database
        conn = sqlite3.connect(db_path)

        # Query the stand table
        df = pd.read_sql_query(f"SELECT * FROM {table_name}", conn)

        # Close the connection
        conn.close()

        return df

    except sqlite3.Error as e:
        print(f"SQLite error: {e}")
    except Exception as e:
        print(f"Error: {e}")

    return None


def get_total_carbon(data: pd.DataFrame, year: int):
    # Sum the branch mass for all trees in the final year
    total_branch_mass = data[data["year"] == year]["branchMass"].sum()
    # print(f"Total branch mass in the final year: {total_branch_mass:.2f} kg")

    # Same for the stem mass, coarse root mass, and fine root mass
    total_stem_mass = data[data["year"] == year]["stemMass"].sum()
    # print(f"Total stem mass in the final year: {total_stem_mass:.2f} kg")

    total_coarse_root_mass = data[data["year"] == year]["coarseRootMass"].sum()
    # print(f"Total coarse root mass in the final year: {total_coarse_root_mass:.2f} kg")

    total_fine_root_mass = data[data["year"] == year]["fineRootMass"].sum()
    # print(f"Total fine root mass in the final year: {total_fine_root_mass:.2f} kg")

    total_carbon_kg = (
        total_branch_mass
        + total_stem_mass
        + total_coarse_root_mass
        + total_fine_root_mass
    ) * 0.5  # 50% of the mass is carbon

    return total_carbon_kg


def shortname_to_color(shortname: str, cluster: int) -> tuple[int, int, int]:
    """
    Convert a shortname and cluster to a color using a deterministic hash function.
    Species with the same cluster should have a similar shade.
    """
    # Generate a base color for each cluster
    cluster_colors = {
        0: (100, 100, 255),  # Blue shades
        1: (50, 200, 50),  # Green shades
        2: (200, 50, 50),  # Red shades
        3: (200, 200, 50),  # Yellow shades
        4: (200, 100, 200),  # Purple shades
        5: (50, 200, 200),  # Cyan shades
    }

    # Use a hash of the shortname to create variation within the cluster
    hash_val = sum(ord(c) for c in shortname)

    # Get base color for the cluster
    base_r, base_g, base_b = cluster_colors.get(cluster, (150, 150, 150))

    # Create variations based on species name while keeping the dominant hue
    variation = 255  # Amount of variation within a cluster
    r = max(0, min(255, base_r + (hash_val % variation) - variation // 2))
    g = max(0, min(255, base_g + ((hash_val // 10) % variation) - variation // 2))
    b = max(0, min(255, base_b + ((hash_val // 100) % variation) - variation // 2))

    return (r, g, b)


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
        self.species = species_in_cluster.sample(n=1).iloc[0]["shortName"]
        self.color = shortname_to_color(self.species, cluster)


class ForestEnv(gym.Env):
    metadata = {"render_modes": ["human", "rgb_array"], "render_fps": 4}

    def __init__(self, render_mode=None, size=10, num_seedlings=10, process_index=1):

        self.size = size  # The size of the square grid
        self.window_size = 512  # The size of the PyGame window
        self.num_seedlings = num_seedlings  # The number of seedlings to plant

        self.seedlings: list[Seedling] = []
        self.previous_carbon = 0.0  # Previous carbon storage for reward calculation

        self.process_index = process_index  # Process index for file management
        self._set_up_process_files()

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

    def _set_up_process_files(self):
        base_dir = "/home/main/iland-model/data/"
        process_dir = os.path.join(base_dir, f"process_{self.process_index}")

        # Create the directory if it doesn't exist
        os.makedirs(process_dir, exist_ok=True)

        # Clear the directory
        for filename in os.listdir(process_dir):
            file_path = os.path.join(process_dir, filename)
            try:
                if os.path.isfile(file_path):
                    os.remove(file_path)
                elif os.path.isdir(file_path):
                    os.rmdir(file_path)
            except Exception as e:
                print(f"Error deleting file {file_path}: {e}")

        # Copy the xml file to the process directory
        xml_file = "/home/main/iland-model/data/project.xml"
        dest_xml_file = os.path.join(process_dir, "project.xml")
        try:
            if os.path.isfile(dest_xml_file):
                os.remove(dest_xml_file)
            shutil.copy(xml_file, dest_xml_file)
        except Exception as e:
            print(f"Error copying file {xml_file} to {dest_xml_file}: {e}")

        self.xml_path = dest_xml_file
        self.process_dir = process_dir

        # Read the xml file to change a few parameters
        try:
            tree = ET.parse(self.xml_path)
            root = tree.getroot()

            # Print the elements in the root
            for elem in root.iter():
                if elem.text == "output.sqlite":
                    elem.text = os.path.join(process_dir, "output.sqlite")
                    print("Found output.sqlite, changed to:", elem.text)

            # Write the changes back to the XML file
            tree.write(self.xml_path)

        except ET.ParseError as e:
            print(f"Error parsing XML file: {e}")
        except Exception as e:
            print(f"Error: {e}")

    def _get_obs(self):
        obs = np.zeros((self.size, self.size, 3), dtype=np.uint8)

        # Draw the seedlings
        for seedling in self.seedlings:
            obs[seedling.y, seedling.x] = shortname_to_color(
                seedling.species, seedling.cluster
            )

        # Now draw the agent as a white pixel
        obs[self._agent_location[1], self._agent_location[0]] = (255, 255, 255)

        return obs

    def _get_info(self):
        return {
            "remaining_seedlings": self.num_seedlings - len(self.seedlings),
        }

    def reset(self, seed=None, options=None):
        # We need the following line to seed self.np_random
        super().reset(seed=seed)

        # Choose the agent's location uniformly at random
        self._agent_location = self.np_random.integers(0, self.size, size=2, dtype=int)
        self.previous_carbon = 0.0  # Reset previous carbon storage
        self.seedlings = []  # Reset seedlings

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
            observation = self._get_obs()
            info = self._get_info()

            if self.render_mode == "human":
                self._render_frame()

            return observation, 0.0, False, False, info
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

        # Initialize the simulation with the updated seedlings
        self.initialize(os.path.join(self.process_dir, "seedling_init.txt"))

        # Run the simulation
        sim_success = self.run_simulation()

        if not sim_success:
            # Simulation failed
            reward = -10.0  # Larger penalty for simulation failure
            terminated = True  # End the episode
            truncated = True
            return self._get_obs(), reward, terminated, truncated, info

        # Read the simulation results
        tree_data, current_carbon = self.read_output()

        # If tree_data is None, simulation gave no valid output
        if tree_data is None:
            reward = -5.0  # Penalty for invalid output
            terminated = True
            truncated = True
            return self._get_obs(), reward, terminated, truncated, info

        # Calculate reward as the improvement in carbon storage
        carbon_improvement = current_carbon - self.previous_carbon
        reward = (
            carbon_improvement  # Reward is directly proportional to carbon improvement
        )

        # Update previous carbon for next step
        self.previous_carbon = current_carbon

        # An episode is done iff the agent has planted the max seedlings
        terminated = len(self.seedlings) >= self.num_seedlings
        observation = self._get_obs()
        info = self._get_info()

        if self.render_mode == "human":
            self._render_frame()

        return observation, reward, terminated, False, info

    def render(self):
        if self.render_mode == "rgb_array":
            return self._render_frame()

    def initialize(self, path="data/seedling_init.txt"):
        """
        Generate a .txt file that specifies the initial list of trees present in the stand.
        This is loaded by iLand to initialize the stand before it simulates growth.
        Overwrite the file if it already exists.
        Each line in the file, except for the first one, represents a seedling.
        The first line is: x;y;species;dbh;height;age

        Example file has contents:
        x;y;species;dbh;height;age
        31.11;8.01;piab;42.2;29.7;120
        21.11;15.11;piab;52.8;33.5;0
        11.51;25.11;fasy;55;35;100;1
        """
        # Ensure the directory exists
        os.makedirs(os.path.dirname(path), exist_ok=True)

        # Write the header and seedling data to the file
        with open(path, "w") as f:
            f.write("x;y;species;dbh;height;age\n")

            # Write each seedling
            for seedling in self.seedlings:
                x = seedling.x
                y = seedling.y
                species = seedling.species
                # Initial DBH (Diameter at Breast Height), height, and age
                # These are set to small values for seedlings
                dbh = 2.0  # 2 cm
                height = 1.0  # 1 meter
                age = 0  # Just planted

                f.write(f"{x:.2f};{y:.2f};{species};{dbh:.1f};{height:.1f};{age}\n")

        return path

    def run_simulation(self, path="build/python_interface", years=10):
        """
        Run the executable in the path. Wait for it to finish.
        The executable is iLand, which simulates the growth of the forest stand.
        It reads from the text file created by the initialize() method.
        """

        try:
            # Run the command and wait for it to complete
            args = [path, self.xml_path, str(years)]
            result = subprocess.run(args, check=True, capture_output=True, text=True)

            # Check if the simulation was successful
            if result.returncode == 0:
                print(result.stdout)
                print(result.stderr)
                return True
            else:
                print(f"Simulation failed with return code {result.returncode}")
                print(f"Error output: {result.stderr}")
                return False

        except subprocess.CalledProcessError as e:
            print(f"Error running simulation: {e}")
            return False
        except Exception as e:
            print(f"Unexpected error: {e}")
            return False

    def read_output(self) -> tuple[pd.DataFrame, float]:
        """
        Read the output from the SQLite database file.
        The database file is created by the simulation.

        Returns:
            tuple: A tuple containing the tree data and the total carbon in the final year.
        """
        # Read the tree data from the SQLite database
        tree_data = read_table(
            db_path=os.path.join(self.process_dir, "output.sqlite"), table_name="tree"
        )

        if tree_data is None:
            print("Error: Could not read the tree table.")
            return None, 0.0

        # Find the maximum year in the dataset
        final_year = tree_data["year"].max()

        # Calculate the total carbon in the final year
        total_carbon = get_total_carbon(tree_data, final_year)

        return tree_data, total_carbon

    def _render_frame(self):
        if self.window is None and self.render_mode == "human":
            pygame.init()
            pygame.display.init()
            self.window = pygame.display.set_mode((self.window_size, self.window_size))
        if self.clock is None and self.render_mode == "human":
            self.clock = pygame.time.Clock()

        canvas = pygame.Surface((self.window_size, self.window_size))

        obs = self._get_obs()

        # Fill the canvas with the observation
        for y in range(self.size):
            for x in range(self.size):
                color = obs[y, x]
                pygame.draw.rect(
                    canvas,
                    color,
                    (
                        x * (self.window_size // self.size),
                        y * (self.window_size // self.size),
                        self.window_size // self.size,
                        self.window_size // self.size,
                    ),
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
    env = ForestEnv(render_mode="human", size=25, num_seedlings=100)
    obs, info = env.reset()
    done = False
    while not done:
        action = env.action_space.sample()
        action = get_action_from_keyboard_input()
        obs, reward, done, _, info = env.step(action)
        print(f"Action: {action}, Reward: {reward}, Info: {info}")
