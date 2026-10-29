"""Integration checks for the actual retained menu-brand candidate."""
import json
import unittest

import build_native_ui_v710_tv as candidate
import build_native_ui_v79_tv as baseline
from native_semih_brand import IMAGE_ID, PATCHES, RESOURCE
from build_native_volume_patch import elf_va_offset
from native_ui_v79_assets import image_paths


class MenuBrandIntegrationTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.old = {'08_APP' + row['path']: row['candidate'].read_bytes()
                   for row in baseline.verified_packaging_records()}
        cls.rows = candidate.verified_packaging_records()
        cls.new = {'08_APP' + row['path']: row['candidate'].read_bytes()
                   for row in cls.rows}

    def test_retained_release_reconstructs_from_pinned_sources(self):
        self.assertEqual(candidate.verified_records(), self.rows)
        self.assertEqual(len(self.new), 19)

    def test_only_menu_code_table_and_private_logo_differ(self):
        self.assertEqual(set(self.new) - set(self.old), {RESOURCE})
        self.assertFalse(set(self.old) - set(self.new))
        self.assertEqual({p for p in self.old if self.old[p] != self.new[p]},
                         {'08_APP/bin/dvbt_board', '08_APP/rc/rc/bin/Image_res.bin'})

    def test_entire_elf_outside_declared_operands_is_preserved(self):
        old, new = self.old['08_APP/bin/dvbt_board'], self.new['08_APP/bin/dvbt_board']
        self.assertEqual(len(old), len(new))
        allowed = {elf_va_offset(old, address, 4) + i for address in PATCHES for i in (0, 1)}
        self.assertEqual({i for i, (a, b) in enumerate(zip(old, new)) if a != b}, allowed)
        self.assertEqual(new[:4096], old[:4096])

    def test_existing_image_ids_and_stock_brand_remain_unchanged(self):
        path = '08_APP/rc/rc/bin/Image_res.bin'
        old, new = image_paths(self.old[path]), image_paths(self.new[path])
        self.assertEqual(new[:IMAGE_ID], old)
        self.assertEqual(len(new), IMAGE_ID + 1)
        self.assertIn('logo_400_120.png', new[915])
        self.assertIn('semih_menu_brand.png', new[IMAGE_ID])

    def test_scope_does_not_claim_speed_or_hardware_activation(self):
        scope = json.loads((candidate.OUT / 'manifest.json').read_text(encoding='utf-8'))['scope']
        self.assertFalse(scope['fast_zapping_forced'])
        self.assertFalse(scope['fast_boot_enabled'])
        self.assertFalse(scope['television_tested'])
        self.assertFalse(scope['four_k_decoder_changes'])

    def test_builder_refuses_original_and_sibling_output_paths(self):
        for path in (candidate.SOURCE / '08_APP/bin/dvbt_board', baseline.OUT / 'manifest.json'):
            with self.assertRaises(ValueError):
                candidate.guard(path)


if __name__ == '__main__':
    unittest.main()
