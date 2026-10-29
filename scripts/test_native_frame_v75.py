"""Installed V7.5 byte bridge plus explicit demo DB, MUF/Pillow limits."""
import json,unittest
from unittest.mock import patch
import native_frame_rehost as r
import native_frame_viewer as viewer
from native_channel_name_rehost import run_name_bridge

class V75PreviewTests(unittest.TestCase):
 def test_leading_zero_executes_installed_name_bridge(self):
  image,e=r.render_numeric('v7.5-tv','01');b=e['native_name_bridge']
  self.assertTrue(b['native_name_bridge_installed']);self.assertFalse(b['device_database'])
  self.assertEqual(b['digits'],'01');self.assertEqual(b['number'],1);self.assertTrue(b['matched'])
  self.assertEqual(b['rect'],(1566,206,254,38));self.assertEqual(b['font_resource_id'],0x4b0)
  self.assertEqual(b['font_size'],26);self.assertEqual(b['color'],0xff527185)
  self.assertGreater(b['native_execution']['unique_instructions'],100)
  self.assertTrue(any(c['widget']=='native helper destination name: PC demo service' for c in e['callbacks']))
 def test_missing_zero_destination_clears_name(self):
  _,e=r.render_numeric('v7.5-tv','0000');b=e['native_name_bridge']
  self.assertEqual(b['text'],'');self.assertFalse(b['matched'])
  self.assertFalse(any(c['widget']=='native helper destination name: PC demo service' for c in e['callbacks']))
  calls=[c['name'] for c in b['native_execution']['update']['boundaries']]
  self.assertIn('GetSel',calls);self.assertNotIn('GetName',calls)
 def test_four_digit_limit_historical_five_retained(self):
  with self.assertRaises(ValueError):r.render_numeric('v7.5-tv','12345')
  with self.assertRaises(ValueError):viewer.frame_bytes('variant=v7.5-tv&scene=numeric&digits=12345')
  r.render_numeric('v7.4-tv','12345')
 def test_gray_native_progress_and_badge_geometry(self):
  for vol,mute in [(0,False),(35,True),(35,False)]:
   _,e=r.render('v7.5-tv',vol,mute)
   self.assertEqual(e['progress_fill_color'],0xff898989 if vol==0 or mute else 0xff0082d4)
   self.assertEqual([v['color'] for v in e['native_volume_state']['state']['progress_colors']],[e['progress_fill_color']]*4)
  _,e=r.render_mute_badge('v7.5-tv');self.assertEqual(e['surface_geometry']['icon'],(1784,74,52,52))
  self.assertEqual(e['input_assets'][0]['image_id'],2181);self.assertFalse(e['lifecycle_executed'])
 def test_default_and_fail_closed_actual_helper_comparison(self):
  _,raw=viewer.frame_bytes('variant=v7.5-tv&scene=numeric&digits=01');m=json.loads(raw)
  self.assertEqual(m['variant'],'v7.5-tv');self.assertTrue(m['channel_resolution']['native_name_bridge_installed'])
  with patch('native_ui_v75_name.code_update',return_value=b'bad'):
   with self.assertRaises(ValueError):run_name_bridge('v7.5-tv','01')

if __name__=='__main__':unittest.main()
