"""V7 TV scope regression: original menus, only volume/numeric changes."""
import json
import struct
import unittest
from unittest.mock import patch
import build_native_ui_v7_tv as build
from build_native_volume_patch import elf_va_offset

class V7TVTests(unittest.TestCase):
    def test_exact_twelve_files_and_one_new_numeric_background(self):
        records=build.verified_packaging_records()
        self.assertEqual(len(records),12);self.assertEqual(sum(r['original_sha256'] is None for r in records),1)
        self.assertFalse(any(r['path'].startswith(build.MENU_PREFIX) for r in records))
        self.assertEqual(records,build.verified_records())

    def test_all_menu_handler_bytes_and_message_tables_are_original(self):
        original=(build.SOURCE/'08_APP/bin/dvbt_board').read_bytes()
        current=(build.OUT/'overlay/08_APP/bin/dvbt_board').read_bytes()
        maps=json.loads((build.ROOT/'analiz/ui-yapi-haritasi.json').read_text(encoding='utf-8'))['message_maps']
        checked=set();changed=set()
        for m in maps:
            if m['module']!='08_APP/bin/dvbt_board':continue
            for r in m.get('records',[]):
                off=r['record_file_offset'];expected=struct.pack('<7I',*r['raw_u32'])
                self.assertEqual(original[off:off+28],expected);self.assertEqual(current[off:off+28],expected)
                h=r['handler'];extent=h.get('fde_range');start=int(h['address'],16)
                if not extent or int(extent['start'],16)!=start or start in checked:continue
                checked.add(start);size=int(extent['end_exclusive'],16)-start;p=elf_va_offset(original,start,size)
                if original[p:p+size]!=current[p:p+size]:changed.add(start)
        self.assertGreater(len(checked),1000)
        self.assertTrue(changed.issubset({0x895b84,0xfb9780,0xfb7d18}),[hex(x) for x in changed])

    def test_geometry_and_image_changes_cannot_touch_existing_menu_ids(self):
        prior=(build.SOURCE/'08_APP/rc/rc/bin/Num_res.bin').read_bytes()
        current=(build.OUT/'overlay/08_APP/rc/rc/bin/Num_res.bin').read_bytes()
        ids=[i for i in range((len(prior)-56)//4) if prior[56+i*4:60+i*4]!=current[56+i*4:60+i*4]]
        self.assertTrue(ids)
        self.assertTrue(all(0x98f<=i<=0x99a or 0x5a3e<=i<=0x5a79 for i in ids))
        prior=(build.SOURCE/'08_APP/rc/rc/bin/Image_res.bin').read_bytes()
        current=(build.OUT/'overlay/08_APP/rc/rc/bin/Image_res.bin').read_bytes()
        self.assertEqual(current[56:len(prior)],prior[56:])
        self.assertEqual(struct.unpack_from('<I',current,28)[0],2180)

    def test_code_pins_and_output_boundary_reject_tampering(self):
        import native_ui_v7_tv_pins as pins
        with patch.object(pins,'MANIFEST_SHA','0'*64):
            with self.assertRaises(ValueError):build.verified_packaging_records()
        with self.assertRaises(ValueError):build.guard(build.ROOT/'outside-v7.bin')

if __name__=='__main__':unittest.main()
