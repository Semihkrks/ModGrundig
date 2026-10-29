"""Bounded V7.6 helper execution; explicit PC demo services, no TV process."""
from pathlib import Path
import struct
import native_ui_v76_name as code
from test_native_ui_v76_name import Harness,LABEL,LINE,EVIDENCE
from native_numeric_model import resolve,FIXTURE
from build_native_volume_patch import elf_va_offset


def run_name_bridge(variant,digits,*,elapsed_ms=0):
    if variant!='v7.6-tv' or not digits.isascii() or not digits.isdigit() or not 1<=len(digits)<=4:
        raise ValueError('V7.6 native TenKey requires 1..4 ASCII digits')
    if type(elapsed_ms) is not int or not 0<=elapsed_ms<=10000:
        raise ValueError('Bounded elapsed_ms must be an integer in0..10000')
    from native_frame_rehost import source_file,validate_tv_inputs,sha
    validate_tv_inputs(variant)
    raw=source_file(variant,'08_APP/bin/dvbt_board').read_bytes()
    segments={}
    for name,va,expected in [('create',code.CREATE,code.code_create()),('update',code.UPDATE,code.code_update()),('start_timer',code.START_TIMER,code.code_start_timer()),('tick_timer',code.TICK_TIMER,code.code_tick_timer())]:
        offset=elf_va_offset(raw,va,len(expected));actual=raw[offset:offset+len(expected)]
        if actual!=expected: raise ValueError('Pinned V7.6 installed helper differs from current verified bytes')
        segments[name]=(va,actual)
    selection=resolve(digits)
    class PreviewHarness(Harness):
        def hook(self,uc,address,size,data):
            for name,(va,blob) in segments.items():
                if va<=address<va+len(blob):
                    self.visited.add(address);self.steps+=1
                    if self.steps>3000:raise AssertionError('Installed preview helper watchdog')
                    return
            return super().hook(uc,address,size,data)
    harness=PreviewHarness(digits=digits,typed=int(digits),count=len(digits),name=selection['name'] if selection['matched'] else '',selection=selection['matched'],widget=False)
    harness.visited=set()
    # Execute the actual installed bytes, after exact comparison with the builder.
    for va,blob in segments.values():harness.uc.mem_write(va,blob)
    # Verify original duration/count instructions retained in the actual installed ELF.
    for va,word in [(0x895a98,0x904301a4),(0x895a9c,0x24020004),(0x895aa0,0x1462000e),
                    (0x895ab0,0x240507d0),(0x895ab4,0x24060001),
                    (0x895ae4,0x24050bb8),(0x895ae8,0x00003021)]:
        offset=elf_va_offset(raw,va,4)
        if struct.unpack_from('<I',raw,offset)[0]!=word:raise ValueError('Original duration/count selection differs')
    # Harness.run appends detailed test evidence; remove only this request's entries
    # so a long-lived local viewer does not retain all prior helper traces.
    evidence_start=len(EVIDENCE)
    try:
        created=harness.run('create');updated=harness.run('update')
        duration=2000 if len(digits)==4 else 3000
        started=harness.run('start',duration=duration)
        tick_steps=[]
        for _ in range(min(elapsed_ms,duration)//50):
            if 2 not in harness.timers:break
            tick=harness.run('tick',timerid=2)
            tick_steps.append(tick['steps'])
    finally:
        del EVIDENCE[evidence_start:]
    line_rect=struct.unpack('<4I',harness.uc.mem_read(LINE+0x1c,16))
    timer=dict(rect=line_rect,color=harness.r32(LINE+0x4c),elapsed_ms=elapsed_ms,
        duration_ms=duration,remaining_ms=harness.r32(LABEL+0x250),period_ms=50,
        dispatched_ticks=len(tick_steps),tick_steps=tick_steps,
        native_helpers_executed=True,original_tuning_timer=harness.timers.get(1 if duration==2000 else 0),
        lifecycle_executed=False,
        boundary='Actual installed START/TICK helper instructions; synthetic periodic tick delivery. Original channel tuning/expiry not executed; the physical timer may be delayed.')
    rect=harness.new_rect
    font=harness.r32(LABEL+0x130)
    size=struct.unpack('<H',harness.uc.mem_read(LABEL+0x13a,2))[0]
    color=harness.r32(LABEL+0x7c);align=harness.r32(LABEL+0x128)
    name=harness.texts.get(LABEL,'')
    return dict(text=name,rect=rect,font_resource_id=font,font_size=size,color=color,alignment=align,
        countdown=timer,
        native_name_bridge_installed=True,data_source='explicit PC demo service; TV reads its real manager',
        device_database=False,matched=selection['matched'],digits=digits,number=int(digits),name=name,
        fixture_path=FIXTURE.relative_to(Path(__file__).resolve().parents[1]).as_posix(),fixture_sha256=sha(FIXTURE.read_bytes()),
        helper_inputs={name:dict(va=hex(va),bytes=len(blob),sha256=sha(blob)) for name,(va,blob) in segments.items()},
        native_execution=dict(unique_instructions=len(harness.visited),executed_addresses=[hex(p) for p in sorted(harness.visited)],create=created,update=updated,start_timer=started),
        boundary='Only installed CREATE/UPDATE/START/TICK helper bytes executed; modeled widget allocation/strings/DB/route services; no tuner or full TV')
