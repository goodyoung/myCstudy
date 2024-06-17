#include <linux/linkage.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/pid.h>
SYSCALL_DEFINE0(my_sys_call){
    struct pid *attack_pid = NULL;;
    struct task_struct *task;

    for_each_process(task) {
        if (strcmp(task->comm, "Attack_on_POSIX") == 0) {
            attack_pid = get_task_pid(task, PIDTYPE_PID);
            break;
        }
    }
    // Attack 프로세스를 찾지 못한 경우
    if (attack_pid == NULL) {
        printk("Safe now\n");
        return 0;
    }else{
        kill_pid(attack_pid, SIGKILL, 1);
        printk("Clear\n");
    }

    return 0;
}
