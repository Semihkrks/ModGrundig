"""Installed V7.7 native name/absence-of-countdown and mute lifecycle preview."""
import json
import unittest
from unittest.mock import patch
import native_frame_rehost as r
import native_frame_viewer as viewer
from native_channel_name_v77_rehost import run_name_bridge
from native_mute_v77_rehost import run_flow,render_flow

class V77PreviewTests(unittest.TestCase):
 def test_native_name_and_no_cosmetic_child_or_timers(self):
  _,e=r.render_numeric('v7.7-tv','01');b=e['native_name_bridge']
  self.assertEqual(b['text'],'TRT 1');self.assertEqual(b['digits'],'01')
  self.assertTrue(b['native_name_bridge_installed']);self.assertFalse(b['device_database'])
  self.assertIsNone(b['countdown']);self.assertTrue(b['countdown_removed'])
  self.assertEqual(set(b['helper_inputs']),{'create','update'})
  self.assertFalse(any(c['widget']=='native cosmetic timer ID2 blue line' for c in e['callbacks']))
  calls=[c['name'] for c in b['native_execution']['update']['boundaries']]
  self.assertNotIn('SetTimer',calls);self.assertNotIn('AbsContainer',calls)
 def test_unknown_channel_message_retained(self):
  _,e=r.render_numeric('v7.7-tv','0000');b=e['native_name_bridge']
  self.assertFalse(b['matched']);self.assertEqual(b['text'],'Kayıtlı kanal yok')
  self.assertTrue(any(c['widget']=='native helper destination name: PC demo service' for c in e['callbacks']))
 def test_gray_zero_muted_and_normal_blue(self):
  for volume,muted in [(0,False),(0,True),(35,True),(35,False),(100,False)]:
   _,e=r.render('v7.7-tv',volume,muted)
   self.assertTrue(e['native_volume_state']['native']['returned'])
   self.assertEqual(e['progress_fill_color'],0xff898989 if volume==0 or muted else 0xff0082d4)
 def test_modern_topright_badge_geometry(self):
  _,e=r.render_mute_badge('v7.7-tv');g=e['surface_geometry'];icon=g['icon']
  self.assertEqual(icon,(1772,74,64,64));self.assertEqual(1920-icon[0]-icon[2],84)
  self.assertEqual(r.intersect_rect(icon,g['outer_frame'],g['root'],g['panel']),icon)
 def test_removed_countdown_url_and_digits_limits(self):
  with self.assertRaises(ValueError):viewer.frame_bytes('variant=v7.7-tv&scene=numeric&digits=01&elapsed_ms=50')
  with self.assertRaises(ValueError):viewer.frame_bytes('variant=v7.7-tv&scene=numeric&digits=12345')
  with patch('native_ui_v77_name.code_update',return_value=b'bad'):
   with self.assertRaises(ValueError):run_name_bridge('v7.7-tv','01')
 def test_actual_mute_key_keeps_normal_panel_and_returns_gray_state(self):
  _,e=render_flow('v7.7-tv','mute-key',35,False);flow=e['native_lifecycle']
  self.assertTrue(e['lifecycle_executed']);self.assertTrue(flow['native_lifecycle_instructions_executed'])
  self.assertTrue(flow['muted']);self.assertEqual(flow['mode'],0);self.assertTrue(flow['panel_open']);self.assertFalse(flow['badge_visible'])
  self.assertEqual(e['progress_fill_color'],0xff898989)
  self.assertEqual([i['id'] for i in flow['images'] if i['widget']==0x1a8],[680]*4)
  self.assertNotIn(['show',0x180],flow['actions']);self.assertIn(['show',0x184],flow['actions'])
  self.assertIn('0xfb93d4',flow['executed_addresses']);self.assertIn('0xfb7d18',flow['executed_addresses'])
  _,e=render_flow('v7.7-tv','mute-key',35,True)
  self.assertFalse(e['native_lifecycle']['muted']);self.assertEqual(e['progress_fill_color'],0xff0082d4)
 def test_real_timeout_zero_and_mute_show_corner_badge(self):
  for volume,muted in [(0,False),(0,True),(35,True)]:
   _,e=render_flow('v7.7-tv','timeout',volume,muted);flow=e['native_lifecycle']
   self.assertFalse(flow['panel_open']);self.assertTrue(flow['badge_visible'])
   self.assertEqual(flow['muted'],muted);self.assertTrue(e['lifecycle_executed'])
   self.assertEqual(e['surface_geometry']['icon'],(1772,74,64,64))
   self.assertIn('0x1161000',flow['executed_addresses'])
   self.assertFalse(any(a[0]=='audio_set_mute' for a in flow['actions']))
  _,e=render_flow('v7.7-tv','timeout',35,False)
  self.assertFalse(e['native_lifecycle']['badge_visible']);self.assertEqual(e['surface_geometry'],{})
 def test_event_http_metadata_native_timeout_and_input_guard(self):
  _,raw=viewer.frame_bytes('variant=v7.7-tv&scene=mute-key&volume=35&mute=0');m=json.loads(raw)
  self.assertTrue(m['mute']);self.assertEqual(m['panel_timeout_ms'],3000);self.assertTrue(m['lifecycle_executed'])
  self.assertEqual(m['native_lifecycle']['mode'],0);self.assertIsNone(m['countdown'])
  with self.assertRaises(ValueError):viewer.frame_bytes('variant=v7.6-tv&scene=mute-key')
  with patch('native_ui_v77_mute.code_predicate',return_value=b'bad'):
   with self.assertRaises(ValueError):run_flow('v7.7-tv','timeout',0,False)
 def test_external_modes_zero_do_not_imply_local_mute(self):
  for mode in (2,3):
   flow=run_flow('v7.7-tv','timeout',0,False,mode=mode)
   self.assertFalse(flow['badge_visible']);self.assertFalse(flow['muted'])
   flow=run_flow('v7.7-tv','timeout',35,True,mode=mode)
   self.assertTrue(flow['badge_visible']);self.assertTrue(flow['muted'])
 def test_v77_explicit_and_http_metadata(self):
  _,raw=viewer.frame_bytes('variant=v7.7-tv&scene=numeric&digits=01');m=json.loads(raw)
  self.assertEqual(m['variant'],'v7.7-tv');self.assertIsNone(m['countdown'])
  self.assertTrue(m['channel_resolution']['native_name_bridge_installed'])

if __name__=='__main__':unittest.main()
