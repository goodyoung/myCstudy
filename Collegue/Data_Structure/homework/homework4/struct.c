#include <stdio.h> // 표준입출력 라이브러리 사용하기 위한 라이브러리 불러오기
struct student1 { // student1 구조체 선언
    char lastName; // char (1 bytes) lastName 선언
    int studentId; // 정수형 (4 bytes) studentId 선언
    char grade; // char (1 bytes) grade 선언
};


typedef struct { // student2 구조체 선언
    char lastName; // char (1 bytes) lastName 선언
    int studentId; // 정수형 (4 bytes) studentId 선언
    char grade; // char (1 bytes) grade 선언
} student2;

int main() {
    printf("[----- [Goh Geon Young]  [2020017027] -----]\n");
    struct student1 st1 = {'A', 100, 'A'}; // 구조체 변수 st1를 초기화하고 그 안의 멤버를 정의한다.
    printf("st1.lastName = %c\n", st1.lastName); // 구조체 변수 st1에 저장된 lastName멤버의 값을 출력한다.
    printf("st1.studentId = %d\n", st1.studentId); // 구조체 변수 st1에 저장된 studentId 멤버의 값을 출력한다.
    printf("st1.grade = %c\n", st1.grade); // 구조체 변수 st1에 저장된 grade 멤버의 값을 출력한다.

    student2 st2 = {'B', 200, 'B'}; // 구조체 변수 st2를 초기화하고 그 안의 멤버를 정의한다.
    printf("\nst2.lastName = %c\n", st2.lastName); // 구조체 변수 st2에 저장된 lastName멤버의 값을 출력한다.
    printf("st2.studentId = %d\n", st2.studentId); // 구조체 변수 st2에 저장된 studentId 멤버의 값을 출력한다.
    printf("st2.grade = %c\n", st2.grade); // 구조체 변수 st2에 저장된 grade 멤버의 값을 출력한다.
    
    student2 st3; // 구조체 변수 st3를 선언
    st3 = st2; // 구조체 변수 st2를 st3에 대입
    printf("\nst3.lastName = %c\n", st3.lastName); // 구조체 변수 st3에 저장된 lastName멤버의 값을 출력한다.
    printf("st3.studentId = %d\n", st3.studentId); // 구조체 변수 st3에 저장된 studentId멤버의 값을 출력한다.
    printf("st3.grade = %c\n", st3.grade); // 구조체 변수 st3에 저장된 grade 멤버의 값을 출력한다.
    
    /* equality test */
    // st2와 st3의 각각의 멤버 변수들이 다 일치하는지 확인하는 작업 -> 구조체 st2와 st3가 완전히 같은지 확인
    if (st3.lastName == st2.lastName &&
    st3.studentId == st2.studentId &&
    st3.grade == st2.grade) {
        printf("equal\n"); // 만약 다 같으면 equal 표시
    }
    else 
        printf("not equal\n"); // 만약 하나라도 같지 않으면 not equal 표시

    return 0; // 0 반환 및 프로그램 종료
}