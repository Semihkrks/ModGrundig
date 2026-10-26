"""Offline v4 font/icon deltas, pinned source and generated-output regressions."""
import io
import json
from pathlib import Path
import struct
import unittest
from unittest.mock import patch
from PIL import Image
import build_native_ui_v4 as v4


class NativeV4Tests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.num=(v4.volume.SOURCE/v4.volume.NUM_REL).read_bytes()
        cls.elf=(v4.volume.SOURCE/v4.volume.ELF_REL).read_bytes()
        cls.new_num,cls.new_elf,cls.proof=v4.construct(cls.num,cls.elf)
        cls.manifest=json.loads((v4.OUT/'manifest.json').read_text())

    def test_exact_eight_local_instruction_changes_from_v3(self):
        prior_num,prior_elf,_=v4.v3.construct(self.num,self.elf)
        self.assertEqual(self.new_num,prior_num)
        self.assertEqual(len(self.proof['code_records']),8)
        allowed=set()
        for va,old,new in [(va,0x240204ae,0x240204af)for va in v4.FONT_VAS]+[(va,0x24040025,0x24040000)for va in v4.COLOR_VAS]:
            off=v4.volume.elf_va_offset(self.elf,va,4)
            self.assertEqual(struct.unpack_from('<I',prior_elf,off)[0],old)
            self.assertEqual(struct.unpack_from('<I',self.new_elf,off)[0],new)
            allowed.update(range(off,off+4))
        v4.volume.verify_allowlist(prior_elf,self.new_elf,allowed)
        self.assertEqual(v4.sha(self.new_elf),'62fd931e69eabae725d7b1938c91cf2ae52e46444a0e23794ef9bcd737c6eaf4')

    def test_overlay_changes_only_elf_and_two_icons_from_v3(self):
        records=v4.verified_records()
        self.assertEqual(len(records),22)
        differences=[]
        for row in records:
            relative='08_APP'+row['path']
            actual=row['candidate'].read_bytes()
            if actual!=(v4.v3.OUT/'overlay'/relative).read_bytes():differences.append(relative)
            self.assertEqual(row['original_sha256'],v4.sha((v4.volume.SOURCE/relative).read_bytes()))
        self.assertEqual(set(differences),{v4.volume.ELF_REL,*v4.ICON_PATHS.values()})
        self.assertFalse(self.manifest['firmware_repacked'])
        self.assertFalse(self.manifest['television_tested'])

    def test_icons_preserve_oem_format_and_improve_visible_glyph(self):
        for rid,relative in v4.ICON_PATHS.items():
            old=(v4.v3.OUT/'overlay'/relative).read_bytes()
            new=(v4.OUT/'overlay'/relative).read_bytes()
            original=(v4.volume.SOURCE/relative).read_bytes()
            self.assertEqual(v4.sha(new),v4.ICON_SHAS[rid])
            a,b=v4.geometry(original),v4.geometry(new)
            for field in ('width','height','bit_depth','color_type','interlace'):
                self.assertEqual(a[field],b[field])
            self.assertEqual(b['chunk_crc_errors'],0)
            self.assertTrue(b['iend_present'])
            self.assertEqual(b['trailing_bytes'],0)
            with Image.open(io.BytesIO(original)) as src,Image.open(io.BytesIO(new)) as dst:
                self.assertEqual(dst.mode,'P')
                self.assertEqual('transparency'in src.info,'transparency'in dst.info)
            oldbox,newbox=v4.glyph_bbox(old),v4.glyph_bbox(new)
            oldwidth,newwidth=oldbox[2]-oldbox[0],newbox[2]-newbox[0]
            self.assertGreater(newwidth,oldwidth*1.3)
            self.assertGreaterEqual(newbox[0],8)
            self.assertLessEqual(newbox[2],92)
            self.assertGreaterEqual(newwidth*30/b['width'],20)

    def test_font_uses_existing_resource_without_global_table_change(self):
        metrics=v4.font_metrics()
        self.assertEqual(metrics['resource_id'],0x4af)
        self.assertEqual(metrics['pixel_size'],36)
        self.assertLessEqual(metrics['measured_widths']['100'],76)
        self.assertEqual(struct.unpack_from('<I',self.new_num,56+4*0x3215)[0],36)
        self.assertEqual(v4.sha((v4.volume.SOURCE/v4.FONT_REL).read_bytes()),v4.FONT_SHA)
        rows={r['relative_path']for r in self.manifest['records']}
        self.assertFalse(any('/font/'in p or p.endswith(('Color_res.bin','Image_res.bin'))for p in rows))

    def test_tampered_overlay_is_rejected_read_only(self):
        target=v4.OUT/'overlay'/v4.ICON_PATHS[682]
        original=Path.read_bytes
        def modified(path):
            data=original(path)
            return data[:-1]+bytes([data[-1]^1]) if path==target else data
        with patch.object(Path,'read_bytes',modified):
            with self.assertRaisesRegex(ValueError,'pinned raster'):v4.verified_records()

    def test_tampered_manifest_is_not_authority(self):
        target=v4.OUT/'manifest.json'
        original=Path.read_text
        def modified(path,*args,**kwargs):
            text=original(path,*args,**kwargs)
            if path==target:
                data=json.loads(text)
                data['records'][0]['candidate_sha256']='0'*64
                return json.dumps(data)
            return text
        with patch.object(Path,'read_text',modified):
            with self.assertRaisesRegex(ValueError,'reconstructed'):v4.verified_records()

    def test_output_escape_and_source_tampering_fail_closed(self):
        for path in (v4.ROOT/'README.md',v4.OUT/'../../../../README.md',v4.volume.SOURCE/v4.volume.ELF_REL):
            with self.assertRaises(ValueError):v4.guard(path)
        tampered=bytearray(self.elf);tampered[100]^=1
        with self.assertRaises(ValueError):v4.construct(self.num,bytes(tampered))
        # Recovery must never accept this now-valid nonzero overlay.
        with self.assertRaisesRegex(ValueError,'exact known|nonzero'):v4.recover_zero_outputs()


if __name__=='__main__':unittest.main()
