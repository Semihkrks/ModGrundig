"""V7.3 gray recolor preserves approved glyph and native V7.2 selection."""
import json
import unittest
from PIL import Image
import native_frame_rehost as r
import native_frame_viewer as viewer

class V73PreviewTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.frames={(v,m):r.render('v7.3-tv',v,m) for v,m in [(0,False),(35,True),(35,False)]}

    def test_gray_native_selection(self):
        for (v,m),(image,e) in self.frames.items():
            gray=v==0 or m
            self.assertEqual(e['panel_style']['image_resource_id'],2180 if gray else 674)
            for obj,resource in [(0x1a4,2180 if gray else 674),(0x1a8,680 if gray else 682)]:
                self.assertEqual([i['resource_id'] for i in e['native_volume_state']['state']['image_sets'] if i['object_offset']==obj],[resource]*4)
            self.assertEqual(image.getpixel((114,340))[:3],(232,232,232) if gray else (245,245,245))
            self.assertEqual(e['surface_geometry']['panel'],(80,306,68,450))

    def test_original_approved_glyph_indices_and_alpha(self):
        relative='08_APP/rc/ARimages/Grundig/volume/mute_icon.png'
        with Image.open(r.source_file('v7.1-tv',relative)) as old,Image.open(r.source_file('v7.3-tv',relative)) as new:
            self.assertEqual(old.size,new.size);self.assertEqual(old.mode,new.mode)
            self.assertEqual(old.tobytes(),new.tobytes())
            self.assertEqual(old.convert('RGBA').getchannel('A').tobytes(),new.convert('RGBA').getchannel('A').tobytes())
            red,green,blue,_=new.convert('RGBA').split()
            self.assertEqual(red.tobytes(),green.tobytes());self.assertEqual(red.tobytes(),blue.tobytes())

    def test_normal_and_numeric_unchanged(self):
        old,_=r.render('v7.1-tv',35,False)
        self.assertEqual(old.tobytes(),self.frames[35,False][0].tobytes())
        old,oe=r.render_numeric('v7.1-tv','12345');new,ne=r.render_numeric('v7.3-tv','12345')
        self.assertEqual(old.tobytes(),new.tobytes());self.assertEqual(oe['surface_geometry'],ne['surface_geometry'])
        self.assertIsNone(ne['channel_resolution'])

    def test_existing_badge_has_static_provenance_no_invented_lifecycle(self):
        im,e=r.render_mute_badge('v7.3-tv')
        self.assertEqual(e['surface_geometry']['icon'],(0,490,100,100))
        self.assertEqual(e['input_assets'][0]['image_id'],680)
        self.assertTrue(e['input_assets'][0]['path'].endswith('/Grundig/volume/mute_icon.png'))
        self.assertFalse(e['lifecycle_executed'])
        self.assertIn('zero alone does not launch',e['lifecycle_provenance']['rule'])
        self.assertEqual(e['constructor_provenance']['other_state_image_id'],401)
        self.assertEqual(im.getpixel((101,540)),(25,32,42,255))
        _,meta=viewer.frame_bytes('variant=v7.3-tv&scene=mute');data=json.loads(meta)
        self.assertEqual(data['variant'],'v7.3-tv');self.assertFalse(data['lifecycle_executed'])

if __name__=='__main__':unittest.main()
