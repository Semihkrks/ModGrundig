"""Host mkfs fixture: selective LZO on a default-none UBIFS; no firmware runs."""
import fcntl
import json
import os
from pathlib import Path
import struct
import subprocess
from collections import Counter
from build_native_app import MKFS,WORK,ROOT,sha,verify_index_crc
from ubireader.ubi_io import ubi_file
from ubireader.ubifs import ubifs,nodes
from ubireader.ubifs import defines as D

base=WORK/'selective-compression-probe-v8'
if base.exists():raise FileExistsError('Probe already exists')
if sha(MKFS)!='f424c5cb122bc24a10858512926fbe5a29c74b4b6a80c5e347bd7e9aa07f48bb':raise ValueError('Host tool changed')
base.mkdir();tree=base/'files';tree.mkdir()
for name,compress in [('compressed.dat',True),('raw.dat',False)]:
    p=tree/name;p.write_bytes(b'host fixture '+b'X'*32755)
    fd=os.open(p,os.O_RDONLY)
    try:
        flags=struct.unpack('I',fcntl.ioctl(fd,0x80086601,struct.pack('I',0)))[0]
        flags=flags|4 if compress else flags&~4
        fcntl.ioctl(fd,0x40086602,struct.pack('I',flags))
    finally:os.close(fd)
image=base/'probe.ubifs'
command=[str(MKFS),'-r',str(tree),'-m','2048','-e','126976','-c','321','-o',str(image),'-x','none','-f','8','-l','4','-p','1']
subprocess.run(command,check=True,capture_output=True,timeout=60)
crc=verify_index_crc(image);f=ubi_file(str(image),1)
try:
    fs=ubifs(f);master=fs.master_node;todo=[(master.root_lnum,master.root_offs,master.root_len)];counts=Counter()
    while todo:
        lnum,offset,length=todo.pop();f.seek(lnum*fs.leb_size+offset);raw=f.read(length);header=nodes.common_hdr(raw[:D.UBIFS_COMMON_HDR_SZ])
        if header.node_type==D.UBIFS_IDX_NODE:
            todo.extend((b.lnum,b.offs,b.len) for b in nodes.idx_node(raw[D.UBIFS_COMMON_HDR_SZ:]).branches)
        elif header.node_type==D.UBIFS_DATA_NODE:counts[str(struct.unpack_from('<H',raw,44)[0])]+=1
finally:f.close()
if not counts.get('0') or not counts.get('1') or counts.get('2'):raise ValueError('Selective compressor fixture failed')
report=dict(status='pass',host_mkfs_sha256=sha(MKFS),command=command,compression_types=dict(counts),index_crc=crc,
    method='Default none; FS_COMPR_FL set only on compressed.dat; actual committed DATA_NODE codecs checked',
    originals_modified=False,target_executed=False,
    upstream_source='https://kernel.googlesource.com/pub/scm/linux/kernel/git/rw/mtd-utils/+/refs/heads/master/mkfs.ubifs/mkfs.ubifs.c')
(ROOT/'analiz/native-ui-port-v8/selective-compression-probe.json').write_text(json.dumps(report,indent=2)+'\n')
print(json.dumps(report))
