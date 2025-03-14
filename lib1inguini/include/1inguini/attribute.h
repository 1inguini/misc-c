// SPDX-License-Identifier: MIT
// Copyright © 2025 1inguini.
// Based on musl libc licensed under MIT license
// Copyright © 2005-2020 Rich Felker, et al.

#ifndef LIB1INGUINI_ATTRIBUTE
#define LIB1INGUINI_ATTRIBUTE

#define weak __attribute__((__weak__))
#define hidden __attribute__((__visibility__("hidden")))
#define weak_alias(old, new) \
  extern __typeof(old) new __attribute__((__weak__, __alias__(#old)))

#endif