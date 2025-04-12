import sqlite3
import pandas as pd

#!/usr/bin/env python3

import os.path
import random


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


def read_output():

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

    # Sum the branch mass for all trees in the final year
    total_branch_mass = tree_data[tree_data["year"] == final_year]["branchMass"].sum()
    print(f"Total branch mass in the final year: {total_branch_mass:.2f} kg")

    # Same for the stem mass, coarse root mass, and fine root mass
    total_stem_mass = tree_data[tree_data["year"] == final_year]["stemMass"].sum()
    print(f"Total stem mass in the final year: {total_stem_mass:.2f} kg")

    total_coarse_root_mass = tree_data[tree_data["year"] == final_year][
        "coarseRootMass"
    ].sum()
    print(f"Total coarse root mass in the final year: {total_coarse_root_mass:.2f} kg")

    total_fine_root_mass = tree_data[tree_data["year"] == final_year][
        "fineRootMass"
    ].sum()
    print(f"Total fine root mass in the final year: {total_fine_root_mass:.2f} kg")

    total_carbon = (
        total_branch_mass
        + total_stem_mass
        + total_coarse_root_mass
        + total_fine_root_mass
    ) * 0.5  # 50% of the mass is carbon
    print(f"Total carbon in the final year: {total_carbon:.2f} kg")


def generate_init_file(path="data/seedling_init.txt", seedling_count=100):
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

        for i in range(seedling_count):
            x = random.uniform(0, 100)
            y = random.uniform(0, 100)
            species = random.choice(["piab", "fasy"])
            dbh = random.uniform(1.0, 3.0)
            height = random.uniform(0.3, 1.0)
            age = 1.0

            # Write the data
            f.write(f"{x:.2f};{y:.2f};{species};{dbh:.2f};{height:.2f};{age:.2f}\n")


def run_process(path="build/python_interface"):
    """
    Run the executable in the path. Wait for it to finish."""
    import subprocess

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


if __name__ == "__main__":

    generate_init_file(path="data/seedling_init.txt")

    result = run_process(path="build/python_interface")

    if result is None:
        print("Error: Could not run the process.")
        exit(1)

    read_output()
