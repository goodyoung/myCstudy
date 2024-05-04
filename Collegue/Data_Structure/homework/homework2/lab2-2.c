#include <stdio.h> // printf를 호출하기 위해 stdio.h 파일을 불러옴
int main() {
    printf("[----- [Goh Geon Young]  [2020017027] -----]\n");

    int i; // 정수형 변수 i 선언 
    int *ptr; // 정수형 포인터 변수 ptr 선언
    int **dptr; // 정수형 2중 포인터 변수 dptr 선언

    i = 1234; // 정수형 변수 i에 1234값 할당

    printf("[checking values before ptr = &i] \n");
    printf("value of i == %d\n", i); // 정수형 변수 i의 값을 부호 있는 10진수 정수로 출력 (위에서 할당한 1234가 나온다)
    printf("address of i == %p\n", &i); // 정수형 변수 i의 주소 값을 포인터 16진수로 출력 (i가 저장된 메모리 주소값이 나온다.)
    printf("value of ptr == %p\n", ptr); // 정수형 포인터 변수 ptr의 값을 포인터 16진수로 출력 (ptr에 값 할당이 되어있지 않아서 임의의 메모리 주소 값이 출력)
    printf("address of ptr == %p\n", &ptr); // 정수형 포인터 변수 ptr이 저장되어 있는 메모리 공간의 주소값을 포인터 16진수로 출력 (ptr이 저장된 메모리 주소값이 나온다.)

    /* ptr is now holding the address of i */
    ptr = &i; // 정수형 변수 i의 주소 값을 정수형 포인터 변수 ptr에 할당.

    printf("\n[checking values after ptr = &i] \n");
    printf("value of i == %d\n", i); // 정수형 변수 i의 값을 부호 있는 10진수 정수로 출력 (위에서 할당한 1234가 나온다)
    printf("address of i == %p\n", &i); // 정수형 변수 i의 주소 값을 포인터 16진수로 출력 (i가 저장된 메모리 주소값이 나온다.)
    printf("value of ptr == %p\n", ptr); // 정수형 포인터 변수 ptr의 값을 포인터 16진수로 출력 (ptr에 i의 주소값이 할당이 되어있으므로 바로 위의 i의 주소값과 동일하게 출력되게 된다.)
    printf("address of ptr == %p\n", &ptr); // 정수형 포인터 변수 ptr이 저장되어 있는 메모리 공간의 주소값을 포인터 16진수로 출력 (ptr이 저장된 메모리 주소값이 나온다.)
    printf("value of *ptr == %d\n", *ptr); // 정수형 포인터 변수 ptr이 가리키고 있는 메모리 주소내의 값을 부호 있는 10진수 정수로 출력 (i의 주소값이 할당되어 있으므로 i의 값(1234)이 출력되게 된다.)

    /* dptr is now holding the address of ptr */
    dptr = &ptr; // 정수형 포인터 변수 ptr의 주소 값을 정수형 이중 포인터 변수 dptr에 할당.

    printf("\n[checking values after dptr = &ptr] \n");
    printf("value of i == %d\n", i); // 정수형 변수 i의 값을 부호 있는 10진수 정수로 출력 (위에서 할당한 1234가 나온다.)
    printf("address of i == %p\n", &i); // 정수형 변수 i의 주소 값을 포인터 16진수로 출력 (i가 저장된 메모리 주소값이 나온다.)
    printf("value of ptr == %p\n", ptr); // 정수형 포인터 변수 ptr의 값을 포인터 16진수로 출력 (ptr에 i의 주소값이 할당이 되어있으므로 바로 위의 i의 주소값과 동일하게 출력되게 된다.)
    printf("address of ptr == %p\n", &ptr); // 정수형 포인터 변수 ptr이 저장되어 있는 메모리 공간의 주소값을 포인터 16진수로 출력 (ptr이 저장된 메모리 주소값이 나온다.)
    printf("value of *ptr == %d\n", *ptr); // 정수형 포인터 변수 ptr이 가리키고 있는 메모리 주소내의 값을 출력 (i의 주소값이 할당되어 있으므로 i의 값(1234)이 출력되게 된다.)
    printf("value of dptr == %p\n", dptr); // 정수형 이중 포인터 변수 dptr의 값을 포인터 16진수로 출력 (dptr에 ptr의 주소값이 할당이 되어있으므로 ptr의 주소값과 동일하게 출력되게 된다.)
    printf("address of dptr == %p\n", &dptr); // 정수형 이중 포인터 변수 dptr이 저장되어 있는 메모리 공간의 주소값을 포인터 16진수로 출력 (dptr이 저장된 메모리 주소값이 나온다.)
    printf("value of *dptr == %p\n", *dptr); // 정수형 이중 포인터 변수 dptr이 가리키고 있는 메모리 주소내의 값을 출력 (ptr의 주소값이 할당되어 있으므로 ptr의 값(i의 주소값)이 출력되게 된다.)
    printf("value of **dptr == %d\n", **dptr); // 정수형 이중 포인터 변수 dptr이 가리키고 있는 메모리 주소내의 값이 다시 참조하고 있는 값을 출력 (ptr의 주소값이 할당되어 있으므로 ptr의 값(i의 주소값)이 참조하고 있는 i의 값이 출력되게 된다.)

    /* changing the value of *ptr */
    *ptr = 7777; // 정수형 포인터 변수 ptr이 가리키고 있는 메모리 주소내의 값을 7777로 변경한다. (1234가 7777로 변경된다.)

    printf("\n[after *ptr = 7777] \n");
    printf("value of i == %d\n", i); // 정수형 변수 i의 값을 부호 있는 10진수 정수로 출력 (위에서 변경된 7777로 나온다.)
    printf("value of *ptr == %d\n", *ptr); // 정수형 포인터 변수 ptr이 가리키고 있는 메모리 주소내의 값을 출력 (i의 주소값이 할당되어 있으므로 i의 값(7777)이 출력되게 된다.)
    printf("value of **dptr == %d\n", **dptr); // 정수형 이중 포인터 변수 dptr이 가리키고 있는 메모리 주소내의 값이 다시 참조하고 있는 값을 출력 (ptr의 주소값이 할당되어 있으므로 ptr의 값(i의 주소값)이 참조하고 있는 i의 값(7777)이 출력되게 된다.)

    /* changing the value of **dptr */
    **dptr = 8888; // 정수형 이중 포인터 변수 dptr이 가리키고 있는 메모리 주소내의 값이 다시 참조하고 있는 값을 8888로 변경한다. (7777이 8888로 변경된다.)

    printf("\n[after **dptr = 8888] \n");
    printf("value of i == %d\n", i); // 정수형 변수 i의 값을 부호 있는 10진수 정수로 출력 (위에서 변경된 8888로 나온다.)
    printf("value of *ptr == %d\n", *ptr); // 정수형 포인터 변수 ptr이 가리키고 있는 메모리 주소내의 값을 출력 (i의 주소값이 할당되어 있으므로 i의 값(8888)이 출력되게 된다.)
    printf("value of **dptr == %d\n", **dptr); // 정수형 이중 포인터 변수 dptr이 가리키고 있는 메모리 주소내의 값이 다시 참조하고 있는 값을 출력 (ptr의 주소값이 할당되어 있으므로 ptr의 값(i의 주소값)이 참조하고 있는 i의 값(8888)이 출력되게 된다.)

    return 0; // 0을 반환하면서 프로그램 종료

}