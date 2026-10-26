"""Pinned in-place V7.2 normal-volume presentation delta; no target execution."""
from __future__ import annotations
import hashlib
import io
import struct
from PIL import Image, ImageDraw
from build_native_volume_patch import elf_va_offset, verify_allowlist
from native_ui_v71_tv_pins import RECORDS
ELF='08_APP/bin/dvbt_board'
IMAGE='08_APP/rc/rc/bin/Image_res.bin'
MUTED_ICON='08_APP/rc/ARimages/Grundig/volume/mute_icon.png'
MUTED_BACKGROUND='08_APP/rc/ARimages/Grundig/modern/volume_muted_bg.png'
MUTED_BACKGROUND_ID=2180
START,END=0xfb8200,0xfb8358
BLOCK_SHA='324c3e71860142481236ec6f46d060da3650102e97642a1ae780e5fd1dacf940'
def sha(raw): return hashlib.sha256(raw).hexdigest()
def png(image):
    stream=io.BytesIO(); image.save(stream,format='PNG',compress_level=9);return stream.getvalue()
def muted_background_png():
    s=4; im=Image.new('RGBA',(68*s,450*s),(222,233,241,0))
    ImageDraw.Draw(im).rounded_rectangle((0,0,im.width-1,im.height-1),radius=34*s,fill=(222,233,241,255))
    return png(im.resize((68,450),Image.Resampling.LANCZOS))
def muted_icon_png():
    s=4;im=Image.new('RGBA',(44*s,44*s),(0,0,0,0));d=ImageDraw.Draw(im)
    p=lambda pts:[(int(x*s),int(y*s)) for x,y in pts]
    d.polygon(p([(6,17),(13,17),(23,9),(23,35),(13,27),(6,27)]),fill=(88,115,136,255))
    d.line(p([(32,15),(32,29)]),fill=(136,156,172,255),width=2*s)
    d.line(p([(8,7),(37,36)]),fill=(222,233,241,255),width=6*s)
    d.line(p([(8,7),(37,36)]),fill=(183,112,105,255),width=3*s)
    for x,y in [(8,7),(37,36)]:d.ellipse(((x-1.5)*s,(y-1.5)*s,(x+1.5)*s,(y+1.5)*s),fill=(183,112,105,255))
    return png(im.resize((44,44),Image.Resampling.LANCZOS))
def block():
    words=[];labels={};fix=[]
    def emit(*v): words.extend(v)
    def branch(op,rs,rt,label):fix.append((len(words),op,rs,rt,label));emit(0)
    def li(rt,value):return (9<<26)|(rt<<16)|value
    def sw(rt,offset):return 0xafc00000|(rt<<16)|offset
    # Pinned predecessor loads IsMuted into s0 and volume into v0.
    emit(0x0010100b)  # movn v0,zero,s0: preserve inherited zero-or-muted rule
    branch(5,2,0,'normal');emit(0)
    emit(li(2,680),sw(2,0x40),li(2,2180),sw(2,0x44))
    branch(4,0,0,'set');emit(0)
    labels['normal']=len(words);emit(li(2,682),sw(2,0x40),li(2,674),sw(2,0x44))
    labels['set']=len(words)
    for widget,slot in [(0x1a8,0x40),(0x1a4,0x44)]:
        for field in (0xb8,0xcc,0xe0,0xf4):
            # a1 loaded in call delay slot; no caller-saved value spans an import.
            emit(0x8fc200c0,0x8c420000|widget,0x24440000|field,0x8f99f6f0,0x0320f809,0x8fc50000|slot,0x8fdc0018)
    for widget in (0x1a8,0x1a4):
        emit(0x8fc200c0,0x8c440000|widget,0x8f998b18,0x0320f809,0,0x8fdc0018)
    # Original branch to existing epilogue. All geometry/audio/ARC code is outside span.
    pc=START+4*len(words);emit(0x10000000|(((0xfb8b0c-(pc+4))//4)&0xffff),0)
    for idx,op,rs,rt,label in fix:words[idx]=(op<<26)|(rs<<21)|(rt<<16)|((labels[label]-idx-1)&0xffff)
    if len(words)>((END-START)//4):raise ValueError('Block overflow')
    words += [0]*((END-START)//4-len(words))
    return struct.pack('<%dI'%len(words),*words)
def apply(payloads):
    expected={p:(digest,size) for p,_,digest,size in RECORDS}
    if payloads.keys()!=expected.keys():raise ValueError('Expected exact pinned twelve-file V7.1 overlay')
    for p,data in payloads.items():
        digest,size=expected[p]
        if not isinstance(data,bytes) or len(data)!=size or sha(data)!=digest:raise ValueError('Pinned V7.1 mismatch: '+p)
    result=dict(payloads);raw=payloads[ELF];off=elf_va_offset(raw,START,END-START)
    if sha(raw[off:off+END-START])!=BLOCK_SHA:raise ValueError('Unexpected native selection block')
    # Exact effective-muted predecessor, including imported move callback delay slot.
    if raw[off-8:off]!=bytes.fromhex('2900d0932c00c28f'):raise ValueError('Unexpected inherited mute/volume selector')
    updated=bytearray(raw);updated[off:off+END-START]=block();result[ELF]=bytes(updated)
    changed=verify_allowlist(raw,result[ELF],set(range(off,off+END-START)))
    table=payloads[IMAGE];hdr=struct.unpack_from('<14I',table)
    if hdr[1]!=len(table) or hdr[2]!=5 or hdr[4]!=2180*4 or hdr[5:7]!=(56,56) or hdr[7]!=2180:raise ValueError('Unexpected image table')
    pos=56
    for _ in range(2180):
        length=struct.unpack_from('<I',table,pos)[0];pos+=4
        if not length or pos+length>len(table) or table[pos+length-1]!=0:raise ValueError('Malformed image record')
        pos+=length
    if pos!=len(table):raise ValueError('Image trailing data')
    path=b'../rc/ARimages/Grundig/modern/volume_muted_bg.png\0'
    out=bytearray(table+struct.pack('<I',len(path))+path)
    for offset,value in [(4,len(out)),(16,2181*4),(28,2181)]:struct.pack_into('<I',out,offset,value)
    result[IMAGE]=bytes(out);result[MUTED_BACKGROUND]=muted_background_png();result[MUTED_ICON]=muted_icon_png()
    proof=dict(revision='v7.2-mute',input_profile='exact twelve-file V7.1 overlay',native_span=[hex(START),hex(END)],native_block_sha256=sha(block()),elf_changed_byte_offsets=changed,code_records=[dict(va=hex(START+i),old_word=hex(struct.unpack_from('<I',raw,off+i)[0]),new_word=hex(struct.unpack_from('<I',result[ELF],off+i)[0])) for i in range(0,END-START,4)],changed_paths=sorted(p for p in result if result[p]!=payloads.get(p)),effective_muted='volume == 0 OR IsMuted',normal=dict(speaker=682,panel=674),muted=dict(speaker=680,panel=2180),all_image_fields=['0xb8','0xcc','0xe0','0xf4'],invalidations=['frame+0x1a8 speaker','frame+0x1a4 panel'],native_scope='mode0 presentation block only; existing function span; no caves or new imports',unchanged=['volume/mute source state','audio routing','ARC mode branches','numeric resources','OnCreate and panel image flag'],evidence='retained direct Ghidra instructions at 0xfb7d18; exact V71 ELF pin; bounded MIPS tests are separate',limits=['No hardware execution or physical TV verification','Service and UI imports are explicit mocked boundaries in bounded tests'])
    return result,proof

