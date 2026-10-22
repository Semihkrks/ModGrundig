#!/bin/sh
# Query existing imported programs; never execute firmware or save the project.
set -eu
export JAVA_HOME=/home/semih/.local/share/grundig-tools/jdk21
export PATH="$JAVA_HOME/bin:$PATH"
GHIDRA=/home/semih/.local/share/grundig-tools/ghidra/ghidra_12.1.4_PUBLIC
WORK=/home/semih/grundig-analysis/ghidra-projects
ROOT=/mnt/c/Users/Semih/Desktop/grundig
OUTPUT_ROOT="$ROOT/analiz/native/ui-targeted"
if [ "${1:-}" = "--deep" ]; then
    OUTPUT_ROOT="$ROOT/analiz/native/ui-deep"
    shift
fi

if [ "${1:-}" = "--compile-check" ]; then
    [ "$#" -eq 1 ] || { printf '%s\n' 'Usage: query-ui-linux.sh --compile-check' >&2; exit 2; }
    mkdir -p "$OUTPUT_ROOT/compile-check"
    CLASSPATH=$(find "$GHIDRA" -type f -name '*.jar' -printf '%p:')
    exec "$JAVA_HOME/bin/javac" -proc:none -encoding UTF-8 -cp "$CLASSPATH" \
      -d "$OUTPUT_ROOT/compile-check" "$ROOT/scripts/ghidra/ExportUiSelection.java"
fi

[ "$#" -eq 3 ] || { printf '%s\n' 'Usage: query-ui-linux.sh main|muf SELECTION_FILE NEW_RUN_NAME' >&2; exit 2; }
case "$1" in
    main) PROJECT=GrundigBounded; PROGRAM=dvbt_board ;;
    muf) PROJECT=GrundigMuf; PROGRAM=libmuf.so ;;
    *) printf '%s\n' 'Only main (GrundigBounded) and muf (GrundigMuf) projects are allowed.' >&2; exit 2 ;;
esac
SELECTION=$2
RUN_NAME=$3
case "$SELECTION" in /*) ;; *) printf '%s\n' 'Selection file must use an absolute Linux path.' >&2; exit 2 ;; esac
case "$RUN_NAME" in ''|*[!a-zA-Z0-9_-]*) printf '%s\n' 'Run name must contain only letters, numbers, underscore or hyphen.' >&2; exit 2 ;; esac
[ -f "$SELECTION" ] && [ ! -L "$SELECTION" ] || { printf '%s\n' 'Selection must be a regular non-symlink file.' >&2; exit 2; }
[ -f "$WORK/$PROJECT.gpr" ] || { printf '%s\n' 'Required existing project is absent; import is never attempted.' >&2; exit 2; }
mkdir -p "$OUTPUT_ROOT"
OUTPUT="$OUTPUT_ROOT/$RUN_NAME"
mkdir "$OUTPUT"
sha256sum "$ROOT/scripts/ghidra/ExportUiSelection.java" > "$OUTPUT/query-script.sha256"
"$GHIDRA/support/analyzeHeadless" "$WORK" "$PROJECT" \
  -process "$PROGRAM" -noanalysis -readOnly \
  -scriptPath "$ROOT/scripts/ghidra" \
  -postScript ExportUiSelection.java "$SELECTION" "$OUTPUT" \
  -max-cpu 2 -log "$OUTPUT/ghidra.log"
[ -f "$OUTPUT/summary.json" ] || { printf '%s\n' 'Ghidra did not produce completion summary; inspect the retained run log.' >&2; exit 3; }
