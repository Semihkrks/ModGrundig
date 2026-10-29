"""Bounded V76 native mute resources; no device or firmware process executes."""
import io
import json
from pathlib import Path
import struct
import unittest
from PIL import Image
import build_native_ui_v75_tv as base
import native_ui_v76_mute as mute
from build_native_volume_patch import elf_va_offset


class MuteV76Tests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.inputs = {'08_APP'+r['path']:r['candidate'].read_bytes()
                      for r in base.verified_packaging_records()}
        cls.outputs, cls.proof = mute.apply(cls.inputs)

    def test_only_geometry_badge_and_legacy_fallback_change(self):
        changed={p for p,b in self.outputs.items() if self.inputs.get(p)!=b}
        self.assertEqual(changed,{mute.NUM,mute.BADGE,mute.LEGACY})
        self.assertEqual(self.outputs[mute.ELF],self.inputs[mute.ELF])
        self.assertEqual(self.outputs[mute.PANEL_ICON],self.inputs[mute.PANEL_ICON])
        self.assertEqual(mute.sha(self.inputs[mute.BADGE]),'b715372a955609be668bccb839466323fe00f07447147ee11fa4ad0f60d93066')

    def test_enlarged_geometry_and_safe_ancestor_bounds(self):
        raw=self.outputs[mute.NUM]
        n=lambda i:struct.unpack_from('<I',raw,56+4*i)[0]
        outer=tuple(n(i) for i in (0x5b38,0x5b39,0x5b37,0x5b36))
        x=outer[0]+n(0x4219);y=outer[1]+25+30
        w=n(0x4218);h=n(0x4217)
        self.assertEqual((x,y,w,h),mute.SCREEN_ICON)
        self.assertEqual(1920-(x+w),84)
        self.assertGreaterEqual(x,outer[0]);self.assertGreaterEqual(y,outer[1])
        self.assertLessEqual(x+w,outer[0]+158)
        self.assertLessEqual(y+h,outer[1]+25+165)
        self.assertLessEqual(outer[0]+outer[2],1920)
        self.assertLessEqual(outer[1]+outer[3],1080)

    def test_badge_and_fallback_have_modern_glyph_and_transparent_corners(self):
        for path,size in ((mute.BADGE,(64,64)),(mute.LEGACY,(85,95))):
            image=Image.open(io.BytesIO(self.outputs[path])).convert('RGBA')
            self.assertEqual(image.size,size)
            self.assertEqual(image.getpixel((0,0))[3],0)
            colors=set(image.getdata())
            self.assertTrue(any(b>r and g>r and a==255 for r,g,b,a in colors))
            self.assertTrue(any(r>240 and g>240 and b>240 and a>220 for r,g,b,a in colors))
        oldpath=base.SOURCE/mute.LEGACY
        self.assertEqual(mute.sha(oldpath.read_bytes()),mute.LEGACY_ORIGINAL_SHA)

    def test_rejects_missing_volume_gp_recovery(self):
        b=bytearray(self.inputs[mute.ELF]);off=elf_va_offset(b,0xfb8200,4)
        struct.pack_into('<I',b,off,0)
        with self.assertRaisesRegex(ValueError,'GP recovery'):
            mute.apply({**self.inputs,mute.ELF:bytes(b)})

    def test_rejects_any_old_standalone_image_state(self):
        for va,_ in mute.ICON_PATCHES:
            b=bytearray(self.inputs[mute.ELF]);off=elf_va_offset(b,va,4)
            struct.pack_into('<I',b,off,0x24050191)
            with self.assertRaisesRegex(ValueError,'2181 state'):
                mute.apply({**self.inputs,mute.ELF:bytes(b)})

    def test_numeric_mutations_outside_mute_fields_survive(self):
        b=bytearray(self.inputs[mute.NUM]);b[100]^=1
        out,_=mute.apply({**self.inputs,mute.NUM:bytes(b)})
        self.assertEqual(out[mute.NUM][100],b[100])


if __name__=='__main__':
    result=unittest.TextTestRunner(verbosity=2).run(unittest.defaultTestLoader.loadTestsFromTestCase(MuteV76Tests))
    directory=base.ROOT/'analiz/native-ui-v76/mute';directory.mkdir(parents=True,exist_ok=True)
    for p in (mute.BADGE,mute.LEGACY):
        (directory/Path(p).name).write_bytes(MuteV76Tests.outputs[p])
    (directory/'bounded-tests.json').write_text(json.dumps(dict(passed=result.wasSuccessful(),
        tests=result.testsRun,failures=len(result.failures),errors=len(result.errors),
        proof=MuteV76Tests.proof,physical_tv_tested=False),ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    raise SystemExit(not result.wasSuccessful())
