"""Independent readback metadata policy tests; no target program runs."""
from pathlib import Path
import stat
import tempfile
import unittest

import verify_native_release as verify


class ReadbackMetadataTests(unittest.TestCase):
    def setUp(self):
        self.tmp=tempfile.TemporaryDirectory();self.addCleanup(self.tmp.cleanup)
        self.file=Path(self.tmp.name)/'test.png';self.file.write_bytes(b'pngfixture')
        self.parent='/rc/ARimages/Grundig';self.directory=self.parent+'/modern'
        self.new=self.directory+'/home_bg.png'
        self.original={self.parent:dict(type='directory',mode=stat.S_IFDIR|0o775,uid=1000,gid=1000,
            nlink=19,mtime_sec=1617867743,mtime_nsec=0,size=1328)}
        self.records=[dict(path=self.new,candidate=self.file,original_sha256=None)]
        self.current={self.parent:{**self.original[self.parent],'nlink':20},
                      self.directory:{**self.original[self.parent],'nlink':2},
                      self.new:{**self.original[self.parent],'type':'regular','mode':stat.S_IFREG|0o644,
                                'nlink':1,'size':len(b'pngfixture')}}

    def test_declared_additions_and_single_parent_nlink_delta_are_verified(self):
        r=verify.validate_metadata(self.original,self.current,'v8',self.records)
        self.assertEqual(r,dict(original_metadata_entries_checked=1,new_resource_files_checked=1,
                                new_directories_checked=1,original_parent_nlink_delta=1))

    def test_original_owner_time_and_mode_tamper_rejected(self):
        for field in ('mode','uid','gid','nlink','mtime_sec','mtime_nsec'):
            current={k:dict(v) for k,v in self.current.items()};current[self.parent][field]+=1
            with self.subTest(field=field),self.assertRaisesRegex(ValueError,'Original metadata'):
                verify.validate_metadata(self.original,current,'v8',self.records)

    def test_versioned_home_directory_metadata_and_links(self):
        version=self.directory+'/v8';new=version+'/home-991.png'
        records=self.records+[dict(path=new,candidate=self.file,original_sha256=None)]
        current={k:dict(v) for k,v in self.current.items()}
        current[self.directory]['nlink']=3
        current[version]={**self.original[self.parent],'nlink':2}
        current[new]=dict(self.current[self.new])
        result=verify.validate_metadata(self.original,current,'v8',records)
        self.assertEqual(result['new_directories_checked'],2)
        self.assertEqual(result['original_parent_nlink_delta'],1)

    def test_unlisted_paths_and_nonflat_pngs_rejected(self):
        with self.assertRaisesRegex(ValueError,'paths'):
            verify.validate_metadata(self.original,{**self.current,'/extra':{}},'v8',self.records)
        with self.assertRaisesRegex(ValueError,'private flat'):
            verify.validate_metadata(self.original,self.current,'v8',[{**self.records[0],'path':self.directory+'/sub/x.png'}])

    def test_new_file_mode_size_and_time_must_match_declared_policy(self):
        for field in ('mode','size','mtime_sec'):
            current={k:dict(v) for k,v in self.current.items()};current[self.new][field]+=1
            with self.subTest(field=field),self.assertRaises(ValueError):
                verify.validate_metadata(self.original,current,'v8',self.records)

    def test_old_versions_remain_exact_metadata_only(self):
        for revision in ('v2','v3'):
            r=verify.validate_metadata(self.original,self.original,revision)
            self.assertEqual(r['new_resource_files_checked'],0)
            with self.assertRaisesRegex(ValueError,'Old revision'):
                verify.validate_metadata(self.original,self.current,revision,self.records)


if __name__=='__main__':unittest.main(verbosity=2)
