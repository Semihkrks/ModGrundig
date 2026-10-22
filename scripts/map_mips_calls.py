"""Conservative offline MIPS32 PIC call-site index; never execute target code.

Only constants defined inside a basic block and the linked ELF GP/GOT are used.
Unknown register/vtable calls remain unknown. This is not whole-program analysis.
"""
from __future__ import annotations

from collections import Counter
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess

ROOT = Path(__file__).resolve().parents[1]
TARGET = ROOT/'analiz/dosya-sistemleri-tam/08_APP/bin/dvbt_board'
MASK = 0xffffffff


class Elf32:
    def __init__(self, path):
        self.raw = path.read_bytes()
        if self.raw[:6] != b'\x7fELF\x01\x01':
            raise ValueError('Expected ELF32 little-endian')
        h = struct.unpack_from('<HHIIIIIHHHHHH', self.raw, 16)
        if h[1] != 8:
            raise ValueError('Expected MIPS')
        self.sections = []
        for i in range(h[11]):
            v = struct.unpack_from('<10I', self.raw, h[5]+i*h[10])
            self.sections.append(dict(zip(('name_offset','type','flags','va','offset',
                                           'size','link','info','align','entsize'), v)))
        st = self.sections[h[12]]
        names = self.raw[st['offset']:st['offset']+st['size']]
        for s in self.sections:
            s['name'] = self.string(names, s['name_offset'])
        self.by_name = {s['name']: s for s in self.sections}
        self.symbols = []
        sym = self.by_name['.dynsym']
        st = self.sections[sym['link']]
        strings = self.raw[st['offset']:st['offset']+st['size']]
        for i in range(sym['size']//sym['entsize']):
            n, value, size, info, other, shndx = struct.unpack_from(
                '<IIIBBH', self.raw, sym['offset']+i*sym['entsize'])
            self.symbols.append({'index':i, 'name':self.string(strings,n), 'value':value,
                                 'size':size,'type':info&15,'shndx':shndx,
                                 'other':other,'imported':shndx==0})
        self.tags = {}
        for s in self.sections:
            if s['type']==6:
                for offset in range(s['offset'],s['offset']+s['size'],8):
                    tag, value = struct.unpack_from('<II',self.raw,offset)
                    if not tag:
                        break
                    self.tags[tag] = value
        self.got_symbols = {}
        got = self.tags[3]
        first_symbol = self.tags[0x70000013]
        locals_count = self.tags[0x7000000a]
        for symbol in self.symbols[first_symbol:]:
            self.got_symbols[got+4*(locals_count+symbol['index']-first_symbol)] = symbol
        reginfo = next((s for s in self.sections if s['type']==0x70000006),None)
        self.gp = self.u32(reginfo['va']+20) if reginfo else None

    @staticmethod
    def string(data, pos):
        return data[pos:data.index(0,pos)].decode('utf-8',errors='replace')

    def file_offset(self, va):
        for s in self.sections:
            if s['type']!=8 and s['va']<=va<s['va']+s['size']:
                return s['offset']+va-s['va']
        raise ValueError(f'Unmapped VA {va:x}')

    def u32(self, va):
        return struct.unpack_from('<I',self.raw,self.file_offset(va))[0]


def signed16(v):
    return v-65536 if v&0x8000 else v


def const(value, at, basis='local_constant'):
    return {'value':value&MASK,'defined_at':hex(at),'basis':basis}


def shift_constant(function, rs, value, amount):
    if function==0:
        return (value<<amount)&MASK
    if function==2:
        if rs==1:  # MIPS32r2 ROTR uses the SRL encoding with rs=1.
            return ((value>>amount)|(value<<(32-amount)))&MASK
        return value>>amount
    if function==3:
        return ((value if value<0x80000000 else value-0x100000000)>>amount)&MASK
    raise ValueError('Unsupported immediate shift')


def literal(v):
    return v.get('value') if v else None


def build(module='main'):
    target_path = TARGET if module=='main' else ROOT/'analiz/dosya-sistemleri-tam/07_MSLIB/libmuf.so'
    function_input = 'analiz/native/dvbt_board/functions.json' if module=='main' else 'analiz/native/libmuf/functions.json'
    fde_input = 'analiz/ui-fde-araliklari.json' if module=='main' else 'analiz/ui-muf-fde-araliklari.json'
    elf = Elf32(target_path)
    digest = hashlib.sha256(elf.raw).hexdigest()
    if module=='muf':
        # Decode only host readelf metadata; neither firmware tools nor target code run.
        if __import__('os').name=='nt':
            command = ['wsl','-d','Ubuntu','--exec','readelf','--debug-dump=frames','--wide',
                       '/mnt/c/'+str(target_path)[3:].replace('\\','/')]
        else:
            command = ['readelf','--debug-dump=frames','--wide',str(target_path)]
        frames = subprocess.run(command,text=True,capture_output=True,check=True)
        records = [{'fde_section_offset':hex(int(m[0],16)),'start':hex(int(m[1],16)),
                    'end_exclusive':hex(int(m[2],16)),'bytes':int(m[2],16)-int(m[1],16)}
                   for m in re.findall(r'^([0-9a-fA-F]+).*?\bFDE\b.*?\bpc=([0-9a-fA-F]+)\.\.([0-9a-fA-F]+)',frames.stdout,re.M)]
        (ROOT/fde_input).write_text(json.dumps({'tool':'GNU readelf --debug-dump=frames --wide',
                                             'target_sha256':digest,'records':records},indent=2)+'\n')
    fdes = json.loads((ROOT/fde_input).read_text())
    if digest != fdes['target_sha256']:
        raise ValueError('FDE target hash mismatch')
    functions = json.loads((ROOT/function_input).read_text())
    funcs = {int(f['address'],16):dict(f) for f in functions if not f['external']}
    for f in fdes['records']:
        a = int(f['start'],16)
        funcs.setdefault(a,{'name':f'FUN_{a:08x}','address':hex(a)})
        funcs[a]['fde_bytes'] = f['bytes']
    for s in elf.symbols:
        if s['type']==2 and s['value'] and not s['imported']:
            funcs.setdefault(s['value'],{'name':s['name'],'address':hex(s['value'])})
            if s['size']:
                funcs[s['value']]['symbol_bytes'] = s['size']
    # Demangle textual ELF names only; c++filt is a host tool, never target execution.
    symbols = [s['name'] for s in elf.symbols]
    cmd = ['wsl','-d','Ubuntu','--exec','c++filt'] if __import__('os').name=='nt' else ['c++filt']
    result = subprocess.run(cmd,input='\n'.join(symbols)+'\n',text=True,capture_output=True,check=True)
    demangled = result.stdout.splitlines()
    if len(demangled)!=len(symbols):
        raise ValueError('Demangle line count mismatch')
    for s, name in zip(elf.symbols,demangled):
        s['demangled'] = name
    symbol_by_va = {s['value']:s for s in elf.symbols if s['value'] and not s['imported']}
    starts = sorted(funcs)
    text = elf.by_name['.text']
    text_end = text['va']+text['size']
    calls, jumps, coverage, skipped = [], [], [], []
    got_section = elf.by_name['.got']

    def transfer(word, va, regs):
        op, rs, rt, rd = word>>26,(word>>21)&31,(word>>16)&31,(word>>11)&31
        imm, fn, sa = word&65535,word&63,(word>>6)&31
        a, b = literal(regs[rs]),literal(regs[rt])
        dst, value = None,None
        if op==15:
            dst,value = rt,const(imm<<16,va)
        elif op in (8,9,12,13,14):
            dst = rt
            if a is not None:
                val = {8:lambda:a+signed16(imm),9:lambda:a+signed16(imm),
                       12:lambda:a&imm,13:lambda:a|imm,14:lambda:a^imm}[op]()
                value = const(val,va)
        elif op==0 and fn in (0,2,3,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x2a,0x2b):
            dst = rd
            if fn in (0,2,3) and b is not None:
                value = const(shift_constant(fn,rs,b,sa),va)
            elif a is not None and b is not None:
                values = {0x20:lambda:a+b,0x21:lambda:a+b,0x22:lambda:a-b,
                          0x23:lambda:a-b,0x24:lambda:a&b,0x25:lambda:a|b,
                          0x26:lambda:a^b,0x27:lambda:~(a|b),
                          0x2a:lambda:int((a^0x80000000)<(b^0x80000000)),
                          0x2b:lambda:int(a<b)}
                value = const(values[fn](),va)
            elif fn in (0x21,0x25) and (rs==0 or rt==0):
                value = dict(regs[rt if rs==0 else rs]) if regs[rt if rs==0 else rs] else None
        elif op==35:
            dst = rt
            slot = (a+signed16(imm))&MASK if a is not None else None
            if slot is not None and got_section['va']<=slot<got_section['va']+got_section['size']:
                s = elf.got_symbols.get(slot)
                value = const(elf.u32(slot),va,'linked_got_initial_value')
                value['got_slot'] = hex(slot)
                if s:
                    value.update(symbol=s['name'],symbol_demangled=s['demangled'],
                                 symbol_imported=s['imported'])
            else:
                value = {'memory_base_register':rs,'memory_offset':signed16(imm),
                         'defined_at':hex(va),'basis':'unresolved_memory_load'}
        elif op in (10,11,32,33,34,36,37,38,48,56,60):
            dst = rt
        elif op==0 and fn in (1,4,6,7,10,11,16,18,0x2c,0x2d):
            dst = rd
        elif op in (16,17,18) and rs in (0,2):
            dst = rt
        elif op==28 and fn in (2,32,33):
            dst = rd
        elif op==31:
            dst = rt if fn in (0,4,0x3b) else rd
        if dst==28 and value is not None and literal(value) is None and function_gp is not None:
            # O32 PIC functions restore their own GP after callee calls. This is
            # an explicit invariant assumption, not a stack-memory simulation.
            value = const(function_gp,va,'PIC_function_gp_invariant_assumption')
        if dst:
            regs[dst] = value

    for i,start in enumerate(starts):
        f = funcs[start]
        if not text['va']<=start<text_end:
            skipped.append({'address':hex(start),'reason':'outside_text'})
            continue
        bound_type = 'dynamic_symbol_size' if f.get('symbol_bytes') else 'eh_frame_FDE' if f.get('fde_bytes') else 'next_known_entry_candidate'
        size = f.get('symbol_bytes') or f.get('fde_bytes') or min(f.get('body_bytes',0), (starts[i+1] if i+1<len(starts) else text_end)-start)
        if not size or size<4:
            skipped.append({'address':hex(start),'reason':'no_positive_range'})
            continue
        end = min(start+size,text_end)
        words = [(a,elf.u32(a)) for a in range(start,end-3,4)]
        function_gp = None
        if len(words)>=3:
            w0,w1,w2 = (x[1] for x in words[:3])
            if (w0>>26==15 and (w0>>16)&31==28 and w1>>26==9 and
                (w1>>21)&31==28 and (w1>>16)&31==28 and w2>>26==0 and
                w2&63==0x21 and (w2>>11)&31==28 and
                {(w2>>21)&31,(w2>>16)&31}=={25,28}):
                function_gp = (((w0&65535)<<16)+signed16(w1&65535)+start)&MASK
        leaders = {start}
        for va,w in words:
            op,rs,rt,fn = w>>26,(w>>21)&31,(w>>16)&31,w&63
            if (op in (4,5,6,7,20,21,22,23) or
                (op==1 and rt in (0,1,2,3,16,17,18,19)) or
                (op in (16,17,18) and rs==8)):
                leaders.update((va+8,(va+4+(signed16(w&65535)<<2))&MASK))
            elif op==2:
                leaders.update((va+8,((va+4)&0xf0000000)|((w&0x3ffffff)<<2)))
            elif op==0 and fn==8:
                leaders.add(va+8)
        def new_regs():
            r = [None]*32
            r[0] = const(0,start)
            r[25] = const(start,start,'PIC_entry_t9_equals_function_entry_assumption')
            if function_gp is not None:
                r[28] = const(function_gp,start,'PIC_entry_prologue_GP_derivation')
            elif elf.gp and got_section['va']-0x8000<=elf.gp<=got_section['va']+0x10000:
                r[28] = const(elf.gp,start,'linked_reginfo_gp_ABI_assumption')
            return r
        regs = new_regs()
        pending = None
        counts = Counter()
        for va,w in words:
            if va in leaders and va!=start:
                gp = regs[28]
                regs = [None]*32
                regs[0] = const(0,va)
                regs[28] = gp
            op,rs,rt,rd,fn = w>>26,(w>>21)&31,(w>>16)&31,(w>>11)&31,w&63
            if pending:
                transfer(w,va,regs)  # MIPS delay slot executes before callee receives args.
                pending['argument_candidates_a0_a3'] = [regs[x] for x in (4,5,6,7)]
                calls.append(pending)
                counts[pending['resolution']] += 1
                pending = None
                for reg in (1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,24,25,31):
                    regs[reg] = None
                continue
            kind, target = None,None
            if op==3:
                kind,target = 'jal',const(((va+4)&0xf0000000)|((w&0x3ffffff)<<2),va,'literal_instruction_target')
            elif op==0 and fn==9:
                kind,target = 'jalr',regs[rs]
            elif op==1 and rt in (16,17,18,19):
                kind,target = 'conditional_branch_and_link',const(va+4+(signed16(w&65535)<<2),va,'literal_conditional_target')
            if kind:
                name = target.get('symbol_demangled') if target else None
                value = literal(target)
                if not name and value in funcs:
                    name = funcs[value]['name']
                if not name and value in symbol_by_va:
                    name = symbol_by_va[value]['demangled']
                pending = {'function':f['name'],'function_address':hex(start),
                           'range_basis':bound_type,'site':hex(va),'word':hex(w),'kind':kind,
                           'target_candidate':target,'target_name_candidate':name,
                           'resolution':'symbolic_GOT_candidate' if target and target.get('symbol') else
                           'constant_address_candidate' if value is not None else 'unresolved_indirect',
                           'evidence':'static_instruction_and_basic_block_constant_propagation'}
                continue
            if op==0 and fn==8 and rs!=31:
                jumps.append({'function_address':hex(start),'function':f['name'],
                              'site':hex(va),'kind':'nonlink_register_tail_or_dispatch_candidate',
                              'register':rs,'target_candidate':regs[rs]})
            elif op==2:
                dest = ((va+4)&0xf0000000)|((w&0x3ffffff)<<2)
                if not start<=dest<end:
                    jumps.append({'function_address':hex(start),'function':f['name'],
                                  'site':hex(va),'kind':'nonlink_absolute_jump_outside_range_candidate',
                                  'target_candidate':const(dest,va,'literal_instruction_target')})
            transfer(w,va,regs)
        if pending:
            pending['argument_candidates_a0_a3'] = [None]*4
            pending['missing_delay_slot_in_range'] = True
            calls.append(pending)
            counts[pending['resolution']] += 1
        coverage.append({'address':hex(start),'name':f['name'],'range_basis':bound_type,
                         'gp_from_entry_prologue':hex(function_gp) if function_gp is not None else None,
                         'bytes_scanned':end-start,'call_sites':sum(counts.values()),'resolutions':dict(counts)})
    intervals = sorted((int(f['address'],16),int(f['address'],16)+f['bytes_scanned']) for f in coverage)
    cursor, uncovered = text['va'],[]
    for a,b in intervals:
        if a>cursor:
            uncovered.append({'start':hex(cursor),'end_exclusive':hex(a),'bytes':a-cursor})
        cursor = max(cursor,b)
    if cursor<text_end:
        uncovered.append({'start':hex(cursor),'end_exclusive':hex(text_end),'bytes':text_end-cursor})
    report = {'schema_version':1,'target':target_path.relative_to(ROOT).as_posix(),
              'target_sha256':digest,'method':'raw_ELF32_MIPS_instruction_decoding',
              'target_executed':False,'target_modified':False,'linked_gp':hex(elf.gp) if elf.gp else None,
              'inputs':{p:hashlib.sha256((ROOT/p).read_bytes()).hexdigest() for p in
                        (fde_input,function_input)},
              'stats':{'function_ranges':len(coverage),'call_sites':len(calls),
                       'resolution_counts':dict(Counter(c['resolution'] for c in calls)),
                       'range_basis_counts':dict(Counter(c['range_basis'] for c in coverage)),
                       'unique_call_site_addresses':len({c['site'] for c in calls}),
                       'gp_prologue_functions':sum(c['gp_from_entry_prologue'] is not None for c in coverage),
                       'nonlink_jump_candidates':len(jumps),'text_section_bytes':text['size'],
                       'text_range_bytes_covered':text['size']-sum(r['bytes'] for r in uncovered),
                       'uncovered_text_ranges':len(uncovered),
                       'skipped':len(skipped)},
              'limitations':[
                  'Static call-site candidates, not runtime bindings or an exhaustive control-flow graph.',
                  'Entry t9 and linked reginfo GP are explicit ABI assumptions.',
                  'Only supported instruction constants within straight-line basic blocks propagate; unknowns are retained.',
                  'GOT contents are initial linked values and may be rebound; imported GOT symbols take precedence over initial pointers.',
                  'ABI volatile registers are invalidated after calls; GP and saved registers are retained by ABI assumption.',
                  'A GP restored from unknown memory is replaced by the independently decoded PIC prologue GP under an explicit per-function ABI invariant assumption.',
                  'Unknown memory loads, vtable targets, cross-block values and stack arguments are not resolved.',
                  'Nonlink register jumps can be tail calls or switch dispatch; they are separate candidates and not counted as calls.',
                  'Next-entry ranges are candidates; symbol and FDE ranges are declarations, not execution observations.',
                  'Conditional branch feasibility is not evaluated; constant arguments are static candidates only.'],
              'coverage':coverage,'uncovered_text_ranges':uncovered,
              'skipped':skipped,'calls':calls,'nonlink_jump_candidates':jumps}
    path = ROOT/('analiz/ui-kod-cagrilari.json' if module=='main' else 'analiz/ui-muf-kod-cagrilari.json')
    path.write_text(json.dumps(report,ensure_ascii=False,separators=(',',':'))+'\n',encoding='utf-8')
    print(json.dumps(report['stats']))


def self_test():
    assert shift_constant(2,0,0x12345678,8)==0x00123456
    assert shift_constant(2,1,0x12345678,8)==0x78123456
    assert shift_constant(2,1,0x12345678,0)==0x12345678
    assert shift_constant(3,0,0x80000000,31)==0xffffffff
    assert shift_constant(0,0,0x80000000,1)==0
    assert signed16(0xffff)==-1 and signed16(0x8000)==-32768
    print(json.dumps({'self_test':'passed','checks':['SRL_ROTR_distinction','rotate_zero',
                                                   'arithmetic_shift','32bit_mask','signed_immediate']}))


if __name__=='__main__':
    import argparse
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--module',choices=('main','muf'),default='main')
    parser.add_argument('--self-test',action='store_true')
    args = parser.parse_args()
    self_test() if args.self_test else build(args.module)
