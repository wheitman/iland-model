import pandas as pd
import numpy as np
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt
import seaborn as sns
from collections import defaultdict
import sqlite3
import os


# These are the species for which we have light
# interference patterns (LIPs)
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


def get_species_params(filtered_shortnames=None) -> pd.DataFrame:
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

        if filtered_shortnames is not None:

            df = df[df["shortName"].isin(filtered_shortnames)]

        return df

    except sqlite3.Error as e:
        print(f"SQLite error: {e}")
    except Exception as e:
        print(f"Error: {e}")

    return []


def cluster(df, features, n_components=4, n_clusters=8):

    X = df[features].values

    # Standardize the features
    scaler = StandardScaler()
    X_scaled = scaler.fit_transform(X)

    # Perform PCA
    pca = PCA(n_components=n_components)
    X_pca = pca.fit_transform(X_scaled)

    pca_df = pd.DataFrame(data=X_pca, columns=[f"PC{i+1}" for i in range(n_components)])
    pca_df["shortName"] = df["shortName"].values

    # Now cluster
    kmeans = KMeans(n_clusters=n_clusters, random_state=64)
    clusters = kmeans.fit_predict(X_pca)
    pca_df["cluster"] = clusters

    # Get the explained variance ratio
    explained_variance = pca.explained_variance_ratio_

    return pca_df, explained_variance, kmeans


def plot_clusters(pca_df, kmeans, features):
    """
    Plot the clusters in 2D space using the first two principal components.
    """
    plt.figure(figsize=(5, 5))
    sns.scatterplot(
        data=pca_df,
        x="PC1",
        y="PC2",
        hue="cluster",
        palette="Set1",
        s=100,
        alpha=0.7,
        edgecolor="k",
    )
    plt.title("Clusters of Species based on PCA")
    plt.xlabel("Principal Component 1")
    plt.ylabel("Principal Component 2")
    plt.legend(title="Cluster")
    plt.savefig("species_clusters.png", dpi=600)
    plt.show()


if __name__ == "__main__":

    df = get_species_params(filtered_shortnames=shortnames)

    # Features to use for clustering
    features = [
        # "isConiferous",
        # "isEvergreen",
        "specificLeafArea",
        "turnoverLeaf",
        "turnoverRoot",
        "formFactor",
        "probIntrinsic",
        "probStress",
        "lightResponseClass",
    ]

    pca_df, explained_variance, kmeans = cluster(
        df, features, n_components=4, n_clusters=6
    )

    print(pca_df)
    print(f"Explained variance: {explained_variance}")

    # Plot the clusters
    plot_clusters(pca_df, kmeans, features)

    # Save the PCA DataFrame to a CSV file
    pca_df.to_csv("pca_species_clusters.csv", index=False)
