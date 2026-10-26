"""Offline branch/overlay regressions. No firmware program or service is run."""
import json
import os
import struct
import tempfile
import unittest
from pathlib import Path

import build_native_volume_patch as patch


class NativeVolumePatchTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.num = (patch.SOURCE / patch.NUM_REL).read_bytes()
        cls.elf = (patch.SOURCE / patch.ELF_REL).read_bytes()
        cls.new_num, cls.new_elf, cls.changes = patch.construct(cls.num, cls.elf)

    def test_exact_sources_and_allowlisted_changes(self):
        self.assertEqual(patch.sha(self.num), patch.NUM_SHA)
        self.assertEqual(patch.sha(self.elf), patch.ELF_SHA)
        self.assertEqual(len(self.changes), 14)
        num_allowed = {56 + i * 4 + k for i, *_ in patch.NUM_PATCHES for k in range(4)}
        elf_allowed = set(range(patch.PATCH_OFF, patch.PATCH_OFF + len(patch.NEW)))
        patch.verify_allowlist(self.num, self.new_num, num_allowed)
        patch.verify_allowlist(self.elf, self.new_elf, elf_allowed)
        self.assertEqual(self.elf[:patch.PATCH_OFF], self.new_elf[:patch.PATCH_OFF])
        self.assertEqual(self.elf[patch.PATCH_OFF + 20:], self.new_elf[patch.PATCH_OFF + 20:])
        self.assertEqual(self.new_num[:56], self.num[:56])

    def test_tampered_sources_and_unlisted_changes_rejected(self):
        bad_num = bytearray(self.num)
        bad_num[60] ^= 1
        with self.assertRaises(ValueError):
            patch.construct(bytes(bad_num), self.elf)
        bad_elf = bytearray(self.elf)
        bad_elf[patch.PATCH_OFF] ^= 1
        with self.assertRaises(ValueError):
            patch.construct(self.num, bytes(bad_elf))
        with self.assertRaises(ValueError):
            patch.verify_allowlist(self.elf, bytes(bad_elf), set())
        with self.assertRaises(ValueError):
            patch.verify_allowlist(self.num, self.num + b"x", {len(self.num)})

    def test_pt_load_and_no_midwindow_direct_entries(self):
        self.assertEqual(patch.elf_va_offset(self.elf, patch.PATCH_VA, 20), patch.PATCH_OFF)
        with self.assertRaises(ValueError):
            patch.elf_va_offset(self.elf, 0, 20)
        result = patch.direct_entry_scan(self.elf)
        self.assertEqual(result["direct_incoming"], [])
        self.assertFalse(any(result["literal_va_counts"].values()))

    def test_geometry_children_fit_without_global_font_or_color_edits(self):
        def value(i):
            return struct.unpack_from("<I", self.new_num, 56 + 4 * i)[0]
        width, height = value(0x5A43), value(0x5A3E)
        self.assertEqual((width, height), (76, 500))
        self.assertLessEqual(value(0x5A45) + height, value(0x5A3F))
        for x, y, w, h in ((0x5A68, 0x5A69, 0x5A67, 0x5A66),
                           (0x5A78, 0x5A79, 0x5A77, 0x5A76),
                           (0x5A6C, 0x5A6D, 0x5A6B, 0x5A6A)):
            self.assertLessEqual(value(x) + value(w), width)
            self.assertLessEqual(value(y) + value(h), height)
        self.assertEqual(value(0x3215), 36)
        self.assertEqual(value(0x45F5), 3)
        self.assertEqual(value(0x45F9), 4)

    def test_all_202_host_cpu_cases_and_delay_slots(self):
        result = patch.validate_host(self.elf, self.new_elf)
        self.assertEqual(result["emulator_cases"], 202)
        self.assertTrue(result["delay_slots_verified"])
        self.assertTrue(result["virtual_call_arguments_preserved"])
        self.assertTrue(result["saved_s0_and_epilogue_verified"])
        self.assertTrue(result["original_state_unchanged"])

    def test_output_alias_traversal_and_hardlink_rejected(self):
        for destination in (patch.SOURCE / patch.ELF_REL, patch.OUT / "../../../../README.md",
                            patch.ROOT / "README.md"):
            with self.subTest(path=destination):
                with self.assertRaises(ValueError):
                    patch.output_guard(destination)
        patch.OUT.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(dir=patch.OUT, prefix="guard-test-") as folder:
            fixture = Path(folder) / "fixture"
            alias = Path(folder) / "alias"
            fixture.write_bytes(b"unrelated fixture; not firmware")
            os.link(fixture, alias)
            with self.assertRaises(ValueError):
                patch.output_guard(alias)
            self.assertEqual(fixture.read_bytes(), b"unrelated fixture; not firmware")

    def test_deterministic_complete_build_and_original_hashes(self):
        first = patch.build()
        second = patch.build()
        self.assertEqual(first, second)
        self.assertFalse(first["TV_tested"])
        self.assertFalse(first["elf_patch"]["arc_routing_changed"])
        self.assertFalse(first["elf_patch"]["service_mute_flags_changed"])
        for record in first["records"]:
            self.assertEqual(patch.sha((patch.ROOT / record["candidate"]).read_bytes()),
                             record["candidate_sha256"])
            self.assertEqual(patch.sha((patch.SOURCE / record["relative_path"]).read_bytes()),
                             record["original_sha256"])
        manifest = json.loads((patch.OUT / "manifest.json").read_text())
        self.assertEqual(manifest["records"], second["records"])


if __name__ == "__main__":
    unittest.main(verbosity=2)
