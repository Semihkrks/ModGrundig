#!/bin/sh
set -eu
export JAVA_HOME=/home/semih/.local/share/grundig-tools/jdk21
export PATH="$JAVA_HOME/bin:$PATH"
ROOT=/mnt/c/Users/Semih/Desktop/grundig
GHIDRA=/home/semih/.local/share/grundig-tools/ghidra/ghidra_12.1.4_PUBLIC
OUT="$ROOT/analiz/native-4k/transponders/consumer-query"
"$GHIDRA/support/analyzeHeadless" /home/semih/grundig-analysis/system-pass-a/lane0/projects GrundigSystemA0 -process 9c3d825e7162__libmsrv_dvbs_customer.so -recursive -noanalysis -readOnly -scriptPath "$ROOT/scripts/ghidra" -postScript ExportUiSelection.java "$OUT/selection.json" "$OUT" -max-cpu 1 -log "$OUT/ghidra.log"
