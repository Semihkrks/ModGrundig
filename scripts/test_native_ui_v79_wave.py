"""Bounded actual V7.9 Refresh/leaf instruction tests; hardware never runs."""
from __future__ import annotations

import json
from pathlib import Path
import struct
import unittest

import native_ui_v79_wave as patch
from build_native_volume_patch import elf_va_offset
from test_native_ui_v77_mute import Harness as V77Harness, FRAME, STOP, STACK, m
from unicorn import UC_HOOK_MEM_WRITE

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / 'analiz/native-ui-v79/wave'
BASE = ROOT / 'analiz/native-ui-candidate/v7.8-tv/overlay'
NUM = '08_APP/rc/rc/bin/Num_res.bin'


class Harness(V77Harness):
    def __init__(self, raw, nums, **kwargs):
        super().__init__(raw, nums, **kwargs)
        at = elf_va_offset(raw, patch.HELPER, len(patch.code()))
        self.wave_installed = raw[at:at+len(patch.code())] == patch.code()

    def hook(self, uc, address, size, data):
        if self.wave_installed and patch.HELPER <= address < patch.HELPER+len(patch.code()):
            self.steps += 1
            if self.steps > 20000:
                raise AssertionError('Instruction watchdog')
            self.visited.add(address)
            return
        super().hook(uc, address, size, data)


class NativeWaveV79Tests(unittest.TestCase):
    results = []

    @classmethod
    def setUpClass(cls):
        cls.original = (BASE / patch.ELF).read_bytes()
        cls.nums = (BASE / NUM).read_bytes()
        cls.raw, cls.proof = patch.apply(cls.original)

    def refresh(self, raw=None, **kwargs):
        h = Harness(raw or self.raw, self.nums, **kwargs)
        saved = {getattr(m, 'UC_MIPS_REG_S'+str(i)): 0xcafe0000+i for i in range(8)}
        for register, value in saved.items():
            h.u.reg_write(register, value)
        r = h.run(0xfb7d18)
        for register, value in saved.items():
            self.assertEqual(h.u.reg_read(register), value)
        self.assertEqual(h.u.reg_read(m.UC_MIPS_REG_GP), patch_context_gp())
        self.assertEqual(h.u.reg_read(m.UC_MIPS_REG_SP), STACK)
        self.assertEqual(h.u.reg_read(m.UC_MIPS_REG_FP), 0xabcd001e)
        r['abi_preserved'] = ['s0..s7', 'fp', 'sp', 'gp']
        return r

    def test_exact_input_and_non_idempotent_patch_reject_drift(self):
        for bad in (b'', self.raw, bytes([self.original[0]^1])+self.original[1:]):
            with self.assertRaisesRegex(ValueError, 'Exact V7.7/V7.8 ELF'):
                patch.apply(bad)

    def test_only_two_hook_words_and_zero_padding_change(self):
        self.assertEqual(len(self.original), len(self.raw))
        allowed = set()
        for row in self.proof['allowlist']:
            allowed.update(range(row['offset'], row['offset']+row['size']))
        changed = {i for i, (a,b) in enumerate(zip(self.original, self.raw)) if a != b}
        self.assertTrue(changed)
        self.assertTrue(changed <= allowed)
        at = elf_va_offset(self.original, patch.HELPER, patch.HELPER_LIMIT-patch.HELPER)
        self.assertEqual(self.original[at:at+patch.HELPER_LIMIT-patch.HELPER],
                         bytes(patch.HELPER_LIMIT-patch.HELPER))
        self.assertEqual(self.proof['output_sha256'], patch.sha(self.raw))
        self.assertEqual(self.raw[28:52], self.original[28:52])
        self.assertEqual(self.raw[0xd62000:], self.original[0xd62000:])

    def test_local_thresholds_zero_and_mute_keep_existing_bar(self):
        for volume in (0, 1, 20, 21, 60, 61, 100, 101, 255):
            for muted in (False, True):
                with self.subTest(volume=volume, muted=muted):
                    r = self.refresh(volume=volume, muted=muted, mode=0)
                    self.results.append(r)
                    gray = muted or volume == 0
                    expected = 680 if gray else 2182 if volume <= 20 else 682 if volume <= 60 else 2183
                    icons = [x for x in r['images'] if x['widget'] == 0x1a8]
                    self.assertEqual([x['id'] for x in icons], [expected]*4)
                    self.assertEqual([x['field'] for x in icons], [0xb8, 0xcc, 0xe0, 0xf4])
                    self.assertEqual(r['fill_colors'], [0xff898989 if gray else 0xff0082d4]*4)
                    self.assertEqual(r['volume'], volume)  # Presentation clamp never changes audio state.
                    self.assertEqual(r['muted'], muted)
                    self.assertEqual(r['mode'], 0)
                    self.assertFalse(any(x[0] in ('audio_set_mute', 'SetMuteStatus') for x in r['actions']))
                    # KillTimer only consumes a0/a1; poisoned a2/a3 are not args.
                    self.assertEqual(r['timers'][0][:2], ['KillTimer', 0])
                    self.assertEqual(r['timers'][1], ['SetTimer', 3000, 0, 1])
                    self.assertIn(hex(patch.HELPER), r['executed_addresses'])

    def test_arc_and_nonlocal_modes_match_exact_v78_outputs(self):
        for mode in (1, 2, 3):
            for volume in (0, 20, 61, 100):
                for muted in (False, True):
                    for arc in (False, True):
                        with self.subTest(mode=mode, volume=volume, muted=muted, arc=arc):
                            kwargs = dict(mode=mode, volume=volume, muted=muted, arc=arc)
                            before = self.refresh(self.original, **kwargs)
                            after = self.refresh(**kwargs)
                            self.assertEqual(after, before)
                            self.assertNotIn(hex(patch.HELPER), after['executed_addresses'])
                            self.results.append(after)

    def test_mute_unmute_and_volume_key_transitions_use_actual_refresh(self):
        for volume in (0, 20, 60, 100):
            h = Harness(self.raw, self.nums, volume=volume)
            muted = h.run_key()
            self.assertTrue(muted['muted'])
            self.assertEqual([x['id'] for x in muted['images'] if x['widget'] == 0x1a8], [680]*4)
            unmuted = h.run_key()
            self.assertFalse(unmuted['muted'])
            self.assertEqual(unmuted['mode'], 0)
            self.results.extend([muted, unmuted])
        for volume, key, expected_volume, expected_icon in (
                (20, 0xf04c, 21, 682), (21, 0xf04d, 20, 2182),
                (60, 0xf04c, 61, 2183), (61, 0xf04d, 60, 682)):
            h = Harness(self.raw, self.nums, volume=volume)
            r = h.run_key(key)
            self.assertEqual(r['volume'], expected_volume)
            self.assertEqual([x['id'] for x in r['images'] if x['widget'] == 0x1a8], [expected_icon]*4)
            self.results.append(r)

    def test_leaf_all_gpr_gp_sp_ra_preserved_except_v1_and_no_memory_writes(self):
        names = ['ZERO', 'AT', 'V0', 'V1'] + ['A'+str(i) for i in range(4)]
        names += ['T'+str(i) for i in range(10)] + ['S'+str(i) for i in range(8)]
        names += ['K0', 'K1', 'GP', 'SP', 'FP', 'RA', 'HI', 'LO']
        for effective, audible, expected in ((0,0,680),(1,1,2182),(20,1,2182),
                (21,1,682),(60,1,682),(61,1,2183),(100,1,2183),(255,1,2183)):
            h = Harness(self.raw, self.nums)
            for i, name in enumerate(names):
                if name != 'ZERO':
                    h.u.reg_write(getattr(m, 'UC_MIPS_REG_'+name), 0xabc00000+i)
            for name, value in [('V0', effective), ('S0', audible), ('SP', STACK), ('RA', STOP)]:
                h.u.reg_write(getattr(m, 'UC_MIPS_REG_'+name), value)
            before = {name: h.u.reg_read(getattr(m, 'UC_MIPS_REG_'+name)) for name in names}
            writes = []
            h.u.hook_add(UC_HOOK_MEM_WRITE, lambda *args: writes.append(args[2:5]))
            h.steps = 0
            h.done = False
            h.u.emu_start(patch.HELPER, STOP+4, count=100)
            self.assertTrue(h.done)
            self.assertEqual(h.u.reg_read(m.UC_MIPS_REG_V1), expected)
            self.assertEqual(writes, [])
            self.assertEqual(h.calls, [])
            for name, value in before.items():
                if name != 'V1':
                    self.assertEqual(h.u.reg_read(getattr(m, 'UC_MIPS_REG_'+name)), value, name)

    def test_final_packaged_overlay_uses_same_patch_and_shared_refresh_harness(self):
        from native_volume_state_rehost import run_case
        final = ROOT / 'analiz/native-ui-candidate/v7.9-tv/overlay' / patch.ELF
        self.assertEqual(final.read_bytes(), self.raw)
        for volume, expected in ((0,680),(1,2182),(20,2182),(21,682),(60,682),(61,2183),(100,2183)):
            r = run_case('v7.9-tv', volume=volume)
            self.assertEqual([x['resource_id'] for x in r['state']['image_sets']
                              if x['object_offset'] == 0x1a8], [expected]*4)
            self.assertTrue(r['native']['returned'])
            self.results.append(r)


def patch_context_gp():
    from native_ui_v75_name import APP_GP
    return APP_GP


def main():
    result = unittest.TextTestRunner(verbosity=2).run(
        unittest.defaultTestLoader.loadTestsFromTestCase(NativeWaveV79Tests))
    OUT.mkdir(parents=True, exist_ok=True)
    (OUT/'bounded-tests.json').write_text(json.dumps(dict(
        passed=result.wasSuccessful(), tests=result.testsRun,
        failures=len(result.failures), errors=len(result.errors),
        cases=NativeWaveV79Tests.results,
        scope='Actual patched Refresh and OnKey instructions plus isolated leaf; all sound/UI/device dependencies modeled',
        physical_tv_tested=False), ensure_ascii=False, indent=2)+'\n', encoding='utf-8')
    if hasattr(NativeWaveV79Tests, 'proof'):
        (OUT/'helper-proof.json').write_text(json.dumps(NativeWaveV79Tests.proof,
            ensure_ascii=False, indent=2)+'\n', encoding='utf-8')
    raise SystemExit(not result.wasSuccessful())


if __name__ == '__main__':
    main()
