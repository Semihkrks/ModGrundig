#!/bin/sh
# Query a previously analyzed manifest artifact, read-only. Never import or execute it.
set -eu
[ "$#" -eq 3 ] || exit 2
SHA=$1
SELECTION=$2
RUN=$3
case "$SHA" in *[!a-f0-9]*|'') exit 2 ;; esac
[ "${#SHA}" -eq 64 ] || exit 2
case "$RUN" in *[!a-zA-Z0-9_-]*|'') exit 2 ;; esac
case "$SELECTION" in /*) ;; *) exit 2 ;; esac
export JAVA_HOME=/home/semih/.local/share/grundig-tools/jdk21
export PATH="$JAVA_HOME/bin:$PATH"
GHIDRA=/home/semih/.local/share/grundig-tools/ghidra/ghidra_12.1.4_PUBLIC
ROOT=/mnt/c/Users/Semih/Desktop/grundig
MANIFEST="$ROOT/analiz/native/system-modules/manifest.json"
LANE=$(python3 -c 'import json,sys; d=json.load(open(sys.argv[1]));r=next(r for r in d["records"] if r["sha256"]==sys.argv[2]); print(r["lane"])' "$MANIFEST" "$SHA")
PROGRAM=$(python3 -c 'import json,sys,pathlib; d=json.load(open(sys.argv[1]));r=next(r for r in d["records"] if r["sha256"]==sys.argv[2]); print(pathlib.Path(r["input_path"]).name)' "$MANIFEST" "$SHA")
case "$LANE" in 0|1) ;; *) exit 2 ;; esac
WORK="/home/semih/grundig-analysis/system-pass-a/lane$LANE/projects"
OUT="$ROOT/analiz/native/system-focused/$SHA/$RUN"
mkdir -p "$ROOT/analiz/native/system-focused/$SHA"
mkdir "$OUT"
[ -f "$SELECTION" ] && [ ! -L "$SELECTION" ] || exit 2
cp "$SELECTION" "$OUT/selection.json"
sha256sum "$ROOT/scripts/ghidra/ExportUiSelection.java" > "$OUT/query-script.sha256"
"$GHIDRA/support/analyzeHeadless" "$WORK" "GrundigSystemA$LANE" \
  -process "$PROGRAM" -recursive -noanalysis -readOnly \
  -scriptPath "$ROOT/scripts/ghidra" \
  -postScript ExportUiSelection.java "$OUT/selection.json" "$OUT" \
  -max-cpu 2 -log "$OUT/ghidra.log"
python3 -c 'import json,sys;d=json.load(open(sys.argv[1]));assert d["stored_executable_sha256"].lower()==sys.argv[2]' "$OUT/summary.json" "$SHA"
