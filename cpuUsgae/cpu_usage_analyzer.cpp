#include "cpu_usage_analyzer.h"
#include <stdio.h>

cpu_usage_analyzer::cpu_usage_analyzer()

	run();
}



void cpu_usage_analyzer::update_stat()
{
	unsigned long long int ioWait, irq, softIrq, steal, guest, guestnice,idletime;
	unsigned long long int systemalltime, idlealltime, totaltime, virtalltime;
	unsigned long long int systemtime,nicetime,usertime;
	char buffer[256];

	int i,j;
	for (i=0;i<NUM_OF_CPU;i++){
		idle_prev_stat[i]=idle_curr_stat[i];
		nonIdle_prev_stat[i]=nonIdle_curr_stat[i];
	}

	FILE* statFile = fopen(PROCSTATFILE,"r");
	if ( statFile == NULL )
		printf("didnt opennnnnnnnnnnnnn");

	fgets(buffer, 255, statFile); //skip the first line of stat file
	//extract info of all cpu
	for (i=0 ; i<NUM_OF_CPU;i++){
		fgets(buffer, 255, statFile);
		//printf("%s",buffer);
		int scandnum = sscanf(buffer, "cpu  %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu", &usertime, &nicetime, &systemtime, &idletime, &ioWait, &irq, &softIrq, &steal, &guest, &guestnice);
		idle_curr_stat[i] = idletime + ioWait;
		nonIdle_curr_stat[i] = usertime + nicetime + systemtime + irq + softIrq + steal;
	}


}

cpu_usage_analyzer::calc_print_usage()
{
	int i;
	long long unsigned int cpuUsage,totIdle,totNonIdle;
	for (i=0;i<NUM_OF_CPU;i++){
		totIdle = idle_curr_stat[i]- idle_prev_stat[i];
		totNonIdle = nonIdle_curr_stat[i]- nonIdle_prev_stat[i];
		cpuUsage =totNonIdle/(totIdle+totNonIdle);
		printf("cpu %d usage: %llu",i,cpuUsage);
	}
}


cpu_usage_analyzer::run()
{
	while (1)
	{
		update_stat();
		calc_print_usage();
		sleep(/*  */);
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
