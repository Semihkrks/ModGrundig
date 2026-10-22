"""Unpack the verified Ghidra archive to a private Linux tools directory."""
from pathlib import Path
from zipfile import ZipFile
import hashlib
import os
import stat

ROOT = Path(__file__).resolve().parents[1]
ARCHIVE = ROOT / 'tools/downloads/ghidra_12.1.4_PUBLIC_20260921.zip'
DESTINATION = Path('/home/semih/.local/share/grundig-tools/ghidra')

if __name__ == '__main__':
    if os.name != 'posix':
        raise SystemExit('Use Linux Python.')
    with ARCHIVE.open('rb') as stream:
        digest = hashlib.file_digest(stream, 'sha256').hexdigest()
    if digest != 'ddac49f903da9d5bac833e5cc79395098b9c33cfd3279be5f31bd00387d2d4db':
        raise ValueError('Ghidra archive digest mismatch')
    if DESTINATION.exists():
        raise FileExistsError(DESTINATION)
    with ZipFile(ARCHIVE) as archive:
        for entry in archive.infolist():
            target = (DESTINATION / entry.filename).resolve()
            if not target.is_relative_to(DESTINATION):
                raise ValueError('Archive path escapes destination')
            mode = entry.external_attr >> 16
            if stat.S_ISLNK(mode):
                raise ValueError('Unexpected symlink in Ghidra ZIP')
        archive.extractall(DESTINATION)
        for entry in archive.infolist():
            mode = (entry.external_attr >> 16) & 0o777
            if mode:
                (DESTINATION / entry.filename).chmod(mode)
    print(DESTINATION / 'ghidra_12.1.4_PUBLIC')
