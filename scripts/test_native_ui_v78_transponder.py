"""Verify the real stock RF table update; no tuner or firmware process runs."""
import gzip
import struct
import tarfile
import unittest
from pathlib import Path
import xml.etree.ElementTree as ET
import native_ui_v78_transponder as tp

ROOT = Path(__file__).resolve().parents[1]


class TransponderTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.path = ROOT / 'analiz/dosya-sistemleri-tam' / tp.RELATIVE
        cls.old = cls.path.read_bytes()
        cls.new, cls.proof = tp.transform(cls.old)
        cls.a, cls.ma = tp.read_xml(cls.old)
        cls.b, cls.mb = tp.read_xml(cls.new)

    def test_adds_exact_rf_tuple_in_native_units(self):
        root = ET.fromstring(self.b)
        sat = next(s for s in root if s.attrib.get('position') == '420')
        self.assertEqual(sat.attrib['numberofTP'], str(len(sat)))
        self.assertEqual(len(sat), 80)
        self.assertEqual(sum(dict(x.attrib) == tp.TARGET for x in sat), 1)
        self.assertEqual(dict(sat[0].attrib), tp.TARGET)

    def test_preserves_every_existing_transponder_and_other_satellite(self):
        a, b = ET.fromstring(self.a), ET.fromstring(self.b)
        self.assertEqual(len(a), len(b))
        for old, new in zip(a, b):
            if old.attrib.get('position') == '420':
                self.assertEqual([x.attrib for x in old], [x.attrib for x in new][1:])
            else:
                self.assertEqual(ET.tostring(old), ET.tostring(new))

    def test_preserves_archive_layout_metadata_and_valid_checksums(self):
        old, new = gzip.decompress(self.old), gzip.decompress(self.new)
        self.assertEqual(len(old), len(new))
        self.assertEqual(self.old[:10], self.new[:10])
        allowed = set(range(124, 136)) | set(range(148, 156))
        self.assertTrue(all(i in allowed for i, (a, b) in enumerate(zip(old[:512], new[:512])) if a != b))
        for field in ('name', 'mode', 'uid', 'gid', 'mtime', 'type', 'uname', 'gname'):
            self.assertEqual(getattr(self.ma, field), getattr(self.mb, field))
        self.assertEqual(self.mb.size, len(self.b))

    def test_fail_closed_unknown_or_already_modified_inputs(self):
        for raw in (b'', self.old[:-1], self.old + b'x', self.new):
            with self.assertRaises(ValueError):
                tp.transform(raw)

    def test_deterministic_and_source_immutable(self):
        other, proof = tp.transform(self.old)
        self.assertEqual(other, self.new)
        self.assertEqual(proof, self.proof)
        self.assertEqual(tp.sha(self.path.read_bytes()), tp.SOURCE_SHA)

    def test_does_not_claim_decoder_or_device_success(self):
        self.assertFalse(self.proof['decoder_or_panel_modified'])
        self.assertFalse(self.proof['user_channel_database_modified'])
        self.assertFalse(self.proof['physical_tv_tested'])
        self.assertFalse(self.proof['live_device_reloaded'])


if __name__ == '__main__':
    unittest.main(verbosity=2)
