"""Failure-path checks for the offline APP builder; no target execution."""
import json
import os
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

import build_native_app as build


class NativeAppGuards(unittest.TestCase):
    def test_firmware_paths_cannot_escape(self):
        with tempfile.TemporaryDirectory() as text:
            base=Path(text)
            for path in ('relative','/../outside','/bin/../../outside'):
                with self.subTest(path=path),self.assertRaises(ValueError):
                    build.child(base,path)
            self.assertEqual(build.child(base,'/bin/dvbt_board'),base/'bin/dvbt_board')

    def test_inventory_does_not_follow_firmware_symlinks(self):
        with tempfile.TemporaryDirectory() as text:
            base=Path(text)/'stage';base.mkdir()
            (base/'autorun').symlink_to('/outside-the-firmware')
            result=build.inventory(base)
            self.assertEqual(set(result),{'/','/autorun'})
            self.assertEqual(result['/autorun']['type'],'symlink')
            self.assertEqual(result['/autorun']['symlink_target'],'/outside-the-firmware')

    def test_symlink_parent_escape_is_rejected(self):
        with tempfile.TemporaryDirectory() as text:
            base=Path(text)/'stage';base.mkdir()
            outside=Path(text)/'outside';outside.mkdir()
            (base/'bin').symlink_to(outside,target_is_directory=True)
            with self.assertRaises(ValueError):build.child(base,'/bin/dvbt_board')

    def test_hardlink_input_is_rejected(self):
        with tempfile.TemporaryDirectory() as text:
            base=Path(text);(base/'a').write_bytes(b'test')
            os.link(base/'a',base/'b')
            with self.assertRaises(ValueError):build.inventory(base)

    def test_special_file_is_rejected(self):
        with tempfile.TemporaryDirectory() as text:
            base=Path(text);os.mkfifo(base/'unexpected-fifo')
            with self.assertRaises(ValueError):build.inventory(base)

    def test_asset_manifest_cannot_add_an_arbitrary_app_file(self):
        with tempfile.TemporaryDirectory() as text,patch.object(build,'ROOT',Path(text)):
            target=Path(text)/'analiz/native-ui-candidate/v1/assets/manifest.json'
            target.parent.mkdir(parents=True)
            rows=[{'image_id':key,'action':'replace_asset',
                   'original_path':'analiz/dosya-sistemleri-tam/08_APP/'+value,
                   'candidate':'analiz/native-ui-candidate/v1/assets/candidate/08_APP/'+value}
                  for key,value in build.ASSET_PATHS.items()]
            rows[0]['original_path']='analiz/dosya-sistemleri-tam/08_APP/bin/unrelated'
            target.write_text(json.dumps({'assets':rows}))
            with self.assertRaises(ValueError):build.overlay_records()

    def test_extra_asset_id_is_rejected(self):
        with tempfile.TemporaryDirectory() as text,patch.object(build,'ROOT',Path(text)):
            target=Path(text)/'analiz/native-ui-candidate/v1/assets/manifest.json'
            target.parent.mkdir(parents=True)
            target.write_text(json.dumps({'assets':[{'image_id':1}]*21}))
            with self.assertRaises(ValueError):build.overlay_records()


if __name__=='__main__':unittest.main()
