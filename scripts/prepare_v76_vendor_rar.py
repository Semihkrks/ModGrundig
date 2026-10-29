"""Preserve the vendor RAR4 blocks, replacing only SWImage with stored V7.6 bytes.

No embedded program is executed. Validation uses two independent archive readers
and a new extraction directory. All other compressed member blocks remain exact.
"""
from pathlib import Path, PurePosixPath
import hashlib
import json
import os
import struct
import subprocess
import zipfile
import zlib

from build_native_ui_v76_tv import OUT, ROOT, guard
from inspect_vendor_rar import EXPECTED_SHA, RAR, wsl_path

IMAGE_SHA = 'edcfb3198a67170d29e0ee801525a057a329f3ca769f4226c8d7a709e26f3645'
MEMBER = 'Target_GM/image/GM_SWImage.bin'
DEST = OUT / 'package/GMGRMR.-.-.-.-.V03.017.04_V7.6_TEST.rar'
EXTRACTED = OUT / 'vendor-rar-readback'
REPORT = OUT / 'package/vendor-rar-validation.json'
SIGNATURE = b'Rar!\x1a\x07\x00'


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def blocks(raw):
    if raw[:7] != SIGNATURE:
        raise ValueError('Expected the original RAR4 format')
    position = 7
    while position < len(raw):
        crc, kind, flags, size = struct.unpack_from('<HBHH', raw, position)
        if size < 7 or position + size > len(raw):
            raise ValueError('Invalid RAR header extent')
        header = raw[position:position + size]
        if zlib.crc32(header[2:]) & 0xffff != crc:
            raise ValueError('RAR header CRC mismatch')
        data_size = struct.unpack_from('<I', header, 7)[0] if flags & 0x8000 else 0
        if kind not in (0x73, 0x74, 0x7b) or position + size + data_size > len(raw):
            raise ValueError('Unexpected or truncated RAR block')
        name = None
        if kind == 0x74:
            if size < 32 or flags & (0x0001 | 0x0002 | 0x0004 | 0x0010 | 0x0100 | 0x0200):
                raise ValueError('Unsupported split/encrypted/solid/large/Unicode member')
            name_size = struct.unpack_from('<H', header, 26)[0]
            if 32 + name_size > size:
                raise ValueError('Invalid RAR filename extent')
            name = header[32:32 + name_size].decode('ascii').replace('\\', '/')
            path = PurePosixPath(name)
            if path.is_absolute() or '..' in path.parts or ':' in name:
                raise ValueError('Unsafe archive member')
        yield {'offset': position, 'kind': kind, 'flags': flags, 'header': header,
               'data_size': data_size, 'name': name,
               'raw': raw[position:position + size + data_size]}
        position += size + data_size
    if position != len(raw):
        raise ValueError('RAR extent mismatch')


def sevenzip(action, archive, *arguments):
    return subprocess.run(
        ['wsl', '-d', 'Ubuntu', '--', wsl_path(ROOT / 'tools/7zip-linux/7zz'),
         action, wsl_path(archive), *arguments], check=True, capture_output=True,
        encoding='utf-8').stdout


def prepare():
    for path in (DEST, EXTRACTED, REPORT):
        guard(path)
        if path.exists():
            raise FileExistsError('Refusing to overwrite a release artifact: ' + str(path))
    current_rar_sha = sha(RAR.read_bytes())
    source_description = str(RAR.relative_to(ROOT))
    if current_rar_sha == EXPECTED_SHA:
        original = RAR.read_bytes()
    else:
        # Preserve the independently modified working RAR. Use the exact original
        # retained in the operator's pinned handoff ZIP instead of rewriting it.
        handoff = ROOT / 'Grundig_Tum_Proje_Devir_Paketi.zip'
        if sha(handoff.read_bytes()) != '299cb13a2fe939c531224321952a0be196d3e19fa51441ac4e928a9e30d55f6a':
            raise ValueError('Neither working RAR nor handoff ZIP matches the source')
        with zipfile.ZipFile(handoff) as archive:
            original = archive.read('Kaynaklar/GMGRMR.-.-.-.-.V03.017.04.rar')
        source_description = 'Grundig_Tum_Proje_Devir_Paketi.zip!Kaynaklar/GMGRMR.-.-.-.-.V03.017.04.rar'
    if sha(original) != EXPECTED_SHA:
        raise ValueError('Original RAR identity check failed')
    image = (OUT / 'package/GM_SWImage_UI_v7.6-tv_OFFLINE_UNVERIFIED.bin').read_bytes()
    if sha(image) != IMAGE_SHA or len(image) != 42483736:
        raise ValueError('V7.6 image differs')
    readback = json.loads((OUT / 'package/independent-readback.json').read_text())
    if readback['status'] != 'PASS_OFFLINE_ONLY' or readback['container_sha256'] != IMAGE_SHA:
        raise ValueError('V7.6 independent verification missing')
    old = list(blocks(original))
    pieces, replaced = [SIGNATURE], 0
    for block in old:
        if block['name'] != MEMBER:
            pieces.append(block['raw'])
            continue
        header = bytearray(block['header'])
        if block['flags'] != 0x80c0 or header[25] != 0x33:
            raise ValueError('Unexpected vendor SWImage header')
        if struct.unpack_from('<I', header, 11)[0] != len(image):
            raise ValueError('V7.6 size does not match the vendor image size')
        struct.pack_into('<I', header, 7, len(image))
        struct.pack_into('<I', header, 16, zlib.crc32(image))
        header[25] = 0x30  # RAR4 stored member; no proprietary compressor needed.
        struct.pack_into('<H', header, 0, zlib.crc32(header[2:]) & 0xffff)
        pieces.append(bytes(header) + image)
        replaced += 1
    if replaced != 1:
        raise ValueError('Expected exactly one SWImage member')
    candidate = b''.join(pieces)
    new = list(blocks(candidate))
    if len(old) != len(new):
        raise ValueError('Archive block count changed')
    exact_blocks = 0
    for before, after in zip(old, new):
        if (before['name'], before['kind']) != (after['name'], after['kind']):
            raise ValueError('Archive member order/name changed')
        if before['name'] != MEMBER:
            if before['raw'] != after['raw']:
                raise ValueError('An unrelated archive block changed')
            exact_blocks += 1
    with DEST.open('xb') as stream:
        stream.write(candidate)
        stream.flush()
        os.fsync(stream.fileno())
    if DEST.read_bytes() != candidate:
        raise ValueError('RAR write readback differs')
    if 'Everything is Ok' not in sevenzip('t', DEST):
        raise ValueError('7-Zip did not report success')
    subprocess.run(['C:/Program Files/WinRAR/Rar.exe', 't', '-cfg-', '-inul', str(DEST)],
                   check=True, capture_output=True)
    EXTRACTED.mkdir()
    sevenzip('x', DEST, '-o' + wsl_path(EXTRACTED), '-y')
    expected = json.loads((ROOT / 'analiz/vendor-rar-inspection.json').read_text(encoding='utf-8'))
    if expected['archive_sha256'] != EXPECTED_SHA:
        raise ValueError('Source inventory differs')
    names = {entry['path'] for entry in expected['entries']}
    paths = list(EXTRACTED.rglob('*'))
    if {path.relative_to(EXTRACTED).as_posix() for path in paths} != names:
        raise ValueError('Extracted file/directory set changed')
    verified = []
    for entry in expected['entries']:
        path = EXTRACTED / entry['path']
        guard(path)
        if entry['directory']:
            if not path.is_dir():
                raise ValueError('Missing vendor directory')
            continue
        expected_hash = IMAGE_SHA if entry['path'] == MEMBER else entry['sha256']
        actual_hash = sha(path.read_bytes())
        if actual_hash != expected_hash:
            raise ValueError('Extracted member hash differs: ' + entry['path'])
        verified.append({'path': entry['path'], 'sha256': actual_hash,
                         'unchanged_from_vendor': entry['path'] != MEMBER})
    if sha(RAR.read_bytes()) != current_rar_sha:
        raise ValueError('Working source archive changed during packaging')
    result = dict(status='PASS_OFFLINE_ONLY', archive=str(DEST.relative_to(ROOT)),
                  archive_format='RAR4, same as original', archive_sha256=sha(candidate),
                  archive_bytes=len(candidate), source_rar_sha256=EXPECTED_SHA,
                  source_description=source_description,
                  working_rar_sha256=current_rar_sha,
                  files_verified=len(verified), directories_verified=expected['directories'],
                  unchanged_files=16, changed_files=[MEMBER],
                  original_blocks_preserved_exactly=exact_blocks,
                  swimage_storage='RAR4 m0 stored; original member used m3 compression',
                  member_order_and_other_headers_preserved=True,
                  sevenzip_test='PASS', winrar_test='PASS', extracted_members=verified,
                  extra_files_inside_archive=False, original_archive_unchanged=True,
                  television_tested=False, flash_ready=False,
                  note='RAR packaging does not establish TV archive support or firmware acceptance.')
    with REPORT.open('x', encoding='utf-8') as stream:
        json.dump(result, stream, ensure_ascii=False, indent=2)
        stream.write('\n')
    print(json.dumps({k: result[k] for k in ('status', 'archive', 'archive_sha256',
                      'archive_bytes', 'files_verified', 'directories_verified',
                      'unchanged_files', 'sevenzip_test', 'winrar_test', 'flash_ready')}, ensure_ascii=False))


if __name__ == '__main__':
    prepare()
