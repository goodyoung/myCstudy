#include <stdio.h> // 표준입출력 라이브러리 사용하기 위한 라이브러리 불러오기

struct student { // student 구조체 선언
    char lastName[13]; // char 배열(13 bytes) lastName 선언
    int studentId; // 정수형 (4 bytes) studentId 선언
    short grade; // short형 (2 bytes) grade 선언
};

int main() {
    printf("[----- [Goh Geon Young]  [2020017027] -----]\n");
    struct student pst; // 구조체 student 변수 pst 선언

    printf("size of student = %ld\n", sizeof(struct student)); // 구조체 student가 메모리에서 차지하는 byte 값을 long 데이터 타입으로 출력
    /* 출력 시 padding에 의해서 4byte int 자료형이 최대 크기이므로 4byte를 기준으로 메모리 순서를 맞추게 된다.
       따라서 13 + (3) + 4 + 2 + (2) = 24bytes(괄호는 padding byte)가 나오게 된다.
    */
    
    printf("size of int = %ld\n", sizeof(int)); // int의 데이터 타입이 메모리에서 차지하는 byte 값을 long 데이터 타입으로 출력
    
    printf("size of short = %ld\n", sizeof(short)); // short의 데이터 타입이 메모리에서 차지하는 byte 값을 long 데이터 타입으로 출력
    return 0; 
}