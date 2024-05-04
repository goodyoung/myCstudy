#include <stdio.h> // 표준입출력 라이브러리 사용하기 위한 라이브러리 불러오기
#include <stdlib.h> // 메모리 동적할당을 하기 위한 라이브러리 불러오기
void main() {
    printf("[----- [Goh Geon Young]  [2020017027] -----]\n");
    int list[5]; // 크기가 5인 정수형 배열 선언

    int *plist[5]; // 포인터 변수를 5개 저장할 수 있는 정수형 포인터 배열 선언

    list[0] = 10; // list 첫번째 공간에 10을 할당

    list[1] = 11; // list 두번째 공간에 11을 할당

    plist[0] = (int*)malloc(sizeof(int)); // plist 첫번째 공간에 int 크기의 메모리 동적 할당

    printf("list[0] \t= %d\n", list[0]); // list의 첫번째 공간에 저장된 값 출력

    printf("list \t\t= %p\n", list); // list 배열이 저장된 시작 주소 출력

    printf("&list[0] \t= %p\n", &list[0]); // list의 첫번째 공간에 저장된 값이 위치한 주소값을 출력 (list 랑 같다.)

    printf("list + 0 \t= %p\n", list+0); // list의 첫번째 공간의 주소값 출력 (list, &list[0] 랑 같다.)

    printf("list + 1 \t= %p\n", list+1); // list의 두번째 공간의 주소값 출력

    printf("list + 2 \t= %p\n", list+2); // list의 세번째 공간의 주소값 출력

    printf("list + 3 \t= %p\n", list+3); // list의 네번째 공간의 주소값 출력

    printf("list + 4 \t= %p\n", list+4); // list의 다섯번째 공간의 주소값 출력

    printf("&list[4] \t= %p\n", &list[4]); // list의 다섯번째 공간에 저장된 값이 위치한 주소값을 출력

    free(plist[0]); // plist 배열의 첫번째 공간에 동적 할당된 메모리 해제
}
