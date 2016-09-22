/*
 * main.c
 *
 *  Created on: Oct 7, 2013
 *      Author: noam
 */

#define _GNU_SOURCE
#include <sched.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define CPUS 8

int main(int argc, char **argv) {
	long i=0,j;
	int sum=0;
	int core=-1;

	cpu_set_t my_set;        /* Define your cpu_set bit mask. */
   	CPU_ZERO(&my_set);       /* Initialize it all to 0, i.e. no CPUs selected. */


	if (argc == 1 ){
		for(j=0;j<CPUS;j++){
			CPU_SET(j, &my_set);     /* set the bit that represents core i. */
		}
	} else  {
		for(j=1; j<argc; j++) 
		{
			core = atoi(argv[j]);
			if (core >= CPUS)
			{
				printf("wrong argument.\n");
				return -1;
			}
	   		CPU_SET(core, &my_set);     /* set the bit that represents core i. */
		}
	}

   	sched_setaffinity(0, sizeof(cpu_set_t), &my_set);

   	printf("Setting pid %d to cpu %d\n",getpid(),sched_getcpu());

	while(1){

		for (i=0;i<2000000000;i+=1) {
			sum+=2;
		}
		//sleep(2);
	   	printf("Process pid %d is running on cpu %d.    res=%d\n",getpid(),sched_getcpu(),sum);

	}
}
