"""Cross-build our collector against stock glibc 2.8, never the TV application.

Linux host compilers only. The optional QEMU test runs our new collector in a
synthetic empty-mount fixture, with an isolated copy of the stock loader/libc.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
WORK = ROOT/'tools/diag-build'
SYSROOT = ROOT/'tools/mips-diag-sysroot/root/usr/mipsel-linux-gnu'
RUNTIME = ROOT/'tools/diag-runtime'
OUT = ROOT/'analiz/native-4k/diag-sink/build-v2'


def sha(path):
    assert path.is_file() and not path.is_symlink(), str(path)
    return hashlib.sha256(path.read_bytes()).hexdigest()


def run(command):
    return subprocess.run(command, check=True, text=True, capture_output=True, timeout=90).stdout


def main():
    assert sys.platform == 'linux', 'Linux build host required'
    sources = [ROOT/'native-diag/modgrundig_diag_sink.c', ROOT/'native-diag/glibc28_compat.c']
    libc = ROOT/'analiz/dosya-sistemleri-tam/06_RFS/lib/libc-2.8.so'
    loader = libc.with_name('ld-2.8.so')
    crt = SYSROOT/'lib/crt1.o'
    inputs = {str(p.relative_to(ROOT)): sha(p) for p in sources+[libc, loader, crt]}
    assert not OUT.exists(), 'Never overwrite a reviewed collector build'
    WORK.mkdir(parents=True, exist_ok=True)
    flags = ['--target=mipsel-linux-gnu', '--sysroot='+str(SYSROOT), '-march=mips32r2',
             '-mabi=32', '-mfp32', '-fPIC', '-fno-stack-protector', '-U_FORTIFY_SOURCE',
             '-O2', '-std=c99', '-Wall', '-Wextra', '-Werror']
    objects = []
    commands = []
    for source in sources:
        obj = WORK/(source.stem+'.o')
        command = ['clang', *flags, '-c', str(source), '-o', str(obj)]
        run(command); commands.append(command); objects.append(obj)
    binary = WORK/'modgrundig-diag-sink'
    command = ['mipsel-linux-gnu-ld', '--allow-shlib-undefined', '-o', str(binary),
               '--dynamic-linker=/lib/ld.so.1', str(crt), *map(str, objects), str(libc)]
    run(command); commands.append(command)
    from map_mips_calls import Elf32
    elf = Elf32(binary)
    assert elf.raw[:6] == b'\x7fELF\x01\x01'
    header = run(['readelf', '-h', str(binary)])
    dynamic = run(['readelf', '-d', str(binary)])
    program = run(['readelf', '-l', str(binary)])
    versions = run(['readelf', '--version-info', str(binary)])
    assert 'mips32r2' in header and 'o32' in header
    assert re.findall(r'Shared library: \[(.*?)\]', dynamic) == ['libc.so.6']
    assert '[Requesting program interpreter: /lib/ld.so.1]' in program
    required_versions = sorted(set(re.findall(r'GLIBC_[0-9.]+', versions)))
    assert required_versions and all(tuple(map(int, v[6:].split('.'))) <= (2, 8) for v in required_versions)

    # Our binary only: no vendor app, updater, shell/profile, MMIO or TV program.
    (RUNTIME/'lib').mkdir(parents=True, exist_ok=True)
    for source in (libc, loader):
        target = RUNTIME/'lib'/source.name
        if target.exists():
            assert sha(target) == sha(source)
        else:
            shutil.copyfile(source, target)
    for name, target in [('libc.so.6', libc.name), ('ld.so.1', loader.name)]:
        path = RUNTIME/'lib'/name
        if path.is_symlink():
            assert os.readlink(path) == target
        else:
            assert not path.exists(); path.symlink_to(target)
    empty = WORK/'empty-mounts'; empty.write_text('')
    command = ['qemu-mipsel', '-L', str(RUNTIME), str(binary), '--duration', '1',
               '--mounts', str(empty), '--fifo', str(WORK/'smoke-diag.fifo')]
    run(command)
    assert not (WORK/'smoke-diag.fifo').exists(), 'No marker must mean no FIFO'
    assert all(sha(ROOT/name) == digest for name, digest in inputs.items())
    OUT.mkdir(parents=True)
    shutil.copyfile(binary, OUT/'modgrundig-diag-sink')
    os.chmod(OUT/'modgrundig-diag-sink', 0o755)
    proof = dict(status='PASS_CROSS_LINK_AND_OWN_COLLECTOR_QEMU_SMOKE',
                 inputs=inputs, collector_sha256=sha(binary), bytes=binary.stat().st_size,
                 dynamic_dependencies=['libc.so.6'], required_glibc_versions=required_versions,
                 commands=commands, qemu_command=command,
                 compiler=run(['clang', '--version']).splitlines()[0],
                 vendor_program_executed=False, vendor_loader_and_libc_used=True,
                 synthetic_mount_fixture=True, target_hardware_executed=False,
                 TV_compatibility_verified=False, firmware_created=False)
    for name, text in [('elf-header.txt', header), ('dynamic.txt', dynamic),
                       ('program-headers.txt', program), ('versions.txt', versions)]:
        (OUT/name).write_text(text)
    (OUT/'build-proof.json').write_text(json.dumps(proof, indent=2)+'\n')
    print(json.dumps({k: proof[k] for k in ['status', 'collector_sha256', 'bytes', 'required_glibc_versions']}))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--revision', choices=['build-v2', 'build-v3'], default='build-v2')
    args = parser.parse_args()
    OUT = ROOT/'analiz/native-4k/diag-sink'/args.revision
    main()
