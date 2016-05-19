#include <linux/kernel.h>
#include <linux/sched.h>

#include "../kernel/sched/sched.h"
#include <linux/slab.h>
#include <asm/uaccess.h>

asmlinkage long sys_get_tasks_from_rq(int cpu_num,void* dst)
{
	struct rq * my_rq;

	my_rq=cpu_rq(cpu_num);
	int* pids = (int*) kmalloc(sizeof(int)*my_rq->nr_running,GFP_KERNEL);
	struct task_struct *p, *n;
	int i=0;
	raw_spin_lock_irq(&my_rq->lock);
	list_for_each_entry_safe(p, n, &my_rq->cfs_tasks, se.group_node){
		pids[i]=task_pid_vnr(p);		
		printk("curr pid is %d\n",pids[i]);
		i++;
		
	}
	
	raw_spin_unlock_irq(&my_rq->lock);

	copy_to_user(dst,pids,300);
	return 0;
}

