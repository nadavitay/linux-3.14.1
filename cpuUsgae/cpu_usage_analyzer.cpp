#include "cpu_usage_analyzer.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

cpu_usage_analyzer::cpu_usage_analyzer(){

	/*memset(idle_prev_stat,0,sizeof(*idle_curr_stat)*NUM_OF_CPU);
	memset(idle_prev_stat,0,sizeof(*idle_prev_stat)*NUM_OF_CPU);
	memset(idle_prev_stat,0,sizeof(*nonIdle_curr_stat)*NUM_OF_CPU);
	memset(idle_prev_stat,0,sizeof(*nonIdle_prev_stat)*NUM_OF_CPU);*/
	int i;
	for (i=0;i<NUM_OF_CPU;i++){
		idle_curr_stat[i]=0;
		idle_prev_stat[i]=0;
		nonIdle_curr_stat[i]=0;
		nonIdle_prev_stat[i]=0;
	}

}



void cpu_usage_analyzer::update_stat()
{
	unsigned long long int ioWait, irq, softIrq, steal, guest, guestnice,idletime;

	unsigned long long int systemtime,nicetime,usertime;
	char buffer[256];

	int i;
	for (i=0;i<NUM_OF_CPU;i++){
		idle_prev_stat[i]=idle_curr_stat[i];
		nonIdle_prev_stat[i]=nonIdle_curr_stat[i];
	}
	
	//printf("update stat : before opening file\n");
	FILE* statFile = fopen(PROCSTATFILE,"r");
	if ( statFile == NULL )
		printf("didnt opennnnnnnnnnnnnn");

	fgets(buffer, 255, statFile); //skip the first line of stat file
	//extract info of all cpu
	for (i=0 ; i<NUM_OF_CPU;i++){
		fgets(buffer, 255, statFile);
		//printf("%s",buffer);
		 sscanf(buffer, "cpu  %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu", &usertime, &nicetime, &systemtime, &idletime, &ioWait, &irq, &softIrq, &steal, &guest, &guestnice);
		idle_curr_stat[i] = idletime + ioWait;
		nonIdle_curr_stat[i] = usertime + nicetime + systemtime + irq + softIrq + steal;
	}

	fclose(statFile);
}

void cpu_usage_analyzer::calc_print_usage()
{
	int i;
	long  double totIdle,totNonIdle, cpuUsage;
	for (i=0;i<NUM_OF_CPU;i++){
		totIdle = idle_curr_stat[i]- idle_prev_stat[i];
		totNonIdle = nonIdle_curr_stat[i]- nonIdle_prev_stat[i];
		cpuUsage =totNonIdle/(totIdle+totNonIdle);
		printf("cpu %d usage: %Lf\n",i,cpuUsage);
	}
}


void cpu_usage_analyzer::run()
{
	
	/*int i;
	for (i=0;i<10;i++){
		update_stat();
		calc_print_usage();
		sleep(1);
	}*/
	while (1)
	{
		//printf("before update stat");
		update_stat();
		//printf("hello");
		calc_print_usage();
		//printf("before sleep");
		sleep(1);
		
	}
}

/*
 * file = fopen(PROCSTATFILE, "r");
   if (file == NULL) {
      CRT_fatalError("Cannot open " PROCSTATFILE);
   }
   for (int i = 0; i <= cpus; i++) {
      char buffer[256];
      int cpuid;
      unsigned long long int ioWait, irq, softIrq, steal, guest, guestnice;
      unsigned long long int systemalltime, idlealltime, totaltime, virtalltime;
      ioWait = irq = softIrq = steal = guest = guestnice = 0;
      // Dependending on your kernel version,
      // 5, 7, 8 or 9 of these fields will be set.
      // The rest will remain at zero.
      fgets(buffer, 255, file);
      if (i == 0)
         sscanf(buffer, "cpu  %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu", &usertime, &nicetime, &systemtime, &idletime, &ioWait, &irq, &softIrq, &steal, &guest, &guestnice);
      else {
         sscanf(buffer, "cpu%4d %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu", &cpuid, &usertime, &nicetime, &systemtime, &idletime, &ioWait, &irq, &softIrq, &steal, &guest, &guestnice);
         assert(cpuid == i - 1);
      }
 *
 * */
