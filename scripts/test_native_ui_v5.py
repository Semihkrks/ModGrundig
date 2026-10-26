"""Offline V5 geometry, instruction, resource, and immutable-output checks."""
import io
import json
from pathlib import Path
import struct
import sys
import unittest
from unittest.mock import patch

from PIL import Image
import build_native_ui_v5 as v5

sys.path.insert(0,str(v5.ROOT/'tools/native-volume-venv/Lib/site-packages'))


def paths(raw):
    count=struct.unpack_from('<I',raw,28)[0]
    result=[]
    cursor=56
    for _ in range(count):
        size=struct.unpack_from('<I',raw,cursor)[0]
        result.append(raw[cursor:cursor+4+size])
        cursor+=4+size
    if cursor!=len(raw):raise ValueError('Image table is not fully consumed')
    return result


class NativeV5Tests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.num=(v5.volume.SOURCE/v5.volume.NUM_REL).read_bytes()
        cls.elf=(v5.volume.SOURCE/v5.volume.ELF_REL).read_bytes()
        cls.prior_num,cls.prior_elf,_=v5.v4.construct(cls.num,cls.elf)
        cls.new_num,cls.new_elf,cls.proof=v5.construct(cls.num,cls.elf)
        cls.manifest=json.loads((v5.OUT/'manifest.json').read_text())

    def test_exact_fourteen_local_instruction_changes(self):
        expected=[(va,0x240204af,0x240204ae) for va in v5.v4.FONT_VAS]
        expected += [(va,0x240204af,0x240204b0) for va in v5.NUMERIC_FONT_VAS]
        expected += [(va,0x240501f1,0x24050000|2179) for va in v5.NUMERIC_IMAGE_VAS]
        expected += [(0x896100,0x2404005e,0x24040001),(0x89610c,0,0xa204003a)]
        self.assertEqual(len(self.proof['code_records']),14)
        allowed=set()
        for va,old,new in expected:
            off=v5.volume.elf_va_offset(self.elf,va,4)
            self.assertEqual(struct.unpack_from('<I',self.prior_elf,off)[0],old)
            self.assertEqual(struct.unpack_from('<I',self.new_elf,off)[0],new)
            allowed.update(range(off,off+4))
        v5.volume.verify_allowlist(self.prior_elf,self.new_elf,allowed)
        self.assertEqual(v5.sha(self.new_elf),'f48239c5b3ac82405edd42417518f4f22098a8771218ae87460bee8464f0c5a2')
        # Dark volume color instructions from v4 are preserved.
        for va in v5.v4.COLOR_VAS:
            self.assertEqual(struct.unpack_from('<I',self.new_elf,v5.volume.elf_va_offset(self.elf,va,4))[0],0x24040000)

    def test_compact_geometry_and_child_containment(self):
        n=lambda rid:struct.unpack_from('<I',self.new_num,56+4*rid)[0]
        self.assertEqual((n(0x5a40),n(0x5a3f)),(68,490))
        self.assertEqual((n(0x5a43),n(0x5a3e)),(68,450))
        self.assertEqual((n(0x5a68),n(0x5a69),n(0x5a67),n(0x5a66)),(13,394,42,42))
        self.assertEqual((n(0x5a6c),n(0x5a6d),n(0x5a6b),n(0x5a6a)),(31,86,6,276))
        self.assertEqual(n(0x5a77),68)
        self.assertEqual(n(0x3215),36)
        self.assertLessEqual(n(0x5a44)+n(0x5a43),n(0x5a40))
        self.assertLessEqual(n(0x5a45)+n(0x5a3e),n(0x5a3f))
        for x,y,w,h in ((0x5a68,0x5a69,0x5a67,0x5a66),(0x5a78,0x5a79,0x5a77,0x5a76),(0x5a6c,0x5a6d,0x5a6b,0x5a6a)):
            self.assertLessEqual(n(x)+n(w),68)
            self.assertLessEqual(n(y)+n(h),450)
        v5.volume.verify_allowlist(self.prior_num,self.new_num,{56+4*rid+i for rid,_,_ in v5.NUM_PATCHES for i in range(4)})

    def test_image_append_keeps_every_existing_resource_id(self):
        original=(v5.volume.SOURCE/v5.IMAGE_REL).read_bytes()
        appended=v5.append_image_table(original)
        before,after=paths(original),paths(appended)
        self.assertEqual(len(before),2179)
        self.assertEqual(len(after),2180)
        self.assertEqual(after[:-1],before)
        self.assertEqual(after[-1][4:],v5.CARD_RESOURCE.encode()+b'\0')
        self.assertEqual(struct.unpack_from('<I',appended,4)[0],len(appended))
        self.assertEqual(struct.unpack_from('<I',appended,16)[0],2180*4)
        self.assertEqual(struct.unpack_from('<I',appended,28)[0],2180)
        for word in set(range(14))-{1,4,7}:
            self.assertEqual(appended[word*4:word*4+4],original[word*4:word*4+4])
        self.assertEqual(appended[56:len(original)],original[56:])
        with self.assertRaisesRegex(ValueError,'Pinned'):v5.append_image_table(original[:-1]+b'x')

    def test_card_rounding_alpha_and_existing_fonts(self):
        raw=v5.card_png()
        self.assertEqual(v5.sha(raw),'ba5688c60a80d691de5a1032c5ec7b36f3cf07657f8b9ca5fc984c9da4184ba9')
        with Image.open(io.BytesIO(raw)) as card:
            self.assertEqual(card.size,(310,112))
            self.assertEqual(card.mode,'RGBA')
            self.assertEqual(card.getpixel((0,0))[3],0)
            self.assertEqual(card.getpixel((155,56)),(245,245,245,255))
            self.assertTrue(any(0<a<255 for a in card.getchannel('A').get_flattened_data()))
        metrics=v5.font_metrics()
        self.assertEqual(metrics['0x4ae']['size'],36)
        self.assertLess(metrics['0x4ae']['measured_widths']['100'],68)
        self.assertEqual(metrics['0x4b0']['size'],48)
        self.assertLess(metrics['0x4b0']['measured_widths']['9999'],254)

    def test_overlay_reconstruction_preserves_icons_and_prior_outputs(self):
        rows=v5.verified_records()
        self.assertEqual(len(rows),24)
        for rid,relative in v5.v4.ICON_PATHS.items():
            self.assertEqual(v5.sha((v5.OUT/'overlay'/relative).read_bytes()),v5.v4.ICON_SHAS[rid])
        changes=set()
        for row in rows:
            relative='08_APP'+row['path']
            prior=v5.v4.OUT/'overlay'/relative
            if not prior.exists() or prior.read_bytes()!=row['candidate'].read_bytes():changes.add(relative)
        self.assertEqual(changes,{v5.volume.ELF_REL,v5.volume.NUM_REL,v5.IMAGE_REL,v5.CARD_REL})
        self.assertFalse(self.manifest['television_tested'])
        self.assertFalse(self.manifest['firmware_repacked'])
        self.assertFalse(self.manifest['flash_ready'])
        self.assertFalse(any('/font/' in r['path'] or r['path'].endswith('Color_res.bin') for r in rows))

    def test_inherited_zero_volume_and_mute_cpu_cases(self):
        report=v5.volume.validate_host(self.elf,self.new_elf)
        self.assertEqual(report['emulator_cases'],202)
        self.assertTrue(report['delay_slots_verified'])
        self.assertTrue(report['virtual_call_arguments_preserved'])
        self.assertTrue(report['saved_s0_and_epilogue_verified'])
        self.assertTrue(report['original_state_unchanged'])

    def test_tampered_overlay_and_manifest_are_rejected(self):
        target=v5.OUT/'overlay'/v5.CARD_REL
        original_read=Path.read_bytes
        def tamper(path):
            raw=original_read(path)
            return raw[:-1]+bytes([raw[-1]^1]) if path==target else raw
        with patch.object(Path,'read_bytes',tamper):
            with self.assertRaisesRegex(ValueError,'reconstructed'):v5.verified_records()
        original_text=Path.read_text
        def tamper_manifest(path,*args,**kwargs):
            text=original_text(path,*args,**kwargs)
            if path==v5.OUT/'manifest.json':
                value=json.loads(text);value['records'][0]['candidate_sha256']='0'*64
                return json.dumps(value)
            return text
        with patch.object(Path,'read_text',tamper_manifest):
            with self.assertRaisesRegex(ValueError,'reconstructed'):v5.verified_records()

    def test_output_escape_and_pinned_source_tampering_rejected(self):
        for path in (v5.ROOT/'README.md',v5.OUT/'../../../../README.md',v5.volume.SOURCE/v5.volume.ELF_REL):
            with self.assertRaises(ValueError):v5.guard(path)
        bad=bytearray(self.elf);bad[100]^=1
        with self.assertRaises(ValueError):v5.construct(self.num,bytes(bad))


if __name__=='__main__':unittest.main(verbosity=2)
