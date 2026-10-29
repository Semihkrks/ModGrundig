"""Read-only selected playback metadata path; no full TV process/hardware execution."""
import json,struct,sys,hashlib
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'scripts'));sys.path.insert(0,str(ROOT/'tools/native-volume-venv/Lib/site-packages'))
from map_mips_calls import Elf32
import capstone
from unicorn import Uc,UC_ARCH_MIPS,UC_MODE_MIPS32,UC_MODE_LITTLE_ENDIAN,UC_HOOK_CODE
from unicorn import mips_const as r
OUT=Path(__file__).resolve().parent
FILES={'dvb':'07_MSLIB/libmsrv_dvb.so','common':'07_MSLIB/libmsrv_common.so'}
E={k:Elf32(ROOT/'analiz/dosya-sistemleri-tam'/p) for k,p in FILES.items()}
TARGETS={'dvb':[0x2d4d6a08,0x2d4d6e28],'common':[0x2d9da078,0x2d9d7e40,0x2d9d9484,0x2d9d4c30]}
D=capstone.Cs(capstone.CS_ARCH_MIPS,capstone.CS_MODE_MIPS32|capstone.CS_MODE_LITTLE_ENDIAN)
functions=[]
for key,targets in TARGETS.items():
 e=E[key]
 for va in targets:
  s=next(s for s in e.symbols if s['value']==va);raw=e.raw[e.file_offset(va):e.file_offset(va)+s['size']];ins=list(D.disasm(raw,va));words=[int.from_bytes(i.bytes,'little') for i in ins]
  hi=words[0]&65535;lo=words[1]&65535;gp=(va+(hi<<16)+(lo if lo<32768 else lo-65536))&0xffffffff
  refs=[]
  for i,w in zip(ins,words):
   if w>>26==35 and (w>>21)&31==28 and (w>>16)&31==25:
    imm=w&65535;imm=imm if imm<32768 else imm-65536;slot=gp+imm
    if slot in e.got_symbols:refs.append(dict(load_at=hex(i.address),got=hex(slot),symbol=e.got_symbols[slot]['name']))
  functions.append(dict(path=FILES[key],name=s['name'],va=hex(va),bytes=len(raw),sha256=hashlib.sha256(raw).hexdigest(),gp=hex(gp),direct_GOT_call_candidates=refs))
  (OUT/(key+'-'+hex(va)+'.asm.txt')).write_text('\n'.join(f'{i.address:08x}: {i.bytes.hex()} {i.mnemonic} {i.op_str}' for i in ins)+'\n',encoding='utf-8')
def guest(e):
 u=Uc(UC_ARCH_MIPS,UC_MODE_MIPS32|UC_MODE_LITTLE_ENDIAN)
 phoff=struct.unpack_from('<I',e.raw,28)[0];size,count=struct.unpack_from('<HH',e.raw,42)
 for j in range(count):
  k,off,va,pa,fs,ms,flags,align=struct.unpack_from('<8I',e.raw,phoff+j*size)
  if k==1:
   lo=va&~4095;hi=(va+ms+4095)&~4095;u.mem_map(lo,hi-lo);u.mem_write(va,e.raw[off:off+fs])
 for va in [0x10000000,0x11000000,0x12000000]:u.mem_map(va,0x10000)
 u.reg_write(r.UC_MIPS_REG_SP,0x12008000)
 return u
# Actual full-entry prefix + switch, stopped BEFOREaudio/provider calls.
converter=[];e=E['dvb'];gp=0x2d5dfc20;table=e.u32(gp-0x7fd0)+0x4778
for typ,pid in [(x,101) for x in range(8)]+[(5,0x1fff)]:
 u=guest(e);program=0x10000000;out=0x10002000
 u.mem_write(program+0x19,bytes([typ]));u.mem_write(program+0x30,struct.pack('<H',pid));u.mem_write(out,struct.pack('<I',0xbad))
 for reg,val in [(r.UC_MIPS_REG_A0,0x10004000),(r.UC_MIPS_REG_A1,program),(r.UC_MIPS_REG_A2,0x10005000),(r.UC_MIPS_REG_A3,out),(r.UC_MIPS_REG_T9,0x2d4d6a08)]:u.reg_write(reg,val)
 seen=[]
 def hook(uc,va,size,data):
  assert 0x2d4d6a08<=va<0x2d4d6a08+1056;seen.append(va)
 u.hook_add(UC_HOOK_CODE,hook);u.emu_start(0x2d4d6a08,0x2d4d6a64,count=400)
 val=struct.unpack('<I',u.mem_read(out,4))[0]
 if typ==5:assert val==(7 if pid!=0x1fff else 0)
 converter.append(dict(program_video_type=typ,video_pid=pid,output_avinfo_codec=val,executed_addresses=[hex(x) for x in seen]))
# ActualDoStart dispatch block forwards the converter's codec7 to namedSDKfunction.
forward=[];e=E['common'];gp=0x2da91f90;got=gp-0x5854
assert 'SetVdecTypeEN27mapi_video_dtv_cfg_datatype10CODEC_TYPEEh' in e.got_symbols[got]['name']
for control_flag in [0,1]:
 u=guest(e);info=0x10000000;monitor=0x10002000;decoder=0x10004000;stub=0x11000000
 u.mem_write(info,struct.pack('<I',7));u.mem_write(info+0x26,bytes([control_flag]));u.mem_write(monitor+0x138,struct.pack('<I',decoder));u.mem_write(got,struct.pack('<I',stub))
 u.reg_write(r.UC_MIPS_REG_GP,gp);u.reg_write(r.UC_MIPS_REG_S4,info);u.reg_write(r.UC_MIPS_REG_S3,monitor);seen=[]
 def hook(uc,va,size,data):
  assert 0x2d9d92f0<=va<=0x2d9d930c or 0x2d9d9420<=va<=0x2d9d9440;seen.append(va)
 u.hook_add(UC_HOOK_CODE,hook);u.emu_start(0x2d9d92f0,stub,count=100)
 args=[u.reg_read(x) for x in [r.UC_MIPS_REG_A0,r.UC_MIPS_REG_A1,r.UC_MIPS_REG_A2]];assert args==[decoder,7,control_flag]
 forward.append(dict(info_codec=7,control_flag=control_flag,actual_SetVdecType_args=args,executed_addresses=[hex(x) for x in seen]))
report=dict(status='PASS_OFFLINE_SELECTED_NATIVE_BLOCKS',new_functions=len(functions),functions=functions,files={FILES[k]:hashlib.sha256(e.raw).hexdigest() for k,e in E.items()},video_type_switch_table=dict(va=hex(table),case5_target='0x2d4d6cf0'),converter_cases=converter,DoStart_forward_cases=forward,total_bounded_cases=len(converter)+len(forward),
 conclusion='StoredVIDEO_TYPE5→playbackAVInfo7→SDKDTVSetVdecType7 isproven; previousdecoderstageestablished7→VDEC16→EVD. NoHEVCspecificrejectinthismetadataandplaybackpath.',
 limitation='Eventqueuecodec-preservingcopy/dispatchlinks arestaticGOT+memory-flowproof; fullthread/eventloop andhardwaredecode notexecuted. No whole-firmware absenceclaim forotherfilters.')
(OUT/'playback-evidence.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
print(json.dumps(dict(status=report['status'],new_functions=len(functions),bounded_cases=report['total_bounded_cases'],converter=[(x['program_video_type'],x['video_pid'],x['output_avinfo_codec']) for x in converter],forward=forward)))
