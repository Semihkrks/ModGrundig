#!/usr/bin/env python3
"""Bounded MIPSel application laboratory. Run on Ubuntu/WSL; never boots firmware.

Only the pinned dvbt_board application is launchable. No arbitrary guest command,
firmware shell, init, update script, host device or network is exposed.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
from pathlib import Path, PurePosixPath
import re
import resource
import shutil
import stat
import subprocess
import tempfile
import time
import urllib.request

BASE = Path('/home/semih/.local/share/grundig-analysis/emulation-lab-v1')
SOURCE = Path('/home/semih/.local/share/grundig-analysis/full-v1/files')
CANDIDATES = {
    name: Path('/home/semih/.local/share/grundig-analysis/native-build-v1/app-reextracted-' + name)
    for name in ('v2', 'v3')
}
REPO = Path(__file__).resolve().parents[1]
OUT = REPO / 'analiz/emulation-lab'
VERSION = '1:10.2.1+ds-1ubuntu3.3'
DEB_SHA = 'a00c7fdf34c913b799f8d1cc556d3fdd9f9fd695167a17baf86123a9cfaefb22'
DEB_NAME = 'qemu-user_10.2.1+ds-1ubuntu3.3_amd64.deb'
DEB_URL = 'https://archive.ubuntu.com/ubuntu/pool/universe/q/qemu/' + DEB_NAME
QEMU_SHA = '7d30ccb62bb20c49fc405636df39362c41f748c0fc053675a8866ffabab13432'
APP_HASHES = {
    'original': '51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916',
    'v2': '9b64ca24f6f7ff0833284599f8bdec3db1b90c820d4fdfdb9ff26711c1ad41c2',
    'v3': 'c109a782f476dfb8b23136d7dad3a231c57dd4cb605e081da559ed370f76208a',
}
SDK_SHA = '00d147f752f92c9706e6496d0cda21de528e81f0c73cac54426b2618c17fe5fb'
# Explicit, synthetic filesystem models, never successful hardware responses.
UBI_TOPOLOGIES = {
    'ubi-directory': {},
    'ubi-mpool-name': {'class/ubi/ubi0_0/name': b'MPOOL\n'},
    'ubi-mpool-empty': {'class/ubi/ubi0_0/name': b'MPOOL\n',
                        'class/ubi/ubi0_0/data_bytes': b'0\n',
                        'class/ubi/ubi0_0/usable_eb_size': b'126976\n'},
}
PROBE_C = r'''
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(void) {
  const char *denied[]={"/host-sentinel","/mnt/c/Users","/home/semih",
     "/dev/mem","/dev/mtd0","/dev/sda","/dev/fb0","/certificate"};
  int good=1;
  for(unsigned i=0;i<sizeof(denied)/sizeof(denied[0]);i++) {
    int r=access(denied[i],F_OK); printf("absent %s %d\n",denied[i],r==-1);
    if(r!=-1)good=0;
  }
  int f=open("/root-write-test",O_WRONLY|O_CREAT,0600);
  int ro=f<0 && errno==EROFS; printf("root_readonly %d\n",ro); if(f>=0)close(f);
  int t=open("/tmp/scratch",O_WRONLY|O_CREAT,0600);
  printf("private_tmp_writable %d\n",t>=0); if(t>=0)close(t); else good=0;
  int s=socket(AF_INET,SOCK_STREAM,0); struct sockaddr_in a={0};
  a.sin_family=AF_INET;a.sin_port=htons(443);inet_pton(AF_INET,"192.0.2.1",&a.sin_addr);
  int c=s>=0?connect(s,(void*)&a,sizeof(a)):-1;
  int net=(s>=0 && c<0 && errno==ENETUNREACH);if(s>=0)close(s);
  printf("network_unreachable %d\n",net);
  printf("pid_namespace %d\n",getpid()<=3);
  return good && ro && t>=0 && net && getpid()<=3 ? 0:1;
}
'''


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def save(name: str, data: dict) -> None:
    OUT.mkdir(parents=True, exist_ok=True)
    (OUT / name).write_text(json.dumps(data, indent=2, ensure_ascii=False) + '\n')


def checked(command: list[str], **kwargs) -> str:
    return subprocess.check_output(command, text=True, stderr=subprocess.STDOUT, **kwargs)


def verify_qemu(path: Path) -> None:
    """Compiled-in executable authority; editable reports never authorize code."""
    if path.is_symlink() or not path.is_file() or sha(path) != QEMU_SHA:
        raise RuntimeError('Host QEMU executable SHA mismatch; execution prohibited')


def setup() -> dict:
    BASE.mkdir(parents=True, exist_ok=True)
    metadata = checked(['apt-cache', 'show', 'qemu-user=' + VERSION])
    if not re.search(r'^SHA256: ' + DEB_SHA + r'$', metadata, re.M):
        raise RuntimeError('Pinned Ubuntu package SHA does not match apt metadata')
    package = BASE / DEB_NAME
    if not package.exists():
        with urllib.request.urlopen(DEB_URL, timeout=60) as src, package.open('xb') as dst:
            shutil.copyfileobj(src, dst)
    if sha(package) != DEB_SHA:
        raise RuntimeError('Downloaded host package SHA mismatch')
    tools = BASE / 'tools'
    if not tools.exists():
        tools.mkdir()
        checked(['dpkg-deb', '--extract', str(package), str(tools)])
    qemu = tools / 'usr/bin/qemu-mipsel'
    verify_qemu(qemu)
    version = checked([str(qemu), '--version']).splitlines()[0]
    filetype = checked(['file', str(qemu)]).strip()
    if 'statically linked' not in filetype and 'static-pie linked' not in filetype:
        raise RuntimeError('Host emulator is not statically linked')
    result = {'package_version': VERSION, 'package_url': DEB_URL,
              'package_sha256': DEB_SHA, 'apt_sha_verified': True,
              'qemu_path': str(qemu), 'qemu_sha256': sha(qemu),
              'qemu_version': version, 'qemu_file': filetype,
              'bubblewrap_version': checked(['/usr/bin/bwrap', '--version']).strip(),
              'system_install': False, 'package_scripts_executed': False}
    save('host-tools.json', result)
    return result


def symlink_safe(relative: str, target: str) -> bool:
    """Guest absolute links allowed only inside library/resource/application roots."""
    p = PurePosixPath(target) if target.startswith('/') else PurePosixPath('/') / PurePosixPath(relative).parent / target
    parts: list[str] = []
    for segment in p.parts:
        if segment in ('/', '.', ''):
            continue
        if segment == '..':
            if not parts:
                return False
            parts.pop()
        else:
            parts.append(segment)
    return bool(parts) and parts[0] in ('lib', 'usr', 'mslib', 'applications', 'config')


def permitted(relative: str) -> bool:
    p = PurePosixPath(relative)
    lowered = {s.lower() for s in p.parts}
    if lowered & {'certificate', 'certificates', 'customer', 'customer_update', 'private', 'keys', 'ssl', 'ssh', '.ssh', 'modules'}:
        return False
    name = p.name.lower()
    if name.endswith(('.pem', '.key', '.crt', '.cer', '.p12', '.pfx', '.sh', '.ko')):
        return False
    return not any(s in name for s in ('password', 'passwd', 'shadow', 'deviceid', 'device_id', 'serialnumber', 'privatekey'))


def copy_tree(src: Path, dst: Path, guest_prefix: str, counts: dict) -> None:
    if not src.is_dir() or src.is_symlink():
        raise RuntimeError('Source tree must be a real directory')
    dst.mkdir(parents=True, exist_ok=True)
    for root, dirs, files in os.walk(src, followlinks=False):
        parent = Path(root).relative_to(src)
        for name in dirs[:] + files:
            path = Path(root) / name
            rel = PurePosixPath(guest_prefix) / parent.as_posix() / name
            if not permitted(str(rel)):
                if name in dirs:
                    dirs.remove(name)
                counts['excluded'] += 1
                continue
            target = dst / parent / name
            info = path.lstat()
            if stat.S_ISLNK(info.st_mode):
                if name in dirs:
                    dirs.remove(name)
                link = os.readlink(path)
                if not symlink_safe(str(rel), link):
                    counts['excluded_links'] += 1
                    continue
                target.symlink_to(link)
                counts['symlinks'] += 1
            elif stat.S_ISDIR(info.st_mode):
                target.mkdir(exist_ok=True)
            elif stat.S_ISREG(info.st_mode):
                shutil.copyfile(path, target)
                target.chmod(0o644)
                counts['files'] += 1
            else:
                counts['excluded_special'] += 1


def sandbox(root: Path, command: list[str], *, app: bool = False, topology: str | None = None) -> list[str]:
    cmd = ['/usr/bin/bwrap', '--unshare-all', '--unshare-user', '--die-with-parent', '--new-session',
           '--disable-userns', '--cap-drop', 'ALL', '--clearenv', '--hostname', 'grundig-offline-lab',
           '--ro-bind', str(root), '/', '--proc', '/proc', '--dev', '/dev', '--tmpfs', '/tmp',
           '--tmpfs', '/run', '--tmpfs', '/USR_DB', '--tmpfs', '/BACKUP_DB',
           '--setenv', 'HOME', '/tmp', '--setenv', 'PATH', '/nonexistent',
           '--setenv', 'LANG', 'C', '--setenv', 'LD_LIBRARY_PATH',
           '/mslib:/mslib/utopia:/mslib/gstreamer-0.10:/config:/mslib/directfb-1.4-0/inputdrivers',
           '--chdir', '/applications/bin' if app else '/']
    fixture = root / 'lab-fixtures/cmdline'
    if fixture.is_file() and not fixture.is_symlink():
        cmd += ['--ro-bind', str(fixture), '/proc/cmdline']
    if topology is not None:
        model = verify_topology(topology)
        cmd += ['--ro-bind', str(model / 'sys'), '/sys']
    cmd += ['--']
    return cmd + command


def limits() -> None:
    resource.setrlimit(resource.RLIMIT_CPU, (15, 15))
    # 32-bit QEMU needs address-space reservation beyond the guest RAM used.
    resource.setrlimit(resource.RLIMIT_AS, (8 * 1024**3, 8 * 1024**3))
    resource.setrlimit(resource.RLIMIT_CORE, (0, 0))
    resource.setrlimit(resource.RLIMIT_FSIZE, (1024 * 1024, 1024 * 1024))
    resource.setrlimit(resource.RLIMIT_NOFILE, (128, 128))
    resource.setrlimit(resource.RLIMIT_NPROC, (64, 64))


def bounded(command: list[str]) -> dict:
    start = time.monotonic()
    with tempfile.TemporaryFile() as log:
        proc = subprocess.Popen(command, stdout=log, stderr=log, stdin=subprocess.DEVNULL,
                                preexec_fn=limits, start_new_session=True)
        timed_out = False
        try:
            proc.wait(timeout=20)
        except subprocess.TimeoutExpired:
            timed_out = True
            os.killpg(proc.pid, 9)
            proc.wait()
        log.seek(0)
        raw = log.read(1024 * 1024).decode('utf-8', 'replace')
    # The tree excludes provisioning, keys and certificates. No raw target output
    # is exported: retain only syscall names, paths and numeric results below.
    return {'exit_code': proc.returncode, 'timeout': timed_out,
            'seconds': round(time.monotonic() - start, 3), 'raw': raw}


def isolation_probe() -> dict:
    root = BASE / 'probe-root'
    root.mkdir(parents=True, exist_ok=True)
    for p in ('proc', 'dev', 'tmp', 'run', 'USR_DB', 'BACKUP_DB'):
        (root / p).mkdir(exist_ok=True)
    source = BASE / 'probe.c'
    source.write_text(PROBE_C)
    checked(['cc', '-static', '-O2', '-Wall', '-Wextra', str(source), '-o', str(root / 'probe')])
    result = bounded(sandbox(root, ['/probe']))
    report = {k: v for k, v in result.items() if k != 'raw'}
    report['checks'] = result['raw'].splitlines()
    report['passed'] = result['exit_code'] == 0 and not result['timeout']
    report['probe_sha256'] = sha(root / 'probe')
    save('isolation-probe.json', report)
    if not report['passed']:
        raise RuntimeError('Isolation probe failed; target execution prohibited')
    return report


def prepare(variant: str, qemu: Path) -> dict:
    verify_qemu(qemu)
    root = BASE / ('guest-' + variant)
    if root.exists():
        raise RuntimeError('Guest already exists; refusing implicit reuse or deletion: ' + str(root))
    app = SOURCE / '08_APP' if variant == 'original' else CANDIDATES[variant]
    actual = sha(app / 'bin/dvbt_board')
    if actual != APP_HASHES[variant]:
        raise RuntimeError('Application hash mismatch: ' + variant)
    counts = dict(files=0, symlinks=0, excluded=0, excluded_links=0, excluded_special=0)
    root.mkdir()
    copy_tree(SOURCE / '06_RFS/lib', root / 'lib', 'lib', counts)
    if (SOURCE / '06_RFS/usr/lib').is_dir():
        copy_tree(SOURCE / '06_RFS/usr/lib', root / 'usr/lib', 'usr/lib', counts)
    else:
        (root / 'usr/lib').mkdir(parents=True)
    copy_tree(SOURCE / '07_MSLIB', root / 'mslib', 'mslib', counts)
    # Public UI resources only; do not copy the application shell/helpers.
    for part in ('rc', 'defaults', 'system'):
        copy_tree(app / part, root / 'applications' / part, 'applications/' + part, counts)
    (root / 'applications/bin').mkdir(parents=True)
    shutil.copyfile(app / 'bin/dvbt_board', root / 'applications/bin/dvbt_board')
    (root / 'applications/bin/dvbt_board').chmod(0o755)
    (root / 'config').mkdir()
    # Explicit CONFIG ELF library allowlist; not scripts or provisioning files.
    for name in ('libsysteminfo.so', 'libdfbinfo.so', 'libMMAPInfo.so'):
        shutil.copyfile(SOURCE / '09_CONFIG' / name, root / 'config' / name)
    # No configuration shell, boot parameters, provisioning or calibration is copied.
    (root / 'emulator').mkdir()
    verify_qemu(qemu)
    shutil.copyfile(qemu, root / 'emulator/qemu-mipsel')
    verify_qemu(root / 'emulator/qemu-mipsel')
    (root / 'emulator/qemu-mipsel').chmod(0o755)
    for p in ('proc', 'dev', 'sys', 'tmp', 'run', 'etc', 'USR_DB', 'BACKUP_DB'):
        (root / p).mkdir(exist_ok=True)
    result = {'variant': variant, 'guest_root': str(root), 'application_sha256': actual,
              'qemu_sha256': sha(root / 'emulator/qemu-mipsel'), 'copy_counts': counts,
              'source_mutated': False, 'configuration': 'three explicit ELF libraries; no board/provisioning settings',
              'guest_shells': 0, 'hardware_devices': 0, 'certificate_customer_partitions': False}
    save('guest-' + variant + '.json', result)
    return result


def sanitize_syscalls(raw: str) -> dict:
    paths: list[dict] = []
    calls: dict[str, int] = {}
    signals: list[str] = []
    tail: list[dict] = []
    for line in raw.splitlines():
        m = re.match(r'^\d+ ([a-zA-Z0-9_]+)\(', line)
        if m:
            name = m.group(1)
            calls[name] = calls.get(name, 0) + 1
            tail.append({'call': name, 'result': line.rsplit(' = ', 1)[-1][:80]
                         if ' = ' in line else 'unknown'})
            # Only path arguments from file-open operations are retained; never
            # read/write buffers, environment dumps or application stdout.
            if name in ('open', 'openat', 'access', 'readlink', 'stat', 'stat64', 'lstat64'):
                quoted = re.findall(r'"([^"\n]*)"', line)
                if quoted:
                    paths.append({'call': name, 'path': quoted[0][:240],
                                  'result': line.rsplit(' = ', 1)[-1][:80] if ' = ' in line else 'unknown'})
        if line.startswith('--- SIG'):
            signals.append(line[:160])
    assertions = re.findall(r'(?:Assertion|assertion) [A-Za-z0-9_`\x27 .:!<>=()+/*-]{1,220}(?:failed|failure)', raw)
    return {'syscall_counts': calls, 'file_path_operations': paths[:1000], 'tail_syscalls': tail[-25:],
            'signals': signals, 'raw_log_persisted': False,
            'application_stdout_persisted': False, 'assertions': assertions[:10],
            'raw_bytes_observed': len(raw.encode())}


def fixed_diagnostics(raw: str, root: Path) -> list[dict]:
    """Only emit fixed local binary literals; never interpolated runtime values."""
    found = []
    assertion_symbols = re.findall(r'ASSERT FAIL:\s*([A-Za-z_][A-Za-z0-9_:~]{2,100})', raw)
    keywords = re.compile(r'assert|failed|error|LX_MEM|cmdline|kernel memory|panic|mapi_system|mapi_storage_factory_config_nand', re.I)
    for prefix in ('mslib', 'config', 'applications/bin'):
        for path in (root / prefix).rglob('*'):
            if not path.is_file() or path.is_symlink():
                continue
            data = path.read_bytes()
            if not data.startswith(b'\x7fELF'):
                continue
            for symbol in assertion_symbols:
                token = symbol.encode() + b'\x00'
                offset = data.find(token)
                if offset >= 0:
                    found.append({'binary': '/' + str(path.relative_to(root)),
                                  'file_offset': hex(offset), 'assertion_symbol': symbol})
            for match in re.finditer(rb'[\x20-\x7e]{12,}', data):
                literal = match.group().decode('ascii')
                if not keywords.search(literal):
                    continue
                fragment = literal.split('%', 1)[0].strip()
                if len(fragment) >= 18 and fragment in raw and fragment != '/proc/cmdline':
                    found.append({'binary': '/' + str(path.relative_to(root)),
                                  'file_offset': hex(match.start()), 'fixed_literal_prefix': fragment[:220]})
    return found[:40]


def topology_fixture(name: str, sdk: Path) -> dict:
    if name not in UBI_TOPOLOGIES:
        raise RuntimeError('Unknown synthetic topology')
    if sdk.is_symlink() or sha(sdk) != SDK_SHA:
        raise RuntimeError('Topology static proof SDK hash mismatch')
    data = sdk.read_bytes()
    for offset, expected in ((0x437E18, b'/sys/class/ubi\0'),
                             (0x437F28, b'/sys/class/ubi/%s/name\0'),
                             (0x437F40, b'/sys/class/ubi/ubi%d_%d\0'),
                             (0x437A6C, b'MPOOL\0'),
                             (0x4381D0, b'/sys/class/ubi/ubi%d_%d/data_bytes\0'),
                             (0x438204, b'/sys/class/ubi/ubi%d_%d/usable_eb_size\0')):
        if data[offset:offset + len(expected)] != expected:
            raise RuntimeError('Topology static literal mismatch')
    model = BASE / 'topology-fixtures' / name
    if model.exists():
        verify_topology(name)
    else:
        (model / 'sys/class/ubi').mkdir(parents=True)
        for relative, value in UBI_TOPOLOGIES[name].items():
            path = model / 'sys' / relative
            path.parent.mkdir(parents=True, exist_ok=True)
            with path.open('xb') as stream:
                stream.write(value)
    verify_topology(name)
    result = {'name': name, 'synthetic': True, 'private_sys_root': str(model / 'sys'),
              'modeled_directories': ['sys/class/ubi'] + (['sys/class/ubi/ubi0_0'] if UBI_TOPOLOGIES[name] else []),
              'modeled_files': {k: v.decode().strip() for k, v in UBI_TOPOLOGIES[name].items()},
              'topology_proof': 'ubi-model-static.json', 'device_nodes_exposed': 0,
              'ioctl_results_faked': False, 'physical_volume_contents': False,
              'data_bytes_semantics': 'zero models a deliberately empty synthetic volume; no device content',
              'leb_size_semantics': '126976 is fixture geometry matching original UBIFS LEB, not a probed device'}
    save('topology-' + name + '.json', result)
    return result


def verify_topology(name: str) -> Path:
    if name not in UBI_TOPOLOGIES:
        raise RuntimeError('Unknown synthetic topology')
    model = BASE / 'topology-fixtures' / name
    if model.resolve() != BASE.resolve() / 'topology-fixtures' / name:
        raise RuntimeError('Topology path escapes laboratory root')
    if model.is_symlink() or not (model / 'sys/class/ubi').is_dir():
        raise RuntimeError('Topology directory missing or linked')
    seen = {}
    for path in model.rglob('*'):
        if path.is_symlink():
            raise RuntimeError('Topology symlink prohibited')
        if path.is_dir():
            continue
        if not path.is_file():
            raise RuntimeError('Topology device/special file prohibited')
        seen[str(path.relative_to(model / 'sys'))] = path.read_bytes()
    if seen != UBI_TOPOLOGIES[name]:
        raise RuntimeError('Topology files differ from fixed synthetic model')
    return model


def run(variant: str, topology: str | None = None) -> dict:
    # Re-run current isolation test immediately before every target launch.
    isolation_probe()
    root = BASE / ('guest-' + variant)
    if not (root / 'lab-fixtures/cmdline').is_file():
        raise RuntimeError('Synthetic cmdline fixture required; do not expose host boot arguments')
    app = root / 'applications/bin/dvbt_board'
    if sha(app) != APP_HASHES[variant]:
        raise RuntimeError('Prepared guest application differs from allowlist')
    verify_qemu(root / 'emulator/qemu-mipsel')
    if topology is not None:
        topology_fixture(topology, root / 'mslib/libMStarSDK.so')
    result = bounded(sandbox(root, ['/emulator/qemu-mipsel', '-R', '0', '-strace',
                                     '/applications/bin/dvbt_board'], app=True, topology=topology))
    report = {k: v for k, v in result.items() if k != 'raw'}
    report.update(sanitize_syscalls(result['raw']))
    report['shared_library_opened_paths'] = sorted({item['path'] for item in report['file_path_operations']
        if item['call'] in ('open', 'openat') and item['result'].isdigit() and '.so' in item['path']})
    report['shared_library_opened_count'] = len(report['shared_library_opened_paths'])
    report['fixed_binary_diagnostics'] = fixed_diagnostics(result['raw'], root)
    report.update(variant=variant, application_sha256=sha(app),
                  full_board_emulator=False, screen_rendered=False, boot_script_executed=False)
    report['synthetic_cmdline'] = (root / 'lab-fixtures/cmdline').read_text().strip()
    report['synthetic_ubi_topology'] = topology
    # Loader diagnostics contain only library names. Keep precise missing-library
    # messages without exporting arbitrary application text.
    report['loader_errors'] = re.findall(r'(?:error while loading shared libraries: [A-Za-z0-9_.+-]+: [A-Za-z ]+)', result['raw'])[:20]
    report['qemu_errors'] = [s[:200] for s in result['raw'].splitlines()
                             if s.startswith('qemu: ') or s.startswith('qemu-mipsel: ')]
    save('run-' + variant + ('-' + topology if topology else '') + '.json', report)
    return report


def fixtures(variant: str) -> dict:
    root = BASE / ('guest-' + variant)
    if sha(root / 'applications/bin/dvbt_board') != APP_HASHES[variant]:
        raise RuntimeError('Guest application mismatch')
    sdk = root / 'mslib/libMStarSDK.so'
    data = sdk.read_bytes()
    # GetBootSource's GOT-referenced literals, proven in the retained Capstone
    # listing. No guessed LX_MEM or device/memory response is supplied.
    for offset, expected in ((0x4394BC, b'ENV=\0'), (0x439508, b'NAND\0'),
                             (0x439510, b'EMMC\0'), (0x439518, b'SERIAL\0')):
        if data[offset:offset + len(expected)] != expected:
            raise RuntimeError('GetBootSource static literal proof mismatch')
    directory = root / 'lab-fixtures'
    directory.mkdir(exist_ok=True)
    fixture = directory / 'cmdline'
    if fixture.exists() and fixture.read_bytes() != b'ENV=NAND\n':
        raise RuntimeError('Refusing to replace unknown fixture')
    fixture.write_bytes(b'ENV=NAND\n')
    result = {'variant': variant, 'cmdline': 'ENV=NAND', 'synthetic_test_data': True,
              'physical_tv_bootargs': False, 'device_ioctl_stub': False,
              'proof': 'getbootsource-static.json', 'sdk_sha256': sha(sdk)}
    save('fixtures-' + variant + '.json', result)
    return result


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('action', choices=('setup', 'probe', 'prepare', 'fixtures', 'run'))
    parser.add_argument('--variant', choices=tuple(APP_HASHES), default='v2')
    parser.add_argument('--topology', choices=tuple(UBI_TOPOLOGIES), default=None,
                        help='Explicit synthetic UBI sysfs only; no hardware/ioctl emulation')
    args = parser.parse_args()
    if os.name != 'posix' or not Path('/usr/bin/bwrap').is_file():
        parser.error('Run using WSL Ubuntu; bubblewrap is required')
    if args.action == 'setup':
        result = setup()
    elif args.action == 'probe':
        result = isolation_probe()
    elif args.action == 'prepare':
        result = prepare(args.variant, BASE / 'tools/usr/bin/qemu-mipsel')
    elif args.action == 'fixtures':
        result = fixtures(args.variant)
    else:
        result = run(args.variant, args.topology)
    if args.action == 'run':
        summary_fields = ('variant', 'exit_code', 'timeout', 'seconds', 'shared_library_opened_count',
                          'fixed_binary_diagnostics', 'synthetic_cmdline', 'full_board_emulator',
                          'screen_rendered', 'synthetic_ubi_topology', 'loader_errors', 'qemu_errors')
        result = {k: result[k] for k in summary_fields}
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
