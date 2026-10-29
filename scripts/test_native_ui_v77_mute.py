"""Actual installed OnKey -> Refresh and timeout instruction regression tests.

Sound, widget surface and app dependencies are explicit model boundaries.
No firmware process, devices or system calls are executed.
"""
import json
import struct
import sys
import unittest
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools/native-volume-venv/Lib/site-packages'))
from unicorn import Uc,UC_ARCH_MIPS,UC_MODE_MIPS32,UC_MODE_LITTLE_ENDIAN,UC_HOOK_CODE,UC_HOOK_MEM_INVALID
from unicorn import mips_const as m
import native_ui_v77_mute as patch

FRAME,STOP,STUB,STACK=0x10000000,0x11000000,0x11001000,0x12010000
BADGE_FRAME,PANEL_APP,BADGE_APP,SOUND=FRAME+0x1e000,FRAME+0x1e400,FRAME+0x1e500,FRAME+0x1e600
IMPORTS={0x10c4ce4:'GetMuteControlFrame',0x10c5068:'Hide',0x10cc98c:'Show',
 0x10c909c:'SoundInstance',0x10cd110:'GetMainVolume',0x10ca504:'IsMuted',
 0x10c538c:'DigiLinkInstance',0x10c966c:'IsARCMuteOn',0x10c786c:'KillTimer',
 0x10cb058:'SetTimer',0x10c97b4:'sprintf',0x10c6920:'allocator',0x10c4f9c:'string',
 0x10cb39c:'MStringSet',0x10c5070:'stringDestructor',0x10c4948:'allocatorDestructor',
 0x10c4e28:'Invalidate',0x10caa64:'SetCurValue',0x10c8a6c:'RcGetNum',
 0x10c9810:'RectSet',0x10cba00:'MImgSet',0x10cb3d8:'GetMSrvSSSound',
 0x10c94cc:'SetMuteStatus',0x10c5804:'GetRect',0x10c858c:'IsARCActive',
 0x10cb89c:'IsCECInitCompleted',0x10c855c:'GetHDMIDevPlugged',
 0x10c98f8:'GetParentApp',0x10c4dec:'Kill',0x10cd064:'SetMute',
 0x10c7b50:'ProccessUserRCInput',0x10c7038:'IsRcKeyProcessedByCec',
 0x10c8a5c:'GetSystemTime',0x10c75f8:'GetTimeDiffFromNow',
 0x10cc2ec:'MainVolumeUp',0x10cbd40:'MainVolumeDown',
 0x10c9890:'operator_new',0x10cae90:'MuteControlApp',0x10c7470:'Run',0x10c856c:'AppShow'}

class Harness:
 def __init__(self,raw,nums=None,*,volume=35,muted=False,mode=0,arc=False,arc_processed=True,existing_badge=False,poison=True,poison_mode_on_kill=None):
  self.raw=raw;self.nums=nums or (ROOT/'analiz/native-ui-candidate/v7.7-tv/overlay'/patch.NUM).read_bytes()
  self.volume=volume;self.muted=muted;self.arc=arc;self.arc_processed=arc_processed;self.poison=poison
  self.poison_mode_on_kill=poison_mode_on_kill
  self.badge_visible=existing_badge;self.panel_open=True;self.calls=[];self.actions=[];self.visited=set();self.images=[];self.timers=[]
  self.u=Uc(UC_ARCH_MIPS,UC_MODE_MIPS32|UC_MODE_LITTLE_ENDIAN)
  phoff=struct.unpack_from('<I',raw,28)[0];size,count=struct.unpack_from('<HH',raw,42)
  for i in range(count):
   kind,off,va,_,fs,ms,_,_=struct.unpack_from('<8I',raw,phoff+i*size)
   if kind==1:
    lo=va&~4095;hi=(va+ms+4095)&~4095;self.u.mem_map(lo,hi-lo);self.u.mem_write(va,raw[off:off+fs])
  for lo,size in [(FRAME,0x20000),(STOP,0x10000),(0x12000000,0x20000)]:self.u.mem_map(lo,size)
  self.boundaries={}
  for i,(got,name) in enumerate(IMPORTS.items()):
   address=STUB+i*16;self.w32(got,address);self.u.mem_write(address,struct.pack('<II',0x03e00008,0));self.boundaries[address]=name
  self.w32(0x10c5f88,0xfb7d18) # Execute the actual Refresh, not a mocked callback.
  self.w32(0x10cc1dc,0xfb7aec)
  self.objects={FRAME+0x1000+i*0x1000:off for i,off in enumerate((0x1a4,0x180,0x184,0x188,0x1a8,0x1ac,0x1b0,0x1b4,0x1b8,0x1bc))}
  for address,off in self.objects.items():self.w32(FRAME+off,address);self.w32(address,FRAME+0x1f000)
  virtual=STUB+0x800;self.u.mem_write(virtual,struct.pack('<II',0x03e00008,0));self.boundaries[virtual]='VirtualMoveRect';self.w32(FRAME+0x1f024,virtual)
  self.w32(FRAME+0x214,mode)
  for got,value in [(0x10ca234,0),(0x10c6bc8,1),(0x10cd038,1)]:self.w32(self.r32(got),value)
  progress=next(a for a,o in self.objects.items() if o==0x1bc)
  for field in (0x2a4,0x2a8,0x2ac,0x2b0):self.w32(progress+field,0xff0082d4)
  self.u.hook_add(UC_HOOK_CODE,self.hook);self.u.hook_add(UC_HOOK_MEM_INVALID,self.invalid)
 def r32(self,a):return struct.unpack('<I',self.u.mem_read(a,4))[0]
 def w32(self,a,v):self.u.mem_write(a,struct.pack('<I',v&0xffffffff))
 def offset(self,a):
  if a not in self.objects:raise AssertionError('Unknown modeled widget '+hex(a))
  return self.objects[a]
 def cstring(self,a):
  out=bytearray()
  for i in range(100):
   v=self.u.mem_read(a+i,1)
   if v==b'\0':return out.decode('ascii')
   out+=v
  raise AssertionError('Unbounded format string')
 def callback(self,key,a):
  if key in ('SoundInstance','DigiLinkInstance','GetMSrvSSSound'):return SOUND
  if key=='GetMainVolume':return self.volume
  if key=='IsMuted':return int(self.muted)
  if key=='IsARCMuteOn':return int(self.muted)
  if key in ('IsARCActive','IsCECInitCompleted','GetHDMIDevPlugged'):return int(self.arc)
  if key=='IsRcKeyProcessedByCec':return int(self.arc_processed)
  if key=='SetMute':self.muted=bool(a[1]);self.actions.append(['audio_set_mute',self.muted]);return 1
  if key=='GetMuteControlFrame':return BADGE_FRAME if self.badge_visible else 0
  if key=='GetParentApp':return BADGE_APP if a[0]==BADGE_FRAME else PANEL_APP
  if key=='Kill':
   if a[0]==BADGE_APP:self.badge_visible=False;self.actions.append(['badge_kill'])
   elif a[0]==PANEL_APP:
    self.panel_open=False;self.actions.append(['panel_kill'])
    if self.poison_mode_on_kill is not None:self.w32(FRAME+0x214,self.poison_mode_on_kill)
   else:raise AssertionError('Unexpected app kill')
   return 1
  if key=='operator_new':assert a[0]==0x3c;return BADGE_APP
  if key=='MuteControlApp':assert a[0]==BADGE_APP;return BADGE_APP
  if key=='Run':assert a[:3]==[BADGE_APP,0x10ff,0];self.badge_visible=True;self.actions.append(['badge_run',0x10ff]);return 1
  if key=='AppShow':assert a[:2]==[BADGE_APP,0];self.badge_visible=True;self.actions.append(['badge_show']);return 1
  if key=='sprintf':
   assert self.cstring(a[1])=='%d';v=str(a[2]).encode();self.u.mem_write(a[0],v+b'\0');return len(v)
  if key=='string':self.w32(a[0],a[1]);return a[0]
  if key=='MStringSet':self.last_text=self.cstring(self.r32(a[1]));return 0
  if key in ('allocator','allocatorDestructor','stringDestructor'):return 0
  if key=='Invalidate':self.offset(a[0]);return 0
  if key in ('Hide','Show'):self.actions.append([key.lower(),self.offset(a[0])]);return 1
  if key in ('KillTimer','SetTimer'):self.timers.append([key,*a[1:4]]);return 1
  if key=='SetCurValue':self.progress_value=a[1];return 1
  if key=='RcGetNum':return struct.unpack_from('<I',self.nums,56+4*a[0])[0]
  if key=='RectSet':self.u.mem_write(a[0],struct.pack('<4I',*a[1:5]));return 0
  if key=='VirtualMoveRect':self.offset(a[0]);return 1
  if key=='GetRect':self.u.mem_write(a[1],struct.pack('<4i',0,0,158,89));return 0
  if key=='MImgSet':
   candidates=[(p,o) for p,o in self.objects.items() if p<=a[0]<p+0x400];assert len(candidates)==1
   p,o=candidates[0];self.images.append(dict(widget=o,field=a[0]-p,id=a[1]));return 0
  if key in ('ProccessUserRCInput','SetMuteStatus'):self.actions.append([key,*a[1:4]]);return 1
  if key=='GetSystemTime':return 1000
  if key=='GetTimeDiffFromNow':return 0
  if key in ('MainVolumeUp','MainVolumeDown'):
   self.volume=max(0,min(100,self.volume+(a[1] if key=='MainVolumeUp' else -a[1])))
   if key=='MainVolumeUp':self.muted=False # Explicit service boundary; device manager body not run.
   self.actions.append([key,self.volume]);return 1
  raise AssertionError('Unknown dependency '+key)
 def invalid(self,uc,access,address,size,value,data):raise AssertionError('Guest invalidaccess '+hex(address)+' pc'+hex(uc.reg_read(m.UC_MIPS_REG_PC)))
 def hook(self,uc,address,size,data):
  self.steps+=1
  if self.steps>20000:raise AssertionError('Instruction watchdog')
  if address==STOP:self.done=True;uc.emu_stop();return
  if address in self.boundaries:
   a=[uc.reg_read(r) for r in (m.UC_MIPS_REG_A0,m.UC_MIPS_REG_A1,m.UC_MIPS_REG_A2,m.UC_MIPS_REG_A3)];a.append(self.r32(uc.reg_read(m.UC_MIPS_REG_SP)+16))
   key=self.boundaries[address];self.calls.append(dict(name=key,args=a));v=self.callback(key,a)
   if self.poison:
    for r in (m.UC_MIPS_REG_V1,m.UC_MIPS_REG_A0,m.UC_MIPS_REG_A1,m.UC_MIPS_REG_A2,m.UC_MIPS_REG_A3,m.UC_MIPS_REG_T0,m.UC_MIPS_REG_T1,m.UC_MIPS_REG_T2,m.UC_MIPS_REG_T3,m.UC_MIPS_REG_T4,m.UC_MIPS_REG_T5,m.UC_MIPS_REG_T6,m.UC_MIPS_REG_T7,m.UC_MIPS_REG_T8,m.UC_MIPS_REG_T9,m.UC_MIPS_REG_GP):uc.reg_write(r,0xbad00000+r*4)
   uc.reg_write(m.UC_MIPS_REG_V0,v)
  elif address-4 in self.boundaries:pass
  elif any(lo<=address<hi for lo,hi in [(0xfb8c7c,0xfb9780),(0xfb7d18,0xfb8b30),(0xfb7aec,0xfb7d18),(0xdf8330,0xdf8364),(patch.PREDICATE,patch.PREDICATE+len(patch.code_predicate()))]):self.visited.add(address)
  else:raise AssertionError('Execution outside selected UI paths '+hex(address))
 def run(self,entry,key=0xf04e):
  self.steps=0;self.done=False
  for reg,val in [(m.UC_MIPS_REG_SP,STACK),(m.UC_MIPS_REG_FP,0xabcd001e),(m.UC_MIPS_REG_GP,patch.APP_GP),(m.UC_MIPS_REG_T9,entry),(m.UC_MIPS_REG_RA,STOP),(m.UC_MIPS_REG_A0,FRAME),(m.UC_MIPS_REG_A1,0),(m.UC_MIPS_REG_A2,key if entry==0xfb8c7c else 0),(m.UC_MIPS_REG_A3,0)]:self.u.reg_write(reg,val)
  self.u.emu_start(entry,STOP+4,count=20001)
  assert self.done and self.u.reg_read(m.UC_MIPS_REG_SP)==STACK
  assert self.u.reg_read(m.UC_MIPS_REG_FP)==0xabcd001e
  progress=next(a for a,o in self.objects.items() if o==0x1bc)
  return dict(muted=self.muted,volume=self.volume,mode=self.r32(FRAME+0x214),panel_open=self.panel_open,
      badge_visible=self.badge_visible,actions=self.actions.copy(),images=self.images.copy(),
      fill_colors=[self.r32(progress+f) for f in (0x2a4,0x2a8,0x2ac,0x2b0)],
      calls=self.calls.copy(),timers=self.timers.copy(),steps=self.steps,executed_addresses=[hex(x) for x in sorted(self.visited)],
      scope='actual installed OnKey/Refresh/timeout/predicate instructions; sound/app/surface services modeled',physical_tv_tested=False)
 def run_key(self,key=0xf04e):return self.run(0xfb8c7c,key)
 def run_timeout(self):return self.run(0xfb7aec)
 def run_badge_event(self):return self.run(0xdf8330)

class NativeMuteV77Tests(unittest.TestCase):
 @classmethod
 def setUpClass(cls):
  cls.raw=(ROOT/'analiz/native-ui-candidate/v7.7-tv/overlay'/patch.ELF).read_bytes()
  cls.nums=(ROOT/'analiz/native-ui-candidate/v7.7-tv/overlay'/patch.NUM).read_bytes();cls.results=[]
 def test_real_mute_key_keeps_normal_panel_and_toggle_back(self):
  h=Harness(self.raw,self.nums);a=h.run_key();self.results.append(a)
  self.assertTrue(a['muted']);self.assertTrue(a['panel_open']);self.assertEqual(a['mode'],0)
  self.assertEqual(a['fill_colors'],[0xff898989]*4);self.assertFalse(a['badge_visible'])
  self.assertEqual([x['id'] for x in a['images'] if x['widget']==0x1a8],[680]*4)
  self.assertNotIn(['show',0x180],a['actions']);self.assertIn(['show',0x184],a['actions'])
  b=h.run_key();self.assertFalse(b['muted']);self.assertEqual(b['fill_colors'],[0xff0082d4]*4)
 def test_zero_and_real_mute_timeout_show_badge(self):
  for volume,muted in [(0,False),(0,True),(35,True),(100,True),(1,False),(35,False)]:
   h=Harness(self.raw,self.nums,volume=volume,muted=muted);r=h.run_timeout();self.results.append(r)
   self.assertFalse(r['panel_open']);self.assertEqual(r['badge_visible'],muted or volume==0)
   self.assertEqual(r['muted'],muted)
   if r['badge_visible']:
    h.run_badge_event();self.assertTrue(h.badge_visible)
 def test_reopen_panel_kills_existing_badge_before_show(self):
  h=Harness(self.raw,self.nums,volume=0,existing_badge=True);r=h.run_key(0xf04c);self.results.append(r)
  self.assertFalse(r['badge_visible']);self.assertEqual(r['volume'],1);self.assertEqual(r['mode'],0)
  self.assertLess(r['actions'].index(['badge_kill']),r['actions'].index(['show',0x184]))
 def test_arc_processed_mute_keeps_original_mode3_no_local_toggle(self):
  h=Harness(self.raw,self.nums,arc=True);r=h.run_key();self.results.append(r)
  self.assertEqual(r['mode'],3);self.assertFalse(any(a[0]=='audio_set_mute' for a in r['actions']))
  self.assertTrue(any(a[0]=='ProccessUserRCInput' for a in r['actions']))
 def test_zero_alone_applies_only_to_captured_local_mode0(self):
  for mode in (0,1,2,3):
   for volume in (0,35):
    for muted in (False,True):
     h=Harness(self.raw,self.nums,volume=volume,muted=muted,mode=mode)
     r=h.run_timeout();self.results.append(r)
     self.assertEqual(r['badge_visible'],muted or (mode==0 and volume==0))
     volume_calls=[c for c in r['calls'] if c['name']=='GetMainVolume']
     self.assertEqual(len(volume_calls),int(not muted and mode==0))
 def test_mode_captured_before_parent_kill_no_dead_frame_read(self):
  for mode,poisoned,expected in [(0,0xbad00214,True),(2,0,False),(3,0,False)]:
   h=Harness(self.raw,self.nums,volume=0,muted=False,mode=mode,poison_mode_on_kill=poisoned)
   r=h.run_timeout();self.results.append(r)
   self.assertEqual(r['mode'],poisoned)
   self.assertEqual(r['badge_visible'],expected)
   killtimer=next(c for c in r['calls'] if c['name']=='KillTimer')
   self.assertEqual(killtimer['args'][:2],[FRAME,0])
 def test_mute_key_with_existing_badge_clears_it_and_refreshes_panel(self):
  h=Harness(self.raw,self.nums,volume=35,muted=True,existing_badge=True,mode=1)
  r=h.run_key();self.results.append(r)
  self.assertFalse(r['muted']);self.assertFalse(r['badge_visible']);self.assertEqual(r['mode'],0)
  self.assertIn(['badge_kill'],r['actions']);self.assertIn(['show',0x184],r['actions'])
  self.assertEqual(r['fill_colors'],[0xff0082d4]*4)
 def test_corners_and_predicate_bytes_installed(self):
  n=lambda i:struct.unpack_from('<I',self.nums,56+4*i)[0]
  x=n(0x5b38)+n(0x4219);y=n(0x5b39)+25+30
  self.assertEqual((x,y,n(0x4218),n(0x4217)),(1772,74,64,64));self.assertEqual(1920-x-n(0x4218),84)
  from build_native_volume_patch import elf_va_offset
  at=elf_va_offset(self.raw,patch.PREDICATE,len(patch.code_predicate()))
  self.assertEqual(self.raw[at:at+len(patch.code_predicate())],patch.code_predicate())

if __name__=='__main__':
 result=unittest.TextTestRunner(verbosity=2).run(unittest.defaultTestLoader.loadTestsFromTestCase(NativeMuteV77Tests))
 out=ROOT/'analiz/native-ui-v77/mute';out.mkdir(parents=True,exist_ok=True)
 (out/'native-transitions.json').write_text(json.dumps(dict(passed=result.wasSuccessful(),tests=result.testsRun,
     failures=len(result.failures),errors=len(result.errors),cases=NativeMuteV77Tests.results,
     real_sound_manager_and_device_not_executed=True),ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
 raise SystemExit(not result.wasSuccessful())
