import io
import struct
import unittest
from pathlib import Path
from PIL import Image
import native_ui_v8_settings as patch
from build_native_volume_patch import elf_va_offset

class SettingsPatchTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        root=Path(__file__).resolve().parents[1]/'analiz/native-ui-candidate/v7/overlay/08_APP'
        cls.num=(root/'rc/rc/bin/Num_res.bin').read_bytes();cls.elf=(root/'bin/dvbt_board').read_bytes()

    def test_only_thirteen_local_visual_arguments_change(self):
        num,elf,assets,proof=patch.transform(self.num,self.elf,{})
        self.assertEqual(num,self.num);self.assertEqual(len(proof['code_records']),13)
        allowed={r['file_offset']+i for r in proof['code_records'] for i in range(4)}
        self.assertTrue(all(i in allowed for i,(a,b) in enumerate(zip(self.elf,elf)) if a!=b))
        self.assertEqual(len(elf),len(self.elf))
        for r in proof['code_records']:
            self.assertEqual(struct.unpack_from('<I',elf,r['file_offset'])[0],int(r['new_word'],16))

    def test_private_images_preserve_original_dimensions_and_white_contrast(self):
        _,_,assets,proof=patch.transform(self.num,self.elf,{})
        self.assertEqual([r['id'] for r in proof['image_records']],[2224,2225])
        for name,size in [('v8_settings_focus.png',(1354,90)),('v8_settings_header.png',(1378,49))]:
            image=Image.open(io.BytesIO(assets[patch.BASE+name]))
            self.assertEqual(image.size,size);self.assertEqual(image.mode,'RGBA')
            self.assertEqual(image.getpixel((0,0))[3],0)
        rgb=(25,107,157)
        def linear(v):
            v=v/255;return v/12.92 if v<=.04045 else ((v+.055)/1.055)**2.4
        lum=sum(w*linear(v) for w,v in zip((.2126,.7152,.0722),rgb))
        self.assertGreater(1.05/(lum+.05),4.5)

    def test_modified_source_argument_or_resource_collision_is_rejected(self):
        raw=bytearray(self.elf);off=elf_va_offset(raw,patch.FOCUS_VAS[0],4);raw[off]^=1
        with self.assertRaises(ValueError):patch.transform(self.num,bytes(raw),{})
        with self.assertRaises(ValueError):patch.transform(self.num,self.elf,{patch.BASE+'v8_settings_focus.png':b'wrong'})

if __name__=='__main__':unittest.main()
