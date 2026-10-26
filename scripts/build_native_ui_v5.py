"""Separate offline v5 overlay: restored volume font, larger icon widget, numeric card.

No firmware package or device write. Existing resource IDs remain stable.
"""
from __future__ import annotations
import hashlib
import io
import json
import os
from pathlib import Path
import struct
from PIL import Image, ImageDraw, ImageFont
import build_native_ui_v4 as v4
import build_native_volume_patch as volume

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/'analiz/native-ui-candidate/v5'
IMAGE_REL='08_APP/rc/rc/bin/Image_res.bin'
IMAGE_SHA='d6b1b9fde60c9cc4624f264a8e75da4245e6fb3e9dab7534ddce01706fbcd2f3'
CARD_REL='08_APP/rc/ARimages/Grundig/modern/numeric_bg.png'
CARD_RESOURCE='../rc/ARimages/Grundig/modern/numeric_bg.png'
CARD_ID=2179
DEJAVU_REL='08_APP/rc/rc/DejaVuSans.ttf'
DEJAVU_SHA='f4d46af3f8b795d13cffe2ab07d639e0f116412a18f9706ee87f94770b1dd5b2'
DIN_SHA='1e00616ed6d74da0eb3105683da02722e697c52f4a7461c1d0bd891ae344aa75'
NUM_PATCHES=(
    (0x5a40,76,68),(0x5a3f,540,490),  # root
    (0x5a43,76,68),(0x5a3e,500,450),  # panel
    (0x5a77,76,68),                   # number width
    (0x5a67,30,42),(0x5a66,30,42),
    (0x5a68,23,13),(0x5a69,444,394),
    (0x5a6c,35,31),(0x5a6d,92,86),(0x5a6a,320,276),
)
NUMERIC_FONT_VAS=(0x896730,0x896740,0x896750,0x896760)
NUMERIC_IMAGE_VAS=(0x896260,0x896284,0x8962a8,0x8962cc)
FLAG_ARGUMENT_VA,FLAG_STORE_VA=0x896100,0x89610c

def sha(data):return hashlib.sha256(data).hexdigest()

def guard(path):
    boundary=ROOT.resolve()/'analiz/native-ui-candidate/v5'
    if OUT.resolve()!=boundary or not path.resolve().is_relative_to(boundary):
        raise ValueError('V5 output escapes pinned directory')
    cursor=path
    while cursor!=ROOT:
        if cursor.is_symlink() or (hasattr(cursor,'is_junction') and cursor.is_junction()):
            raise ValueError('Symlink/junction in V5 output')
        if cursor.exists() and cursor.is_file() and cursor.stat().st_nlink!=1:
            raise ValueError('Hardlinked V5 output')
        cursor=cursor.parent

def write_new(path,payload):
    guard(path);path.parent.mkdir(parents=True,exist_ok=True);guard(path)
    with path.open('xb') as stream:
        stream.write(payload);stream.flush();os.fsync(stream.fileno())
    if path.read_bytes()!=payload:raise ValueError('Persisted output differs from written bytes')

def construct(num,elf):
    previous_num,previous_elf,inherited=v4.construct(num,elf)
    new_num,new_elf=bytearray(previous_num),bytearray(previous_elf)
    num_records=[]
    for rid,old,new in NUM_PATCHES:
        off=56+4*rid
        if struct.unpack_from('<I',previous_num,off)[0]!=old:raise ValueError('Unexpected v4 speaker geometry')
        struct.pack_into('<I',new_num,off,new)
        num_records.append(dict(id=rid,file_offset=off,old=old,new=new))
    patches=[]
    for vas,old,new,role in ((v4.FONT_VAS,0x240204af,0x240204ae,'restore volume DINPro font'),
                             (NUMERIC_FONT_VAS,0x240204af,0x240204b0,'numeric DejaVu Sans font'),
                             (NUMERIC_IMAGE_VAS,0x240501f1,0x24050000|CARD_ID,'numeric rounded background image')):
        patches.extend((va,old,new,role) for va in vas)
    # This jalr delay slot executes while a0=1 and s0 points at the background.
    # RcGetColor(1) subsequently writes the normal color, ignored by image mode.
    patches.extend(((FLAG_ARGUMENT_VA,0x2404005e,0x24040001,'set image-enable byte value'),
                    (FLAG_STORE_VA,0x00000000,0xa204003a,'enable background image before color callback')))
    records=[]
    for va,old,new,role in patches:
        off=volume.elf_va_offset(elf,va,4)
        if struct.unpack_from('<I',previous_elf,off)[0]!=old:raise ValueError(f'Unexpected local instruction at {va:#x}')
        struct.pack_into('<I',new_elf,off,new)
        records.append(dict(va=hex(va),file_offset=off,old_word=hex(old),new_word=hex(new),role=role))
    volume.verify_allowlist(previous_num,bytes(new_num),{r['file_offset']+k for r in num_records for k in range(4)})
    volume.verify_allowlist(previous_elf,bytes(new_elf),{r['file_offset']+k for r in records for k in range(4)})
    return bytes(new_num),bytes(new_elf),dict(inherited_v4=inherited,num_records=num_records,code_records=records)

def append_image_table(raw):
    if sha(raw)!=IMAGE_SHA:raise ValueError('Pinned original Image_res changed')
    words=struct.unpack_from('<14I',raw)
    if words[1]!=len(raw) or words[2]!=5 or words[4]!=CARD_ID*4 or words[5:7]!=(56,56) or words[7]!=CARD_ID:
        raise ValueError('Unexpected Image_res header')
    # All prior variable-length records are preserved byte-for-byte.
    pos=56
    for _ in range(CARD_ID):
        length=struct.unpack_from('<I',raw,pos)[0]
        end=pos+4+length
        if not length or end>len(raw) or raw[end-1]!=0:raise ValueError('Malformed original image path')
        pos=end
    if pos!=len(raw):raise ValueError('Unexpected original table trailing bytes')
    path=CARD_RESOURCE.encode('utf-8')+b'\0'
    result=bytearray(raw+struct.pack('<I',len(path))+path)
    struct.pack_into('<I',result,4,len(result))
    struct.pack_into('<I',result,16,(CARD_ID+1)*4)
    struct.pack_into('<I',result,28,CARD_ID+1)
    return bytes(result)

def card_png():
    scale=4
    image=Image.new('RGBA',(310*scale,112*scale),(245,245,245,0))
    draw=ImageDraw.Draw(image)
    draw.rounded_rectangle((0,0,310*scale-1,112*scale-1),radius=20*scale,fill=(245,245,245,255))
    image=image.resize((310,112),Image.Resampling.LANCZOS)
    out=io.BytesIO();image.save(out,format='PNG',compress_level=9)
    return out.getvalue()


def font_metrics():
    _,resources=v4.table()
    expected={0x4ae:'../rc/font/DINPro-CondMedium.otf',0x4b0:'../rc/rc/DejaVuSans.ttf'}
    result={}
    for rid,path in expected.items():
        if resources[rid]['resource_path']!=path:raise ValueError('Existing font resource ID changed')
        raw=(volume.SOURCE/'08_APP'/path.removeprefix('../')).read_bytes()
        if sha(raw)!=(DIN_SHA if rid==0x4ae else DEJAVU_SHA):raise ValueError('Pinned original font changed')
        size=36 if rid==0x4ae else 48
        font=ImageFont.truetype(io.BytesIO(raw),size)
        texts=('0','35','100') if rid==0x4ae else ('1','1234','9999')
        widths={text:round(font.getlength(text),3) for text in texts}
        widget_width=68 if rid==0x4ae else 254
        if max(widths.values())>widget_width:raise ValueError('Font overflows numeric widget')
        result[hex(rid)]=dict(size=size,widget_width=widget_width,measured_widths=widths,sha256=sha(raw))
    return result

def expected_payloads():
    prior=v4.verified_records()
    payloads={'08_APP'+row['path']:row['candidate'].read_bytes() for row in prior}
    new_num,new_elf,proof=construct((volume.SOURCE/volume.NUM_REL).read_bytes(),(volume.SOURCE/volume.ELF_REL).read_bytes())
    payloads[volume.NUM_REL]=new_num;payloads[volume.ELF_REL]=new_elf
    payloads[IMAGE_REL]=append_image_table((volume.SOURCE/IMAGE_REL).read_bytes())
    payloads[CARD_REL]=card_png()
    font=(volume.SOURCE/DEJAVU_REL).read_bytes()
    if sha(font)!=DEJAVU_SHA:raise ValueError('Pinned existing DejaVu font changed')
    font_metrics()
    return payloads,proof

def verified_records():
    guard(OUT/'manifest.json')
    manifest=json.loads((OUT/'manifest.json').read_text())
    payloads,_=expected_payloads()
    rows=manifest['records']
    if len(rows)!=24 or {r['relative_path'] for r in rows}!=payloads.keys():raise ValueError('Unexpected v5 overlay set')
    if {p.relative_to(OUT/'overlay').as_posix() for p in (OUT/'overlay').rglob('*') if p.is_file()}!=payloads.keys():
        raise ValueError('Unexpected files in v5 overlay')
    result=[]
    for row in rows:
        relative=row['relative_path'];target=OUT/'overlay'/relative;guard(target)
        original=None if relative==CARD_REL else sha((volume.SOURCE/relative).read_bytes())
        if row['original_sha256']!=original or row['candidate_sha256']!=sha(payloads[relative]) or target.read_bytes()!=payloads[relative]:
            raise ValueError('V5 output differs from reconstructed inputs')
        result.append(dict(path='/'+Path(relative).relative_to('08_APP').as_posix(),candidate=target,
                           original_sha256=original,candidate_sha256=row['candidate_sha256']))
    return result

def build():
    guard(OUT/'manifest.json')
    if (OUT/'manifest.json').exists():return dict(status='verified_existing_v5',files=len(verified_records()))
    if OUT.exists() and any(p.is_file() for p in OUT.rglob('*')):raise FileExistsError('Refusing partial/existing V5 outputs')
    payloads,proof=expected_payloads()
    records=[]
    for relative,payload in payloads.items():
        write_new(OUT/'overlay'/relative,payload)
        original=None if relative==CARD_REL else sha((volume.SOURCE/relative).read_bytes())
        records.append(dict(relative_path=relative,original_sha256=original,candidate_sha256=sha(payload),bytes=len(payload)))
    proof.update(revision='v5',status='offline_visual_overlay_not_flashable',records=records,
                 volume_font=dict(id=0x4ae,size=36,color_id=0),numeric_font=dict(id=0x4b0,path=DEJAVU_REL,size=48,sha256=DEJAVU_SHA),
                 font_metrics=font_metrics(),
                 volume_geometry=dict(root=[68,490],panel=[68,450],speaker=[13,394,42,42],
                                      number_width=68,track=[31,86,6,276]),
                 rounded_numeric=dict(image_id=CARD_ID,path=CARD_REL,resource_path=CARD_RESOURCE,size=[310,112],radius=20,
                                      image_enabled_byte='widget+0x3a=1',clrkey='native GetU32 out-of-range default 0xffffffff; existing table unchanged'),
                 television_tested=False,firmware_repacked=False,flash_ready=False,
                 limits=['Original OnCreate is not executed by this builder; patched arguments are statically verified.',
                         'Image header appends one record and updates total bytes, index bytes and count; existing IDs/records unchanged.',
                         'Host software rendering and full television behavior remain separate evidence scopes.'])
    write_new(OUT/'manifest.json',json.dumps(proof,indent=2).encode('utf-8'))
    verified_records()
    return dict(status=proof['status'],files=len(records),new_image_id=CARD_ID)

if __name__=='__main__':print(json.dumps(build()))
