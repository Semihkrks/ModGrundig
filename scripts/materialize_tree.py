"""Create a Windows-readable regular-file view; keep original links in the tar."""
from pathlib import Path
import json
import shutil
import tarfile

ROOT = Path(__file__).resolve().parents[1]
OUTPUT = ROOT / 'analiz/dosya-sistemleri-tam'

if __name__ == '__main__':
    if OUTPUT.exists():
        raise FileExistsError(OUTPUT)
    metadata = []
    with tarfile.open(ROOT / 'analiz/dosya-sistemleri-tam.tar') as archive:
        for entry in archive:
            target = (OUTPUT / entry.name).resolve()
            if not target.is_relative_to(OUTPUT.resolve()):
                raise ValueError('Unsafe archive path')
            metadata.append({'path': entry.name, 'type': entry.type.decode('ascii'),
                             'mode': entry.mode, 'uid': entry.uid, 'gid': entry.gid,
                             'linkname': entry.linkname, 'size': entry.size})
            if entry.isdir():
                target.mkdir(parents=True, exist_ok=True)
            elif entry.isfile():
                target.parent.mkdir(parents=True, exist_ok=True)
                with archive.extractfile(entry) as source, target.open('xb') as destination:
                    shutil.copyfileobj(source, destination)
    (ROOT / 'analiz/dosya-sistemleri-tam-metadata.json').write_text(
        json.dumps({'entries': metadata, 'limitations': [
            'Tar metadata describes the extracted tree, not original UBIFS ownership/mode.',
            'Links and special files are metadata only in the Windows-readable view.',
            'Canonical Linux tree and tar retain extracted symlinks.']},
                   ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(f'Materialized {sum(x["type"] == "0" for x in metadata)} regular files')
