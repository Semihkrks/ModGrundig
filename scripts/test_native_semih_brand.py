"""Offline byte scope, native resources, artwork and evidence regression checks."""
import io
import struct
import unittest
from pathlib import Path
from PIL import Image
import native_semih_brand as brand
from build_native_volume_patch import elf_va_offset
from native_ui_v79_assets import image_paths

BASE = brand.ROOT/'analiz/native-ui-candidate/v7.9-tv/overlay'


class SemihBrandTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.elf = (BASE/'08_APP/bin/dvbt_board').read_bytes()
        cls.table = (BASE/'08_APP/rc/rc/bin/Image_res.bin').read_bytes()

    def test_only_eight_immediate_operands_change(self):
        actual, proof = brand.apply(self.elf)
        expected = bytearray(self.elf)
        for va in brand.PATCHES:
            at = elf_va_offset(self.elf, va, 4)
            struct.pack_into('<I', expected, at, 0x24050888)
        self.assertEqual(actual, bytes(expected))
        self.assertEqual(len(actual), len(self.elf))
        self.assertEqual(len(proof['instruction_patches']), 8)
        self.assertFalse(proof['geometry_modified'])
        self.assertFalse(proof['helpers_added'])

    def test_source_guard(self):
        damaged = bytearray(self.elf); damaged[100] ^= 1
        with self.assertRaises(ValueError): brand.apply(bytes(damaged))
        with self.assertRaises(ValueError): brand.apply(bytearray(self.elf))

    def test_append_preserves_all_stock_and_inherited_images(self):
        assets, table, proof = brand.expected_payloads(self.table)
        before, after = image_paths(self.table), image_paths(table)
        self.assertEqual(len(after), 2185)
        self.assertEqual(after[:-1], before)
        self.assertEqual(after[915], before[915])
        self.assertEqual(table[56:len(self.table)], self.table[56:])
        self.assertEqual(set(assets), {brand.RESOURCE})
        self.assertEqual(after[2184], '../rc/ARimages/Grundig/modern/semih_menu_brand.png')
        self.assertTrue(proof['original_915_unchanged'])

    def test_table_guard(self):
        damaged = bytearray(self.table); damaged[-2] ^= 1
        with self.assertRaises(ValueError): brand.expected_payloads(bytes(damaged))

    def test_native_alpha_capheight_and_center(self):
        raw = (brand.OUT/'semih_menu_brand.png').read_bytes()
        fmt = brand.png_format(raw)
        self.assertTrue(fmt['transparency'])
        im = Image.open(io.BytesIO(raw)).convert('RGBA')
        self.assertEqual(im.size, (400, 120))
        self.assertEqual(im.getchannel('A').getbbox(), (98, 43, 302, 77))
        self.assertEqual((98+302)/2, 200)
        self.assertEqual(77-43, 34)
        self.assertEqual(im.getpixel((0, 0)), (255, 255, 255, 0))

    def test_crc_validation(self):
        raw = bytearray((brand.OUT/'semih_menu_brand.png').read_bytes()); raw[-1] ^= 1
        with self.assertRaises(ValueError): brand.png_format(bytes(raw))

    def test_evidence_and_artwork_are_explicit(self):
        self.assertIn('not an exact recovered font', brand.source_svg())
        self.assertNotIn('<image', brand.source_svg())
        self.assertNotIn('<text', brand.source_svg())
        self.assertEqual((brand.OUT/'semih_menu_brand.svg').read_bytes(), brand.source_svg().encode())


if __name__ == '__main__': unittest.main()
