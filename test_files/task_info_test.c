#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <linux/kernel.h>
#include <sys/types.h>

int main(int argc,char** argv){
	
	int pid = atoi(argv[1]);
	//int mypid = getpid();
	syscall(317, pid);
	return;
	

}
