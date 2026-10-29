"""V7.6 installed helper preview and explicit synthetic channel service checks."""
import json
import unittest
from unittest.mock import patch
import native_frame_rehost as r
import native_frame_viewer as viewer
from native_channel_name_v76_rehost import run_name_bridge

class V76PreviewTests(unittest.TestCase):
 def test_native_target_name_leading_zero(self):
  _,e=r.render_numeric('v7.6-tv','01');b=e['native_name_bridge']
  self.assertTrue(b['native_name_bridge_installed']);self.assertFalse(b['device_database'])
  self.assertEqual((b['digits'],b['number'],b['matched'],b['text']),('01',1,True,'TRT 1'))
  self.assertEqual(b['font_resource_id'],0x4b0);self.assertEqual(b['font_size'],26)
  self.assertGreater(b['native_execution']['unique_instructions'],100)
 def test_unregistered_number_native_text(self):
  _,e=r.render_numeric('v7.6-tv','0000');b=e['native_name_bridge']
  self.assertFalse(b['matched']);self.assertEqual(b['text'],'Kayıtlı kanal yok')
  self.assertTrue(any(c['widget']=='native helper destination name: PC demo service' for c in e['callbacks']))
  calls=[c['name'] for c in b['native_execution']['update']['boundaries']]
  self.assertIn('GetSel',calls);self.assertNotIn('GetName',calls)
 def test_volume_gp_regression_and_gray_state(self):
  for volume,muted in [(0,False),(1,False),(35,True),(100,False)]:
   _,e=r.render('v7.6-tv',volume,muted)
   self.assertTrue(e['native_volume_state']['native']['returned'])
   self.assertEqual(e['progress_fill_color'],0xff898989 if volume==0 or muted else 0xff0082d4)
 def test_bigger_badge_screen_margins_and_real_resource(self):
  _,e=r.render_mute_badge('v7.6-tv');g=e['surface_geometry'];icon=g['icon']
  self.assertEqual(icon,(1772,74,64,64));self.assertEqual(1920-icon[0]-icon[2],84)
  self.assertEqual(r.intersect_rect(icon,g['outer_frame'],g['root'],g['panel']),icon)
  self.assertEqual(e['input_assets'][0]['image_id'],2181);self.assertFalse(e['lifecycle_executed'])
 def test_four_digit_limit_and_helper_fail_closed(self):
  with self.assertRaises(ValueError):r.render_numeric('v7.6-tv','12345')
  with self.assertRaises(ValueError):viewer.frame_bytes('variant=v7.6-tv&scene=numeric&digits=12345')
  with patch('native_ui_v76_name.code_update',return_value=b'bad'):
   with self.assertRaises(ValueError):run_name_bridge('v7.6-tv','01')
 def test_native_countdown_real_helpers_and_original_duration_selection(self):
  for digits,duration in [('01',3000),('0000',2000)]:
   widths=[]
   for elapsed in (0,duration//2,duration):
    b=run_name_bridge('v7.6-tv',digits,elapsed_ms=elapsed);timer=b['countdown']
    self.assertTrue(timer['native_helpers_executed']);self.assertFalse(timer['lifecycle_executed'])
    self.assertEqual(timer['duration_ms'],duration);self.assertEqual(timer['remaining_ms'],duration-elapsed)
    self.assertEqual(timer['rect'][2],254*(duration-elapsed)//duration)
    self.assertEqual(timer['color'],0xff0082d4);self.assertEqual(timer['original_tuning_timer'],duration)
    self.assertEqual(set(b['helper_inputs']),{'create','update','start_timer','tick_timer'})
    widths.append(timer['rect'][2])
   self.assertEqual(widths,[254,127,0])
 def test_countdown_input_bounds_and_native_render_callback(self):
  _,e=r.render_numeric('v7.6-tv','01',elapsed_ms=1500)
  self.assertTrue(any(c['widget']=='native cosmetic timer ID2 blue line' for c in e['callbacks']))
  with self.assertRaises(ValueError):viewer.frame_bytes('variant=v7.6-tv&scene=volume&elapsed_ms=50')
  with self.assertRaises(ValueError):viewer.frame_bytes('variant=v7.6-tv&scene=numeric&elapsed_ms=-1')
  with self.assertRaises(ValueError):viewer.frame_bytes('variant=v7.6-tv&scene=numeric&elapsed_ms=10001')
 def test_default_v76_candidate(self):
  _,raw=viewer.frame_bytes('variant=v7.6-tv&scene=numeric&digits=01');self.assertEqual(json.loads(raw)['variant'],'v7.6-tv')
 def test_http_metadata_is_explicit_demo(self):
  _,raw=viewer.frame_bytes('variant=v7.6-tv&scene=numeric&digits=01');m=json.loads(raw)
  self.assertEqual(m['variant'],'v7.6-tv');self.assertTrue(m['channel_resolution']['native_name_bridge_installed'])
  self.assertFalse(m['channel_resolution']['device_database'])

if __name__=='__main__':unittest.main()
