#!/bin/sh
set -eu
export GHIDRA_INSTALL_DIR=/home/semih/.local/share/grundig-tools/ghidra/ghidra_12.1.4_PUBLIC
export JAVA_HOME=/home/semih/.local/share/grundig-tools/jdk21
export PATH="$JAVA_HOME/bin:/home/semih/.local/share/uv/tools/unblob/bin:/home/semih/.local/bin:$PATH"
export REA_UNBLOB_COMMAND=/home/semih/.local/bin/unblob
export REA_GHIDRA_STARTUP_TIMEOUT_MS=600000
exec /home/semih/.local/bin/node /home/semih/.local/lib/node_modules/rea-agents/scripts/rea.mjs "$@"
