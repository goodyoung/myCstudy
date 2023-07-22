#include <stdio.h>

//함수 포인터
// int test(int a ){
//     printf("test(): Hello World");
//     return 0;
// }
// int main(void){
//     // test(5);
//     int (*pfTest)(int) = test; 
//     pfTest(5);
//     return 0;
// }

// c언어 재귀호출
// 함수 내부에서 자신을 스스로 호출하는 구조
// 논리 구조는 반복문과 같다. --> 대신 반복을 끝내기 위한 조건이 필요. 그 조건을 신중히 생각해야 한다.
// call stack을 활용하기 위해 사용한다. 쌓여 올라간다.
//stack: 1MB인데 재귀호출 양이 상당하면 그것 또한 모른다.
// 디버그 모드로 따라가면서 stack이 쌓이는 것을 확인하고 본다,

// int test(int a ){

//     // for (a=5 ; 조건 ; a-1)
//     if ( a<= 0){
//         return 0;
//     }
//     printf("test(): %d\n",a);
//     return test(a-1);
// }
// int main(void){
//     int num;
//     num = 5;
//     test(num);
//     return 0;
// }


//single linked list (선형)
//연결  리스트는(컨테이너) 여러 구조체 인스턴스를 체인처럼 줄줄이 포인터로 연결한 자료구조이다.
// 연결에 사용된 포인터 숫자가 한 개이고 자기 다음을 가리키는 것이 특징이다.


//연결 리스트(자료 구조: 데이터를 관리하기 위한 체계) 요령
// 구조체 배열로 테스트 한다.
// 연결 순서를 임의로 변경 해본다 (debugger)
// 리스트 출력은 별도 함수로 분리한다. (추적을 용이하게 하려고)
// 디버거로 노드 하나씩 따라가며 메모리 위치를 확인한다.

typedef struct NODE {
    //관리될 데이터
    int nData; 
    //데이터 관리를 위한 포인터
    struct NODE* next; //노드 구조체를 가리키는 포인터
} NODE;
int main(void){
    //연결 리스트 완성
    NODE list[5]={0};
    // 값을 넣기 초기화
    list[0].nData = 100;
    list[1].nData = 200;
    list[2].nData = 300;
    list[3].nData = 400;
    list[4].nData = 500;

    //구조체 리스트 생성 후 연결 연결
    //연결 리스트 구조화.
    list[0].next = &list[1];
    list[1].next = &list[2];
    list[2].next = &list[3];
    list[3].next = &list[4];
    list[4].next = NULL;
    
    for (int i = 0 ; i < 5; i++){
        printf("list[%d]: %d\n",i,list[i].nData);
    }
    
    //포인터
    NODE * pTmp = &list[0];

    while (pTmp != NULL){
        printf("%p: %d\n",pTmp,pTmp -> nData);
        //오버라이드
        pTmp = pTmp->next; //여기를 힘들어 한다. 
        //pTmp 값(주소) -> '->' -> 그 값(주소)의 next의 주소 값 -> pTmp에 그 값 할당
    }


    return 0;
}