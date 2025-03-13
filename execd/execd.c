// SPDX-License-Identifier: CC0-1.0
// execd by 1inguini since 2025-03-13

#include <nolibc/nolibc.h>

int main(int argc, char const *argv[])
{
  char message[] = "Hello World!\n";
  write(STDOUT_FILENO, message, strlen(message));
  return 0;
}
