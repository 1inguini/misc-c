#!/bin/bash
set -e
IFS='
'

cd "$(dirname "$0")"

repo=$(jj root || git rev-parse --show-toplevel)

cc() {
  clang "$@"
}

cc -nostdlib -I"$repo/include" execd.c -o ./execd.out && ./execd.out "$@"
