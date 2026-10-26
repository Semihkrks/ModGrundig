"""Build an offline TV menu model from retained UI-only resource evidence.

Does not run firmware, use a decompiler, contact a device or modify sources.
Control ranges, initial values and selectable combinations are simulator policy,
not recovered device calibration or a claim of hardware availability.
"""
from __future__ import annotations
import hashlib
import json
import re
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
TABLE = ROOT / 'analiz/dosya-sistemleri-tam/08_APP/rc/rc_Turkish/bin/Str_res.bin'
data = TABLE.read_bytes()
assert data[:4] == b'_tsm' and struct.unpack_from('<I', data, 8)[0] == 3
texts = []
pos = 56
for index in range(struct.unpack_from('<I', data, 28)[0]):
    size = struct.unpack_from('<I', data, pos)[0]
    assert size > 0 and data[pos + 3 + size] == 0
    texts.append({'stringId': index, 'offset': pos + 4,
                  'text': data[pos + 4:pos + 3 + size].decode('utf-8')})
    pos += size + 4
assert pos == len(data)

SOURCE = {
    'picture': {'function': 'PictureSettingsFrame', 'address': '0xe28b14', 'file': 'analiz/native/ui-targeted/dvbt_board/00e28b14.c'},
    'sound': {'function': 'SoundSettingsFrame', 'address': '0xee9afc', 'file': 'analiz/native/ui-targeted/dvbt_board/00ee9afc.c'},
    'source': {'function': 'SourceSetupFrame', 'address': '0xf0dd24', 'file': 'analiz/native/ui-deep/source-setup-payload128/00f0dd24.c'},
    'general': {'function': 'GeneralSettingsFrame', 'address': '0xd01710', 'file': 'analiz/native/ui-four/general/bounded300/00d01710.c'},
    'home': {'function': 'HomePageFrame', 'address': '0xd42150', 'file': 'analiz/native/ui-four/home/conly600/00d42150.c'},
    'parental': {'function': 'ParentalControlFrame constructor-body candidate', 'address': '0xe001bc', 'file': 'analiz/ui-kod-cagrilari.json'},
    'timer': {'function': 'Timer settings constructor-body candidate', 'address': '0xf404b8', 'file': 'analiz/ui-kod-cagrilari.json'},
}
general = json.loads((ROOT / 'analiz/native/ui-four/general/widget-resource-groups.json').read_text(encoding='utf-8'))['widgets']
general_labels = {}
for widget in general:
    for label in widget.get('label_string_candidates', []):
        general_labels.setdefault(label['id'], []).append({
            'widgetId': widget['widget_id'], 'constructor': widget['constructor_site'],
            'stringCall': label['site'],
            'handlers': widget.get('event_0x16_selector_handler_candidates', []),
        })

native_labels = {}
for name, source in SOURCE.items():
    if not source['file'].endswith('.c'):
        continue
    code = (ROOT / source['file']).read_text(encoding='utf-8')
    for match in re.finditer(r'PTR_Set_010c61fc\)\([^;]+;', code):
        ids = re.findall(r',\s*(0x[0-9a-f]+|[0-9]+)\);', match.group())
        if ids:
            native_labels.setdefault((name, int(ids[-1], 0)), []).append(code.count('\n', 0, match.start()) + 1)

# This retained index decodes argument constants from MIPS instructions. It is
# static call-site evidence; it is not execution or a new decompilation.
raw = json.loads((ROOT / 'analiz/ui-kod-cagrilari.json').read_text(encoding='utf-8'))
raw_strings = {}
for call in raw['calls']:
    if not (call.get('target_name_candidate') or '').startswith('MString::Set'):
        continue
    arguments = call.get('argument_candidates_a0_a3') or []
    if len(arguments) > 1 and arguments[1] is not None:
        sid = arguments[1].get('value')
        raw_strings.setdefault(sid, []).append({
            'function': call['function'], 'functionAddress': call['function_address'],
            'site': call['site'], 'target': call['target_name_candidate'],
            'basis': 'retained_static_instruction_argument_candidate',
        })
del raw

MENUS = {}
def menu(key, title, source, title_id=None):
    MENUS[key] = {'title': texts[title_id]['text'] if title_id is not None else title,
                  'source': SOURCE[source], 'rows': []}
    return MENUS[key]

def row(menu_key, key, sid, kind, value=None, *, source=None, options=None, **extra):
    source = source or {'picture': 'picture', 'sound': 'sound', 'source': 'source'}.get(menu_key, 'general')
    label = texts[sid]
    binding = general_labels.get(sid, []) if source == 'general' else []
    lines = native_labels.get((source, sid), [])
    callsites = [c for c in raw_strings.get(sid, []) if c['functionAddress'] == SOURCE[source]['address']]
    item = {'id': key, 'label': label['text'], 'type': kind, 'value': value,
            'evidence': {'stringId': sid, 'stringOffset': label['offset'],
                         'sourceFunction': SOURCE[source]['function'],
                         'sourceAddress': SOURCE[source]['address'],
                         'sourceFile': SOURCE[source]['file'],
                         'labelBasis': 'retained_widget_binding' if binding else 'retained_C_string_assignment' if lines else 'retained_static_string_call' if callsites else 'resource_text_only',
                         'C_lines': lines, 'widgetBindings': binding,
                         'stringCallsites': callsites,
                         'otherUIStringCallCandidates': raw_strings.get(sid, [])[:12] if not callsites and not binding and not lines else [],
                         'interaction': 'offline_simulator', 'defaults': 'demo',
                         'rangeAndOptionGrouping': 'simulator_policy', 'deviceAvailabilityVerified': False}, **extra}
    if options is not None:
        item['options'] = [texts[i]['text'] if isinstance(i, int) else i for i in options]
        item['evidence']['optionStringIds'] = [i if isinstance(i, int) else None for i in options]
        if value is None:
            item['value'] = item['options'][0]
    MENUS[menu_key]['rows'].append(item)

def slider(m, key, sid, value=50, minimum=0, maximum=100, **kw):
    row(m, key, sid, 'range', value, min=minimum, max=maximum, step=1, **kw)

def choice(m, key, sid, opts, **kw):
    row(m, key, sid, 'choice', options=opts, **kw)

def toggle(m, key, sid, value=False, **kw):
    row(m, key, sid, 'toggle', value, **kw)

def link(m, key, sid, destination, **kw):
    row(m, key, sid, 'submenu', menu=destination, **kw)

def action(m, key, sid, action_id, **kw):
    row(m, key, sid, 'action', action=action_id, **kw)

menu('picture', '', 'picture', 3747)
choice('picture', 'picture-mode', 3745, [4000, 4169, 4097, 3119])
slider('picture', 'picture-backlight', 3141, 70)
slider('picture', 'picture-brightness', 3749)
slider('picture', 'picture-contrast', 3751, 70)
slider('picture', 'picture-color', 3750)
slider('picture', 'picture-sharpness', 3752, 40)
choice('picture', 'picture-temperature', 3203, [3205, 3204, 3206])
choice('picture', 'picture-format', 4485, [3054, 2214, 2215])
choice('picture', 'picture-noise', 65, [3654, 3528, 3681, 3478])
choice('picture', 'picture-dynamic-contrast', 3340, [3654, 3528, 3681, 3478])
action('picture', 'picture-reset', 72, 'reset-picture')

menu('sound', '', 'sound', 3997)
slider('sound', 'sound-volume', 4174, 32)
choice('sound', 'sound-mode', 3994, [4000, 3115, 4097, 3119, 3120])
slider('sound', 'sound-balance', 3142, 0, -50, 50)
toggle('sound', 'sound-avl', 2193)
toggle('sound', 'sound-night', 3631)
link('sound', 'sound-equalizer', 3389, 'equalizer')
slider('sound', 'sound-headphones', 92, 30)
toggle('sound', 'sound-speakers', 4058, True)
choice('sound', 'sound-digital-output', 3671, [109, 3054])
action('sound', 'sound-reset', 124, 'reset-sound')
menu('equalizer', '', 'sound', 3389)
for key, sid in [('120', 2042), ('500', 2130), ('1500', 2074), ('5000', 2135), ('10000', 2034)]:
    slider('equalizer', f'equalizer-{key}', sid, 0, -12, 12, source='sound', unit='dB')

menu('source', '', 'source', 4091)
choice('source', 'source-input', 4001, [3293, 3847, 3169, 393, 394, 395, 396, 3857])
link('source', 'source-channels', 3022, 'channels')
choice('source', 'source-antenna', 4216, [3083, 3169, 3847])
action('source', 'source-auto-search', 3850, 'scan-channels')
action('source', 'source-manual-search', 4429, 'manual-scan')

menu('tv', '', 'general', 3913)
link('tv', 'tv-language', 4423, 'language')
link('tv', 'tv-accessibility', 3058, 'accessibility')
link('tv', 'tv-advanced', 128, 'advanced')
link('tv', 'tv-about', 4206, 'about')

menu('language', '', 'general', 4423)
for key, sid in [('menu', 4431), ('audio', 4221), ('subtitle', 4553), ('keyboard', 4421)]:
    choice('language', f'language-{key}', sid, [2598, 509])

menu('accessibility', '', 'general', 3058)
toggle('accessibility', 'accessibility-audio-description', 3111)
choice('accessibility', 'accessibility-subtitle-mode', 4025, [3654, 3330])
slider('accessibility', 'accessibility-description-volume', 4219)
toggle('accessibility', 'accessibility-subtitles', 4024)

menu('advanced', '', 'general', 128)
choice('advanced', 'advanced-auto-off', 3128, [3654, 4564, 4565, 4566, 4567])
toggle('advanced', 'advanced-fast-channel', 3408, True)
choice('advanced', 'advanced-power-led', 3767, [3681, 3654, 3528, 3478])
toggle('advanced', 'advanced-power-save', 3771)
toggle('advanced', 'advanced-help', 4288, True)
toggle('advanced', 'advanced-fast-start', 4357)

menu('about', '', 'general', 4206)
row('about', 'about-product', 4499, 'info', 'Çevrimdışı TV simülatörü')
row('about', 'about-version', 3838, 'info', 'GMGRMR V03.017.04 · kaynak paket')
row('about', 'about-tv-name', 4057, 'info', 'Grundig TV · demo')
action('about', 'about-clear-history', 4506, 'clear-history')
action('about', 'about-factory-reset', 3811, 'reset-all')

menu('parental', '', 'parental', 3735)
toggle('parental', 'parental-menu-lock', 3734, source='parental')
toggle('parental', 'parental-source-lock', 4004, source='parental')
toggle('parental', 'parental-channel-lock', 3187, source='parental')
choice('parental', 'parental-rating', 3835, [3654, 4579, 4577, 4578], source='parental')
action('parental', 'parental-change-pin', 3182, 'change-pin', source='parental')

menu('timer', '', 'timer', 4069)
choice('timer', 'timer-sleep', 3981, [3654, '15 dk.', '30 dk.', '60 dk.', '90 dk.', '120 dk.'], source='timer')
choice('timer', 'timer-shutdown', 3129, [3654, '30 dk.', '60 dk.', '120 dk.'], source='timer')
choice('timer', 'timer-startup', 3130, [3654, '15 dk.', '30 dk.', '60 dk.'], source='timer')
slider('timer', 'timer-start-volume', 4013, 20, source='timer')

menu('channels', '', 'source', 4059)
action('channels', 'channels-open-list', 4059, 'open-channels', source='source')
action('channels', 'channels-favorites', 3415, 'open-favorites', source='source')
choice('channels', 'channels-service-type', 4576, ['TV', 'Radyo'], source='source')
action('channels', 'channels-auto-search', 3133, 'scan-channels', source='source')
action('channels', 'channels-signal', 3972, 'signal-info', source='source')

rows = [r for m in MENUS.values() for r in m['rows']]
assert len({r['id'] for r in rows}) == len(rows)
assert all(r.get('menu') in MENUS for r in rows if r['type'] == 'submenu')
assert all(r['value'] in r['options'] for r in rows if r['type'] == 'choice')
assert all(r['min'] <= r['value'] <= r['max'] for r in rows if r['type'] == 'range')

evidence = {
    'schemaVersion': 1, 'date': '2026-10-23', 'skill': 'reverse-engineer-anything',
    'targetExecuted': False, 'targetModified': False, 'deviceObserved': False,
    'method': 'local_UI_string_table_and_retained_static_analysis',
    'notREA_Evidence': True,
    'table': {'path': TABLE.relative_to(ROOT).as_posix(), 'sha256': hashlib.sha256(data).hexdigest(), 'records': len(texts)},
    'scope': 'Base UI labels only; extended active catalogue and callsite checks are in feature-coverage.json. No keys, certificates or device identifiers read.',
    'limits': [
        'All initial values, slider limits, units and option groupings are offline simulator policy, not recovered calibration.',
        'A string label alone does not prove its row is enabled on the physical TV.',
        'resource_text_only rows retain string evidence and menu context; a specific row call address is not asserted.',
        'Options with null optionStringIds are explicitly demo text, not firmware enum recovery.',
        'Timer selections describe relative demo delays; native timer scheduling semantics are not claimed.',
        'This is the generated 68-row base. Host-only extensions add recording/update paths via extra-menu-data.js; network, Web, apps and unverified hardware modes stay excluded.',
    ],
    'counts': {'menus': len(MENUS), 'rows': len(rows),
               'nativeLabelBindings': sum(r['evidence']['labelBasis'] != 'resource_text_only' for r in rows)},
    'menus': MENUS,
}
output = ROOT / 'analiz/ui-modernizasyon/menu-schema-evidence.json'
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(evidence, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
(ROOT / 'ui-preview/firmware-menu-data.js').write_text(
    '// Generated by scripts/export_tv_menu_schema.py; all control values are offline demo policy.\n'
    'export const MENUS = ' + json.dumps(MENUS, ensure_ascii=False, indent=2) + ';\n'
    "import {extendMenus} from './extra-menu-data.js';\nextendMenus(MENUS);\n", encoding='utf-8')
print(json.dumps(evidence['counts']))
