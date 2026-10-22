"""Prepare immutable-source copies and ordered work manifest for local Ghidra."""
from pathlib import Path
import hashlib
import json
import re
import shutil

ROOT=Path(__file__).resolve().parents[1]
WORK=Path('/home/semih/grundig-analysis/system-pass-a')

def main():
    inventory=json.loads((ROOT/'analiz/envanter-v2/elf-envanteri.json').read_text())
    out=ROOT/'analiz/native/system-modules'
    out.mkdir(parents=True,exist_ok=True)
    known={json.loads((ROOT/p).read_text())['stored_executable_sha256']
           for p in ('analiz/native/ui-targeted/dvbt_board/summary.json','analiz/native/ui-targeted/libmuf/summary.json')}
    groups={}
    for e in inventory['elfs']:
        groups.setdefault(e['sha256'],[]).append(e)
    priority=re.compile(r'msrv|MStarSDK|libar_cec|apiAUDIO|drvAUDIO|libdirectfb|drvIR|apiCEC|mboot|upgrade|update',re.I)
    records=[]
    for i,(sha,entries) in enumerate(sorted(groups.items(),key=lambda p:(not any(priority.search(e['path']) for e in p[1]),sum(e['size'] for e in p[1])))):
        paths=[e['path'] for e in entries]
        record={'sha256':sha,'module_paths':paths,'bytes':entries[0]['size'],'status':'existing_UI_analysis' if sha in known else 'queued'}
        if sha not in known:
            lane=i%2
            directory=WORK/f'lane{lane}'/'inputs'
            directory.mkdir(parents=True,exist_ok=True)
            source=Path('/home/semih/.local/share/grundig-analysis/full-v1/files')/paths[0]
            if source.is_symlink() or not source.is_file():raise ValueError('Nonregular source')
            data=source.read_bytes()
            if hashlib.sha256(data).hexdigest()!=sha:raise ValueError('Source hash mismatch')
            dest=directory/(sha[:12]+'__'+Path(paths[0]).name)
            dest.write_bytes(data)
            record.update(lane=lane,input_path=str(dest))
        records.append(record)
    manifest={'schema_version':1,'source_inventory_sha256':hashlib.sha256((ROOT/'analiz/envanter-v2/elf-envanteri.json').read_bytes()).hexdigest(),
              'module_paths':len(inventory['elfs']),'unique_hashes':len(groups),'records':records,
              'originals_modified':False,'target_execution':False}
    (out/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(json.dumps({'module_paths':len(inventory['elfs']),'unique_hashes':len(groups),'queued':sum(r['status']=='queued' for r in records)}))

if __name__=='__main__':main()
