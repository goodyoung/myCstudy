#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int N; // 프로그램 인자값 받을 전역 변수 N선언

// 팩토리얼 계산 함수
int factorial(int n){
    if (n==0) // 0이 되면 1을 반환
        return 1;
    else
        return n*factorial(n-1); // 재귀 함수로 팩토리얼 계산
}

// 첫 번째 thread가 실행하는 함수
void *thread_factorial() {
    printf("sumfact: factorial = %d\n", factorial(N)); // 1부터 N까지의 합 계산 및 출력
    return NULL; // 쓰레드가 사용하는 함수는 반환값이 필요하므로 NULL 반환
}

// 나머지 thread가 실행하는 함수
void *thread_sum() {
    int thread_result = 0;
    
    for(int i = 1 ; i < N+1 ; i++){ // 1부터 N까지 합 계산
        thread_result += i;
    }
    printf("sumfact: sum = %d\n", thread_result); // 1부터 N까지 합 출력

    return NULL; // 쓰레드가 사용하는 함수는 반환값이 필요하므로 NULL 반환
}

int main(int argc, char *argv[]) {
    N = atoi(argv[1]); // 명령형 인자(N) 정수형 변환
    
    pthread_t thread_id[N]; // thread 배열 생성

    // create thread
    for(int i =0; i<N;i++){
        if (i==0) // 첫번째 thread일 경우
            pthread_create(&thread_id[i],NULL,thread_factorial,NULL); // factorial 기능을 하는 함수 실행
        else
            pthread_create(&thread_id[i],NULL,thread_sum,NULL); // sum 기능을 하는 함수 실행
    }

    // thread join
    for(int i =0; i<N;i++){
        pthread_join(thread_id[i], NULL); // 각 tread가 종료될 때까지 기다림
    }

    return 1; // 프로그램 종료
}
