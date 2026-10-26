"""Final V7.2 scope, preservation and packaging pin checks."""
import struct
import unittest
from unittest.mock import patch

import build_native_ui_v71_tv as before
import build_native_ui_v72_tv as build
import native_ui_v72_mute as mute
from build_native_volume_patch import elf_va_offset


class V72ScopeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.old = {'08_APP' + r['path']: r['candidate'].read_bytes()
                   for r in before.verified_packaging_records()}
        cls.new = {'08_APP' + r['path']: r['candidate'].read_bytes()
                   for r in build.verified_packaging_records()}

    def test_four_path_delta_and_all_v71_geometry_preserved(self):
        self.assertEqual(set(self.new) - set(self.old), {mute.MUTED_BACKGROUND})
        self.assertEqual(len(self.new), 13)
        changed = {p for p in self.new if self.new[p] != self.old.get(p)}
        self.assertEqual(changed, {mute.ELF, mute.IMAGE, mute.MUTED_ICON,
                                   mute.MUTED_BACKGROUND})
        self.assertEqual(self.new['08_APP/rc/rc/bin/Num_res.bin'],
                         self.old['08_APP/rc/rc/bin/Num_res.bin'])
        self.assertEqual(build.verified_records(), build.verified_packaging_records())

    def test_entire_elf_outside_normal_mode_selection_block_is_identical(self):
        a, b = self.old[mute.ELF], self.new[mute.ELF]
        off = elf_va_offset(a, mute.START, mute.END - mute.START)
        self.assertEqual(len(a), len(b))
        self.assertEqual(a[:off], b[:off])
        self.assertEqual(a[off + mute.END - mute.START:], b[off + mute.END - mute.START:])
        self.assertEqual(b[off:off + mute.END - mute.START], mute.block())

    def test_existing_resource_records_preserved_and_only_one_appended(self):
        a, b = self.old[mute.IMAGE], self.new[mute.IMAGE]
        self.assertEqual(a[56:], b[56:len(a)])
        self.assertEqual(struct.unpack_from('<I', b, 28)[0], 2181)
        length = struct.unpack_from('<I', b, len(a))[0]
        path = b[len(a) + 4:]
        self.assertEqual(len(path), length)
        self.assertEqual(path, b'../rc/ARimages/Grundig/modern/volume_muted_bg.png\0')

    def test_manifest_code_pin_and_output_boundary_fail_closed(self):
        import native_ui_v72_tv_pins as pins
        with patch.object(pins, 'MANIFEST_SHA', '0' * 64):
            with self.assertRaises(ValueError):
                build.verified_packaging_records()
        with self.assertRaises(ValueError):
            build.guard(build.ROOT / 'outside-v72.bin')


if __name__ == '__main__':
    unittest.main()
