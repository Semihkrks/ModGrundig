import io
import unittest
from PIL import Image
import build_native_ui_v72_tv as previous
import native_ui_v73_gray as gray


class GrayMuteTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.old = {'08_APP' + r['path']: r['candidate'].read_bytes()
                   for r in previous.verified_packaging_records()}
        cls.approved = (previous.ROOT / 'analiz/native-ui-candidate/v7.1-tv/overlay' / gray.ICON).read_bytes()
        cls.button = (previous.SOURCE / gray.BADGE).read_bytes()
        cls.new, cls.proof = gray.apply(cls.old, cls.approved, cls.button)

    def test_approved_shape_indices_and_alpha_preserved(self):
        old = Image.open(io.BytesIO(self.approved))
        new = Image.open(io.BytesIO(self.new[gray.ICON]))
        self.assertEqual((new.mode, new.size), (old.mode, old.size))
        self.assertEqual(new.tobytes(), old.tobytes())
        self.assertEqual(new.convert('RGBA').getchannel('A').tobytes(),
                         old.convert('RGBA').getchannel('A').tobytes())

    def test_all_assets_neutral_gray_and_glyph_readable(self):
        for path in (gray.ICON, gray.BADGE, gray.BACKGROUND):
            im = Image.open(io.BytesIO(self.new[path])).convert('RGBA')
            visible = [(r, g, b) for r, g, b, a in im.getdata() if a]
            self.assertTrue(all(r == g == b for r, g, b in visible), path)
        im = Image.open(io.BytesIO(self.new[gray.ICON])).convert('RGBA')
        self.assertLess(min(p[0] for p in im.getdata() if p[3] > 200), 150)
        self.assertEqual(im.getpixel((50, 50))[3], 255)

    def test_only_three_assets_change_no_native_or_lifecycle_change(self):
        self.assertEqual(set(self.new) - set(self.old), {gray.BADGE})
        self.assertEqual({p for p in self.new if self.new[p] != self.old.get(p)},
                         {gray.ICON, gray.BADGE, gray.BACKGROUND})
        for path in ('08_APP/bin/dvbt_board', '08_APP/rc/rc/bin/Num_res.bin',
                     '08_APP/rc/rc/bin/Image_res.bin'):
            self.assertEqual(self.new[path], self.old[path])

    def test_unexpected_asset_or_input_rejected(self):
        with self.assertRaises(ValueError):
            gray.apply(self.old, self.approved + b'x', self.button)
        bad = dict(self.old)
        bad['08_APP/bin/dvbt_board'] += b'x'
        with self.assertRaises(ValueError):
            gray.apply(bad, self.approved, self.button)


if __name__ == '__main__':
    unittest.main()
