# etcd (WIP)

Ad-hoc supervisior daemon without libc.

Inspired by

* [s6](https://skarnet.org/software/s6/index.html) from [skarnet](https://skarnet.org/)
* [supervise-daemon](https://github.com/OpenRC/openrc/tree/master/src/supervise-daemon) from [OpenRC](https://github.com/OpenRC/openrc/)
* [D. J. Bernstein](https://cr.yp.to/djb.html)'s [daemontools](https://cr.yp.to/daemontools.html).
* `systemd-run`

# Dependency

* [lib1inguini](../lib1inguini)

## Usage

``` sh
execd /run/execd/yes /usr/bin/yes Hello World!
```

## Current status

nothing.

## LICENSE

execd as a whole is licensed under the Creative Commons Zero v1.0 Universal (CC0-1.0)

Copyright © 2025 1inguini. (Should I write this notice for CC0-1.0?)

Portions of this software are derived from third-party works. Refer each subdirectories for detail.

* mostly everything: [D. J. Bernstein](https://cr.yp.to/djb.html)'s [daemontools](https://cr.yp.to/daemontools.html) which is public domain.
