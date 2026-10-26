"""Regression reproduces the V73 GP fault and stresses the V71-based repair."""
import io
import json
from pathlib import Path
import sys
import types
import unittest
from unittest.mock import patch
sys.path.insert(0, str(Path(__file__).resolve().parent))
import build_native_ui_v74_tv as build
import native_ui_v74_safe as safe
from native_volume_state_rehost import ROOT
from PIL import Image

source = (ROOT / 'scripts/native_volume_state_rehost.py').read_text(encoding='utf-8')
needle = 'uc.reg_write(UC_MIPS_REG_V0, callback(name, args))'
assert source.count(needle) == 1
source = source.replace(needle, needle + '''
            if globals().get('POISON_ALL',False):
                for reg in (UC_MIPS_REG_V1,UC_MIPS_REG_A0,UC_MIPS_REG_A1,UC_MIPS_REG_A2,UC_MIPS_REG_A3,UC_MIPS_REG_T0,UC_MIPS_REG_T1,UC_MIPS_REG_T2,UC_MIPS_REG_T3,UC_MIPS_REG_T4,UC_MIPS_REG_T5,UC_MIPS_REG_T6,UC_MIPS_REG_T7,UC_MIPS_REG_T8,UC_MIPS_REG_T9,UC_MIPS_REG_GP):
                    uc.reg_write(reg,0xbad00000+reg*4)
            elif name=='VirtualMoveRect' and globals().get('POISON_MOVE',False):
                uc.reg_write(UC_MIPS_REG_GP,0xdead8000)''')
needle = 'return dict(variant=variant,'
assert source.count(needle) == 1
source = source.replace(needle, "state['verified_fill']=[r32(next(a for a,o in objects.items() if o==0x1bc)+f) for f in (0x2a4,0x2a8,0x2ac,0x2b0)]\n    " + needle)
h = types.ModuleType('safe_gp_harness')
h.__file__ = str(ROOT / 'scripts/native_volume_state_rehost.py')
exec(compile(source, h.__file__, 'exec'), h.__dict__)

class SafeV74Tests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.rows = build.verified_packaging_records()
        cls.payloads = {'08_APP' + r['path']: r['candidate'].read_bytes() for r in cls.rows}
        h.SHA['v7.4-tv'] = safe.sha(cls.payloads[safe.ELF])
        h.NUM_SHA['v7.4-tv'] = safe.sha(cls.payloads[safe.NUM])
        cls.runs = []

    def tearDown(self):
        h.POISON_ALL = h.POISON_MOVE = False

    def test_old_gp_fault_reproduces_and_v71_does_not_fail(self):
        h.POISON_MOVE = True
        self.assertTrue(h.run_case('v7.1-tv',35,False)['native']['returned'])
        with self.assertRaises(Exception) as error:
            h.run_case('v7.3-tv',35,False)
        self.assertIn('Invalid memory read', str(error.exception))
        self.assertTrue(h.run_case('v7.4-tv',35,False)['native']['returned'])

    def test_exhaustive_zero_mute_color_states_after_virtual_gp_clobber(self):
        h.POISON_MOVE = True
        for volume in range(101):
            for mute in (False,True):
                case = h.run_case('v7.4-tv',volume,mute)
                s = case['state']; muted = mute or volume == 0
                self.assertEqual(s['verified_fill'], [safe.MUTED_COLOR if muted else safe.NORMAL_COLOR] * 4)
                for offset, expected in ((0x1a8,680 if muted else 682),(0x1a4,2180 if muted else 674)):
                    self.assertEqual([x['resource_id'] for x in s['image_sets'] if x['object_offset']==offset], [expected]*4)
                self.assertEqual(s['audio_mute_requests'], [])
                self.runs.append(dict(volume=volume,mute=mute,fill=s['verified_fill'],returned=True))

    def test_every_import_may_clobber_caller_saved_registers(self):
        h.POISON_ALL = True
        for volume in (0,1,35,100,255):
            for mute in (False,True):
                case=h.run_case('v7.4-tv',volume,mute)
                self.assertTrue(case['native']['returned'])
                self.assertEqual(case['state']['verified_fill'],[safe.MUTED_COLOR if mute or volume==0 else safe.NORMAL_COLOR]*4)

    def test_arc_service_outputs_preserved(self):
        for mode in (1,2,3):
            for muted in (False,True):
                for arc in (False,True):
                    old=h.run_case('v7.1-tv',35,muted,mode,arc_muted=arc)
                    new=h.run_case('v7.4-tv',35,muted,mode,arc_muted=arc)
                    self.assertEqual(old['state'],new['state'])

    def test_badge_and_ancestors_fit_safe_screen_bounds(self):
        nums=self.payloads[safe.NUM]
        n=lambda rid:int.from_bytes(nums[56+4*rid:60+4*rid],'little')
        outer=[n(i) for i in (0x5b38,0x5b39,0x5b37,0x5b36)]
        self.assertEqual(outer,[1728,19,160,230])
        self.assertLessEqual(outer[0]+outer[2],1920)
        self.assertLessEqual(outer[1]+outer[3],1080)
        self.assertEqual(n(0x4219)+n(0x4218),108)
        self.assertLessEqual(108,n(0x4220))
        image=Image.open(io.BytesIO(self.payloads[safe.BADGE])).convert('RGBA')
        self.assertEqual(image.size,(52,52));self.assertEqual(image.getpixel((0,0))[3],0)

    def test_manifest_reconstruction_matches_code_pins(self):
        self.assertEqual(build.verified_records(),self.rows)
        self.assertEqual(len(self.rows),14)

if __name__=='__main__':
    result=unittest.TextTestRunner(verbosity=2).run(unittest.defaultTestLoader.loadTestsFromTestCase(SafeV74Tests))
    out=ROOT/'analiz/native-ui-v74';out.mkdir(exist_ok=True)
    (out/'safe-gp-regression.json').write_text(json.dumps(dict(passed=result.wasSuccessful(),tests=result.testsRun,
        failures=len(result.failures),errors=len(result.errors),cases=SafeV74Tests.runs,
        defect='V73 loses caller GP after VirtualMoveRect; V71 restores it',
        physical_tv_tested=False),indent=2)+'\n',encoding='utf-8')
    sys.exit(not result.wasSuccessful())
