#include <linux/kernel.h>
#include "/home/nadav/linux-3.14.1_GitFolder/kernel/sched/sched.h"

 asmlinkage long sys_get_rq_num_running(int cpu_num)
{		
		printk("inside get_rq_num_running\n");
	        struct rq * my_rq;
		if (cpu_num == 0)
			my_rq=cpu_rq(0);
		else
			my_rq=cpu_rq(1);
		return my_rq->nr_running;
			 
}
