"""Synthetic in-memory FAT32 cases only. Never opens a real volume."""
from array import array
import io
import struct
import unittest
from recover_fat32_diag import inspect, numeric_records

LINES = b'MGDIAG_META 1 3 0 0 3\n'+b'MGDIAG 1 1 2 0 4300 4500 4300 0 3\n'+b'MGDIAG 1 1 7 6 4855 4955 4855 0 3\n'+b'MGDIAG 1 1 2 0 4300 4500 4300 0 3\n'


def fixture(kind='orphan'):
    reserved, per_fat, count = 32, 512, 65525
    start = (reserved+2*per_fat)*512
    raw = bytearray(start+8*512)
    raw[510:512] = b'\x55\xaa'
    struct.pack_into('<H', raw, 11, 512); raw[13] = 1; raw[16] = 2
    struct.pack_into('<H', raw, 14, reserved)
    struct.pack_into('<I', raw, 32, reserved+2*per_fat+count)
    struct.pack_into('<I', raw, 36, per_fat); struct.pack_into('<I', raw, 44, 2)
    fat = array('I', [0])*65536
    for i in [0, 1, 2, 3, 4]: fat[i] = 0x0fffffff
    if kind == 'none': fat[4] = 0
    if kind == 'cross': fat[4] = 3
    if kind == 'cycle': fat[4] = 5; fat[5] = 4
    f = fat.tobytes()
    raw[reserved*512:(reserved+per_fat)*512] = f
    raw[(reserved+per_fat)*512:start] = f
    if kind == 'mirror': raw[(reserved+per_fat)*512+16] ^= 1
    entry = bytearray(32); entry[:11] = b'LIVE    BIN'; entry[11] = 0x20
    struct.pack_into('<H', entry, 26, 3); struct.pack_into('<I', entry, 28, 3)
    raw[start:start+32] = entry
    raw[start+512:start+515] = b'abc'
    raw[start+1024:start+1024+len(LINES)] = LINES
    return io.BytesIO(raw)


class RecoveryTests(unittest.TestCase):
    def test_orphan_recovered_without_stream_mutation(self):
        stream = fixture(); before = stream.getvalue(); result = inspect(stream)
        self.assertEqual(result['orphan_clusters'], 1)
        self.assertEqual(result['recovered'][0]['numeric_records'], LINES.decode().splitlines())
        self.assertEqual(stream.getvalue(), before)

    def test_adjacent_records_are_all_preserved(self):
        self.assertEqual(len(numeric_records(LINES)), 4)

    def test_no_orphans_after_allocation_cleanup(self):
        self.assertEqual(inspect(fixture('none'))['orphan_clusters'], 0)

    def test_mirrored_fat_disagreement_rejected(self):
        with self.assertRaisesRegex(ValueError, 'Mirrored FATs differ'): inspect(fixture('mirror'))

    def test_orphan_cannot_include_live_file(self):
        with self.assertRaisesRegex(ValueError, 'links into live'): inspect(fixture('cross'))

    def test_orphan_cycle_rejected(self):
        with self.assertRaisesRegex(ValueError, 'cycle'): inspect(fixture('cycle'))

    def test_private_or_malformed_lines_not_returned(self):
        data = b'private text\nMGDIAG 1 secret\nMGDIAG 1 999999999999 2 0 1 2 1 0 3\n'
        self.assertEqual(numeric_records(data), [])


if __name__ == '__main__': unittest.main(verbosity=2)
