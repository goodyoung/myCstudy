#include <stdio.h> // printf를 호출하기 위해 stdio.h 파일을 불러옴
int main(){

    printf("[----- [Goh Geon Young]  [2020017027] -----]\n");
    char charType; // 문자형 변수 charType를 선언
    int integerType; // 정수형 변수 integerType를 선언
    float floatType; // 실수형 변수 floatType를 선언 (메모리 크기: 4byte)
    double doubleType; // 실수형 변수 doubleType를 선언 (메모리 크기: 8byte)

    printf("Size of char: %ld byte\n",sizeof(charType)); // 문자형 변수 charType이 메모리에서 차지하는 byte 값을 long 데이터 타입으로 출력
    printf("Size of int: %ld bytes\n",sizeof(integerType)); // 정수형 변수 integerType이 메모리에서 차지하는 byte 값을 long 데이터 타입으로 출력
    printf("Size of float: %ld bytes\n",sizeof(floatType)); // 실수형 변수 floatType이 메모리에서 차지하는 byte 값을 long 데이터 타입으로 출력
    printf("Size of double: %ld bytes\n",sizeof(doubleType)); // 실수형 변수 doubleType이 메모리에서 차지하는 byte 값을 long 데이터 타입으로 출력
    
    printf("-----------------------------------------\n");
    printf("Size of char: %ld byte\n",sizeof(char)); // char의 데이터 타입이 메모리에서 차지하는 byte 값을 long 데이터 타입으로 출력
    printf("Size of int: %ld bytes\n",sizeof(int)); // int의 데이터 타입이 메모리에서 차지하는 byte 값을 long 데이터 타입으로 출력
    printf("Size of float: %ld bytes\n",sizeof(float)); // float의 데이터 타입이 메모리에서 차지하는 byte 값을 long 데이터 타입으로 출력
    printf("Size of double: %ld bytes\n",sizeof(double)); // double의 데이터 타입이 메모리에서 차지하는 byte 값을 long 데이터 타입으로 출력

    printf("-----------------------------------------\n");
    printf("Size of char*: %ld byte\n",sizeof(char*)); // char*의 데이터 타입이 메모리에서 차지하는 byte 값을 long 데이터 타입으로 출력
    printf("Size of int*: %ld bytes\n",sizeof(int*)); // int*의 데이터 타입이 메모리에서 차지하는 byte 값을 long 데이터 타입으로 출력
    printf("Size of float*: %ld bytes\n",sizeof(float*)); // float*의 데이터 타입이 메모리에서 차지하는 byte 값을 long 데이터 타입으로 출력
    printf("Size of double*: %ld bytes\n",sizeof(double*)); // double*의 데이터 타입이 메모리에서 차지하는 byte 값을 long 데이터 타입으로 출력
    
    return 0; // 0을 반환하면서 프로그램 종료
}