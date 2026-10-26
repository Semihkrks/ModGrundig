"""Bounded V7.5 helper execution; explicit PC demo services, no TV process."""
from pathlib import Path
import struct
import native_ui_v75_name as code
from test_native_ui_v75_name import Harness,LABEL
from native_numeric_model import resolve,FIXTURE
from build_native_volume_patch import elf_va_offset


def run_name_bridge(variant,digits):
    if variant!='v7.5-tv' or not digits.isascii() or not digits.isdigit() or not 1<=len(digits)<=4:
        raise ValueError('V7.5 native TenKey requires 1..4 ASCII digits')
    from native_frame_rehost import source_file,validate_tv_inputs,sha
    validate_tv_inputs(variant)
    raw=source_file(variant,'08_APP/bin/dvbt_board').read_bytes()
    segments={}
    for name,va,expected in [('create',code.CREATE,code.code_create()),('update',code.UPDATE,code.code_update())]:
        offset=elf_va_offset(raw,va,len(expected));actual=raw[offset:offset+len(expected)]
        if actual!=expected: raise ValueError('Pinned V7.5 installed helper differs from current verified bytes')
        segments[name]=(va,actual)
    selection=resolve(digits)
    class PreviewHarness(Harness):
        def hook(self,uc,address,size,data):
            for name,(va,blob) in segments.items():
                if va<=address<va+len(blob):self.visited.add(address)
            return super().hook(uc,address,size,data)
    harness=PreviewHarness(digits=digits,typed=int(digits),count=len(digits),name=selection['name'] if selection['matched'] else '',selection=selection['matched'],widget=False)
    harness.visited=set()
    # Execute the actual installed bytes, after exact comparison with the builder.
    for va,blob in segments.values():harness.uc.mem_write(va,blob)
    created=harness.run('create');updated=harness.run('update')
    rect=harness.new_rect
    font=harness.r32(LABEL+0x130)
    size=struct.unpack('<H',harness.uc.mem_read(LABEL+0x13a,2))[0]
    color=harness.r32(LABEL+0x7c);align=harness.r32(LABEL+0x128)
    name=harness.texts.get(LABEL,'')
    return dict(text=name,rect=rect,font_resource_id=font,font_size=size,color=color,alignment=align,
        native_name_bridge_installed=True,data_source='explicit PC demo service; TV reads its real manager',
        device_database=False,matched=selection['matched'],digits=digits,number=int(digits),name=name,
        fixture_path=FIXTURE.relative_to(Path(__file__).resolve().parents[1]).as_posix(),fixture_sha256=sha(FIXTURE.read_bytes()),
        helper_inputs={name:dict(va=hex(va),bytes=len(blob),sha256=sha(blob)) for name,(va,blob) in segments.items()},
        native_execution=dict(unique_instructions=len(harness.visited),executed_addresses=[hex(p) for p in sorted(harness.visited)],create=created,update=updated),
        boundary='Only installed CREATE/UPDATE helper bytes executed; modeled widget allocation/strings/DB/route services; no tuner or full TV')
