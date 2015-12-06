#ifndef CPU_USAGE_ANALYZER.H
#define CPU_USAGE_ANALYZER.H

#define NUM_OF_CPU 2

#define PROCSTATFILE "/proc/stat"



class cpu_usage_analyzer
{
public:
	cpu_usage_analyzer();

	void run();
	void update_stat();
	void calc_print_usage();

private:
	unsigned long long int idle_prev_stat[NUM_OF_CPU];
	unsigned long long int idle_curr_stat[NUM_OF_CPU];
	unsigned long long int nonIdle_curr_stat[NUM_OF_CPU];
	unsigned long long int nonIdle_prev_stat[NUM_OF_CPU];
};

#endif


/*typedef struct
{
	unsigned long long int 	usertime,
							nicetime,
							systemtime,
							idletime,
							ioWait,
							irq,
							softIrq,
							steal,
							guest,
							guestnice;
} cpu_stat;*/
