#!/bin/sh
# Only settings metadata in an isolated existing project; no target execution/save.
set -eu
[ "$#" -ge 2 ] && [ "$#" -le 3 ] || exit 2
SELECTION=$1
RUN=$2
MODE=${3:-listing}
case "$MODE" in listing|abi) ;; *) exit 2 ;; esac
case "$RUN" in ''|*[!a-zA-Z0-9_-]*) exit 2 ;; esac
case "$SELECTION" in /*) ;; *) exit 2 ;; esac
[ -f "$SELECTION" ] && [ ! -L "$SELECTION" ] || exit 2
ROOT=/mnt/c/Users/Semih/Desktop/grundig
WORK=/home/semih/grundig-analysis/ui-four/settings
if [ "$MODE" = abi ]; then
    WORK=/home/semih/grundig-analysis/ui-four/settings-abi
    SOURCE=/home/semih/grundig-analysis/ghidra-projects
    mkdir -p "$WORK"
    if [ ! -f "$WORK/GrundigBounded.gpr" ]; then
        [ ! -e "$WORK/GrundigBounded.rep" ] || exit 3
        cp -a "$SOURCE/GrundigBounded.rep" "$WORK/GrundigBounded.rep"
        cp -a "$SOURCE/GrundigBounded.gpr" "$WORK/GrundigBounded.gpr"
    fi
fi
[ -f "$WORK/GrundigBounded.gpr" ] || exit 3
OUT="$ROOT/analiz/native/ui-four/settings/$RUN"
export JAVA_HOME=/home/semih/.local/share/grundig-tools/jdk21
export PATH="$JAVA_HOME/bin:$PATH"
GHIDRA=/home/semih/.local/share/grundig-tools/ghidra/ghidra_12.1.4_PUBLIC
mkdir "$OUT"
cp "$SELECTION" "$OUT/selection.json"
sha256sum "$ROOT/scripts/ghidra/ExportUiSelection.java" "$ROOT/scripts/ghidra/SettingsFillListingGaps.java" "$ROOT/scripts/ghidra/SettingsCorrectAbi.java" > "$OUT/query-scripts.sha256"
set -- "$WORK" GrundigBounded -process dvbt_board -noanalysis -readOnly -max-cpu 1 \
    -scriptPath "$ROOT/scripts/ghidra" -preScript SettingsFillListingGaps.java "$OUT"
if [ "$MODE" = abi ]; then
    set -- "$@" -preScript SettingsCorrectAbi.java "$OUT"
fi
set -- "$@" -postScript ExportUiSelection.java "$OUT/selection.json" "$OUT" -log "$OUT/ghidra.log"
"$GHIDRA/support/analyzeHeadless" "$@"
[ -f "$OUT/summary.json" ]
