"""Join observed firmware relationships into a queryable offline graph."""
from collections import Counter
from pathlib import Path
import json

ROOT = Path(__file__).resolve().parents[1]
ANALYSIS = ROOT/'analiz'

def read(name):
    return json.loads((ANALYSIS/name).read_text(encoding='utf-8'))

if __name__ == '__main__':
    nodes = {}
    edges = []
    def node(identifier, kind, **facts):
        nodes.setdefault(identifier, {'id': identifier, 'kind': kind, **facts})
        return identifier
    def edge(source, target, relationship, status, **evidence):
        edges.append({'source': source, 'target': target, 'relationship': relationship,
                      'status': status, 'evidence': evidence})
    def file(path):
        return node('file:'+path, 'firmware_file', path=path)
    package = node('package:GM_SWImage.bin', 'upgrade_package')
    sections = read('bolum-haritasi.json')
    for section in sections['sections']:
        target = node('payload:'+str(section['ordinal']), 'payload',
                      label=section.get('write_target', section['label']),
                      sha256=section['output_sha256'], format=section['identification']['format'])
        edge(package, target, 'contains_compressed_range', 'observed_data',
             record='bolum-haritasi.json', offset=section['source_offset'],
             compressed_bytes=section['compressed_bytes'], crc_matches=section['crc32_validation']['matches_declaration'])
    inventory = read('dosya-envanteri.json')
    for entry in inventory['files']:
        if entry['type'] == 'directory':
            continue
        identifier = file(entry['path'])
        nodes[identifier].update(type=entry['type'], sha256=entry.get('sha256'))
        if entry['type'] == 'symlink':
            target = node('symlink-target:'+entry['path'], 'virtual_link_target',
                          text=entry['target'], host_followed=False)
            edge(identifier, target, 'symlink_text', 'observed_data', record='dosya-envanteri.json')
    for row in read('bagimliliklar.json')['edges']:
        dependency = node('needed:'+row['source']+':'+row['needed'], 'needed_library', name=row['needed'])
        edge(file(row['source']), dependency, 'DT_NEEDED', 'observed_data', record='bagimliliklar.json')
        for candidate in row['candidates']:
            edge(dependency, file(candidate['path']), 'may_resolve_to', 'candidate',
                 record='bagimliliklar.json', runtime_resolved=False, match=candidate['match'])
    ui = read('ui-kaynak-haritasi.json')
    for table in ui['image_resource_tables']:
        source = node('resource-table:'+table['path'], 'resource_table', path=table['path'], sha256=table['sha256'])
        for record in table['records']:
            target = node(source+':index:'+str(record['index_zero_based']), 'resource_record',
                          declared_path=record['resource_path'], sha256=record['asset_sha256'])
            edge(source, target, 'declares_resource_path', 'observed_data',
                 record='ui-kaynak-haritasi.json', index=record['index_zero_based'],
                 byte_offset=record['path_offset'], resolution=record['resolution_status'])
    for keymap in ui['keymaps']:
        source = node('keymap:'+keymap['path'], 'keymap', path=keymap['path'])
        for record in keymap['rows']:
            target = node('muf-key:'+record['key_symbol_hex'], 'muf_key', value=record['key_symbol_hex'])
            edge(source, target, 'maps_hardware_key', 'observed_data',
                 record='ui-kaynak-haritasi.json', line=record['line'],
                 hardware=record['hardware_keycode_hex'], label=record['mvk_comment_name'])
    for match in ui['asset_matches']:
        source = node('supplied:'+match['supplied']['path'], 'supplied_asset', sha256=match['supplied']['sha256'])
        for actual in match['firmware_matches']:
            target = node('asset:'+actual['path'], 'asset', path=actual['path'], sha256=actual['sha256'])
            edge(source, target, 'identical_sha256', 'observed_data', record='ui-kaynak-haritasi.json')
    boot = [
        ('06_RFS/etc/inittab', '06_RFS/etc/init.d/rcS', 'sysinit', 1),
        ('06_RFS/etc/init.d/rcS', '11_customer_update', 'mount_customer_update', 8),
        ('06_RFS/etc/init.d/rcS', '10_customer', 'mount_customer', 9),
        ('11_customer_update/profile', '07_MSLIB', 'mount_/mslib', 53),
        ('11_customer_update/profile', '08_APP', 'mount_/applications', 60),
        ('11_customer_update/profile', '09_CONFIG', 'mount_/config', 63),
        ('11_customer_update/profile', '09_CONFIG/krl/ir/mdrv-ir.ko', 'loads_IR_module', 77),
        ('11_customer_update/profile', '08_APP/bin/autorun', 'executes_relative_to_applications_bin', 115),
    ]
    for source, target, relation, line in boot:
        edge(file(source), file(target), relation, 'observed_script_text', line=line, executed_on_TV=False)
    native = ANALYSIS/'native/dvbt_board'
    if (native/'functions.json').exists() and (native/'callgraph.json').exists():
        for function in json.loads((native/'functions.json').read_text(encoding='utf-8')):
            node('dvbt:'+function['address'], 'function', **function)
        for row in json.loads((native/'callgraph.json').read_text(encoding='utf-8')):
            for target in row['calls']:
                edge(node('dvbt:'+row['from'], 'function'), node('dvbt:'+target, 'function'),
                     'ghidra_observed_call_target', 'static_analysis',
                     record='native/dvbt_board/callgraph.json', runtime_verified=False)
    report = {'schema_version': 1, 'nodes': list(nodes.values()), 'edges': edges,
              'counts': {'nodes': len(nodes), 'edges': len(edges),
                         'relationships': dict(Counter(x['relationship'] for x in edges)),
                         'statuses': dict(Counter(x['status'] for x in edges))},
              'limitations': ['No edge claims a device runtime observation.',
                              'Missing resource targets and unresolved library candidates remain explicit.',
                              'Ghidra graph can omit unresolved indirect calls; see native analysis logs.',
                              'Package offsets, extracted file offsets and virtual addresses are separate scopes.']}
    (ANALYSIS/'baglanti-grafi.json').write_text(json.dumps(report, ensure_ascii=False, indent=2)+'\n', encoding='utf-8')
    print(json.dumps(report['counts'], ensure_ascii=False))
