"""Copy the verified V7 vendor tree to D:; never execute update or firmware code."""
from pathlib import Path, PurePosixPath
import hashlib
import json
import os
import shutil

ROOT = Path(__file__).resolve().parents[1]
BASE = ROOT / 'analiz/native-ui-candidate/v7-tv'
SOURCE = BASE / 'vendor-rar-readback'
DEST = Path('D:/')
IMAGE_SHA = '3291477403bd9d1961a1e27a45d974fcb7e1bdef54bacc676e10c11bfb0c5e71'


def digest(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def main():
    if os.name != 'nt' or DEST.resolve() != Path('D:/') or not DEST.is_dir():
        raise ValueError('Expected the explicitly requested D: destination')
    report = json.loads((BASE / 'package/vendor-rar-validation.json').read_text(encoding='utf-8'))
    if report['files_verified'] != 17 or report['directories_verified'] != 11:
        raise ValueError('Unexpected vendor tree inventory')
    expected_files = {row['path']: row['sha256'] for row in report['extracted_members']}
    if expected_files.get('Target_GM/image/GM_SWImage.bin') != IMAGE_SHA:
        raise ValueError('Wrong V7 image identity')
    paths = sorted(SOURCE.rglob('*'))
    directories = [p.relative_to(SOURCE).as_posix() for p in paths if p.is_dir()]
    files = [p.relative_to(SOURCE).as_posix() for p in paths if p.is_file()]
    if set(files) != set(expected_files) or len(directories) != 11:
        raise ValueError('Source inventory changed')
    for rel in directories + files:
        if PurePosixPath(rel).is_absolute() or '..' in PurePosixPath(rel).parts:
            raise ValueError('Unsafe relative path')
        source, target = SOURCE / rel, DEST / rel
        if source.is_symlink() or (hasattr(source, 'is_junction') and source.is_junction()):
            raise ValueError('Aliased source')
        if not target.resolve().is_relative_to(DEST) or target.exists() or target.is_symlink():
            raise FileExistsError('Refusing existing or aliased USB destination: ' + str(target))
    for rel, expected in expected_files.items():
        if digest(SOURCE / rel) != expected:
            raise ValueError('Source file changed: ' + rel)
    for rel in sorted(directories, key=lambda value: (value.count('/'), value)):
        (DEST / rel).mkdir()
    verified = []
    for rel, expected in expected_files.items():
        with (SOURCE / rel).open('rb') as source, (DEST / rel).open('xb') as target:
            shutil.copyfileobj(source, target, length=1024 * 1024)
            target.flush()
            os.fsync(target.fileno())
        actual = digest(DEST / rel)
        if actual != expected:
            raise ValueError('USB readback differs: ' + rel)
        verified.append(dict(path=rel, sha256=actual))
    output = dict(status='COPY_AND_HOST_READBACK_PASS', destination='D:/',
                  expected_image_path='D:/Target_GM/image/GM_SWImage.bin',
                  v7_sha256=IMAGE_SHA, files_verified=len(verified), directories_created=len(directories),
                  files=verified, format_performed=False, preexisting_files_modified=False,
                  versions_changed=False, firmware_executed=False, television_written=False,
                  television_acceptance_verified=False,
                  filesystem_scan='Read-only CHKDSK reported no file-system problems before copy.',
                  prior_volume_dirty_flag=True,
                  limits=['Host readback does not establish target TV acceptance.',
                          'Windows reported a dirty flag before copy; disk hardware status was Healthy.',
                          'No disk repair, formatting, or firmware update command was run.'])
    (BASE / 'package/usb-drive-D-validation.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({key: output[key] for key in ('status', 'destination', 'expected_image_path',
                     'files_verified', 'directories_created', 'v7_sha256', 'television_acceptance_verified')}))


if __name__ == '__main__':
    main()
