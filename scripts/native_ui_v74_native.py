"""Exact V7.3 input, in-place native volume fill-color state delta only."""
import hashlib,struct
from build_native_volume_patch import elf_va_offset,verify_allowlist
from native_ui_v73_tv_pins import RECORDS
from native_ui_v72_mute import START,END
ELF='08_APP/bin/dvbt_board'
COLOR='08_APP/rc/rc/bin/Color_res.bin'
NORMAL_COLOR=0xff0082d4
MUTED_COLOR=0xff898989
FIELDS=(0x2a4,0x2a8,0x2ac,0x2b0)
OLD_BLOCK_SHA='a601119509a04f383a2add75423fd25d09c42f6604cb15251d5d6d6dc0ecce78'
def sha(raw):return hashlib.sha256(raw).hexdigest()
def block():
    w=[]
    def emit(*a):w.extend(a)
    # Restore the caller GP after the preceding virtual MoveRect call.
    emit(0x8fdc0018)
    # v0 volume, s0 mute from pinned predecessor. s0 is saved in function prologue.
    emit(0x0010100b,0x0002802b) # movn v0,zero,s0; sltu s0,zero,v0
    emit(0x00101840,0x246302a8,0xafc30040) # icon680+2*normal
    emit(0x24030884,0x240202a2,0x0050180b,0xafc30044) # panel2180/674
    emit(0x3c03ff89,0x34638989,0x3c02ff00,0x344282d4,0x0050180b,0xafc30048)
    for widget,slot in [(0x1a8,0x40),(0x1a4,0x44)]:
        emit(0x8fc200c0,0x8c500000|widget)
        for field in (0xb8,0xcc,0xe0,0xf4):
            emit(0x26040000|field,0x8f99f6f0,0x0320f809,0x8fc50000|slot,0x8fdc0018)
    for widget in (0x1a8,0x1a4):emit(0x8fc200c0,0x8c440000|widget,0x8f998b18,0x0320f809,0,0x8fdc0018)
    emit(0x8fc200c0,0x8c4401bc,0x8fc20048)
    for field in FIELDS:emit(0xac820000|field)
    emit(0x8f998b18,0x0320f809,0,0x8fdc0018)
    pc=START+len(w)*4;emit(0x10000000|(((0xfb8b0c-pc-4)//4)&0xffff),0)
    if len(w)>86:raise ValueError('Native block overflow')
    w += [0]*(86-len(w));return struct.pack('<86I',*w)
def apply(payloads):
    expected={p:(digest,size) for p,_,digest,size in RECORDS}
    if payloads.keys()!=expected.keys():raise ValueError('Expected exact fourteen-file V7.3 overlay')
    for p,r in payloads.items():
        digest,size=expected[p]
        if not isinstance(r,bytes) or sha(r)!=digest or len(r)!=size:raise ValueError('Pinned V7.3 mismatch: '+p)
    raw=payloads[ELF];off=elf_va_offset(raw,START,END-START)
    if sha(raw[off:off+END-START])!=OLD_BLOCK_SHA:raise ValueError('Unexpected V7.3 native block')
    if raw[off-8:off]!=bytes.fromhex('2900d0932c00c28f'):raise ValueError('Inherited mute/volume loads changed')
    # Verify s0 save/restore directly rather than assuming an ABI-preserved register.
    if struct.pack('<I',0xafb000ac) not in raw[elf_va_offset(raw,0xfb7d18,60):elf_va_offset(raw,0xfb7d18,60)+60]:raise ValueError('Missing s0 prologue save')
    out=bytearray(raw);out[off:off+END-START]=block();result=dict(payloads);result[ELF]=bytes(out)
    changes=verify_allowlist(raw,result[ELF],set(range(off,off+END-START)))
    proof=dict(revision='v7.4-progress-native',input_profile='exact fourteen-file V7.3',changed_paths=[ELF],normal_color=hex(NORMAL_COLOR),muted_color=hex(MUTED_COLOR),color_fields=[hex(f) for f in FIELDS],native_span=[hex(START),hex(END)],block_sha256=sha(block()),elf_changed_byte_offsets=changes,code_records=[dict(va=hex(START+i),old_word=hex(struct.unpack_from('<I',raw,off+i)[0]),new_word=hex(struct.unpack_from('<I',result[ELF],off+i)[0])) for i in range(0,344,4)],effective_muted='volume == 0 OR IsMuted',invalidations=['speaker','panel','progress'],unchanged=['all bytes outside existing mode0 block','audio/mute state','ARC branches','geometry','assets and resource tables'],evidence=['OnCreate0xfb9780 SetBarColor loads Color25 four times','libmuf SetBarColor0x2e26ff00 stores +2a4,+2ac,+2a8,+2b0','fillwidget begins ProgressBar+258; color fields equal embedded MWidget+4c/+50/+54/+58','ProgressBar::Update0x2e26fff0 moves/draws embeddedfillwidget+258'],limits=['Bounded native instructions with mocked service/UI boundaries; not physical TV verification'])
    return result,proof

