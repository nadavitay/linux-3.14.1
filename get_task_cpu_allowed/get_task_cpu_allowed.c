#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/cpumask.h>
#include <asm/uaccess.h>

asmlinkage long sys_get_task_cpu_allowed(pid_t task_pid, void* dst){
	struct task_struct* my_task = find_task_by_vpid(task_pid);
	char buff[256];
	cpumask_scnprintf(buff, 256, &(my_task->cpus_allowed));
	copy_to_user(dst, buff, 256);
	return 0;
}

