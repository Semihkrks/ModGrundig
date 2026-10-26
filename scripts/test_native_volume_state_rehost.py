"""Behavior checks across native original/v3 RefreshVolumeUI branches."""
import unittest
from unittest.mock import patch
import native_volume_state_rehost as native


class NativeVolumeStateTests(unittest.TestCase):
    def test_zero_icon_branch_changes_without_faking_audio_mute(self):
        old = native.run_case('original', 0)
        new = native.run_case('v3', 0)
        self.assertEqual({x['resource_id'] for x in old['state']['image_sets']}, {682})
        self.assertEqual({x['resource_id'] for x in new['state']['image_sets']}, {680})
        self.assertEqual(new['state']['audio_mute_requests'], [])
        self.assertEqual(new['state']['text'], '0')
        self.assertEqual(new['state']['progress_value'], 0)
        self.assertTrue(new['native']['returned'])
        self.assertGreater(new['native']['unique_instructions'], 200)

    def test_range_endpoints_clamp_and_actual_text(self):
        for volume in (1, 35, 100, 150):
            result = native.run_case('v3', volume)
            state = result['state']
            self.assertEqual(state['progress_value'], min(100, volume))
            # Actual routine formats the input before clamping progress.
            self.assertEqual(state['text'], str(volume))
            self.assertEqual({x['resource_id'] for x in state['image_sets']}, {682})
            self.assertEqual(state['shown_offsets'], [0x184])
            self.assertIn({'name': 'SetTimer', 'args': [3000, 0, 1]}, state['timers'])
            thumb = next(r['rect'] for r in state['rects'] if r['object_offset'] == 0x1b4)
            self.assertEqual(thumb, [37, 402-320*min(100, volume)//100, 25, 25])

    def test_explicit_mute_and_arc_are_distinct_native_branches(self):
        normal = native.run_case('v3', 35, muted=True)
        self.assertEqual({x['resource_id'] for x in normal['state']['image_sets']}, {680})
        arc = native.run_case('v3', 35, mode=3, arc_muted=True)
        self.assertEqual(arc['state']['audio_mute_requests'], [[4, 1, 0]])
        self.assertEqual({x['resource_id'] for x in arc['state']['image_sets']}, {5})
        self.assertEqual(arc['state']['shown_offsets'], [0x188])
        self.assertEqual([r['rect'][2:] for r in arc['state']['rects']], [[158, 90], [158, 89]])
        clear = native.run_case('v3', 35, mode=3)
        self.assertEqual(clear['state']['audio_mute_requests'], [[4, 0, 0]])
        self.assertIn('TimerEventHandler', [x['name'] for x in clear['state']['timers']])

    def test_arc_key_direction_and_hiding_gate(self):
        up = native.run_case('v3', mode=2, key=0xf04c)
        down = native.run_case('v3', mode=2, key=0xf04d)
        self.assertEqual({x['resource_id'] for x in up['state']['image_sets']}, {6})
        self.assertEqual({x['resource_id'] for x in down['state']['image_sets']}, {4})
        for active in (True, False):
            r = native.run_case('v3', mode=2, key=0xf000, arc_active=active)
            self.assertEqual(r['state']['hidden_offsets'].count(0x188), 2 if active else 1)

    def test_watchdog_and_tampered_inputs_fail_closed(self):
        with self.assertRaisesRegex(RuntimeError, 'watchdog|did not return'):
            native.run_case(instruction_budget=10)
        with self.assertRaises(ValueError): native.run_case(volume=256)
        with self.assertRaises(ValueError): native.run_case(variant='unknown')
        with patch.object(native, 'SHA', {'v3': '0'*64}):
            with self.assertRaisesRegex(ValueError, 'digest mismatch'): native.run_case()

    def test_v4_typography_patch_preserves_native_volume_and_arc_logic(self):
        for args in ({'volume': 0}, {'volume': 100, 'muted': True}, {'mode': 3, 'arc_muted': True}):
            previous = native.run_case('v3', **args)
            current = native.run_case('v4', **args)
            self.assertEqual(previous['state'], current['state'])
            self.assertEqual(previous['native']['executed_addresses'], current['native']['executed_addresses'])
            self.assertNotEqual(previous['native']['elf_sha256'], current['native']['elf_sha256'])

    def test_v5_compact_geometry_keeps_zero_mute_and_limits(self):
        for value in (0, 1, 35, 100):
            current = native.run_case('v5', value)
            state = current['state']
            self.assertEqual(state['text'], str(value))
            self.assertEqual(state['progress_value'], value)
            self.assertEqual({r['resource_id'] for r in state['image_sets']}, {680 if value == 0 else 682})
            thumb = next(r['rect'] for r in state['rects'] if r['object_offset'] == 0x1b4)
            self.assertEqual(thumb[1], 352-276*value//100)
        arc = native.run_case('v5', 35, mode=3, arc_muted=True)
        self.assertEqual(arc['state'], native.run_case('v4', 35, mode=3, arc_muted=True)['state'])

    def test_v6_visual_changes_do_not_change_audio_or_arc_branches(self):
        for args in ({'volume':0},{'volume':100,'muted':True},{'mode':3,'arc_muted':True}):
            self.assertEqual(native.run_case('v6',**args)['state'],native.run_case('v5',**args)['state'])


if __name__ == '__main__':
    unittest.main()
