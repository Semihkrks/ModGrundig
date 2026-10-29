"""Bounded static consumer proof, using four retained Ghidra function exports."""
import hashlib,json,re,struct
from pathlib import Path
from map_mips_calls import Elf32
ROOT=Path(__file__).resolve().parents[1]
SOURCE=ROOT/'analiz/dosya-sistemleri-tam/07_MSLIB/libmsrv_dvbs_customer.so'
OUT=ROOT/'analiz/native-4k/transponders'
QUERY=OUT/'consumer-query'
SHA='9c3d825e7162bb36495c9e74ddc345d151e4b8e51e3190f822d25e607b7cd9ed'
elf=Elf32(SOURCE)
assert hashlib.sha256(elf.raw).hexdigest()==SHA
summary=json.loads((QUERY/'summary.json').read_text())
assert summary['stored_executable_sha256']==SHA and summary['processed_count']==summary['decompile_complete_count']==4
functions={};assembly=[];calls=[]
for address in ['2e9665a8','2e9666dc','2e967260','2e9674d4']:
 d=json.loads((QUERY/(address+'.json')).read_text());entry=int(address,16)
 words=struct.unpack_from('<3I',elf.raw,elf.file_offset(entry))
 assert words[0]>>16==0x3c1c and words[1]>>16==0x279c and words[2]==0x0399e021
 immediate=words[1]&0xffff;immediate=immediate-65536 if immediate&0x8000 else immediate
 gp=(entry+((words[0]&0xffff)<<16)+immediate)&0xffffffff
 functions[address]=dict(name=d['name'],body_bytes=d['body_bytes'],instruction_count=d['instruction_count'],decompile_complete=d['decompile_complete'],gp=hex(gp),gp_basis='PIC entry t9==function entry; first3 original instructions')
 assembly.append('\n'+d['name']+' '+address)
 load=None
 for index,row in enumerate(d['instructions']):
  inst=row['instruction'].lstrip('_');assembly.append(row['address']+' '+row['instruction'])
  m=re.match(r'lw t9,(-?0x[0-9a-f]+)\(gp\)',inst)
  if m:load=(index,gp+int(m.group(1),16),row['address'])
  elif inst.startswith(('lw t9,','move t9,')):load=None
  elif inst=='jalr t9':
   if load and index-load[0]<=12:
    slot=load[1];symbol=elf.got_symbols.get(slot)
    if symbol:calls.append(dict(function=address,callsite=row['address'],load=load[2],got_slot=hex(slot),symbol=symbol['name'],symbol_value=hex(symbol['value']),symbol_imported=symbol['imported'],basis='original GOT slot to linked dynamic symbol; runtime loader implementation not executed'))
   load=None
vt=[]
for slot in (0x3c,0x40,0x44,0x6c,0x78,0xc0,0xc4,0xcc,0xd8,0xdc):
 at=0x2e99d108+slot;target=elf.u32(at);symbol=next(s for s in elf.symbols if s['value']==target and s['type']==2)
 vt.append(dict(slot=hex(slot),entry_va=hex(at),file_offset=hex(elf.file_offset(at)),target=hex(target),symbol=symbol['name'],basis='raw original Customer-class vtable; actual virtual call target conditional on runtimevptr'))
commands=[]
for off in (0x417e8,0x4182c):
 raw=elf.raw[off:elf.raw.index(0,off)];commands.append(dict(file_offset=hex(off),va=hex(0x2e940000+off),text=raw.decode('ascii'),executed=False))
proof=dict(date='2026-10-27',module=str(SOURCE.relative_to(ROOT)),sha256=SHA,kind='direct Ghidra static analysis + original ELF GOT/vtable validation; not REA Evidence',functions=functions,got_bound_calls=calls,got_callsite_count=len(calls),vtable=vt,commands_as_data_only=commands,
 lifecycle=[dict(entry='0x2e9674d4 Init',condition='4-byte primary SAT storage header matches embedded format version; both sat/TP bitmap loads succeed',result='LoadCur, occupied LoadSat slots0..23 and occupied LoadTp slots0..2999; return without archive/XML'),dict(entry='0x2e9674d4 Init',condition='primary header read fails, header mismatches, or either bitmap load fails',result='virtualslot+0x3c targets ResetSatDB for original Customer vtable'),dict(entry='0x2e9666dc ResetSatDB',condition='global vSatList vector empty',result='LoadSatelliteListfromXML; then rebuild SAT database'),dict(entry='0x2e9666dc ResetSatDB',condition='global vSatList already populated',result='skip new tar/XML load; still clear/rebuild using cached list'),dict(entry='0x2e9665a8 LoadSatelliteListfromXML',condition='called',result='system(tar→USR_DB),system(tar→BACKUP_DB), sync only ifbothsuccess; Process_Loader(this,1) on BOTH success/failure; returns1always'),dict(entry='0x2e967260 ReloadSatList',condition='called',result='Finalize/Init both storage objects; readprimary header/bitmap and loadexisting SAT rows; failureprints warning but no ResetSatDB/archivecall in this body')],
 reset_effects=dict(clear_calls=['0x2e96678c primary storage this+0x84','0x2e96679c backup storage this+0x88'],format_header_write='0x2e9667bc 4bytes atoffset0',save_all='0x2e966b08',current_sat_reset0='0x2e966b1c virtual+0x6c',current_tp_reset0='0x2e966b30 virtual+0x78',satellite_limit=24,per_sat_tp_loop_limit=254),
 prototype_corrections=[dict(function='0x2e9665a8',issue='Decompiler wrongly types GetInstance return as uchar and hides Process_Loader argument',assembly='0x2e9665ec moves fullv0→s2;0x2e966668→6674 and66ac→66b8 set a0=s2,a1=1; GOT symbol Process_Loader(unsignedchar) is a nonstatic member(this,1)'),dict(function='0x2e9674d4',issue='Decompiler mapi_storage::Read argument display is misleading',assembly='0x2e9675e0..760c: a0=primary storage,a1=0offset,a2=stack18buffer,a3=4bytes; no target read was performed')],
 conclusion='Replacing APP/defaults/frequency_tables.tar.gz alone does not merge new transponders into an alreadyvalid persistent SAT DB. ResetSatDB is destructive to SAT storage/current selections and was NOT invoked.',
 unresolved=['Normal startup framework caller of Init not traced within four-function budget','Factory-reset/first-install UI callers of ResetSatDB not traced; function name is not evidence of a specific UI gesture','Process_Loader implementation/XML path parsing not decompiled here; only importedmembercall and reset use of globalvSatList verified','Actual device primary/backup DB validity/version and existing TP lists not read'],target_executed=False,commands_executed=False,device_access=False,database_modified=False)
(OUT/'consumer-proof.json').write_bytes((json.dumps(proof,ensure_ascii=False,indent=2)+'\n').encode('utf-8'))
(OUT/'consumer-assembly.txt').write_bytes(('\n'.join(assembly)+'\n').encode('utf-8'))
print(json.dumps(dict(functions=4,decompiled=4,got_bound_calls=len(calls),class_vtable_slots=len(vt),original_sha256=SHA)))
