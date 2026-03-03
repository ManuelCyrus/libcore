#!/bin/bash

PROG="./test"
OUT="gdb_output_error.txt"

gdb -q "$PROG" \
    -ex "set confirm off"\
    -ex "run" \
    -ex "backtrace" \
    -ex "quit" \
    > "$OUT" 2>&1

echo "OUTPUT ESTA EM $OUT"