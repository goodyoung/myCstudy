#include <stdio.h>
#include <sys/syscall.h>
#define SYS_NUM 452
int main(void){
    syscall(SYS_NUM);
    return 0;
}