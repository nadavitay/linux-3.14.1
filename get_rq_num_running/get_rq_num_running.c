#include <linux/kernel.h>
#include "/home/nadav/linux-3.14.1/kernel/sched/sched.h"

 asmlinkage long sys_get_rq_num_running(int cpu_num)
{		
		printk("inside get_rq_num_running\n");
	        struct rq * my_rq;
		
	
		my_rq=cpu_rq(cpu_num);
		return my_rq->nr_running;
			 
}
