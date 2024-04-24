#include <stdio.h> // 표준입출력 라이브러리 사용하기 위한 라이브러리 불러오기
#define MAX_SIZE 100 // 상수 매크로 선언

float sum1(float list[], int); // 함수 sum1 프로토타입 선언
float sum2(float *list, int); // 함수 sum2 프로토타입 선언
float sum3(int n, float *list); // 함수 sum3 프로토타입 선언

float input[MAX_SIZE], answer;  // 크기가 100인 실수형 배열 및 실수형 변수 선언
int i; // 정수형 변수 선언

void main(void) {
    printf("[----- [Goh Geon Young]  [2020017027] -----]\n");
    for(i=0; i < MAX_SIZE; i++) // i가 0에서 99까지 100번 반복
        input[i] = i; // input 배열에 첫번째 공간부터 100번째 공간에 0~99를 각각 저장

    /* for checking call by reference */ 
    printf("--------------------------------------\n");
    printf(" sum1(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input); // input 배열이 저장된 시작 주소 출력

    answer = sum1(input, MAX_SIZE); // sum1 함수에 매개변수 input 배열 시작 주소, 상수 100을 전달. sum1 반환값을 실수형 변수 answer로 할당.

    printf("The sum is: %f\n\n", answer); // sum1 반환값을 받은 실수형 변수 answer의 값 출력

    printf("--------------------------------------\n");
    printf(" sum2(input, MAX_SIZE) \n");

    printf("--------------------------------------\n");
    printf("input \t= %p\n", input); // input 배열이 저장된 시작 주소 출력
    answer = sum2(input, MAX_SIZE); // sum2 함수에 매개변수 input 배열 시작 주소, 상수 100을 전달. sum2 반환값을 실수형 변수 answer로 할당.
    printf("The sum is: %f\n\n", answer); // sum2 반환값을 받은 실수형 변수 answer의 값 출력

    printf("--------------------------------------\n");
    printf(" sum3(MAX_SIZE, input) \n"); 
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input); // input 배열이 저장된 시작 주소 출력
    answer = sum3(MAX_SIZE, input); // sum3 함수에 매개변수 상수 100과 input 배열 시작 주소를 전달. sum3 반환값을 실수형 변수 answer로 할당.
    printf("The sum is: %f\n\n", answer); // sum3 반환값을 받은 실수형 변수 answer의 값 출력
}

float sum1(float list[], int n) {
    printf("list \t= %p\n", list); // call by reference로 호출 시 받아온 배열(input)의 시작 주소를 출력
    printf("&list \t= %p\n\n", &list); // 매개변수 list 배열이 저장되어있는 있는 주소 출력
    int i; // 정수형 변수 i 선언
    float tempsum = 0; // 실수형 변수 tempsum에 0 값 할당.
    for(i = 0; i < n; i++) // i가 0에서 99까지 100번 반복 (매개변수 정수형 변수 n은 100의 값을 받았다.)
        tempsum += list[i]; // 매개변수 list 인덱스에 접근을 하여 값을 얻는 방식으로 모든 요소를 누적하여 실수형 변수 tempsum에 더함.
    return tempsum; // 실수형 변수 tempsum을 반환.
}

float sum2(float *list, int n) {
    printf("list \t= %p\n", list); // call by reference로 호출 시 받아온 배열(input)의 시작 주소를 출력
    printf("&list \t= %p\n\n", &list); // 매개변수 list 배열이 저장되어있는 있는 주소 출력
    int i; // 정수형 변수 i 선언
    float tempsum = 0; // 실수형 변수 tempsum에 0 값 할당.

    for(i = 0; i < n; i++) // i가 0에서 99까지 100번 반복 (매개변수 정수형 변수 n은 100의 값을 받았다.)
        tempsum += *(list + i); // 매개변수 list 배열의 i번째 공간 안의 값에 접근하는 방식으로 모든 요소를 누적하여 실수형 변수 tempsum에 더함.
    return tempsum; // 실수형 변수 tempsum을 반환.
}

/* stack variable reuse test */
float sum3(int n, float *list) { // sum2와 다르게 매개변수의 순서가 다르게 받아온다. 그럼 sum2의 매개변수의 list의 시작주소와는 다른 값이 나타나게 된다.
    printf("list \t= %p\n", list); // call by reference로 호출 시 받아온 배열(input)의 시작 주소를 출력
    printf("&list \t= %p\n\n", &list); // 매개변수 list 배열이 저장되어있는 있는 주소 출력
    int i; // 정수형 변수 i 선언
    float tempsum = 0; // 실수형 변수 tempsum에 0 값 할당.
    for(i = 0; i < n; i++) // i가 0에서 99까지 100번 반복 (매개변수 정수형 변수 n은 100의 값을 받았다.)
        tempsum += *(list + i); // 매개변수 list 배열의 i번째 공간의 주소내의 값에 접근하는 방식으로 모든 요소를 누적하여 실수형 변수 tempsum에 더함.
    return tempsum; // 실수형 변수 tempsum을 반환.
}
