#include <stdio.h> // 표준입출력 라이브러리 사용하기 위한 라이브러리 불러오기


void print_one(int *ptr, int rows); // 함수 print_one 프로토타입 선언

int main() {
    printf("[----- [Goh Geon Young]  [2020017027] -----]\n");
    int one[] = {0, 1, 2, 3, 4}; // 0,1,2,3,4를 저장하는 정수형 배열 one 선언
    
    printf("one = %p\n", one); // one 배열이 저장된 시작 주소 출력
    
    printf("&one = %p\n", &one); // 매개변수 one 배열이 저장되어있는 있는 주소 출력
    
    printf("&one[0] = %p\n", &one[0]); // one의 첫번째 공간에 저장된 값이 위치한 주소값을 출력
    printf("\n"); 
    
    printf("------------------------------------\n");
    printf(" print_one(&one[0], 5) \n");
    printf("------------------------------------\n");
    
    print_one(&one[0], 5); // print_one 함수에 매개변수 one의 첫번째 공간에 저장된 값이 위치한 주소값과 정수 5를 전달.
    
    printf("------------------------------------\n");
    printf(" print_one(one, 5) \n");
    printf("------------------------------------\n");
    
    print_one(one, 5); // print_one 함수에 매개변수 one 배열이 저장되어있는 첫번째 주소값과 정수 5를 전달.
    
    return 0; // 0 반환 및 프로그램 종료
}
    

void print_one(int *ptr, int rows) { // 함수 내부에서 call by reference의 값을 포인터 변수 ptr로 받고, call by value로 rows라는 변수로 받는다.
    /* print out a one-dimensional array using a pointer */
    int i; // 정수형 변수 i 선언
    printf ("Address \t Contents\n");
    for (i = 0; i < rows; i++) { // i가 0에서 rows까지 반복 (매개변수 정수형 변수 rows은 두 번의 호출 모두 정수 5를 받았다.)
        printf("%p \t %5d\n", ptr + i, *(ptr + i)); // 정수형 포인터 변수 ptr에 정수 i를 더한 주소값하고 해당 주소값에 저장된 값 출력
    }
    printf("\n"); 
}
