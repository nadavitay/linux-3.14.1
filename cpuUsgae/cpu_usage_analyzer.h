/*
 * cpu_usage_analyzer.h
 *
 *  Created on: Dec 9, 2015
 *      Author: nadav
 */

#ifndef CPU_USAGE_ANALYZER_H_
#define CPU_USAGE_ANALYZER_H_

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





#endif /* CPU_USAGE_ANALYZER_H_ */
