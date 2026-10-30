#!/bin/sh
# Selected existing functions, unsaved analysis metadata only; no target run.
set -eu
export JAVA_HOME=/home/semih/.local/share/grundig-tools/jdk21
export PATH="$JAVA_HOME/bin:$PATH"
ROOT=/mnt/c/Users/Semih/Desktop/grundig
GHIDRA=/home/semih/.local/share/grundig-tools/ghidra/ghidra_12.1.4_PUBLIC
OUT="$ROOT/analiz/native-4k/video-stage6/ghidra-v1"
mkdir "$OUT"
"$GHIDRA/support/analyzeHeadless" /home/semih/grundig-analysis/system-pass-a/lane1/projects GrundigSystemA1 -process 215c0a86cdd9__libapiVDEC.so -recursive -noanalysis -readOnly -scriptPath "$ROOT/scripts/ghidra" -postScript ExportUiSelection.java "$ROOT/analiz/native-4k/video-stage6/selection.json" "$OUT" -max-cpu 1 -log "$OUT/ghidra.log"
