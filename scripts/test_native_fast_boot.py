"""Bounded read-only validation of the fast-boot investigation guards."""
import hashlib
from pathlib import Path
import struct
import tempfile
import unittest

from native_fast_boot import Elf32, ROOT, SOURCES, checked_bytes, inspect_sources


class FastBootEvidenceTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        relative, sha = SOURCES["control"]
        cls.control = checked_bytes(ROOT / "analiz/dosya-sistemleri-tam" / relative, sha)

    def test_real_sources_stubs_and_current_baseline(self):
        proof = inspect_sources()
        self.assertFalse(proof["patch_emitted"])
        self.assertFalse(proof["firmware_bytes_modified"])
        self.assertEqual(3, len(proof["compiled_transition_stubs"]))
        self.assertEqual(24, sum(q["complete_functions"] for q in proof["retained_direct_ghidra_queries"]))

    def test_file_backed_boundary_refuses_unmapped_tail(self):
        elf = Elf32(self.control)
        p = next(p for p in elf.loads if p[4] < p[5])
        with self.assertRaises(ValueError):
            elf.at(p[2] + p[4] - 4, 8)

    def test_corrupt_layout_fails_before_symbol_scan(self):
        data = bytearray(self.control)
        struct.pack_into("<I", data, 32, len(data) - 2)
        with self.assertRaises(ValueError):
            Elf32(bytes(data))

    def test_wrong_identity_fails_closed(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "sample"
            path.write_bytes(b"changed")
            with self.assertRaises(ValueError):
                checked_bytes(path, hashlib.sha256(b"original").hexdigest())
            self.assertEqual(b"changed", path.read_bytes())

    def test_missing_symbol_has_no_fallback(self):
        with self.assertRaises(ValueError):
            Elf32(self.control).symbol("nonexistent_fast_boot_implementation")

    def test_read_only_inspection_preserves_input(self):
        before = hashlib.sha256(self.control).hexdigest()
        elf = Elf32(self.control)
        elf.symbol("_ZN12MSrv_Control18Normal2FakeStandbyEv")
        self.assertEqual(before, hashlib.sha256(self.control).hexdigest())


if __name__ == "__main__":
    unittest.main()
