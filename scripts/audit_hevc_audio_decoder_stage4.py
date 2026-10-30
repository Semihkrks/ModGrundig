"""Source-pinned static stage4 audit: no target execution or firmware edits."""
from __future__ import annotations
import hashlib
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools/native-volume-venv/Lib/site-packages'))
from map_mips_calls import Elf32
import capstone

OUT=ROOT/'analiz/native-4k/audio-stage4'
SOURCE={
 'sdk':('07_MSLIB/libMStarSDK.so','00d147f752f92c9706e6496d0cda21de528e81f0c73cac54426b2618c17fe5fb'),
 'customer':('07_MSLIB/libMStarSDK_customer.so','4ebd5fc038a843b26c03b6cb6b44b5e9052820bea388c5d4fc1913b840e83949'),
 'api':('07_MSLIB/utopia/libapiAUDIO.so','d55e76dd24baea83657739e4424982cb8c4b00d90a9144792c1c6b430fe46651'),
}
D=capstone.Cs(capstone.CS_ARCH_MIPS,capstone.CS_MODE_MIPS32|capstone.CS_MODE_LITTLE_ENDIAN)


def sha(raw):return hashlib.sha256(raw).hexdigest()


def run():
    OUT.mkdir(parents=True,exist_ok=True)
    es={}
    for key,(path,digest) in SOURCE.items():
        e=Elf32(ROOT/'analiz/dosya-sistemleri-tam'/path)
        assert sha(e.raw)==digest,path
        es[key]=e
    body_specs={'sdk':[(0x2caaa93c,52)],'customer':[(0x2dc65c6c,228),(0x2dc6ac08,412),(0x2dc65de0,1148)],'api':[(0x2d08ab00,92)]}
    rows=[]

    def export(key,va,size,kind):
        e=es[key];off=e.file_offset(va);raw=e.raw[off:off+size];ins=list(D.disasm(raw,va))
        assert sum(i.size for i in ins)==size
        path=f'{key}-{va:08x}.asm.txt'
        (OUT/path).write_text('\n'.join(f'{i.address:08x}: {i.bytes.hex()} {i.mnemonic} {i.op_str}' for i in ins)+'\n',encoding='utf8')
        row=dict(module=SOURCE[key][0],va=hex(va),bytes=size,sha256=sha(raw),kind=kind,assembly=path)
        rows.append(row)
        return row

    for key,specs in body_specs.items():
        summary=json.loads((OUT/(key+'-v1/summary.json')).read_text())
        assert summary['stored_executable_sha256'].lower()==SOURCE[key][1]
        for va,size in specs:
            report=json.loads((OUT/(key+'-v1')/(f'{va:08x}.json')).read_text())
            assert report['C_export_complete'] and (OUT/(key+'-v1')/(f'{va:08x}.c')).stat().st_size
            row=export(key,va,size,'new_C_export')
            row['name']=report['name']

    # Exact pure enum converters required by SetAudioDec, not added Ghidra runs.
    export('customer',0x2dc634d8,120,'decoder_ID_enum_helper_raw')
    export('customer',0x2dc6625c,88,'DSP_enum_dispatch_raw')
    e=es['customer'];gp=0x2dd16fc0;table=e.u32(gp-0x7fd0)-0x6908
    mapping=[]
    for typ in range(20):
        target=(e.u32(table+4*typ)+gp)&0xffffffff
        vals=[]
        for va in range(target,target+20,4):
            w=e.u32(va)
            if w>>26==9 and (w>>21)&31==0 and (w>>16)&31==2:vals.append(w&65535)
        if typ==3:
            result=None;note='analog SIF configuration-dependent branch; not reduced to a constant'
        else:
            assert vals,hex(target)
            result=vals[0];note='constant from original case instructions'
        mapping.append(dict(input_DSP_enum=typ,target=hex(target),new_API_system_enum=result,basis=note))
        # Selected case words make the dispatch evidence independent of C typing.
        export('customer',target,20,'DSP_enum_selected_case')
    expected={0:1,1:3,2:3,4:4,5:1,6:3,7:3,8:4,18:20,19:20}
    for typ,val in expected.items():assert mapping[typ]['new_API_system_enum']==val

    # Only selected driver dispatcher cases/forwarders, never whole AUDIOIoctl.
    blocks=[(0x2d08c7b8,112,'AUDIOIoctl_table_dispatch_prefix'),
            (0x2d08cbe8,32,'AUDIOIoctl_cmd3d_case'),
            (0x2d08e7a0,20,'AUDIOOpen_callback_assignment'),
            (0x2d080820,56,'inner_IsMadLock_forwarder'),
            (0x2d0807b8,52,'GetCommAudioInfo_forwarder'),
            (0x2d057c14,52,'MDrv_GetCommAudioInfo_forwarder'),
            (0x2d074a14,88,'HAL_GetCommInfo_type0_prefix'),
            (0x2d074b7c,16,'HAL_GetCommInfo_type0_branch'),
            (0x2d074da8,36,'HAL_GetCommInfo_type0_branch'),
            (0x2d075144,8,'HAL_GetCommInfo_type0_selector'),
            (0x2d074bc8,20,'HAL_GetCommInfo_shared_SHM_call')]
    for va,size,label in blocks:export('api',va,size,label)
    closure=[(0x2d082f00,468,'final_GetDecodeSystem_cached_ID_record'),
             (0x2d07f534,376,'final_GetAudioInfo2_ID_forwarder'),
             (0x2d05735c,108,'final_MDrv_GetAudioInfo2_HAL_pointer')]
    for va,size,label in closure:export('api',va,size,label)
    e=es['api'];gp=0x2d23a000;ioctl_table=e.u32(gp-0x7fd0)-0x284
    case=(e.u32(ioctl_table+4*0x3d)+gp)&0xffffffff
    assert case==0x2d08cbe8
    assert e.got_symbols[gp-0x7100]['name']=='_MApi_AUDIO_IsMadLock'
    assert e.u32(0x2d08e7a8)==0xac4400fc  # sw a0,+0xfc(v0)
    assert e.u32(0x2d08cbec)==0x8c5900fc  # callback load
    assert e.u32(0x2d080840)==0x00002021  # GetCommAudioInfo(info0)
    assert e.u32(0x2d074dc8)==0x24040001  # SHM info selector1
    assert e.u32(0x2d075148)==0x00002821  # SHM decoder/bank selector0
    assert e.got_symbols[gp-0x7bdc]['name']=='HAL_DEC_R2_Get_SHM_INFO'
    assert e.u32(0x2d082f70)==0x00112140  # sll a0,s1,5
    assert e.u32(0x2d082f68)==0x00111080  # sll v0,s1,2: combined stride36
    assert e.u32(0x2d07f594)==0x02602021  # original decoder ID forwarded in a0
    assert e.got_symbols[gp-0x73a0]['name']=='g_FuncPrt_Hal_GetAudioInfo2'

    def route(main,secondary,processor):
        if main==-1 and secondary==-1:return 'legacy_one_argument_DSP_switch'
        selected=main if processor==0 else secondary if processor==1 else -1
        if selected==-1:return 'no_DSP_switch'
        if selected==3:return 'SetAudioDec_rejects_ID3'
        return f'SetAudioDec_ID{selected}'
    inputs=[(-1,-1,0,'legacy_one_argument_DSP_switch'),(1,-1,0,'SetAudioDec_ID1'),
            (-1,2,0,'no_DSP_switch'),(1,2,1,'SetAudioDec_ID2'),
            (1,-1,1,'no_DSP_switch'),(1,2,2,'no_DSP_switch'),(3,2,0,'SetAudioDec_rejects_ID3')]
    cases=[]
    for main,secondary,processor,expected_route in inputs:
        result=route(main,secondary,processor);assert result==expected_route
        cases.append(dict(main_id=main,secondary_id=secondary,processor=processor,result=result))
    result=dict(schema_version=1,offline_static_only=True,target_executed=False,patch_proposed=False,
      sources={path:digest for path,digest in SOURCE.values()},
      observation=dict(installed_audio_test=True,update_completed_100_percent=True,restarted=True,
        both_reported_tracks_silent=True,helper_executed=None,MAD_lock=None,live_PID_or_codec=None),
      counts=dict(new_C_exports=5,enum_dispatch_rows=20,decoder_ID_host_cases=7,
        selected_driver_blocks=len(blocks),final_closure_raw_functions=len(closure),final_closure_new_C=0),
      evidence=rows,main_processor_route=dict(processor=0,ID_field='audio_object+0x12c',
        secondary_ID_field='+0x130',DSP_status_field='+0x140',virtual_slot='0x58',
        target='mapi_audio_customer::SetAudioDec=0x2dc6ac08',
        API_ID_mapping={'-1':-1,'0':0,'1':1,'2':2,'other':-1},live_initialized_ID=None),
      DSP_enum_mapping=mapping,DSP_enum_table=hex(table),host_route_cases=cases,
      IsMadLock_chain=dict(public='mapi_audio::IsMadLock0x2caaa93c',API='MApi_AUDIO_IsMadLock0x2d08ab00',
        ioctl_command='0x3d',table=hex(ioctl_table),case=hex(case),private_callback_slot='0xfc',
        callback='_MApi_AUDIO_IsMadLock0x2d080820',comm_info_type=0,
        final_read='HAL_DEC_R2_Get_SHM_INFO(info_type1,selector0)',
        decoder_ID_to_SHM_selector_equivalence_proven=False),
      conclusion='Main audio uses runtime decoder-ID APIs when initialized; MAD lock reads fixed SHM selector0. This API distinction does not prove a wrong lock or explain device silence.',
      final_ID_closure=dict(
        GetDecodeSystem='0x2d082f00 reads cached g_AudioVars2+0x98+36*ID and flag+0x9d+36*ID; no HAL selector map',
        GetAudioInfo2='0x2d07f534 forwards ID/infoType/output unmodified to MDrv_AUDIO_GetAudioInfo2',
        MDrv_GetAudioInfo2='0x2d05735c forwards unmodified args through runtime g_FuncPrt_Hal_GetAudioInfo2; null returns0',
        HAL_pointer='BSS0x2d2330cc, runtime assignment/target not proven in this scope',
        HAL_MAD_GetAudioInfo2='Export0x2d072d38 size2264; body deliberately not expanded',
        main_ID_allocation_policy='Fieldread+0x12c proven; allocation writer not inspected, so statically-fixed vs allocation-time policy unresolved',
        decoder_ID_to_SHM_mapping_proven=False),
      next_boundary='Runtime HAL callback g_FuncPrt_Hal_GetAudioInfo2 and decoder-ID-to-SHM selector map; no A2 predicate proven.',
      unresolved=['Live selected Dolby/HE-AAC PMT/DB enum, PIDs and DSP values are unavailable',
        'Main decoder ID allocation/runtime value is not observed',
        'SetAudioDec→SetDecodeSystem returns success1 without validating API return here; actual DSP result unknown',
        'Decoder-ID to fixed SHM selector0 relationship unresolved',
        'GetAudioDecStatus virtual+0x64 prototype known, but no proven hardware lock field or replacement ABI in this scope',
        'No HEVC-specific audio DSP branch found in the selected switch; codec/source enum spaces remain distinct'])
    (OUT/'results.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(status='PASS_STATIC_AUDIT',**result['counts'])))
    return result


if __name__=='__main__':run()
