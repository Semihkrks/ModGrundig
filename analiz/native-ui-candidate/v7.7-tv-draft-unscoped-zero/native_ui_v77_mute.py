"""Native V7.7 mute-key mode correction and zero-or-muted timeout predicate.

Only an offline bytes transformation; never runs the TV process or update code.
"""
import hashlib
import struct
from native_ui_v75_name import Assembler as BaseAssembler
from native_ui_v75_name import APP_GP, ZERO,V0,V1,A0,A1,A2,A3,T9,S0,S1,S2,S3,S4,S5,S6,GP,SP,FP,RA
from build_native_volume_patch import elf_va_offset, verify_allowlist

ELF='08_APP/bin/dvbt_board'
NUM='08_APP/rc/rc/bin/Num_res.bin'
PREDICATE=0x01161000
GOT={'IsMuted':0x10ca504,'GetMainVolume':0x10cd110}

class Assembler(BaseAssembler):
    def got(self,rt,name):
        self.lw(rt,GOT[name]-APP_GP,GP)

def code_predicate():
    a=Assembler(PREDICATE)
    a.prologue();a.gp();a.sw(GP,0x94);a.move(S0,A0)
    a.call('IsMuted');a.bne(V0,ZERO,'muted')
    a.move(A0,S0);a.call('GetMainVolume')
    a.i(11,V0,V0,1) # sltiu v0,v0,1: only a genuine zero volume is true.
    a.b('done')
    a.label('muted');a.li(V0,1)
    a.label('done');a.epilogue(fixed_gp=True)
    return a.finish()

def extras():
    return [(PREDICATE,code_predicate())]

EXTRA_HELPERS=extras()

def unwind_frames():
    raw=code_predicate();words=struct.unpack('<%dI'%(len(raw)//4),raw)
    events=[dict(pc=4,cfa_offset=0xa0)]
    for idx,w in enumerate(words):
        op,rs,rt,imm=w>>26,(w>>21)&31,(w>>16)&31,w&0xffff
        if idx<12 and op==43 and rs==SP:
            events.append(dict(pc=4*(idx+1),offsets={rt:imm-0xa0}))
        if idx>=len(words)-16 and op==35 and rs==SP and rt in (RA,FP,GP,S0,S1,S2,S3,S4,S5,S6):
            events.append(dict(pc=4*(idx+1),restores=[rt]))
    events.append(dict(pc=len(raw),cfa_offset=0))
    return [dict(start=PREDICATE,size=len(raw),frame_size=0xa0,prologue_end=48,
                 sp_adjust_pc=0,sp_restore_pc=len(raw)-4,events=events,personality=None,lsda=None)]

def hook_records():
    jal=0x0c000000|((PREDICATE>>2)&0x3ffffff)
    return [(0xfb93d4,0x24020001,0x24020000),
            (0xfb7b94,0x8f99e1f4,jal),(0xfb7b98,0x0320f809,0)]

def apply(payloads):
    original=payloads[ELF]
    off=elf_va_offset(original,PREDICATE,len(code_predicate()))
    if original[off:off+len(code_predicate())] != code_predicate():
        raise ValueError('V7.7 timeout predicate must be installed before hooks')
    # Actual local mute mode store remains, only its preceding value changes.
    for va,word in [(0xfb93d0,0x8fc30078),(0xfb93d8,0xac620214),
                    (0xfb93a4,0x24030003),(0xfb9424,0x0320f809),
                    (0xfb7ba0,0x8fdc0010),(0xfb8200,0x8fdc0018)]:
        if struct.unpack_from('<I',original,elf_va_offset(original,va,4))[0]!=word:
            raise ValueError('Mute audio/ARC/GP context differs at '+hex(va))
    out=bytearray(original);allowed=set()
    for va,old,new in hook_records():
        at=elf_va_offset(original,va,4)
        if struct.unpack_from('<I',original,at)[0]!=old:
            raise ValueError('Original native mute hook differs at '+hex(va))
        struct.pack_into('<I',out,at,new);allowed.update(range(at,at+4))
    verify_allowlist(original,bytes(out),allowed)
    nums=payloads[NUM];n=lambda i:struct.unpack_from('<I',nums,56+4*i)[0]
    if tuple(n(i) for i in (0x5b38,0x5b39,0x4219,0x4218,0x4217))!=(1728,19,44,64,64):
        raise ValueError('V7.6 corner badge bounds missing')
    result=dict(payloads);result[ELF]=bytes(out)
    proof=dict(revision='v7.7-tv',root_cause='Original OnKey local mute wrote mode1; Refresh mode1 selected isolated left mute root',
        local_mode_patch=dict(va='0xfb93d4',old_mode=1,new_mode=0,store='0xfb93d8 frame+0x214'),
        original_audio_toggle='0xfb93dc..0xfb942c retained SoundInstance/IsMuted/SetMute',
        arc_processed_mode3='0xfb93a4 unchanged',
        predicate=dict(va=hex(PREDICATE),bytes=len(code_predicate()),sha256=hashlib.sha256(code_predicate()).hexdigest(),
                       receives='original SoundInstance pointer in a0',rule='IsMuted || GetMainVolume==0',got={k:hex(v) for k,v in GOT.items()}),
        timeout_call='0xfb7b94/0xfb7b98 replace only IsMuted import; original app close/create/show remains',
        entry_cleanup='Refresh0xfb7d18 first checks GetMuteControlFrame and kills its parent app before showing panel',
        standalone_lifecycle='MuteControlFrame0xdf8330 returns1 with no IsMuted poll; class range has no other IsMuted check except explicit SetMute toggle0xdf8590',
        badge_screen=[1772,74,64,64],right_margin=84,top_margin=74,
        shared_assets_unchanged=True,audio_routing_unchanged=True,
        hooks=[dict(va=hex(v),old=hex(a),new=hex(b)) for v,a,b in hook_records()],
        unwind_frames=unwind_frames(),physical_tv_tested=False,
        limits=['Native helpers/events tested with modeled sound/UI dependencies; full TV not executed',
                'Zero-alone badge visibility is a visual rule and does not turn audio mute on',
                'ARC/CEC branches remain original; physical external-device behavior unmeasured'])
    return result,proof
