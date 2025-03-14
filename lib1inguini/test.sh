#!/bin/bash
set -e
IFS='
'

cd "$(dirname "$0")"

repo=$(jj root || git rev-parse --show-toplevel)
src=$(pwd)

cc() {
  clang -static -nostdlib -I"$src/include/" "$@"
}

prog=$1
shift

mkdir -p out/example/
cc crt/x86_64/*.s "src/start.c" "example/$prog.c" -o "./example/$prog.out"
"./example/$prog.out" "$@"
