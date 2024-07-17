import requests
import zipfile
import os

# Configuration
REPO_OWNER = "NyTekCFW"
REPO_NAME = "OpenMLX"
CURRENT_VERSION_FILE = "version.txt"
DOWNLOAD_DIR = "."

# Fonction pour obtenir la version actuelle
def get_current_version():
    with open(CURRENT_VERSION_FILE, "r") as f:
        return f.read().strip()

# Fonction pour obtenir la dernière version sur GitHub
def get_latest_version():
    url = f"https://api.github.com/repos/{REPO_OWNER}/{REPO_NAME}/releases/latest"
    response = requests.get(url)
    data = response.json()
    return data["tag_name"]

# Fonction pour télécharger la dernière version
def download_latest_version(latest_version):
    url = f"https://github.com/{REPO_OWNER}/{REPO_NAME}/archive/refs/tags/{latest_version}.zip"
    response = requests.get(url)
    zip_path = os.path.join(DOWNLOAD_DIR, f"{REPO_NAME}-{latest_version}.zip")
    with open(zip_path, "wb") as f:
        f.write(response.content)
    return zip_path

# Fonction pour extraire le fichier ZIP téléchargé
def extract_zip(zip_path, extract_to="."):
    with zipfile.ZipFile(zip_path, "r") as zip_ref:
        zip_ref.extractall(extract_to)

# Fonction principale pour mettre à jour
def update():
    current_version = get_current_version()
    latest_version = get_latest_version()

    print(f"Current version: {current_version}")
    print(f"Latest version: {latest_version}")

    if current_version != latest_version:
        print("Updating to the latest version...")
        zip_path = download_latest_version(latest_version)
        extract_zip(zip_path)
        os.remove(zip_path)  # Supprime le fichier ZIP après extraction
        with open(CURRENT_VERSION_FILE, "w") as f:
            f.write(latest_version)
        print("Update completed.")
    else:
        print("You already have the latest version.")

if __name__ == "__main__":
    if not os.path.exists(DOWNLOAD_DIR):
        os.makedirs(DOWNLOAD_DIR)
    update()

