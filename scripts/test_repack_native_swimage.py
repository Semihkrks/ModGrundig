"""Host-only envelope tests. No firmware, target binary or update command runs."""
import json
from pathlib import Path
import random
import struct
import tempfile
import unittest
from unittest.mock import patch
import zlib

import repack_native_swimage as R


def footer(data):
    result = bytearray(data)
    end = len(result) - 24
    struct.pack_into("<I", result, end, zlib.crc32(result[:R.HEADER_SIZE]))
    struct.pack_into("<I", result, end + 4, zlib.crc32(result[:end + 4]))
    return bytes(result)


def app_fixture(noisy=False):
    data = bytearray(17 * 126976)
    struct.pack_into("<I", data, 0, 0x06101831)
    struct.pack_into("<I", data, 16, 4096)
    data[20] = 6
    struct.pack_into("<IIIII", data, 28, 0, 2048, 126976, 17, 321)
    struct.pack_into("<I", data, 80, 4)
    struct.pack_into("<I", data, 4, zlib.crc32(data[8:4096]) ^ 0xFFFFFFFF)
    if noisy:
        data[4096:604096] = random.Random(714).randbytes(600000)
    return bytes(data)


def container_fixture():
    """A synthetic, non-mountable test envelope; never a device image."""
    app = app_fixture(noisy=True)
    labels = ["mboot"] * 5 + ["kernel", "ROOTFS", "mslib", "applications", "config", "customer", "customer", "certificate", "oad"]
    targets = ["mboot"] * 5 + ["KL", "RFS", "MSLIB", "APP", "CONFIG", "customer", "customer_update", "certificate", "oad"]
    lines = [b"# Script Size = 0x4000 #\n", b"setenv sample_guard preserved\n"]
    pieces = []
    offset = R.HEADER_SIZE
    for i, (label, target) in enumerate(zip(labels, targets)):
        raw = app if i == R.APP_ORDINAL else (f"inert test payload {i} ".encode() * 20)
        packed = R.compress_app(raw)
        lines.append(f"# File Partition: {label}\n".encode())
        commands = [f"filepartload 0x81E00000 $(UpgradeImage) 0x{offset:x} 0x{len(packed):x} #{label}",
                    f"mscompress7 d 0 0x81E00000 {len(packed):x} 0x80200000 #{label}",
                    f"crc32 0x80200000 0x{len(raw):x} 0x81E00000 #{label}",
                    f"mw 0x81E00004 0x{zlib.crc32(raw):08X} 4 #{label}",
                    f"cmp.b 0x81E00000 0x81E00004 4 #{label}",
                    f"ubi write 0x80200000 {target} 0x{len(raw):x} 0x{len(raw):x} #{label}"]
        lines.extend((command + "\n").encode() for command in commands)
        slot = ((len(packed) + R.ALIGNMENT - 1) // R.ALIGNMENT) * R.ALIGNMENT
        pieces.append(packed.ljust(slot, b"\x00"))
        offset += slot
    lines.append(b"% <- this is end of script symbol\n")
    header = b"".join(lines).ljust(R.HEADER_SIZE, b"\x00")
    return footer(header + b"".join(pieces) + b"\x00" * 8 + R.FOOTER_MARKER), app


class RepackTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.original, cls.old_app = container_fixture()
        cls.app = app_fixture()
        cls.digest = R.sha(cls.original)
        with patch.object(R, "STOCK_SHA256", cls.digest):
            cls.candidate, cls.report = R.build_bytes(cls.original, cls.app)

    def test_stock_sha_guard_rejects_synthetic_source(self):
        with self.assertRaisesRegex(ValueError, "SHA-256"):
            R.build_bytes(self.original, self.app)

    def test_all_14_payloads_redecoded_and_13_unchanged(self):
        report = R.verify_candidate(self.original, self.candidate, self.app)
        self.assertEqual(report["payloads_decoded"], 14)
        self.assertEqual(sum(row["unchanged"] for row in report["checks"]), 13)
        self.assertEqual(report["app_sha256"], R.sha(self.app))
        self.assertTrue(report["all_offsets_preserved"])
        self.assertEqual(len(self.original), len(self.candidate))

    def test_shrunken_app_keeps_entire_old_slot(self):
        before = R.inspect_package(self.original)["sections"][8]
        after = R.inspect_package(self.candidate)["sections"][8]
        self.assertGreater(before["compressed_bytes"] - after["compressed_bytes"], R.ALIGNMENT)
        self.assertEqual(before["slot_end"], after["slot_end"])
        self.assertTrue(not any(self.candidate[after["source_offset"] + after["compressed_bytes"]:after["slot_end"]]))

    def test_container_header_and_image_crcs(self):
        result = R.inspect_package(self.candidate)
        end = len(self.candidate) - 24
        self.assertEqual(int(result["header_crc32"], 16), zlib.crc32(self.candidate[:0x4000]))
        self.assertEqual(int(result["image_crc32"], 16), zlib.crc32(self.candidate[:end + 4]))

    def test_output_never_claims_flash_ready_or_tv_verified(self):
        self.assertFalse(self.report["flash_ready"])
        self.assertFalse(self.report["tv_verified"])
        self.assertFalse(self.report["firmware_executed"])

    def test_both_app_ubi_write_lengths(self):
        section = R.inspect_package(self.candidate)["sections"][8]
        write = next(line for line in section["commands"] if line.startswith("ubi write "))
        self.assertIn(f"APP 0x{len(self.app):x} 0x{len(self.app):x}", write)

    def test_app_slot_overflow_refused(self):
        slot = self.report["app_slot_bytes"]
        with patch.object(R, "STOCK_SHA256", self.digest), patch.object(R, "compress_app", return_value=b"X" * (slot + 1)):
            with self.assertRaisesRegex(ValueError, "exceeds its stock slot"):
                R.build_bytes(self.original, self.app)

    def test_higher_effort_host_presets_preserve_stock_stream_properties(self):
        raw=b'inert host compression compatibility fixture '*100
        for preset in ('9','9e'):
            with self.subTest(preset=preset):
                packed=R.compress_app(raw,preset)
                self.assertEqual(packed[:5],b'\x5d\x00\x00\x00\x04')
                self.assertEqual(packed[-2:],b'\xbe\xef')
                self.assertEqual(int.from_bytes(packed[5:13],'little'),len(raw))
                self.assertEqual(R.decode_section(packed,dict(source_offset=0,compressed_bytes=len(packed))),raw)
        with self.assertRaisesRegex(ValueError,'Unsupported host'):
            R.compress_app(raw,'arbitrary')

    def test_ubifs_bad_superblock_crc_refused(self):
        broken = bytearray(self.app)
        broken[500] ^= 1
        with self.assertRaisesRegex(ValueError, "superblock CRC"):
            R.ubifs_profile(bytes(broken))

    def test_ubifs_incompatible_geometry_refused(self):
        broken = bytearray(self.app)
        struct.pack_into("<I", broken, 32, 4096)
        struct.pack_into("<I", broken, 4, zlib.crc32(broken[8:4096]) ^ 0xFFFFFFFF)
        with self.assertRaisesRegex(ValueError, "geometry"):
            R.ubifs_profile(bytes(broken))

    def test_ubifs_length_mismatch_refused(self):
        with self.assertRaisesRegex(ValueError, "length and LEB"):
            R.ubifs_profile(self.app + b"X")

    def test_outer_crc_tamper_refused(self):
        broken = bytearray(self.candidate)
        broken[-24] ^= 1
        with self.assertRaisesRegex(ValueError, "header CRC"):
            R.inspect_package(bytes(broken))

    def test_footer_marker_tamper_refused(self):
        with self.assertRaisesRegex(ValueError, "footer marker"):
            R.inspect_package(self.candidate[:-1] + b"X")

    def test_non_app_update_command_change_refused(self):
        broken = footer(self.candidate.replace(b"sample_guard preserved", b"sample_guard modified!", 1))
        with self.assertRaisesRegex(ValueError, "Non-APP update"):
            R.verify_candidate(self.original, broken, self.app)

    def test_second_write_length_tamper_refused(self):
        old = f"APP 0x{len(self.app):x} 0x{len(self.app):x}".encode()
        new = f"APP 0x{len(self.app):x} 0x{len(self.app)-1:x}".encode()
        broken = footer(self.candidate.replace(old, new, 1))
        with self.assertRaisesRegex(ValueError, "write lengths"):
            R.verify_candidate(self.original, broken, self.app)

    def test_app_command_memory_address_tamper_refused(self):
        lines = self.candidate[:0x4000].splitlines(keepends=True)
        header = b"".join(line.replace(b"mw 0x81E00004", b"mw 0x81E00008")
                           if line.rstrip().endswith(b"#applications") else line for line in lines)
        broken = footer(header + self.candidate[0x4000:])
        with self.assertRaisesRegex(ValueError, "beyond reviewed"):
            R.verify_candidate(self.original, broken, self.app)

    def test_nonzero_slot_padding_refused(self):
        section = R.inspect_package(self.candidate)["sections"][8]
        broken = bytearray(self.candidate)
        broken[section["source_offset"] + section["compressed_bytes"] + 20] = 1
        with self.assertRaisesRegex(ValueError, "Nonzero payload padding"):
            R.inspect_package(footer(broken))

    def test_beef_trailer_tamper_refused(self):
        section = R.inspect_package(self.candidate)["sections"][3]
        broken = bytearray(self.candidate)
        broken[section["source_offset"] + section["compressed_bytes"] - 1] ^= 1
        with self.assertRaisesRegex(ValueError, "BE EF trailer"):
            R.inspect_package(footer(broken))

    def test_lzma_output_budget_refused(self):
        section = R.inspect_package(self.candidate)["sections"][3]
        broken = bytearray(self.candidate)
        offset = section["source_offset"] + 5
        broken[offset:offset + 8] = (R.MAX_SECTION + 1).to_bytes(8, "little")
        with self.assertRaisesRegex(ValueError, "budget"):
            R.inspect_package(footer(broken))

    def test_output_path_cannot_escape(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            with patch.object(R, "OUTPUT_ROOT", root / "isolated"):
                with self.assertRaisesRegex(ValueError, "outside isolated"):
                    R.new_output(root / "elsewhere.bin")
                with self.assertRaisesRegex(ValueError, "outside isolated"):
                    R.new_output(root / "isolated" / ".." / "escape.bin")

    def test_writes_readback_report_and_no_overwrite(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            source, app, output, report = [root / name for name in ("source.bin", "app.ubifs", "candidate.bin", "report.json")]
            source.write_bytes(self.original)
            app.write_bytes(self.app)
            with patch.object(R, "OUTPUT_ROOT", root), patch.object(R, "STOCK_SHA256", self.digest):
                result = R.build(source, app, output, report)
                self.assertEqual(result["verification"]["container_sha256"], R.sha(output.read_bytes()))
                self.assertFalse(json.loads(report.read_text(encoding="utf-8"))["flash_ready"])
                self.assertEqual(source.read_bytes(), self.original)
                self.assertEqual(app.read_bytes(), self.app)
                with self.assertRaisesRegex(ValueError, "overwrite"):
                    R.build(source, app, output, report)

    def test_stock_real_package_envelope_if_available(self):
        source = R.ROOT / "analiz/firmware-dogrulanmis/Target_GM/image/GM_SWImage.bin"
        if not source.is_file():
            self.skipTest("Original firmware unavailable; synthetic checks still run")
        raw = source.read_bytes()
        self.assertEqual(R.sha(raw), R.STOCK_SHA256)
        result = R.inspect_package(raw)
        self.assertEqual(len(result["sections"]), 14)
        self.assertEqual(result["header_crc32"], "ba098e64")
        self.assertEqual(result["image_crc32"], "e22ae63a")


if __name__ == "__main__":
    unittest.main(verbosity=2)
