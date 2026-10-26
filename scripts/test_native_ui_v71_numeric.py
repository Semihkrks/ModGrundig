"""Static byte, actual outer-window clipping, and resource regressions."""
import struct
import unittest

import native_ui_v71_numeric as patch
from build_native_ui_v7_tv import verified_packaging_records


class NumericFixTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.base = {'08_APP' + r['path']: r['candidate'].read_bytes()
                    for r in verified_packaging_records()}
        cls.after, cls.proof = patch.apply(cls.base)

    def test_physical_v7_symptom_is_predicted_by_actual_outer_window(self):
        before = self.proof['before']
        self.assertEqual(before['outer_frame'], [0, 0, 1920, 80])
        self.assertEqual(before['root'], [0, 0, 1920, 312])
        self.assertEqual(before['background_visible'], [1538, 64, 310, 16])
        self.assertEqual(before['digits_visible'][3], 0)

    def test_both_card_and_digits_fit_all_actual_ancestors(self):
        after = self.proof['after']
        self.assertEqual(after['outer_frame'], [0, 0, 1920, 312])
        for widget in ('background', 'digits'):
            self.assertEqual(after[widget + '_visible'], after[widget])
            self.assertEqual(patch.intersect(after[widget], after['root']), after[widget])
            self.assertEqual(patch.intersect(after[widget], after['outer_frame']), after[widget])

    def test_card_and_text_are_siblings_with_safe_screen_insets(self):
        after = self.proof['after']
        self.assertEqual(after['background'], [1538, 64, 310, 224])
        self.assertEqual(after['digits'], [1566, 118, 254, 78])
        self.assertEqual(patch.intersect(after['digits'], after['background']), after['digits'])
        self.assertEqual(patch.intersect(after['background'], [72, 54, 1776, 972]), after['background'])

    def test_only_one_instruction_word_changes_without_length_change(self):
        before, after = self.base[patch.ELF], self.after[patch.ELF]
        off = patch.elf_va_offset(before, 0x89518c, 4)
        self.assertEqual(struct.unpack_from('<I', before, off)[0], 0x24040050)
        self.assertEqual(struct.unpack_from('<I', after, off)[0], 0x2404098f)
        self.assertEqual(before[:off], after[:off])
        self.assertEqual(before[off + 4:], after[off + 4:])
        self.assertEqual(len(before), len(after))

    def test_global_geometry_assets_fonts_and_all_other_paths_unchanged(self):
        self.assertEqual(self.base.keys(), self.after.keys())
        for path in self.base:
            if path != patch.ELF:
                self.assertIs(self.base[path], self.after[path])
        self.assertEqual(patch.number(self.after[patch.NUM], 0x50), 80)
        self.assertFalse(self.proof['global_num_0x50_changed'])

    def test_channel_timer_and_key_handlers_unchanged(self):
        # Exact retained FDE ranges, plus constructor state/service initialization.
        for start, end in ((0x89552c, 0x895b84), (0x8968d8, 0x89711c), (0x89722c, 0x897388)):
            off = patch.elf_va_offset(self.base[patch.ELF], start, end - start)
            self.assertEqual(self.base[patch.ELF][off:off + end - start],
                             self.after[patch.ELF][off:off + end - start])

    def test_native_image_flag_and_all_four_text_states_remain_verified(self):
        raw = self.after[patch.ELF]
        expected = {0x89610c: 0xa204003a, 0x896800: 0x24020011}
        expected.update({va: 0x24050883 for va in (0x896260, 0x896284, 0x8962a8, 0x8962cc)})
        expected.update({va: 0x240204b0 for va in (0x896730, 0x896740, 0x896750, 0x896760)})
        expected.update({va: 0x2402003a for va in (0x896784, 0x8967a8, 0x8967cc, 0x8967f0)})
        expected.update({va: 0x24040000 for va in (0x896548, 0x896568, 0x896588, 0x8965a8)})
        for va, word in expected.items():
            self.assertEqual(struct.unpack_from('<I', raw, patch.elf_va_offset(raw, va, 4))[0], word)

    def test_numeric_font_fits_padded_box(self):
        metrics = self.proof['resources']['font_metrics']
        self.assertGreater(metrics['12']['width'], 50)
        self.assertLessEqual(metrics['99999']['width'] + 6, 254)
        self.assertLessEqual(max(v['bbox'][3] for v in metrics.values()) + 6, 78)

    def test_rejects_stale_numeric_geometry(self):
        payloads = dict(self.base)
        nums = bytearray(payloads[patch.NUM])
        struct.pack_into('<I', nums, 56 + 4 * 0x99a, 106)
        payloads[patch.NUM] = bytes(nums)
        with self.assertRaisesRegex(ValueError, 'geometry'):
            patch.apply(payloads)

    def test_rejects_stale_code_and_double_application(self):
        with self.assertRaisesRegex(ValueError, 'code span'):
            patch.apply(self.after)
        payloads = dict(self.base)
        elf = bytearray(payloads[patch.ELF])
        off = patch.elf_va_offset(elf, 0x895548, 4)
        elf[off] ^= 1
        payloads[patch.ELF] = bytes(elf)
        with self.assertRaisesRegex(ValueError, 'code span'):
            patch.apply(payloads)

    def test_rejects_unreviewed_card_or_image_table(self):
        for path in (patch.CARD, patch.IMAGE):
            payloads = dict(self.base)
            payloads[path] = payloads[path] + b'\0'
            with self.assertRaisesRegex(ValueError, 'resource changed'):
                patch.apply(payloads)

    def test_composes_volume_changes_without_mutating_input(self):
        payloads = dict(self.base)
        nums = bytearray(payloads[patch.NUM])
        struct.pack_into('<I', nums, 56 + 4 * 0x5a43, 72)
        payloads[patch.NUM] = bytes(nums)
        raw = bytearray(payloads[patch.ELF])
        off = patch.elf_va_offset(raw, 0xfbd38c, 4)
        raw[off] ^= 1  # Outside numeric ownership; parent validates volume bytes.
        payloads[patch.ELF] = bytes(raw)
        input_snapshot = dict(payloads)
        result, _ = patch.apply(payloads)
        self.assertEqual(result[patch.NUM], payloads[patch.NUM])
        self.assertEqual(result[patch.ELF][off:off + 4], payloads[patch.ELF][off:off + 4])
        self.assertEqual(payloads, input_snapshot)


if __name__ == '__main__':
    unittest.main()
