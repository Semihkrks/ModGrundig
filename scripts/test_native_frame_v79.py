"""Integration of installed V7.9 selector, image IDs, geometry and old lifecycle."""
import json
import unittest
from pathlib import Path

import native_frame_rehost as rehost
import native_frame_viewer as viewer
from native_mute_v77_rehost import render_flow

OUT = Path(__file__).resolve().parents[1] / 'analiz/native-ui-v79/preview'


class V79FrameTests(unittest.TestCase):
    def test_native_selection_resolves_the_packaged_image_paths(self):
        for volume, expected in [(0,680),(1,2182),(20,2182),(21,682),(60,682),(61,2183),(100,2183)]:
            with self.subTest(volume=volume):
                image, evidence = rehost.render('v7.9-tv',volume)
                selected=[r['resource_id'] for r in evidence['native_volume_state']['state']['image_sets'] if r['object_offset']==0x1a8]
                self.assertEqual(selected,[expected]*4)
                self.assertEqual(evidence['surface_geometry']['panel'],(40,306,68,450))
                self.assertEqual(evidence['surface_geometry']['speaker'],(52,699,44,44))
                self.assertTrue(evidence['native_volume_state']['native']['returned'])
                if volume in (0,20,35,61,100):
                    OUT.mkdir(parents=True,exist_ok=True)
                    image.save(OUT/f'volume{volume}.png')
                    (OUT/f'volume{volume}.json').write_text(json.dumps(evidence,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')

    def test_zero_and_mute_keep_gray_panel_and_bar(self):
        for volume, muted in [(0,False),(20,True),(61,True),(100,True)]:
            with self.subTest(volume=volume,muted=muted):
                _,e=rehost.render('v7.9-tv',volume,muted)
                self.assertEqual(e['progress_fill_color'],0xff898989)
                self.assertEqual(e['panel_style']['image_resource_id'],2180)
                ids=[x['resource_id'] for x in e['native_volume_state']['state']['image_sets'] if x['object_offset']==0x1a8]
                self.assertEqual(ids,[680]*4)

    def test_actual_mute_key_and_timeout_keep_old_behavior(self):
        image,e=render_flow('v7.9-tv','mute-key',61,False)
        self.assertTrue(e['native_lifecycle']['muted'])
        self.assertTrue(e['native_lifecycle']['panel_open'])
        self.assertEqual(e['progress_fill_color'],0xff898989)
        _,e=render_flow('v7.9-tv','mute-key',61,True)
        self.assertFalse(e['native_lifecycle']['muted'])
        self.assertEqual(e['progress_fill_color'],0xff0082d4)
        for volume,muted in [(0,False),(61,True)]:
            _,e=render_flow('v7.9-tv','timeout',volume,muted)
            self.assertTrue(e['native_lifecycle']['badge_visible'])
            self.assertEqual(e['surface_geometry']['icon'],(1772,74,64,64))

    def test_channel_name_and_no_countdown_remain(self):
        for digits,expected in [('01','TRT 1'),('0000','Kayıtlı kanal yok')]:
            _,e=rehost.render_numeric('v7.9-tv',digits)
            self.assertEqual(e['native_name_bridge']['text'],expected)
            self.assertTrue(e['native_name_bridge']['countdown_removed'])

    def test_pinned_new_table_has_two_append_only_resources(self):
        old,new=rehost.image_table('v7.7-tv'),rehost.image_table('v7.9-tv')
        self.assertEqual(len(old),2182)
        self.assertEqual(len(new),2184)
        self.assertEqual(old,new[:2182])
        self.assertEqual(new[2182]['resource_path'],'../rc/ARimages/Grundig/modern/volume_low.png')
        self.assertEqual(new[2183]['resource_path'],'../rc/ARimages/Grundig/modern/volume_high.png')

    def test_current_default_and_http_metadata_are_v79(self):
        image,raw=viewer.frame_bytes('scene=numeric&digits=01')
        meta=json.loads(raw)
        self.assertEqual(meta['variant'],'v7.9-tv')
        self.assertTrue(meta['channel_resolution']['native_name_bridge_installed'])
        self.assertIsNone(meta['countdown'])
        self.assertTrue(image.startswith(b'\x89PNG\r\n\x1a\n'))


if __name__=='__main__':unittest.main(verbosity=2)
