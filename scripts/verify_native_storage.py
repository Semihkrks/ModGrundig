"""Verify actual v8 UBIFS DATA codecs; no target code or file payload export."""
import json
import argparse
import struct
from collections import Counter
from build_native_app import ROOT,sha,verify_index_crc
from export_ubifs_metadata import inspect_image
from ubireader.ubi_io import ubi_file
from ubireader.ubifs import ubifs,nodes
from ubireader.ubifs import defines as D

parser=argparse.ArgumentParser();parser.add_argument('--revision',choices=('v8','v7-tv','v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv'),default='v7-tv');args=parser.parse_args()
image=ROOT/f'analiz/native-ui-candidate/{args.revision}/package/08_APP.ubifs'
metadata=inspect_image(image);entry=next(r for r in metadata['entries'] if r['path']=='/bin/dvbt_board')
crc=verify_index_crc(image);f=ubi_file(str(image),1);counts=Counter();elf_counts=Counter()
try:
    fs=ubifs(f);master=fs.master_node;todo=[(master.root_lnum,master.root_offs,master.root_len)]
    while todo:
        lnum,offset,length=todo.pop();f.seek(lnum*fs.leb_size+offset);raw=f.read(length);header=nodes.common_hdr(raw[:D.UBIFS_COMMON_HDR_SZ])
        if header.node_type==D.UBIFS_IDX_NODE:
            todo.extend((b.lnum,b.offs,b.len) for b in nodes.idx_node(raw[D.UBIFS_COMMON_HDR_SZ:]).branches)
        elif header.node_type==D.UBIFS_DATA_NODE:
            codec=str(struct.unpack_from('<H',raw,44)[0]);counts[codec]+=1
            if struct.unpack_from('<I',raw,24)[0]==entry['inum']:elf_counts[codec]+=1
finally:f.close()
if set(counts)-{'0','1'} or not counts.get('1') or not elf_counts.get('0') or set(elf_counts)!={'0'}:
    raise ValueError('V8 storage policy differs from LZO + raw ELF')
result=dict(status='pass',app_sha256=sha(image),app_bytes=image.stat().st_size,compression_types=dict(counts),
    elf_inode=entry['inum'],elf_data_compression_types=dict(elf_counts),committed_crc=crc,
    format_version=metadata['superblock']['fmt_version'],target_executed=False,
    new_kernel_codec_required=False,file_contents_modified_by_storage_policy=False)
(image.parent/'storage-validation.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result))
