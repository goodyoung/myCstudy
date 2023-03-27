#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//선언
void p(int num);
void function_without_return();
int function_with_return();
void function_without_params();
void function_with_params(int num1, int num2, int num3);
int apple(int num1, int num2);
int add(int num, int num2);

int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);
void success(void);
void fail(void);
int result(int num1, int num2, int answer);
int main(void){
    /*//function 정의
    int num =2;
    printf("num은 %d 입니다\n", num);
    //2 +3은?
    // num = num +3;
    // num += 3;
    // p(num);
    //함수 종류
    //반환값이 없는 함수
    // function_without_return();
    //반환값이 있는 함수
    int ret = function_with_return();
    p(ret);
    //파라미터(전달값)이 없는 함수
    function_without_params();
    //파라미터(전달값)이 있는 함수
    function_with_params(1,2,3);
    //반환값과 전달값이 있는 함수
    int ret2 = apple(5,2);
    printf("남은 수는 %d개 이다.\n", ret2);*/
    /*// 계산기 빼기 곱하기 나누기도 같은 방식~
    int num = 2;
    num = add(num, 3);
    // p(num);*/

    //비밀번호 마스터-프로젝트
    //문이 5개가 있고 각 문마다 점점 어려운 수식 퀴즈가 출제 (랜덤)
    //맞히면 통과, 틀리면 실패
    srand(time(NULL));
    int count = 0;
    for (int i = 1; i <= 5; i++)
    {
        int num1 = getRandomNumber(i);
        int num2 = getRandomNumber(i);
        showQuestion(i, num1, num2);

        int answer = -1;
        scanf("%d", &answer);
        int a = result(num1, num2, answer);
        if (a ==1){
            count++;
        }
    }
    printf("\n\n 당신은 5개의 비밀번호 중 %d 개를 맞혔습니다\n", count);
    return 0;
}

//정의
void p(int num){
    printf("num은 %d 입니다\n",num);
}
/*//function: 반환형(char/int/void_아무것도 없다/float/double) 함수이름(전달값_여러개 가능){}
void function_without_return(){
    printf("반환 값이 없는 함수입니다.");
}
int function_with_return(){
    printf("반환 값이 있는 함수입니다.\n");
    return 10;
}
void function_without_params(){
    printf("전달값이 없는 함수입니다.\n");
}
void function_with_params(int num1, int num2, int num3){
    printf("전달값이 있는 함수입니다. %d %d %d\n", num1, num2 ,num3);
}
int apple(int num1, int num2){
    return num1 - num2;
}*/
int add(int num, int num2){
    return num + num2;
}


int getRandomNumber(int level)
{
    return rand() % (level * 7) + 1;
}
void showQuestion(int level, int num1, int num2)
{
    printf("\n\n\n########## %d 번째 비밀번호 ########\n", level);
    printf("\n\t%d x %d 는?\n\n", num1, num2);
    printf("##################################\n");
    printf("\n비밀번호를 입력하세요 (종료 : -1) >> ");
}
void success(void)
{
    printf("\n >> Good ! 정답입니다 \n");
}
void fail(void)
{
    printf("\n >> 땡 ! 틀렸습니다 \n");
}
int result(int num1, int num2, int answer){
        if (answer == -1)
        {
            printf("프로그램을 종료합니다\n");
            exit(0);
        }
        else if (answer == num1 * num2)
        {
            success();
            return 1;
        }
        else
        {
            fail();
            return 0;
        }
}