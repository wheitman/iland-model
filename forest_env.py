"""
forest_env.py - Complete implementation of the Forest Environment for RL
"""

import random
import numpy as np
import gymnasium as gym
from gymnasium import spaces
import matplotlib

matplotlib.use("Agg")
from matplotlib import pyplot as plt
import subprocess
import os
import sqlite3
import pandas as pd
from skimage.draw import random_shapes


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


class ForestEnv(gym.Env):
    """
    Custom Environment that follows gymnasium interface.
    The agent learns to plant seedlings to optimise total carbon capture after some years.
    """

    metadata = {"render_modes": ["console", "human"]}

    def __init__(
        self,
        species_names: list[str],
        render_mode=None,
        years=10,
        num_seedlings=100,
        grid_size=100,
    ):
        super(ForestEnv, self).__init__()
        self.render_mode = render_mode
        self.years = years
        self.grid_size = grid_size
        self.total_seedlings = num_seedlings
        self.seedlings_planted = []
        self.previous_carbon = 0.0
        self.species_names = species_names
        self.keepout = self.get_random_keepout_mask(grid_size)

        self.action_space = spaces.Box(-1, 1, shape=(3,), dtype=np.float32)

        # Modified observation space to encode species information
        # Values:
        # 0: Empty plantable space
        # 1: Keepout area
        # 2+: Planted seedlings (value = species_index + 2)
        #
        # Using channel-first format for CnnPolicy compatibility
        self.observation_space = spaces.Box(
            low=0,
            high=len(species_names) + 2,  # Maximum value is number of species + 2
            shape=(self.grid_size, self.grid_size, 1),  # Keep as 3D tensor for CNN
            dtype=np.uint8,
        )

        self.num_failed_plantings = 0

    def get_random_keepout_mask(self, size):

        if random.random() < 0.5:
            # Create a random keepout mask with shapes.
            # Trees can only be planted OUTSIDE the shapes.
            # The shapes represent areas where trees cannot be planted,
            # such as roads or buildings.
            image, labels = random_shapes(
                (size, size),
                max_shapes=10,
                min_shapes=1,
                min_size=size // 8,
                max_size=size // 4,
                allow_overlap=True,
                channel_axis=None,
            )

            # This is the area not populated by any shape
            mask = image < 255

        else:
            # Create a random mask with shapes
            # Trees can only be planted WITHIN the shapes
            # in this case. This is to mimick the circles found in
            # Miyawaki forests.
            image, labels = random_shapes(
                (size, size),
                max_shapes=10,
                min_shapes=1,
                min_size=size // 4,
                max_size=size // 2,
                allow_overlap=False,
                channel_axis=None,
                shape="circle",
            )

            # This is the area that IS populated by any shape
            mask = image == 255

        return mask

    def get_observation(self):
        """
        Returns the current state of the environment as an observation.
        The observation is a grid where each cell represents either:
        - Empty space where seedlings can be planted (0)
        - Keepout area where seedlings cannot be planted (1)
        - Planted seedlings (2 + species_index)
        """
        # Initialize observation grid with zeros
        obs = np.zeros((self.grid_size, self.grid_size), dtype=np.uint8)

        # Mark keepout areas with 1
        obs[~self.keepout] = 1

        # Mark planted seedlings with their species index + 2
        for x, y, species_idx in self.seedlings_planted:
            # Convert from real coordinates to grid indices
            grid_x = int(min(max(0, x), self.grid_size - 1))
            grid_y = int(min(max(0, y), self.grid_size - 1))
            # Set the value to species_idx + 2 (so species 0 becomes 2, species 1 becomes 3, etc.)
            obs[grid_y, grid_x] = species_idx + 2

        # Reshape to match observation space (add channel dimension)
        return obs.reshape(self.grid_size, self.grid_size, 1)

    def reset(self, seed=None, options=None):
        """
        Reset the environment to its initial state.

        Args:
            seed: Random seed
            options: Additional options

        Returns:
            observation: Initial observation
            info: Additional information
        """
        # Reset RNG if seed is provided
        if seed is not None:
            np.random.seed(seed)
            random.seed(seed)

        # Reset state
        self.seedlings_planted = []
        self.previous_carbon = 0.0
        self.num_failed_plantings = 0

        # Generate a new random keepout mask
        self.keepout = self.get_random_keepout_mask(self.grid_size)

        # Return initial observation and info
        info = {"planted_seedlings": 0, "total_carbon": 0.0}
        return self.get_observation(), info

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
            for x, y, species_idx in self.seedlings_planted:
                species = self.species_names[species_idx]
                # Initial DBH (Diameter at Breast Height), height, and age
                # These are set to small values for seedlings
                dbh = 2.0  # 2 cm
                height = 1.0  # 1 meter
                age = 0  # Just planted

                f.write(f"{x:.2f};{y:.2f};{species};{dbh:.1f};{height:.1f};{age}\n")

        return path

    def run_simulation(self, path="build/python_interface"):
        """
        Run the executable in the path. Wait for it to finish.
        The executable is iLand, which simulates the growth of the forest stand.
        It reads from the text file created by the initialize() method.
        """

        try:
            # Run the command and wait for it to complete
            result = subprocess.run(path, check=True, capture_output=True, text=True)

            # Check if the simulation was successful
            if result.returncode == 0:
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
        tree_data = read_table(table_name="tree")

        if tree_data is None:
            print("Error: Could not read the tree table.")
            return None, 0.0

        # Find the maximum year in the dataset
        final_year = tree_data["year"].max()

        # Calculate the total carbon in the final year
        total_carbon = get_total_carbon(tree_data, final_year)

        return tree_data, total_carbon

    def get_smallest_seedling_distance(self):
        """
        Calculate the smallest distance between all planted seedlings.
        """
        if len(self.seedlings_planted) < 2:
            return float("inf")
        distances = []
        for i in range(len(self.seedlings_planted)):
            for j in range(i + 1, len(self.seedlings_planted)):
                dist = np.linalg.norm(
                    np.array(self.seedlings_planted[i][:2])
                    - np.array(self.seedlings_planted[j][:2])
                )
                distances.append(dist)
        return min(distances) if distances else float("inf")

    def step(self, action):
        """
        Take a step in the environment by planting a seedling at the specified location.

        Args:
            action: A 3D vector of [-1, 1] values representing:
                    [x_position, y_position, species]

        Returns:
            observation: The updated state
            reward: The reward for taking this action
            terminated: Whether the episode is done
            truncated: Whether the episode was truncated
            info: Additional information
        """
        # Normalize action from [-1, 1] to grid coordinates and species
        x_norm = (action[0] + 1) / 2  # Convert from [-1, 1] to [0, 1]
        y_norm = (action[1] + 1) / 2  # Convert from [-1, 1] to [0, 1]

        # Convert to grid coordinates
        x = x_norm * self.grid_size
        y = y_norm * self.grid_size

        # Convert species index from [-1, 1] to [0, len(species_names)-1]
        species_norm = (action[2] + 1) / 2  # Convert from [-1, 1] to [0, 1]
        species_idx = int(species_norm * (len(self.species_names) - 1))

        # Round to ensure it's a valid index
        species_idx = max(0, min(species_idx, len(self.species_names) - 1))

        # Check if the planting location is valid (within keepout mask)
        grid_x = int(min(max(0, x), self.grid_size - 1))
        grid_y = int(min(max(0, y), self.grid_size - 1))

        valid_planting = (
            self.keepout[grid_y, grid_x] and self.get_smallest_seedling_distance() > 0.5
        )

        info = {
            "planted_seedlings": len(self.seedlings_planted),
            "valid_planting": valid_planting,
            "location": (x, y),
            "species": self.species_names[species_idx],
            "species_idx": species_idx,
        }

        if not valid_planting:
            # Invalid planting location (in keepout area)
            self.num_failed_plantings += 1
            reward = -10.0  # Penalty for planting in invalid location
            terminated = False
            truncated = (
                self.num_failed_plantings > 10
            )  # Truncate if too many failed plantings

            # Return current observation without updating
            return self.get_observation(), reward, terminated, truncated, info

        # Add the seedling to our list
        self.seedlings_planted.append((x, y, species_idx))

        # Initialize the simulation with the updated seedlings
        self.initialize()

        # Run the simulation
        sim_success = self.run_simulation()

        if not sim_success:
            # Simulation failed
            reward = -10.0  # Larger penalty for simulation failure
            terminated = True  # End the episode
            truncated = True
            return self.get_observation(), reward, terminated, truncated, info

        # Read the simulation results
        tree_data, current_carbon = self.read_output()

        # If tree_data is None, simulation gave no valid output
        if tree_data is None:
            reward = -5.0  # Penalty for invalid output
            terminated = True
            truncated = True
            return self.get_observation(), reward, terminated, truncated, info

        # Calculate reward as the improvement in carbon storage
        carbon_improvement = current_carbon - self.previous_carbon
        reward = (
            carbon_improvement  # Reward is directly proportional to carbon improvement
        )

        # Update previous carbon for next step
        self.previous_carbon = current_carbon

        # Check if we've planted all seedlings
        terminated = len(self.seedlings_planted) >= self.total_seedlings
        truncated = False

        # Update info
        info["total_carbon"] = current_carbon
        info["carbon_improvement"] = carbon_improvement

        return self.get_observation(), reward, terminated, truncated, info

    def render(self):
        """
        Render the environment.

        If render_mode is "console", print the state to console.
        If render_mode is "human", display the state graphically.
        """
        if self.render_mode is None:
            return

        obs = self.get_observation()

        if self.render_mode == "console":
            print(
                f"Seedlings planted: {len(self.seedlings_planted)}/{self.total_seedlings}"
            )
            print(f"Total carbon: {self.previous_carbon:.2f} kg")

            # Print a simplified view of the forest
            grid = np.zeros((self.grid_size, self.grid_size), dtype=str)
            grid.fill(".")  # Empty space
            grid[~self.keepout] = "X"  # Keepout areas

            for x, y, species_idx in self.seedlings_planted:
                grid_x = int(min(max(0, x), self.grid_size - 1))
                grid_y = int(min(max(0, y), self.grid_size - 1))
                # Use a letter for each species (A for species 0, B for species 1, etc.)
                species_letter = chr(65 + species_idx % 26)  # A-Z for species
                grid[grid_y, grid_x] = species_letter

            # Print a subset of the grid to avoid flooding the console
            subset_size = min(20, self.grid_size)
            for i in range(subset_size):
                row = grid[i * self.grid_size // subset_size]
                print(
                    "".join(
                        row[j * self.grid_size // subset_size]
                        for j in range(subset_size)
                    )
                )

            # Print species legend
            print("\nSpecies Legend:")
            for i, species in enumerate(self.species_names):
                species_letter = chr(65 + i % 26)
                print(f"{species_letter}: {species}")

        elif self.render_mode == "human":
            # Create a color-coded visualization
            plt.figure(figsize=(10, 10))

            # Create an RGB image
            rgb_img = np.zeros((self.grid_size, self.grid_size, 3), dtype=np.uint8)

            # Set different colors for different elements
            # Keepout areas (red)
            rgb_img[~self.keepout] = [255, 0, 0]

            # Define a distinct color palette for different species
            # Using HSV color space for better color separation
            species_colors = []
            for i in range(len(self.species_names)):
                # Distribute hues evenly around the color wheel
                hue = i / len(self.species_names)
                # Convert HSV to RGB (simplified conversion)
                if hue < 1 / 6:
                    r, g, b = 255, int(255 * 6 * hue), 0
                elif hue < 2 / 6:
                    r, g, b = int(255 * (2 - 6 * hue)), 255, 0
                elif hue < 3 / 6:
                    r, g, b = 0, 255, int(255 * (6 * hue - 2))
                elif hue < 4 / 6:
                    r, g, b = 0, int(255 * (4 - 6 * hue)), 255
                elif hue < 5 / 6:
                    r, g, b = int(255 * (6 * hue - 4)), 0, 255
                else:
                    r, g, b = 255, 0, int(255 * (6 - 6 * hue))
                species_colors.append([r, g, b])

            # Planted seedlings with species-specific colors
            for x, y, species_idx in self.seedlings_planted:
                grid_x = int(min(max(0, x), self.grid_size - 1))
                grid_y = int(min(max(0, y), self.grid_size - 1))

                # Use the pre-defined color for this species
                color = species_colors[species_idx % len(species_colors)]
                rgb_img[grid_y, grid_x] = color

            plt.imshow(rgb_img)
            plt.title(
                f"Seedlings: {len(self.seedlings_planted)}/{self.total_seedlings}, Carbon: {self.previous_carbon:.2f} kg"
            )

            # Add a legend for species colors
            from matplotlib.patches import Patch

            legend_elements = [
                Patch(
                    facecolor=np.array(species_colors[i]) / 255,
                    label=f"{self.species_names[i]}",
                )
                for i in range(len(self.species_names))
            ]
            plt.legend(handles=legend_elements, loc="lower right", title="Species")

            plt.axis("off")
            plt.tight_layout()

            plt.pause(0.01)  # Small pause to update display

    def close(self):
        if self.render_mode == "human":
            plt.close("all")
