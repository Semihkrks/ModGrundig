#!/bin/sh
# Offline analysis only. Never execute extracted code or update commands.
set -eu
export JAVA_HOME=/home/semih/.local/share/grundig-tools/jdk21
export PATH="$JAVA_HOME/bin:$PATH"
export JAVA_TOOL_OPTIONS=-Xmx2G
GHIDRA=/home/semih/.local/share/grundig-tools/ghidra/ghidra_12.1.4_PUBLIC
ROOT=/mnt/c/Users/Semih/Desktop/grundig
WORK=/home/semih/grundig-analysis/ghidra-projects
OUT="$ROOT/analiz/native/boot-candidate-v1"
INPUT="$ROOT/analiz/bolumler/04_mboot.bin"
if [ "${1:-}" = --resume-own-project ]; then
  test -f "$WORK/GrundigBootCandidateV1.gpr"
  test -f "$OUT/source-hash-manifest.json"
  set -- -process 04_mboot.bin
else
  test "$#" -eq 0
  test ! -e "$WORK/GrundigBootCandidateV1.gpr"
  test ! -e "$WORK/GrundigBootCandidateV1.rep"
  set -- -import "$INPUT" -loader BinaryLoader -loader-baseAddr 0x8e1efd80
fi
mkdir -p "$WORK" "$OUT"
python3 - "$ROOT" "$OUT" <<'PY'
import hashlib,json,pathlib,sys,datetime
root,out=map(pathlib.Path,sys.argv[1:])
paths=['analiz/bolumler/04_mboot.bin','scripts/ghidra/ExportRawBootHandlers.java','tools/analyze-boot-candidate-linux.sh']
prior=out/'source-hash-manifest.json'
if prior.exists():
    expected=json.loads(prior.read_text())['inputs'][0]['sha256']
    assert hashlib.sha256((root/paths[0]).read_bytes()).hexdigest()==expected,'Source differs from prior owned project import'
record={'created_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'target_execution':False,'firmware_modified':False,'inputs':[{'path':p,'bytes':(root/p).stat().st_size,'sha256':hashlib.sha256((root/p).read_bytes()).hexdigest()} for p in paths]}
(out/'source-hash-manifest.json').write_text(json.dumps(record,indent=2)+'\n')
PY
timeout --signal=TERM --kill-after=15s 240s "$GHIDRA/support/analyzeHeadless" "$WORK" GrundigBootCandidateV1 \
  "$@" \
  -processor MIPS:LE:32:default -cspec default -noanalysis \
  -scriptPath "$ROOT/scripts/ghidra" \
  -postScript ExportRawBootHandlers.java "$OUT" -max-cpu 2 \
  -log "$OUT/headless.log" -scriptlog "$OUT/script.log"
python3 - "$INPUT" "$OUT" <<'PY'
import hashlib,json,pathlib,sys
p,out=map(pathlib.Path,sys.argv[1:])
m=json.loads((out/'source-hash-manifest.json').read_text())
after=hashlib.sha256(p.read_bytes()).hexdigest()
assert after==m['inputs'][0]['sha256'],'Input changed during analysis'
(out/'source-hash-verification.json').write_text(json.dumps({'sha256_after':after,'source_unchanged':True,'source_bytes':p.stat().st_size},indent=2)+'\n')
assert (out/'summary.json').is_file(),'Ghidra script did not produce summary'
s=json.loads((out/'summary.json').read_text())
assert s['source_manifest_sha256']==hashlib.sha256((out/'source-hash-manifest.json').read_bytes()).hexdigest(),'Stale or failed Ghidra script result'
assert s['source_sha256']==after,'Analysis DB source hash mismatch'
PY
