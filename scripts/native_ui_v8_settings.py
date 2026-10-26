"""Local native settings appearance patch; no event or global palette changes."""
import hashlib
import io
import struct
from pathlib import Path
from PIL import Image, ImageDraw
from build_native_volume_patch import elf_va_offset, verify_allowlist

ROOT=Path(__file__).resolve().parents[1]
EVIDENCE='analiz/native/ui-four/settings/reduced-recovery180/0055b6c0.json'
EVIDENCE_SHA='4b359c41e67a592f933ab08e4620306ad0b78dde51429b5a4fa5456afc7a4f3c'
FOCUS_ID,HEADER_ID=2224,2225
FOCUS_VAS=(0x5677ec,0x56780c,0x56782c,0x5678f0,0x567910,0x567930,
           0x567a54,0x567a74,0x567a94,0x567b58,0x567b78,0x567b98)
HEADER_VAS=(0x5682f8,)
BASE='08_APP/rc/ARimages/Grundig/modern/'

def png(size,fill,outline=None):
    image=Image.new('RGBA',size,(0,0,0,0))
    ImageDraw.Draw(image).rounded_rectangle((0,0,size[0]-1,size[1]-1),radius=12,
                                           fill=fill,outline=outline,width=2)
    out=io.BytesIO();image.save(out,format='PNG',compress_level=9)
    return out.getvalue()

def transform(num,elf,assets):
    if hashlib.sha256((ROOT/EVIDENCE).read_bytes()).hexdigest()!=EVIDENCE_SHA:
        raise ValueError('Pinned settings static evidence changed')
    output=bytearray(elf);records=[]
    for vas,old_id,new_id,role in ((FOCUS_VAS,0x122,FOCUS_ID,'Combo/Image/Spin/NumberEdit focus image'),
                                  (HEADER_VAS,0x6d,HEADER_ID,'ordinary settings header image')):
        for va in vas:
            offset=elf_va_offset(elf,va,4);old=0x24050000|old_id;new=0x24050000|new_id
            if struct.unpack_from('<I',elf,offset)[0]!=old:raise ValueError(f'Settings instruction mismatch {va:#x}')
            # The symbolic MImg::Set target load and jalr must also remain intact.
            if struct.unpack_from('<II',elf,offset+4)!=(0x8f99f6f0,0x0320f809):
                raise ValueError('Settings image call boundary changed')
            struct.pack_into('<I',output,offset,new)
            records.append(dict(va=hex(va),file_offset=offset,old_word=hex(old),new_word=hex(new),
                                callsite=hex(va+8),role=role,source_function='0x55b6c0',
                                source=EVIDENCE,source_sha256=EVIDENCE_SHA))
    verify_allowlist(elf,bytes(output),{r['file_offset']+i for r in records for i in range(4)})
    result=dict(assets)
    focus=BASE+'v8_settings_focus.png';header=BASE+'v8_settings_header.png'
    for path,raw in ((focus,png((1354,90),(25,107,157,255),(71,161,210,255))),
                     (header,png((1378,49),(33,59,80,245)))):
        if path in result:raise ValueError('Private settings resource collision')
        result[path]=raw
    return num,bytes(output),result,dict(code_records=records,num_records=[],image_records=[
        dict(id=FOCUS_ID,path='../rc/'+focus.removeprefix('08_APP/rc/')),
        dict(id=HEADER_ID,path='../rc/'+header.removeprefix('08_APP/rc/'))],
        description='Native soft blue rounded focus and dark header; existing white text remains readable',
        unchanged=['normal row theme','event handlers','settings values','ports','global colors','animation gate'],
        limits=['Not a full white settings theme or Chrome pixel parity','Only branches reaching NewUI_Settings shared style path'])
