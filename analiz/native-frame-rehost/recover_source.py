"""Restore this renderer's exact successful patches from its two local agent logs.

Reads only renderer apply_patch tool inputs, never user text or arbitrary commands.
The zero-filled file is the only source target permitted; output is reviewed again
with all existing rendering tests. Kept as an auditable recovery record.
"""
from pathlib import Path
import hashlib
import json

ROOT=Path(__file__).resolve().parents[2]
TARGET=ROOT/'scripts/native_frame_rehost.py'
LOGROOT=Path('C:/Users/Semih/.codex/sessions/2026/10/24')
SELECTIONS=(('rollout-2026-10-24T03-52-14-01a16b64-dbdd-7d83-8ca5-fd102109adb9.jsonl',(119,138)),
            ('rollout-2026-10-24T11-54-00-01a16d1d-ee6f-7f80-b5f1-e15d137585f9.jsonl',(92,102,122,141,151,171,259)))
source=[]
records=[]
for filename,indices in SELECTIONS:
    events=[json.loads(line) for line in (LOGROOT/filename).read_text(encoding='utf-8').splitlines()]
    for index in indices:
        code=events[index]['payload']['input']
        start=code.index('tools.apply_patch(')+len('tools.apply_patch(')
        patch,_=json.JSONDecoder().raw_decode(code[start:])
        lines=patch.splitlines()
        header=next(line for line in lines if line.startswith('*** Add File:') or line.startswith('*** Update File:'))
        if not header.endswith('/scripts/native_frame_rehost.py'):
            raise ValueError('Not the selected renderer patch')
        body=lines[lines.index(header)+1:]
        body=body[:next((i for i,line in enumerate(body) if line.startswith('*** ')),len(body))]
        if header.startswith('*** Add File:'):
            if source:raise ValueError('Duplicate initial source')
            source=[line[1:] for line in body if line.startswith('+')]
        else:
            groups=[]
            for line in body:
                if line.startswith('@@'):groups.append([])
                elif groups:groups[-1].append(line)
                elif line:raise ValueError('Missing hunk header')
            cursor=0
            for group in groups:
                old=[line[1:] for line in group if line.startswith((' ','-'))]
                new=[line[1:] for line in group if line.startswith((' ','+'))]
                candidates=[i for i in range(cursor,len(source)-len(old)+1) if source[i:i+len(old)]==old]
                if not candidates:raise ValueError(f'Hunk context not found, patch {index}: {old[:2]}')
                position=candidates[0]
                source[position:position+len(old)]=new
                cursor=position+len(new)
        records.append(dict(log=filename,event=index,patch_sha256=hashlib.sha256(patch.encode()).hexdigest()))
restored=('\n'.join(source)+'\n').encode()
compile(restored,str(TARGET),'exec')
prior=TARGET.read_bytes()
if prior and set(prior)!={0}:raise ValueError('Refusing overwrite of a non-zero-filled source')
TARGET.write_bytes(restored)
proof=dict(previous_bytes=len(prior),previous_all_zero=bool(prior) and set(prior)=={0},
           restored_bytes=len(restored),restored_sha256=hashlib.sha256(restored).hexdigest(),
           successful_source_patches=records,excluded_failed_patch='11:54 renderer event71 failed context verification; never applied')
(ROOT/'analiz/native-frame-rehost/source-recovery.json').write_text(json.dumps(proof,indent=2)+'\n')
print(json.dumps({k:v for k,v in proof.items() if k!='successful_source_patches'}))
