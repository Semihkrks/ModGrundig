"""Host-only metadata/addition contracts; no mkfs, firmware or target runs."""
import hashlib
from pathlib import Path
import stat
import tempfile
import unittest
from unittest.mock import patch

import build_native_app as app


class NativeAppV8Tests(unittest.TestCase):
    def test_compressor_policy_preserves_defaults_and_requires_pinned_kernel_proof(self):
        self.assertEqual(app.compressor_policy('v3','lzo'),'v3')
        self.assertEqual(app.compressor_policy('v8','zlib'),'v8-zlib')
        self.assertEqual(app.compressor_policy('v8','lzo-raw-elf'),'v8-lzo-raw-elf')
        with self.assertRaises(ValueError):app.compressor_policy('v3','zlib')
        with self.assertRaises(ValueError):app.compressor_policy('v8','lz4')
        with patch.object(app,'sha',return_value='0'*64):
            with self.assertRaises(ValueError):app.compressor_policy('v8','zlib')

    def setUp(self):
        self.tmp=tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root=Path(self.tmp.name)
        self.file=self.root/'numeric.png';self.file.write_bytes(b'fixture')
        parent='/rc/ARimages/Grundig'
        self.original={parent:{'path':parent,'type':'directory','mode':stat.S_IFDIR|0o775,
            'uid':1000,'gid':1000,'nlink':19,'mtime_sec':1617867743,'mtime_nsec':0,'size':1328}}
        self.row={'path':parent+'/modern/numeric_bg.png','candidate':self.file,
                  'original_sha256':None,'candidate_sha256':hashlib.sha256(b'fixture').hexdigest()}

    def test_v8_declares_only_new_file_and_parent_without_changing_original_owner_time(self):
        expected,added=app.expected_with_additions(self.original,[self.row],'v8')
        self.assertEqual(added,['/rc/ARimages/Grundig/modern',self.row['path']])
        self.assertEqual(expected['/rc/ARimages/Grundig']['nlink'],20)
        self.assertEqual(self.original['/rc/ARimages/Grundig']['nlink'],19)
        for name,row in expected.items():
            self.assertEqual((row['uid'],row['gid'],row['mtime_sec'],row['mtime_nsec']),
                             (1000,1000,1617867743,0))
        self.assertEqual(expected[self.row['path']]['mode'],stat.S_IFREG|0o644)
        self.assertEqual(expected[self.row['path']]['nlink'],1)

    def test_old_versions_cannot_add_file(self):
        for revision in ('v2','v3'):
            with self.subTest(revision=revision),self.assertRaisesRegex(ValueError,'Unapproved'):
                app.expected_with_additions(self.original,[self.row],revision)

    def test_unapproved_duplicate_traversal_and_false_original_are_rejected(self):
        for change in ({'path':'/bin/extra'}, {'path':'/rc/../extra'},
                       {'path':'/rc/ARimages/Grundig/modern/sub/extra.png'},
                       {'path':'/rc/ARimages/Grundig/modern/extra.sh'}, {'original_sha256':'0'*64}):
            with self.subTest(change=change),self.assertRaises(ValueError):
                app.expected_with_additions(self.original,[{**self.row,**change}],'v8')
        with self.assertRaisesRegex(ValueError,'duplicate'):
            app.expected_with_additions(self.original,[self.row,self.row],'v8')

    def test_multiple_private_pngs_add_one_parent_and_preserve_parent_nlink(self):
        second={**self.row,'path':'/rc/ARimages/Grundig/modern/menu_background.png'}
        expected,added=app.expected_with_additions(self.original,[self.row,second],'v8')
        self.assertEqual(len(added),3)
        self.assertEqual(expected['/rc/ARimages/Grundig']['nlink'],20)
        self.assertEqual(expected['/rc/ARimages/Grundig/modern']['nlink'],2)

    def test_versioned_home_subdirectory_adds_only_its_exact_parent_link(self):
        second={**self.row,'path':'/rc/ARimages/Grundig/modern/v8/home-991.png'}
        expected,added=app.expected_with_additions(self.original,[self.row,second],'v8')
        self.assertEqual(len(added),4)
        self.assertEqual(expected['/rc/ARimages/Grundig']['nlink'],20)
        self.assertEqual(expected['/rc/ARimages/Grundig/modern']['nlink'],3)
        self.assertEqual(expected['/rc/ARimages/Grundig/modern/v8']['nlink'],2)

    def test_added_resource_cannot_replace_an_original_directory(self):
        row={**self.row,'path':'/rc/ARimages/Grundig'}
        with self.assertRaisesRegex(ValueError,'original regular'):
            app.expected_with_additions(self.original,[row],'v8')

    def test_packaging_rechecks_candidate_path_and_hash(self):
        boundary=self.root/'analiz/native-ui-candidate/v8/overlay/08_APP'
        p=boundary/self.row['path'].lstrip('/');p.parent.mkdir(parents=True);p.write_bytes(b'fixture')
        row={**self.row,'candidate':p}
        with patch.object(app,'ROOT',self.root):
            app.validate_overlay_inputs([row],'v8')
            p.write_bytes(b'changed')
            with self.assertRaisesRegex(ValueError,'changed'):
                app.validate_overlay_inputs([row],'v8')
            with self.assertRaisesRegex(ValueError,'binding'):
                app.validate_overlay_inputs([{**row,'candidate':self.file}],'v8')


if __name__=='__main__':unittest.main(verbosity=2)
