"""V7.2 native refresh selection and MUF/Pillow composition contracts."""
import json
import unittest
from PIL import Image, ImageChops
import native_frame_rehost as r
import native_frame_viewer as viewer
from native_volume_state_rehost import run_case

class V72PreviewTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.frames={(v,m):r.render('v7.2-tv',v,m) for v,m in ((0,False),(35,True),(35,False),(100,False))}

    def test_native_selection_all_visual_states_and_invalidations(self):
        for (v,m),(_,e) in self.frames.items():
            s=e['native_volume_state']; muted=v==0 or m
            self.assertTrue(s['native']['returned'])
            for obj,resource in ((0x1a4,2180 if muted else 674),(0x1a8,680 if muted else 682)):
                assignments=[i for i in s['state']['image_sets'] if i['object_offset']==obj]
                self.assertEqual([i['resource_id'] for i in assignments],[resource]*4)
                self.assertEqual(len({i['field_offset'] for i in assignments}),4)
                self.assertIn(obj,s['state']['invalidated_offsets'])
            self.assertEqual(e['panel_style']['image_resource_id'],2180 if muted else 674)
            self.assertEqual(e['surface_geometry']['panel'],(80,306,68,450))
            self.assertEqual(s['state']['text'],str(v))

    def test_actual_panel_pixels_and_boundary_alpha(self):
        normal=self.frames[35,False][0]; muted=self.frames[35,True][0]
        self.assertNotEqual(normal.getpixel((114,340)),muted.getpixel((114,340)))
        for (v,m),(image,e) in self.frames.items():
            panel=next(a for a in e['input_assets'] if a['image_id'] in (674,2180))
            with Image.open(r.ROOT/panel['path']) as source:
                self.assertEqual(source.convert('RGBA').getpixel((0,0))[3],0)
            self.assertEqual(image.getpixel((80,306)),(25,32,42,255))
            self.assertEqual(image.getpixel((79,500)),(25,32,42,255))
            self.assertEqual(image.getpixel((148,500)),(25,32,42,255))
            self.assertEqual(image.getpixel((114,755))[3],255)

    def test_normal_and_numeric_unchanged(self):
        old,_=r.render('v7.1-tv',35,False)
        self.assertIsNone(ImageChops.difference(old,self.frames[35,False][0]).getbbox())
        old,oe=r.render_numeric('v7.1-tv','12345');new,ne=r.render_numeric('v7.2-tv','12345')
        self.assertEqual(old.tobytes(),new.tobytes())
        self.assertEqual(oe['surface_geometry'],ne['surface_geometry'])
        self.assertIsNone(ne['channel_resolution'])

    def test_repeat_transition_uses_selected_native_bytes(self):
        sequence=[run_case('v7.2-tv',35,m)['state'] for m in (False,True,False,True,False)]
        self.assertEqual(sequence[0],sequence[2]);self.assertEqual(sequence[2],sequence[4])
        self.assertEqual(sequence[1],sequence[3])
        self.assertNotEqual(sequence[0]['image_sets'],sequence[1]['image_sets'])

    def test_table_and_default(self):
        records=r.image_table('v7.2-tv');self.assertEqual(len(records),2181)
        self.assertEqual(records[2180]['resource_path'],'../rc/ARimages/Grundig/modern/volume_muted_bg.png')
        _,meta=viewer.frame_bytes('variant=v7.2-tv&volume=0')
        data=json.loads(meta);self.assertEqual(data['variant'],'v7.2-tv')
        self.assertEqual(data['panel_style']['image_resource_id'],2180)

if __name__=='__main__':unittest.main()
