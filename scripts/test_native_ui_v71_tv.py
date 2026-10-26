"""Cross-helper scope and native-handler preservation checks for V7.1."""
import json
import struct
import unittest
from unittest.mock import patch

import build_native_ui_v71_tv as build
import build_native_ui_v7_tv as prior
from build_native_volume_patch import elf_va_offset


class V71IntegrationTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.old = {row['path']: row['candidate'].read_bytes() for row in prior.verified_packaging_records()}
        cls.new = {row['path']: row['candidate'].read_bytes() for row in build.verified_packaging_records()}

    def test_only_three_reviewed_files_differ_from_device_tested_v7(self):
        self.assertEqual(self.old.keys(), self.new.keys())
        self.assertEqual(len(self.new), 12)
        self.assertEqual(sorted(path for path in self.old if self.old[path] != self.new[path]),
                         ['/bin/dvbt_board', '/rc/ARimages/Common/popups/volumeControl/bg.png', '/rc/rc/bin/Num_res.bin'])
        self.assertEqual(build.verified_records(), build.verified_packaging_records())

    def test_exact_three_instruction_words_and_two_position_resources(self):
        old, new = self.old['/bin/dvbt_board'], self.new['/bin/dvbt_board']
        differences = [i for i in range(0, len(old) - 3, 4) if old[i:i + 4] != new[i:i + 4]]
        self.assertEqual(differences, [elf_va_offset(old, va, 4) for va in (0x89518c, 0xfbb550, 0xfbb55c)])
        old, new = self.old['/rc/rc/bin/Num_res.bin'], self.new['/rc/rc/bin/Num_res.bin']
        ids = [i for i in range((len(old) - 56) // 4) if old[56 + i * 4:60 + i * 4] != new[56 + i * 4:60 + i * 4]]
        self.assertEqual(ids, [0x5a41, 0x5a42])
        self.assertEqual(struct.unpack_from('<I', new, 56 + 4 * 0x50)[0], 80)

    def test_all_original_message_tables_and_nonvisual_handlers_preserved(self):
        original = (build.SOURCE / '08_APP/bin/dvbt_board').read_bytes()
        current = self.new['/bin/dvbt_board']
        maps = json.loads((build.ROOT / 'analiz/ui-yapi-haritasi.json').read_text(encoding='utf-8'))['message_maps']
        checked, changed = set(), set()
        for mapping in maps:
            if mapping['module'] != '08_APP/bin/dvbt_board':
                continue
            for row in mapping.get('records', []):
                off = row['record_file_offset']
                self.assertEqual(current[off:off + 28], struct.pack('<7I', *row['raw_u32']))
                handler = row['handler']
                extent, start = handler.get('fde_range'), int(handler['address'], 16)
                if not extent or int(extent['start'], 16) != start or start in checked:
                    continue
                checked.add(start)
                size = int(extent['end_exclusive'], 16) - start
                off = elf_va_offset(original, start, size)
                if original[off:off + size] != current[off:off + size]:
                    changed.add(start)
        self.assertGreater(len(checked), 1000)
        self.assertTrue(changed.issubset({0x895b84, 0xfb9780, 0xfb7d18}), [hex(v) for v in changed])

    def test_code_pins_and_output_boundary_reject_tampering(self):
        import native_ui_v71_tv_pins as pins
        with patch.object(pins, 'MANIFEST_SHA', '0' * 64):
            with self.assertRaises(ValueError):
                build.verified_packaging_records()
        with self.assertRaises(ValueError):
            build.guard(build.ROOT / 'outside-v71.bin')


if __name__ == '__main__':
    unittest.main()
