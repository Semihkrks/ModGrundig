"""Extract already decoded UBIFS images on Linux; never execute their contents."""

from pathlib import Path
import json
import os
import struct
import subprocess

ROOT = Path(__file__).resolve().parents[1]
READER = Path('/home/semih/.local/share/uv/tools/unblob/bin/ubireader_extract_files')
OUTPUT = ROOT / 'analiz' / 'dosya-sistemleri'
LOGS = ROOT / 'analiz' / 'loglar'

if __name__ == '__main__':
    if os.name != 'posix':
        raise SystemExit('Run using WSL/Linux Python, not the firmware Python.')
    OUTPUT.mkdir(parents=True, exist_ok=True)
    LOGS.mkdir(parents=True, exist_ok=True)
    records = []
    for image in sorted((ROOT / 'analiz' / 'bolumler').glob('*.bin')):
        header = image.read_bytes()[:64]
        if not header.startswith(b'\x31\x18\x10\x06'):
            continue
        leb_size = struct.unpack_from('<I', header, 36)[0]
        if not 4096 <= leb_size <= 4 * 1024 * 1024:
            raise ValueError(f'Implausible LEB size: {image.name}')
        destination = OUTPUT / image.stem
        if destination.exists():
            raise FileExistsError(destination)
        log = LOGS / f'{image.stem}-ubireader.log'
        command = [str(READER), '-e', str(leb_size), '-o', str(destination), str(image)]
        with log.open('w', encoding='utf-8') as stream:
            result = subprocess.run(command, stdout=stream, stderr=subprocess.STDOUT,
                                    check=False, timeout=180)
        record = {'image': str(image), 'output': str(destination), 'log': str(log),
                  'leb_size': leb_size, 'exit_code': result.returncode,
                  'command': command, 'original_permissions_restored': False}
        records.append(record)
        print(json.dumps(record), flush=True)
    (ROOT / 'analiz' / 'ubifs-extraction.json').write_text(
        json.dumps({'extractor': str(READER), 'volumes': records,
                    'limitations': ['Exit code alone does not prove complete extraction; review logs.',
                                    'No ownership/xattr restoration; not a repackable filesystem tree.']},
                   ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
