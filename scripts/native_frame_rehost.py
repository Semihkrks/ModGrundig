"""Bounded native MUF paint rehost, not a television/SoC emulator.

Executes unmodified, hash-pinned libmuf MIPS instructions. Explicit callback
boundaries supply widget state and Pillow-backed DirectFB surface primitives.
No firmware process, syscall, device, bootloader, or update script is run.
"""
from __future__ import annotations
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import struct
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools/native-volume-venv/Lib/site-packages'))
from unicorn import Uc, UC_ARCH_MIPS, UC_MODE_MIPS32, UC_MODE_LITTLE_ENDIAN, UC_HOOK_CODE, UC_HOOK_MEM_INVALID
from unicorn.mips_const import *
from PIL import Image, ImageDraw, ImageFont

SOURCE = ROOT / 'analiz/dosya-sistemleri-tam'
OVERLAY = ROOT / 'analiz/native-ui-candidate/v3/overlay'
V4_OVERLAY = ROOT / 'analiz/native-ui-candidate/v4/overlay'
V5_OVERLAY = ROOT / 'analiz/native-ui-candidate/v5/overlay'
V6_OVERLAY = ROOT / 'analiz/native-ui-candidate/v6/overlay'
V7_OVERLAY = ROOT / 'analiz/native-ui-candidate/v7/overlay'
V8_OVERLAY = ROOT / 'analiz/native-ui-candidate/v8/overlay'
V7_TV_OVERLAY = ROOT / 'analiz/native-ui-candidate/v7-tv/overlay'
V71_TV_OVERLAY = ROOT / 'analiz/native-ui-candidate/v7.1-tv/overlay'
V72_TV_OVERLAY = ROOT / 'analiz/native-ui-candidate/v7.2-tv/overlay'
V73_TV_OVERLAY = ROOT / 'analiz/native-ui-candidate/v7.3-tv/overlay'
V74_TV_OVERLAY = ROOT / 'analiz/native-ui-candidate/v7.4-tv/overlay'
V75_TV_OVERLAY = ROOT / 'analiz/native-ui-candidate/v7.5-tv/overlay'
V76_TV_OVERLAY = ROOT / 'analiz/native-ui-candidate/v7.6-tv/overlay'
V77_TV_OVERLAY = ROOT / 'analiz/native-ui-candidate/v7.7-tv/overlay'
V79_TV_OVERLAY = ROOT / 'analiz/native-ui-candidate/v7.9-tv/overlay'
TV_VARIANTS = ('v7-tv', 'v7.1-tv', 'v7.2-tv', 'v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv')
OUT = ROOT / 'analiz/native-frame-rehost'
LIB = SOURCE / '07_MSLIB/libmuf.so'
LIB_SHA = '494d4aa45a3c8d8e10760388d8d30111e9127a0357d38cdf97979b9f9bb16d96'
FUNCTIONS = {
    'DrawBackground': (0x2e251be4, 928),
    'RenderImageToSurface': (0x2e23e684, 2716),
    'DrawBorders': (0x2e24d438, 424),
    'DrawString': (0x2e24de4c, 2400),
    'CalculateTextDrawFlags': (0x2e24fe3c, 324),
}
JSONS = (
    'analiz/native/ui-deep/muf-core35/2e251be4.json',
    'analiz/native/ui-targeted/render-core5/2e23e684.json',
    'analiz/native/ui-targeted/volume-style-v1/2e24d438.json',
    'analiz/native/ui-targeted/text-small3/2e24de4c.json',
    'analiz/native/ui-targeted/text-render6/2e24fe3c.json',
)
WIDGET, SURFACE, SOURCE_SURFACE, SYSTEM = 0x10000000, 0x10002000, 0x10003000, 0x10004000
STOP, STUB = 0x11000000, 0x11001000
STACK = 0x12010000
V4_ELF_SHA = '62fd931e69eabae725d7b1938c91cf2ae52e46444a0e23794ef9bcd737c6eaf4'
V4_ICON_SHA = {
    680: '703208975d4b1424f003a2998e89c164116968e47e6d05dac6551e3f38698696',
    682: 'aa1c3918d73338f4065285fbc634fe56169dcc7019af99753b907a897796b099',
}
FONT_SHA = {
    0x4ae: '1e00616ed6d74da0eb3105683da02722e697c52f4a7461c1d0bd891ae344aa75',
    0x4af: '347e36d73e5db9b791c4ad385e391bf6fceeb0e17e830634d5fe35ca7da5f0bb',
    0x4b0: 'f4d46af3f8b795d13cffe2ab07d639e0f116412a18f9706ee87f94770b1dd5b2',
}

def sha(data):
    return hashlib.sha256(data).hexdigest()

def u32(data, offset):
    return struct.unpack_from('<I', data, offset)[0]

def intersect_rect(*rectangles):
    """Intersect logical screen xywh rectangles, retaining empty intersections."""
    x = max(r[0] for r in rectangles)
    y = max(r[1] for r in rectangles)
    right = min(r[0] + r[2] for r in rectangles)
    bottom = min(r[1] + r[3] for r in rectangles)
    return (x, y, max(0, right - x), max(0, bottom - y))


def validate_tv_inputs(variant):
    """Read-only overlay/manifest validation; no build helper execution."""
    if variant == 'v7.9-tv':
        from native_ui_v79_tv_pins import MANIFEST_SHA, RECORDS
        overlay = V79_TV_OVERLAY
    elif variant == 'v7.7-tv':
        from native_ui_v77_tv_pins import MANIFEST_SHA, RECORDS
        overlay = V77_TV_OVERLAY
    elif variant == 'v7.6-tv':
        from native_ui_v76_tv_pins import MANIFEST_SHA, RECORDS
        overlay = V76_TV_OVERLAY
    elif variant == 'v7.5-tv':
        from native_ui_v75_tv_pins import MANIFEST_SHA, RECORDS
        overlay = V75_TV_OVERLAY
    elif variant == 'v7.4-tv':
        from native_ui_v74_tv_pins import MANIFEST_SHA, RECORDS
        overlay = V74_TV_OVERLAY
    elif variant == 'v7.3-tv':
        from native_ui_v73_tv_pins import MANIFEST_SHA, RECORDS
        overlay = V73_TV_OVERLAY
    elif variant == 'v7.2-tv':
        from native_ui_v72_tv_pins import MANIFEST_SHA, RECORDS
        overlay = V72_TV_OVERLAY
    elif variant == 'v7.1-tv':
        from native_ui_v71_tv_pins import MANIFEST_SHA, RECORDS
        overlay = V71_TV_OVERLAY
    elif variant == 'v7-tv':
        from native_ui_v7_tv_pins import MANIFEST_SHA, RECORDS
        overlay = V7_TV_OVERLAY
    else:
        raise ValueError('Expected TV preview variant')
    manifest = (overlay.parent / 'manifest.json').read_bytes()
    if sha(manifest) != MANIFEST_SHA:
        raise ValueError('TV preview manifest pin mismatch')
    for relative, _, digest, size in RECORDS:
        path = source_file(variant, relative)
        raw = path.read_bytes()
        if not path.is_relative_to(overlay) or len(raw) != size or sha(raw) != digest:
            raise ValueError(f'TV preview overlay pin mismatch: {relative}')
    return dict(manifest_sha256=MANIFEST_SHA, overlay_files=len(RECORDS))


def source_file(variant, relative):
    if variant not in ('original', 'v3', 'v4', 'v5', 'v6', 'v7', 'v8', 'v7-tv', 'v7.1-tv', 'v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv'):
        raise ValueError('Unsupported source variant')
    source = SOURCE / relative
    overlay = V79_TV_OVERLAY if variant == 'v7.9-tv' else V77_TV_OVERLAY if variant == 'v7.7-tv' else V76_TV_OVERLAY if variant == 'v7.6-tv' else V75_TV_OVERLAY if variant == 'v7.5-tv' else V74_TV_OVERLAY if variant == 'v7.4-tv' else V73_TV_OVERLAY if variant == 'v7.3-tv' else V72_TV_OVERLAY if variant == 'v7.2-tv' else V71_TV_OVERLAY if variant == 'v7.1-tv' else V7_TV_OVERLAY if variant == 'v7-tv' else V8_OVERLAY if variant == 'v8' else V7_OVERLAY if variant == 'v7' else V6_OVERLAY if variant == 'v6' else V5_OVERLAY if variant == 'v5' else V4_OVERLAY if variant == 'v4' else OVERLAY
    candidate = overlay / relative
    selected = candidate if variant != 'original' and candidate.is_file() else source
    boundary = overlay if selected == candidate else SOURCE
    if not selected.resolve().is_relative_to(boundary.resolve()):
        raise ValueError('Escaping input boundary')
    return selected


def volume_style(variant):
    """Read four local constructor arguments from the selected pinned ELF.

    This is static field preparation; OnCreate itself is not rehosted. The font
    table and font files stay original. No browser CSS font enters the frame.
    """
    from build_native_volume_patch import elf_va_offset
    from native_volume_state_rehost import SHA, register_v76_pins, register_v77_pins, register_v79_pins
    if variant=='v7.6-tv': register_v76_pins()
    if variant in ('v7.7-tv','v7.9-tv'): register_v77_pins()
    if variant=='v7.9-tv': register_v79_pins()
    raw = source_file(variant, '08_APP/bin/dvbt_board').read_bytes()
    expected = V4_ELF_SHA if variant == 'v4' else SHA[variant]
    if sha(raw) != expected:
        raise ValueError('Pinned volume constructor ELF SHA256 mismatch')
    fields = []
    values = {}
    for role, addresses, opcode in (
            ('font', (0xfbbe18, 0xfbbe28, 0xfbbe38, 0xfbbe48), 0x24020000),
            ('color', (0xfbbc30, 0xfbbc50, 0xfbbc70, 0xfbbc90), 0x24040000)):
        selected = []
        for va in addresses:
            off = elf_va_offset(raw, va, 4)
            word = u32(raw, off)
            if word & 0xffff0000 != opcode:
                raise ValueError('Unexpected local constructor instruction')
            selected.append(word & 0xffff)
            fields.append(dict(role=role, va=hex(va), file_offset=off, word=hex(word)))
        if len(set(selected)) != 1:
            raise ValueError('Inconsistent widget visual state arguments')
        values[role] = selected[0]
    expected_style = (0x4af, 0) if variant == 'v4' else (0x4ae, 0) if variant in ('v5','v6','v7','v8','v7-tv','v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv') else (0x4ae, 0x25)
    if (values['font'], values['color']) != expected_style:
        raise ValueError('Unexpected selected volume typography')
    resource = image_table(variant)[values['font']]['resource_path']
    font = source_file(variant, '08_APP/'+resource.replace('../rc/', 'rc/'))
    if sha(font.read_bytes()) != FONT_SHA[values['font']]:
        raise ValueError('Pinned volume font SHA256 mismatch')
    return font, dict(font_resource_id=values['font'], color_resource_id=values['color'],
                      elf_sha256=sha(raw), field_source='static local OnCreate instruction arguments; constructor not executed',
                      local_instructions=fields)


def numeric_style(variant):
    """Read the selected numeric constructor's local resource bindings."""
    from build_native_volume_patch import elf_va_offset
    from native_volume_state_rehost import SHA, register_v76_pins, register_v77_pins, register_v79_pins
    if variant=='v7.6-tv': register_v76_pins()
    if variant in ('v7.7-tv','v7.9-tv'): register_v77_pins()
    if variant=='v7.9-tv': register_v79_pins()
    raw = source_file(variant, '08_APP/bin/dvbt_board').read_bytes()
    if sha(raw) != SHA[variant]:
        raise ValueError('Pinned numeric constructor ELF SHA256 mismatch')
    fields,values=[],{}
    groups=(('font',(0x896730,0x896740,0x896750,0x896760),0x24020000),
            ('color',(0x896548,0x896568,0x896588,0x8965a8),0x24040000),
            ('background_color',(0x896100,0x896120,0x896140,0x896160),0x24040000),
            ('background_image',(0x896260,0x896284,0x8962a8,0x8962cc),0x24050000))
    for role,addresses,opcode in groups:
        selected=[]
        for va in addresses:
            off=elf_va_offset(raw,va,4)
            word=u32(raw,off)
            if word&0xffff0000!=opcode:
                raise ValueError('Unexpected numeric constructor argument instruction')
            selected.append(word&0xffff)
            fields.append(dict(role=role,va=hex(va),file_offset=off,word=hex(word)))
        if variant in ('v5','v6','v7','v8','v7-tv','v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv') and role=='background_color':
            if selected != [1, 0x5e, 0x5e, 0x5e]:
                raise ValueError('Unexpected image-enabled background color arguments')
        elif len(set(selected))!=1:
            raise ValueError('Inconsistent numeric visual state arguments')
        values[role]=selected[0]
    expected=(0x4b0,0,1,2179) if variant in ('v5','v6','v7','v8','v7-tv','v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv') else (0x4af,0x5e,0x12,0x1f1) if variant=='original' else (0x4af,0,0x5e,0x1f1)
    if tuple(values[k] for k in ('font','color','background_color','background_image'))!=expected:
        raise ValueError('Unexpected numeric resource bindings')
    if variant in ('v5','v6','v7','v8','v7-tv','v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv'):
        offset=elf_va_offset(raw,0x89610c,4)
        if u32(raw,offset)!=0xa204003a:
            raise ValueError('Expected native image-enable store in jalr delay slot')
        fields.append(dict(role='background image enabled',va='0x89610c',file_offset=offset,word='0xa204003a'))
    records=image_table(variant)
    font=source_file(variant,'08_APP/'+records[values['font']]['resource_path'].replace('../rc/','rc/'))
    if sha(font.read_bytes())!=FONT_SHA[values['font']]:
        raise ValueError('Pinned numeric font SHA256 mismatch')
    size,alignment=48,0x42
    if variant in ('v6','v7','v8','v7-tv','v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv'):
        for va in (0x896784,0x8967a8,0x8967cc,0x8967f0):
            off=elf_va_offset(raw,va,4)
            if u32(raw,off)!=0x2402003a:
                raise ValueError('Expected local numeric font size58')
            fields.append(dict(role='font size58',va=hex(va),file_offset=off,word='0x2402003a'))
        if u32(raw,elf_va_offset(raw,0x896800,4))!=0x24020011:
            raise ValueError('Expected numeric left/top alignment')
        size,alignment=58,0x11
    return font,dict(font_resource_id=values['font'],color_resource_id=values['color'],
                     font_size=size,alignment=alignment,
                     background_color_resource_id=values['background_color'],background_image_resource_id=values['background_image'],
                     elf_sha256=sha(raw),local_instructions=fields,
                     field_source='Static numeric OnCreate instruction arguments; constructor not executed')

class NativePainter:
    """Actual paint instructions with injected native object state and APIs."""
    def __init__(self, instruction_budget=50000):
        raw = LIB.read_bytes()
        if sha(raw) != LIB_SHA:
            raise ValueError('Pinned original libmuf SHA256 mismatch')
        if raw[:7] != b'\x7fELF\x01\x01\x01' or struct.unpack_from('<H', raw, 18)[0] != 8:
            raise ValueError('Expected little-endian MIPS ELF32')
        self.uc = Uc(UC_ARCH_MIPS, UC_MODE_MIPS32 | UC_MODE_LITTLE_ENDIAN)
        self.budget = instruction_budget
        self.raw = raw
        self.segments = []
        phoff = u32(raw, 28)
        size, count = struct.unpack_from('<HH', raw, 42)
        for i in range(count):
            kind, off, va, _, filesz, memsz, flags, _ = struct.unpack_from('<8I', raw, phoff + size*i)
            if kind != 1:
                continue
            start, end = va & ~4095, (va + memsz + 4095) & ~4095
            self.uc.mem_map(start, end-start)
            self.uc.mem_write(va, raw[off:off+filesz])
            self.segments.append(dict(va=va, file_offset=off, file_size=filesz, memory_size=memsz, flags=flags))
        self.uc.mem_map(WIDGET, 0x10000)
        self.uc.mem_map(STOP, 0x10000)
        self.uc.mem_map(0x12000000, 0x20000)
        # libstdc++ canonical empty-string representation, dependency boundary.
        self.uc.mem_map(0x2c820000, 0x10000)
        self.uc.mem_write(STUB, struct.pack('<II', 0x03e00008, 0))
        self.allowed = set()
        self.function_addresses = {}
        for name,path in zip(FUNCTIONS,JSONS):
            addresses={int(i['address'], 16) for i in json.loads((ROOT/path).read_text())['instructions']}
            self.function_addresses[name]=addresses
            self.allowed.update(addresses)
        # Ghidra's selected switch-body misses this disjoint bottom-center case.
        # Verified directly in the hash-pinned original ELF with Capstone:
        # flags=9; y=rect.y+rect.h; x=rect.x+rect.w/2; branch 0x2e24fed8.
        numeric_alignment=set(range(0x2e24ffa0,0x2e24ffd8,4))
        # Original switch's left/top case (alignment0x11): flags4, x=rect.x,
        # y=rect.y, branch0x2e24fed8. Seven raw-ELF instructions omitted by
        # the retained Ghidra instruction list; no callback/RTL query needed.
        numeric_alignment.update(range(0x2e24fffc,0x2e250018,4))
        self.allowed.update(numeric_alignment)
        self.function_addresses['CalculateTextDrawFlags'].update(numeric_alignment)
        self.callsites = {
            0x2e251c1c: 'QueryVisualState', 0x2e251c38:'QueryFlag', 0x2e251f3c:'QueryFlag',
            0x2e251c4c:'GetDFBSurface', 0x2e251c64:'ClipDFBSurface',
            0x2e251cbc:'GetAbsRect', 0x2e251e88:'GetAbsRect',
            0x2e251e6c:'GetMResourceManager',
            0x2e251ef0:'native:RenderImageToSurface',
            0x2e251e38:'native:DrawBorders', 0x2e251f04:'native:DrawBorders',
            0x2e23e6e8:'MImgQueryFlag',0x2e23e710:'FindCachedSurface',0x2e23e728:'GetInstance',
            0x2e23e758:'GetSize',0x2e23e768:'GetPixelFormat',0x2e23e788:'GetPosition',
            0x2e23e904:'MImgQueryFlag',0x2e23e978:'GetSize',
            0x2e23ed5c:'SetSrcBlendFunction',0x2e23ed70:'SetDstBlendFunction',
            0x2e23ed84:'SetBlittingFlags',0x2e23ed98:'SetRenderOptions',0x2e23edac:'SetBlittingFlags',
            0x2e23edcc:'StretchBlit',0x2e23e9dc:'ReleaseSource',0x2e23e9f4:'MImgQueryFlag',
            0x2e23ea14:'ReleaseSource',
            0x2e24d480:'QueryFlag',0x2e24d4a8:'SetColor',0x2e24d538:'SetColor',
            0x2e24d500:'FillRectangle',0x2e24d568:'FillRectangle',
            0x2e24d59c:'FillRectangle',0x2e24d5cc:'FillRectangle',
            0x2e24dec0:'QueryVisualState',0x2e24e448:'QueryVisualState',
            0x2e24df10:'NewTextBuffer',0x2e24e0e0:'DeleteTextBuffer',
            0x2e24e610:'SurfaceDrawString',0x2e24fedc:'QueryVisualState',
        }
        for va in (0x2e251d14,0x2e251d5c,0x2e251dcc):
            self.callsites[va]='SetColor'
        for va in (0x2e251d3c,0x2e251d84,0x2e251dac,0x2e251df8,0x2e251e24):
            self.callsites[va]='FillRectangle'
        # Native code reads the function table before our callsite boundary.
        for off in range(0, 0x120, 4):
            self.write32(SURFACE+off, STUB)
            self.write32(SOURCE_SURFACE+off, STUB)
        self.write32(SYSTEM+4, SURFACE)
        self.uc.hook_add(UC_HOOK_CODE, self._hook)
        self.uc.hook_add(UC_HOOK_MEM_INVALID, self._invalid)
        self.trace=[]
        self.visited=Counter()
        self.pending=None
        self.image=None
        self.color=(0,0,0,0)
        self.canvas=Image.new('RGBA',(1920,1080),(25,32,42,255))
        self.clip_rect=(0,0,1920,1080)
        self.compositions=[]
        self.label=''
        self.count=0
        self.completed=False

    def read32(self, address):
        return u32(self.uc.mem_read(address,4),0)

    def write32(self, address, value):
        self.uc.mem_write(address,struct.pack('<I',value & 0xffffffff))

    def rect(self, address):
        return struct.unpack('<4i',self.uc.mem_read(address,16))

    def _invalid(self, uc, access, address, size, value, _):
        raise RuntimeError(f'Unmapped access {address:#x}, size {size}, PC {uc.reg_read(UC_MIPS_REG_PC):#x}; no automatic mapping')

    def _hook(self, uc, address, size, _):
        self.count+=1
        if self.count>self.budget:
            raise RuntimeError('Native instruction watchdog exceeded')
        if address == STOP:
            self.completed=True
            uc.emu_stop()
            return
        if address == STUB:
            if not self.pending:
                raise RuntimeError('Unclassified stub call')
            name, caller=self.pending
            self.pending=None
            args=[uc.reg_read(x) for x in (UC_MIPS_REG_A0,UC_MIPS_REG_A1,UC_MIPS_REG_A2,UC_MIPS_REG_A3)]
            args.extend(self.read32(uc.reg_read(UC_MIPS_REG_SP)+offset) for offset in (16,20))
            self.trace.append(dict(widget=self.label, callsite=hex(caller), boundary=name, args=args))
            result=self.callback(name,args)
            uc.reg_write(UC_MIPS_REG_V0,result)
            return
        if address == STUB+4:
            return
        if address not in self.allowed:
            raise RuntimeError(f'Execution escaped selected native ranges: {address:#x}')
        self.visited[address]+=1
        if address in self.callsites:
            name=self.callsites[address]
            if name.startswith('native:'):
                target=FUNCTIONS[name.split(':')[1]][0]
            else:
                target=STUB
                self.pending=(name,address)
            uc.reg_write(UC_MIPS_REG_T9,target)

    def callback(self,name,a):
        if name in ('QueryVisualState','MImgQueryFlag','ClipDFBSurface','ReleaseSource','SetSrcBlendFunction',
                    'SetDstBlendFunction','SetBlittingFlags','SetRenderOptions'):
            return 0
        if name=='QueryFlag':
            return int(a[1]==1)
        if name=='GetDFBSurface':
            return SURFACE
        if name=='GetMResourceManager' or name=='GetInstance':
            return SYSTEM
        if name=='GetAbsRect':
            self.uc.mem_write(a[1],struct.pack('<4i',*self.widget_rect))
            return 0
        if name=='FindCachedSurface':
            self.write32(a[2],SOURCE_SURFACE)
            self.write32(a[3],0xffffffff)
            return 1
        if name=='GetSize':
            w,h=self.image.size if a[0]==SOURCE_SURFACE else self.widget_rect[2:]
            self.write32(a[1],w)
            self.write32(a[2],h)
            return 0
        if name=='GetPosition':
            self.uc.mem_write(a[1],struct.pack('<2I',0,0))
            return 0
        if name=='GetPixelFormat':
            self.write32(a[1],4)
            return 0
        if name=='SetColor':
            self.color=tuple(x&255 for x in a[1:5])
            return 0
        if name=='FillRectangle':
            x,y,w,h=a[1:5]
            if w>0 and h>0:
                layer=Image.new('RGBA',(w,h),self.color)
                self._compose(layer,x,y)
            return 0
        if name=='StretchBlit':
            sx,sy,sw,sh=self.rect(a[2])
            dx,dy,dw,dh=self.rect(a[3])
            if min(sw,sh,dw,dh)<=0:
                raise RuntimeError('Invalid native StretchBlit rectangle')
            layer=self.image.crop((sx,sy,sx+sw,sy+sh)).resize((dw,dh),Image.Resampling.BILINEAR)
            self._compose(layer,dx,dy)
            return 0
        if name=='NewTextBuffer':
            if a[0]>1024:
                raise RuntimeError('Text buffer exceeds bounded allocation')
            self.uc.mem_write(WIDGET+0x5000,bytes(1024))
            return WIDGET+0x5000
        if name=='DeleteTextBuffer':
            return 0
        if name=='SurfaceDrawString':
            text=bytes(self.uc.mem_read(a[1],a[2])).decode('utf-8')
            x,y,flags=a[3],a[4],a[5]
            layer=Image.new('RGBA',self.widget_rect[2:],(0,0,0,0))
            draw=ImageDraw.Draw(layer)
            anchor=('m' if flags&3==1 else 'r' if flags&3==2 else 'l')+('t' if flags&4 else 'b' if flags&8 else 's')
            draw.text((x,y),text,font=self.font,fill=self.text_color,anchor=anchor)
            self._compose(layer,0,0)
            self.trace[-1].update(text=text,x=x,y=y,flags=flags,font_backend='Pillow FreeType; actual firmware font file')
            return 0
        raise RuntimeError(f'Unknown dependency: {name}')

    def _compose(self,layer,x,y):
        # Native primitives use widget-local coordinates. Parent/window clipping
        # is a declared host model of DirectFB subsurfaces, not a native driver.
        dx,dy=self.widget_rect[0]+x,self.widget_rect[1]+y
        visible=intersect_rect((dx,dy,*layer.size),self.clip_rect,(0,0,*self.canvas.size))
        self.compositions.append(dict(widget=self.label,draw_rect=(dx,dy,*layer.size),
                                      clip_rect=self.clip_rect,visible_rect=visible))
        vx,vy,vw,vh=visible
        if vw and vh:
            cropped=layer.crop((vx-dx,vy-dy,vx-dx+vw,vy-dy+vh))
            self.canvas.alpha_composite(cropped,(vx,vy))

    def paint(self,label,rect,*,image=None,color=0,border_mask=0,border_width=0,border_color=0,
              clip=None,image_enabled=None):
        x,y,w,h=rect
        if w<=0 or h<=0 or w>1920 or h>1080:
            raise ValueError('Invalid bounded widget dimensions')
        self.label=label
        self.widget_rect=rect
        self.clip_rect=intersect_rect(rect,clip) if clip is not None else (0,0,1920,1080)
        self.image=image.convert('RGBA') if image is not None else None
        if image_enabled is None:
            image_enabled=image is not None
        if image_enabled and image is None:
            raise ValueError('Image flag requires a declared image surface')
        self.uc.mem_write(WIDGET,bytes(0x600))
        for off,value in zip((0x1c,0x20,0x24,0x28),rect):
            self.write32(WIDGET+off,value)
        self.uc.mem_write(WIDGET+0x39,b'\x01'+bytes([int(image_enabled)]))
        self.write32(WIDGET+0x4c,color)
        self.uc.mem_write(WIDGET+0x160,bytes((border_mask,border_width)))
        self.write32(WIDGET+0x16c,border_color)
        # Set empty-string GOT dependency to its pinned external address.
        gp=0x2e251be4+0x70000-0x6304
        gp_render=0x2e23e684+0x80000-0x2da4
        self.write32(gp_render-0x6c50,0x2c828ab8)
        self.write32(0x2c828ab8,0)
        self.uc.reg_write(UC_MIPS_REG_SP,STACK)
        self.uc.reg_write(UC_MIPS_REG_A0,WIDGET)
        self.uc.reg_write(UC_MIPS_REG_A1,WIDGET+0x400)
        self.uc.reg_write(UC_MIPS_REG_A2,1)
        self.uc.reg_write(UC_MIPS_REG_T9,FUNCTIONS['DrawBackground'][0])
        self.uc.reg_write(UC_MIPS_REG_RA,STOP)
        self.count=0
        self.completed=False
        self.uc.emu_start(FUNCTIONS['DrawBackground'][0],STOP+4,count=self.budget+2)
        if not self.completed:
            raise RuntimeError('Native routine did not return within watchdog')

    def evidence(self):
        ranges={}
        for name,(start,length) in FUNCTIONS.items():
            pcs=[p for p in self.visited if p in self.function_addresses[name]]
            ranges[name]=dict(entry=hex(start),function_bytes=length,unique_executed_instructions=len(pcs),
                              executed_instruction_count=sum(self.visited[p] for p in pcs),executed_addresses=[hex(p) for p in sorted(pcs)])
        return dict(libmuf_sha256=LIB_SHA,elf_load_segments=self.segments,native_functions=ranges,
                    callbacks=self.trace, compositions=self.compositions,
                    framebuffer='Host Pillow RGBA; bilinear StretchBlit and source-over alpha',
                    clipping_boundary='Explicit host intersections of widget/parent/outer rectangles when supplied; DirectFB clipping code is not executed',
                    never_executed=['Full dvbt_board process','Boot/kernel/init','NAND/UBI','DirectFB/GOP drivers','TV tuner/decoder','Actual broadcast'],
                    state_boundary='Widget object state assembled from retained OnCreate C and Num resources, not original constructor execution',
                    relocation_boundary='One libstdc++ empty-string GOT cell injected; original paint instruction bytes unchanged',
                    disassembly_correction='CalculateTextDrawFlags omitted switch blocks: bottom-center0x2e24ffa0..ffd4 (14 instructions), left/top0x2e24fffc..2e250014 (7); bounded original ELF bytes, never patched')

    def text(self,label,rect,text,font_path,size,color,align=0x22,padding=0,clip=None):
        """Native alignment and byte loop; host FreeType is the explicit surface boundary."""
        self.label=label
        self.widget_rect=rect
        self.clip_rect=intersect_rect(rect,clip) if clip is not None else (0,0,1920,1080)
        self.font=ImageFont.truetype(str(font_path),size)
        self.text_color=((color>>16)&255,(color>>8)&255,color&255,color>>24)
        self.uc.mem_write(WIDGET,bytes(0x1000))
        self.uc.mem_write(WIDGET+0x138,struct.pack('<H',5))
        rectp,xp,yp,fp,txtp,mapp=[WIDGET+off for off in (0x800,0x810,0x814,0x818,0x820,0x900)]
        self.uc.mem_write(rectp,struct.pack('<4i',padding,padding,rect[2]-2*padding,rect[3]-2*padding))
        data=text.encode('utf-8')
        if len(data)>1000:
            raise ValueError('Text exceeds bounded allocation')
        self.uc.mem_write(txtp,data+b'\0')
        # Font GetHeight is a model boundary. Pillow metrics differ from DirectFB's rasterizer.
        metrics=self.font.getmetrics()
        height=sum(metrics)
        self._invoke('CalculateTextDrawFlags',[WIDGET,rectp,align,height],[xp,yp,fp])
        self._invoke('DrawString',[WIDGET,SURFACE,WIDGET+0xa00,txtp],[len(data),xp,yp,self.read32(fp),0,mapp])
        draw=next(item for item in reversed(self.trace) if item['boundary']=='SurfaceDrawString')
        draw.update(font_metrics=dict(ascent=metrics[0],descent=metrics[1],modeled_GetHeight=height,
                                      boundary='Pillow metrics sum; actual DirectFB GetHeight is not executed'))

    def _invoke(self,name,args,stack_args):
        self.uc.reg_write(UC_MIPS_REG_SP,STACK)
        for reg,value in zip((UC_MIPS_REG_A0,UC_MIPS_REG_A1,UC_MIPS_REG_A2,UC_MIPS_REG_A3),args):
            self.uc.reg_write(reg,value)
        for i,value in enumerate(stack_args):
            self.write32(STACK+16+4*i,value)
        entry=FUNCTIONS[name][0]
        self.uc.reg_write(UC_MIPS_REG_T9,entry)
        self.uc.reg_write(UC_MIPS_REG_RA,STOP)
        self.count=0
        self.completed=False
        self.uc.emu_start(entry,STOP+4,count=self.budget+2)
        if not self.completed:
            raise RuntimeError(f'{name} did not return within watchdog')

def image_table(variant='original'):
    from build_soft_ui_assets import table
    if variant in ('v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv'):
        from map_ui_asset_dependencies import parse_table, CACHE
        validate_tv_inputs(variant)
        path=source_file(variant,'08_APP/rc/rc/bin/Image_res.bin')
        CACHE.pop(path,None)
        info,records=parse_table(path)
        if info['status']!='fully_parsed' or len(records)!=(2184 if variant=='v7.9-tv' else 2182 if variant in ('v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv') else 2181) or records[2180]['resource_path']!='../rc/ARimages/Grundig/modern/volume_muted_bg.png':
            raise ValueError('Unexpected V7.2 appended mute panel resource')
        if variant in ('v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv') and records[2181]['resource_path']!='../rc/ARimages/Grundig/modern/mute_badge.png':
            raise ValueError('Unexpected V7.4 standalone white badge resource')
        return records
    if variant == 'v8':
        from build_native_ui_v8 import verified_packaging_records, IMAGE_REL
        from map_ui_asset_dependencies import parse_table, CACHE
        verified_packaging_records()
        path=source_file(variant,IMAGE_REL);CACHE.pop(path,None)
        info,records=parse_table(path)
        if info['status']!='fully_parsed' or len(records)!=2226:
            raise ValueError('Unexpected V8 image table')
        return records
    if variant in ('v5','v6','v7','v7-tv','v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv'):
        from build_native_ui_v5 import append_image_table, IMAGE_REL
        from map_ui_asset_dependencies import parse_table, CACHE
        path=source_file(variant,IMAGE_REL)
        expected=append_image_table((SOURCE/IMAGE_REL).read_bytes())
        if path.read_bytes()!=expected:
            raise ValueError('V5 Image resource table differs from reconstructed append')
        CACHE.pop(path,None)
        info,records=parse_table(path)
        if info['status']!='fully_parsed' or len(records)!=2180:
            raise ValueError('Unexpected v5 resource table boundaries')
        return records
    _,records=table()
    return records

def render(variant,volume=35,mute=False,*,half_margin_review=False):
    if not 0<=volume<=100:
        raise ValueError('Volume must be 0..100')
    from native_volume_state_rehost import run_case
    pins=validate_tv_inputs(variant) if variant in TV_VARIANTS else None
    native_state=run_case(variant,volume,mute,0)
    state=native_state['state']
    num_path=source_file(variant,'08_APP/rc/rc/bin/Num_res.bin')
    nums=num_path.read_bytes()
    margin_proof=None
    if half_margin_review:
        if half_margin_review is not True or variant!='v7.7-tv':
            raise ValueError('Half-margin review requires the pinned V7.7 rendering base')
        from build_native_ui_v79_margin_review import verified_margin_resource
        nums,num_path,margin_proof=verified_margin_resource()
    def n(i): return u32(nums,56+i*4)
    colors=(SOURCE/'08_APP/rc/rc/bin/Color_res.bin').read_bytes()
    def c(i): return u32(colors,56+i*4)
    records=image_table(variant)
    inputs=[]
    def img(i):
        record=records[i]
        rel=record['resource_path']
        if not isinstance(rel,str):
            raise ValueError('Unexpected image resource record')
        path=source_file(variant,'08_APP/'+rel.replace('../rc/','rc/'))
        if variant in ('v4','v5','v6','v7','v8','v7-tv','v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv') and not (variant in ('v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv') and i==680) and i in V4_ICON_SHA and sha(path.read_bytes())!=V4_ICON_SHA[i]:
            raise ValueError('Pinned v4 icon SHA256 mismatch')
        inputs.append(dict(image_id=i,path=path.relative_to(ROOT).as_posix(),sha256=sha(path.read_bytes())))
        return Image.open(path).convert('RGBA')
    p=NativePainter()
    outer=None
    root_local=(n(0x5a41),n(0x5a42),n(0x5a40),n(0x5a3f))
    root=root_local
    clip=None
    panel_style=None
    if variant in TV_VARIANTS:
        from build_native_volume_patch import elf_va_offset
        raw=source_file(variant,'08_APP/bin/dvbt_board').read_bytes()
        outer=tuple(n(i) for i in (0x5bf0,0x5bf1,0x5bef,0x5bee))
        root=(outer[0]+root_local[0],outer[1]+root_local[1],*root_local[2:])
        clip=intersect_rect(outer,root)
        argument=u32(raw,elf_va_offset(raw,0xfbb550,4))
        store=u32(raw,elf_va_offset(raw,0xfbb55c,4))
        expected=(0x24040001,0xa204003a) if variant in ('v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv') else (0x2404005e,0)
        if (argument,store)!=expected:
            raise ValueError('Unexpected pinned panel image flag instructions')
        panel_style=dict(image_resource_id=674,image_enabled=store==0xa204003a,
                         normal_color_resource_id=argument&0xffff,
                         root_final_image_resource_id=1485,root_image_is_null=True,
                         flag_source='Static constructor words0xfbb550/0xfbb55c and retained default flag; OnCreate not executed')
        # OnCreate later overwrites root image685 with null1485. Never invent a shadow.
    else:
        p.paint('normal-root image 685',root,image=img(685))
    panel=(root[0]+n(0x5a44),root[1]+n(0x5a45),n(0x5a43),n(0x5a3e))
    panel_id=674
    if variant in ('v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv'):
        panel_sets=[item['resource_id'] for item in state['image_sets'] if item['object_offset']==0x1a4]
        if len(panel_sets)!=4 or len(set(panel_sets))!=1 or panel_sets[0] not in (674,2180):
            raise ValueError('Unexpected native panel image assignments')
        panel_id=panel_sets[0]
        panel_style['image_resource_id']=panel_id
    p.paint(f'volume-panel image {panel_id}',panel,image=img(panel_id),clip=clip,
            image_enabled=panel_style['image_enabled'] if panel_style else None,
            color=c(panel_style['normal_color_resource_id']) if panel_style else 0)
    child_clip=intersect_rect(clip,panel) if clip is not None else None
    # OnCreate0xfb9780: these children are owned by panel (+0x1a4), not root.
    speaker=(panel[0]+n(0x5a68),panel[1]+n(0x5a69),n(0x5a67),n(0x5a66))
    speaker_id=next(item['resource_id'] for item in state['image_sets'] if item['object_offset']==0x1a8)
    p.paint('mute' if speaker_id==680 else 'speaker',speaker,
            image=img(speaker_id),
            # ShowBorder(...,1,color,8,0,2,...) stores width1 at 1920x1080.
            # Its width2 fallback requires BOTH OSD dimensions to differ.
            border_mask=8 if variant=='original' else 0,border_width=1,border_color=c(0x13),clip=child_clip)
    # Track background is the original ProgressBar background colour (0x24).
    track=(panel[0]+n(0x5a6c),panel[1]+n(0x5a6d),n(0x5a6b),n(0x5a6a))
    p.paint('progress background configured from Num/Color',track,color=c(0x24),clip=child_clip)
    # ProgressBar fill arrangement is a host-derived state assumption here;
    # its native paint is executed, but SetCurValue/Update are not rehosted yet.
    fill_colors=[item['color'] for item in state['progress_colors']]
    if len(fill_colors)!=4 or len(set(fill_colors))!=1: raise ValueError('Inconsistent native progress color states')
    fill_color=fill_colors[0]
    fill=track[3]*state['progress_value']//100
    if fill:
        p.paint('progress fill HOST geometry assumption',(track[0],track[1]+track[3]-fill,track[2],fill),color=fill_color,clip=child_clip)
    local_knob=next(item['rect'] for item in state['rects'] if item['object_offset']==0x1b4)
    knob=(panel[0]+local_knob[0],panel[1]+local_knob[1],*local_knob[2:])
    p.paint('thumb image 681',knob,image=img(681),clip=child_clip)
    number=(panel[0]+n(0x5a78),panel[1]+n(0x5a79),n(0x5a77),n(0x5a76))
    font,style=volume_style(variant)
    p.text('volume number',number,state['text'],font,n(0x3215),c(style['color_resource_id']),clip=child_clip)
    evidence=p.evidence()
    evidence.update(variant=variant,volume=volume,mute=mute,input_assets=inputs,num_path=num_path.relative_to(ROOT).as_posix(),
                    num_sha256=sha(nums),surface_geometry=dict(outer_frame=outer,root_local=root_local,root=root,panel=panel,speaker=speaker,track=track,thumb=knob),
                    progress_fill_color=fill_color,text_geometry=number,font_sha256=sha(font.read_bytes()),native_volume_state=native_state,
                    verified_pins=pins,panel_style=panel_style,half_margin_review=margin_proof,
                    parent_clip=clip,child_clip=child_clip,
                    geometry_basis='1920x1080 logical screen; outer origin added for TV variants; active hardware scaling/overscan unmeasured',
                    volume_style=style,font_path=font.relative_to(ROOT).as_posix(),
                    omitted=['Main menu and channel UI','Full device scaling/compositor'],
                    approximate=['ProgressBar fill rectangle from native-selected value but host geometry formula; native ProgressBar Update not executed','Surface interpolation differs from unknown hardware scaler','Font rasterizer and GetHeight backend are Pillow FreeType; native DrawString and alignment execute'])
    return p.canvas,evidence


def render_numeric(variant,digits='123',elapsed_ms=0):
    """Native paint/text routines, synthetic numeric frame state from OnCreate."""
    if not digits.isascii() or not digits.isdigit() or not 1<=len(digits)<=(4 if variant in ('v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv') else 5):
        raise ValueError('Numeric input must contain 1..5 ASCII digits')
    if type(elapsed_ms) is not int or not 0<=elapsed_ms<=10000 or (variant!='v7.6-tv' and elapsed_ms):
        raise ValueError('Elapsed milliseconds supported only for V7.6 in 0..10000')
    pins=validate_tv_inputs(variant) if variant in TV_VARIANTS else None
    num_path=source_file(variant,'08_APP/rc/rc/bin/Num_res.bin')
    nums=num_path.read_bytes()
    colors=(SOURCE/'08_APP/rc/rc/bin/Color_res.bin').read_bytes()
    def n(i):return u32(nums,56+4*i)
    def c(i):return u32(colors,56+4*i)
    p=NativePainter()
    root=(n(0x991),n(0x992),n(0x990),n(0x98f))
    outer=None
    clip=None
    outer_height_resource=None
    if variant in TV_VARIANTS:
        from build_native_volume_patch import elf_va_offset
        raw=source_file(variant,'08_APP/bin/dvbt_board').read_bytes()
        word=u32(raw,elf_va_offset(raw,0x89518c,4))
        expected=0x2404098f if variant in ('v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv') else 0x24040050
        if word!=expected:
            raise ValueError('Unexpected pinned numeric outer-height instruction')
        outer_height_resource=word&0xffff
        outer=tuple(n(i) for i in (0x52,0x53,0x51,outer_height_resource))
        root=(outer[0]+root[0],outer[1]+root[1],*root[2:])
        clip=intersect_rect(outer,root)
    background=(root[0]+n(0x995),root[1]+n(0x996),n(0x994),n(0x993))
    textrect=(root[0]+n(0x999),root[1]+n(0x99a),n(0x998),n(0x997))
    font,style=numeric_style(variant)
    background_input=None
    if variant in ('v5','v6','v7','v8','v7-tv','v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv'):
        if variant in ('v6','v7','v8','v7-tv','v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv'):
            from build_native_ui_v6 import CARD_REL, card_png
        else:
            from build_native_ui_v5 import CARD_REL, card_png
        record=image_table(variant)[style['background_image_resource_id']]
        relative='08_APP/'+record['resource_path'].replace('../rc/','rc/')
        if relative!=CARD_REL:
            raise ValueError('Unexpected numeric background resource path')
        path=source_file(variant,relative)
        raw=path.read_bytes()
        if raw!=card_png():
            raise ValueError('V5 numeric PNG differs from reconstructed rounded card')
        with Image.open(path) as source:
            p.paint('numeric rounded image resource 2179',background,image=source.convert('RGBA'),clip=clip)
        background_input=dict(image_id=2179,path=path.relative_to(ROOT).as_posix(),sha256=sha(raw))
    else:
        p.paint('numeric background: OnCreate local color assignment',background,color=c(style['background_color_resource_id']))
    p.text('numeric entry',textrect,digits,font,style['font_size'],c(style['color_resource_id']),align=style['alignment'],padding=n(0x45f5),clip=clip)
    channel=None
    if variant in ('v6','v7'):
        from native_numeric_model import resolve
        channel=resolve(digits)
        name=channel['name']
        name_font=ImageFont.truetype(str(font),26)
        while name_font.getlength(name)>254 and len(name)>1:
            name=name[:-2]+'…'
        name_rect=(background[0]+28,background[1]+(142 if variant=='v7' else 126),254,38)
        p.text('matched name: proposed widget, demo-service input',name_rect,name,font,26,
               0xff106eaf if channel['matched'] else 0xff61788c,align=0x11)
        channel.update(display_name=name,proposed_widget_rect=name_rect,
                       native_widget_created=False,
                       boundary='Additional name widget exists only in rehost design; no native OnCreate/event bridge installed')
    name_bridge=None
    if variant in ('v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv'):
        if variant in ('v7.7-tv','v7.9-tv'):
            from native_channel_name_v77_rehost import run_name_bridge
        elif variant=='v7.6-tv':
            from native_channel_name_v76_rehost import run_name_bridge
        else:
            from native_channel_name_rehost import run_name_bridge
        name_bridge=run_name_bridge(variant,digits,elapsed_ms=elapsed_ms) if variant=='v7.6-tv' else run_name_bridge(variant,digits)
        name_font=source_file(variant,'08_APP/'+image_table(variant)[name_bridge['font_resource_id']]['resource_path'].replace('../rc/','rc/'))
        if sha(name_font.read_bytes())!=FONT_SHA[name_bridge['font_resource_id']]: raise ValueError('Name font identity differs')
        if name_bridge['text']:
            p.text('native helper destination name: PC demo service',name_bridge['rect'],name_bridge['text'],name_font,name_bridge['font_size'],name_bridge['color'],align=name_bridge['alignment'],clip=clip)
        if variant=='v7.6-tv' and name_bridge.get('countdown'):
            timer=name_bridge['countdown']
            if timer['rect'][2]:
                p.paint('native cosmetic timer ID2 blue line',timer['rect'],color=timer['color'],clip=clip)
        channel=name_bridge
    evidence=p.evidence()
    evidence.update(variant=variant,numeric_input=digits,num_sha256=sha(nums),font_sha256=sha(font.read_bytes()),
                    font_path=font.relative_to(ROOT).as_posix(),numeric_style=style,
                    background_input=background_input,
                    channel_resolution=channel,native_name_bridge=name_bridge,
                    verified_pins=pins,outer_height_resource=outer_height_resource,
                    parent_clip=clip,
                    surface_geometry=dict(outer_frame=outer,root=root,background=background,text=textrect,
                                          background_visible=intersect_rect(background,clip) if clip is not None else background,
                                          text_visible=intersect_rect(textrect,clip) if clip is not None else textrect),
                    omitted=['NumericInput event handler/channel tuning','Full device compositor'],
                    approximate=['OnCreate fields assembled from retained C, original constructor not executed',
                                 'Font rasterizer and GetHeight use Pillow FreeType, native text alignment/byte loop execute'],
                    behavior_boundary='Digits are supplied test input, not an executed remote/channel event')
    return p.canvas,evidence

def render_mute_badge(variant='v7.3-tv'):
    """Existing MuteControlFrame image with pinned static constructor inputs."""
    if variant not in ('v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv'):
        raise ValueError('Expected pinned existing mute badge variant')
    pins=validate_tv_inputs(variant)
    modern=variant in ('v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv')
    rid=2181 if modern else 680
    record=image_table(variant)[rid]
    relative='08_APP/'+record['resource_path'].replace('../rc/','rc/')
    expected='08_APP/rc/ARimages/Grundig/modern/mute_badge.png' if modern else '08_APP/rc/ARimages/Grundig/volume/mute_icon.png'
    if relative!=expected: raise ValueError('Unexpected existing standalone image')
    path=source_file(variant,relative)
    painter=NativePainter()
    if modern:
        from build_native_volume_patch import elf_va_offset
        raw=source_file(variant,'08_APP/bin/dvbt_board').read_bytes()
        nums=source_file(variant,'08_APP/rc/rc/bin/Num_res.bin').read_bytes()
        def n(i):return u32(nums,56+4*i)
        for va in (0xdf9324,0xdf9348,0xdf936c,0xdf9390):
            if u32(raw,elf_va_offset(raw,va,4))!=0x24050000|2181: raise ValueError('Standalone image argument differs')
        for va in (0xdf9648,0xdf966c,0xdf9690,0xdf96b4,0xdf996c,0xdf9990,0xdf99b4,0xdf99d8,0xdf9c90,0xdf9cb4,0xdf9cd8,0xdf9cfc,0xdf9fb4,0xdf9fd8,0xdf9ffc,0xdfa020,0xdfa2d8,0xdfa2fc,0xdfa320,0xdfa344):
            if u32(raw,elf_va_offset(raw,va,4))!=0x24050000|1485: raise ValueError('Standalone shadow not null')
        outer=(n(0x5b38),n(0x5b39),160,230)
        root=(outer[0],outer[1],n(0x4208),230)
        panel=(root[0],root[1]+25,158,165)
        icon=(panel[0]+n(0x4219),panel[1]+30,n(0x4218),n(0x4217))
        if icon!=((1772,74,64,64) if variant in ('v7.6-tv','v7.7-tv','v7.9-tv') else (1784,74,52,52)): raise ValueError('Pinned standalone badge geometry differs')
    else:
        outer=(0,435,160,230);root=(0,435,165,230);panel=(0,460,158,165);icon=(0,490,100,100)
    clip=intersect_rect(outer,root,panel)
    with Image.open(path) as source:
        painter.paint(f'existing MuteControlFrame image {rid}',icon,image=source.convert('RGBA'),clip=clip)
    evidence=painter.evidence()
    evidence.update(variant=variant,scene='mute',verified_pins=pins,
        surface_geometry=dict(outer_frame=outer,root=root,panel=panel,icon=icon),
        input_assets=[dict(image_id=rid,path=path.relative_to(ROOT).as_posix(),sha256=sha(path.read_bytes()))],
        constructor_provenance=dict(entry='0xdf8630',normal_image_call='0xdf932c',
            other_state_image_calls=['0xdf9350','0xdf9374','0xdf9398'],other_state_image_id=2181 if modern else 401,
            shadow_image_id=1485 if modern else None,root_image_id=1485,root_image_is_null=True),
        lifecycle_provenance=dict(timer='0xfb7aec',application_id='0x10ff',
            rule=('V7.7 actual timeout checks IsMuted OR (captured mode0 AND GetMainVolume==0) before closing Volume and running MuteControl' if variant in ('v7.7-tv','v7.9-tv') else 'Existing timer checks IsMuted before closing Volume and running MuteControl; zero alone does not launch standalone')),
        lifecycle_executed=False,
        geometry_basis='Pinned static OnCreate instructions and Num fields; constructor and timer not executed',
        omitted=['Existing border composition','Timer, visibility and application lifecycle','Full device compositor'],
        approximate=['Host Pillow image rasterization; static constructor geometry; no full frame lifecycle'])
    return painter.canvas,evidence


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--variant',choices=('original','v3','v4','v5','v6','v7','v8','v7-tv','v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv','both','all'),default='both')
    parser.add_argument('--volume',type=int,default=35)
    parser.add_argument('--mute',action='store_true')
    parser.add_argument('--numeric',help='Also render native numeric input surfaces with supplied digits')
    args=parser.parse_args()
    if not 0<=args.volume<=100:
        parser.error('volume must be 0..100')
    OUT.mkdir(parents=True,exist_ok=True)
    if not OUT.resolve().is_relative_to((ROOT/'analiz').resolve()):
        raise ValueError('Output boundary escaped')
    for variant in (('original','v3','v4','v5','v6','v7','v8','v7-tv','v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.9-tv') if args.variant=='all' else ('original','v3') if args.variant=='both' else (args.variant,)):
        image,evidence=render(variant,args.volume,args.mute)
        stem=f'{variant}-volume-{args.volume}'+('-mute' if args.mute else '')
        image.save(OUT/(stem+'.png'))
        (OUT/(stem+'.json')).write_text(json.dumps(evidence,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
        print(json.dumps(dict(variant=variant,image=str(OUT/(stem+'.png')),instructions={k:v['unique_executed_instructions'] for k,v in evidence['native_functions'].items()},callbacks=len(evidence['callbacks']))))
        if args.numeric:
            image,evidence=render_numeric(variant,args.numeric)
            stem=f'{variant}-numeric-{args.numeric}'
            image.save(OUT/(stem+'.png'))
            (OUT/(stem+'.json')).write_text(json.dumps(evidence,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')

if __name__=='__main__':
    main()
