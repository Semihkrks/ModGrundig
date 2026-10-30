"""Source-pinned HAL audio lock contract; bounded native tests, all hardware mocked."""
import hashlib,json,struct,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
sys.path[:0]=[str(ROOT/'tools/native-volume-venv/Lib/site-packages')]
from map_mips_calls import Elf32
from unicorn import Uc,UC_ARCH_MIPS,UC_MODE_MIPS32,UC_MODE_LITTLE_ENDIAN,UC_HOOK_CODE
from unicorn import mips_const as m
SHA='d55e76dd24baea83657739e4424982cb8c4b00d90a9144792c1c6b430fe46651'
OUT=ROOT/'analiz/native-4k/audio-stage5-hal'

def run():
 e=Elf32(ROOT/'analiz/dosya-sistemleri-tam/07_MSLIB/utopia/libapiAUDIO.so')
 assert hashlib.sha256(e.raw).hexdigest()==SHA
 syms={s['name']:s for s in e.symbols if not s['imported']}
 get=syms['HAL_MAD_GetAudioInfo2'];convert=syms['HAL_AUDIO_Convert_DecId_to_ADECId'];hardware=syms['HAL_DEC_R2_Get_SHM_INFO']['value'];gvars=syms['g_AudioVars2']['value']
 init=syms['HAL_MAD_Init']['value'];hi=e.u32(init)&65535;lo=e.u32(init+4)&65535
 gp=(init+(hi<<16)+(lo if lo<32768 else lo-65536))&0xffffffff
 words={va:e.u32(va) for va in [0x2d075ea8,0x2d075eb0,0x2d075eb8]}
 assert list(words.values())==[0x8f848c84,0x8f828c60,0xac440000]
 assert e.u32(gp-0x737c)==get['value'] and e.u32(gp-0x73a0)==0x2d2330cc
 phoff=struct.unpack_from('<I',e.raw,28)[0];phsz,phnum=struct.unpack_from('<HH',e.raw,42)
 segments=[struct.unpack_from('<8I',e.raw,phoff+i*phsz) for i in range(phnum)]
 cases=[]
 for dec in [0,1,2]:
  for lock in [0,1,2]:
   u=Uc(UC_ARCH_MIPS,UC_MODE_MIPS32|UC_MODE_LITTLE_ENDIAN);pages=set()
   for seg in segments:
    typ,off,va,_,filesz,memsz,flags,align=seg
    if typ!=1:continue
    for page in range(va&~4095,(va+memsz+4095)&~4095,4096):
     if page not in pages:u.mem_map(page,4096);pages.add(page)
    u.mem_write(va,e.raw[off:off+filesz])
   for start,size in [(0x50000000,0x4000),(0x60000000,0x10000),(0x70000000,0x1000)]:u.mem_map(start,size)
   u.mem_write(gvars,struct.pack('<I',0x50001000)) # mock initialized shared state; no HAL init
   u.mem_write(0x50000100,b'\xaa'*16)
   for reg,value in [(m.UC_MIPS_REG_A0,dec),(m.UC_MIPS_REG_A1,0),(m.UC_MIPS_REG_A2,0x50000100),(m.UC_MIPS_REG_T9,get['value']),(m.UC_MIPS_REG_SP,0x60008000),(m.UC_MIPS_REG_RA,0x70000000)]:u.reg_write(reg,value)
   saved=[m.UC_MIPS_REG_S0,m.UC_MIPS_REG_S1,m.UC_MIPS_REG_S2,m.UC_MIPS_REG_S3,m.UC_MIPS_REG_S4,m.UC_MIPS_REG_S5,m.UC_MIPS_REG_S6,m.UC_MIPS_REG_S7,m.UC_MIPS_REG_FP]
   for i,reg in enumerate(saved):u.reg_write(reg,0x11220000+i)
   seen=[];converter_inputs=[]
   def hook(uc,address,size,data):
    if address==0x70000000:uc.emu_stop();return
    if address==convert['value']:converter_inputs.append(uc.reg_read(m.UC_MIPS_REG_A0))
    if address==hardware:
     args=[uc.reg_read(m.UC_MIPS_REG_A0),uc.reg_read(m.UC_MIPS_REG_A1)];assert args==[1,0],args;seen.append(args)
     uc.reg_write(m.UC_MIPS_REG_V0,lock);uc.reg_write(m.UC_MIPS_REG_PC,uc.reg_read(m.UC_MIPS_REG_RA));return
    assert any(s['value']<=address<s['value']+s['size'] for s in [get,convert]),hex(address)
   u.hook_add(UC_HOOK_CODE,hook);u.emu_start(get['value'],0x70000004,count=2000)
   assert u.reg_read(m.UC_MIPS_REG_PC)==0x70000000
   assert u.reg_read(m.UC_MIPS_REG_V0)==1 # API success is NOT the lock boolean
   expected=int(lock!=0);actual=bytes(u.mem_read(0x50000100,16))
   assert actual==bytes([expected])+b'\xaa'*15,actual
   assert seen==[[1,0]] and converter_inputs==[dec] and u.reg_read(m.UC_MIPS_REG_SP)==0x60008000
   assert all(u.reg_read(reg)==0x11220000+i for i,reg in enumerate(saved))
   cases.append(dict(api_decoder_id=dec,info_type=0,mocked_SHM_value=lock,SHM_read=seen[0],api_success=1,one_byte_lock=expected,other_output_bytes_unchanged=True,callee_saved_stack_preserved=True))
 exports={}
 for runname,va in [('api-v1',0x2d072d38),('api-v1',0x2d06260c),('customer-v1',0x2dc67de4)]:
  f=OUT/runname/f'{va:08x}.c';assert f.is_file();exports[str(f.relative_to(ROOT))]=hashlib.sha256(f.read_bytes()).hexdigest()
 proof=dict(status='PASS_BOUNDED_NATIVE_HAL_CONTRACT',source_sha256=SHA,new_C_exports=3,
  callback_assignment=dict(init=hex(init),gp=hex(gp),words={hex(k):hex(v) for k,v in words.items()},target=hex(get['value']),pointer_address='0x2d2330cc',hardware_init_executed=False),
  all_selected_valid_API_IDs_map_to_ADEC0=True,legacy_SHM_read=[1,0],
  mismatch_hypothesis_supported=False,hardware_executed=False,full_firmware_executed=False,
  initialized_shared_state_mocked=True,hardware_SHM_function_mocked=True,case_count=len(cases),cases=cases,exports=exports,
  distinction='Return value1 means API call success; output onebyte separately means actual lock0/1',
  source_function_hashes={s['name']:hashlib.sha256(e.raw[e.file_offset(s['value']):e.file_offset(s['value'])+s['size']]).hexdigest() for s in [get,convert]},
  limitations=['No actual DSP, PCM, TS or RF data','Valid selected API IDs0/1/2 tested only','Legacy equivalence relies on separately pinned stage4 SHM(1,0) chain'])
 (OUT/'results.json').write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8')
 print(json.dumps({k:proof[k] for k in ['status','new_C_exports','case_count','mismatch_hypothesis_supported']}))
if __name__=='__main__':run()
