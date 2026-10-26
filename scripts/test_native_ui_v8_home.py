"""Native Home byte allowlist/PNG tests and original MUF config-copy execution."""
import hashlib
import json
from pathlib import Path
import struct
import unittest
from unittest.mock import patch
import native_ui_v8_home as home


class HomeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        base=home.ROOT/'analiz/native-ui-candidate/v7/overlay'
        cls.num=(base/'08_APP/rc/rc/bin/Num_res.bin').read_bytes()
        cls.elf=(base/'08_APP/bin/dvbt_board').read_bytes()
        cls.result=home.transform(cls.num,cls.elf,{})

    def test_only_evidenced_instruction_words_change(self):
        num,elf,assets,changes=self.result
        self.assertEqual(num,self.num)
        expected=set()
        from build_native_volume_patch import elf_va_offset
        for p in changes['code_patches']:
            off=elf_va_offset(elf,int(p['va'],16),4)
            self.assertEqual(struct.unpack_from('<I',elf,off)[0],int(p['new_word'],16))
            expected.update(range(off,off+4))
        actual={i for i,(old,new) in enumerate(zip(self.elf,elf)) if old!=new}
        self.assertTrue(actual);self.assertTrue(actual.issubset(expected))
        self.assertEqual(len(changes['code_patches']),357)
        self.assertFalse(changes['native_navigation_modified'])
        self.assertFalse(changes['global_colors_modified'])

    def test_private_resources_preserve_png_contract_and_old_assets(self):
        seed={'08_APP/untouched.png':b'unchanged'}
        _,_,assets,changes=home.transform(self.num,self.elf,seed)
        self.assertEqual(seed,{'08_APP/untouched.png':b'unchanged'})
        self.assertEqual(assets['08_APP/untouched.png'],b'unchanged')
        expected=set(range(2180,2184))|set(range(2188,2224))
        self.assertEqual({r['id'] for r in changes['image_records']},expected)
        for row in changes['assets']:
            old=home._source(row);new=assets[row['relative_path']]
            self.assertEqual(old[16:26],new[16:26])
            self.assertEqual(hashlib.sha256(new).hexdigest(),row['candidate_sha256'])
            self.assertEqual(hashlib.sha256(old).hexdigest(),row['source_sha256'])

    def test_tampered_plan_instruction_or_inherited_icon_rejected(self):
        with patch.object(home,'PLAN_SHA','0'*64):
            with self.assertRaises(ValueError):home.plan()
        from build_native_volume_patch import elf_va_offset
        raw=bytearray(self.elf);off=elf_va_offset(raw,int(home.plan()['code_patches'][0]['va'],16),4);raw[off]^=1
        with self.assertRaises(ValueError):home.transform(self.num,bytes(raw),{})
        with patch.object(home,'ICON_MANIFEST_SHA','0'*64):
            with self.assertRaises(ValueError):home.transform(self.num,self.elf,{})

    def test_active_native_icons_match_current_approved_chrome_pixels(self):
        from PIL import Image
        import io
        assets=self.result[2];rows={r['old_id']:r for r in self.result[3]['assets']}
        approved=home.approved_icons();self.assertEqual(len(approved),22)
        for old,r in approved.items():
            image=Image.open(io.BytesIO(assets[rows[old]['relative_path']])).convert('RGBA')
            self.assertEqual(hashlib.sha256(image.tobytes()).hexdigest(),r['rgba_sha256'])
            box=r['compensated_svg_box'];expand=r['native_expand']
            self.assertAlmostEqual(box[0]*expand[0]/190,r['chrome_svg_box'])
            self.assertAlmostEqual(box[1]*expand[1]/190,r['chrome_svg_box'])

    def test_scene_retains_native_geometry_and_private_bindings(self):
        scene=home.scene_spec(self.num);self.assertFalse(scene['runtime_position_verified'])
        root=next(w for w in scene['widgets'] if w['field']=='this+0x180')
        self.assertEqual(root['rect'],[0,0,1920,504]);self.assertEqual(root['images'],[2180])
        picture=next(w for w in scene['widgets'] if w['field']=='this+0x204')
        self.assertEqual(picture['constructor_va'],'0xd4e2ac')
        self.assertTrue(all(i>=2188 for group in picture['foregrounds'] for i in group))

    def test_dark_fallback_panels_keep_their_original_white_text(self):
        from build_native_volume_patch import elf_va_offset
        excluded=home.plan()['preserved_dark_fallback_text']['removed_color_patch_sites']
        self.assertEqual(len(excluded),27)
        changed=self.result[1]
        for va in excluded:
            off=elf_va_offset(changed,int(va,16),4)
            self.assertEqual(changed[off:off+4],self.elf[off:off+4])
            self.assertEqual(struct.unpack_from('<I',changed,off)[0],0x24040045)
        patched={p['va'] for p in self.result[3]['code_patches']}
        self.assertTrue(patched.isdisjoint(excluded))

    def test_all_private_foregrounds_have_light_cards_and_picture_enables_images(self):
        audit=home.plan()['complete_foreground_parent_audit']['widgets']
        self.assertEqual(len(audit),18)
        self.assertEqual(len({i for c in audit for g in c['foreground_ids'] for i in g}),36)
        for c in audit:
            self.assertEqual(len(c['backgrounds']),4)
            self.assertTrue(all(r['new_id'] in [2181,2182,2183] for r in c['backgrounds']))
        import sys
        sys.path.insert(0,str(home.ROOT/'tools/native-volume-venv/Lib/site-packages'))
        from unicorn import Uc,UC_ARCH_MIPS,UC_MODE_MIPS32,UC_MODE_LITTLE_ENDIAN
        from unicorn.mips_const import UC_MIPS_REG_A0,UC_MIPS_REG_A1,UC_MIPS_REG_A2,UC_MIPS_REG_A3,UC_MIPS_REG_T9
        u=Uc(UC_ARCH_MIPS,UC_MODE_MIPS32|UC_MODE_LITTLE_ENDIAN)
        widget,code,callee=0x10000000,0x20000000,0x2e2285f0
        u.mem_map(widget,4096);u.mem_map(code,4096);u.mem_map(callee&~4095,4096)
        from build_native_volume_patch import elf_va_offset
        call_offset=elf_va_offset(self.result[1],0xd4e65c,8)
        u.mem_write(code,self.result[1][call_offset:call_offset+8])
        lib=(home.SOURCE/'07_MSLIB/libmuf.so').read_bytes()
        self.assertEqual(hashlib.sha256(lib).hexdigest(),'494d4aa45a3c8d8e10760388d8d30111e9127a0357d38cdf97979b9f9bb16d96')
        phoff=struct.unpack_from('<I',lib,28)[0];phsize,nph=struct.unpack_from('<HH',lib,42)
        for i in range(nph):
            kind,offset,va,_,size,_,_,_=struct.unpack_from('<8I',lib,phoff+i*phsize)
            if kind==1 and va<=callee and callee+16<=va+size:
                actual=lib[offset+callee-va:offset+callee-va+16];break
        else:self.fail('Native SetImgExpandProperty range not file-backed')
        self.assertEqual(actual,struct.pack('<4I',0xac860250,0xa0850258,0x03e00008,0xac870254))
        u.mem_write(callee,actual)
        for reg,val in [(UC_MIPS_REG_A0,widget),(UC_MIPS_REG_A1,1),(UC_MIPS_REG_A2,136),(UC_MIPS_REG_A3,136),(UC_MIPS_REG_T9,callee)]:u.reg_write(reg,val)
        u.emu_start(code,code+8,count=20)
        self.assertEqual(bytes(u.mem_read(widget+0x39,2)),b'\0\1')
        self.assertEqual(struct.unpack('<II',u.mem_read(widget+0x250,8)),(136,136))
        self.assertEqual(bytes(u.mem_read(widget+0x258,1)),b'\1')

    def test_all_dynamic_mixers_have_light_backgrounds_for_dark_text(self):
        from collections import defaultdict
        from build_native_volume_patch import elf_va_offset
        rows=[r for r in self.result[3]['code_patches'] if r.get('category')=='dynamic_mixer_private_background']
        self.assertEqual(len(rows),84);mixers=defaultdict(list)
        for r in rows:
            off=elf_va_offset(self.result[1],int(r['va'],16),4)
            self.assertEqual(struct.unpack_from('<I',self.result[1],off)[0],0x24050000|r['new_id'])
            self.assertEqual(r['new_id'],2181 if r['old_id'] in [40,78,857,461] else 2182)
            mixers[r['destination'].split('+')[0]].append(r['new_id'])
        self.assertEqual(len(mixers),21)
        for images in mixers.values():self.assertEqual(sorted(images),[2181,2181,2181,2182])
        from PIL import Image
        import io
        assets=self.result[2]
        for old_id in [946,947]:
            row=next(r for r in home.plan()['assets'] if r['old_id']==old_id)
            image=Image.open(io.BytesIO(assets[row['relative_path']])).convert('RGB')
            self.assertTrue(all(v>=200 for v in image.getpixel((image.width//2,image.height//2))))

    def test_separator_headers_keep_white_text_on_original_dark_images(self):
        from build_native_volume_patch import elf_va_offset
        excluded=home.plan()['preserved_dark_separator_headers']['removed_color_patch_sites']
        self.assertEqual(len(excluded),8)
        changed=self.result[1];patched={r['va'] for r in self.result[3]['code_patches']}
        for va in excluded:
            off=elf_va_offset(changed,int(va,16),4)
            self.assertEqual(changed[off:off+4],self.elf[off:off+4])
            self.assertEqual(struct.unpack_from('<I',changed,off)[0],0x2404005e)
        self.assertTrue(patched.isdisjoint(excluded))


def run_original(function,allowed_calls,config_colors):
    """Bounded original bytes, synthetic objects and explicit no-op service boundaries."""
    import sys
    sys.path.insert(0,str(home.ROOT/'tools/native-volume-venv/Lib/site-packages'))
    from unicorn import Uc, UC_ARCH_MIPS, UC_MODE_MIPS32, UC_MODE_LITTLE_ENDIAN, UC_HOOK_CODE
    from unicorn.mips_const import UC_MIPS_REG_PC,UC_MIPS_REG_RA,UC_MIPS_REG_SP,UC_MIPS_REG_T9,UC_MIPS_REG_A0,UC_MIPS_REG_A1,UC_MIPS_REG_V0
    raw=(home.SOURCE/'07_MSLIB/libmuf.so').read_bytes()
    assert hashlib.sha256(raw).hexdigest()=='494d4aa45a3c8d8e10760388d8d30111e9127a0357d38cdf97979b9f9bb16d96'
    u=Uc(UC_ARCH_MIPS,UC_MODE_MIPS32|UC_MODE_LITTLE_ENDIAN)
    phoff=struct.unpack_from('<I',raw,28)[0];entry_size,count=struct.unpack_from('<HH',raw,42)
    for i in range(count):
        kind,off,va,_,size,memory,_,_=struct.unpack_from('<8I',raw,phoff+i*entry_size)
        if kind!=1:continue
        page=va&~4095;length=((va+memory+4095)&~4095)-page
        u.mem_map(page,length);u.mem_write(va,raw[off:off+size])
    obj,arr,conf,child=0x10000000,0x10001000,0x10002000,0x10003000
    stack,stop,stub=0x11010000,0x12000000,0x12001000
    u.mem_map(obj,0x10000);u.mem_map(0x11000000,0x20000);u.mem_map(stop,0x2000)
    u.mem_write(stub,struct.pack('<II',0x03e00008,0))
    def word(address,value):u.mem_write(address,struct.pack('<I',value))
    word(obj+0x250,arr);word(obj+0x260,1);word(arr,child)
    u.mem_write(conf+0x78,b'\1')
    for offset,color in zip([0x34,0x38,0x3c,0x40],config_colors):word(conf+offset,color)
    calls=[];executed=[]
    entry,size=function
    def hook(uc,address,_size,_data):
        if address==stop:uc.emu_stop();return
        if address in allowed_calls:
            calls.append(hex(address));uc.reg_write(UC_MIPS_REG_T9,stub)
        elif address==stub:
            uc.reg_write(UC_MIPS_REG_V0,0)
            # Explicit geometry dependency returns a zero test origin.
            output=uc.reg_read(UC_MIPS_REG_A1)
            if entry==0x2e2853c0 and output>=0x11000000:uc.mem_write(output,b'\0'*8)
        elif not (entry<=address<entry+size or address==stub+4):
            raise ValueError(f'Unresolved native control flow {address:#x}')
        executed.append(hex(address))
    u.hook_add(UC_HOOK_CODE,hook)
    u.reg_write(UC_MIPS_REG_A0,obj);u.reg_write(UC_MIPS_REG_A1,conf);u.reg_write(UC_MIPS_REG_T9,entry)
    u.reg_write(UC_MIPS_REG_SP,stack);u.reg_write(UC_MIPS_REG_RA,stop)
    if entry==0x2e2853c0:
        for offset,color in zip([0x7c,0x80,0x84,0x88],config_colors):word(child+offset,color)
    u.emu_start(entry,stop,count=2500)
    if u.reg_read(UC_MIPS_REG_PC)!=stop:raise ValueError('Native MUF call did not return')
    for i in range(count):
        kind,off,va,_,file_size,_,_,_=struct.unpack_from('<8I',raw,phoff+i*entry_size)
        if kind==1 and va<=entry and entry+size<=va+file_size:
            assert bytes(u.mem_read(entry,size))==raw[off+entry-va:off+entry-va+size]
            break
    else:raise ValueError('Original MUF function range not file-backed')
    colors=[struct.unpack('<I',u.mem_read(child+off,4))[0] for off in [0x7c,0x80,0x84,0x88]]
    return colors,dict(function=hex(entry),unique_instructions=len(set(executed)),calls=calls,returned=True,
                       original_bytes_unchanged=True,target_device_executed=False)


class OriginalCompositeTests(unittest.TestCase):
    def test_native_config_copy_to_four_child_text_color_slots(self):
        colors=[0x10203040,0x50607080,0x90a0b0c0,0xd0e0f001]
        actual,evidence=run_original((0x2e285b38,660),{0x2e285bb8,0x2e285bd4,0x2e285d64},colors)
        self.assertEqual(actual,colors);self.assertTrue(evidence['returned'])

    def test_native_update_composite_retains_four_child_colors(self):
        colors=[0x10203040,0x50607080,0x90a0b0c0,0xd0e0f001]
        actual,evidence=run_original((0x2e2853c0,556),{0x2e2853f8,0x2e285468,0x2e285484,0x2e2854a8,0x2e285564},colors)
        self.assertEqual(actual,colors);self.assertTrue(evidence['returned'])


if __name__=='__main__':unittest.main()
