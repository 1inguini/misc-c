# lib1inguini

libc alternative.

libcの代わりに使うやつ。

## Current status

"Hello World!"はできた。

## Selecting target architecture

`ln -s $TARGET_ARCH ./arch/target`

## LICENSE

lib1inguini as a is licensed under the Creative Commons Zero v1.0 Universal (CC0-1.0)

But lots of code are derived from third-party works, so think it as MIT or something.

Copyright © 2025 1inguini. (Should I write this notice for CC0-1.0?)

Portions of this software are derived from third-party works:

* musl libc v1.2.5 `Copyright © 2005-2020 Rich Felker, et al.` licensed under the standard MIT License.
  * `arch/`: From `arch/` and `crt/`.
    (Actually this part doesn't need copyright and permission notice according to musl's COPYRIGHT file .)
  * `include/1inguini/attribute.h`: From `src/include/features.h`
  * And more...
