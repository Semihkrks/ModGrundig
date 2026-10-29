"""Static V7.7 ELF placement/CFI and original-hook drift tests; no process runs."""
import hashlib,json,struct,sys,unittest
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];sys.path.insert(0,str(ROOT/'scripts'))
import native_ui_v77_name as n
import native_ui_v77_elf as e
from build_native_ui_v74_tv import verified_packaging_records
from build_native_volume_patch import elf_va_offset
class PlacementTests(unittest.TestCase):
 @classmethod
 def setUpClass(cls):
  row=next(r for r in verified_packaging_records() if r['path']=='/bin/dvbt_board')
  cls.original=row['candidate'].read_bytes();cls.output,cls.proof=e.append_payload(cls.original,n.code_create(),n.code_update(),extras=n.extras(),unwind_frames=n.unwind_frames())
 def test_two_name_helpers_load_mapping_unwind_and_original_headers(self):
  self.assertTrue(self.proof['original_phdr_bytes_preserved']);self.assertTrue(self.proof['unwind']['old_entries_preserved'])
  self.assertEqual(self.proof['unwind']['original_entries'],6741);self.assertEqual(self.proof['unwind']['merged_entries'],6743)
  self.assertLessEqual(self.proof['segment_size'],65536)
  for va,raw in [(n.CREATE,n.code_create()),(n.UPDATE,n.code_update()),*n.extras()]:
   off=elf_va_offset(self.output,va,len(raw));self.assertEqual(self.output[off:off+len(raw)],raw)
  self.assertEqual(self.output[:28],self.original[:28]);self.assertEqual(self.output[46:len(self.original)],self.original[46:])
 def test_original_hooks_and_t9_gp_prologue_match(self):
  for va,old,new in n.hook_records():self.assertEqual(struct.unpack_from('<I',self.original,elf_va_offset(self.original,va,4))[0],old)
  for va in (0x895808,0x89580c,0x895abc,0x895ac0,0x895af0,0x895af4,0x8968d8,0x8968dc,0x8968e0):
   off=elf_va_offset(self.original,va,4);self.assertEqual(self.output[off:off+4],self.original[off:off+4])
 def test_unwind_cfa_callee_saved_rules_at_every_external_call(self):
  for frame,(va,raw) in zip(n.unwind_frames(),[(n.CREATE,n.code_create()),(n.UPDATE,n.code_update()),*n.extras()]):
   cfa=0;saved={};events=iter(frame['events']);event=next(events,None)
   for i,word in enumerate(struct.unpack('<%dI'%(len(raw)//4),raw)):
    pc=i*4
    while event is not None and event['pc']<=pc:
     cfa=event.get('cfa_offset',cfa);saved.update(event.get('offsets',{}))
     for reg in event.get('restores',[]):saved.pop(reg,None)
     event=next(events,None)
    if word==0x0320f809:
     self.assertEqual(cfa,160);self.assertEqual(saved[n.RA],-4);self.assertEqual(saved[n.GP],-12)
     for reg in range(n.S0,n.S6+1):self.assertIn(reg,saved)
 def test_optional_mute_slot_accepts_third_complete_fde(self):
  # Deliberately synthetic leaf used ONLY to validate loader/FDE composition.
  va=e.SEGMENT_VA+0x1000;raw=struct.pack('<II',0x03e00008,0)
  frame=dict(start=va,size=len(raw),frame_size=0,events=[],personality=None,lsda=None)
  output,proof=e.append_payload(self.original,n.code_create(),n.code_update(),extras=[(va,raw)],unwind_frames=n.unwind_frames()+[frame])
  self.assertTrue(proof['unwind']['old_entries_preserved']);self.assertEqual(proof['unwind']['merged_entries'],6744)
  self.assertLessEqual(proof['segment_size'],65536)
  off=elf_va_offset(output,va,len(raw));self.assertEqual(output[off:off+len(raw)],raw)
 def test_slot_overlap_duplicates_and_missing_extra_fde_rejected(self):
  va=e.SEGMENT_VA+0x1000;raw=struct.pack('<II',0x03e00008,0)
  bad=[[(n.UPDATE,raw)],[(va,raw),(va,raw)],[(va+4,raw)],[(va,b'\0'*8192)]]
  for extra in bad:
   with self.assertRaises(ValueError):e.append_payload(self.original,n.code_create(),n.code_update(),extras=extra,unwind_frames=n.unwind_frames())
  with self.assertRaises(ValueError):e.append_payload(self.original,n.code_create(),n.code_update(),extras=[(va,raw)],unwind_frames=n.unwind_frames())
if __name__=='__main__':
 r=unittest.TextTestRunner().run(unittest.defaultTestLoader.loadTestsFromTestCase(PlacementTests))
 if r.wasSuccessful():
  out=ROOT/'analiz/native-ui-v77/native-name';out.mkdir(parents=True,exist_ok=True)
  (out/'elf-placement.json').write_text(json.dumps(PlacementTests.proof,indent=2)+'\n',encoding='utf-8')
 sys.exit(not r.wasSuccessful())
