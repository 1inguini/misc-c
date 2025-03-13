// SPDX-License-Identifier: CC0-1.0
// execd by 1inguini since 2025-03-13

#include <nolibc/nolibc.h>
#define NOLIBC_IGNORE_ERRNO

// `sigprocmask`はnolibcにない?
ssize_t sys_rt_sigprocmask(
    int how, const sigset_t *set, sigset_t *oldset, size_t sigsetsize)
{
  return my_syscall4(__NR_rt_sigprocmask, how, set, oldset, sigsetsize);
}

typedef ssize_t syscall_result; // `sys_*`の返り値

char usage[] = "execd: usage: execd $SUPERVISE_DIR $COMMAND $ARG1 $ARG2...\n";

syscall_result execd_log(int fd, char const message[])
{
  return sys_write(fd, message, strlen(message));
}

// 前提が満たされてないことが確認されたときに早期リターンする用
// ログを吐いたあとやユーザーにデバッグとかを求めるときは使わない
void execd_bye()
{
  execd_log(STDERR_FILENO, usage);
  exit(EXIT_FAILURE);
}

int main(int argc, char const *argv[])
{
  // temporary variable to store result of previous syscall
  syscall_result r = 0;

  // 前提条件チェック
  // BEGIN precondition-check
  if (argc < 2) // コマンド引数は2以上必要
  {
    execd_bye();
  }
  const char *sv_dir = argv[1];
  // END precondition-check

  // よくわからないがself pipeというものが必要らしい
  // BEGIN self-pipe
  int self_pipe[2];

  // s6、というか skalibsがこのフラグを立ててたのでわからないが立てておく
  // https://github.com/skarnet/skalibs/blob/main/src/libstddjb/selfpipe.c#L83
  // daemontoolsもあとから`fcntl`で設定してた (`coe.h`,`ndelay.h`)
  r = sys_pipe2(self_pipe, O_NONBLOCK | O_CLOEXEC);
  if (r)
  {
    execd_log(STDERR_FILENO, "execd: unable to create self-pipe");
    return EXIT_FAILURE;
  }
  // END self-pipe

  // BEGIN modify-signal-handling
  // `sigprocmask`はnolibcにない?

  // END modify-signal-handling
}
