# misc-c

Miscellaneous C language scripts.

## execd (WIP)

Ad-hoc supervisior daemon.

Inspired by

* [s6](https://skarnet.org/software/s6/index.html) from [skarnet](https://skarnet.org/)
* [supervise-daemon](https://github.com/OpenRC/openrc/tree/master/src/supervise-daemon) from [OpenRC](https://github.com/OpenRC/openrc/)
* [D. J. Bernstein](https://cr.yp.to/djb.html)'s [daemontools](https://cr.yp.to/daemontools.html).
* `systemd-run`

### Usage

``` sh
execd /run/execd/yes /usr/bin/yes Hello World!
```

### memo

Linuxの[nolibc](https://web.git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/tree/tools/include/nolibc)をexecdに使ってみる?

### LICENSE

CC0 1.0 Universal

## LICENSE

各サブディレクトリ参照

* `include/nolibc` is imported from Linux, so it's GPL-2.0
