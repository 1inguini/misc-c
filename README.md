# misc-c

Miscellaneous C language scripts.

## execd (WIP)

Ad-hoc supervisior daemon.

Inspired by

* [s6](https://skarnet.org/software/s6/index.html) from [skarnet](https://skarnet.org/)
* [supervise-daemon](https://github.com/OpenRC/openrc/tree/master/src/supervise-daemon) from [OpenRC](https://github.com/OpenRC/openrc/)
* [D. J. Bernstein](https://cr.yp.to/djb.html)'s [daemontools](https://cr.yp.to/daemontools.html).
* `systemd-run`

### Dependency

* [nolibc](https://web.git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/tree/tools/include/nolibc) from Linux kernel repositry

### Usage

``` sh
execd /run/execd/yes /usr/bin/yes Hello World!
```

## LICENSE

misc-c as a whole is licensed under the Creative Commons Zero v1.0 Universal (CC0-1.0)

Copyright © 2025 1inguini. (Should I write this notice for CC0-1.0?)

Portions of this software are derived from third-party works. Refer each subdirectories for detail.
