"""Read-only positive and tamper checks on the diagnostic container in RAM."""
import lzma
from pathlib import Path
import struct
import unittest
import zlib
from unpack_mstar import parse_header
from verify_native_hevc_diag import verify, ROOT


class PackageTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        out = ROOT/'analiz/native-ui-candidate/v7.9-hevc-diag/package'
        cls.base = (ROOT/'analiz/native-ui-candidate/v7.9-tv/package/GM_SWImage_UI_v7.9-tv_OFFLINE_UNVERIFIED.bin').read_bytes()
        cls.candidate = (out/'GM_SWImage_UI_v7.9-hevc-diag_OFFLINE_UNVERIFIED.bin').read_bytes()
        cls.images = {7: (out/'07_MSLIB.ubifs').read_bytes(), 11: (out/'11_customer_update.ubifs').read_bytes()}

    def repaired_crc(self, raw):
        raw = bytearray(raw); footer = len(raw)-24
        struct.pack_into('<I', raw, footer, zlib.crc32(raw[:0x4000]))
        struct.pack_into('<I', raw, footer+4, zlib.crc32(raw[:footer+4]))
        return bytes(raw)

    def mutate_header(self, old, new):
        self.assertEqual(len(old), len(new))
        self.assertEqual(self.candidate[:0x4000].count(old), 1)
        raw = bytearray(self.candidate)
        at = raw.index(old, 0, 0x4000); raw[at:at+len(old)] = new
        return self.repaired_crc(raw)

    def test_exact_candidate(self):
        result = verify(self.base, self.candidate, self.images)
        self.assertEqual(result['payloads_checked'], 14)
        self.assertEqual(result['changed_payloads'], [7, 11])

    def test_header_comment_tamper_rejected_even_with_valid_crc(self):
        blob = self.mutate_header(b'# File Partition: set_partition', b'# File Partition: Set_partition')
        with self.assertRaises(ValueError): verify(self.base, blob, self.images)

    def test_customer_write_extent_tamper_rejected(self):
        blob = self.mutate_header(b'customer_update 0x300000 #customer', b'customer_update 0x600000 #customer')
        with self.assertRaises(ValueError): verify(self.base, blob, self.images)

    def test_second_mslib_write_length_must_match(self):
        length = f'0x{len(self.images[7]):x}'.encode()
        altered = f'0x{len(self.images[7])+4:x}'.encode()
        blob = self.mutate_header(b'MSLIB '+length+b' '+length, b'MSLIB '+length+b' '+altered)
        with self.assertRaises(ValueError): verify(self.base, blob, self.images)

    def test_boot_payload_tamper_rejected(self):
        _, rows = parse_header(self.candidate[:0x4000], len(self.candidate)-24)
        raw = bytearray(self.candidate); raw[rows[0]['source_offset']+20] ^= 0x40
        with self.assertRaises((ValueError, lzma.LZMAError)):
            verify(self.base, self.repaired_crc(raw), self.images)

    def test_outer_crc_tamper_rejected(self):
        raw = bytearray(self.candidate); raw[-24] ^= 1
        with self.assertRaises(ValueError): verify(self.base, bytes(raw), self.images)


if __name__ == '__main__':
    unittest.main(verbosity=2)
