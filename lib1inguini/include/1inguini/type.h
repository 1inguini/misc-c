// SPDX-License-Identifier: CC0-1.0
// Copyright © 2025 1inguini. (Should I write this notice for CC0-1.0?)

#ifndef LIB1INGUINI_TYPE_H
#define LIB1INGUINI_TYPE_H

// 本当はsedでもっと高度に置き換えるけどビルドがめんどくさいのでマクロで誤魔化す
#define TYPEDEF typedef
#define STRUCT struct
#define UNION union
#include "../../arch/target/bits/alltypes.h.in"
#include "alltypes.h.in"
#undef TYPEDEF
#undef STRUCT
#undef UNION

#endif