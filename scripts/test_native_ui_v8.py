"""Native v8 composition, stable image IDs and independent packaging pins."""
import json
import struct
import unittest
from unittest.mock import patch
import build_native_ui_v8 as build

@unittest.skipUnless((build.OUT/'manifest.json').exists(),'V8 menu experiment cancelled by user')
class V8CompositionTests(unittest.TestCase):
    def test_reconstructed_overlay_agrees_with_code_pinned_packaging(self):
        reconstructed=build.verified_records();pinned=build.verified_packaging_records()
        self.assertEqual(reconstructed,pinned)
        self.assertEqual(len(reconstructed),68)
        self.assertEqual(sum(r['original_sha256'] is None for r in reconstructed),45)

    def test_original_image_records_and_all_event_bytes_stay_unchanged(self):
        import build_native_volume_patch as original
        base=build.ROOT/'analiz/native-ui-candidate/v7/overlay'
        prior=(base/build.IMAGE_REL).read_bytes();current=(build.OUT/'overlay'/build.IMAGE_REL).read_bytes()
        self.assertEqual(current[56:len(prior)],prior[56:])
        self.assertEqual(struct.unpack_from('<I',current,28)[0],2226)
        before=(base/build.ELF_REL).read_bytes();after=(build.OUT/'overlay'/build.ELF_REL).read_bytes()
        m=json.loads((build.OUT/'manifest.json').read_text(encoding='utf-8'))
        allowed={r['file_offset']+i for p in m['changes']['components'].values() for r in p['code_records'] for i in range(4)}
        original.verify_allowlist(before,after,allowed)
        self.assertFalse(m['changes']['event_handlers_modified'])
        self.assertEqual((base/build.NUM_REL).read_bytes(),(build.OUT/'overlay'/build.NUM_REL).read_bytes())

    def test_table_gaps_and_path_escape_are_rejected(self):
        prior=(build.ROOT/'analiz/native-ui-candidate/v7/overlay'/build.IMAGE_REL).read_bytes()
        for row in ({'id':2181,'path':'../rc/ARimages/Grundig/modern/v8.png'},
                    {'id':2180,'path':'../rc/ARimages/Grundig/modern/../../bad.png'}):
            with self.assertRaises(ValueError):build.append_images(prior,[row])
        with self.assertRaises(ValueError):build.append_images(prior[:-1],[])

    def test_manifest_cannot_replace_code_pinned_identity(self):
        import native_ui_v8_pins as pins
        with patch.object(pins,'MANIFEST_SHA','0'*64):
            with self.assertRaises(ValueError):build.verified_packaging_records()
        with patch.object(pins,'RECORDS',()):
            with self.assertRaises(ValueError):build.verified_packaging_records()

if __name__=='__main__':unittest.main()
