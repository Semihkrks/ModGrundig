#!/bin/sh
set -eu
export JAVA_HOME=/home/semih/.local/share/grundig-tools/jdk21
export PATH="$JAVA_HOME/bin:$PATH"
GHIDRA=/home/semih/.local/share/grundig-tools/ghidra/ghidra_12.1.4_PUBLIC
WORK=/home/semih/grundig-analysis/ghidra-projects
ROOT=/mnt/c/Users/Semih/Desktop/grundig
mkdir -p "$WORK" "$ROOT/analiz/native/libmuf"
exec "$GHIDRA/support/analyzeHeadless" "$WORK" GrundigMuf \
  -import /home/semih/.local/share/grundig-analysis/full-v1/files/07_MSLIB/libmuf.so \
  -processor MIPS:LE:32:default -cspec default \
  -scriptPath "$ROOT/scripts/ghidra" \
  -preScript ConfigureBoundedAnalysis.java "$ROOT/analiz/native/libmuf" \
  -postScript ExportFirmwareMap.java "$ROOT/analiz/native/libmuf" \
  -analysisTimeoutPerFile 180 -max-cpu 2 \
  -log "$ROOT/analiz/loglar/ghidra-muf.log"
