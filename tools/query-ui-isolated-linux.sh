#!/bin/sh
# Isolated copies of existing Ghidra metadata; no target execution or saved changes.
set -eu
[ "$#" -eq 3 ] || exit 2
KEY=$1
SELECTION=$2
RUN=$3
case "$KEY" in settings|general|home|tools|channels) ;; *) exit 2 ;; esac
case "$RUN" in ''|*[!a-zA-Z0-9_-]*) exit 2 ;; esac
case "$SELECTION" in /*) ;; *) exit 2 ;; esac
[ -f "$SELECTION" ] && [ ! -L "$SELECTION" ] || exit 2
ROOT=/mnt/c/Users/Semih/Desktop/grundig
SOURCE=/home/semih/grundig-analysis/ghidra-projects
WORK=/home/semih/grundig-analysis/ui-four/$KEY
OUT="$ROOT/analiz/native/ui-four/$KEY/$RUN"
export JAVA_HOME=/home/semih/.local/share/grundig-tools/jdk21
export PATH="$JAVA_HOME/bin:$PATH"
GHIDRA=/home/semih/.local/share/grundig-tools/ghidra/ghidra_12.1.4_PUBLIC
mkdir -p "$WORK"
if [ ! -f "$WORK/GrundigBounded.gpr" ]; then
    [ ! -e "$WORK/GrundigBounded.rep" ] || exit 3
    cp -a "$SOURCE/GrundigBounded.rep" "$WORK/GrundigBounded.rep"
    cp -a "$SOURCE/GrundigBounded.gpr" "$WORK/GrundigBounded.gpr"
fi
mkdir -p "$ROOT/analiz/native/ui-four/$KEY"
mkdir "$OUT"
cp "$SELECTION" "$OUT/selection.json"
sha256sum "$ROOT/scripts/ghidra/ExportUiSelection.java" > "$OUT/query-script.sha256"
"$GHIDRA/support/analyzeHeadless" "$WORK" GrundigBounded \
    -process dvbt_board -noanalysis -readOnly -max-cpu 1 \
    -scriptPath "$ROOT/scripts/ghidra" \
    -postScript ExportUiSelection.java "$OUT/selection.json" "$OUT" \
    -log "$OUT/ghidra.log"
[ -f "$OUT/summary.json" ]
