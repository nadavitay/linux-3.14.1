#include <linux/sched.h>
#include <linux/kernel.h>
#include "../kernel/sched/sched.h"

asmlinkage long sys_get_cfs_queue_weight(int cpu_num){
	struct rq * rq_ = cpu_rq(cpu_num);
	return (rq_->cfs).load.weight;
}
