"""Add one verified TRT4K RF transponder to a separate stock-default archive.

No channel record, decoder capability, panel timing or user database is patched.
"""
import gzip
import hashlib
import io
import re
import struct
import tarfile
import xml.etree.ElementTree as ET
import zlib

RELATIVE = '08_APP/defaults/frequency_tables.tar.gz'
SOURCE_SHA = '4395205081af99ca7514b8527ca221000a2f1769befd22ac0339caf156f68765'
XML_SHA = '977344f21ebb6d86b6df57062eafc92181d231e2e756ddbe78c77a721e2a1975'
MEMBER = 'satellite_list.xml'
TARGET = dict(frequency='11767000', polarization='VERTICAL', symbol_rate='15000000',
              modulation_system='DVB_S2', modulation_type='PSK_8', fec_inner='FEC_3_4')
SOURCE_URL = 'https://www.trt.net.tr/corporate/faq/2'


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def read_xml(raw):
    if len(raw) > 1000000:
        raise ValueError('Unexpected RF archive size')
    with tarfile.open(fileobj=io.BytesIO(raw), mode='r:gz') as archive:
        members = archive.getmembers()
        if len(members) != 1 or members[0].name != MEMBER or not members[0].isfile():
            raise ValueError('Expected the single regular satellite-list member')
        if members[0].size > 1000000:
            raise ValueError('Unexpected satellite-list size')
        return archive.extractfile(members[0]).read(), members[0]


def transform(original):
    if sha(original) != SOURCE_SHA:
        raise ValueError('Pinned stock frequency archive differs')
    xml, member = read_xml(original)
    if sha(xml) != XML_SHA or member.offset != 0 or member.offset_data != 512:
        raise ValueError('Pinned archive layout differs')
    tree = ET.fromstring(xml)
    satellites = [s for s in tree if s.attrib.get('position') == '420']
    if len(satellites) != 1:
        raise ValueError('Ambiguous Turksat satellite')
    sat = satellites[0]
    if len(sat) != 79 or sat.attrib.get('numberofTP') != '79':
        raise ValueError('Pinned Turksat table differs')
    if any(t.attrib.get('frequency') == TARGET['frequency'] for t in sat):
        raise ValueError('Target frequency already exists; review instead of duplicating')
    tag = re.search(rb'<sat\b[^>]*\bposition="420"[^>]*>', xml)
    if not tag or xml.count(tag.group()) != 1:
        raise ValueError('Satellite tag does not have a unique byte location')
    changed_tag = tag.group().replace(b'numberofTP="79"', b'numberofTP="80"')
    if changed_tag == tag.group():
        raise ValueError('Missing declared transponder count')
    ending = re.match(rb'[\r\n]+', xml[tag.end():])
    if not ending:
        raise ValueError('Unexpected XML line ending')
    line = b'    <transponder ' + b' '.join(k.encode() + b'="' + v.encode() + b'"'
                                            for k, v in TARGET.items()) + b' />'
    replacement = changed_tag + ending.group() + line
    new_xml = xml[:tag.start()] + replacement + xml[tag.end():]
    # Retain the original tar header, owner/mode/time, block layout and trailer.
    raw_tar = gzip.decompress(original)
    old_end = 512 + ((member.size + 511) // 512) * 512
    if 512 + len(new_xml) > old_end or len(raw_tar) > 1000000:
        raise ValueError('The bounded update no longer fits the original tar block')
    header = bytearray(raw_tar[:512])
    header[124:136] = ('%011o\0' % len(new_xml)).encode('ascii')
    header[148:156] = b' ' * 8
    header[148:156] = ('%06o\0 ' % sum(header)).encode('ascii')
    new_tar = bytes(header) + new_xml + bytes(old_end - 512 - len(new_xml)) + raw_tar[old_end:]
    if original[:4] != b'\x1f\x8b\x08\x00':
        raise ValueError('Unexpected gzip header options')
    compressor = zlib.compressobj(level=6, wbits=-15)
    packed = compressor.compress(new_tar) + compressor.flush()
    candidate = original[:10] + packed + struct.pack('<II', zlib.crc32(new_tar), len(new_tar))
    parsed_xml, new_member = read_xml(candidate)
    new_tree = ET.fromstring(parsed_xml)
    new_sat = next(s for s in new_tree if s.attrib.get('position') == '420')
    if dict(new_sat[0].attrib) != TARGET or len(new_sat) != 80:
        raise ValueError('New transponder did not roundtrip')
    if [dict(t.attrib) for t in new_sat][1:] != [dict(t.attrib) for t in sat]:
        raise ValueError('An existing transponder changed')
    for old, new in zip(tree, new_tree):
        if old.attrib.get('position') != '420' and ET.tostring(old) != ET.tostring(new):
            raise ValueError('An unrelated satellite changed')
    for field in ('name', 'mode', 'uid', 'gid', 'mtime', 'type', 'uname', 'gname'):
        if getattr(member, field) != getattr(new_member, field):
            raise ValueError('Archive member metadata changed: ' + field)
    proof = dict(kind='RF default transponder data update, not a codec unlock', checked='2026-10-27',
                 source_sha256=SOURCE_SHA, candidate_sha256=sha(candidate), member=MEMBER,
                 original_xml_sha256=XML_SHA, xml_sha256=sha(new_xml), official_source=SOURCE_URL,
                 satellite_position='420', transponders_before=79, transponders_after=80,
                 added=TARGET, original_tp_and_other_satellites_preserved=True,
                 user_channel_database_modified=False, decoder_or_panel_modified=False,
                 live_device_reloaded=False, physical_tv_tested=False)
    return candidate, proof
