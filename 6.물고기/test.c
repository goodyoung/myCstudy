#include <time.h>
#include <stdio.h>

int main(void)
{
    int  i;
    double start, end;

    //for 루프 시작 시간
    start = (double)clock() / CLOCKS_PER_SEC;    

    //for루프 100000000번 돌아보기
    int sum = 0;
    for (i = 0; i < 100000000; i++) {
        sum++;
    }

    //for 루프 끝난 시간
    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("프로그램 수행 시간 :%lf\n", (end));

    printf("프로그램 수행 시간 :%lf\n", (end-start));
}