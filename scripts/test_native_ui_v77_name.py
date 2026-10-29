"""Execute only generated helper instructions with explicit synthetic boundaries."""
import json,struct,sys,unittest
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'scripts'));sys.path.insert(0,str(ROOT/'tools/native-volume-venv/Lib/site-packages'))
import native_ui_v77_name as n
from unicorn import Uc,UC_ARCH_MIPS,UC_MODE_MIPS32,UC_MODE_LITTLE_ENDIAN,UC_HOOK_CODE,UC_HOOK_MEM_INVALID
from unicorn import mips_const as m
FRAME=0x10000000;ROOTW=0x10002000;DIGIT=0x10004000;LABEL=0x10006000
MANAGER=0x10008000;CUSTOMER=0x1000a000;CONTROL=0x1000c000
STOP=0x11000000;STUB=0x11001000;STACK=0x12008000
EVIDENCE=[]
class Harness:
 def __init__(self,*,name='TRT 1',digits='01',typed=1,count=2,manager=True,cast=True,selection=True,route=0,current_route=0,widget=True,frame=True,control=True,name_success=True,new_success=True,poison=True):
  self.cfg=locals();self.uc=Uc(UC_ARCH_MIPS,UC_MODE_MIPS32|UC_MODE_LITTLE_ENDIAN)
  for start,size in [(0x1160000,0x4000),(0x10c0000,0x20000),(FRAME,0x20000),(STOP,0x10000),(0x12000000,0x10000)]:self.uc.mem_map(start,size)
  self.uc.mem_write(n.CREATE,n.code_create());self.uc.mem_write(n.UPDATE,n.code_update())
  self.names={0x10010000:digits};self.texts={};self.live=set(self.names);self.calls=[];self.invalidates=[];self.created=[];self.destroyed=[];self.registry={3:LABEL} if widget else {};self.added=[];self.flags=[];self.shown=[];self.callbacks={};self.last=None
  self.w32(FRAME+0x180,ROOTW);self.uc.mem_write(FRAME+0x1a2,struct.pack('<HB',typed,count))
  for obj,vtable in [(ROOTW,FRAME+0x3000),(MANAGER,FRAME+0x9000),(CUSTOMER,FRAME+0xb000),(CONTROL,FRAME+0xd000)]:self.w32(obj,vtable)
  for i,key in enumerate(k for k in n.GOT if k not in ('nothrow_object','ManagerRTTI','CustomerRTTI')):
   address=STUB+16*i;self.uc.mem_write(address,struct.pack('<II',0x03e00008,0));self.w32(n.GOT[key],address);self.callbacks[address]=key
  self.w32(n.GOT['nothrow_object'],FRAME+0x14000);self.w32(n.GOT['ManagerRTTI'],FRAME+0x15000);self.w32(n.GOT['CustomerRTTI'],FRAME+0x16000)
  for i,(obj,slot,key) in enumerate([(ROOTW,0x34,'AddChild'),(CUSTOMER,0x4c,'GetName'),(CONTROL,0x1b8,'GetRoute')]):
   address=STUB+0x800+i*16;self.uc.mem_write(address,struct.pack('<II',0x03e00008,0));self.callbacks[address]=key;self.w32(self.r32(obj)+slot,address)
  self.uc.hook_add(UC_HOOK_CODE,self.hook);self.uc.hook_add(UC_HOOK_MEM_INVALID,self.invalid)
 def r32(self,a):return struct.unpack('<I',self.uc.mem_read(a,4))[0]
 def w32(self,a,v):self.uc.mem_write(a,struct.pack('<I',v&0xffffffff))
 def invalid(self,uc,access,address,size,value,data):raise AssertionError(f'Unexpected guest access {address:x} at {uc.reg_read(m.UC_MIPS_REG_PC):x}')
 def callback(self,key,a):
  c=self.cfg
  if key=='SetText':
   assert a[1] in self.live,'Use-after-destroy string'
   self.texts[a[0]]=str(self.names[a[1]])
   return 0x12345678 if a[0]==DIGIT else 0
  if key=='GetParentFrame':assert a[0]==DIGIT;return FRAME if c['frame'] else 0
  if key=='GetWidget':assert a[:2]==[FRAME,3];return self.registry.get(3,0)
  if key=='MStringCtor':
   assert a[0] not in self.live
   self.names[a[0]]='';self.live.add(a[0]);self.created.append(a[0]);self.w32(a[0]+4,FRAME+0x17000);return a[0]
  if key=='MStringDtor':assert a[0] in self.live;self.live.remove(a[0]);del self.names[a[0]];self.destroyed.append(a[0]);return 0
  if key=='GetManager':return MANAGER if c['manager'] else 0
  if key=='dynamic_cast':assert a[:4]==[MANAGER,FRAME+0x15000,FRAME+0x16000,0];return CUSTOMER if c['cast'] else 0
  if key=='GetSel':
   assert a[0]==CUSTOMER and a[1]==c['typed']
   if c['selection']:
    self.uc.mem_write(a[2],struct.pack('<H',42));self.uc.mem_write(a[3],bytes([1]));self.uc.mem_write(a[4],bytes([c['route']]))
   return int(c['selection'])
  if key=='GetControl':return CONTROL if c['control'] else 0
  if key=='GetRoute':assert a[:2]==[CONTROL,0];return c['current_route']
  if key=='GetName':
   assert a[:4]==[CUSTOMER,42,1,c['route']]
   ptr=a[4]-4;assert ptr in self.live
   # Deliberately allow a failing provider to dirty the output, testing reset.
   self.names[ptr]=c['name'] if c['name_success'] else 'partial stale output'
   return int(c['name_success'])
  if key=='StringAssign':
   ptr=a[0]-4;assert ptr in self.live
   raw=bytearray()
   for i in range(24):
    byte=self.uc.mem_read(a[1]+i,1)
    if byte==b'\0':break
    raw.extend(byte)
   else:raise AssertionError('Unterminated fallback literal')
   self.names[ptr]=bytes(raw).decode('utf-8');return a[0]
  if key=='Invalidate':self.invalidates.append(a[0]);return 0
  if key=='new_nothrow':assert a[:2]==[0x250,FRAME+0x14000];return LABEL if c['new_success'] else 0
  if key=='TextBox':
   assert a[0]==LABEL and a[1]==ROOTW and a[3]==0 and a[4]==3
   rect=struct.unpack('<4I',self.uc.mem_read(a[2],16));assert rect==n.RECT;self.new_rect=rect;return LABEL
  if key=='SetFlag':self.flags.append(a[:3]);return 0
  if key=='AddChild':assert a[:2]==[ROOTW,LABEL];self.registry[3]=LABEL;self.added.append(a[:2]);return 0
  if key=='Show':self.shown.append(a[0]);return 0
  raise AssertionError('Unhandled boundary '+key)
 def hook(self,uc,address,size,data):
  self.steps+=1
  if self.steps>3000:raise AssertionError('Watchdog')
  if address==STOP:self.done=True;uc.emu_stop();return
  if address in self.callbacks:
   key=self.callbacks[address];a=[uc.reg_read(x) for x in (m.UC_MIPS_REG_A0,m.UC_MIPS_REG_A1,m.UC_MIPS_REG_A2,m.UC_MIPS_REG_A3)];a.append(self.r32(uc.reg_read(m.UC_MIPS_REG_SP)+16));self.calls.append(dict(name=key,args=a));v=self.callback(key,a)
   if self.cfg['poison']:
    for reg in (m.UC_MIPS_REG_V1,m.UC_MIPS_REG_A0,m.UC_MIPS_REG_A1,m.UC_MIPS_REG_A2,m.UC_MIPS_REG_A3,m.UC_MIPS_REG_T0,m.UC_MIPS_REG_T1,m.UC_MIPS_REG_T2,m.UC_MIPS_REG_T3,m.UC_MIPS_REG_T4,m.UC_MIPS_REG_T5,m.UC_MIPS_REG_T6,m.UC_MIPS_REG_T7,m.UC_MIPS_REG_T8,m.UC_MIPS_REG_T9,m.UC_MIPS_REG_GP):uc.reg_write(reg,0xbad00000+reg*4)
   uc.reg_write(m.UC_MIPS_REG_V0,v)
  elif any(address==a+4 for a in self.callbacks):pass
  elif not any(base<=address<base+len(raw) for base,raw in [(n.CREATE,n.code_create()),(n.UPDATE,n.code_update())]):raise AssertionError(f'Execution escaped helper {address:x}')
 def run(self,which='update'):
  self.steps=0;self.done=False;u=self.uc
  initial={m.UC_MIPS_REG_S0:0xabc00010,m.UC_MIPS_REG_S1:0xabc00011,m.UC_MIPS_REG_S2:0xabc00012,m.UC_MIPS_REG_S3:0xabc00013,m.UC_MIPS_REG_S4:0xabc00014,m.UC_MIPS_REG_S5:0xabc00015,m.UC_MIPS_REG_S6:0xabc00016,m.UC_MIPS_REG_S7:0xabc00017,m.UC_MIPS_REG_FP:0xabc0001e,m.UC_MIPS_REG_GP:0x12345678 if which=='create' else n.APP_GP,m.UC_MIPS_REG_SP:STACK}
  for reg,val in initial.items():u.reg_write(reg,val)
  u.reg_write(m.UC_MIPS_REG_A0,DIGIT if which=='update' else FRAME);u.reg_write(m.UC_MIPS_REG_A1,0x10010000);u.reg_write(m.UC_MIPS_REG_RA,STOP)
  entry=n.UPDATE if which=='update' else n.CREATE;u.emu_start(entry,STOP+4,count=3001,timeout=1000000)
  assert self.done
  for reg,val in initial.items():
   expected=n.APP_GP if which=='create' and reg==m.UC_MIPS_REG_GP else val
   assert u.reg_read(reg)==expected,f'Callee-saved register changed {reg}'
  result=dict(which=which,typed=self.cfg['typed'],digits=self.cfg['digits'],name=self.texts.get(LABEL),steps=self.steps,return_value=u.reg_read(m.UC_MIPS_REG_V0),boundaries=self.calls.copy(),active_strings=len(self.live),caller_saved_poison=self.cfg['poison'])
  EVIDENCE.append(result);return result
class NameTests(unittest.TestCase):
 def test_countdown_completely_removed_native_and_no_extra_state(self):
  import native_ui_v75_name as previous
  self.assertEqual(n.code_create(),previous.code_create());self.assertEqual(n.extras(),[])
  self.assertEqual(len(n.hook_records()),6);self.assertEqual(len(n.unwind_frames()),2)
  self.assertFalse({'SetTimer','KillTimer','AbsContainer'} & set(n.GOT))
  self.assertTrue(all(va not in (0x895808,0x89580c,0x895abc,0x895ac0,0x895af0,0x895af4,0x8968d8,0x8968dc,0x8968e0) for va,_,_ in n.hook_records()))
  h=Harness(widget=False);h.run('create');self.assertEqual(h.registry,{3:LABEL});self.assertEqual(h.added,[[ROOTW,LABEL]])
  self.assertEqual([row['args'][0] for row in h.calls if row['name']=='new_nothrow'],[0x250])
  h.cfg['selection']=False;h.run();self.assertEqual(h.texts[LABEL],n.UNKNOWN_TEXT);self.assertEqual(h.texts[DIGIT],'01')
 def test_success_leadingzero_utf8_and_long_text(self):
  for digits,typed,name in [('01',1,'TRT 1'),('0001',1,'Çağrı Türkçe HD'),('99',99,'日本語放送'),('1234',1234,'X'*500)]:
   h=Harness(digits=digits,typed=typed,count=len(digits),name=name);r=h.run()
   self.assertEqual(h.texts[DIGIT],digits);self.assertEqual(h.texts[LABEL],name);self.assertEqual(r['return_value'],0x12345678);self.assertEqual(len(h.live),1);self.assertEqual(h.created,h.destroyed);self.assertEqual(h.calls[0]['name'],'SetText');self.assertIn(LABEL,h.invalidates)
 def test_failure_and_stale_label_clear(self):
  for options in [dict(manager=False),dict(cast=False),dict(selection=False),dict(control=False),dict(route=1,current_route=0),dict(name_success=False),dict(count=0),dict(count=5)]:
   h=Harness(**options);h.texts[LABEL]='old channel';h.run();self.assertEqual(h.texts[LABEL],n.UNKNOWN_TEXT if options.get('selection') is False else '');self.assertEqual(len(h.live),1)
 def test_missing_widget_or_frame_keeps_digits(self):
  for option in [dict(widget=False),dict(frame=False)]:
   h=Harness(**option);h.run();self.assertEqual(h.texts[DIGIT],'01');self.assertNotIn(LABEL,h.texts);self.assertFalse(h.created)
 def test_create_and_all_font_states(self):
  h=Harness(widget=False);r=h.run('create');self.assertEqual(r['return_value'],0);self.assertEqual(h.registry[3],LABEL);self.assertEqual(h.r32(STACK-0xa0+0x94),n.APP_GP)
  for off in (0x130,0x13c,0x148,0x154):self.assertEqual(h.r32(LABEL+off),0x4b0)
  for off in (0x13a,0x146,0x152,0x15e):self.assertEqual(struct.unpack('<H',h.uc.mem_read(LABEL+off,2))[0],26)
  
  for off in (0x7c,0x80,0x84,0x88):self.assertEqual(h.r32(LABEL+off),0xff527185)
  self.assertEqual(h.r32(LABEL+0x128),0x11);self.assertEqual(h.flags,[[LABEL,2,0],[LABEL,16,0]]);self.assertEqual(h.shown,[LABEL]);self.assertEqual(h.uc.mem_read(LABEL+0x39,1),b'\0')
  h.run('update');self.assertEqual(h.texts[LABEL],'TRT 1');before=len(h.added);h.run('create');self.assertEqual(len(h.added),before)
 def test_create_nothrow_failure_is_noop(self):
  h=Harness(widget=False,new_success=False);h.run('create');self.assertNotIn(3,h.registry);self.assertFalse(h.added);self.assertFalse(h.shown)
 def test_rapid_updates_no_stale_text_or_string_leak(self):
  h=Harness()
  for i in range(20):
   h.cfg['name_success']=i%3!=0;h.cfg['name']='Kanal '+str(i);h.cfg['typed']=i;h.uc.mem_write(FRAME+0x1a2,struct.pack('<H',i));h.run()
   self.assertEqual(h.texts[LABEL],h.cfg['name'] if h.cfg['name_success'] else '');self.assertEqual(len(h.live),1)
if __name__=='__main__':
 r=unittest.TextTestRunner().run(unittest.defaultTestLoader.loadTestsFromTestCase(NameTests))
 if r.wasSuccessful():
  out=ROOT/'analiz/native-ui-v77/native-name';out.mkdir(parents=True,exist_ok=True)
  (out/'bounded-tests.json').write_text(json.dumps(dict(proof=n.proof(),cases=EVIDENCE,synthetic_names_only=True,limits=['Only generated helper instructions executed; all services mocked','Text clipping/rendering and native heap exception behavior not executed']),indent=2,ensure_ascii=False)+'\n',encoding='utf-8')
  import capstone
  d=capstone.Cs(capstone.CS_ARCH_MIPS,capstone.CS_MODE_MIPS32|capstone.CS_MODE_LITTLE_ENDIAN)
  (out/'helper-disassembly.txt').write_text('\n'.join(f'{i.address:08x}: {i.bytes.hex()} {i.mnemonic} {i.op_str}' for base,raw in [(n.CREATE,n.code_create()),(n.UPDATE,n.code_update())] for i in d.disasm(raw,base))+'\n')
 sys.exit(not r.wasSuccessful())
