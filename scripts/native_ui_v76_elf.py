"""Offline-only ELF32 MIPSEL extension. Never executes the supplied image.

The program-header table moves into the new RX mapping so Linux's
load_addr + e_phoff computation still yields the mapped PT_PHDR address.
Original section tables and original program-header bytes remain in place.
"""
import hashlib
import struct

FILE_OFFSET = 0xD60000
SEGMENT_VA = 0x1160000
CREATE_VA = SEGMENT_VA + 0x100
UPDATE_VA = SEGMENT_VA + 0x800
MAX_SEGMENT_SIZE = 0x10000
CODE_LIMIT = 0x2000
PH = struct.Struct('<8I')


def _uleb(value):
    if value < 0: raise ValueError('Negative ULEB')
    out=bytearray()
    while True:
        byte=value & 127;value >>= 7
        out.append(byte | (128 if value else 0))
        if not value:return bytes(out)


def _unwind(elf, original, frames):
    """Build independent CIE/FDEs and rebase the complete binary search index."""
    old=next((p for p in original if p[0]==0x6474E550),None)
    if old is None:raise ValueError('PT_GNU_EH_FRAME required')
    off,va,size=old[1],old[2],old[4]
    if off+size>len(elf) or elf[off:off+4]!=bytes([1,0x1b,3,0x3b]):
        raise ValueError('Unsupported original EH header encodings')
    frame_delta,count=struct.unpack_from('<iI',elf,off+4)
    if size!=12+count*8:raise ValueError('EH table size mismatch')
    pairs=[tuple(va+x for x in struct.unpack_from('<ii',elf,off+12+i*8)) for i in range(count)]
    if any(pairs[i][0]>=pairs[i+1][0] for i in range(len(pairs)-1)):
        raise ValueError('Original EH index not strictly ordered')
    # zR; absolute FDE PC encoding; code align4, data align-4, return register31.
    cie_body=b'\0\0\0\0\x01zR\0\x04\x7c\x1f\x01\x00\x0c\x1d\x00'
    for register in list(range(16,23))+[28,30,31]:cie_body+=b'\x08'+_uleb(register)
    cie_body+=bytes((-len(cie_body))%4)
    payload=bytearray(struct.pack('<I',len(cie_body))+cie_body)
    rows=[]
    for frame in frames:
        start,length=frame['start'],frame['size']
        if start not in (CREATE_VA,UPDATE_VA,SEGMENT_VA+0x1000,SEGMENT_VA+0x1400) or length<=0 or length%4:raise ValueError('Invalid unwind range')
        fde_offset=len(payload);instructions=bytearray();position=0
        for event in frame['events']:
            pc=event['pc']
            if pc<position or pc>length or pc%4:raise ValueError('Invalid CFI event PC')
            delta=(pc-position)//4
            if delta:
                instructions.extend(bytes([0x40+delta]) if delta<64 else b'\x04'+struct.pack('<I',delta))
            position=pc
            if 'cfa_offset' in event:instructions.extend(b'\x0e'+_uleb(event['cfa_offset']))
            for register,offset in event.get('offsets',{}).items():
                if not 0<=register<32 or offset>0 or offset%4:raise ValueError('Invalid saved register')
                instructions.extend(bytes([0x80+register])+_uleb(-offset//4))
            for register in event.get('restores',[]):
                if not 0<=register<32:raise ValueError('Invalid restored register')
                instructions.append(0xc0+register)
        body=struct.pack('<III',fde_offset+4,start,length)+b'\x00'+instructions
        body+=bytes((-len(body))%4)
        payload.extend(struct.pack('<I',len(body))+body)
        pairs.append((start,SEGMENT_VA+0x2000+fde_offset))
        rows.append(frame)
    payload.extend(bytes(4))
    header_offset=0x2000+len(payload)
    header_va=SEGMENT_VA+header_offset
    pairs.sort()
    if len({p[0] for p in pairs})!=len(pairs):raise ValueError('Duplicate EH search PC')
    header=bytearray(bytes([1,0x1b,3,0x3b])+struct.pack('<iI',va+4+frame_delta-(header_va+4),len(pairs)))
    for pc,fde in pairs:header.extend(struct.pack('<ii',pc-header_va,fde-header_va))
    payload.extend(header)
    ph=(old[0],FILE_OFFSET+header_offset,header_va,header_va,len(header),len(header),4,4)
    proof={'original_entries':count,'merged_entries':len(pairs),'old_entries_preserved':all((va+struct.unpack_from('<i',elf,off+12+i*8)[0],va+struct.unpack_from('<i',elf,off+16+i*8)[0]) in pairs for i in range(count)), 'header_va':header_va,'new_frames':rows,'temporary_cleanup_on_exception':False}
    return bytes(payload),ph,proof


def headers(elf):
    if len(elf) < 52 or elf[:7] != b'\x7fELF\x01\x01\x01':
        raise ValueError('ELF32 little-endian version 1 required')
    if struct.unpack_from('<HHI', elf, 16) != (2, 8, 1):
        raise ValueError('ET_EXEC MIPS required')
    offset = struct.unpack_from('<I', elf, 28)[0]
    size, count = struct.unpack_from('<HH', elf, 42)
    if size != 32 or count != 7 or offset != 52 or offset + count * size > len(elf):
        raise ValueError('Unexpected original program-header table')
    return [PH.unpack_from(elf, offset + i * size) for i in range(count)]


def append_payload(elf: bytes, code_create: bytes, code_update: bytes, *, unwind_frames=None, extras=()):
    """Return an extended copy and auditable placement proof; reject drift."""
    original = headers(elf)
    loads = [p for p in original if p[0] == 1]
    if not loads or loads[0][1:4] != (0, 0x400000, 0x400000) or loads[0][4] != 0xC1D800:
        raise ValueError('Unexpected first LOAD profile')
    if loads[-1][1:6] != (0xCBD3D4, 0x10ED3D4, 0x10ED3D4, 0x720E2, 0x720E2):
        raise ValueError('Unexpected final LOAD profile')
    if sum(p[0] == 6 for p in original) != 1 or original[0][0] != 6:
        raise ValueError('Expected leading PT_PHDR')
    if len(elf) > FILE_OFFSET:
        raise ValueError('New segment would overlap existing file')
    if not code_create or not code_update or len(code_create) % 4 or len(code_update) % 4:
        raise ValueError('Nonempty word-aligned MIPS helpers required')
    if len(code_create) > UPDATE_VA - CREATE_VA or len(code_update) > CODE_LIMIT - 0x800:
        raise ValueError('Helper exceeds reserved slot')
    for p in loads:
        if p[4] > p[5] or p[1] + p[4] > len(elf):
            raise ValueError('Invalid original LOAD bounds')
        if p[2] + p[5] > SEGMENT_VA or p[1] + p[4] > FILE_OFFSET:
            raise ValueError('New LOAD overlaps original LOAD')
        if p[7] > 1 and (p[7] & (p[7]-1) or p[1] % p[7] != p[2] % p[7]):
            raise ValueError('Invalid original LOAD alignment')
    for i, p in enumerate(loads):
        for q in loads[i+1:]:
            if max(p[2],q[2]) < min(p[2]+p[5],q[2]+q[5]):
                raise ValueError('Original LOAD ranges overlap')
    ranges=[(CREATE_VA,code_create),(UPDATE_VA,code_update),*list(extras)]
    if len(ranges)!=4 or {va for va,_ in ranges}!={CREATE_VA,UPDATE_VA,SEGMENT_VA+0x1000,SEGMENT_VA+0x1400}:
        raise ValueError('Exact four V7.6 helpers required')
    ranges.sort()
    for i,(va,raw) in enumerate(ranges):
        end=ranges[i+1][0] if i+1<len(ranges) else SEGMENT_VA+CODE_LIMIT
        if not raw or len(raw)%4 or va+len(raw)>end:raise ValueError('V7.6 helper slot overlap/empty')
    segment_size=max(va-SEGMENT_VA+len(raw) for va,raw in ranges)
    moved = list(original)
    unwind_proof=None;unwind_payload=b''
    if unwind_frames is not None:
        if len(unwind_frames)!=4 or {f['start']:f['size'] for f in unwind_frames}!={va:len(raw) for va,raw in ranges}:
            raise ValueError('All four complete helper ranges need FDEs')
        unwind_payload,unwind_ph,unwind_proof=_unwind(elf,original,unwind_frames)
        moved=[unwind_ph if p[0]==0x6474E550 else p for p in moved]
        segment_size=0x2000+len(unwind_payload)
        if segment_size>MAX_SEGMENT_SIZE:raise ValueError('Unwind segment exceeds 64KiB cap')
    moved[0] = (6, FILE_OFFSET, SEGMENT_VA, SEGMENT_VA, 8 * 32, 8 * 32, original[0][6], original[0][7])
    moved.append((1, FILE_OFFSET, SEGMENT_VA, SEGMENT_VA, segment_size, segment_size, 5, 0x10000))
    segment = bytearray(segment_size)
    for i, p in enumerate(moved):
        PH.pack_into(segment, i * 32, *p)
    segment[0x100:0x100 + len(code_create)] = code_create
    segment[0x800:0x800+len(code_update)] = code_update
    for va,raw in extras:segment[va-SEGMENT_VA:va-SEGMENT_VA+len(raw)]=raw
    if unwind_payload:segment[0x2000:]=unwind_payload
    result = bytearray(elf)
    struct.pack_into('<I', result, 28, FILE_OFFSET)
    struct.pack_into('<H', result, 44, 8)
    result.extend(bytes(FILE_OFFSET - len(result)))
    result.extend(segment)
    assert SEGMENT_VA == 0x400000 + FILE_OFFSET
    assert FILE_OFFSET % 0x10000 == SEGMENT_VA % 0x10000
    proof = {'input_sha256': hashlib.sha256(elf).hexdigest(),
             'output_sha256': hashlib.sha256(result).hexdigest(),
             'file_offset': FILE_OFFSET, 'segment_va': SEGMENT_VA,
             'create_va': CREATE_VA, 'update_va': UPDATE_VA,
             'segment_size': segment_size, 'phnum': 8,
             'original_phdr_bytes_preserved': result[52:276] == elf[52:276],
             'at_phdr': 0x400000 + FILE_OFFSET,
             'original_load_changes': [{'offset': a, 'size': b} for a, b in [(28, 4), (44, 2)]],
             'section_table_unchanged': result[32:36] == elf[32:36],
             'dynamic_and_mips_got_untouched': True,
             'unwind':unwind_proof,
             'device_tested': False}
    return bytes(result), proof
