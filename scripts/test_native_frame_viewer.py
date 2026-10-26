"""Local viewer API boundaries and genuine PNG response checks."""
import io
import json
import threading
import unittest
from http.client import HTTPConnection
from http.server import HTTPServer
from PIL import Image
import native_frame_viewer as viewer


class NativeFrameViewerTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.server = HTTPServer(('127.0.0.1', 0), viewer.Handler)
        cls.port = cls.server.server_port
        cls.thread = threading.Thread(target=cls.server.serve_forever, daemon=True)
        cls.thread.start()

    @classmethod
    def tearDownClass(cls):
        cls.server.shutdown()
        cls.server.server_close()
        cls.thread.join(timeout=3)

    def request(self, path, headers=None):
        connection = HTTPConnection('127.0.0.1', self.port, timeout=10)
        connection.request('GET', path, headers=headers or {})
        response = connection.getresponse()
        body = response.read()
        result = response.status, dict(response.getheaders()), body
        connection.close()
        return result

    def test_actual_frame_and_metadata(self):
        status, headers, body = self.request('/frame.png?variant=v5&volume=0')
        self.assertEqual(status, 200)
        self.assertEqual(headers['Content-Type'], 'image/png')
        with Image.open(io.BytesIO(body)) as image:
            self.assertEqual(image.size, (1920, 1080))
        status, _, body = self.request('/frame.json?variant=v5&volume=0')
        self.assertEqual(status, 200)
        metadata = json.loads(body)
        self.assertEqual(metadata['variant'], 'v5')
        self.assertGreater(metadata['native_instructions']['DrawString'], 100)
        self.assertIn('mocked services', metadata['boundaries'])

    def test_bad_parameters_never_render(self):
        for query in ('volume=-1', 'volume=101', 'mute=yes', 'variant=other', 'scene=boot',
                      'digits=abc', 'digits=123456', 'volume=1&volume=2', 'path=../AGENTS.md'):
            with self.subTest(query=query):
                self.assertEqual(self.request('/frame.png?'+query)[0], 400)

    def test_v7_tv_numeric_has_no_proposed_name_and_menu_scene_is_absent(self):
        self.assertEqual(self.request('/frame.png?variant=v7-tv&scene=resources')[0],400)
        self.assertEqual(self.request('/frame.png?variant=v8&scene=volume')[0],400)
        status,headers,raw=self.request('/frame.json?variant=v7-tv&scene=numeric&digits=12')
        self.assertEqual(status,200)
        self.assertIsNone(json.loads(raw)['channel_resolution'])
        self.assertNotIn('X-Channel-Resolution',headers)

    def test_rich_card_metadata_and_safe_header(self):
        from urllib.parse import unquote
        status,headers,_=self.request('/frame.png?variant=v6&scene=numeric&digits=12')
        self.assertEqual(status,200)
        channel=json.loads(unquote(headers['X-Channel-Resolution']))
        self.assertEqual(channel['name'],'TRT Müzik')
        self.assertFalse(channel['native_name_bridge_installed'])
        self.assertNotIn('\n',headers['X-Channel-Resolution'])
        status,_,body=self.request('/frame.json?variant=v6&scene=numeric&digits=999')
        self.assertEqual(status,200)
        self.assertFalse(json.loads(body)['channel_resolution']['matched'])

    def test_host_origin_and_filesystem_boundaries(self):
        self.assertEqual(self.request('/', {'Host': 'example.com'})[0], 403)
        self.assertEqual(self.request('/', {'Origin': 'https://example.com'})[0], 403)
        self.assertEqual(self.request('/../AGENTS.md')[0], 404)
        self.assertEqual(self.request('/?'+('a'*257))[0], 400)
        status, headers, _ = self.request('/')
        self.assertEqual(status, 200)
        self.assertIn('same-origin', headers['Cross-Origin-Resource-Policy'])

    def test_full_preview_static_and_pinned_graphics_remain_contained(self):
        for path,mime in (('/preview/?menu=1','text/html'),('/preview/app.js','text/javascript'),
                          ('/preview/native-fonts/DINPro-CondMedium.otf','font/otf'),
                          ('/preview/native-assets/volume-speaker.png','image/png')):
            status,headers,body=self.request(path)
            self.assertEqual(status,200,path)
            self.assertTrue(headers['Content-Type'].startswith(mime))
            self.assertIn("script-src 'self'",headers['Content-Security-Policy'])
            self.assertTrue(body)
        for path in ('/preview/%2e%2e/AGENTS.md','/preview/tests/tv-model.test.mjs','/preview/native-fonts/../../AGENTS.md',
                     '/preview/.env','/preview/native-assets/unknown.png'):
            self.assertEqual(self.request(path)[0],404,path)


if __name__ == '__main__':
    unittest.main()
