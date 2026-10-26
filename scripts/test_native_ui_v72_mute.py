"""Bounded MIPS presentation tests, never a TV process or firmware update."""
import io,json,sys,types,unittest
from pathlib import Path
from unittest.mock import patch
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'scripts'))
import native_ui_v72_mute as m
from native_ui_v71_tv_pins import RECORDS
P={r:(ROOT/'analiz/native-ui-candidate/v7.1-tv/overlay'/r).read_bytes() for r,*_ in RECORDS}
O,PROOF=m.apply(P)
# Reuse existing explicit boundary harness; add proven OnCreate panel object.
# Source adaptation changes only the synthetic object inventory, no guest code.
source=(ROOT/'scripts/native_volume_state_rehost.py').read_text().replace('offsets = (0x180,','offsets = (0x1a4, 0x180,')
h=types.ModuleType('v72_bounded');h.__file__=str(ROOT/'scripts/native_volume_state_rehost.py');exec(compile(source,h.__file__,'exec'),h.__dict__)
h.SHA['v7.1-tv']=m.sha(O[m.ELF])
read=Path.read_bytes
results=[]
def run(volume,muted,mode=0,**kw):
    def injected(path):
        if path==ROOT/'analiz/native-ui-candidate/v7.1-tv/overlay'/m.ELF:return O[m.ELF]
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
            self.assertEqual(state['audio_mute_requests'],[]);results.append(case)
    def test_arc_unchanged(self):
        original_sha=h.SHA['v7.1-tv']
        for mode in (1,2,3):
            for muted in (False,True):
                for arc in (False,True):
                    actual=run(35,muted,mode,arc_muted=arc)
                    h.SHA['v7.1-tv']=m.sha(P[m.ELF])
                    before=h.run_case('v7.1-tv',35,muted,mode,arc_muted=arc)
                    h.SHA['v7.1-tv']=original_sha
                    self.assertEqual(actual['state'],before['state']);results.append(actual)
    def test_pins_and_assets(self):
        for path in P:
            bad=dict(P);bad[path]=bad[path][:-1]+bytes([bad[path][-1]^1])
            with self.assertRaises(ValueError):m.apply(bad)
        from PIL import Image
        for path,size in [(m.MUTED_BACKGROUND,(68,450)),(m.MUTED_ICON,(44,44))]:
            im=Image.open(io.BytesIO(O[path]));self.assertEqual(im.size,size);self.assertEqual(im.mode,'RGBA')
        self.assertEqual(O['08_APP/rc/rc/bin/Num_res.bin'],P['08_APP/rc/rc/bin/Num_res.bin'])
if __name__=='__main__':
    suite=unittest.defaultTestLoader.loadTestsFromTestCase(TestMute);r=unittest.TextTestRunner().run(suite)
    if r.wasSuccessful():
        out=ROOT/'analiz/native-ui-v72';out.mkdir(exist_ok=True)
        (out/'mute-native-evidence.json').write_text(json.dumps(dict(proof=PROOF,cases=results,limits=['Synthetic widgets and mocked imports; no physical TV or target process execution','Rapid transition sequence reruns bounded function with fresh synthetic frame; every image state overwritten on every refresh']),indent=2)+'\n')
        import capstone
        d=capstone.Cs(capstone.CS_ARCH_MIPS,capstone.CS_MODE_MIPS32|capstone.CS_MODE_LITTLE_ENDIAN)
        (out/'mute-block-disassembly.txt').write_text('\n'.join(f'{i.address:08x}: {i.bytes.hex()} {i.mnemonic} {i.op_str}' for i in d.disasm(m.block(),m.START))+'\n')
    sys.exit(not r.wasSuccessful())
