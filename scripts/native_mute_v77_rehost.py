"""Installed V7.7 UI event paths with explicit sound/app/surface boundaries."""
from build_native_volume_patch import elf_va_offset
import native_ui_v77_mute as code
from test_native_ui_v77_mute import Harness


def run_flow(variant,action,volume=35,muted=False,*,existing_badge=False,mode=0):
    if variant not in ('v7.7-tv','v7.9-tv') or action not in ('mute-key','timeout') or type(volume) is not int or not 0<=volume<=100 or type(muted) is not bool or type(mode) is not int or mode not in (0,1,2,3):
        raise ValueError('Invalid bounded V7.7 lifecycle input')
    from native_frame_rehost import source_file,validate_tv_inputs,sha
    validate_tv_inputs(variant)
    raw=source_file(variant,code.ELF).read_bytes()
    nums=source_file(variant,code.NUM).read_bytes()
    helper=code.code_predicate();at=elf_va_offset(raw,code.PREDICATE,len(helper))
    if raw[at:at+len(helper)]!=helper:raise ValueError('Installed timeout predicate differs')
    active_harness=Harness
    if variant=='v7.9-tv':
        from native_ui_v79_wave import HELPER,code as wave_code
        wave=wave_code();at=elf_va_offset(raw,HELPER,len(wave))
        if raw[at:at+len(wave)]!=wave:raise ValueError('Installed V7.9 lifecycle wave helper differs')
        class WaveHarness(Harness):
            def hook(self,uc,address,size,data):
                if HELPER<=address<HELPER+len(wave):
                    self.visited.add(address)
                    return
                return super().hook(uc,address,size,data)
        active_harness=WaveHarness
    h=active_harness(raw,nums,volume=volume,muted=muted,existing_badge=existing_badge,mode=mode)
    flow=h.run_key() if action=='mute-key' else h.run_timeout()
    flow.update(action=action,variant=variant,elf_sha256=sha(raw),num_sha256=sha(nums),input_volume=volume,input_muted=muted,
                native_lifecycle_instructions_executed=True,
                boundary='Actual installed OnKey→Refresh or timeout→predicate instructions; sound manager, app allocation/visibility and graphics services modeled; no full TV process')
    return flow


def render_flow(variant,action,volume=35,muted=False):
    from native_frame_rehost import render,render_mute_badge,NativePainter
    flow=run_flow(variant,action,volume,muted)
    if flow['panel_open']:
        if flow['mode']!=0:raise ValueError('Local mute key did not keep the normal volume panel')
        image,e=render(variant,flow['volume'],flow['muted'])
        if [e['progress_fill_color']]*4!=flow['fill_colors']:
            raise ValueError('Refresh paint state differs from actual OnKey→Refresh result')
        icon_ids=[x['resource_id'] for x in e['native_volume_state']['state']['image_sets'] if x['object_offset']==0x1a8]
        actual_icons=[x['id'] for x in flow['images'] if x['widget']==0x1a8]
        if icon_ids!=actual_icons:raise ValueError('Mute-key speaker image selection differs')
    elif flow['badge_visible']:
        image,e=render_mute_badge(variant)
    else:
        painter=NativePainter();image=painter.canvas;e=painter.evidence()
        e.update(variant=variant,surface_geometry={},input_assets=[],omitted=['Full device compositor and TV video'],verified_pins=None)
    e.update(scene=action,volume=flow['volume'],mute=flow['muted'],native_lifecycle=flow,
             lifecycle_executed=True,lifecycle_boundary=flow['boundary'],
             lifecycle_provenance=dict(entry='0xfb8c7c→0xfb7d18' if action=='mute-key' else '0xfb7aec',
                 rule='Installed local mute mode0; local volume0 or explicit mute may show corner badge after timeout'))
    return image,e
