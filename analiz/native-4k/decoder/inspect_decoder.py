"""Read-only shipped decoder functions; bounded pure helpers only, no firmware process."""
import sys,json,hashlib,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'scripts'));sys.path.insert(0,str(ROOT/'tools/native-volume-venv/Lib/site-packages'))
from map_mips_calls import Elf32
from unicorn import Uc,UC_ARCH_MIPS,UC_MODE_MIPS32,UC_MODE_LITTLE_ENDIAN,UC_HOOK_CODE
from unicorn import mips_const as r
import capstone
E=Elf32(ROOT/'analiz/dosya-sistemleri-tam/07_MSLIB/utopia/libapiVDEC.so')
D=capstone.Cs(capstone.CS_ARCH_MIPS,capstone.CS_MODE_MIPS32|capstone.CS_MODE_LITTLE_ENDIAN)
OUT=Path(__file__).resolve().parent
STOP=0x11000000;DATA=0x10000000;STACK=0x12008000
names=['MApi_VDEC_GetCaps','MDrv_HVD_EX_GetCaps','MDrv_HVD_EX_CHIP_Capability','HAL_VPU_EX_CHIP_Capability','HAL_HVD_EX_GetFrmRateIsSupported','HAL_MVD_GetFrmRateIsSupported','_MApi_VDEC_EX_V2_CheckCaps','MApi_VDEC_EX_V2_GetFreeStream','MApi_VDEC_EX_V2_Init','_HVD_EX_DemuxTS_ParseHEVCSPS']
syms={s['name']:s for s in E.symbols if s['name'] in names}
(OUT/'decoder-disassembly.txt').write_text('\n'.join(f"{name} VA={s['value']:08x} bytes={s['size']}\n"+'\n'.join(f'{i.address:08x}: {i.bytes.hex()} {i.mnemonic} {i.op_str}' for i in D.disasm(E.raw[E.file_offset(s['value']):E.file_offset(s['value'])+s['size']],s['value'])) for name,s in syms.items())+'\n',encoding='utf-8')
def guest():
 u=Uc(UC_ARCH_MIPS,UC_MODE_MIPS32|UC_MODE_LITTLE_ENDIAN)
 off=struct.unpack_from('<I',E.raw,28)[0];sz,num=struct.unpack_from('<HH',E.raw,42)
 for j in range(num):
  k,f,v,p,fs,ms,flags,align=struct.unpack_from('<8I',E.raw,off+j*sz)
  if k==1:
   lo=v&~4095;hi=(v+ms+4095)&~4095;u.mem_map(lo,hi-lo);u.mem_write(v,E.raw[f:f+fs])
 for addr in (STOP,DATA,0x12000000):u.mem_map(addr,0x10000)
 u.reg_write(r.UC_MIPS_REG_SP,STACK);u.reg_write(r.UC_MIPS_REG_RA,STOP)
 return u

def call(u,name,args):
 s=syms[name];va=s['value'];steps=[]
 for reg,val in zip((r.UC_MIPS_REG_A0,r.UC_MIPS_REG_A1,r.UC_MIPS_REG_A2,r.UC_MIPS_REG_A3),args):u.reg_write(reg,val)
 u.reg_write(r.UC_MIPS_REG_T9,va)
 def hook(uc,a,size,data):
  if a==STOP:return
  assert va<=a<va+s['size'],f'Pure helper escaped to {a:x}'
  steps.append(a)
 u.hook_add(UC_HOOK_CODE,hook);u.emu_start(va,STOP,count=5000)
 assert u.reg_read(r.UC_MIPS_REG_SP)==STACK
 return dict(return_value=u.reg_read(r.UC_MIPS_REG_V0),executed_addresses=[hex(a) for a in steps])
caps=[]
for presence in (0,1):
 u=guest();gp=0x2d648428+0xfce18;u.mem_write(gp-0x6ca0,struct.pack('<I',presence));u.mem_write(DATA,b'\xa5')
 a=call(u,'_MApi_VDEC_EX_V2_CheckCaps',[0,16,DATA,0]);a.update(codec16_from_HEVC_player=True,driver_presence_slot_value=presence,support_byte=bytes(u.mem_read(DATA,1))[0]);assert a['support_byte']==0;caps.append(a)
rates=[]
for w,h,rate in [(1920,1080,60000),(1920,1088,60000),(3840,2160,30000),(3840,2160,50000),(3840,2160,60000),(3840,2160,15000)]:
 u=guest();gp=0x2d60feb0+0x135390;u.mem_write(gp-0x7ab8,struct.pack('<I',DATA+0x100));u.mem_write(DATA+0x100,bytes(4))
 a=call(u,'HAL_HVD_EX_GetFrmRateIsSupported',[0,w,h,rate]);expected=int(w*h*rate<=((0x1d<<32)|0xab370000));assert a['return_value']==expected;a.update(width=w,height=h,rate_argument=rate,multiplied_value=w*h*rate,threshold=(0x1d<<32)|0xab370000);rates.append(a)
report=dict(kind='direct shipped MIPS static analysis and selected purehelperinstruction execution, not REA Evidence',firmware_executed=False,original_modified=False,source=dict(path='analiz/dosya-sistemleri-tam/07_MSLIB/utopia/libapiVDEC.so',sha256=hashlib.sha256(E.raw).hexdigest()),function_inventory={n:dict(va=hex(s['value']),bytes=s['size']) for n,s in syms.items()},codec16_capability_cases=caps,frame_rate_arithmetic_cases=rates,limits=['No device or hardware commands. Only complete pure selected function bodies run in Unicorn with syntheticstack/output/debugflag.','Codec16 association proven from libvdplayer HEVC init caller; no SDKheader/schema supplied.','Framerate argumentunits and reachability from HEVC init notproved by these arithmeticcases; do notclaim this alone isASICmaximum.','HEVC10bit/Main10/chroma/resolution hardware limitsunresolved.'])
(OUT/'decoder-evidence.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
print(json.dumps(dict(caps=[(c['driver_presence_slot_value'],c['return_value'],c['support_byte']) for c in caps],rates=[(c['width'],c['height'],c['rate_argument'],c['return_value']) for c in rates])))
