"""Execute only generated helper instructions with explicit synthetic boundaries."""
import json,struct,sys,unittest
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'scripts'));sys.path.insert(0,str(ROOT/'tools/native-volume-venv/Lib/site-packages'))
import native_ui_v76_name as n
from unicorn import Uc,UC_ARCH_MIPS,UC_MODE_MIPS32,UC_MODE_LITTLE_ENDIAN,UC_HOOK_CODE,UC_HOOK_MEM_INVALID
from unicorn import mips_const as m
FRAME=0x10000000;ROOTW=0x10002000;DIGIT=0x10004000;LABEL=0x10006000
MANAGER=0x10008000;CUSTOMER=0x1000a000;CONTROL=0x1000c000
STOP=0x11000000;STUB=0x11001000;STACK=0x12008000
LINE=0x10007000
EVIDENCE=[]
class Harness:
 def __init__(self,*,name='TRT 1',digits='01',typed=1,count=2,manager=True,cast=True,selection=True,route=0,current_route=0,widget=True,frame=True,control=True,name_success=True,new_success=True,poison=True):
  self.cfg=locals();self.uc=Uc(UC_ARCH_MIPS,UC_MODE_MIPS32|UC_MODE_LITTLE_ENDIAN)
  for start,size in [(0x1160000,0x4000),(0x10c0000,0x20000),(FRAME,0x20000),(STOP,0x10000),(0x12000000,0x10000)]:self.uc.mem_map(start,size)
  self.uc.mem_write(n.CREATE,n.code_create());self.uc.mem_write(n.UPDATE,n.code_update());self.uc.mem_map(n.ORIGINAL_TIMER&~4095,4096)
  for va,raw in n.extras():self.uc.mem_write(va,raw)
  self.names={0x10010000:digits};self.texts={};self.live=set(self.names);self.calls=[];self.invalidates=[];self.created=[];self.destroyed=[];self.registry={3:LABEL,4:LINE} if widget else {};self.added=[];self.timers={};self.timer_events=[];self.moves=[];self.forwarded=[];self.flags=[];self.shown=[];self.callbacks={};self.last=None
  self.w32(FRAME+0x180,ROOTW);self.uc.mem_write(FRAME+0x1a2,struct.pack('<HB',typed,count))
  for obj,vtable in [(LINE,FRAME+0x13000),(ROOTW,FRAME+0x3000),(MANAGER,FRAME+0x9000),(CUSTOMER,FRAME+0xb000),(CONTROL,FRAME+0xd000)]:self.w32(obj,vtable)
  for i,key in enumerate(k for k in n.GOT if k not in ('nothrow_object','ManagerRTTI','CustomerRTTI')):
   address=STUB+16*i;self.uc.mem_write(address,struct.pack('<II',0x03e00008,0));self.w32(n.GOT[key],address);self.callbacks[address]=key
  self.w32(n.GOT['nothrow_object'],FRAME+0x14000);self.w32(n.GOT['ManagerRTTI'],FRAME+0x15000);self.w32(n.GOT['CustomerRTTI'],FRAME+0x16000)
  for i,(obj,slot,key) in enumerate([(ROOTW,0x34,'AddChild'),(CUSTOMER,0x4c,'GetName'),(CONTROL,0x1b8,'GetRoute'),(LINE,0x24,'MoveLine')]):
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
  if key=='GetWidget':assert a[0]==FRAME and a[1] in (3,4);return self.registry.get(a[1],0)
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
  if key=='Invalidate':self.invalidates.append(a[0]);return 0
  if key=='new_nothrow':
   assert a[0] in (0x258,0x264) and a[1]==FRAME+0x14000
   return (LABEL if a[0]==0x258 else LINE) if c['new_success'] else 0
  if key=='TextBox':
   assert a[0]==LABEL and a[1]==ROOTW and a[3]==0 and a[4]==3
   rect=struct.unpack('<4I',self.uc.mem_read(a[2],16));assert rect==n.RECT;self.new_rect=rect;return LABEL
  if key=='AbsContainer':
   assert a[:2]==[LINE,ROOTW] and a[3:]==[0,4]
   rect=struct.unpack('<4I',self.uc.mem_read(a[2],16));assert rect==n.LINE_RECT
   self.uc.mem_write(LINE+0x1c,struct.pack('<4I',*rect));return LINE
  if key=='StringAssign':
   ptr=a[0]-4;assert ptr in self.live
   raw=bytearray()
   for i in range(24):
    b=self.uc.mem_read(a[1]+i,1)
    if b==b'\0':break
    raw.extend(b)
   else:raise AssertionError('Unterminated native fallback')
   self.names[ptr]=bytes(raw).decode('utf-8');return a[0]
  if key=='SetTimer':
   assert a[0]==FRAME
   assert a[1:4] in ([3000,0,0],[2000,1,0],[50,2,0])
   self.timer_events.append(('set',*a[:4]));self.timers[a[2]]=a[1];return 1
  if key=='KillTimer':
   assert a[:2]==[FRAME,2];self.timer_events.append(('kill',*a[:2]));self.timers.pop(2,None);return 1
  if key=='MoveLine':
   assert a[:3]==[LINE,n.LINE_RECT[0],n.LINE_RECT[1]]
   rect=struct.unpack('<4I',self.uc.mem_read(a[3],16))
   assert rect[:2]==n.LINE_RECT[:2] and rect[3]==4 and 0<=rect[2]<=254
   self.uc.mem_write(LINE+0x1c,struct.pack('<4I',*rect));self.moves.append(rect);return 1
  if key=='SetFlag':self.flags.append(a[:3]);return 0
  if key=='AddChild':
   assert a[0]==ROOTW and a[1] in (LABEL,LINE)
   self.registry[3 if a[1]==LABEL else 4]=a[1];self.added.append(a[:2]);return 0
  if key=='Show':self.shown.append(a[0]);return 0
  raise AssertionError('Unhandled boundary '+key)
 def hook(self,uc,address,size,data):
  self.steps+=1
  if self.steps>3000:raise AssertionError('Watchdog')
  if address==n.ORIGINAL_TIMER+12:
   a=[uc.reg_read(reg) for reg in (m.UC_MIPS_REG_A0,m.UC_MIPS_REG_A1,m.UC_MIPS_REG_A2,m.UC_MIPS_REG_A3)]
   assert uc.reg_read(m.UC_MIPS_REG_T9)==n.ORIGINAL_TIMER
   assert uc.reg_read(m.UC_MIPS_REG_GP)==n.APP_GP
   self.forwarded.append(a);self.done=True;uc.emu_stop();return
  if address==STOP:self.done=True;uc.emu_stop();return
  if address in self.callbacks:
   key=self.callbacks[address];a=[uc.reg_read(x) for x in (m.UC_MIPS_REG_A0,m.UC_MIPS_REG_A1,m.UC_MIPS_REG_A2,m.UC_MIPS_REG_A3)];a.append(self.r32(uc.reg_read(m.UC_MIPS_REG_SP)+16));self.calls.append(dict(name=key,args=a));v=self.callback(key,a)
   if self.cfg['poison']:
    for reg in (m.UC_MIPS_REG_V1,m.UC_MIPS_REG_A0,m.UC_MIPS_REG_A1,m.UC_MIPS_REG_A2,m.UC_MIPS_REG_A3,m.UC_MIPS_REG_T0,m.UC_MIPS_REG_T1,m.UC_MIPS_REG_T2,m.UC_MIPS_REG_T3,m.UC_MIPS_REG_T4,m.UC_MIPS_REG_T5,m.UC_MIPS_REG_T6,m.UC_MIPS_REG_T7,m.UC_MIPS_REG_T8,m.UC_MIPS_REG_T9,m.UC_MIPS_REG_GP):uc.reg_write(reg,0xbad00000+reg*4)
   uc.reg_write(m.UC_MIPS_REG_V0,v)
  elif any(address==a+4 for a in self.callbacks):pass
  elif not any(base<=address<base+len(raw) for base,raw in [(n.CREATE,n.code_create()),(n.UPDATE,n.code_update()),*n.extras()]):raise AssertionError(f'Execution escaped helper {address:x}')
 def run(self,which='update',*,duration=3000,timerid=2):
  self.steps=0;self.done=False;u=self.uc
  initial={m.UC_MIPS_REG_S0:0xabc00010,m.UC_MIPS_REG_S1:0xabc00011,m.UC_MIPS_REG_S2:0xabc00012,m.UC_MIPS_REG_S3:0xabc00013,m.UC_MIPS_REG_S4:0xabc00014,m.UC_MIPS_REG_S5:0xabc00015,m.UC_MIPS_REG_S6:0xabc00016,m.UC_MIPS_REG_S7:0xabc00017,m.UC_MIPS_REG_FP:0xabc0001e,m.UC_MIPS_REG_GP:0x12345678 if which in ('create','tick') else n.APP_GP,m.UC_MIPS_REG_SP:STACK}
  for reg,val in initial.items():u.reg_write(reg,val)
  u.reg_write(m.UC_MIPS_REG_A0,DIGIT if which=='update' else FRAME);u.reg_write(m.UC_MIPS_REG_A1,0x10010000);u.reg_write(m.UC_MIPS_REG_RA,STOP)
  if which=='start':
   u.reg_write(m.UC_MIPS_REG_A1,duration);u.reg_write(m.UC_MIPS_REG_A2,1 if duration==2000 else 0);u.reg_write(m.UC_MIPS_REG_A3,0)
  if which=='tick':
   u.reg_write(m.UC_MIPS_REG_A1,0xfeed);u.reg_write(m.UC_MIPS_REG_A2,timerid);u.reg_write(m.UC_MIPS_REG_A3,0xbeef)
  entry={'update':n.UPDATE,'create':n.CREATE,'start':n.START_TIMER,'tick':n.TICK_TIMER}[which];u.emu_start(entry,STOP+4,count=3001,timeout=1000000)
  assert self.done
  for reg,val in initial.items():
   expected=n.APP_GP if which in ('create','tick','start') and reg==m.UC_MIPS_REG_GP else val
   assert u.reg_read(reg)==expected,f'Callee-saved register changed {reg}'
  result=dict(which=which,typed=self.cfg['typed'],digits=self.cfg['digits'],name=self.texts.get(LABEL),steps=self.steps,return_value=u.reg_read(m.UC_MIPS_REG_V0),boundaries=self.calls.copy(),active_strings=len(self.live),caller_saved_poison=self.cfg['poison'])
  EVIDENCE.append(result);return result

class NameTests(unittest.TestCase):
 def test_actual_utf8_missing_message_and_lookup_error_distinction(self):
  h=Harness(selection=False);h.run();self.assertEqual(h.texts[LABEL],n.UNKNOWN_TEXT);self.assertEqual(h.texts[DIGIT],'01');self.assertEqual(h.created,h.destroyed)
  for options in [dict(manager=False),dict(cast=False),dict(control=False),dict(route=1,current_route=0),dict(name_success=False),dict(count=0),dict(count=5)]:
   h=Harness(**options);h.run();self.assertEqual(h.texts[LABEL],'');self.assertEqual(len(h.live),1)
 def test_native_create_geometry_font_allocations_and_owned_children(self):
  h=Harness(widget=False);h.run('create');self.assertEqual(h.registry,{3:LABEL,4:LINE});self.assertEqual(h.r32(LABEL+0x250),0);self.assertEqual(h.r32(LABEL+0x254),0)
  self.assertEqual([x['args'][0] for x in h.calls if x['name']=='new_nothrow'],[0x258,0x264])
  self.assertEqual(struct.unpack('<4I',h.uc.mem_read(LINE+0x1c,16)),n.LINE_RECT)
  self.assertEqual(h.r32(LINE+0x4c),0xff0082d4)
  h.run();self.assertEqual(h.texts[LABEL],'TRT 1')
 def test_original_timeout_untouched_and_blue_countdown_shrinks(self):
  for duration in (2000,3000):
   h=Harness(widget=False);h.run('create');h.run('update');h.run('start',duration=duration)
   self.assertEqual(h.timer_events[0],('set',FRAME,duration,1 if duration==2000 else 0,0))
   self.assertEqual(h.timers,{1 if duration==2000 else 0:duration,2:50})
   widths=[]
   for _ in range(duration//50):
    h.run('tick');widths.append(h.moves[-1][2])
   self.assertEqual(widths,sorted(widths,reverse=True));self.assertEqual(widths[-1],0);self.assertNotIn(2,h.timers)
   self.assertFalse(h.forwarded);self.assertIn(1 if duration==2000 else 0,h.timers)
   h.run('tick',timerid=1 if duration==2000 else 0)
   self.assertEqual(h.forwarded[-1],[FRAME,0xfeed,1 if duration==2000 else 0,0xbeef]);self.assertNotIn(2,h.timers)
 def test_rapid_digits_reset_cosmetic_no_tuning_delay(self):
  h=Harness(widget=False);h.run('create');h.run('start');h.run('tick');self.assertEqual(h.r32(LABEL+0x250),2950)
  h.run('start',duration=2000);self.assertEqual(h.r32(LABEL+0x250),2000);self.assertEqual(h.moves[-1][2],254)
  h.run('tick',timerid=1);self.assertNotIn(2,h.timers);self.assertEqual(len(h.forwarded),1)
 def test_unknown_timer_preserves_original_noop_and_missing_widgets(self):
  h=Harness();h.run('tick',timerid=99);self.assertEqual(h.forwarded,[[FRAME,0xfeed,99,0xbeef]]);self.assertFalse(h.timer_events)
  h=Harness(widget=False);h.run('start');self.assertEqual(h.timers,{0:3000});self.assertFalse(h.moves)
 def test_name_sequence_and_string_lifetimes(self):
  h=Harness()
  for success,selection,name in [(True,True,'TRT 1'),(False,True,'partial'),(True,False,''),(True,True,'\u00c7a\u011fr\u0131 HD')]:
   h.cfg.update(name_success=success,selection=selection,name=name);h.run()
   self.assertEqual(h.texts[LABEL],name if success and selection else n.UNKNOWN_TEXT if not selection else '')
   self.assertEqual(h.created,h.destroyed);self.assertEqual(len(h.live),1)
 def test_oom_and_zero_state_do_not_add_timers_or_forward_spurious_tick(self):
  h=Harness(widget=False,new_success=False);h.run('create');self.assertEqual(h.registry,{});h.run('start');self.assertEqual(h.timers,{0:3000})
  h=Harness(widget=False);h.run('create');h.run('tick');self.assertFalse(h.forwarded);self.assertFalse(h.moves)
if __name__=='__main__':
 r=unittest.TextTestRunner().run(unittest.defaultTestLoader.loadTestsFromTestCase(NameTests))
 if r.wasSuccessful():
  out=ROOT/'analiz/native-ui-v76/native-name';out.mkdir(parents=True,exist_ok=True)
  (out/'bounded-tests.json').write_text(json.dumps(dict(proof=n.proof(),cases=EVIDENCE,synthetic_names_only=True,limits=['Only generated helper instructions executed; native service/timer/rendering callbacks modeled']),indent=2,ensure_ascii=False)+'\n',encoding='utf-8')
  import capstone
  d=capstone.Cs(capstone.CS_ARCH_MIPS,capstone.CS_MODE_MIPS32|capstone.CS_MODE_LITTLE_ENDIAN)
  (out/'helper-disassembly.txt').write_text('\n'.join(f'{i.address:08x}: {i.bytes.hex()} {i.mnemonic} {i.op_str}' for base,raw in [(n.CREATE,n.code_create()),(n.UPDATE,n.code_update()),*n.extras()] for i in d.disasm(raw,base))+'\n',encoding='utf-8')
 sys.exit(not r.wasSuccessful())
