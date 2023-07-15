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
int test(int a ){

    // for (a=5 ; 조건 ; a-1)
    if ( a<= 0){
        return 0;
    }
    printf("test(): %d\n",a);
    return test(a-1);
}
int main(void){
    int num;
    num = 5;
    test(num);
    return 0;
}
