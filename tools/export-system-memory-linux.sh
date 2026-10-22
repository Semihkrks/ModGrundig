#!/bin/sh
set -eu
case "${1:-}" in 0|1) LANE=$1 ;; *) exit 2 ;; esac
export JAVA_HOME=/home/semih/.local/share/grundig-tools/jdk21
export PATH="$JAVA_HOME/bin:$PATH"
ROOT=/mnt/c/Users/Semih/Desktop/grundig
GHIDRA=/home/semih/.local/share/grundig-tools/ghidra/ghidra_12.1.4_PUBLIC
WORK="/home/semih/grundig-analysis/system-pass-a/lane$LANE/projects"
exec "$GHIDRA/support/analyzeHeadless" "$WORK" "GrundigSystemA$LANE" \
  -process '*' -recursive -noanalysis -readOnly -max-cpu 2 \
  -scriptPath "$ROOT/scripts/ghidra" \
  -postScript ExportProgramMemory.java "$ROOT/analiz/native/system-modules" \
  -log "$ROOT/analiz/loglar/ghidra-system-memory-lane$LANE.log"
