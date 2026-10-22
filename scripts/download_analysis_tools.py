"""Download the selected official analysis tools; verify release SHA-256.

This script does not run installers or firmware. Archives remain in the workspace.
"""

from concurrent.futures import ThreadPoolExecutor
from hashlib import sha256
from pathlib import Path
from urllib.request import Request, urlopen

ROOT = Path(__file__).resolve().parents[1]
ASSETS = (
    (
        "ghidra_12.1.4_PUBLIC_20260921.zip",
        "https://github.com/NationalSecurityAgency/ghidra/releases/download/"
        "Ghidra_12.1.4_build/ghidra_12.1.4_PUBLIC_20260921.zip",
        "ddac49f903da9d5bac833e5cc79395098b9c33cfd3279be5f31bd00387d2d4db",
    ),
    (
        "OpenJDK21U-jdk_x64_linux_hotspot_21.0.12.1_1.tar.gz",
        "https://github.com/adoptium/temurin21-binaries/releases/download/"
        "jdk-21.0.12.1%2B1/OpenJDK21U-jdk_x64_linux_hotspot_21.0.12.1_1.tar.gz",
        "ce79869e1307ed8ee1e2baa86a412b1eb5b75d10a01006d788a6f968bcfaee94",
    ),
)


def digest(path: Path) -> str:
    with path.open("rb") as stream:
        return sha256_stream(stream)


def sha256_stream(stream) -> str:
    result = sha256()
    for chunk in iter(lambda: stream.read(1024 * 1024), b""):
        result.update(chunk)
    return result.hexdigest()


def download(asset: tuple[str, str, str]) -> None:
    name, url, expected = asset
    destination = ROOT / "tools" / "downloads" / name
    destination.parent.mkdir(parents=True, exist_ok=True)
    if destination.exists():
        if digest(destination) != expected:
            raise ValueError(f"Existing file digest mismatch: {name}")
        print(f"Already verified: {name}", flush=True)
        return
    temporary = destination.with_suffix(destination.suffix + ".partial")
    request = Request(url, headers={"User-Agent": "Grundig-local-analysis"})
    with urlopen(request, timeout=90) as response, temporary.open("wb") as output:
        for chunk in iter(lambda: response.read(1024 * 1024), b""):
            output.write(chunk)
    if digest(temporary) != expected:
        raise ValueError(f"Downloaded file digest mismatch: {name}")
    temporary.replace(destination)
    print(f"Downloaded and SHA-256 verified: {name}", flush=True)


if __name__ == "__main__":
    with ThreadPoolExecutor(max_workers=2) as executor:
        list(executor.map(download, ASSETS))
