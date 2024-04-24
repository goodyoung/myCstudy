#include <stdio.h> // 표준입출력 라이브러리 사용하기 위한 라이브러리 불러오기
#include <stdlib.h> // 메모리 동적할당을 하기 위한 라이브러리 불러오기

int main() {
    printf("[----- [Goh Geon Young]  [2020017027] -----]\n");
    int list[5]; // 크기가 5인 정수형 배열 선언
    int *plist[5] = {NULL,}; // 포인터 변수를 5개 저장할 수 있는 정수형 포인터 배열 선언, 할당된 배열 안의 값은 NULL로 초기화

    plist[0] = (int *)malloc(sizeof(int)); // plist 첫번째 공간에 int 크기의 메모리 동적 할당

    list[0] = 1; // list 첫번째 공간에 1을 할당
    list[1] = 100; // list 두번째 공간에 100을 할당
    
    *plist[0] = 200; // plist 첫번째 공간(int 크기의 메모리)에 할당된 메모리 주소값 안에 값 200을 저장
    
    
    printf("list[0] = %d\n", list[0]); // list의 첫번째 공간에 저장된 값 출력
    
    printf("&list[0] = %p\n", &list[0]); // list의 첫번째 공간에 저장된 값이 위치한 주소값을 출력
    
    printf("list = %p\n", list); // list 배열이 저장된 시작 주소 출력 (&list[0] 랑 같다.)
    
    printf("&list = %p\n", &list); // list 배열이 저장되어있는 주소 출력 (list, &list[0] 랑 같다.)
    
    printf("----------------------------------------\n\n");
    printf("list[1] = %d\n", list[1]); // list의 두번째 공간에 저장된 값 출력
    
    printf("&list[1] = %p\n", &list[1]); // list의 두번째 공간에 저장된 값이 위치한 주소값을 출력
    
    printf("*(list+1) = %d\n", *(list + 1)); // list의 두번째의 주소내의 값 출력
    
    printf("list+1 = %p\n", list+1); // list의 두번째 공간의 주소 값 출력
    
    printf("----------------------------------------\n\n");
    printf("*plist[0] = %d\n", *plist[0]); // plist의 첫번째 공간에 할당된 공간에 저장된 값을 출력
    
    printf("&plist[0] = %p\n", &plist[0]); // plist의 첫번째 공간에 저장된 값이 위치한 주소값을 출력
    
    printf("&plist = %p\n", &plist); // plist 배열이 저장되어있는 주소 출력 (&plist[0] 랑 같다.)
    
    
    printf("plist = %p\n", plist); // plist 배열이 저장된 시작 주소 출력 (&plist, &plist[0] 랑 같다.)
    
    printf("plist[0] = %p\n", plist[0]); // plist 배열의 첫번째 공간에 할당된 메모리 주소 출력 (첫번째 공간에 정수형 int 공간을 동적 할당을 하였으므로 값이 나온다)
    
    printf("plist[1] = %p\n", plist[1]); // plist 배열의 두번째 공간에 할당된 메모리 주소 출력
    
    printf("plist[2] = %p\n", plist[2]); // plist 배열의 세번째 공간에 할당된 메모리 주소 출력
    
    printf("plist[3] = %p\n", plist[3]); // plist 배열의 네번째 공간에 할당된 메모리 주소 출력
    
    printf("plist[4] = %p\n", plist[4]); // plist 배열의 다섯번째 공간에 할당된 메모리 주소 출력
    
    free(plist[0]); // plist 배열의 첫번째 공간에 동적 할당된 메모리 해제
    
    return 0; // 0 반환 및 프로그램 종료
}