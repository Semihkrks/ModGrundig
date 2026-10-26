"""Generated-only C++ exception crossing new RX/FDE with old firmware libs."""
exec((__import__('pathlib').Path(__file__).parent/'probe.py').read_text())
# Reuses reviewed isolated root and pinned loader/libc, never the TV image.
source_root=Path('/home/semih/.local/share/grundig-analysis/full-v1/files/06_RFS/lib')
extra={}
expected_extra={'libstdc++.so.6.0.10':'11427a71b958e7422cc736c9f16810a66595e0e19ca69966f6a1cdd2dc9a0e5c','libgcc_s.so.1':'e12aeecb32628a1e5e11b51fc03945c91d5b9a573114425208dafad070d50f29','libm-2.8.so':'8254aa2fc5663729aff53394fc1d740f1dccd071d0c5004940cdc0f1e2dc2e7d'}
for name in ['libstdc++.so.6.0.10','libgcc_s.so.1','libm-2.8.so']:
    src=source_root/name
    assert src.is_file() and not src.is_symlink()
    extra[name]=hashlib.sha256(src.read_bytes()).hexdigest()
    assert extra[name]==expected_extra[name]
    shutil.copyfile(src,root/'lib'/name)
for name,target in [('libstdc++.so.6','libstdc++.so.6.0.10'),('libgcc_s.so','libgcc_s.so.1'),('libm.so.6','libm-2.8.so')]:
    if not (root/'lib'/name).exists():os.symlink(target,root/'lib'/name)
(out/'throw.cpp').write_text('''extern "C" __attribute__((noinline)) void thrower() { throw 75; }
extern "C" int probe_main() { try { ((void(*)())0x01160100)(); } catch(int x) {return x;} return 99; }
''')
flags=['--target=mipsel-linux-gnu','-march=mips32r2','-mabi=32','-mhard-float','-mabicalls','-fPIC','-fexceptions','-fcxx-exceptions','-O1','-fno-stack-protector']
subprocess.run([str(clang),*flags,'-c',str(out/'throw.cpp'),'-o',str(root/'throw.o')],env=env,check=True)
subprocess.run([str(clang),*flags,'-c',str(repo/'native-ui/png-probe/start.S'),'-o',str(root/'start.o')],env=env,check=True)
subprocess.run([str(lld),'-m','elf32ltsmip','--image-base=0x400000','--eh-frame-hdr','-o',str(root/'cpp-original'),'-e','__start','--dynamic-linker','/lib/ld.so.1',str(root/'start.o'),str(root/'throw.o'),'-L'+str(root/'lib'),'-l:libstdc++.so.6','-l:libgcc_s.so.1','-l:libm.so.6','-l:libc.so.6'],env=env,check=True)
symbols=subprocess.check_output(['nm',str(root/'cpp-original')],text=True)
thrower=int(next(line.split()[0] for line in symbols.splitlines() if line.endswith(' thrower')),16)
# Helper saves RA, calls generated thrower, restores only on normal return.
words=[0x27bdff60,0xafbf009c,0x3c190000|(thrower>>16),0x37390000|(thrower&65535),0x0320f809,0,0x8fbf009c,0x03e00008,0x27bd00a0]
helper=struct.pack('<9I',*words)
descriptor={'start':extension.CREATE_VA,'size':len(helper),'events':[{'pc':4,'cfa_offset':160},{'pc':8,'offsets':{31:-4}},{'pc':28,'restores':[31]},{'pc':36,'cfa_offset':0}]}
data=bytearray((root/'cpp-original').read_bytes());off=struct.unpack_from('<I',data,28)[0];num=struct.unpack_from('<H',data,44)[0]
ph=[extension.PH.unpack_from(data,off+i*32) for i in range(num)]
assert next(p for p in ph if p[0]==1)[2]-next(p for p in ph if p[0]==1)[1]==0x400000
unwind,ehph,proof=extension._unwind(data,ph,[descriptor])
size=0x2000+len(unwind)
newph=[(6,extension.FILE_OFFSET+0x1000,extension.SEGMENT_VA+0x1000,extension.SEGMENT_VA+0x1000,(num+1)*32,(num+1)*32,p[6],p[7]) if p[0]==6 else ehph if p[0]==0x6474E550 else p for p in ph]
newph.append((1,extension.FILE_OFFSET,extension.SEGMENT_VA,extension.SEGMENT_VA,size,size,5,0x10000))
segment=bytearray(size)
for i,p in enumerate(newph):extension.PH.pack_into(segment,0x1000+i*32,*p)
assert len(newph)*32<=0x1000
segment[0x100:0x100+len(helper)]=helper;segment[0x2000:]=unwind
struct.pack_into('<I',data,28,extension.FILE_OFFSET+0x1000);struct.pack_into('<H',data,44,len(newph))
data.extend(bytes(extension.FILE_OFFSET-len(data)));data.extend(segment)
(root/'cpp-relocated').write_bytes(data);(root/'cpp-relocated').chmod(0o755)
result=lab.bounded(lab.sandbox(root,['/emulator/qemu-mipsel','-R','0','/cpp-relocated']))
negative=bytearray(data)
for i,p in enumerate(newph):
    if p[0]==0x6474E550:extension.PH.pack_into(negative,extension.FILE_OFFSET+0x1000+i*32,*next(q for q in ph if q[0]==p[0]))
(root/'cpp-without-fde').write_bytes(negative);(root/'cpp-without-fde').chmod(0o755)
control=lab.bounded(lab.sandbox(root,['/emulator/qemu-mipsel','-R','0','/cpp-without-fde']))
report={'generated_only':True,'firmware_app_executed':False,'expected_exit':75,'result':result,'negative_control_without_fde':control,'extra_library_sha256':extra,'unwind':proof}
(out/'cpp-results.json').write_text(json.dumps(report,indent=2)+'\n')
print(json.dumps(report,indent=2));assert result['exit_code']==75 and not result['timeout'];assert control['exit_code']!=75 and not control['timeout']
