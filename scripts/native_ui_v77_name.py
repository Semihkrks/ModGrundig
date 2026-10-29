"""V7.7 native numeric name plus missing-channel message; no cosmetic timer.

No firmware files are modified here. App GOT/ABI bindings are pinned facts;
external calls remain native at deployment and mocked only in bounded tests.
"""
from __future__ import annotations
import hashlib
import struct
CREATE=0x01160100
UPDATE=0x01160800
APP_GP=0x010cc310
RECT=(1566,206,254,38)
WIDGET_ID=3
UNKNOWN_TEXT="Kay\u0131tl\u0131 kanal yok"
GOT={
 'new_nothrow':0x10c6e6c,'nothrow_object':0x10cc2b0,
 'TextBox':0x10c8c40,'GetWidget':0x10c6f88,'GetParentFrame':0x10cc368,
 'SetFlag':0x10cb13c,'Show':0x10cc98c,'Invalidate':0x10c4e28,
 'SetText':0x10ca418,'MStringCtor':0x10c5d38,'MStringDtor':0x10c6fa8,
 'GetManager':0x10cc370,'dynamic_cast':0x10c6984,
 'ManagerRTTI':0x10ccde0,'CustomerRTTI':0x10c9978,
 'GetSel':0x10cce20,'GetControl':0x10cb5a8,'StringAssign':0x10c90f4,
}
ZERO,V0,V1,A0,A1,A2,A3,T0,T1,T9,S0,S1,S2,S3,S4,S5,S6,GP,SP,FP,RA=0,2,3,4,5,6,7,8,9,25,16,17,18,19,20,21,22,28,29,30,31
class Assembler:
 def __init__(self,base):self.base=base;self.words=[];self.labels={};self.fix=[]
 def emit(self,*words):self.words.extend(words)
 def r(self,rs,rt,rd,fun,sh=0):self.emit((rs<<21)|(rt<<16)|(rd<<11)|(sh<<6)|fun)
 def i(self,op,rs,rt,imm):self.emit((op<<26)|(rs<<21)|(rt<<16)|(imm&0xffff))
 def li(self,rt,value):
  if -32768<=value<=32767:self.i(9,ZERO,rt,value)
  else:self.i(15,ZERO,rt,value>>16);self.i(13,rt,rt,value&0xffff)
 def move(self,rd,rs):self.r(rs,ZERO,rd,0x21)
 def addiu(self,rt,rs,imm):self.i(9,rs,rt,imm)
 def lw(self,rt,off,rs=SP):self.i(35,rs,rt,off)
 def sw(self,rt,off,rs=SP):self.i(43,rs,rt,off)
 def lbu(self,rt,off,rs):self.i(36,rs,rt,off)
 def lhu(self,rt,off,rs):self.i(37,rs,rt,off)
 def sh(self,rt,off,rs):self.i(41,rs,rt,off)
 def sb(self,rt,off,rs):self.i(40,rs,rt,off)
 def label(self,name):
  if name in self.labels:raise ValueError('Duplicate assembler label')
  self.labels[name]=len(self.words)
 def branch(self,op,rs,rt,label):self.fix.append((len(self.words),op,rs,rt,label));self.emit(0,0)
 def beq(self,rs,rt,label):self.branch(4,rs,rt,label)
 def bne(self,rs,rt,label):self.branch(5,rs,rt,label)
 def b(self,label):self.beq(ZERO,ZERO,label)
 def gp(self):self.li(GP,APP_GP)
 def got(self,rt,name):self.lw(rt,GOT[name]-APP_GP,GP)
 def call(self,name):self.gp();self.got(T9,name);self.r(T9,ZERO,RA,9);self.emit(0);self.gp()
 def virtual(self,obj,slot):
  self.lw(T9,0,obj);self.lw(T9,slot,T9);self.r(T9,ZERO,RA,9);self.emit(0);self.gp()
 def prologue(self):
  self.addiu(SP,SP,-0xa0)
  for reg,off in [(RA,0x9c),(FP,0x98),(GP,0x94)]+[(S0+i,0x90-4*i) for i in range(7)]:self.sw(reg,off)
  self.move(FP,SP)
 def epilogue(self,fixed_gp=False):
  for reg,off in [(RA,0x9c),(FP,0x98),(GP,0x94)]+[(S0+i,0x90-4*i) for i in range(7)]:
   if fixed_gp and reg==GP:self.gp()
   else:self.lw(reg,off)
  self.r(RA,ZERO,ZERO,8);self.addiu(SP,SP,0xa0)
 def finish(self):
  for pos,op,rs,rt,label in self.fix:
   if label not in self.labels:raise ValueError('Undefined label '+label)
   disp=self.labels[label]-pos-1
   if not -32768<=disp<32768:raise ValueError('Branch range')
   self.words[pos]=(op<<26)|(rs<<21)|(rt<<16)|(disp&0xffff)
  return struct.pack('<%dI'%len(self.words),*self.words)
def code_create():
 a=Assembler(CREATE);a.prologue();a.gp();a.sw(GP,0x94);a.move(S0,A0)
 a.li(A1,WIDGET_ID);a.call('GetWidget');a.bne(V0,ZERO,'done')
 a.lw(S2,0x180,S0);a.beq(S2,ZERO,'done')
 a.li(A0,0x250);a.gp();a.got(A1,'nothrow_object');a.call('new_nothrow');a.move(S1,V0);a.beq(S1,ZERO,'done')
 for off,value in zip((0x20,0x24,0x28,0x2c),RECT):a.li(V0,value);a.sw(V0,off)
 a.li(V0,WIDGET_ID);a.sw(V0,0x10);a.move(A0,S1);a.move(A1,S2);a.addiu(A2,SP,0x20);a.li(A3,0);a.call('TextBox')
 a.li(V0,0x4b0)
 for off in (0x130,0x13c,0x148,0x154):a.sw(V0,off,S1)
 a.li(V0,26)
 for off in (0x13a,0x146,0x152,0x15e):a.sh(V0,off,S1)
 a.li(V0,0x11);a.sw(V0,0x128,S1);a.sb(ZERO,0x39,S1)
 a.li(V0,0xff527185)
 for off in (0x7c,0x80,0x84,0x88):a.sw(V0,off,S1)
 for flag in (2,0x10):a.move(A0,S1);a.li(A1,flag);a.li(A2,0);a.call('SetFlag')
 a.move(A0,S2);a.move(A1,S1);a.virtual(S2,0x34)
 a.move(A0,S1);a.call('Show')
 a.label('done');a.li(V0,0);a.epilogue(fixed_gp=True);raw=a.finish()
 if CREATE+len(raw)>UPDATE:raise ValueError('CREATE overlaps UPDATE')
 return raw
def code_update():

 a=Assembler(UPDATE);a.prologue();a.move(S0,A0);a.move(S1,A1)

 a.call('SetText');a.sw(V0,0x60) # Preserve the replaced call's return value.

 a.move(A0,S0);a.call('GetParentFrame');a.move(S2,V0);a.beq(S2,ZERO,'done')

 a.move(A0,S2);a.li(A1,WIDGET_ID);a.call('GetWidget');a.move(S3,V0);a.beq(S3,ZERO,'done')

 a.addiu(A0,SP,0x30);a.call('MStringCtor')

 a.lbu(V0,0x1a4,S2);a.beq(V0,ZERO,'commit');a.i(11,V0,V1,5);a.beq(V1,ZERO,'commit')

 a.call('GetManager');a.move(S4,V0);a.beq(S4,ZERO,'commit')

 a.move(A0,S4);a.gp();a.got(A1,'ManagerRTTI');a.got(A2,'CustomerRTTI');a.li(A3,0);a.call('dynamic_cast');a.move(S4,V0);a.beq(S4,ZERO,'commit')

 a.addiu(V0,SP,0x43);a.sw(V0,0x10)

 a.move(A0,S4);a.lhu(A1,0x1a2,S2);a.addiu(A2,SP,0x40);a.addiu(A3,SP,0x42);a.call('GetSel');a.li(V1,1);a.bne(V0,V1,'unknown')

 a.call('GetControl');a.move(S5,V0);a.beq(S5,ZERO,'commit')

 a.move(A0,S5);a.li(A1,0);a.virtual(S5,0x1b8);a.i(12,V0,V0,255);a.lbu(V1,0x43,SP);a.bne(V0,V1,'commit')

 a.addiu(V0,SP,0x34);a.sw(V0,0x10)

 a.move(A0,S4);a.lhu(A1,0x40,SP);a.lbu(A2,0x42,SP);a.lbu(A3,0x43,SP);a.virtual(S4,0x4c)

 a.li(V1,1);a.beq(V0,V1,'commit')

 # A failed provider cannot leave stale or partial names visible.

 a.addiu(A0,SP,0x30);a.call('MStringDtor');a.addiu(A0,SP,0x30);a.call('MStringCtor')

 a.b('commit')

 a.label('unknown')

 literal=UNKNOWN_TEXT.encode('utf-8')+b'\0';literal+=bytes((-len(literal))%4)

 if len(literal)>24:raise ValueError('Fallback literal exceeds verified local buffer')

 for i in range(0,len(literal),4):a.li(V0,struct.unpack_from('<I',literal,i)[0]);a.sw(V0,0x48+i)

 a.addiu(A0,SP,0x34);a.addiu(A1,SP,0x48);a.call('StringAssign')

 a.label('commit');a.move(A0,S3);a.addiu(A1,SP,0x30);a.call('SetText')

 a.move(A0,S3);a.call('Invalidate')

 a.addiu(A0,SP,0x30);a.call('MStringDtor')

 a.label('done');a.lw(V0,0x60);a.epilogue();return a.finish()


def unwind_frames():
 """Loader API: CFA-relative save rules and PC offsets within each function.

 CIE default CFA is SP+0 and RA is31. All helper SP adjustments are explicit.
 CREATE intentionally keeps the saved GP rule during its fixed-GP epilogue.
 No personality/LSDA cleanup is claimed by these FDE-only rules.
 """
 result=[]
 for start,raw in [(CREATE,code_create()),(UPDATE,code_update())]:
  events=[dict(pc=4,cfa_offset=0xa0)]
  words=struct.unpack('<%dI'%(len(raw)//4),raw)
  for idx,word in enumerate(words):
   op,rs,rt,imm=word>>26,(word>>21)&31,(word>>16)&31,word&0xffff
   if idx<12 and op==43 and rs==SP:
    events.append(dict(pc=4*(idx+1),offsets={rt:imm-0xa0}))
   if idx>=len(words)-14 and op==35 and rs==SP and rt in (RA,FP,GP,S0,S1,S2,S3,S4,S5,S6):
    events.append(dict(pc=4*(idx+1),restores=[rt]))
  events.append(dict(pc=len(raw),cfa_offset=0))
  result.append(dict(start=start,size=len(raw),frame_size=0xa0,prologue_end=48,sp_adjust_pc=0,sp_restore_pc=len(raw)-4,events=events,personality=None,lsda=None))
 return result

def extras():return []
def hook_records():
 jal=lambda va:0x0c000000|((va>>2)&0x3ffffff)
 return [(0x8968ac,0x8fdc0018,0x8fc40060),(0x8968b0,0x00001021,jal(CREATE)),
  (0x8957c8,0x8f99e108,jal(UPDATE)),(0x8957cc,0x0320f809,0),
  (0x895a68,0x8f99e108,jal(UPDATE)),(0x895a6c,0x0320f809,0)]
def proof():
 return dict(revision='v7.7-tv',kind='native numeric channel name and missing-channel text; countdown removed',
  create=hex(CREATE),update=hex(UPDATE),app_gp=hex(APP_GP),
  create_size=len(code_create()),update_size=len(code_update()),
  create_sha256=hashlib.sha256(code_create()).hexdigest(),update_sha256=hashlib.sha256(code_update()).hexdigest(),
  widget=dict(id=3,parent='frame+0x180',allocation=0x250,rect=list(RECT),font_id=0x4b0,font_size=26),
  missing_channel=dict(text=UNKNOWN_TEXT,only_on='GetProgramSelInfo returned not1',encoding='UTF-8 std::string::operator=(const char*) via GOT0x10c90f4',other_lookup_errors='clear label'),
  countdown=False,extra_widgets=False,extra_timers=False,private_state_tail=False,
  timers='All original SetTimer/OnTimer bytes and tuning behavior preserved; no hooks or added timer calls',
  hooks=[dict(va=hex(va),old=hex(old),new=hex(new)) for va,old,new in hook_records()],
  got={key:hex(value) for key,value in GOT.items()},unwind_frames=unwind_frames(),
  lifetime='original digit SetText first; name SetText owns copy; normal MString cleanup preserved',
  limits=['Bounded helpers with modeled native callbacks; physicalTV not tested.','No LSDA local cleanup: later native allocation exceptions may leak temporary string/widget resources.'])
