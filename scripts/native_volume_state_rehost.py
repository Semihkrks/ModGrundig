"""Run selected native RefreshVolumeUI bytes with explicit service/UI boundaries.

This is bounded instruction emulation, not a running TV process. No syscalls,
device access, firmware files, or original ELF instructions are modified.
"""
from __future__ import annotations
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

SOURCE = ROOT / 'analiz/dosya-sistemleri-tam'
OVERLAY = ROOT / 'analiz/native-ui-candidate/v3/overlay'
OUT = ROOT / 'analiz/native-volume-state'
ENTRY = 0xfb7d18
FRAME, STOP, STUB, STACK = 0x10000000, 0x11000000, 0x11001000, 0x12010000
SHA = {
    'original': '51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916',
    'v3': 'c109a782f476dfb8b23136d7dad3a231c57dd4cb605e081da559ed370f76208a',
    'v4': '62fd931e69eabae725d7b1938c91cf2ae52e46444a0e23794ef9bcd737c6eaf4',
    'v5': 'f48239c5b3ac82405edd42417518f4f22098a8771218ae87460bee8464f0c5a2',
    'v6': '9ededb627b8548d0b12f6495d66bac4a0943fb3d92e83a2f3547a86b1ec33dc3',
    'v7': '9ededb627b8548d0b12f6495d66bac4a0943fb3d92e83a2f3547a86b1ec33dc3',
    'v7-tv': '9ededb627b8548d0b12f6495d66bac4a0943fb3d92e83a2f3547a86b1ec33dc3',
    'v8': '3eea9fc3ecea42edfbaefc25d5c88867a7f756bc8a06959095cb2e7a36354045',
}
NUM_SHA = {
    'original': 'e20c03cd212f548eb8154e8e49d6cf4daafc5fd5842887c51590bf76cfe613ff',
    'v3': 'bbf8e22e74266e69c4f6c1df9bd1b038645b8cc024c8c1331c4753d6888edf35',
    'v4': 'bbf8e22e74266e69c4f6c1df9bd1b038645b8cc024c8c1331c4753d6888edf35',
    'v5': '81228423a23fde8bd54855d47d613b0cd61db381ebb332388d9e013d2a637a43',
    'v6': '43a48071364ae37466f34cc0b5ac61ebe9498ad72c53671defa591c5450e376e',
    'v7': 'd293c1c7aeec39c4384915a66aa42be0c37b1fd52b726e74022551707d122cfa',
    'v7-tv': 'd293c1c7aeec39c4384915a66aa42be0c37b1fd52b726e74022551707d122cfa',
    'v8': 'd293c1c7aeec39c4384915a66aa42be0c37b1fd52b726e74022551707d122cfa',
}
# Shared final candidate pins; no build helper or candidate mutation.
from native_ui_v71_tv_pins import RECORDS as V71_RECORDS
V71_PINS = {relative: digest for relative, _, digest, _ in V71_RECORDS}
SHA['v7.1-tv'] = V71_PINS['08_APP/bin/dvbt_board']
NUM_SHA['v7.1-tv'] = V71_PINS['08_APP/rc/rc/bin/Num_res.bin']
from native_ui_v72_tv_pins import RECORDS as V72_RECORDS
V72_PINS = {relative: digest for relative, _, digest, _ in V72_RECORDS}
SHA['v7.2-tv'] = V72_PINS['08_APP/bin/dvbt_board']
NUM_SHA['v7.2-tv'] = V72_PINS['08_APP/rc/rc/bin/Num_res.bin']
from native_ui_v73_tv_pins import RECORDS as V73_RECORDS
V73_PINS = {relative: digest for relative, _, digest, _ in V73_RECORDS}
SHA['v7.3-tv'] = V73_PINS['08_APP/bin/dvbt_board']
NUM_SHA['v7.3-tv'] = V73_PINS['08_APP/rc/rc/bin/Num_res.bin']
from native_ui_v74_tv_pins import RECORDS as V74_RECORDS
V74_PINS = {relative: digest for relative, _, digest, _ in V74_RECORDS}
SHA['v7.4-tv'] = V74_PINS['08_APP/bin/dvbt_board']
NUM_SHA['v7.4-tv'] = V74_PINS['08_APP/rc/rc/bin/Num_res.bin']
from native_ui_v75_tv_pins import RECORDS as V75_RECORDS
V75_PINS = {relative: digest for relative, _, digest, _ in V75_RECORDS}
SHA['v7.5-tv'] = V75_PINS['08_APP/bin/dvbt_board']
NUM_SHA['v7.5-tv'] = V75_PINS['08_APP/rc/rc/bin/Num_res.bin']

def register_v76_pins():
    # Lazy registration preserves historical previews before a new overlay exists.
    from native_ui_v76_tv_pins import RECORDS
    pins = {relative: digest for relative, _, digest, _ in RECORDS}
    SHA['v7.6-tv'] = pins['08_APP/bin/dvbt_board']
    NUM_SHA['v7.6-tv'] = pins['08_APP/rc/rc/bin/Num_res.bin']


def register_v77_pins():
    from native_ui_v77_tv_pins import RECORDS
    pins = {relative: digest for relative, _, digest, _ in RECORDS}
    SHA['v7.7-tv'] = pins['08_APP/bin/dvbt_board']
    NUM_SHA['v7.7-tv'] = pins['08_APP/rc/rc/bin/Num_res.bin']

def register_v79_pins():
    from native_ui_v79_tv_pins import RECORDS
    pins = {relative: digest for relative, _, digest, _ in RECORDS}
    SHA['v7.9-tv'] = pins['08_APP/bin/dvbt_board']
    NUM_SHA['v7.9-tv'] = pins['08_APP/rc/rc/bin/Num_res.bin']

IMPORTS = {
    0x10c4ce4: 'GetMuteControlFrame', 0x10c5068: 'Hide', 0x10cc98c: 'Show',
    0x10c909c: 'SoundInstance', 0x10cd110: 'GetMainVolume', 0x10ca504: 'IsMuted',
    0x10c538c: 'DigiLinkInstance', 0x10c966c: 'IsARCMuteOn',
    0x10c786c: 'KillTimer', 0x10cb058: 'SetTimer', 0x10c97b4: 'sprintf',
    0x10c6920: 'allocator', 0x10c4f9c: 'string', 0x10cb39c: 'MStringSet',
    0x10c5070: 'stringDestructor', 0x10c4948: 'allocatorDestructor',
    0x10c4e28: 'Invalidate', 0x10caa64: 'SetCurValue', 0x10c8a6c: 'RcGetNum',
    0x10c9810: 'RectSet', 0x10cba00: 'MImgSet', 0x10cb3d8: 'GetMSrvSSSound',
    0x10c94cc: 'SetMuteStatus', 0x10cc1dc: 'TimerEventHandler', 0x10c5804: 'GetRect',
    0x10c858c: 'IsARCActive', 0x10cb89c: 'IsCECInitCompleted', 0x10c855c: 'GetHDMIDevPlugged',
}

def sha(data):
    return hashlib.sha256(data).hexdigest()

def run_case(variant='v3', volume=35, muted=False, mode=0, arc_muted=False,
             key=0xf04c, arc_active=True, instruction_budget=10000):
    if variant=='v7.6-tv': register_v76_pins()
    if variant=='v7.7-tv': register_v77_pins()
    if variant=='v7.9-tv': register_v79_pins()
    if variant not in SHA or not 0 <= volume <= 255 or mode not in (0, 1, 2, 3):
        raise ValueError('Unsupported bounded input')
    base = SOURCE if variant == 'original' else ROOT/f'analiz/native-ui-candidate/{variant}/overlay'
    raw = (base/'08_APP/bin/dvbt_board').read_bytes()
    nums = (base/'08_APP/rc/rc/bin/Num_res.bin').read_bytes()
    if sha(raw) != SHA[variant]:
        raise ValueError('ELF digest mismatch')
    if sha(nums) != NUM_SHA[variant]:
        raise ValueError('Num resource digest mismatch')
    if raw[:7] != b'\x7fELF\x01\x01\x01' or struct.unpack_from('<H', raw, 18)[0] != 8:
        raise ValueError('Expected little-endian MIPS ELF32')
    uc = Uc(UC_ARCH_MIPS, UC_MODE_MIPS32 | UC_MODE_LITTLE_ENDIAN)
    def r32(addr): return struct.unpack('<I', uc.mem_read(addr, 4))[0]
    def w32(addr, value): uc.mem_write(addr, struct.pack('<I', value & 0xffffffff))
    def rect(addr): return list(struct.unpack('<4i', uc.mem_read(addr, 16)))
    def cstring(addr):
        result = bytearray()
        for i in range(64):
            byte = uc.mem_read(addr+i, 1)
            if byte == b'\0': return result.decode('ascii')
            result.extend(byte)
        raise ValueError('Unbounded string dependency')
    phoff = struct.unpack_from('<I', raw, 28)[0]
    phsize, phcount = struct.unpack_from('<HH', raw, 42)
    for i in range(phcount):
        kind, off, va, _, filesz, memsz, _, _ = struct.unpack_from('<8I', raw, phoff+i*phsize)
        if kind == 1:
            start, end = va & ~4095, (va+memsz+4095)&~4095
            uc.mem_map(start, end-start)
            uc.mem_write(va, raw[off:off+filesz])
    uc.mem_map(FRAME, 0x20000)
    uc.mem_map(STOP, 0x10000)
    uc.mem_map(0x12000000, 0x20000)
    boundary = {}
    for i, (got, name) in enumerate(IMPORTS.items()):
        address = STUB+i*16
        w32(got, address)
        uc.mem_write(address, struct.pack('<II', 0x03e00008, 0))
        boundary[address] = name
    virtual_move = STUB+0x800
    uc.mem_write(virtual_move, struct.pack('<II', 0x03e00008, 0))
    boundary[virtual_move] = 'VirtualMoveRect'
    offsets = (0x1a4, 0x180, 0x184, 0x188, 0x1a8, 0x1ac, 0x1b0, 0x1b4, 0x1b8, 0x1bc)
    objects = {FRAME+0x1000+i*0x1000: off for i, off in enumerate(offsets)}
    for address, off in objects.items():
        w32(FRAME+off, address)
        w32(address, FRAME+0x1f000)
    progress_color_fields=(0x2a4,0x2a8,0x2ac,0x2b0)
    colors=(SOURCE/'08_APP/rc/rc/bin/Color_res.bin').read_bytes()
    initial_bar_color=struct.unpack_from('<I',colors,56+4*0x25)[0]
    if initial_bar_color!=0xff0082d4: raise ValueError('Unexpected original Color25')
    progress_address=next(address for address,off in objects.items() if off==0x1bc)
    for field in progress_color_fields: w32(progress_address+field,initial_bar_color)
    w32(FRAME+0x1f000+0x24, virtual_move)
    w32(FRAME+0x214, mode)
    w32(0x10c4b08, FRAME+0x1e000)
    w32(FRAME+0x1e000, key)
    state = {'text': None, 'progress_value': None, 'image_sets': [], 'rects': [],
             'shown_offsets': [], 'hidden_offsets': [], 'timers': [], 'audio_mute_requests': [], 'invalidated_offsets': []}
    trace, visited = [], Counter()
    selection = json.loads((ROOT/'analiz/native/ui-targeted/dvbt_board/00fb7d18.json').read_text())
    allowed = {int(i['address'], 16) for i in selection['instructions']}
    if variant=='v7.9-tv':
        from native_ui_v79_wave import HELPER, code
        from build_native_volume_patch import elf_va_offset
        helper=code();at=elf_va_offset(raw,HELPER,len(helper))
        if raw[at:at+len(helper)]!=helper:raise ValueError('Installed V7.9 wave helper differs')
        allowed.update(range(HELPER,HELPER+len(helper),4))
    completed, count = False, 0
    def offset(addr):
        if addr not in objects:
            raise ValueError(f'Unknown widget pointer {addr:#x}')
        return objects[addr]
    def callback(name, a):
        if name in ('GetMuteControlFrame', 'allocator', 'allocatorDestructor', 'stringDestructor'):
            return 0
        if name == 'Invalidate':
            state['invalidated_offsets'].append(offset(a[0])); return 0
        if name in ('SoundInstance', 'DigiLinkInstance', 'GetMSrvSSSound'):
            return FRAME+0x1d000
        if name == 'GetMainVolume': return volume
        if name == 'IsMuted': return int(muted)
        if name == 'IsARCMuteOn': return int(arc_muted)
        if name in ('IsARCActive', 'IsCECInitCompleted', 'GetHDMIDevPlugged'): return int(arc_active)
        if name in ('Hide', 'Show'):
            state['hidden_offsets' if name == 'Hide' else 'shown_offsets'].append(offset(a[0]))
        elif name in ('KillTimer', 'SetTimer', 'TimerEventHandler'):
            state['timers'].append({'name': name, 'args': a[1:4]})
        elif name == 'sprintf':
            # Only this routine's fixed %d format is supported; validate guest format.
            if cstring(a[1]) != '%d': raise ValueError('Unexpected sprintf format')
            text = str(a[2]).encode('ascii')
            uc.mem_write(a[0], text+b'\0')
            return len(text)
        elif name == 'string': w32(a[0], a[1])
        elif name == 'MStringSet':
            state['text'] = cstring(r32(a[1]))
        elif name == 'SetCurValue':
            if offset(a[0]) != 0x1bc: raise ValueError('Unexpected progress object')
            state['progress_value'] = a[1]
        elif name == 'RcGetNum':
            return struct.unpack_from('<I', nums, 56+4*a[0])[0]
        elif name == 'RectSet':
            uc.mem_write(a[0], struct.pack('<4I', *a[1:5]))
        elif name == 'VirtualMoveRect':
            state['rects'].append({'object_offset': offset(a[0]), 'rect': rect(a[3])})
        elif name == 'GetRect':
            # Known synthetic initial ARC positions; widths/heights changed natively.
            uc.mem_write(a[1], struct.pack('<4i', 0, 0, 158, 89))
        elif name == 'MImgSet':
            candidates = [(address, off) for address, off in objects.items() if address <= a[0] < address+0x400]
            if len(candidates) != 1: raise ValueError('Unknown image object')
            address, off = candidates[0]
            state['image_sets'].append({'object_offset': off, 'field_offset': a[0]-address, 'resource_id': a[1]})
        elif name == 'SetMuteStatus':
            state['audio_mute_requests'].append(a[1:4])
        else: raise ValueError(f'Unhandled dependency {name}')
        return 0
    def invalid(uc, access, address, size, value, data):
        raise RuntimeError(f'Unmapped guest access {address:#x} at PC {uc.reg_read(UC_MIPS_REG_PC):#x}')
    def hook(uc, address, size, data):
        nonlocal completed, count
        count += 1
        if count > instruction_budget: raise RuntimeError('Instruction watchdog exceeded')
        if address == STOP:
            completed = True
            uc.emu_stop()
        elif address in boundary:
            args = [uc.reg_read(reg) for reg in (UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_A2, UC_MIPS_REG_A3)]
            args += [r32(uc.reg_read(UC_MIPS_REG_SP)+16)]
            name = boundary[address]
            trace.append({'boundary': name, 'return_address': hex(uc.reg_read(UC_MIPS_REG_RA)), 'args': args})
            uc.reg_write(UC_MIPS_REG_V0, callback(name, args))
            if name == 'VirtualMoveRect':
                # Real PIC callees may replace GP. The caller must restore it.
                # Leaving it intact masked the V72/V73 missing-restore defect.
                uc.reg_write(UC_MIPS_REG_GP, 0xdead8000)
        elif address-4 in boundary:
            pass  # jr ra delay slot, explicitly supplied dependency stub.
        elif address in allowed:
            visited[address] += 1
        else: raise RuntimeError(f'Execution escaped selected native function: {address:#x}')
    uc.hook_add(UC_HOOK_CODE, hook)
    uc.hook_add(UC_HOOK_MEM_INVALID, invalid)
    uc.reg_write(UC_MIPS_REG_SP, STACK)
    uc.reg_write(UC_MIPS_REG_A0, FRAME)
    uc.reg_write(UC_MIPS_REG_T9, ENTRY)
    uc.reg_write(UC_MIPS_REG_RA, STOP)
    uc.emu_start(ENTRY, STOP+4, timeout=2_000_000, count=instruction_budget+2)
    if not completed: raise RuntimeError('Native function did not return within watchdog')
    state['progress_colors']=[dict(field_offset=field,color=r32(progress_address+field)) for field in progress_color_fields]
    state['progress_color_source']='Synthetic OnCreate Color25 initial fields; values read back from native Refresh memory after return'
    return dict(variant=variant, volume=volume, muted=muted, mode=mode, arc_muted=arc_muted,
                key=key, arc_active=arc_active, state=state, boundaries=trace,
                native=dict(entry=hex(ENTRY), elf_sha256=sha(raw), num_sha256=sha(nums), returned=True,
                            unique_instructions=len(visited), executed_instructions=sum(visited.values()),
                            executed_addresses=[hex(p) for p in sorted(visited)]))

def main():
    cases = []
    for variant in SHA:
        for volume in (0, 1, 35, 100, 150):
            for muted in (False, True):
                cases.append(run_case(variant, volume, muted))
        for mode in (1, 2, 3):
            for muted in (False, True):
                cases.append(run_case(variant, 35, muted, mode, muted))
        for key in (0xf04d, 0xf000, 0xf551):
            cases.append(run_case(variant, 35, mode=2, key=key))
    OUT.mkdir(parents=True, exist_ok=True)
    report = dict(kind='Bounded original/v3/v4/v5/v6 RefreshVolumeUI instruction execution with explicit mocked dependencies',
                  limits=['Synthetic frame and child objects; original OnCreate not executed',
                          'All imports are declared dependency callbacks, not native service execution',
                          'Mute icon selection at volume zero does not itself prove an audio hardware mute',
                          'ARC initial GetRect returns a synthetic rectangle; no CEC/hardware execution'], cases=cases)
    (OUT/'states.json').write_text(json.dumps(report, indent=2)+'\n', encoding='utf-8')
    print(json.dumps({'cases': len(cases), 'returned': sum(c['native']['returned'] for c in cases), 'output': str(OUT/'states.json')}))

if __name__ == '__main__':
    main()
