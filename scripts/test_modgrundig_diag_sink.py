"""Linux HOST integration tests; never builds/runs firmware or MIPS code.

Run via WSL: python3 /mnt/c/Users/Semih/Desktop/grundig/scripts/test_modgrundig_diag_sink.py
All removable media and /proc/mounts are simulated inside temporary directories.
"""
from __future__ import annotations

import errno
import json
import os
from pathlib import Path
import shutil
import signal
import stat
import subprocess
import tempfile
import time
import unittest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / 'native-diag/modgrundig_diag_sink.c'
GOOD = b'MGDIAG 1 1 7 1 100 101 102 0 2\n'


def wait_for(predicate, seconds=3):
    deadline = time.monotonic() + seconds
    while time.monotonic() < deadline:
        if predicate():
            return
        time.sleep(0.01)
    raise AssertionError('host simulation condition timed out')


class Simulation:
    def __init__(self, binary):
        self.temp = tempfile.TemporaryDirectory(prefix='mgdiag-host-')
        self.root = Path(self.temp.name)
        self.usb = self.root / 'usb volume'
        self.usb.mkdir()
        self.fifo = self.root / 'diag.fifo'
        self.mounts = self.root / 'mounts'
        self.output = self.usb / 'MODGRUNDIG_DIAG.txt'
        self.marker = self.usb / 'MODGRUNDIG_DIAG_ENABLE'
        self.command = list(binary) if isinstance(binary, (tuple, list)) else [str(binary)]
        self.process = None
        self.env = None
        self.mount_text = '/dev/sda1 ' + str(self.usb).replace(' ', r'\040') + ' vfat rw,nosuid,nodev 0 0\n'
        self.mounts.write_text(self.mount_text)

    def start(self):
        self.process = subprocess.Popen(self.command + [
            '--fifo', str(self.fifo), '--mounts', str(self.mounts),
            '--interval-ms', '100', '--worker-timeout-ms', '150',
        ], stdout=subprocess.DEVNULL, stderr=subprocess.PIPE, env=self.env)

    def enable(self):
        self.marker.write_bytes(b'MGDIAG1\n')
        if self.process is None:
            self.start()
        wait_for(lambda: self.fifo.exists() and stat.S_ISFIFO(self.fifo.stat().st_mode))

    def open_writer(self):
        fd = os.open(self.fifo, os.O_RDWR | os.O_NONBLOCK | os.O_NOFOLLOW)
        st = os.fstat(fd)
        assert stat.S_ISFIFO(st.st_mode) and st.st_uid == os.geteuid()
        assert stat.S_IMODE(st.st_mode) == 0o600
        assert os.fpathconf(fd, 'PC_PIPE_BUF') >= 192
        return fd

    def send(self, value, fd=None):
        own = fd is None
        if own:
            fd = self.open_writer()
        try:
            deadline = time.monotonic() + 2
            while True:
                try:
                    return os.write(fd, value)
                except BlockingIOError:
                    if time.monotonic() >= deadline:
                        raise AssertionError('collector did not drain synthetic FIFO')
                    time.sleep(.002)
        finally:
            if own:
                os.close(fd)

    def text(self):
        try:
            return self.output.read_text()
        except FileNotFoundError:
            return ''

    def close(self):
        if self.process is not None:
            if self.process.poll() is None:
                self.process.terminate()
            self.process.communicate(timeout=2)
        self.temp.cleanup()

    def __enter__(self):
        return self

    def __exit__(self, *args):
        self.close()


@unittest.skipUnless(os.name == 'posix', 'requires Linux host gcc and POSIX FIFO; not a TV test')
class DiagSinkHostTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.build = None
        cls.external_command = None
        override = os.environ.get('MGDIAG_TEST_COMMAND')
        if override:
            command = json.loads(override)
            if not isinstance(command, list) or not command or not all(isinstance(s, str) and s for s in command):
                raise ValueError('MGDIAG_TEST_COMMAND must be a nonempty JSON list of nonempty strings')
            cls.external_command = command
            cls.binary = command
            return
        compiler = shutil.which('gcc')
        if not compiler:
            raise unittest.SkipTest('Linux HOST gcc is unavailable')
        cls.build = tempfile.TemporaryDirectory(prefix='mgdiag-build-')
        cls.binary = Path(cls.build.name) / 'sink-host'
        subprocess.run([compiler, '-std=c99', '-Wall', '-Wextra', '-Werror', '-O2',
                        str(SOURCE), '-o', str(cls.binary)], check=True)
        shim = Path(cls.build.name) / 'sync-host-fault.c'
        shim.write_text('''
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
int __real_fsync(int fd);
int __wrap_fsync(int fd) {
    struct stat st;
    if (fstat(fd,&st)) return -1;
#if defined(FILE_ERROR)
    if (S_ISREG(st.st_mode)) { errno=EIO; return -1; }
#else
    if (S_ISDIR(st.st_mode)) { errno=EINVAL; return -1; }
#endif
    return __real_fsync(fd);
}
''')
        cls.file_sync_error = Path(cls.build.name) / 'sink-host-file-sync-error'
        cls.dir_sync_unsupported = Path(cls.build.name) / 'sink-host-dir-sync-einval'
        for output, define in [(cls.file_sync_error, '-DFILE_ERROR'),
                               (cls.dir_sync_unsupported, '-DDIR_UNSUPPORTED')]:
            subprocess.run([compiler, '-std=c99', '-Wall', '-Wextra', '-Werror', '-O2', define,
                            str(SOURCE), str(shim), '-Wl,--wrap=fsync', '-o', str(output)], check=True)
        startup = Path(cls.build.name) / 'startup-host-race.c'
        startup.write_text('''
#define _GNU_SOURCE
#include <sys/stat.h>
#include <unistd.h>
int __real_mkfifo(const char *, mode_t);
int __wrap_mkfifo(const char *path, mode_t mode) {
    int rc=__real_mkfifo(path,mode);
    if (!rc) usleep(150000); /* Force the old publish-before-open race. */
    return rc;
}
''')
        cls.startup_race = Path(cls.build.name) / 'sink-host-startup-race'
        subprocess.run([compiler, '-std=c99', '-Wall', '-Wextra', '-Werror', '-O2',
                        str(SOURCE), str(startup), '-Wl,--wrap=mkfifo', '-o', str(cls.startup_race)], check=True)
        invariant = Path(cls.build.name) / 'invariant-host-fault.c'
        invariant.write_text('''
#define _GNU_SOURCE
#include <sys/stat.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#if defined(FORMAT_ZERO) || defined(FORMAT_BAD) || defined(FORMAT_BAD_NUMBER)
int __wrap_snprintf(char *buf,size_t size,const char *format,...) {
    (void)format;
    if (size<23) return -1;
#if defined(FORMAT_ZERO)
    buf[0]=0; return 0;
#elif defined(FORMAT_BAD)
    memset(buf,'X',22);buf[21]='\\n';buf[22]=0;return 22;
#else
    memcpy(buf,"MGDIAG_META 1 X 0 0 0\\n",23);return 22;
#endif
}
#endif
#ifdef WRITE_LIES
ssize_t __real_write(int,const void *,size_t);
ssize_t __wrap_write(int fd,const void *buf,size_t n) {
    struct stat st;
    if (!fstat(fd,&st) && S_ISREG(st.st_mode)) return (ssize_t)n;
    return __real_write(fd,buf,n);
}
#endif
#ifdef READ_CORRUPT
ssize_t __real_read(int,void *,size_t);
ssize_t __wrap_read(int fd,void *buf,size_t n) {
    struct stat st;
    ssize_t rc=__real_read(fd,buf,n);
    if (rc>0 && !fstat(fd,&st) && S_ISREG(st.st_mode) && st.st_size>8) ((char *)buf)[0]^=1;
    return rc;
}
#endif
#ifdef COUNT_RENAME
int __real_renameat(int,const char *,int,const char *);
int __wrap_renameat(int a,const char *b,int c,const char *d) {
    int rc=__real_renameat(a,b,c,d);
    const char *path=getenv("MGDIAG_TEST_RENAME_COUNT");
    if (!rc && path) {
        int fd=open(path,O_WRONLY|O_CREAT|O_APPEND,0600);
        if (fd>=0) { ssize_t n=write(fd,"1",1); (void)n; close(fd); }
    }
    return rc;
}
int __real_fsync(int);
int __wrap_fsync(int fd) {
    struct stat st;
    const char *path=getenv("MGDIAG_TEST_FAIL_SYNC_WHILE_EXISTS");
    if (path && !access(path,F_OK) && !fstat(fd,&st) && S_ISREG(st.st_mode)) {errno=EIO;return -1;}
    return __real_fsync(fd);
}
#endif
''')
        cls.invariant_binaries = {}
        for macro, wrappers in [('FORMAT_ZERO', ['snprintf']), ('FORMAT_BAD', ['snprintf']),
                                ('FORMAT_BAD_NUMBER', ['snprintf']), ('WRITE_LIES', ['write']),
                                ('READ_CORRUPT', ['read']), ('COUNT_RENAME', ['renameat', 'fsync'])]:
            output = Path(cls.build.name) / ('sink-host-'+macro.lower())
            subprocess.run([compiler, '-std=c99', '-Wall', '-Wextra', '-Werror', '-O2', '-D'+macro,
                            '-fno-builtin-snprintf', '-U_FORTIFY_SOURCE',
                            str(SOURCE), str(invariant), *['-Wl,--wrap='+w for w in wrappers],
                            '-o', str(output)], check=True)
            cls.invariant_binaries[macro] = output

    @classmethod
    def tearDownClass(cls):
        if cls.build is not None:
            cls.build.cleanup()

    def test_no_marker_preserves_disabled_state(self):
        with Simulation(self.binary) as s:
            s.start()
            time.sleep(.35)
            self.assertFalse(s.fifo.exists())
            self.assertFalse(s.output.exists())
            self.assertIsNone(s.process.poll())

    def test_numeric_whitelist_filters_all_non_numeric_payloads(self):
        with Simulation(self.binary) as s:
            s.enable()
            invalid = [b'MGDIAG 1 PRIVATE_KEY=hidden\n', b'MGDIAG 2 -1 1\n',
                       b'MGDIAG 2 0x4b 1\n', b'MGDIAG 2 75 4294967296\n',
                       b'MGDIAG 9 75 1\n', b'MGDIAG 1 1 7 1 8192 101 102 0 2\n',
                       b'normal secret log\n', b'MGDIAG 2 75 1 extra\n']
            for line in invalid:
                s.send(line)
            s.send(GOOD)
            s.send(b'MGDIAG 2 75 1\n')
            s.send(b'MGDIAG 3 0 7 31457280\n')
            wait_for(lambda: 'MGDIAG 3 0 7 31457280\n' in s.text())
            lines = s.text().splitlines()
            self.assertEqual(lines[1:], [GOOD.decode().strip(), 'MGDIAG 2 75 1', 'MGDIAG 3 0 7 31457280'])
            self.assertEqual(lines[0].split()[2:], ['3', '8', '0', '3'])

    def test_ring_is_bounded_and_preserves_latest_records(self):
        with Simulation(self.binary) as s:
            s.enable()
            fd = s.open_writer()
            try:
                for i in range(500):
                    s.send(f'MGDIAG 3 {i} 7 31457280\n'.encode(), fd)
            finally:
                os.close(fd)
            wait_for(lambda: 'MGDIAG 3 499 7 31457280\n' in s.text())
            text = s.text()
            self.assertLessEqual(len(text.encode()), 16384)
            lines = text.splitlines()
            self.assertEqual(len(lines), 65)
            self.assertEqual(lines[1], 'MGDIAG 3 436 7 31457280')
            self.assertEqual(lines[-1], 'MGDIAG 3 499 7 31457280')

    def test_partial_and_overlong_input_do_not_poison_next_record(self):
        with Simulation(self.binary) as s:
            s.enable()
            fd = s.open_writer()
            try:
                s.send(b'MGDIAG 2 ', fd)
                s.send(b'75 1\n', fd)
                for _ in range(8):
                    s.send(b'X'*128, fd)
                s.send(b'\n'+GOOD, fd)
            finally:
                os.close(fd)
            wait_for(lambda: GOOD.decode() in s.text())
            self.assertEqual(s.text().splitlines()[1:], ['MGDIAG 2 75 1', GOOD.decode().strip()])
            self.assertEqual(s.text().splitlines()[0].split()[4], '1')

    def test_marker_removal_disables_and_old_producer_fd_cannot_sigpipe(self):
        with Simulation(self.binary) as s:
            s.enable()
            fd = s.open_writer()
            try:
                s.marker.unlink()
                wait_for(lambda: not s.fifo.exists())
                # RDWR keeps the writer's own read end alive after sink closure.
                dropped = False
                for _ in range(10000):
                    try:
                        os.write(fd, GOOD)
                    except BlockingIOError as error:
                        self.assertEqual(error.errno, errno.EAGAIN)
                        dropped = True
                        break
                self.assertTrue(dropped)
            finally:
                os.close(fd)
            s.enable()
            s.send(b'MGDIAG 2 75 1\n')
            wait_for(lambda: 'MGDIAG 2 75 1\n' in s.text())

    def test_fifo_symlink_is_refused_without_touching_target(self):
        with Simulation(self.binary) as s:
            victim = s.root / 'victim'
            victim.write_text('unchanged')
            s.fifo.symlink_to(victim)
            s.marker.write_bytes(b'MGDIAG1\n')
            s.start()
            self.assertEqual(s.process.wait(timeout=2), 78)
            self.assertTrue(s.fifo.is_symlink())
            self.assertEqual(victim.read_text(), 'unchanged')

    def test_marker_symlink_and_non_usb_source_are_not_opt_in(self):
        with Simulation(self.binary) as s:
            actual = s.root / 'marker'
            actual.write_bytes(b'MGDIAG1\n')
            s.marker.symlink_to(actual)
            s.start()
            time.sleep(.3)
            self.assertFalse(s.fifo.exists())
            s.marker.unlink()
            s.marker.write_bytes(b'MGDIAG1\n')
            s.mounts.write_text(s.mount_text.replace('/dev/sda1', '/dev/mmcblk0p1'))
            time.sleep(.3)
            self.assertFalse(s.fifo.exists())

    def test_atomic_output_does_not_follow_symlink(self):
        with Simulation(self.binary) as s:
            victim = s.root / 'victim'
            victim.write_text('unchanged')
            s.output.symlink_to(victim)
            s.enable()
            wait_for(lambda: not s.output.is_symlink())
            self.assertEqual(victim.read_text(), 'unchanged')
            self.assertTrue(s.output.is_file())

    def test_stale_bounded_owned_temp_recovers(self):
        with Simulation(self.binary) as s:
            scratch = s.usb / '.MODGRUNDIG_DIAG.tmp'
            scratch.write_text('stale')
            scratch.chmod(0o777)  # FAT/NTFS mount-wide modes need not retain 0600.
            s.enable()
            wait_for(s.output.exists)
            self.assertNotIn('stale', s.text())
            self.assertFalse(scratch.exists())

    def test_hung_usb_worker_does_not_block_fifo_reader(self):
        with Simulation(self.binary) as s:
            s.enable()
            s.mounts.unlink()
            os.mkfifo(s.mounts, 0o600)  # child fopen blocks; main must still drain RAM.
            fd = s.open_writer()
            began = time.monotonic()
            try:
                for i in range(1000):
                    s.send(f'MGDIAG 3 {i} 7 31457280\n'.encode(), fd)
            finally:
                os.close(fd)
            self.assertLess(time.monotonic()-began, 2)
            self.assertIsNone(s.process.poll())
            time.sleep(.3)  # cover the worker-kill deadline.
            s.mounts.unlink()
            s.mounts.write_text(s.mount_text)
            wait_for(lambda: 'MGDIAG 3 999 7 31457280\n' in s.text())
            self.assertEqual(len(s.text().splitlines()), 65)

    def test_file_fsync_failure_preserves_previous_snapshot(self):
        if self.external_command is not None:
            self.skipTest('host-only linker fault shim; not a target test')
        with Simulation(self.file_sync_error) as s:
            s.output.write_text('previous snapshot')
            s.enable()
            s.send(GOOD)
            time.sleep(.35)
            self.assertEqual(s.output.read_text(), 'previous snapshot')
            self.assertFalse((s.usb / '.MODGRUNDIG_DIAG.tmp').exists())
            self.assertIsNone(s.process.poll())

    def test_unsupported_directory_fsync_still_exports(self):
        if self.external_command is not None:
            self.skipTest('host-only linker fault shim; not a target test')
        with Simulation(self.dir_sync_unsupported) as s:
            s.enable()
            s.send(GOOD)
            wait_for(lambda: GOOD.decode() in s.text())
            self.assertIsNone(s.process.poll())

    def test_fifo_is_published_only_after_reader_is_open(self):
        if self.external_command is not None:
            self.skipTest('host-only startup race fault shim; not a target test')
        with Simulation(self.startup_race) as s:
            s.enable()
            # No delay/FD hold workaround: write+close immediately at publication.
            s.send(GOOD)
            wait_for(lambda: GOOD.decode() in s.text())

    def test_zero_and_malformed_headers_do_not_replace_previous_snapshot(self):
        if self.external_command is not None:
            self.skipTest('host-only formatter fault shim; not a target test')
        for macro in ['FORMAT_ZERO', 'FORMAT_BAD', 'FORMAT_BAD_NUMBER']:
            with self.subTest(fault=macro), Simulation(self.invariant_binaries[macro]) as s:
                s.output.write_text('previous snapshot')
                s.enable()
                s.send(GOOD)
                time.sleep(.25)
                self.assertEqual(s.text(), 'previous snapshot')
                self.assertFalse((s.usb / '.MODGRUNDIG_DIAG.tmp').exists())

    def test_falsely_successful_write_and_corrupt_readback_cannot_publish(self):
        if self.external_command is not None:
            self.skipTest('host-only file I/O fault shims; not a target test')
        for macro in ['WRITE_LIES', 'READ_CORRUPT']:
            with self.subTest(fault=macro), Simulation(self.invariant_binaries[macro]) as s:
                s.output.write_text('previous snapshot')
                s.enable()
                s.send(GOOD)
                time.sleep(.25)
                self.assertEqual(s.text(), 'previous snapshot')
                self.assertFalse((s.usb / '.MODGRUNDIG_DIAG.tmp').exists())

    def test_unchanged_snapshot_metadata_is_idle_until_new_event(self):
        with Simulation(self.binary) as s:
            s.enable()
            before = s.output.stat()
            content = s.output.read_bytes()
            time.sleep(.45)  # Four mount/marker intervals, without another rename/write.
            after = s.output.stat()
            self.assertEqual((after.st_ino, after.st_mtime_ns, after.st_size),
                             (before.st_ino, before.st_mtime_ns, before.st_size))
            self.assertEqual(s.output.read_bytes(), content)
            s.send(GOOD)
            wait_for(lambda: GOOD.decode() in s.text())
            self.assertNotEqual(s.output.read_bytes(), content)

    def test_export_failure_retries_success_ipc_stops_renames_and_reoptin_exports(self):
        if self.external_command is not None:
            self.skipTest('host-only rename/fsync instrumentation; not a target test')
        with Simulation(self.invariant_binaries['COUNT_RENAME']) as s:
            count = s.root / 'rename-count'
            failure = s.root / 'fail-sync'
            failure.write_text('test fault')
            s.env = dict(os.environ, MGDIAG_TEST_RENAME_COUNT=str(count),
                         MGDIAG_TEST_FAIL_SYNC_WHILE_EXISTS=str(failure))
            s.output.write_text('previous snapshot')
            s.enable()
            time.sleep(.25)
            self.assertEqual(s.text(), 'previous snapshot')
            self.assertFalse(count.exists())
            failure.unlink()
            wait_for(lambda: s.text().startswith('MGDIAG_META'))
            wait_for(lambda: count.exists() and len(count.read_bytes()) == 1)
            time.sleep(.35)
            self.assertEqual(count.read_bytes(), b'1')
            s.send(GOOD)
            wait_for(lambda: GOOD.decode() in s.text())
            wait_for(lambda: len(count.read_bytes()) == 2)
            time.sleep(.35)
            self.assertEqual(count.read_bytes(), b'11')
            s.marker.unlink()
            wait_for(lambda: not s.fifo.exists())
            s.enable()
            wait_for(lambda: len(count.read_bytes()) == 3)
            self.assertNotIn(GOOD.decode(), s.text())

    def test_postmonitor_three_samples_and_strict_numeric_schema(self):
        with Simulation(self.binary) as s:
            s.enable()
            base = [4, 2500, 7, 4855, 4955, 0, 1, 0, 0, 3, 1, 1]
            invalid = []
            for field, value in [(2, 256), (3, 8192), (4, 8192), (6, 256),
                                 (7, 256), (8, 256), (10, 256), (11, 256)]:
                values = list(base)
                values[field] = value
                invalid.append(('MGDIAG '+' '.join(map(str, values))+'\n').encode())
            line = ('MGDIAG '+' '.join(map(str, base))).encode()
            invalid += [line.rsplit(b' ', 1)[0]+b'\n', line+b' 1\n', line+b' SECRET=hidden\n']
            for value in invalid:
                s.send(value)
            expected = []
            for elapsed, frames in [(2500, 0), (3500, 1), (4500, 4294967295)]:
                values = list(base)
                values[1], values[5] = elapsed, frames
                value = ('MGDIAG '+' '.join(map(str, values))+'\n').encode()
                expected.append(value.decode().strip())
                s.send(value)
            wait_for(lambda: expected[-1] in s.text())
            self.assertEqual(s.text().splitlines()[1:], expected)
            self.assertEqual(s.text().splitlines()[0].split()[2:], ['3', str(len(invalid)), '0', '3'])


if __name__ == '__main__':
    unittest.main(verbosity=2)
