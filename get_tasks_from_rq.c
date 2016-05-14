#include <linux/kernel.h>
#include <sched.h>
#include "/home/user/linux-3.14.1/kernel/sched/sched.h"
#include <linux/slab.h>
asmlinkage long sys_get_(int cpu_num)
{
	struct rq * my_rq;

	my_rq=cpu_rq(cpu_num);
	int* pids = (int*) kmalloc(sizeof(int)*my_rq->nr_running);
	struct task_struct *p, *n;
	raw_spin_lock_irq(&my_rq->lock);
	list_for_each_entry_safe(p, n, &env->src_rq->cfs_tasks, se.group_node){
		
	}
}

