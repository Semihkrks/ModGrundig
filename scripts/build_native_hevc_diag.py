"""Isolated V7.9 diagnostic filesystems; host mkfs/extractors only."""
import argparse
import json
import os
from pathlib import Path
import shutil
import stat
import struct
import subprocess
import sys

import build_native_mslib as m
from build_native_app import inventory, child, verify_index_crc

ROOT = Path(__file__).resolve().parents[1]
REVISION = 'v7.9-hevc-diag'
OUT = ROOT/f'analiz/native-ui-candidate/{REVISION}/package'
HOOK = ROOT/'analiz/native-4k/diag-hooks/fifo-v3/libmsrv_common.so'
HOOK_SHA = '6967d9da7c95b79664924aa8c308380e6d985d57c814aa5ff5dd37670f864f7a'
COLLECTOR = ROOT/'analiz/native-4k/diag-sink/build-v2/modgrundig-diag-sink'
CUSTOMER_SHA = '69719ccfe61ca51aa6570f18147bd5cb1f1a3185f05e8a6d00b4a38a38aeb495'
WORK = Path('/home/semih/.local/share/grundig-analysis/native-build-v1/customer-v79-hevc-diag')
SOURCE = Path('/home/semih/.local/share/grundig-analysis/full-v1/files/11_customer_update')
LAUNCH = (b'# ModGrundig: bounded opt-in numeric telemetry; TV launch is unchanged.\n'
          b'if [ -x /Customer_Update/modgrundig-diag-sink ] && mkdir /tmp/modgrundig-diag.once 2>/dev/null\n'
          b'then\n'
          b'    /Customer_Update/modgrundig-diag-sink --duration 600 </dev/null >/dev/null 2>&1 &\n'
          b'fi\n')


def configure():
    # Reuse the already reviewed MSLIB builder without changing its audio-test
    # default paths, source pins or old release artifacts.
    m.REVISION = REVISION
    m.OUT = OUT
    m.WORK = Path('/home/semih/.local/share/grundig-analysis/native-build-v1/mslib-v79-hevc-diag')


def customer():
    from export_ubifs_metadata import inspect_image
    m.require(sys.platform == 'linux' and os.environ.get('FAKEROOTKEY') is not None, 'Linux fakeroot session required')
    original = ROOT/'analiz/bolumler/11_customer_update.bin'
    m.require(m.sha(original) == CUSTOMER_SHA, 'Customer source changed')
    collector_proof = json.loads((COLLECTOR.parent/'build-proof.json').read_text())
    m.require(m.sha(COLLECTOR) == collector_proof['collector_sha256'], 'Collector build identity differs')
    m.require(collector_proof['status'] == 'PASS_CROSS_LINK_AND_OWN_COLLECTOR_QEMU_SMOKE', 'Target collector proof absent')
    m.require(not WORK.exists() and not (OUT/'11_customer_update.ubifs').exists(), 'Never overwrite diagnostic build')
    meta = inspect_image(original)
    m.require(not meta['issues'] and not meta['unreachable_indexed_inode_count'], 'Original customer index unresolved')
    expected = {r['path']: r for r in meta['entries']}
    WORK.mkdir(parents=True)
    OUT.mkdir(parents=True, exist_ok=True)
    extracted, staging, readback = WORK/'original', WORK/'staging', WORK/'readback'
    with (OUT/'customer-original-extract.log').open('x') as log:
        subprocess.run([str(m.READER), '-e', '126976', '-o', str(extracted), str(original)],
                       check=True, stdout=log, stderr=subprocess.STDOUT, timeout=120)
    baseline, canonical = inventory(extracted), inventory(SOURCE)
    m.require(baseline.keys() == canonical.keys() == expected.keys(), 'Original customer path set differs')
    for name, row in canonical.items():
        if row['type'] == 'regular':
            m.require(row['sha256'] == baseline[name]['sha256'], 'Customer source file differs: '+name)
    shutil.copytree(SOURCE, staging, symlinks=True)
    profile = staging/'profile'
    before = profile.read_bytes()
    anchor = b'export UART_ENABLE=FALSE\n'
    m.require(before.count(anchor) == 1 and b'ModGrundig:' not in before, 'Launcher insertion anchor differs')
    after = before.replace(anchor, LAUNCH+anchor)
    profile.write_bytes(after)
    shutil.copyfile(COLLECTOR, staging/'modgrundig-diag-sink')
    added = '/modgrundig-diag-sink'
    m.require(added not in expected, 'Collector path was not absent')
    expected[added] = dict(expected['/profile'], path=added, type='regular', mode=stat.S_IFREG|0o755,
                           uid=0, gid=0, nlink=1, size=COLLECTOR.stat().st_size)
    for name, row in sorted(expected.items(), key=lambda v: len(v[0]), reverse=True):
        target = child(staging, name)
        os.chown(target, row['uid'], row['gid'], follow_symlinks=False)
        if row['type'] != 'symlink':
            os.chmod(target, stat.S_IMODE(row['mode']))
        ns = row['mtime_sec']*1000000000+row['mtime_nsec']
        os.utime(target, ns=(ns, ns), follow_symlinks=False)
    # This is syntax validation only, never execution of the vendor profile.
    subprocess.run(['sh', '-n', str(profile)], check=True)
    staged = inventory(staging)
    maximum = struct.unpack_from('<I', original.read_bytes(), 44)[0]
    image = WORK/'11_customer_update.ubifs'
    command = [str(m.MKFS), '-r', str(staging), '-m', '2048', '-e', '126976',
               '-c', str(maximum), '-o', str(image), '-x', 'lzo', '-f', '8', '-l', '4', '-p', '1']
    with (OUT/'customer-mkfs.log').open('x') as log:
        subprocess.run(command, check=True, stdout=log, stderr=subprocess.STDOUT, timeout=180)
    built = inspect_image(image)
    m.require(not built['issues'] and not built['unreachable_indexed_inode_count'], 'Customer candidate index unresolved')
    actual_meta = {r['path']: r for r in built['entries']}
    m.require(actual_meta.keys() == expected.keys(), 'Customer metadata path set changed')
    for name, old in expected.items():
        m.require(all(actual_meta[name][k] == old[k] for k in
                      ['type', 'mode', 'uid', 'gid', 'nlink', 'mtime_sec', 'mtime_nsec']), 'Customer metadata differs: '+name)
    sb = built['superblock']
    m.require((sb['fmt_version'], sb['flags'], sb['min_io_size'], sb['leb_size']) == (4, 0, 2048, 126976), 'Customer geometry differs')
    m.require(image.stat().st_size <= 0x300000 and image.stat().st_size == sb['leb_cnt']*126976, 'Customer volume overflow')
    crc = verify_index_crc(image)
    with (OUT/'customer-readback.log').open('x') as log:
        subprocess.run([str(m.READER), '-e', '126976', '-o', str(readback), str(image)],
                       check=True, stdout=log, stderr=subprocess.STDOUT, timeout=120)
    decoded = inventory(readback)
    m.require(decoded.keys() == staged.keys(), 'Customer filesystem readback paths differ')
    for name, row in staged.items():
        m.require(row['type'] == decoded[name]['type'], 'Customer readback type differs')
        if row['type'] == 'regular':
            m.require(row['sha256'] == decoded[name]['sha256'] and row['size'] == decoded[name]['size'], 'Customer readback content differs')
        elif row['type'] == 'symlink':
            m.require(row['symlink_target'] == decoded[name]['symlink_target'], 'Customer readback link differs')
    unchanged = [name for name in canonical if name != '/profile']
    for name in unchanged:
        row = canonical[name]
        m.require(decoded[name]['type'] == row['type'], 'Unrelated customer type changed')
        if row['type'] == 'regular':
            m.require(decoded[name]['sha256'] == row['sha256'], 'Unrelated customer content changed')
    m.require(m.sha(original) == CUSTOMER_SHA and inventory(SOURCE) == canonical, 'Original customer source changed')
    m.write_new(OUT/'11_customer_update.ubifs', image.read_bytes())
    m.save_new(OUT/'customer-index.json', built)
    m.save_new(OUT/'customer-build-validation.json', dict(status='PASS_OFFLINE_ONLY',
        source_sha256=CUSTOMER_SHA, customer_sha256=m.sha(image), bytes=image.stat().st_size,
        added_file=added, collector_sha256=m.sha(COLLECTOR), profile_original_sha256=m.digest(before),
        profile_candidate_sha256=m.digest(after), launcher_insert=LAUNCH.decode(),
        files=decoded, committed_crc=crc, original_unchanged=True,
        vendor_program_executed=False, television_tested=False))
    print(json.dumps(dict(status='PASS_OFFLINE_ONLY', customer_sha256=m.sha(image), bytes=image.stat().st_size)))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('partition', choices=['mslib', 'customer'])
    args = parser.parse_args()
    configure()
    if args.partition == 'mslib':
        m.main(HOOK, HOOK_SHA)
    else:
        customer()
