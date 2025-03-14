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
cc -r arch/target/crt/*.s "src/crt.c" -o crt.o # relocatable object file
cc crt.o "example/$prog.c" -o "./example/$prog.out"
"./example/$prog.out" "$@"
