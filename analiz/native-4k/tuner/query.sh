#!/bin/bash
set -eu
export JAVA_HOME=/home/semih/.local/share/grundig-tools/jdk21
export PATH="$JAVA_HOME/bin:$PATH"
ROOT=/mnt/c/Users/Semih/Desktop/grundig
GHIDRA=/home/semih/.local/share/grundig-tools/ghidra/ghidra_12.1.4_PUBLIC
KEY=$1
LANE=$2
PROGRAM=$3
OUT="$ROOT/analiz/native-4k/tuner/$KEY"
"$GHIDRA/support/analyzeHeadless" "/home/semih/grundig-analysis/system-pass-a/lane$LANE/projects" "GrundigSystemA$LANE" -process "$PROGRAM" -recursive -noanalysis -readOnly -scriptPath "$ROOT/scripts/ghidra" -postScript ExportUiSelection.java "$OUT/selection.json" "$OUT" -max-cpu 1 -log "$OUT/ghidra.log"
