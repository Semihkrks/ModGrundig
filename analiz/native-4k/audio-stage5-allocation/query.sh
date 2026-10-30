#!/bin/sh
set -eu
export JAVA_HOME=/home/semih/.local/share/grundig-tools/jdk21
export PATH="$JAVA_HOME/bin:$PATH"
ROOT=/mnt/c/Users/Semih/Desktop/grundig
GHIDRA=/home/semih/.local/share/grundig-tools/ghidra/ghidra_12.1.4_PUBLIC
OUT="$ROOT/analiz/native-4k/audio-stage5-allocation/customer-v1"
mkdir "$OUT"
"$GHIDRA/support/analyzeHeadless" /home/semih/grundig-analysis/system-pass-a/lane0/projects GrundigSystemA0 -process 4ebd5fc038a8__libMStarSDK_customer.so -recursive -noanalysis -readOnly -scriptPath "$ROOT/scripts/ghidra" -postScript ExportUiSelection.java "$ROOT/analiz/native-4k/audio-stage5-allocation/selection.json" "$OUT" -max-cpu 1 -log "$OUT/ghidra.log"
