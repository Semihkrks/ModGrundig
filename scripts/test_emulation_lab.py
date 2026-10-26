"""Laboratory safety/diagnostic contract tests. No target ELF is executed."""
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

import emulation_lab as lab


class LaboratoryContracts(unittest.TestCase):
    def test_setup_rejects_substituted_qemu_before_any_execution(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            package = root / lab.DEB_NAME
            package.write_bytes(b'package-placeholder')
            qemu = root / 'tools/usr/bin/qemu-mipsel'
            qemu.parent.mkdir(parents=True)
            qemu.write_text('#!/bin/sh\ntouch SHOULD_NOT_EXECUTE\n')
            real_sha = lab.sha
            with patch.object(lab, 'BASE', root), patch.object(lab, 'sha', side_effect=lambda p: lab.DEB_SHA if p == package else real_sha(p)), patch.object(lab, 'checked', return_value='SHA256: ' + lab.DEB_SHA + '\n') as executor:
                with self.assertRaisesRegex(RuntimeError, 'QEMU executable SHA mismatch'):
                    lab.setup()
            self.assertEqual(executor.call_args_list[0].args[0], ['apt-cache', 'show', 'qemu-user=' + lab.VERSION])
            self.assertEqual(executor.call_count, 1)

    def test_prepare_rejects_substituted_qemu_before_copy(self):
        with tempfile.TemporaryDirectory() as directory:
            fake = Path(directory) / 'qemu'
            fake.write_bytes(b'substitute')
            with patch.object(lab, 'copy_tree') as copier:
                with self.assertRaisesRegex(RuntimeError, 'QEMU executable SHA mismatch'):
                    lab.prepare('v3', fake)
                copier.assert_not_called()

    def test_run_does_not_trust_editable_tool_report(self):
        with tempfile.TemporaryDirectory() as directory:
            base = Path(directory)
            root = base / 'guest-v3'
            for folder in ('applications/bin', 'lab-fixtures', 'emulator'):
                (root / folder).mkdir(parents=True, exist_ok=True)
            app = root / 'applications/bin/dvbt_board'
            app.write_bytes(b'placeholder')
            (root / 'lab-fixtures/cmdline').write_text('ENV=NAND\n')
            qemu = root / 'emulator/qemu-mipsel'
            qemu.write_bytes(b'substitute')
            (base / 'host-tools.json').write_text(json.dumps({'qemu_sha256': lab.sha(qemu)}))
            real_sha = lab.sha
            with patch.object(lab, 'BASE', base), patch.object(lab, 'OUT', base), patch.object(lab, 'isolation_probe'), patch.object(lab, 'sha', side_effect=lambda p: lab.APP_HASHES['v3'] if p == app else real_sha(p)), patch.object(lab, 'bounded') as executor:
                with self.assertRaisesRegex(RuntimeError, 'QEMU executable SHA mismatch'):
                    lab.run('v3')
                executor.assert_not_called()

    def test_v3_elf_pin_matches_candidate_manifest(self):
        manifest = json.loads((lab.REPO / 'analiz/native-ui-candidate/v3/manifest.json').read_text())
        record = next(row for row in manifest['records'] if row['relative_path'] == '08_APP/bin/dvbt_board')
        self.assertEqual(lab.APP_HASHES['v3'], record['candidate_sha256'])

    def test_provisioning_paths_excluded(self):
        for name in ('keys/key.bin', 'certificate/a.bin', 'Customer/config', 'foo/private/x',
                     'a/device_id.txt', 'a/key.pem', 'a/update.sh', 'lib/modules/a.ko'):
            self.assertFalse(lab.permitted(name), name)

    def test_public_resources_and_elf_allowed(self):
        for name in ('applications/rc/rc/bin/Num_res.bin', 'mslib/libmuf.so', 'lib/ld.so.1'):
            self.assertTrue(lab.permitted(name))

    def test_guest_links_allow_library_target(self):
        self.assertTrue(lab.symlink_safe('lib/libc.so.6', 'libc-2.8.so'))
        self.assertTrue(lab.symlink_safe('mslib/x.so', '/lib/x.so'))

    def test_guest_links_reject_host_and_devices(self):
        for target in ('/dev/mem', '/home/semih/private', '/mnt/c/a', '../../../host'):
            self.assertFalse(lab.symlink_safe('lib/x', target), target)

    def test_sandbox_contract(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            cmd = lab.sandbox(root, ['/emulator/qemu-mipsel', '/applications/bin/dvbt_board'], app=True)
            for flag in ('--unshare-all', '--unshare-user', '--disable-userns', '--new-session',
                         '--cap-drop', '--clearenv', '--ro-bind', '--proc', '--dev'):
                self.assertIn(flag, cmd)
            self.assertNotIn('/dev/mem', cmd)
            self.assertNotIn('/mnt/c', cmd)
            self.assertEqual(cmd[-2:], ['/emulator/qemu-mipsel', '/applications/bin/dvbt_board'])

    def test_synthetic_cmdline_bound_when_present(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / 'lab-fixtures').mkdir()
            (root / 'lab-fixtures/cmdline').write_text('ENV=NAND\n')
            cmd = lab.sandbox(root, ['/probe'])
            self.assertIn('/proc/cmdline', cmd)
            self.assertIn(str(root / 'lab-fixtures/cmdline'), cmd)

    def test_output_buffers_are_not_retained(self):
        text = '2 read(3,0x1234,100) = 20\n2 write(1,"SECRET_TEST_VALUE",17) = 17\n2 open("/dev/mem",O_RDWR) = -1 errno=2 (No such file or directory)\n'
        result = lab.sanitize_syscalls(text)
        encoded = json.dumps(result)
        self.assertNotIn('SECRET_TEST_VALUE', encoded)
        self.assertNotIn('0x1234', encoded)
        self.assertEqual(result['file_path_operations'][0]['path'], '/dev/mem')

    def test_fixed_binary_diagnostics_exclude_runtime_arguments(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            for folder in ('mslib', 'config', 'applications/bin'):
                (root / folder).mkdir(parents=True, exist_ok=True)
            (root / 'mslib/a.so').write_bytes(b'\x7fELF\0fixed error message for %s\0')
            out = lab.fixed_diagnostics('fixed error message for PRIVATE_DEVICE_ID', root)
            self.assertEqual(out[0]['fixed_literal_prefix'], 'fixed error message for')
            self.assertNotIn('PRIVATE_DEVICE_ID', json.dumps(out))

    def test_failed_probe_prevents_target_execution(self):
        with patch.object(lab, 'isolation_probe', side_effect=RuntimeError('failed')), patch.object(lab, 'bounded') as call:
            with self.assertRaises(RuntimeError):
                lab.run('v2')
            call.assert_not_called()

    def test_synthetic_ubi_topology_is_private_readonly_binding(self):
        with tempfile.TemporaryDirectory() as directory:
            base = Path(directory)
            model = base / 'topology-fixtures/ubi-mpool-name'
            (model / 'sys/class/ubi/ubi0_0').mkdir(parents=True)
            (model / 'sys/class/ubi/ubi0_0/name').write_bytes(b'MPOOL\n')
            with patch.object(lab, 'BASE', base):
                cmd = lab.sandbox(base / 'guest-v3', ['/probe'], topology='ubi-mpool-name')
            index = cmd.index(str(model / 'sys'))
            self.assertEqual(cmd[index - 1:index + 2], ['--ro-bind', str(model / 'sys'), '/sys'])
            self.assertNotIn('/dev/ubi0_0', cmd)

    def test_synthetic_ubi_topology_rejects_extra_file_or_symlink(self):
        with tempfile.TemporaryDirectory() as directory:
            base = Path(directory)
            model = base / 'topology-fixtures/ubi-directory'
            (model / 'sys/class/ubi').mkdir(parents=True)
            extra = model / 'sys/unapproved'
            extra.write_bytes(b'not in fixed model')
            with patch.object(lab, 'BASE', base):
                with self.assertRaisesRegex(RuntimeError, 'differ'):
                    lab.verify_topology('ubi-directory')
                extra.unlink()
                extra.symlink_to('/sys/class/ubi')
                with self.assertRaisesRegex(RuntimeError, 'symlink'):
                    lab.verify_topology('ubi-directory')

    def test_synthetic_ubi_geometry_is_explicitly_empty(self):
        model = lab.UBI_TOPOLOGIES['ubi-mpool-empty']
        self.assertEqual(model['class/ubi/ubi0_0/data_bytes'], b'0\n')
        self.assertEqual(model['class/ubi/ubi0_0/usable_eb_size'], b'126976\n')
        self.assertTrue(all(not name.startswith(('/', '../')) for name in model))

    def test_synthetic_ubi_topology_requires_pinned_sdk(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            sdk = root / 'sdk.so'
            sdk.write_bytes(b'unknown SDK')
            with patch.object(lab, 'BASE', root):
                with self.assertRaisesRegex(RuntimeError, 'SDK hash mismatch'):
                    lab.topology_fixture('ubi-mpool-empty', sdk)
            self.assertFalse((root / 'topology-fixtures').exists())

    def test_copy_tree_preserves_guest_links_without_following(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            source, target = root / 'source', root / 'target'
            source.mkdir()
            (source / 'lib.so').write_bytes(b'test')
            (source / 'link.so').symlink_to('lib.so')
            (source / 'host.so').symlink_to('/dev/mem')
            (source / 'secret.pem').write_text('excluded')
            counts = dict(files=0, symlinks=0, excluded=0, excluded_links=0, excluded_special=0)
            lab.copy_tree(source, target, 'mslib', counts)
            self.assertTrue((target / 'link.so').is_symlink())
            self.assertFalse((target / 'host.so').exists())
            self.assertFalse((target / 'secret.pem').exists())
            self.assertEqual(counts['excluded_links'], 1)


if __name__ == '__main__':
    unittest.main()
