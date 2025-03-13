// SPDX-License-Identifier: CC0-1.0
// execd by 1inguini since 2025-03-13

#include <nolibc/nolibc.h>
#define NOLIBC_IGNORE_ERRNO

typedef ssize_t syscall_result;
char usage[] = "execd: usage: execd $SUPERVISE_DIR $COMMAND $ARG1 $ARG2...\n";

void execd_exit()
{
  sys_write(STDERR_FILENO, usage, strlen(usage));
  exit(EXIT_FAILURE);
}

int main(int argc, char const *argv[])
{
  if (argc < 2) // コマンド引数は2以上必要
  {
    execd_exit();
  }
  const char *sv_dir = argv[1];
}
