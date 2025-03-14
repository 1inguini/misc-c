// SPDX-License-Identifier: CC0-1.0
// Copyright © 2025 1inguini. (Should I write this notice for CC0-1.0?)

#include <1inguini/1inguini.h>

int main(int argc, char const *argv[])
{
  ssize_t res = __syscall3(__NR_write, 1, (size_t)&"Hello World!\n", 13);
  // `write` system call returns the number of bytes written on success, -1 on failure.
  return res < 0; // 0 is success in exit code, but in boolean operation it's false.
}