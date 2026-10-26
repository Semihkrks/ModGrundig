#!/usr/bin/env python3
"""Fixed-input real firmware libpng decoder probe; run under WSL Ubuntu.

Only this newly generated harness is executable. No firmware app, boot/update
scripts, board devices, keys, host filesystem or network enter the guest.
"""
from pathlib import Path
import hashlib
import importlib.util
import json
import os
import re
import shutil
import struct
import subprocess
import urllib.request
import zlib

REPO=Path(__file__).resolve().parents[1]
BASE=Path('/home/semih/.local/share/grundig-analysis/png-probe-v1')
SOURCE=Path('/home/semih/.local/share/grundig-analysis/full-v1/files')
OUT=REPO/'analiz/native-png-probe'
PACKAGES={
 'clang-21':('1:21.1.8-6ubuntu1','792701d9c82e5f237879cc0bda552d8a127ea24b0c7d520e815aff14bd314b03'),
 'libclang-cpp21':('1:21.1.8-6ubuntu1','53687c45a0a4d9eac7dc1f70b2c098a9b4994f2c12d66518b26fc7f7a09bba49'),
 'lld-21':('1:21.1.8-6ubuntu1','eb4f4208329364938c91d958fcdc3226db032c88ae3529adce13c4f3983c0603'),
}
LIBRARY_HASHES={
 'ld-2.8.so':'fe601ae62268ecc106ea09dcf91cf4843aeaff03a9b0955991ba58c0047dca4e',
 'libc-2.8.so':'7c0e5900f24a19e374d81693dbb233cd9cf161b9da2f9707b79ed522b6bbad84',
 'libm-2.8.so':'8254aa2fc5663729aff53394fc1d740f1dccd071d0c5004940cdc0f1e2dc2e7d',
 'libpthread-2.8.so':'664a35efa58130b22e17989c418c64ba27ea359ace6f22ada682f03ea421db23',
 'libpng12.so.0.32.0':'8e4e63d5e7727551ad5b1b10e17e17455cd7ca17698d231a02c8918aeefae11a',
 'libz.so.1.2.8':'76610aafecc4078f6c02ed9f29648c78421171b30a4d7790e33ba2930708656a',
}
INPUT_HASHES={
 'original':'347c72138107e1dfae24068eb9ed50141ac958d65b7e4765697b85dd7d95db18',
 'v2':'202c24b264f4158276af336d819f700ec711b37fcc0a987d1aacf36cbe6f8dc3',
 'rounded':'db95b29b413e60c2e7d6a9de3497cecd417c3edf5dc3224820e8da250b32b7f6',
}
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def run(cmd,**kw):return subprocess.check_output([str(s) for s in cmd],text=True,stderr=subprocess.STDOUT,**kw)
def save(name,data):
 OUT.mkdir(parents=True,exist_ok=True)
 (OUT/name).write_text(json.dumps(data,indent=2)+'\n')
def toolchain():
 BASE.mkdir(parents=True,exist_ok=True);tools=BASE/'tools';tools.mkdir(exist_ok=True)
 provenance=[]
 for package,(version,expected) in PACKAGES.items():
  meta=run(['apt-cache','show',package+'='+version])
  # SHA from signed apt indexes is authoritative; prevent version/URL drift.
  actual=re.search(r'^SHA256: (\w+)$',meta,re.M).group(1)
  if actual!=expected:raise RuntimeError('Pinned package SHA mismatch: '+package)
  filename=re.search(r'^Filename: (.+)$',meta,re.M).group(1)
  target=BASE/Path(filename).name
  if not target.exists():
   with urllib.request.urlopen('https://archive.ubuntu.com/ubuntu/'+filename,timeout=60) as src,target.open('xb') as dst:shutil.copyfileobj(src,dst)
  if sha(target)!=expected:raise RuntimeError('Downloaded SHA mismatch: '+package)
  run(['dpkg-deb','--extract',target,tools])
  provenance.append({'package':package,'version':version,'sha256':expected,'url':'https://archive.ubuntu.com/ubuntu/'+filename})
 env=dict(os.environ,LD_LIBRARY_PATH=str(tools/'usr/lib/x86_64-linux-gnu'))
 clang=tools/'usr/lib/llvm-21/bin/clang';lld=tools/'usr/lib/llvm-21/bin/ld.lld'
 provenance.append({'clang':run([clang,'--version'],env=env).splitlines()[0],'lld':run([lld,'--version'],env=env).strip()})
 save('tools.json',provenance)
 return clang,lld,env
def rounded():
 # P4 source remains 69x620; alpha coverage is calculated after mapping to
 # intended 76x500 native widget coordinates. No firmware replacement here.
 w,h=69,620;packed=bytearray()
 for y in range(h):
  row=[]
  for x in range(w):
   tx=(x+.5)*76/w;ty=(y+.5)*500/h
   cy=max(38,min(462,ty));inside=(tx-38)**2+(ty-cy)**2<=38**2
   row.append(1 if inside else 0)
  packed.append(0)
  for x in range(0,w,2):packed.append((row[x]<<4)|(row[x+1] if x+1<w else 0))
 def chunk(kind,data):return struct.pack('>I',len(data))+kind+data+struct.pack('>I',zlib.crc32(kind+data))
 data=b'\x89PNG\r\n\x1a\n'+chunk(b'IHDR',struct.pack('>IIBBBBB',w,h,4,3,0,0,0))+chunk(b'PLTE',bytes([245,245,245])*16)+chunk(b'tRNS',bytes([0,255])+bytes([255])*14)+chunk(b'IDAT',zlib.compress(packed,9))+chunk(b'IEND',b'')
 (OUT/'rounded-bg674-experimental.png').write_bytes(data)
 return OUT/'rounded-bg674-experimental.png'
def main():
 if os.name!='posix':raise RuntimeError('WSL Ubuntu required')
 OUT.mkdir(parents=True,exist_ok=True)
 clang,lld,env=toolchain()
 spec=importlib.util.spec_from_file_location('emulation_lab',REPO/'scripts/emulation_lab.py');lab=importlib.util.module_from_spec(spec);spec.loader.exec_module(lab)
 isolation=lab.isolation_probe()
 if not isolation['passed']:raise RuntimeError('Isolation self-test failed')
 root=BASE/'guest'
 if root.exists():raise RuntimeError('Refuse overwriting guest')
 root.mkdir()
 for part in ['lib','mslib','inputs','emulator','proc','dev','tmp','run','USR_DB','BACKUP_DB']:(root/part).mkdir()
 libraries=[]
 for part,name in [('06_RFS/lib','ld-2.8.so'),('06_RFS/lib','libc-2.8.so'),('06_RFS/lib','libm-2.8.so'),('06_RFS/lib','libpthread-2.8.so'),('07_MSLIB','libpng12.so.0.32.0'),('07_MSLIB','libz.so.1.2.8')]:
  src=SOURCE/part/name
  if sha(src)!=LIBRARY_HASHES[name]:raise RuntimeError('Original library SHA mismatch: '+name)
  dst=root/('mslib' if part=='07_MSLIB' else 'lib')/name
  shutil.copyfile(src,dst);libraries.append({'source':str(src),'sha256':sha(src)})
 for name,target in [('ld.so.1','ld-2.8.so'),('libc.so.6','libc-2.8.so'),('libm.so.6','libm-2.8.so'),('libpthread.so.0','libpthread-2.8.so')]:os.symlink(target,root/'lib'/name)
 for name,target in [('libpng12.so.0','libpng12.so.0.32.0'),('libz.so.1','libz.so.1.2.8')]:os.symlink(target,root/'mslib'/name)
 qinfo=json.loads((REPO/'analiz/emulation-lab/host-tools.json').read_text());qemu=Path(qinfo['qemu_path'])
 if sha(qemu)!=qinfo['qemu_sha256']:raise RuntimeError('Emulator SHA mismatch')
 shutil.copyfile(qemu,root/'emulator/qemu-mipsel');(root/'emulator/qemu-mipsel').chmod(0o755)
 rel=Path('rc/ARimages/Common/popups/volumeControl/bg.png')
 inputs={'original':SOURCE/'08_APP'/rel,'v2':Path('/home/semih/.local/share/grundig-analysis/native-build-v1/app-reextracted-v2')/rel,'rounded':rounded()}
 for label,src in inputs.items():
  if sha(src)!=INPUT_HASHES[label]:raise RuntimeError('Fixed PNG input SHA mismatch: '+label)
  shutil.copyfile(src,root/'inputs'/(label+'.png'))
 flags=['--target=mipsel-linux-gnu','-march=mips32r2','-mabi=32','-mhard-float','-mabicalls','-fPIC','-fno-stack-protector','-O1','-nostdinc']
 for name in ['probe.c','start.S']:run([clang,*flags,'-c',REPO/'native-ui/png-probe'/name,'-o',BASE/(name+'.o')],env=env)
 run([lld,'-m','elf32ltsmip','-o',root/'png-probe','-e','__start','--dynamic-linker','/lib/ld.so.1',BASE/'start.S.o',BASE/'probe.c.o','-L'+str(root/'mslib'),'-L'+str(root/'lib'),'-rpath-link='+str(root/'mslib'),'-rpath-link='+str(root/'lib'),'-l:libpng12.so.0','-l:libc.so.6'],env=env)
 executable=root/'png-probe';executable.chmod(0o755)
 elf=run(['readelf','-h','-l','-d','-V','-A',executable]);(OUT/'harness-elf.txt').write_text(elf)
 if 'GLIBC_2.34' in elf:raise RuntimeError('New host GLIBC dependency prohibited')
 result=lab.bounded(lab.sandbox(root,['/emulator/qemu-mipsel','-R','0','/png-probe']))
 lines=result['raw'].splitlines();metrics=[list(map(int,s.split()[1:])) for s in lines if re.fullmatch(r'PNG(?: \d+){25}',s)]
 report={k:v for k,v in result.items() if k!='raw'}
 report.update({'isolation_passed':True,'harness_sha256':sha(executable),'libraries':libraries,'inputs':{k:sha(v) for k,v in inputs.items()},'decoded_metrics':dict(zip(inputs,metrics)),'metrics_layout':'width height original_bitdepth original_colortype tRNS then RGBA top-left, top-right, bottom-left, bottom-right, center','screen_rendered':False,'full_tv_emulated':False})
 expected=[
  [69,620,4,3,0]+[10,10,10,255]*5,
  [69,620,4,3,0]+[245,245,245,255]*5,
  [69,620,4,3,1]+[245,245,245,0]*4+[245,245,245,255],
 ]
 report['passed']=result['exit_code']==0 and not result['timeout'] and metrics==expected
 report['diagnostics']=[s[:160] for s in lines if s.startswith('qemu:') or 'error while loading shared libraries' in s]
 save('decode-result.json',report)
 if not report['passed']:raise RuntimeError('Native PNG decode probe failed; inspect fixed report')
 print(json.dumps(report,indent=2))
if __name__=='__main__':main()
