#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]); // 명령형 인자(N) 정수형 변환
    int pid; // 자식 프로세스가 생성이 될 때 반환하는 pid를 담을 정수형 변수 선언 (자식 프로세스는 자기에겐 0 반환, 부모에겐 자기의 pid 반환)
    pid = fork(); // fork 함수로 자식 프로세스 생성

    if (pid == 0){ // 0이라면 -> 자식 프로세스라면
        /* child */
        printf("launch: start sumfact %d\n", N); // sumfact 프로그램 시작 알림
        execlp("./sumfact", "./sumfact", argv[1], NULL); // 프로그램 sumfact으로 인자값 전달하며 프로그램 실행
    }
    else{
        /* parent */
        wait(&pid); // 자식 프로세스가 끝날 때 까지
        
        int parent_result=0; // parent 합 계산을 담을 변수 선언
        
        for(int i = 1 ; i < N+1 ; i++){ // 1부터 N까지 합 계산
            parent_result += i;
        }

        printf("launch: sum = %d\n", parent_result); // 1부터 N까지 합 출력        
    }
    return 1; // 프로그램 종료
}