import numpy as np
import gymnasium as gym
from gymnasium import spaces
from matplotlib import pyplot as plt
import subprocess
import os
import sqlite3
import pandas as pd


def read_table(db_path="output.sqlite", table_name="stand") -> pd.DataFrame:
    """
    Read the contents of the 'stand' table from the SQLite database file.

    Args:
        db_path (str): Path to the SQLite database file

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

        self.action_space = spaces.Box(-1, 1, shape=(3,), dtype=np.float32)

        self.observation_space = spaces.Box(
            low=0,
            high=len(species_names),
            shape=(grid_size, grid_size, 1),
            dtype=np.uint8,
        )

    def get_observation(self):
        """
        The observation is a grid of size grid_size x grid_size,
        where each cell contains the index of the species planted at that location.
        If no species is planted, the cell contains 0.
        """
        obs = np.zeros((self.grid_size, self.grid_size, 1), dtype=np.uint8)

        # Populate the observation grid with species data
        for seedling in self.seedlings_planted:
            x, y = int(seedling[0]), int(seedling[1])
            species_index = self.species_names.index(seedling[2])
            obs[x, y, 0] = species_index

        return obs

    def reset(self, seed=None, options=None) -> np.ndarray:
        """
        Return an empty observation and empty info upon reset.
        """
        super().reset(seed=seed)

        self.seedlings_planted = []
        self.previous_carbon = 0.0
        self.current_carbon = 0.0
        obs = self.get_observation()
        return obs, {}

    def initialize(self, path="data/seedling_init.txt"):
        """
        Generate a .txt file that specifies the initial list of trees present in the stand.
        Overwrite the file if it already exists.
        The first line is: x;y;species;dbh;height;age

        Example file has contents:
        x;y;species;dbh;height;age
        31.11;8.01;piab;42.2;29.7;120
        21.11;15.11;piab;52.8;33.5;0
        11.51;25.11;fasy;55;35;100;1
        """

        # Check if the file exists
        if os.path.isfile(path):
            print(f"File '{path}' already exists. Overwriting it.")

        # Open the file in write mode
        with open(path, "w") as f:
            # Write the header
            f.write("x;y;species;dbh;height;age\n")

            for seedling in self.seedlings_planted:
                x, y, species = seedling
                dbh = 3.0
                height = 2.0
                age = 1.0

                f.write(f"{x:.2f};{y:.2f};{species};{dbh:.2f};{height:.2f};{age:.2f}\n")

    def run_simulation(path="build/python_interface"):
        """
        Run the executable in the path. Wait for it to finish."""

        # Check if the file exists
        if not os.path.isfile(path):
            print(f"Error: Executable file '{path}' not found.")
            return None

        try:
            # Run the executable
            result = subprocess.run([path], check=True, capture_output=True, text=True)

            # Print the output
            print(result.stdout)
            print(result.stderr)

        except subprocess.CalledProcessError as e:
            print(f"Error: {e}")
            return None

        return result

    def read_output(self) -> tuple[pd.DataFrame, float]:
        """
        Read the output from the SQLite database file.
        The database file is created by the simulation.

        Returns:
            tuple: A tuple containing the tree data and the total carbon in the final year.
        """

        # This is a pandas dataframe that contains the following columns:
        # 'year', 'ru', 'rid', 'species', 'id', 'x', 'y', 'dbh', 'height',
        #   'basalArea', 'volume_m3', 'age', 'leafArea_m2', 'foliageMass',
        #   'stemMass', 'branchMass', 'fineRootMass', 'coarseRootMass', 'lri',
        #   'lightResponse', 'stressIndex', 'reserve_kg', 'treeFlags'
        tree_data = read_table(table_name="tree")

        if tree_data is None:
            print("Error: Could not read the tree table.")
            return

        # Print the number of rows
        print(f"Found {len(tree_data)} rows in the tree table.")

        # Print the data
        print("\ntree table contents:")
        print(tree_data)

        final_year = tree_data["year"].max()
        print(f"\nFinal year: {final_year}")

        total_carbon = get_total_carbon(tree_data, final_year)

        print(f"Total carbon in the final year: {total_carbon:.2f} kg")

        return tree_data, total_carbon

    def step(self, action):
        """
        Execute one time step within the environment.
        The action is a vector of length 2 representing the x and y coordinates
        where the agent wants to plant a seedling.
        """
        # Convert action to coordinates
        x = int((action[0] + 1) / 2 * self.grid_size)
        y = int((action[1] + 1) / 2 * self.grid_size)
        x = min(max(x, 0), self.grid_size - 1)
        y = min(max(y, 0), self.grid_size - 1)
        species_index = int((action[2] + 1) / 2 * (len(self.species_names) - 1))

        # Plant a seedling at the specified coordinates
        seedling = [x, y, self.species_names[species_index]]
        self.seedlings_planted.append(seedling)

        # The simulation stops when the maximum number of seedlings is planted
        terminated = False
        truncated = len(self.seedlings_planted) >= self.total_seedlings

        # Initialize the stand with the planted seedlings
        self.initialize()

        # Simulate the growth of the forest stand
        result = self.run_simulation()

        if result is None:
            print("Simulation failed to run.")
            return None

        tree_data, total_carbon = self.read_output()
        self.current_carbon = total_carbon

        reward = self.current_carbon - self.previous_carbon
        self.previous_carbon = self.current_carbon

        info = {}

        return (self.get_observation(), reward, terminated, truncated, info)

    def render(self):
        """
        Render the environment.
        In this case, we will just print the current state of the forest stand.
        """

        if self.render_mode == "console":
            print("Current state of the forest stand:")
            obs = self.get_observation()
            print(obs)
        elif self.render_mode == "human":
            fig, ax = plt.subplots()
            ax.imshow(self.get_observation(), cmap="viridis")
            ax.set_title(f"Iteration {len(self.seedlings_planted)}")
            plt.savefig("output/latest.png")

    def close(self):
        """
        Close the environment.
        In this case, we will just print a message.
        """
        print("Closing the environment.")
