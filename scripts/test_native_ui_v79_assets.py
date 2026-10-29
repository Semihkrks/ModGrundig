"""Approved-icon identity, native PNG format and stable append-only IDs."""
import io
from pathlib import Path
import struct
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch
import xml.etree.ElementTree as ET

from PIL import Image

import native_ui_v79_assets as assets
from map_ui_asset_dependencies import parse_table


class NativeV79AssetsTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.original = (assets.V78/assets.IMAGE).read_bytes()
        cls.payloads, cls.table, cls.proof = assets.expected_payloads(cls.original)

    def test_append_preserves_every_existing_native_resource(self):
        before = assets.image_paths(self.original)
        after = assets.image_paths(self.table)
        self.assertEqual(len(before), 2182)
        self.assertEqual(len(after), 2184)
        self.assertEqual(after[:2182], before)
        self.assertEqual(self.table[56:len(self.original)], self.original[56:])
        self.assertEqual(after[2182:], ['../rc/ARimages/Grundig/modern/volume_low.png',
                                       '../rc/ARimages/Grundig/modern/volume_high.png'])
        self.assertEqual(assets.IDS, dict(low=2182, high=2183))
        self.assertEqual(struct.unpack_from('<I', self.table, 4)[0], len(self.table))
        self.assertEqual(struct.unpack_from('<I', self.table, 16)[0], 2184*4)
        for word in set(range(14))-{1, 4, 7}:
            self.assertEqual(self.original[word*4:word*4+4], self.table[word*4:word*4+4])
        with tempfile.TemporaryDirectory(dir=assets.ASSETS) as temp:
            target = Path(temp)/'Image_res.bin'
            target.write_bytes(self.table)
            meta, rows = parse_table(target)
            self.assertEqual(meta['status'], 'fully_parsed')
            self.assertEqual(rows[2182]['resource_path'], after[2182])
            self.assertEqual(rows[2183]['resource_path'], after[2183])
        self.assertEqual(assets.sha(self.table), '3319b2a33d2950396bb181a558214d901575c82ca2ab8df2a91f52316dfce467')

    def test_bad_table_inputs_fail_closed(self):
        for raw in (b'', self.original[:-1], self.original+b'\0', self.table):
            with self.subTest(length=len(raw)), self.assertRaises(ValueError):
                assets.append_image_table(raw)
        changed = bytearray(self.original)
        changed[12] ^= 1  # opaque header word is pinned too
        with self.assertRaisesRegex(ValueError, 'Pinned'):
            assets.append_image_table(bytes(changed))

    def test_exact_approved_nodes_paths_and_visual_parameters(self):
        ns = '{http://www.w3.org/2000/svg}'
        source = assets.ROOT/'scripts/preview_volume_wave_icons.py'
        self.assertEqual(assets.sha(source.read_bytes()), assets.PREVIEW_SOURCE_SHA)
        self.assertEqual(assets.sha((assets.ROOT/'ui-preview/tv-icons.svg').read_bytes()), assets.SYMBOL_SHA)
        for name in assets.IDS:
            raw = assets.source_svg(name).encode()
            approval = assets.ROOT/f'analiz/ui-volume-review/v79-icons/{name}.svg'
            self.assertEqual(raw, approval.read_bytes())
            self.assertEqual(raw, (assets.ASSETS/f'volume_{name}.svg').read_bytes())
            root = ET.fromstring(raw)
            self.assertEqual(root.attrib, dict(width='100', height='100', viewBox='0 0 100 100'))
            self.assertEqual([node.tag for node in root], [ns+'rect', ns+'g'])
            self.assertEqual(root[0].attrib, dict(width='100', height='100', fill='#f5f5f5'))
            group = root[1]
            self.assertEqual(group.attrib, {'transform': 'translate(10 10) scale(2.5)',
                'fill': 'none', 'stroke': '#1687df', 'stroke-width': '2',
                'stroke-linecap': 'round', 'stroke-linejoin': 'round'})
            self.assertEqual([node.tag for node in group], [ns+'path', ns+'path'])
            self.assertEqual(group[0].attrib, {'d': assets.BODY})
            self.assertEqual(group[1].attrib['d'].count('Q'), len(assets.CURVES[name]))
            self.assertFalse(any('href' in key for node in root.iter() for key in node.attrib))

    def test_native_palette_alpha_and_blue_glyph_containment(self):
        native = assets.png_format((assets.V78/assets.MEDIUM).read_bytes())
        for name in assets.IDS:
            raw = self.payloads[assets.PATHS[name]]
            fmt = assets.png_format(raw)
            for field in ('width', 'height', 'bit_depth', 'color_type', 'interlace', 'alpha_capability'):
                self.assertEqual(fmt[field], native[field])
            self.assertEqual(assets.sha(raw), assets.PNG_SHAS[name])
            with Image.open(io.BytesIO(raw)) as image:
                image.load()
                self.assertEqual(image.mode, 'P')
                self.assertEqual(image.size, (100, 100))
                self.assertNotIn('transparency', image.info)
                rgba = image.convert('RGBA')
                self.assertEqual(rgba.getchannel('A').getextrema(), (255, 255))
                self.assertEqual(rgba.getpixel((0, 0)), (245, 245, 245, 255))
                blue = Image.new('1', image.size)
                blue.putdata([b > r+30 and b > g+10 for r, g, b, _ in rgba.get_flattened_data()])
                left, top, right, bottom = blue.getbbox()
                self.assertGreater(left, 0)
                self.assertGreater(top, 0)
                self.assertLess(right, 100)
                self.assertLess(bottom, 100)
            corrupted = bytearray(raw)
            corrupted[29] ^= 1
            with self.assertRaisesRegex(ValueError, 'CRC'):
                assets.png_format(bytes(corrupted))

    def test_preserves_medium_and_gray_mute_and_returns_only_new_paths(self):
        self.assertEqual(assets.sha((assets.V78/assets.MEDIUM).read_bytes()), assets.MEDIUM_SHA)
        self.assertEqual(assets.sha((assets.V78/assets.MUTE).read_bytes()), assets.MUTE_SHA)
        self.assertEqual(set(self.payloads), set(assets.PATHS.values()))
        self.assertNotIn(assets.MEDIUM, self.payloads)
        self.assertNotIn(assets.MUTE, self.payloads)
        self.assertEqual(self.proof['before_record_count'], 2182)
        self.assertEqual(self.proof['after_record_count'], 2184)
        self.assertFalse(self.proof['runtime_or_numeric_changes'])
        self.assertFalse(self.proof['physical_tv_tested'])

    def test_packaging_requires_no_site_packages(self):
        code = ('import sys; sys.path.insert(0,sys.argv[1]); import native_ui_v79_assets as a; '
                'p,t,e=a.expected_payloads((a.V78/a.IMAGE).read_bytes()); '
                'assert len(p)==2 and len(a.image_paths(t))==2184; '
                'assert not any(m.startswith(("PIL","playwright")) for m in sys.modules)')
        result = subprocess.run([sys.executable, '-S', '-c', code, str(assets.ROOT/'scripts')],
                                capture_output=True, text=True, timeout=30)
        self.assertEqual(result.returncode, 0, result.stderr)

    def test_retained_tamper_does_not_silently_pass(self):
        read = Path.read_bytes
        def substituted(path):
            value = read(path)
            return value+b'\0' if path == assets.ASSETS/'volume_low.png' else value
        with patch.object(Path, 'read_bytes', substituted):
            with self.assertRaisesRegex(ValueError, 'Pinned V7.9 raster'):
                assets.retained_assets()

    def test_chromium_8x_rerender_matches_both_retained_pngs_without_requests(self):
        # raster_assets aborts all routes and fails if even one request occurs.
        self.assertEqual(assets.raster_assets(), self.payloads)


if __name__ == '__main__':
    unittest.main()
