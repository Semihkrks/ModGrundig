"""Bounded source/contract guards for native fast-zapping evidence."""
import struct
import unittest

import native_fast_channel as native


class NativeFastChannelProofTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.baseline = (native.ROOT / "analiz/native-ui-candidate/v7.9-tv/overlay/08_APP/bin/dvbt_board").read_bytes()

    def test_original_and_v79_have_same_native_switch_contract(self):
        original = (native.ROOT / "analiz/dosya-sistemleri-tam/08_APP/bin/dvbt_board").read_bytes()
        first, second = native.collect_proof(original), native.collect_proof(self.baseline)
        self.assertEqual(first["checked_app_words"], second["checked_app_words"])
        self.assertEqual(first["modules"], second["modules"])

    def test_no_forced_getter_or_mutating_apply_is_exposed(self):
        before = self.baseline
        proof = native.collect_proof(before)
        self.assertFalse(proof["patch_emitted"])
        self.assertFalse(hasattr(native, "apply"))
        self.assertEqual(before, self.baseline)

    def test_unknown_app_is_rejected(self):
        changed = bytearray(self.baseline)
        changed[-1] ^= 1
        with self.assertRaisesRegex(ValueError, "Unsupported app baseline"):
            native.collect_proof(bytes(changed))

    def test_changed_native_argument_word_is_rejected(self):
        changed = bytearray(self.baseline)
        offset = native.file_offset(changed, 0x0053D54C)
        struct.pack_into("<I", changed, offset, 0x24050001)
        with self.assertRaisesRegex(ValueError, "Instruction mismatch"):
            native.require_words(changed, {0x0053D54C: 0x00602821})

    def test_elf_file_backing_is_required(self):
        with self.assertRaisesRegex(ValueError, "ELF32"):
            native.file_offset(b"not an ELF", 0)
        with self.assertRaisesRegex(ValueError, "not uniquely file-backed"):
            native.file_offset(self.baseline, 0xFFFFFFFF)

    def test_timeout_values_are_not_channel_benchmarks(self):
        proof = native.collect_proof(self.baseline)
        self.assertEqual(proof["selected_value"], {"Hayır": 0, "Evet": 1})
        self.assertEqual(proof["enabled_avsync_timeout_ms"], 200)
        self.assertEqual(proof["disabled_avsync_timeout_ms"], 2000)
        self.assertIn("elapsed<=GetAvSyncTimeout()", proof["timeout_condition"])
        self.assertFalse(proof["target_executed"])


if __name__ == "__main__":
    unittest.main()
