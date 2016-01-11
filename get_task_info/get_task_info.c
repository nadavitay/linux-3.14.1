#include <linux/sched.h>
#include <linux/kernel.h>

asmlinkage long sys_get_task_info(pid_t task_pid){
    struct task_struct* my_task = find_task_by_vpid(task_pid);
    struct thread_info* task_thread_info = task_thread_info(my_task);
    int my_cpu = task_thread_info->cpu;
    printk("Im in get_task_info running on cpu number %d \n",my_cpu);
    return 0;

}


