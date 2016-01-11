#include <linux/mm.h>
#include <linux/export.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/rculist.h>
#include <linux/bootmem.h>
#include <linux/hash.h>
#include <linux/pid_namespace.h>
#include <linux/init_task.h>
#include <linux/syscalls.h>
#include <linux/proc_ns.h>
#include <linux/proc_fs.h>
#include <linux/kernel.h>

asmlinkage long sys_ get_task_info(pid_t task_pid){
    struct task_struct* task = find_task_by_vpid(task_pid);
    struct thread_info task_thread_info = task_thread_info(task);
    int my_cpu = task_thread_info->cpu;
    printk("Im in get_task_info running on cpu number %d \n",my_cpu);
    return 0;

}


