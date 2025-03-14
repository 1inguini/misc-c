// SPDX-License-Identifier: MIT
// Copyright © 2025 1inguini.
// Based on musl libc licensed under MIT license
// Copyright © 2005-2020 Rich Felker, et al.

#ifndef LIB1INGUINI_MAIN_H
#define LIB1INGUINI_MAIN_H

#include <1inguini/attribute.h>
#include <1inguini/syscall.h>

#define START "_start"
#include "../../arch/target/crt_arch.h"

int main(int argc, const char *argv[]);
weak void _init(); // ?
weak void _fini(); // ?

void exit(int code)
{
  _fini(); // これここでいいんかな?

  __syscall1(__NR_exit_group, code);
  for (;;)
  {
    __syscall1(__NR_exit, code);
  }
}

typedef int lib1inguini_start_main_stage2_fn(int (*)(int, const char **), int, const char *[]);
static lib1inguini_start_main_stage2_fn lib1inguini_start_main_stage2;

int lib1inguini_start_main_stage2(int (*main)(int, const char *[]), int argc, const char *argv[])
{
  exit(main(argc, argv));
  return 0;
}

void _start_c(long *p)
{
  int argc = p[0];
  const char **argv = (void *)(p + 1);

  // muslのsrc/env/__libc_start_main.cから
  // どういう意味かはわからん
  // https://www.reddit.com/r/C_Programming/comments/se3kgi/comment/huguya2/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button
  /* Barrier against hoisting application code or anything using ssp
   * or thread pointer prior to its initialization above. */
  lib1inguini_start_main_stage2_fn *stage2 = lib1inguini_start_main_stage2;
  __asm__("" : "+r"(stage2) : : "memory");
  stage2(main, argc, argv);
}

#endif