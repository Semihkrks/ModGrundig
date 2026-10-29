"""Offline, pinned VDEC stage-three inventory. Never runs firmware or hardware I/O."""
from __future__ import annotations
import hashlib
import json
from pathlib import Path
import sys

from map_mips_calls import Elf32

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / 'analiz/native-4k/video-stage3'
SHA = '215c0a86cdd9fd579655da4752e0a5c7822eb3210e768ca63b86859683c9c02b'
NAMES = (
    'MApi_VDEC_EX_V2_Init', 'MDrv_HVD_EX_Init',
    'HAL_VPU_EX_LoadCode', '_HVD_EX_DemuxTS_ParseHEVCSPS',
    'MDrv_HVD_EX_GetErrCode', '_VPU_EX_GetFrameBufferDefaultSize',
    'HAL_VPU_EX_Init', '_HVD_EX_Init_',
)


def main():
    source = ROOT / 'analiz/dosya-sistemleri-tam/07_MSLIB/utopia/libapiVDEC.so'
    if source.is_symlink():
        raise ValueError('Source symlink refused')
    elf = Elf32(source)
    if hashlib.sha256(elf.raw).hexdigest() != SHA:
        raise ValueError('Pinned VDEC source changed')
    selected = []
    for name in NAMES:
        matches = [s for s in elf.symbols if s['name'] == name and s['shndx'] and s['size']]
        if len(matches) != 1:
            raise ValueError('Exact defined symbol required: ' + name)
        selected.append(matches[0])
    OUT.mkdir(parents=True, exist_ok=True)
    # Pure host disassembly; capstone is used only from the existing tool venv.
    sys.path.insert(0, str(ROOT / 'tools/native-volume-venv/Lib/site-packages'))
    import capstone
    decoder = capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32 | capstone.CS_MODE_LITTLE_ENDIAN)
    records = []
    for s in selected:
        off = elf.file_offset(s['value'])
        raw = elf.raw[off:off+s['size']]
        if len(raw) != s['size']:
            raise ValueError('Selected function outside source')
        instructions = list(decoder.disasm(raw, s['value']))
        if sum(i.size for i in instructions) != len(raw):
            raise ValueError('Incomplete disassembly: ' + s['name'])
        (OUT / (s['name'] + '.asm.txt')).write_text('\n'.join(
            f'{i.address:08x}: {i.bytes.hex()} {i.mnemonic} {i.op_str}' for i in instructions) + '\n', encoding='utf-8')
        records.append(dict(name=s['name'], va=hex(s['value']), bytes=s['size'],
                            body_sha256=hashlib.sha256(raw).hexdigest()))
    selection = dict(target_sha256=SHA, addresses=[f"{s['value']:08x}" for s in selected],
                     decompile_timeout_seconds=90, decompiler_max_payload_mbytes=128,
                     export_syntax_tree=True, seed_t9_entry=True,
                     function_bounds={f"{s['value']:08x}": dict(end_exclusive=hex(s['value']+s['size']),
                         basis='pinned_original_ELF_dynsym') for s in selected})
    (OUT / 'selection.json').write_text(json.dumps(selection, indent=2)+'\n', encoding='utf-8')
    (OUT / 'inventory.json').write_text(json.dumps(dict(source_path=source.relative_to(ROOT).as_posix(),
        source_sha256=SHA, selected_functions=records, firmware_executed=False,
        original_modified=False, method='host capstone static disassembly; separate Ghidra query required'), indent=2)+'\n', encoding='utf-8')
    print(json.dumps(dict(functions=len(records), source_sha256=SHA, firmware_executed=False)))


if __name__ == '__main__':
    main()
