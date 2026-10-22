#!/bin/sh
# Import only manifest copies into a new analysis project. Never execute targets.
set -eu
case "${1:-}" in 0|1) LANE=$1 ;; *) exit 2 ;; esac
export JAVA_HOME=/home/semih/.local/share/grundig-tools/jdk21
export PATH="$JAVA_HOME/bin:$PATH"
export JAVA_TOOL_OPTIONS=-Xmx2G
GHIDRA=/home/semih/.local/share/grundig-tools/ghidra/ghidra_12.1.4_PUBLIC
ROOT=/mnt/c/Users/Semih/Desktop/grundig
WORK=/home/semih/grundig-analysis/system-pass-a
mkdir -p "$WORK/lane$LANE/projects" "$ROOT/analiz/native/system-modules/options-lane$LANE"
exec "$GHIDRA/support/analyzeHeadless" "$WORK/lane$LANE/projects" "GrundigSystemA$LANE" \
  -import "$WORK/lane$LANE/inputs" -recursive -processor MIPS:LE:32:default -cspec default \
  -scriptPath "$ROOT/scripts/ghidra" \
  -preScript ConfigureBoundedAnalysis.java "$ROOT/analiz/native/system-modules/options-lane$LANE" \
  -postScript ExportSystemModule.java "$ROOT/analiz/native/system-modules" \
  -analysisTimeoutPerFile 60 -max-cpu 2 \
  -log "$ROOT/analiz/loglar/ghidra-system-lane$LANE.log"
