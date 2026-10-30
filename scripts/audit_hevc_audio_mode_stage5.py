"""Pinned event/mode separation and bounded AVInfo constructor checks."""
import hashlib,json,struct,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
sys.path[:0]=[str(ROOT/'tools/native-volume-venv/Lib/site-packages')]
from map_mips_calls import Elf32
from unicorn import Uc,UC_ARCH_MIPS,UC_MODE_MIPS32,UC_MODE_LITTLE_ENDIAN
from unicorn import mips_const as m
OUT=ROOT/'analiz/native-4k/audio-stage5-mode'
SHA='06bc6252713a159d5a41849f476503b0c60b035954f0c82909750223e1077d21'
def run():
 e=Elf32(ROOT/'analiz/dosya-sistemleri-tam/07_MSLIB/libmsrv_common.so');assert hashlib.sha256(e.raw).hexdigest()==SHA
 words={0x2d98e440:0xa0800026,0x2d9da284:0x24020001,0x2d9da294:0xafa2003c,0x2d9d9fb0:0x24020100,0x2d9d9fc0:0xafa2003c}
 assert all(e.u32(va)==w for va,w in words.items())
 syms={s['value']:s for s in e.symbols if not s['imported'] and s['type']==2}
 exported={}
 for va in [0x2d9d9da4,0x2d9d6d58,0x2d9d7384]:
  p=OUT/'common-v2'/f'{va:08x}.c';assert p.is_file();exported[str(p.relative_to(ROOT))]=hashlib.sha256(p.read_bytes()).hexdigest()
 ctor=syms[0x2d98e3f8];raw=e.raw[e.file_offset(ctor['value']):e.file_offset(ctor['value'])+ctor['size']];cases=[]
 for fill in [0,0xaa,0xff]:
  u=Uc(UC_ARCH_MIPS,UC_MODE_MIPS32|UC_MODE_LITTLE_ENDIAN);u.mem_map(0x2d98e000,0x1000);u.mem_write(ctor['value'],raw);u.mem_map(0x50000000,0x1000);u.mem_write(0x50000100,bytes([fill])*0x40);u.mem_map(0x70000000,0x1000)
  u.reg_write(m.UC_MIPS_REG_A0,0x50000100);u.reg_write(m.UC_MIPS_REG_RA,0x70000000);u.emu_start(ctor['value'],0x70000000,count=100)
  b=bytes(u.mem_read(0x50000100,0x40));assert b[0x26]==0 and b[0x24:0x26]==b'\x01\x01';assert struct.unpack_from('<H',b,0x12)[0]==0x1fff
  cases.append(dict(prefill=fill,mode26=b[0x26],audio_requested=b[0x24],video_requested=b[0x25],audio_pid=struct.unpack_from('<H',b,0x12)[0]))
 dvb=Elf32(ROOT/'analiz/dosya-sistemleri-tam/07_MSLIB/libmsrv_dvb.so');assert hashlib.sha256(dvb.raw).hexdigest()=='93fe7286bb7fb9bf3d33ccf75556985f68666fe485241099c20bb7165bc88d97'
 assert dvb.u32(0x2d4d7048)==0x8f9988fc
 target=dvb.got_symbols[0x2d5dfc20-0x7704]['name'];assert '5StartE' in target and 'Without' not in target
 result=dict(status='PASS_EVENT_MODE_STATIC_AND_NATIVE_CONSTRUCTOR',new_C_exports=3,new_raw_constructor=True,constructor_native_cases=cases,
  source_sha256=SHA,exports=exported,pinned_words={hex(k):hex(v) for k,v in words.items()},
  event_dispatch=dict(normal_start=1,without_dmx_start=256,command_field='+0x20',mode_field='+0x26',fields_are_distinct=True),
  selected_DVB_update_call=dict(call='0x2d4d704c',symbol=target,argument='caller AVInfo passed unchanged as a1'),
  constructor_mode_default=0,converter_mode_write_found=False,
  applied_guard_field='+0xc6',requested_guard_field='+0xfe',
  selected_DoSetMode_behavior='Display/timing setup using GetDispInfo; not the +0x26 producer',
  unresolved=['Every upstream writer of caller AVInfo+0x26','Actual event/mode and requested/applied fields on TV','All customers and active source caller selection'],
  target_hardware_executed=False,whole_firmware_executed=False,firmware_patch=False)
 (OUT/'results.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
 print(json.dumps(dict(status=result['status'],new_C_exports=3,native_constructor_cases=len(cases))))
if __name__=='__main__':run()
