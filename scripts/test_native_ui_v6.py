"""Offline v6 checks for bounded instruction/geometry changes and immutable inputs."""
import io
import json
from pathlib import Path
import struct
import unittest
from unittest.mock import patch

from PIL import Image
import build_native_ui_v6 as v6


class NativeV6Tests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.num = (v6.volume.SOURCE / v6.volume.NUM_REL).read_bytes()
        cls.elf = (v6.volume.SOURCE / v6.volume.ELF_REL).read_bytes()
        cls.prior_num, cls.prior_elf, _ = v6.v5.construct(cls.num, cls.elf)
        cls.new_num, cls.new_elf, cls.proof = v6.construct(cls.num, cls.elf)
        cls.manifest = json.loads((v6.OUT / 'manifest.json').read_text(encoding='utf-8'))

    def test_exact_five_local_instruction_changes(self):
        self.assertEqual(len(self.proof['code_records']), 5)
        allowed = set()
        for va, old, new, _ in v6.CODE_PATCHES:
            off = v6.volume.elf_va_offset(self.elf, va, 4)
            self.assertEqual(struct.unpack_from('<I', self.prior_elf, off)[0], old)
            self.assertEqual(struct.unpack_from('<I', self.new_elf, off)[0], new)
            allowed.update(range(off, off + 4))
        v6.volume.verify_allowlist(self.prior_elf, self.new_elf, allowed)
        self.assertEqual(v6.sha(self.new_elf), '9ededb627b8548d0b12f6495d66bac4a0943fb3d92e83a2f3547a86b1ec33dc3')
        self.assertEqual(tuple(new for _, _, new, _ in v6.CODE_PATCHES),
                         (0x2402003a,) * 4 + (0x24020011,))
        # All previous volume font and image instructions survive byte-for-byte.
        for va in v6.v5.v4.FONT_VAS + v6.v5.NUMERIC_FONT_VAS + v6.v5.NUMERIC_IMAGE_VAS:
            off = v6.volume.elf_va_offset(self.elf, va, 4)
            self.assertEqual(self.prior_elf[off:off + 4], self.new_elf[off:off + 4])

    def test_eight_only_num_changes_and_containment(self):
        expected = ((0x5a67,42,44),(0x5a66,42,44),(0x5a68,13,12),(0x5a69,394,393),
                    (0x98f,176,312),(0x993,112,224),(0x997,72,78),(0x99a,84,106))
        self.assertEqual(v6.NUM_PATCHES, expected)
        self.assertEqual(v6.sha(self.new_num), '43a48071364ae37466f34cc0b5ac61ebe9498ad72c53671defa591c5450e376e')
        v6.volume.verify_allowlist(self.prior_num, self.new_num,
                                  {56 + 4 * rid + k for rid, _, _ in expected for k in range(4)})
        n = lambda rid: struct.unpack_from('<I', self.new_num, 56 + 4 * rid)[0]
        self.assertEqual((n(0x5a43),n(0x5a3e)), (68,450))
        self.assertEqual((n(0x5a68),n(0x5a69),n(0x5a67),n(0x5a66)), (12,393,44,44))
        self.assertEqual(n(0x3215),36)
        self.assertEqual(n(0x321e),48)
        self.assertEqual((n(0x995),n(0x996),n(0x994),n(0x993)), (1538,64,310,224))
        self.assertEqual((n(0x999),n(0x99a),n(0x998),n(0x997)), (1566,106,254,78))
        self.assertLessEqual(n(0x996)+n(0x993),n(0x98f))
        self.assertLessEqual(n(0x999)+n(0x998),n(0x995)+n(0x994))
        self.assertLessEqual(n(0x99a)+n(0x997),n(0x996)+n(0x993))
        self.assertLessEqual(n(0x5a68)+n(0x5a67),68)
        self.assertLessEqual(n(0x5a69)+n(0x5a66),450)

    def test_card_alpha_static_text_and_font_fit(self):
        self.assertEqual(v6.sha(v6.card_png()), '6144405871b839f29d6be99b7696f678400a415f06c5893d43fd61937801547c')
        with Image.open(io.BytesIO(v6.card_png())) as card:
            self.assertEqual(card.size,(310,224))
            self.assertEqual(card.mode,'RGBA')
            self.assertEqual(card.getpixel((0,0))[3],0)
            self.assertEqual(card.getpixel((155,112)),(245,245,245,255))
            self.assertTrue(any(0<a<255 for a in card.getchannel('A').get_flattened_data()))
            for rect in ((28,22,205,42),(28,183,135,207),(234,20,283,46)):
                self.assertGreater(len(set(card.crop(rect).get_flattened_data())),10)
        metrics = v6.font_metrics()
        self.assertEqual(metrics['0x4ae']['size'],36)
        self.assertEqual(metrics['0x4b0']['size'],58)
        self.assertLess(metrics['0x4b0']['measured_widths']['99999'],254)
        self.assertEqual(metrics['0x4b0']['sha256'],v6.v5.DEJAVU_SHA)

    def test_overlay_reconstructs_24_files_and_changes_only_three(self):
        rows = v6.verified_records()
        self.assertEqual(len(rows),24)
        changes = set()
        for row in rows:
            relative = '08_APP' + row['path']
            if row['candidate'].read_bytes() != (v6.v5.OUT / 'overlay' / relative).read_bytes():
                changes.add(relative)
            if relative != v6.CARD_REL:
                self.assertEqual(row['original_sha256'],v6.sha((v6.volume.SOURCE / relative).read_bytes()))
        self.assertEqual(changes,{v6.volume.NUM_REL,v6.volume.ELF_REL,v6.CARD_REL})
        self.assertFalse(self.manifest['television_tested'])
        self.assertFalse(self.manifest['firmware_repacked'])
        self.assertFalse(self.manifest['flash_ready'])
        self.assertFalse(self.manifest['matched_channel_name']['implemented_in_overlay'])
        self.assertEqual(self.manifest['numeric_font']['global_num_0x321e'],48)
        self.assertEqual(self.manifest['rounded_numeric']['image_id'],2179)

    def test_previous_inputs_stay_pinned_and_existing_output_is_reverified(self):
        before = {row['candidate']:v6.sha(row['candidate'].read_bytes()) for row in v6.v5.verified_records()}
        v6.expected_payloads()
        self.assertEqual(before,{path:v6.sha(path.read_bytes()) for path in before})
        self.assertEqual(v6.build(),dict(status='verified_existing_v6',files=24))

    def test_tampered_overlay_and_manifest_rejected(self):
        target = v6.OUT / 'overlay' / v6.CARD_REL
        original_read = Path.read_bytes
        def tamper(path):
            raw = original_read(path)
            return raw[:-1]+bytes([raw[-1]^1]) if path == target else raw
        with patch.object(Path,'read_bytes',tamper):
            with self.assertRaisesRegex(ValueError,'reconstructed'):
                v6.verified_records()
        original_text = Path.read_text
        def tamper_manifest(path,*args,**kwargs):
            raw = original_text(path,*args,**kwargs)
            if path == v6.OUT / 'manifest.json':
                value = json.loads(raw)
                value['records'][0]['candidate_sha256'] = '0'*64
                return json.dumps(value)
            return raw
        with patch.object(Path,'read_text',tamper_manifest):
            with self.assertRaisesRegex(ValueError,'reconstructed'):
                v6.verified_records()

    def test_output_escape_and_source_tampering_rejected(self):
        for path in (v6.ROOT/'README.md',v6.OUT/'../../../../README.md',v6.volume.SOURCE/v6.volume.ELF_REL):
            with self.assertRaises(ValueError):
                v6.guard(path)
        with patch.object(v6,'OUT',v6.v5.OUT):
            with self.assertRaises(ValueError):
                v6.guard(v6.v5.OUT/'manifest.json')
        with self.assertRaises(FileExistsError):
            v6.write_new(v6.OUT/'manifest.json',b'overwrite')
        bad = bytearray(self.elf)
        bad[100] ^= 1
        with self.assertRaises(ValueError):
            v6.construct(self.num,bytes(bad))


if __name__ == '__main__':
    unittest.main(verbosity=2)
