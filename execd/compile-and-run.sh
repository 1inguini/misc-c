#!/bin/bash
set -e
IFS='
'

cd "$(dirname "$0")"

repo=$(jj root)

cc() {
  clang "$@"
}

cc -I"$repo/include" execd.c -o ./execd.out && ./execd.out "$@"
