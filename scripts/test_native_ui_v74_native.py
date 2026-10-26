"""Bounded MIPS presentation tests, never a TV process or firmware update."""
import io,json,sys,types,unittest
from pathlib import Path
from unittest.mock import patch
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'scripts'))
import native_ui_v74_native as m
from native_ui_v73_tv_pins import RECORDS
P={r:(ROOT/'analiz/native-ui-candidate/v7.3-tv/overlay'/r).read_bytes() for r,*_ in RECORDS}
O,PROOF=m.apply(P)
# Reuse existing explicit boundary harness; add proven OnCreate panel object.
# Source adaptation changes only the synthetic object inventory, no guest code.
source=(ROOT/'scripts/native_volume_state_rehost.py').read_text()
if 'offsets = (0x1a4,' not in source:source=source.replace('offsets = (0x180,','offsets = (0x1a4, 0x180,')
source=source.replace("return dict(variant=variant,","state['fill_colors']=[r32(next(a for a,o in objects.items() if o==0x1bc)+f) for f in (0x2a4,0x2a8,0x2ac,0x2b0)]\n    return dict(variant=variant,")
source=source.replace('uc.reg_write(UC_MIPS_REG_V0, callback(name, args))', '''uc.reg_write(UC_MIPS_REG_V0, callback(name, args))
            if globals().get('ABI_POISON',False) and 0xfb8200 <= uc.reg_read(UC_MIPS_REG_RA) < 0xfb8358:
                for reg in (UC_MIPS_REG_V1,UC_MIPS_REG_A0,UC_MIPS_REG_A1,UC_MIPS_REG_A2,UC_MIPS_REG_A3,UC_MIPS_REG_T0,UC_MIPS_REG_T1,UC_MIPS_REG_T2,UC_MIPS_REG_T3,UC_MIPS_REG_T4,UC_MIPS_REG_T5,UC_MIPS_REG_T6,UC_MIPS_REG_T7,UC_MIPS_REG_T8,UC_MIPS_REG_T9,UC_MIPS_REG_GP):
                    uc.reg_write(reg,0xbad00000+reg*4)''')
h=types.ModuleType('v74_bounded');h.__file__=str(ROOT/'scripts/native_volume_state_rehost.py');exec(compile(source,h.__file__,'exec'),h.__dict__)
h.SHA['v7.1-tv']=m.sha(O[m.ELF]);h.NUM_SHA['v7.1-tv']=m.sha(P['08_APP/rc/rc/bin/Num_res.bin'])
read=Path.read_bytes
results=[]
def run(volume,muted,mode=0,**kw):
    def injected(path):
        if path==ROOT/'analiz/native-ui-candidate/v7.1-tv/overlay'/m.ELF:return O[m.ELF]
        if path==ROOT/'analiz/native-ui-candidate/v7.1-tv/overlay/08_APP/rc/rc/bin/Num_res.bin':return P['08_APP/rc/rc/bin/Num_res.bin']
        return read(path)
    with patch.object(Path,'read_bytes',injected):return h.run_case('v7.1-tv',volume,muted,mode,**kw)
class TestMute(unittest.TestCase):
    def test_states_and_transitions(self):
        # Exhaustive valid volume range and explicit rapid-toggle sequence.
        for volume,muted in [(v,b) for v in range(101) for b in (False,True)]+[(35,False),(35,True),(0,False),(1,False),(1,True),(100,False)]:
            case=run(volume,muted);state=case['state'];effective=muted or volume==0
            for widget,rid in [(0x1a8,680 if effective else 682),(0x1a4,2180 if effective else 674)]:
                self.assertEqual([x for x in state['image_sets'] if x['object_offset']==widget],[dict(object_offset=widget,field_offset=f,resource_id=rid) for f in (0xb8,0xcc,0xe0,0xf4)])
                invalid=[x for x in case['boundaries'] if x['boundary']=='Invalidate']
                self.assertTrue(any(x['args'][0]==h.FRAME+0x1000+list((0x1a4,0x180,0x184,0x188,0x1a8,0x1ac,0x1b0,0x1b4,0x1b8,0x1bc)).index(widget)*0x1000 for x in invalid))
            self.assertEqual(state['audio_mute_requests'],[]);self.assertEqual(state['fill_colors'],[m.MUTED_COLOR if effective else m.NORMAL_COLOR]*4);results.append(case)
    def test_arc_unchanged(self):
        for mode in (1,2,3):
            for muted in (False,True):
                for arc in (False,True):
                    actual=run(35,muted,mode,arc_muted=arc)
                    def prior(path):
                        if path==ROOT/'analiz/native-ui-candidate/v7.1-tv/overlay'/m.ELF:return P[m.ELF]
                        if path==ROOT/'analiz/native-ui-candidate/v7.1-tv/overlay/08_APP/rc/rc/bin/Num_res.bin':return P['08_APP/rc/rc/bin/Num_res.bin']
                        return read(path)
                    with patch.object(Path,'read_bytes',prior),patch.dict(h.SHA,{'v7.1-tv':m.sha(P[m.ELF])}):before=h.run_case('v7.1-tv',35,muted,mode,arc_muted=arc)
                    self.assertEqual(actual['state'],before['state']);results.append(actual)
    def test_abi_caller_saved_poison(self):
        for volume in (0,1,35,100,255):
            for muted in (False,True):
                before=run(volume,muted)
                h.ABI_POISON=True
                try:after=run(volume,muted)
                finally:h.ABI_POISON=False
                self.assertEqual(after['state'],before['state']);results.append(after)
    def test_pins_and_assets(self):
        for path in P:
            bad=dict(P);bad[path]=bad[path][:-1]+bytes([bad[path][-1]^1])
            with self.assertRaises(ValueError):m.apply(bad)
        self.assertEqual({p for p in P if O[p]!=P[p]},{m.ELF})
if __name__=='__main__':
    suite=unittest.defaultTestLoader.loadTestsFromTestCase(TestMute);r=unittest.TextTestRunner().run(suite)
    if r.wasSuccessful():
        out=ROOT/'analiz/native-ui-v74';out.mkdir(exist_ok=True)
        (out/'progress-native-evidence.json').write_text(json.dumps(dict(proof=PROOF,cases=results,limits=['Synthetic widgets and mocked imports; no physical TV or target process execution','Rapid transition sequence reruns bounded function with fresh synthetic frame; every image state overwritten on every refresh']),indent=2)+'\n')
        import capstone
        d=capstone.Cs(capstone.CS_ARCH_MIPS,capstone.CS_MODE_MIPS32|capstone.CS_MODE_LITTLE_ENDIAN)
        (out/'progress-block-disassembly.txt').write_text('\n'.join(f'{i.address:08x}: {i.bytes.hex()} {i.mnemonic} {i.op_str}' for i in d.disasm(m.block(),m.START))+'\n')
    sys.exit(not r.wasSuccessful())
