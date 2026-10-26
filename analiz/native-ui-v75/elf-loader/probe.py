"""Run only a newly generated MIPS probe, never the TV application."""
import hashlib, importlib.util, json, os, shutil, struct, subprocess, sys
from pathlib import Path
repo=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(repo/'scripts'))
import native_ui_v75_elf as extension
import emulation_lab as lab
out=Path(__file__).resolve().parent
base=Path('/home/semih/.local/share/grundig-analysis/png-probe-v1')
root=Path('/home/semih/.local/share/grundig-analysis/v75-elf-loader-probe')
root.mkdir(exist_ok=True)
for name in ['lib','mslib','emulator','proc','dev','tmp','run','USR_DB','BACKUP_DB']:(root/name).mkdir(exist_ok=True)
hashes={'ld-2.8.so':'fe601ae62268ecc106ea09dcf91cf4843aeaff03a9b0955991ba58c0047dca4e','libc-2.8.so':'7c0e5900f24a19e374d81693dbb233cd9cf161b9da2f9707b79ed522b6bbad84'}
for name,digest in hashes.items():
    src=base/'guest/lib'/name
    assert hashlib.sha256(src.read_bytes()).hexdigest()==digest
    shutil.copyfile(src,root/'lib'/name)
for name,target in [('ld.so.1','ld-2.8.so'),('libc.so.6','libc-2.8.so')]:
    if not (root/'lib'/name).exists():os.symlink(target,root/'lib'/name)
qinfo=json.loads((repo/'analiz/emulation-lab/host-tools.json').read_text())
qemu=Path(qinfo['qemu_path']);assert hashlib.sha256(qemu.read_bytes()).hexdigest()==qinfo['qemu_sha256']
shutil.copyfile(qemu,root/'emulator/qemu-mipsel');(root/'emulator/qemu-mipsel').chmod(0o755)
clang=base/'tools/usr/lib/llvm-21/bin/clang';lld=base/'tools/usr/lib/llvm-21/bin/ld.lld'
env=dict(os.environ,LD_LIBRARY_PATH=str(base/'tools/usr/lib/x86_64-linux-gnu'))
source=out/'probe.S'
source.write_text(''' .text
 .set noreorder
 .globl __start
__start:
 addiu $4,$0,74
 addiu $2,$0,4001
 syscall
 nop
''')
subprocess.run([str(clang),'--target=mipsel-linux-gnu','-march=mips32r2','-mabi=32','-c',str(source),'-o',str(root/'probe.o')],env=env,check=True)
subprocess.run([str(lld),'-m','elf32ltsmip','-o',str(root/'probe-original'),'-e','__start','--dynamic-linker','/lib/ld.so.1',str(root/'probe.o'),'--no-as-needed','-L'+str(root/'lib'),'-l:libc.so.6'],env=env,check=True)
data=bytearray((root/'probe-original').read_bytes());off=struct.unpack_from('<I',data,28)[0];num=struct.unpack_from('<H',data,44)[0]
ph=[extension.PH.unpack_from(data,off+i*32) for i in range(num)]
first=next(p for p in ph if p[0]==1)
loadbase=first[2]-first[1]
new_off=0xD60000;new_va=loadbase+new_off
code_offset=((num+1)*32+15)&~15
size=code_offset+16
newph=[(6,new_off,new_va,new_va,(num+1)*32,(num+1)*32,p[6],p[7]) if p[0]==6 else p for p in ph]
newph.append((1,new_off,new_va,new_va,size,size,5,0x10000))
segment=bytearray(size)
for i,p in enumerate(newph):extension.PH.pack_into(segment,i*32,*p)
# Exit 75 from the appended mapping after the old dynamic loader hands over.
struct.pack_into('<4I',segment,code_offset,0x2404004B,0x24020FA1,0x0000000C,0)
struct.pack_into('<I',data,24,new_va+code_offset)
struct.pack_into('<I',data,28,new_off);struct.pack_into('<H',data,44,num+1)
data.extend(bytes(new_off-len(data)));data.extend(segment)
(root/'probe-relocated').write_bytes(data)
for name in ['probe-original','probe-relocated']:(root/name).chmod(0o755)
isolation=lab.isolation_probe();assert isolation['passed']
results={}
for name,expected in [('probe-original',74),('probe-relocated',75)]:
    result=lab.bounded(lab.sandbox(root,['/emulator/qemu-mipsel','-R','0','/'+name]))
    assert result['exit_code']==expected and not result['timeout'],result
    results[name]=result
firmware=Path('/home/semih/.local/share/grundig-analysis/native-build-v1/app-reextracted-v7.4-tv-lzo-raw-elf/bin/dvbt_board').read_bytes()
patched,proof=extension.append_payload(firmware,b'\x08\x00\xe0\x03\x00\x00\x00\x00',b'\x08\x00\xe0\x03\x00\x00\x00\x00')
report={'generated_probe_only':True,'firmware_executed':False,'libraries':hashes,'isolation':isolation,'results':results,'generated_elf_load_base':loadbase,'relocated_phdr_va':new_va,'relocated_phdr_file_offset':new_off,'generated_phnum':num+1,'firmware_static_placement':proof,'limitation':'Generated probe accepts relocated PHDR and new RX entry under QEMU plus firmware ld-2.8. This is not TV kernel or firmware-app execution.'}
(out/'results.json').write_text(json.dumps(report,indent=2)+'\n')
print(json.dumps(report,indent=2))
