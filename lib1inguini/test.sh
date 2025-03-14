#!/bin/bash
set -e
IFS='
'

cd "$(dirname "$0")"

src=$(pwd)

cc() {
  clang -static -nostdlib -I"$src/include/" "$@"
}

prog=$1
shift

mkdir -p out/example/
cc arch/target/crt/*.s "src/start.c" "example/$prog.c" -o "./example/$prog.out"
"./example/$prog.out" "$@"
