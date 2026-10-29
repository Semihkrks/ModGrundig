"""Installed ELF hooks plus helper ABI, with explicit service/UI boundaries."""
import json
import struct
import unittest
from pathlib import Path
from test_native_ui_v77_name import Harness, FRAME, DIGIT, LABEL, STACK, STOP, m
import native_ui_v77_name as name
import build_native_ui_v74_tv as previous
import build_native_ui_v77_tv as build
from build_native_volume_patch import elf_va_offset
from native_ui_v77_elf import FILE_OFFSET

class InstalledHarness(Harness):
    def hook(self, uc, address, size, data):
        if address == getattr(self, 'tail_stop', -1):
            self.done = True
            uc.emu_stop()
            return
        if any(a <= address < b for a, b in getattr(self, 'original_ranges', [])):
            self.steps += 1
            if self.steps > 3000:
                raise AssertionError('Installed hook watchdog')
            return
        return super().hook(uc, address, size, data)


class InstalledV77Tests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.rows = build.verified_packaging_records()
        cls.new = {r['path']: r['candidate'].read_bytes() for r in cls.rows}
        cls.old = {r['path']: r['candidate'].read_bytes() for r in previous.verified_packaging_records()}
        cls.elf = cls.new['/bin/dvbt_board']
        cls.evidence = []

    def harness(self, **kw):
        h = InstalledHarness(**kw)
        h.uc.mem_write(name.CREATE, self.elf[FILE_OFFSET + 0x100:FILE_OFFSET + 0x100 + len(name.code_create())])
        h.uc.mem_write(name.UPDATE, self.elf[FILE_OFFSET + 0x800:FILE_OFFSET + 0x800 + len(name.code_update())])
        h.steps = 0
        h.done = False
        return h

    def test_oncreate_real_tail_preserves_return_stack_and_restores_gp(self):
        h = self.harness(widget=False)
        start, end = 0x8968ac, 0x8968d8
        if not any(a <= 0x896000 <= b for a,b,_ in h.uc.mem_regions()): h.uc.mem_map(0x896000, 0x1000)
        off = elf_va_offset(self.elf, start, end - start)
        h.uc.mem_write(start, self.elf[off:off + end - start])
        h.original_ranges = [(start, end)]
        for addr, value in ((STACK + 0x60, FRAME), (STACK + 0x5c, STOP),
                            (STACK + 0x58, 0xabc0001e), (STACK + 0x54, 0xabc00012),
                            (STACK + 0x50, 0xabc00011), (STACK + 0x4c, 0xabc00010)):
            h.w32(addr, value)
        for reg, value in ((m.UC_MIPS_REG_SP, STACK), (m.UC_MIPS_REG_FP, STACK),
                           (m.UC_MIPS_REG_GP, 0xdead8000), (m.UC_MIPS_REG_A0, 0xbad00000)):
            h.uc.reg_write(reg, value)
        h.uc.emu_start(start, STOP + 4, count=3001)
        self.assertTrue(h.done)
        self.assertEqual(h.registry[3], LABEL)
        self.assertEqual(h.uc.reg_read(m.UC_MIPS_REG_V0), 0)
        self.assertEqual(h.uc.reg_read(m.UC_MIPS_REG_GP), name.APP_GP)
        self.assertEqual(h.uc.reg_read(m.UC_MIPS_REG_SP), STACK + 0x60)
        self.assertEqual(h.uc.reg_read(m.UC_MIPS_REG_FP), 0xabc0001e)
        self.evidence.append(dict(case='installed OnCreate tail', gp_restored=True, return_zero=True))

    def test_both_installed_digit_sites_keep_01_and_set_target_name(self):
        for start in (0x8957c8, 0x895a68):
            h = self.harness(name='TRT 1', digits='01', typed=1, count=2)
            h.uc.mem_map(start & ~4095, 0x1000)
            off = elf_va_offset(self.elf, start, 16)
            h.uc.mem_write(start, self.elf[off:off + 16])
            h.original_ranges = [(start, start + 16)]
            h.tail_stop = start + 16
            h.w32(STACK + 0x10, name.APP_GP)
            for reg, value in ((m.UC_MIPS_REG_A0, DIGIT), (m.UC_MIPS_REG_A1, 0x10010000),
                               (m.UC_MIPS_REG_GP, name.APP_GP), (m.UC_MIPS_REG_SP, STACK),
                               (m.UC_MIPS_REG_FP, STACK)):
                h.uc.reg_write(reg, value)
            h.uc.emu_start(start, h.tail_stop + 4, count=3001)
            self.assertTrue(h.done)
            self.assertEqual(h.texts[DIGIT], '01')
            self.assertEqual(h.texts[LABEL], 'TRT 1')
            self.assertEqual(h.uc.reg_read(m.UC_MIPS_REG_V0), 0x12345678)
            self.assertEqual(h.uc.reg_read(m.UC_MIPS_REG_GP), name.APP_GP)
            self.assertEqual(len(h.live), 1)
            self.evidence.append(dict(case=hex(start), digits='01', selected_name='TRT 1',
                                      mocked_device_database=True, live_temporary_strings=0))

    def test_only_elf_changes_and_original_tuning_volume_resources_preserved(self):
        self.assertEqual(set(self.new)-set(self.old), {'/rc/ARimages/Grundig/volume/mute_button_grundig.png'})
        self.assertEqual({p for p in self.old if self.old[p] != self.new[p]}, {'/bin/dvbt_board','/rc/rc/bin/Num_res.bin','/rc/ARimages/Grundig/modern/mute_badge.png'})
        a, b = self.old['/bin/dvbt_board'], self.elf
        allowed = set(range(28, 32)) | set(range(44, 46))
        for va in (0x8968ac,0x8968b0,0x8957c8,0x8957cc,0x895a68,0x895a6c,0xfb93d4,0xfb7b38,0xfb7b3c,0xfb7b4c,0xfb7b94,0xfb7b98):
            at = elf_va_offset(a, va, 4)
            allowed.update(range(at, at + 4))
        self.assertTrue(all(i in allowed for i, (x, y) in enumerate(zip(a, b)) if x != y))
        self.assertEqual(b[FILE_OFFSET + 0x100:FILE_OFFSET + 0x100 + len(name.code_create())], name.code_create())
        self.assertEqual(b[FILE_OFFSET + 0x800:FILE_OFFSET + 0x800 + len(name.code_update())], name.code_update())

    def test_full_manifest_reconstruction_matches_fixed_code_pins(self):
        self.assertEqual(build.verified_records(), self.rows)


if __name__ == '__main__':
    result = unittest.TextTestRunner(verbosity=2).run(unittest.defaultTestLoader.loadTestsFromTestCase(InstalledV77Tests))
    out = build.ROOT / 'analiz/native-ui-v77/installed-hooks.json'
    out.write_text(json.dumps(dict(passed=result.wasSuccessful(), tests=result.testsRun,
        cases=InstalledV77Tests.evidence, full_firmware_executed=False, tv_tested=False), indent=2) + '\n', encoding='utf-8')
    raise SystemExit(not result.wasSuccessful())
