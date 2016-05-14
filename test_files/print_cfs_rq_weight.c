#include <stdio.h>
#include <string.h>

#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
int main(int argc,char** argv){
//	int cpu_num = atoi(argv[1]);
//	long weight = syscall(320,cpu_num);
//	printf("%ld \n",weight);

  long int cpu0 = syscall(320,0);
  long int cpu1 = syscall(320,1);
  long int cpu2 = syscall(320,2);
  long int cpu3 = syscall(320,3);
  long int cpu4 = syscall(320,4);
  long int cpu5 = syscall(320,5);
  long int cpu6 = syscall(320,6);
  long int cpu7 = syscall(320,7);

  printf("cpu 0: weight :  %ld\n\
cpu 1: weight :  %ld\n\
cpu 2: weight :  %ld\n\
cpu 3: weight :  %ld\n\
cpu 4: weight :  %ld\n\
cpu 5: weight :  %ld\n\
cpu 6: weight :  %ld\n\
cpu 7: weight :  %ld\n",cpu0,cpu1,cpu2,cpu3,cpu4,cpu5,cpu6,cpu7);

  return 0;
}
