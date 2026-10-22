"""Extract UBIFS on Linux storage and retain a complete tar in the workspace."""
from pathlib import Path
import hashlib
import json
import shutil
import struct
import subprocess
import tarfile

ROOT = Path(__file__).resolve().parents[1]
WORK = Path('/home/semih/.local/share/grundig-analysis/full-v1')
READER = Path('/home/semih/.local/share/uv/tools/unblob/bin/ubireader_extract_files')

if __name__ == '__main__':
    if WORK.exists():
        raise FileExistsError(WORK)
    images, files, logs = (WORK / name for name in ('images', 'files', 'logs'))
    for directory in (images, files, logs):
        directory.mkdir(parents=True)
    records = []
    for original in sorted((ROOT / 'analiz/bolumler').glob('*.bin')):
        with original.open('rb') as stream:
            header = stream.read(64)
        if not header.startswith(b'\x31\x18\x10\x06'):
            continue
        copied = images / original.name
        shutil.copyfile(original, copied)
        leb_size = struct.unpack_from('<I', header, 36)[0]
        destination = files / original.stem
        logfile = logs / f'{original.stem}.log'
        command = [str(READER), '-e', str(leb_size), '-o', str(destination), str(copied)]
        with logfile.open('w') as output:
            completed = subprocess.run(command, stdout=output, stderr=subprocess.STDOUT,
                                       timeout=300, check=False)
        records.append({'volume': original.stem, 'source': str(original),
                        'linux_output': str(destination), 'leb_size': leb_size,
                        'exit_code': completed.returncode, 'log': str(logfile)})
        print(f'{original.stem}: extractor exit {completed.returncode}', flush=True)
    archive = ROOT / 'analiz/dosya-sistemleri-tam.tar'
    if archive.exists():
        raise FileExistsError(archive)
    with tarfile.open(archive, 'w', dereference=False) as output:
        for directory in sorted(files.iterdir()):
            output.add(directory, arcname=directory.name, recursive=True)
    for logfile in logs.glob('*.log'):
        shutil.copyfile(logfile, ROOT / 'analiz/loglar' / f'linux-{logfile.name}')
    with archive.open('rb') as stream:
        digest = hashlib.file_digest(stream, 'sha256').hexdigest()
    report = {'canonical_linux_tree': str(files), 'archive': str(archive),
              'archive_sha256': digest, 'volumes': records,
              'limitations': ['Review extractor logs for missing special nodes.',
                              'No root permissions, owner/mode/xattr restoration was requested.',
                              'No extracted target or update script was executed.']}
    (ROOT / 'analiz/ubifs-linux-extraction.json').write_text(
        json.dumps(report, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
