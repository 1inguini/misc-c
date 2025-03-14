// SPDX-License-Identifier: CC0-1.0
// Copyright © 2025 1inguini. (Should I write this notice for CC0-1.0?)

#include <1inguini/1inguini.h>
#include <1inguini/main.h>

int main(int argc, char const *argv[])
{
  return __syscall3(__NR_write, 1, (long)&"Hello World!\n", 13);
}