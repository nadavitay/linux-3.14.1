

#include <stdio.h>
#include <string.h>

#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>

#define TASKS_PER_CPU 40

int main(int argc,char** argv){
	int cpuNum = atoi(argv[1]);
	int pids[300];
	syscall(319,cpuNum,pids);
	int i;
	for (i=0;i<TASKS_PER_CPU;i++){
		printf("%d \t",pids[i]);
	}	
}

