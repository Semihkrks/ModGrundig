#!/bin/sh
# Recover only selected constructor callback bodies in unsaved Ghidra metadata.
set -eu
ROOT=/mnt/c/Users/Semih/Desktop/grundig
OUT="$ROOT/analiz/native/directfb-callbacks-v1"
if [ "$#" -gt 0 ]; then
  [ "$#" -eq 1 ] || exit 2
  case "$1" in *[!a-zA-Z0-9_-]*|'') exit 2 ;; esac
  OUT="$OUT/$1"
fi
TARGET=/home/semih/.local/share/grundig-analysis/full-v1/files/07_MSLIB/libdirectfb-1.4.so.0.2.0
SHA=b05201025cab0dd8734708702a910ff54d24eb723e782c0994a26361194c5bf3
export JAVA_HOME=/home/semih/.local/share/grundig-tools/jdk21
export PATH="$JAVA_HOME/bin:$PATH"
GHIDRA=/home/semih/.local/share/grundig-tools/ghidra/ghidra_12.1.4_PUBLIC
[ -f "$TARGET" ] && [ ! -L "$TARGET" ] || exit 2
[ "$(sha256sum "$TARGET" | cut -d' ' -f1)" = "$SHA" ] || exit 2
mkdir "$OUT"
sha256sum "$TARGET" > "$OUT/target-before.sha256"
sha256sum "$ROOT/scripts/ghidra/ExportDirectFbCallbacks.java" "$ROOT/scripts/ghidra/ExportUiSelection.java" "$0" > "$OUT/query-scripts.sha256"
python3 - "$TARGET" "$OUT" "$SHA" <<'PY'
import sys,pathlib,struct,json
target,out,sha=pathlib.Path(sys.argv[1]),pathlib.Path(sys.argv[2]),sys.argv[3]
b=target.read_bytes(); assert b[:7]==b'\x7fELF\x01\x01\x01'
shoff=struct.unpack_from('<I',b,32)[0]; shsize,shnum,shstridx=struct.unpack_from('<HHH',b,46)
sections=[struct.unpack_from('<10I',b,shoff+i*shsize) for i in range(shnum)]
namesec=sections[shstridx]; names=b[namesec[4]:namesec[4]+namesec[5]]
named={names[s[0]:].split(b'\0',1)[0].decode():s for s in sections}
pdr=named['.pdr']; text=named['.text']; base=text[3]-text[4]
entries=[(i,struct.unpack_from('<8I',b,i)) for i in range(pdr[4],pdr[4]+pdr[5],32)]
addresses=['2de506d0','2de504e4','2de5c164','2de4f450','2de5aac8','2de56064','2de50308','2de5dde0']
slots=['0x5c','0x60','0x68','0x78','0x88','0xd8','0x100','0x0c']
bounds={}
for a,slot in zip(addresses,slots):
 ix=next(i for i,(_,r) in enumerate(entries) if r[0]+base==int(a,16))
 off,r=entries[ix]; nxt=entries[ix+1][1][0]+base
 assert int(a,16)<nxt<=text[3]+text[5]
 bounds[a]={'end_exclusive':hex(nxt)[2:],'basis':'exact MIPS .pdr entry to next procedure entry; constructor-assigned callback','pdr_file_offset':hex(off),'pdr_words':[hex(v) for v in r],'image_base':hex(base),'constructor_interface_byte_offset':slot,'source_file_offset':hex(int(a,16)-base),'range_source_sha256':__import__('hashlib').sha256(b[int(a,16)-base:nxt-base]).hexdigest()}
(out/'selection.json').write_text(json.dumps({'target_sha256':sha,'addresses':addresses,'function_bounds':bounds,'seed_t9_entry':True,'decompile_timeout_seconds':45,'decompiler_max_payload_mbytes':8},indent=2))
(out/'elf-boundaries.json').write_text(json.dumps({'pdr_section_file_offset':hex(pdr[4]),'pdr_section_size':pdr[5],'entry_count':len(entries),'eh_frame_size':named['.eh_frame'][5],'text_base':hex(text[3]),'text_size':text[5],'functions':bounds},indent=2))
PY
"$GHIDRA/support/analyzeHeadless" /home/semih/grundig-analysis/system-pass-a/lane1/projects GrundigSystemA1 \
  -process b05201025cab__libdirectfb-1.4.so.0.2.0 -recursive -noanalysis -readOnly \
  -scriptPath "$ROOT/scripts/ghidra" -postScript ExportDirectFbCallbacks.java "$OUT/selection.json" "$OUT" \
  -max-cpu 2 -log "$OUT/ghidra.log"
sha256sum "$TARGET" > "$OUT/target-after.sha256"
cmp "$OUT/target-before.sha256" "$OUT/target-after.sha256"
python3 - "$OUT" "$SHA" <<'PY'
import json,pathlib,sys
o=pathlib.Path(sys.argv[1]);s=json.loads((o/'summary.json').read_text());assert s['stored_executable_sha256'].lower()==sys.argv[2];assert s['processed_count']==8
s['target_sha256_before_after_identical']=True
(o/'summary.json').write_text(json.dumps(s,indent=2))
PY
