#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
int main(){

long int cpu0 = syscall(316,0);
long int cpu1 = syscall(316,1);
long int cpu2 = syscall(316,2);
long int cpu3 = syscall(316,3);
long int cpu4 = syscall(316,4);
long int cpu5 = syscall(316,5);	          
long int cpu6 = syscall(316,6);
long int cpu7 = syscall(316,7);
//long int cpu0 = syscall(316,0);




printf("cpu 0: nr running :  %ld\ncpu 1: nr running :  %ld\ncpu 2: nr running :  %ld\ncpu 3: nr running :  %ld\n\
cpu 4: nr running :  %ld\ncpu 5: nr running :  %ld\ncpu 6: nr running :  %ld\ncpu 7: nr running :  %ld\n",cpu0,cpu1,cpu2,cpu3,cpu4,cpu5,cpu6,cpu7);
			           return 0;
}
