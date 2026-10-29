#!/bin/sh
set -eu
export JAVA_HOME=/home/semih/.local/share/grundig-tools/jdk21
export PATH="$JAVA_HOME/bin:$PATH"
ROOT=/mnt/c/Users/Semih/Desktop/grundig
GHIDRA=/home/semih/.local/share/grundig-tools/ghidra/ghidra_12.1.4_PUBLIC
case "$1" in
 db) LANE=1; PROGRAM=dbdef96fed7b__libmsrv_system_database.so ;;
 dvb) LANE=0; PROGRAM=93fe7286bb7f__libmsrv_dvb.so ;;
 common) LANE=1; PROGRAM=06bc6252713a__libmsrv_common.so ;;
 customer) LANE=0; PROGRAM=394ee95f0738__libmsrv_common_customer.so ;;
 *) exit 2 ;;
esac
RUN=${2:-$1-v1}
OUT="$ROOT/analiz/native-features/fast-channel/$RUN"
mkdir "$OUT"
"$GHIDRA/support/analyzeHeadless" /home/semih/grundig-analysis/system-pass-a/lane$LANE/projects GrundigSystemA$LANE -process "$PROGRAM" -recursive -noanalysis -readOnly -scriptPath "$ROOT/scripts/ghidra" -postScript ExportUiSelection.java "$ROOT/analiz/native-features/fast-channel/selection-$1.json" "$OUT" -max-cpu 1 -log "$OUT/ghidra.log"
