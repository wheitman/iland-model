import sqlite3
import time
import pandas as pd

#!/usr/bin/env python3

import os.path
import random

shortnames = [
    "abal",
    "Abam",
    "abba",
    "Abgr",
    "abla",
    "Abpr",
    "absa",
    "acca",
    "acja",
    "Acma",
    "acmo",
    "acne",
    "acpa",
    "acpe",
    "acpl",
    "acps",
    "acru",
    "acsi",
    "acsa",
    "acuk",
    "algl",
    "alhi",
    "alin",
    "alma",
    "Alru",
    "alvi",
    "beal",
    "beer",
    "weer",
    "bele",
    "Bene",
    "bepa",
    "bepe",
    "bepl",
    "bepo",
    "bepu",
    "cano",
    "cabe",
    "caca",
    "caco",
    "carcor",
    "cagl",
    "caov",
    "casa",
    "chch",
    "coco",
    "conu",
    "coav",
    "fagr",
    "fasy",
    "fram",
    "frex",
    "frla",
    "frma",
    "frni",
    "frpe",
    "juai",
    "kase",
    "lade",
    "laka",
    "lala",
    "laly",
    "laoc",
    "lasi",
    "maak",
    "mahy",
    "mapr",
    "moau",
    "osvi",
    "pham",
    "piab_bor",
    "piab",
    "pien",
    "pigl_Alaska",
    "pigl_pasture_NE_America",
    "pigl_NE_America",
    "pigl",
    "pije",
    "pima_alaska",
    "pima_NE_America",
    "piru",
    "Pisi",
    "pial",
    "piba",
    "pice",
    "pico_high",
    "pico",
    "pimo",
    "pimu",
    "pini",
    "Pipo",
    "pipu",
    "pire",
    "pist",
    "pisy_bor",
    "pisy",
    "poba",
    "pogr",
    "poni",
    "posi",
    "potr",
    "potr_alaska",
    "potr_NE_America",
    "potr_yellowstone",
    "poptri",
    "prem",
    "prpe",
    "prsa",
    "prse",
    "prss",
    "psme_gla",
    "psme_men",
    "psme",
    "qual",
    "qubi",
    "quco",
    "qude",
    "quma",
    "qumo",
    "qumont",
    "qupe",
    "qupu",
    "quro",
    "quru",
    "quru_B",
    "quve",
    "rops",
    "saba",
    "saca",
    "soal",
    "soar",
    "soau",
    "soco",
    "tabr",
    "tacu",
    "thoc",
    "Thpl",
    "tiam",
    "tico",
    "tija",
    "tima",
    "tipl",
    "tsca",
    "Tshe",
    "Tsme",
    "ulam",
    "ulgl",
    "ulja",
    "ulla",
    "ulru",
]


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


def get_species_params() -> pd.DataFrame:
    """
    Get species parameters from the SQLite database.

    Returns:
        DataFrame: Contents of the 'species' table
    """
    # Check if the file exists
    if not os.path.isfile("data/all_species_database.sqlite"):
        print("Error: Database file 'output.sqlite' not found.")
        return []

    try:
        # Connect to SQLite database
        conn = sqlite3.connect("data/all_species_database.sqlite")

        # Query the species table
        df = pd.read_sql_query("SELECT * FROM species", conn)

        # Close the connection
        conn.close()

        return df

    except sqlite3.Error as e:
        print(f"SQLite error: {e}")
    except Exception as e:
        print(f"Error: {e}")

    return []


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

    total_carbon = get_total_carbon(tree_data, final_year)

    print(f"Total carbon in the final year: {total_carbon:.2f} kg")

    return tree_data


def generate_init_file(
    species_names, path="data/seedling_init.txt", seedling_count=100
):
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
            species = random.choice(species_names)
            dbh = random.uniform(3.0, 5.0)
            height = random.uniform(1.0, 3.0)
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


def get_available_lips():
    """
    LIPs are stored as .bin files under "data/lip". They follow the scheme
    "data/lip/<shortname>.bin". Return the names of all species with files
    in the directory.
    """
    import os

    # Get the list of all files in the directory
    files = os.listdir("data/lip")

    # Filter the files to get only the .bin files
    bin_files = [f for f in files if f.endswith(".bin")]

    # Extract the short names from the file names
    shortnames = [f.split(".")[0] for f in bin_files]

    return shortnames




if __name__ == "__main__":

    # species_params = get_species_params()

    # if species_params is None or len(species_params) == 0:
    #     print("Error: Could not read the species parameters.")
    #     exit(1)

    # Get unique values from "shortName" column as a list
    # unique_species = species_params["shortName"].unique().tolist()
    # print(f"Unique species: {unique_species}")

    # lips = get_available_lips()
    # print(f"Available LIPs: {lips}")

    # available_species = lips  # Only use species with LIPs

    generate_init_file(
        path="data/seedling_init.txt", species_names=shortnames, seedling_count=300
    )

    start = time.time()
    result = run_process(path="build/python_interface")
    end = time.time()
    print(f"Process took {end - start:.2f} seconds.")

    if result is None:
        print("Error: Could not run the process.")
        exit(1)

    tree_data = read_output()

    carbon = []
    for i in range(11):
        total_carbon = get_total_carbon(tree_data, i)
        print(f"Total carbon in year {i}: {total_carbon:.2f} kg")
        carbon.append(total_carbon)

    # Plot carbon over time
    import matplotlib.pyplot as plt
    import numpy as np

    plt.plot(
        np.arange(0, 11),
        carbon,
        marker="o",
        linestyle="-",
        color="b",
        label="Total Carbon",
    )
    plt.xlabel("Year")
    plt.ylabel("Total Carbon (kg)")
    plt.title("Total Carbon Over Time")
    plt.show()
