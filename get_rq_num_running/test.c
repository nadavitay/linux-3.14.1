#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
int main()
{
	         long int cpu0 = syscall(316,0);
		 long int cpu1 = syscall(316,1);
		          printf("cpu 0 nr running :  %ld\ncpu 1: nr running :  %ld\n", cpu0,cpu1);
			           return 0;
}
