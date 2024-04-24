#include <stdio.h> // 표준입출력 라이브러리 사용하기 위한 라이브러리 불러오기

int main() {
    printf("[----- [Goh Geon Young]  [2020017027] -----]\n");

    int **x; // 정수형 2중 포인터 변수 x 선언

    printf("sizeof(x) = %lu\n", sizeof(x)); // 정수형 2중 포인터 변수 x가 메모리에서 차지하는 byte값을 long 데이터 타입으로 출력
    // 포인터 변수의 경우 64bit machine에서 8byte를 차지하기 때문에 8이 출력된다.

    printf("sizeof(*x) = %lu\n", sizeof(*x)); // 정수형 2중 포인터 변수 x가 한 번 dereference가 되어서 메모리에서 차지하는 byte값을 long 데이터 타입으로 출력
    // 2중 포인터가 한 번 dereference가 되어도 여전히 포인터 변수이기 때문에 포인터 변수의 경우 64bit machine에서 8byte를 차지하기 때문에 8이 출력된다.

    printf("sizeof(**x) = %lu\n", sizeof(**x)); // 정수형 2중 포인터 변수 x가 두 번 dereference가 되어서 메모리에서 차지하는 byte값을 long 데이터 타입으로 출력
    // 두 번 dereference가 되면 저장되어있는 값을 나타내기 때문에 정수형 데이터 값이 차지하는 4bytes가 출력이 된다.
}