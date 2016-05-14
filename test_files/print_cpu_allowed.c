#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
int main(int argc, char** argv)
{
  char buff[256];
  int pid = atoi(argv[1]);
  syscall(318, pid, buff);
  printf("cpus allowed mask:  %s        (pid: %d)\n", buff, pid);
  return;
}
