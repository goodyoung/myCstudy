#include <stdio.h>
int main(void){
    //뿔뿔
    /* // 뿔뿔 ++ => a = a+1
    // ++변수 연산 수행 후 변수 실행
    // 변수++ 변수 실행 후 다음 줄 넘어갈 때 ++연산 수행
    int b = 10;
    printf("b는 %d\n", b++);
    //10이 찍힌다
    printf("b는 %d\n", ++b);
    //12가 찍힌다 */

    //반복문 for/ while / do while
    /* //for (선언; 조건; 증감) {}
    for (int i = 1; i <= 10; i++){
        printf("현재 i는 %d 입니다.\n",i);
    } */

    /* //while (조건){}
    int i = 1;
    while (i<=10){
        printf("Hello World %d\n", i++);
    } */
    /* // do {} while (조건);
    int i=1;
    do {
        printf("Hello World %d\n", i++);
    } while (i <= 10); */

    /* // 2중 반복문 구구단
    for (int i = 2; i <10; i++){
        printf("%d단 계산 결과 입니다.\n",i);
        for (int j = 1; j < 10; j++){
            printf("%2d X%2d = %2d\n",i,j,i*j);
        }
        printf("-----------\n");
    } */

    // 별찍기 (기본)
    /* for (int i = 1; i <= 5; i++){
        for (int j = 1; j <=i; j++){
            printf("*");
        }
        printf("\n");
    }
    // 별찍기 (반대)
    for (int i = 1; i <= 5; i++){
        for (int k = 5-i ; k > 0; k--){
            printf(" ");
        }
        for (int j = 1; j<=i; j++){
            printf("*");
        }
        printf("\n");
    } */
    // 피라미드를 쌓아라 - 프로젝트
    int floor;
    printf("몇 층으로 쌓겠느냐?");
    scanf("%d",&floor);
    // 1 3 5 7 2n-1
    int i = 5;
//공백은 그 층 나누기 2
    for (int i =1 ; i <= floor; i++){
        // for (int j = floor - i ; j > 0; j--){
        //     printf(" ");
        // }
        for (int j = i; j <= (floor - 1); j++){
            printf(" ");
        }

        for (int k = 1; k <= (2*i -1); k++){
            printf("*");
        }
        printf("\n");
    }


    return 0;
    
}