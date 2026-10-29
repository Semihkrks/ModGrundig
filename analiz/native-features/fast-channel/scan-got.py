"""Read ELF MIPS GOT loads only; never execute target code."""
import hashlib
import json
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
INVENTORY = json.loads((ROOT / 'analiz/envanter-v2/elf-envanteri.json').read_text(encoding='utf8'))

def scan(module, names):
    b = (ROOT / 'analiz/dosya-sistemleri-tam' / module).read_bytes()
    ph, = struct.unpack_from('<I', b, 28)
    es, count = struct.unpack_from('<HH', b, 42)
    segments = [struct.unpack_from('<8I', b, ph+i*es) for i in range(count)]
    dynamic = next(x for x in segments if x[0] == 2)
    dt = dict(struct.unpack_from('<II', b, off) for off in range(dynamic[1], dynamic[1]+dynamic[4], 8))
    got, local, first = dt[3], dt[0x7000000a], dt[0x70000013]
    e = next(e for e in INVENTORY['elfs'] if e['path'] == module)
    funcs = [json.loads(x) for x in (ROOT / 'analiz/native/system-modules' / hashlib.sha256(b).hexdigest() / 'functions.jsonl').read_text().splitlines()]
    output = []
    for sym in e['symbols']:
        if not any(n in sym['name'] for n in names) or sym['index'] < first:
            continue
        slot = got+4*(local+sym['index']-first)
        imm = (slot-(got+0x7ff0)) & 65535
        for seg in segments:
            if seg[0] != 1 or not seg[6]&1:
                continue
            for off in range(seg[1], seg[1]+seg[4]-3, 4):
                word, = struct.unpack_from('<I', b, off)
                if word>>26 != 0x23 or (word>>21)&31 != 28 or word&65535 != imm:
                    continue
                va = seg[2]+off-seg[1]
                f = next((f for f in funcs if int(f['address'],16)<=va<int(f['address'],16)+f['body_bytes']), {})
                output.append(dict(module=module, symbol=sym['name'], got_slot=hex(slot), instruction_va=hex(va), word=hex(word), function=f))
    return output

if __name__ == '__main__':
    data = scan('07_MSLIB/libmsrv_common_customer.so', ['GetAvSyncTimeout'])
    data += scan('07_MSLIB/libmsrv_dvb.so', ['IsFastZappingEnable'])
    print(json.dumps(data, indent=2))
