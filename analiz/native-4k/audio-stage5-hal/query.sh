#!/bin/sh
set -eu
export JAVA_HOME=/home/semih/.local/share/grundig-tools/jdk21
export PATH="$JAVA_HOME/bin:$PATH"
ROOT=/mnt/c/Users/Semih/Desktop/grundig
GHIDRA=/home/semih/.local/share/grundig-tools/ghidra/ghidra_12.1.4_PUBLIC
case "$1" in
 api) PROGRAM=d55e76dd24ba__libapiAUDIO.so ;;
 customer) PROGRAM=4ebd5fc038a8__libMStarSDK_customer.so ;;
 *) exit 2 ;;
esac
OUT="$ROOT/analiz/native-4k/audio-stage5-hal/$1-v1"
mkdir "$OUT"
"$GHIDRA/support/analyzeHeadless" /home/semih/grundig-analysis/system-pass-a/lane0/projects GrundigSystemA0 -process "$PROGRAM" -recursive -noanalysis -readOnly -scriptPath "$ROOT/scripts/ghidra" -postScript ExportUiSelection.java "$ROOT/analiz/native-4k/audio-stage5-hal/selection-$1.json" "$OUT" -max-cpu 1 -log "$OUT/ghidra.log"
