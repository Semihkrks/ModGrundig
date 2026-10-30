"""V7.9-only test composition: guarded HEVC live-TV audio recovery.

Pure byte transformation of the pinned, unmodified libmsrv_common.so. The
library is identical in the V7.9 MSLIB payload. The APP/firmware are not edited.
"""
from __future__ import annotations
import hashlib
import json
import struct
from pathlib import Path

from native_ui_v75_name import Assembler, ZERO, V0, V1, A0, A1, A2, T9, S0, GP, SP, RA

ROOT = Path(__file__).resolve().parents[1]
INPUT_SHA = '06bc6252713a159d5a41849f476503b0c60b035954f0c82909750223e1077d21'
BASE_APP_SHA = '861d97c013c4d56e093a69cf779abfa6ea78e6c17233af5d6b2b3ba075b0b4ea'
ENTRY = 0x2d9d6124
HELPER = 0x2d957000
HELPER_LIMIT = HELPER + 0x800
CANONICAL_GP = 0x2da91f90
GOT = {'time': -0x775c, 'frame_count': -0x6228, 'mad_lock': -0x5090, 'set_mute': -0x629c}
OLD_WORDS = (0x3c1c000c, 0x279cbe6c, 0x0399e021, 0x27bdffe0,
             0xafbf001c, 0xafb00018, 0xafbc0010, 0x8f9988a4)
NORMAL_AUDIO_MASK = 0x1a0ce
OTHER_AUDIO_REASONS = NORMAL_AUDIO_MASK & ~2


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def va_offset(raw, va, length=4):
    if raw[:6] != b'\x7fELF\x01\x01' or struct.unpack_from('<H',raw,18)[0] != 8:
        raise ValueError('Expected ELF32 little-endian MIPS')
    ph, = struct.unpack_from('<I', raw, 28)
    es, count = struct.unpack_from('<HH', raw, 42)
    for idx in range(count):
        typ, off, start, _, size, _, flags, _ = struct.unpack_from('<8I',raw,ph+es*idx)
        if typ == 1 and start <= va and va+length <= start+size:
            return off+va-start
    raise ValueError(f'VA is not file backed: {va:#x}')


def trampoline():
    # Original PIC prologue computes gp from the actual runtime t9. Derive the
    # helper runtime address from that gp, so rebased ET_DYN loads still work.
    delta = HELPER-CANONICAL_GP
    hi = (delta+0x8000) >> 16
    lo = delta & 0xffff
    return struct.pack('<8I',*OLD_WORDS[:3],
        (15<<26)|(T9<<16)|(hi&0xffff),
        (9<<26)|(T9<<21)|(T9<<16)|lo,
        (T9<<21)|(GP<<16)|(T9<<11)|0x21,
        (T9<<21)|8, 0)


def helper_code():
    a = Assembler(HELPER)
    # Same 0x20 frame and saved registers as the original CheckAudioStatus.
    # gp was computed by the original entry's PIC prologue, not a fixed VA.
    a.addiu(SP,SP,-0x20); a.sw(RA,0x1c); a.sw(S0,0x18); a.sw(GP,0x10)
    a.move(S0,A0)

    def call(name):
        a.lw(T9,GOT[name],GP); a.r(T9,ZERO,RA,9); a.emit(0); a.lw(GP,0x10)

    call('time')
    # Preserve the original absolute time-difference calculation exactly.
    a.lw(V1,0x84,S0)
    a.r(V1,V0,A1,0x23); a.r(V1,V0,A0,0x2b)
    a.r(V0,V1,V0,0x23); a.r(A1,A0,V0,0x0a)
    a.i(11,V0,V0,2001); a.bne(V0,ZERO,'done')
    a.lbu(V0,0x6e,S0); a.bne(V0,ZERO,'done')
    a.lbu(V0,0x92,S0); a.bne(V0,ZERO,'native_recovery')

    # Extension only: live main DVB monitor storing HEVC enum7.
    a.lw(V0,0xa0,S0); a.li(V1,7); a.bne(V0,V1,'done')
    a.lw(V0,0xc,S0); a.li(V1,0x1c); a.bne(V0,V1,'done')
    a.lw(V0,0x1c8,S0); a.bne(V0,ZERO,'done')
    a.lbu(V0,0x1be,S0); a.bne(V0,ZERO,'done')
    a.lbu(V0,0xc6,S0); a.bne(V0,ZERO,'done')
    a.lbu(V0,0x110,S0); a.beq(V0,ZERO,'done')
    a.lbu(V0,0x111,S0); a.beq(V0,ZERO,'done')
    a.lhu(V0,0xb2,S0); a.li(V1,0x1fff); a.beq(V0,V1,'done')
    a.lw(V0,0xa4,S0); a.li(V1,0xff); a.beq(V0,V1,'done')
    # A fallback is only for mute reason2. Other audio reasons are not removed
    # or bypassed, including native mask0x80's special-case behavior.
    a.lw(V0,0x68,S0); a.i(12,V0,V1,2); a.beq(V1,ZERO,'done')
    a.li(V1,OTHER_AUDIO_REASONS); a.r(V0,V1,V0,0x24); a.bne(V0,ZERO,'done')
    a.lw(A0,0x138,S0); a.beq(A0,ZERO,'done')
    call('frame_count'); a.bne(V0,ZERO,'done')

    a.label('native_recovery')
    a.move(A0,S0); call('mad_lock'); a.beq(V0,ZERO,'mark_tried')
    a.sw(ZERO,0x84,S0)
    a.move(A0,S0); a.li(A1,0); a.li(A2,2); call('set_mute')
    a.label('mark_tried'); a.li(V0,1); a.sb(V0,0x113,S0)
    a.label('done'); a.lw(RA,0x1c); a.lw(S0,0x18)
    a.r(RA,ZERO,ZERO,8); a.addiu(SP,SP,0x20)
    result = a.finish()
    if HELPER+len(result)>HELPER_LIMIT:
        raise ValueError('Helper exceeds verified zero region')
    return result


def apply(original):
    if sha(original) != INPUT_SHA:
        raise ValueError('Exact original/V7.9 MSLIB library hash required')
    hook = va_offset(original,ENTRY,len(trampoline()))
    cave = va_offset(original,HELPER,HELPER_LIMIT-HELPER)
    if original[hook:hook+32] != struct.pack('<8I',*OLD_WORDS):
        raise ValueError('Original CheckAudioStatus words differ')
    if original[cave:cave+HELPER_LIMIT-HELPER] != bytes(HELPER_LIMIT-HELPER):
        raise ValueError('Helper region is not original zero padding')
    ph, = struct.unpack_from('<I',original,28); es,count=struct.unpack_from('<HH',original,42)
    segments = [struct.unpack_from('<8I',original,ph+es*i) for i in range(count)]
    if not any(p[0]==1 and p[6]==5 and p[2]<=HELPER and HELPER_LIMIT<=p[2]+p[4] for p in segments):
        raise ValueError('Helper is not in existing R-X PT_LOAD')
    sh, = struct.unpack_from('<I',original,32); ss,sn=struct.unpack_from('<HH',original,46)
    for idx in range(sn):
        s=struct.unpack_from('<10I',original,sh+ss*idx)
        if s[1]!=8 and s[5] and s[3]<HELPER_LIMIT and HELPER<s[3]+s[5]:
            raise ValueError('Helper overlaps an existing ELF section')
    raw = bytearray(original); code=helper_code()
    raw[hook:hook+32]=trampoline(); raw[cave:cave+len(code)]=code
    output=bytes(raw)
    allowed=[dict(offset=hook,size=32,va=hex(ENTRY),kind='PIC entry trampoline'),
             dict(offset=cave,size=len(code),va=hex(HELPER),kind='existing zero RX section gap')]
    changed=[i for i,(x,y) in enumerate(zip(original,output)) if x!=y]
    if any(not any(a['offset']<=i<a['offset']+a['size'] for a in allowed) for i in changed):
        raise ValueError('Changed bytes outside allowlist')
    proof=dict(schema_version=1,kind='V7.9 HEVC live-TV audio recovery test',input_sha256=INPUT_SHA,
      output_sha256=sha(output),base_app_sha256=BASE_APP_SHA,bytes=len(output),
      helper_va=hex(HELPER),helper_size=len(code),helper_sha256=sha(code),allowlist=allowed,
      old_entry_words=[hex(x) for x in OLD_WORDS],new_entry_words=[hex(x) for x in struct.unpack('<8I',trampoline())],
      changed_byte_count=len(changed),elf_size_headers_sections_dynamic_metadata_unchanged=True,
      load_bias_independent=True,timeout='original absolute delta >2000 ms',
      unchanged_native_gate='sync_pending+0x6e ==0; ready92!=0 path remains original recovery',
      fallback_guards=['stored codec7','source0x1c','main window0','live/no PVR(+0x1be==0)',
        'normal demux mode(+0xc6==0)',
        'video_started and audio_started','valid audio PID and codec','mute2 present',
        'no other native audio mask reason','non-null decoder','actual native GetFrameCnt()==0',
        'actual native IsMadLock()!=0'],
      original_mute_call=dict(function='MW_DTV_AVMonitor::SetMuteFlag',arguments=['this',0,2]),
      mute_masks=dict(normal_audio=hex(NORMAL_AUDIO_MASK),alternative_audio='0x15002',
        other_audio_guard=hex(OTHER_AUDIO_REASONS),removed_only='0x2',
        preserved_examples=['video mute0x1','video status0x20','every other mask bit']),
      no_pcr_pid_rewrite=True,no_decoder_success_forcing=True,no_volume_or_user_mute_setting_write=True,
      source_field_evidence=dict(
        constructor='0x2d9d4db4: window parameter stored+0x1c8; window0 sets input identifier+0xc=0x1c, window1=0x25',
        stored_info='DoStart0x2d9d7e40 final copy: AVInfo+0 maps monitor+0xa0, audio PID+0x12 maps+0xb2, input mode+0x26 maps+0xc6',
        playback_flag='Start0x2d9da078 stores incoming control to+0x1be; old1/new0 rejection prints Ignore live pmt change in PVR playback mode',
        monitor_mode_gate='DoMonitor0x2d9d6d04 reads AVInfo+0x26 and skips CheckAudioStatus when nonzero',
        got_targets={'GetTime0':'gp-0x775c','mapi_vdec::GetFrameCnt':'gp-0x6228',
                     'MW_DTV_AVMonitor::IsMadLock':'gp-0x5090','MW_DTV_AVMonitor::SetMuteFlag':'gp-0x629c'}),
      abi=dict(stack_size=32,saved=['ra','s0','gp'],callee_saved_untouched=['s1..s7','fp'],
        native_calls='GOT t9, gp restored after each call',trampoline='gp-relative PIC jr t9, no absolute J26'),
      limits=['Test candidate, no physical TV success claim',
        'Native helper external calls are mocked only in bounded tests',
        'Existing FDE/unwind tables are unchanged; the added helper has no FDE. An exception or asynchronous unwind inside it is not supported',
        'Audio MAD lock and zero video frames are native readiness tests, not measured PCM output or a UHD video fix',
        'User mute setting is not written; physical remote mute/unmute and volume0 behavior still require the TV test',
        'Fallback excludes PVR/file-in playback and sub-window; live HEVC test only'])
    return output,proof


def write_candidate():
    app=ROOT/'analiz/native-ui-candidate/v7.9-tv/overlay/08_APP/bin/dvbt_board'
    if sha(app.read_bytes())!=BASE_APP_SHA:
        raise ValueError('V7.9 APP identity changed')
    source=ROOT/'analiz/dosya-sistemleri-tam/07_MSLIB/libmsrv_common.so'
    result,proof=apply(source.read_bytes())
    out=ROOT/'analiz/native-4k/audio-test'; out.mkdir(parents=True,exist_ok=True)
    (out/'libmsrv_common.so').write_bytes(result)
    (out/'patch-proof.json').write_text(json.dumps(proof,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    (out/'helper.bin').write_bytes(helper_code())
    return proof


if __name__=='__main__':
    print(json.dumps(write_candidate(),ensure_ascii=False))
