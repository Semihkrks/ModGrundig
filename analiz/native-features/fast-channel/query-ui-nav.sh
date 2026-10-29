#!/bin/sh
set -eu
export JAVA_HOME=/home/semih/.local/share/grundig-tools/jdk21
export PATH="$JAVA_HOME/bin:$PATH"
ROOT=/mnt/c/Users/Semih/Desktop/grundig
GHIDRA=/home/semih/.local/share/grundig-tools/ghidra/ghidra_12.1.4_PUBLIC
OUT="$ROOT/analiz/native-features/fast-channel/ui-nav-v1"
mkdir "$OUT"
"$GHIDRA/support/analyzeHeadless" /home/semih/grundig-analysis/ghidra-projects GrundigBounded -process dvbt_board -noanalysis -readOnly -scriptPath "$ROOT/scripts/ghidra" -postScript ExportUiSelection.java "$ROOT/analiz/native-features/fast-channel/selection-ui-nav.json" "$OUT" -max-cpu 1 -log "$OUT/ghidra.log"
