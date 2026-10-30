"""Offline MSLIB-only UBIFS rebuild for the pinned V7.9 audio test.

Run with Linux ubi-reader Python inside one fakeroot session. Only host mkfs and
host extractors are executed; no firmware executable/update command is run.
"""
from __future__ import annotations
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import stat
import struct
import subprocess
import sys

from build_native_app import ROOT, MKFS, READER, inventory, child, verify_index_crc

MSLIB_SHA = '7d92780368b178854a46a8f2e2ee8b625d06c7292695929800e5ecbc56fb827b'
LIB_SHA = '06bc6252713a159d5a41849f476503b0c60b035954f0c82909750223e1077d21'
APP_SHA = '438caad4b1fed4a908d018e154da7939f21a20c4440eab5bc9c6238f104ee4c1'
# Do not overwrite compressed input/CRC scratch at0x81e00000 while decoding to0x80200000.
MAX_DECODED = 0x81E00000 - 0x80200000
REVISION = 'v7.9-audio-test'
OUT = ROOT / f'analiz/native-ui-candidate/{REVISION}/package'
AUDIT = ROOT / 'analiz/native-4k/audio-test-packaging'
SOURCE = Path('/home/semih/.local/share/grundig-analysis/full-v1/files/07_MSLIB')
WORK = Path('/home/semih/.local/share/grundig-analysis/native-build-v1/mslib-v79-audio-test')


def require(ok, message):
    if not ok:
        raise ValueError(message)


def digest(data):
    return hashlib.sha256(data).hexdigest()


def sha(path):
    require(path.is_file() and not path.is_symlink(), 'Regular non-symlink input required')
    return digest(path.read_bytes())


def output_guard(path):
    boundary = ROOT / f'analiz/native-ui-candidate/{REVISION}'
    require(path.resolve().is_relative_to(boundary.resolve()), 'Audio output escapes revision')
    cursor = path
    while cursor != ROOT:
        require(not cursor.is_symlink(), 'Aliased audio output')
        require(not (hasattr(cursor, 'is_junction') and cursor.is_junction()), 'Junction output')
        if cursor.is_file():
            require(cursor.stat().st_nlink == 1, 'Hardlinked output')
        cursor = cursor.parent


def write_new(path, data):
    output_guard(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    output_guard(path)
    with path.open('xb') as stream:
        stream.write(data)
        stream.flush()
        os.fsync(stream.fileno())
    require(path.read_bytes() == data, 'Audio output readback differs')


def save_new(path, obj):
    write_new(path, (json.dumps(obj, indent=2) + '\n').encode())


def verify_library(candidate, expected_sha):
    """Pin bytes and preserve all loader/ABI metadata, permitting in-place code.

    Additional instructions may occupy an original zero gap inside an existing
    RX segment, outside every section. Ownership of its semantic/ABI proof
    remains with the separately reviewed native patch implementation.
    """
    original = ROOT / 'analiz/dosya-sistemleri-tam/07_MSLIB/libmsrv_common.so'
    require(candidate.is_file() and not candidate.is_symlink(), 'Reviewed library must be a regular file')
    old, new = original.read_bytes(), candidate.read_bytes()
    require(digest(old) == LIB_SHA and digest(new) == expected_sha, 'Library code pin differs')
    require(len(old) == len(new) and old[:7] == b'\x7fELF\x01\x01\x01', 'ELF size/class differs')
    require(struct.unpack_from('<HH', old, 16) == (3, 8), 'ET_DYN MIPS required')
    require(old[:52] == new[:52], 'ELF header/ABI differs')
    phoff, shoff = struct.unpack_from('<II', old, 28)
    phsize, phnum, shsize, shnum = struct.unpack_from('<4H', old, 42)
    require(phsize == 32 and shsize == 40, 'Unexpected ELF tables')
    require(old[phoff:phoff+phnum*32] == new[phoff:phoff+phnum*32], 'Program headers differ')
    require(old[shoff:shoff+shnum*40] == new[shoff:shoff+shnum*40], 'Section headers differ')
    sections = [struct.unpack_from('<10I', old, shoff+i*40) for i in range(shnum)]
    segments = [struct.unpack_from('<8I', old, phoff+i*32) for i in range(phnum)]
    changed = []
    for off, (a, b) in enumerate(zip(old, new)):
        if a == b:
            continue
        require(any(p[0] == 1 and p[6] & 1 and p[1] <= off < p[1]+p[4] for p in segments),
                'Patch outside existing file-backed RX segment')
        covering = [s for s in sections if s[1] != 8 and s[4] <= off < s[4]+s[5]]
        require(all(s[2] & 4 for s in covering), 'Non-code ELF section changed')
        if not covering:
            require(a == 0 and off >= 52 and not phoff <= off < phoff+phnum*32
                    and not shoff <= off < shoff+shnum*40, 'Unsectioned nonzero/metadata byte changed')
        changed.append(off)
    require(changed, 'Library has no patch')
    return dict(original_sha256=LIB_SHA, candidate_sha256=expected_sha,
                bytes=len(new), changed_bytes=len(changed), header_and_ABI_preserved=True,
                patch_within_original_RX=True, loader_changes=False)


def validate_metadata(original, current):
    require(original.keys() == current.keys(), 'MSLIB path set changed')
    for name, old in original.items():
        row = current[name]
        require(all(row[k] == old[k] for k in ('type','mode','uid','gid','nlink','mtime_sec','mtime_nsec')),
                'MSLIB inode metadata differs: ' + name)
        if old['type'] == 'symlink':
            require(row['symlink_target'] == old['symlink_target'], 'MSLIB link target changed')


def main(library, library_sha256):
    require(sys.platform == 'linux' and os.environ.get('FAKEROOTKEY') is not None,
            'Run inside one Linux fakeroot session')
    require(len(library_sha256) == 64, 'Explicit reviewed library SHA256 required')
    output_guard(OUT/'mslib-build-validation.json')
    proof = verify_library(library, library_sha256)
    original = ROOT / 'analiz/bolumler/07_MSLIB.bin'
    require(sha(original) == MSLIB_SHA, 'Original MSLIB identity changed')
    require(sha(MKFS) == 'f424c5cb122bc24a10858512926fbe5a29c74b4b6a80c5e347bd7e9aa07f48bb', 'Host mkfs changed')
    require(not WORK.exists(), 'Refusing an existing MSLIB work directory')
    require(not (OUT/'07_MSLIB.ubifs').exists(), 'MSLIB output already exists')
    from export_ubifs_metadata import inspect_image
    meta = inspect_image(original)
    require(not meta['issues'] and not meta['unreachable_indexed_inode_count'], 'Original MSLIB index unresolved')
    require(meta['type_counts'] == {'directory':26,'regular':261,'symlink':54}, 'Original MSLIB inventory changed')
    expected = {r['path']:r for r in meta['entries']}
    WORK.mkdir(parents=True)
    OUT.mkdir(parents=True, exist_ok=True)
    baseline_dir, staging, decoded = WORK/'original', WORK/'staging', WORK/'readback'
    image = WORK/'07_MSLIB.ubifs'
    with (OUT/'mslib-original-extract.log').open('x') as log:
        subprocess.run([str(READER),'-e','126976','-o',str(baseline_dir),str(original)], stdout=log, stderr=subprocess.STDOUT, check=True, timeout=300)
    baseline, canonical = inventory(baseline_dir), inventory(SOURCE)
    require(baseline.keys() == canonical.keys() == expected.keys(), 'MSLIB source paths differ')
    for name, row in canonical.items():
        require(row['type'] == expected[name]['type'], 'Canonical type differs')
        if row['type'] == 'regular':
            require(row['sha256'] == baseline[name]['sha256'] and row['size'] == expected[name]['size'], 'Canonical file differs: '+name)
        elif row['type'] == 'symlink':
            require(row['symlink_target'] == expected[name]['symlink_target'], 'Canonical symlink differs')
    require(canonical['/libmsrv_common.so']['sha256'] == LIB_SHA, 'Common baseline differs')
    shutil.copytree(SOURCE, staging, symlinks=True)
    shutil.copyfile(library, staging/'libmsrv_common.so')
    for name, row in sorted(expected.items(), key=lambda x:len(x[0]), reverse=True):
        target = child(staging, name)
        os.chown(target, row['uid'], row['gid'], follow_symlinks=False)
        if row['type'] != 'symlink':
            os.chmod(target, stat.S_IMODE(row['mode']))
        ts = row['mtime_sec']*1000000000+row['mtime_nsec']
        os.utime(target, ns=(ts,ts), follow_symlinks=False)
    staged = inventory(staging)
    for name, row in staged.items():
        require(all(row[k] == expected[name][k] for k in ('type','mode','uid','gid')), 'Staged ownership/mode differs')
        if row['type'] == 'regular':
            wanted = library_sha256 if name == '/libmsrv_common.so' else canonical[name]['sha256']
            require(row['sha256'] == wanted, 'Unexpected staged file change')
    # Retain the existing LZO codec. Raw-all would exceed the bootloader's
    # fixed input/output RAM gap even when it fits the NAND volume geometry.
    command = [str(MKFS),'-r',str(staging),'-m','2048','-e','126976','-c','480','-o',str(image),'-x','lzo','-f','8','-l','4','-p','1']
    with (OUT/'mslib-mkfs.log').open('x') as log:
        subprocess.run(command, stdout=log, stderr=subprocess.STDOUT, check=True, timeout=300)
    built = inspect_image(image)
    sb = built['superblock']
    require(sb['fmt_version'] == 4 and sb['flags'] == 0 and sb['min_io_size'] == 2048 and sb['leb_size'] == 126976
            and sb['leb_cnt'] <= 480 and image.stat().st_size == sb['leb_cnt']*126976, 'Rebuilt MSLIB geometry differs')
    require(image.stat().st_size <= MAX_DECODED, 'MSLIB decode output would overlap compressed input/CRC scratch')
    require(not built['issues'] and not built['unreachable_indexed_inode_count'], 'Rebuilt index unresolved')
    validate_metadata(expected, {r['path']:r for r in built['entries']})
    crc = verify_index_crc(image)
    with (OUT/'mslib-readback.log').open('x') as log:
        subprocess.run([str(READER),'-e','126976','-o',str(decoded),str(image)], stdout=log, stderr=subprocess.STDOUT, check=True, timeout=300)
    actual = inventory(decoded)
    require(actual.keys() == staged.keys(), 'MSLIB reextraction paths differ')
    for name, row in staged.items():
        require(row['type'] == actual[name]['type'], 'MSLIB reextraction type differs')
        if row['type'] == 'regular':
            require(row['sha256'] == actual[name]['sha256'], 'MSLIB content roundtrip failed: '+name)
        elif row['type'] == 'symlink':
            require(row['symlink_target'] == actual[name]['symlink_target'], 'MSLIB symlink roundtrip failed')
    require(sha(original) == MSLIB_SHA and inventory(SOURCE) == canonical, 'Original MSLIB changed')
    write_new(OUT/'07_MSLIB.ubifs', image.read_bytes())
    save_new(OUT/'mslib-index.json', built)
    save_new(OUT/'mslib-build-validation.json', dict(status='PASS_OFFLINE_ONLY', original_mslib_sha256=MSLIB_SHA,
        mslib_sha256=sha(image), mslib_bytes=image.stat().st_size, library=proof, metadata_entries_verified=len(expected),
        files_verified=261, unchanged_regular_files=260, symlinks_verified=54, committed_crc=crc,
        filesystem_compressor='lzo', max_leb_count=480, max_decoded_bytes=MAX_DECODED, command=command, target_executed=False, flash_ready=False))
    print(json.dumps(dict(status='PASS_OFFLINE_ONLY', mslib_sha256=sha(image), files_verified=261)))


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--library', required=True, type=Path)
    p.add_argument('--library-sha256', required=True)
    a = p.parse_args(); main(a.library, a.library_sha256)
