"""Focused native channel patch contracts; no device execution."""
import io
import struct
import sys
import unittest
from pathlib import Path
import native_ui_v8_channels as channel
from build_native_volume_patch import elf_va_offset, changed_offsets
from PIL import Image

ROOT=Path(__file__).resolve().parents[1]


class NativeChannelV8Tests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.num=(ROOT/'analiz/native-ui-candidate/v7/overlay/08_APP/rc/rc/bin/Num_res.bin').read_bytes()
        cls.elf=(ROOT/'analiz/native-ui-candidate/v7/overlay/08_APP/bin/dvbt_board').read_bytes()

    def test_only_exact_local_argument_words_change(self):
        num,elf,assets,meta=channel.transform(self.num,self.elf,{'inherited':b'keep'})
        self.assertIs(num,self.num)
        self.assertEqual(len(meta['code_records']),25)
        self.assertEqual(assets['inherited'],b'keep')
        allowed={elf_va_offset(self.elf,va,4)+i for va,*_ in channel.PATCHES for i in range(4)}
        self.assertTrue(set(changed_offsets(self.elf,elf)).issubset(allowed))
        self.assertEqual(len(elf),len(self.elf))
        for va,old,new,_ in channel.PATCHES:
            self.assertEqual(struct.unpack_from('<I',elf,elf_va_offset(elf,va,4))[0],new)
            self.assertEqual(old>>16,new>>16)

    def test_changed_input_and_duplicate_output_are_rejected(self):
        broken=bytearray(self.elf);off=elf_va_offset(self.elf,channel.PATCHES[0][0],4)
        broken[off]^=1
        with self.assertRaisesRegex(ValueError,'Unexpected native channel'):
            channel.transform(self.num,bytes(broken))
        with self.assertRaisesRegex(ValueError,'collision'):
            channel.transform(self.num,self.elf,channel.image_payloads())

    def test_images_remain_small_private_static_sources(self):
        assets=channel.image_payloads()
        self.assertEqual(len(assets),2)
        panel=Image.open(io.BytesIO(assets[channel.resource_relative(channel.IMAGE_RECORDS[0]['path'])]))
        band=Image.open(io.BytesIO(assets[channel.resource_relative(channel.IMAGE_RECORDS[1]['path'])]))
        self.assertEqual((panel.mode,panel.size),('RGBA',(353,138)))
        self.assertEqual((band.mode,band.size),('RGBA',(2,250)))
        self.assertEqual(panel.getpixel((0,0))[3],0)
        self.assertEqual(panel.getpixel((176,69)),(245,248,251,255))
        self.assertGreaterEqual(band.getpixel((0,0))[3],240)
        self.assertLess(panel.width*panel.height*4+band.width*band.height*4,200000)

    def test_all_replacement_arguments_execute_with_original_register_opcode(self):
        sys.path.insert(0,str(ROOT/'tools/native-volume-venv/Lib/site-packages'))
        from unicorn import Uc, UC_ARCH_MIPS, UC_MODE_MIPS32, UC_MODE_LITTLE_ENDIAN
        from unicorn.mips_const import UC_MIPS_REG_A0,UC_MIPS_REG_A1,UC_MIPS_REG_A2
        uc=Uc(UC_ARCH_MIPS,UC_MODE_MIPS32|UC_MODE_LITTLE_ENDIAN)
        uc.mem_map(0x10000000,0x1000)
        registers={4:UC_MIPS_REG_A0,5:UC_MIPS_REG_A1}
        for va,old,new,_ in channel.PATCHES:
            target=registers[(new>>16)&31]
            for word in (old,new):
                uc.reg_write(UC_MIPS_REG_A2,0x12345678)
                uc.mem_write(0x10000000,struct.pack('<I',word))
                uc.ctl_remove_cache(0x10000000,0x10000004)
                uc.emu_start(0x10000000,0x10000004,count=1)
                self.assertEqual(uc.reg_read(target),word&0xffff,hex(va))
                self.assertEqual(uc.reg_read(UC_MIPS_REG_A2),0x12345678)

    def test_scene_records_constructor_geometry_without_fake_channels(self):
        scene=channel.scene_spec(self.num)
        self.assertEqual(scene['channel_list']['panel']['rect'],[100,160,1720,770])
        self.assertEqual(scene['channel_list']['list']['rect'],[0,80,680,690])
        self.assertEqual(scene['channel_list']['detail_title']['rect'],[730,100,678,100])
        self.assertEqual(scene['program_info']['band']['rect'],[0,0,1920,250])
        self.assertFalse(scene['fake_channels_embedded'])
        self.assertEqual(scene['native_filter_count_preserved'],7)


if __name__=='__main__':unittest.main()
