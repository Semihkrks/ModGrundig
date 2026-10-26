"""Final TV preview contracts: bounded MUF plus host Pillow, never full TV."""
import json
import unittest
from unittest.mock import patch
import native_frame_rehost as r
import native_frame_viewer as viewer


class FinalPreviewTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.frames = {v: r.render(v, 27) for v in ('v7-tv','v7.1-tv')}
        cls.numeric = {v: r.render_numeric(v, '12') for v in ('v7-tv','v7.1-tv')}

    def test_volume_outer_origin_and_actual_flag(self):
        for v, (_, e) in self.frames.items():
            self.assertEqual(e['surface_geometry']['outer_frame'], (0,160,160,725))
            panel_calls = [c['boundary'] for c in e['callbacks'] if c['widget']=='volume-panel image 674']
            self.assertEqual(e['panel_style']['image_enabled'], v=='v7.1-tv')
            self.assertIn('StretchBlit' if v=='v7.1-tv' else 'FillRectangle', panel_calls)
            self.assertFalse(any(c['widget']=='normal-root image 685' for c in e['callbacks']))
        e = self.frames['v7.1-tv'][1]
        self.assertEqual(e['surface_geometry']['root_local'], (80,126,68,490))
        self.assertEqual(e['surface_geometry']['panel'], (80,306,68,450))

    def test_numeric_outer_clip_and_absent_name(self):
        for v, (image,e) in self.numeric.items():
            self.assertEqual(e['surface_geometry']['outer_frame'], (0,0,1920,312 if v=='v7.1-tv' else 80))
            self.assertEqual(e['surface_geometry']['background'], (1538,64,310,224))
            self.assertEqual(e['surface_geometry']['text'], (1566,118,254,78))
            self.assertIsNone(e['channel_resolution'])
            self.assertFalse(any(c.get('widget','').startswith('matched name') for c in e['callbacks']))
        self.assertEqual(self.numeric['v7-tv'][1]['surface_geometry']['text_visible'][3], 0)
        self.assertEqual(self.numeric['v7.1-tv'][1]['surface_geometry']['text_visible'], (1566,118,254,78))

    def test_all_compositions_stay_in_clip(self):
        for _, e in (*self.frames.values(), *self.numeric.values()):
            for c in e['compositions']:
                x,y,w,h = c['visible_rect']
                cx,cy,cw,ch = c['clip_rect']
                if w and h:
                    self.assertGreaterEqual(x,cx); self.assertGreaterEqual(y,cy)
                    self.assertLessEqual(x+w,cx+cw); self.assertLessEqual(y+h,cy+ch)

    def test_zero_full_and_mute_use_native_refresh(self):
        for volume, muted, icon in ((0,False,680),(100,False,682),(27,True,680)):
            _,e = r.render('v7.1-tv',volume,muted)
            s=e['native_volume_state']
            self.assertTrue(s['native']['returned'])
            self.assertEqual(s['state']['image_sets'][0]['resource_id'],icon)

    def test_pins_fail_closed(self):
        self.assertEqual(r.validate_tv_inputs('v7.1-tv')['overlay_files'],12)
        with patch.object(r,'sha',return_value='bad'):
            with self.assertRaises(ValueError): r.validate_tv_inputs('v7.1-tv')

    def test_viewer_defaults_to_final_candidate(self):
        _,metadata=viewer.frame_bytes('volume=27')
        data=json.loads(metadata)
        self.assertEqual(data['variant'],'v7.5-tv')
        self.assertIn('Pillow',data['boundaries'])


if __name__=='__main__': unittest.main()
