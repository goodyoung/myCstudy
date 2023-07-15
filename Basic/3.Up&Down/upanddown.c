#include <stdio.h>
//random을 위한 모듈?
#include <time.h>
#include <stdlib.h>
int main(void){
    /*//if (조건) { ... } else { ... }
    //printf만 있을 때에는 {}가 필요 없다.
    int age = 15;
    if (age >= 20){
        printf("일반인 입니다.");
    }
    else{
        printf("학생입니다.");
    }*/

    // if / else if / else
    // && --> and의 느낌
    /* int age = 15;
    if (age >= 8 && age <= 13){
        printf("초등학생입니다.\n");

    } else if (age >= 14 && age <= 16){
        printf("중학생입니다.\n");
    } else {
        printf("고등학생입니다.");
    } */
    // break / continue
    // 1번부터 30번까지 있는 반에서 1번에서 5번까지 조별 발표를 합니다.
    /*for (int i = 1; i<= 30; i++){
        if (i <= 5){
        printf("%d번 학생은 조별 발표를 준비 하세요\n",i);
        } else{
            printf("쉬고 계세요");
            break;
        }
    } */
    // 1번부터 30번까지 있는 반에서 7번 학생은 아파서 결석 , 7번을 제외하고 6번부터 10번까지
    /*for (int i = 1; i<= 30; i++)
    {
    if (i>= 6 && i <= 10){
        if (i == 7)
        {
        printf("%d번 학생은 아파서 결석입니다.\n",i);
        continue;
        }
        printf("%d번 학생은 발표입니다.\n", i );
    }
    }*/
    //and or
    //&& ||
    /* int a = 10;
    int b = 11;
    int c = 12;
    int d = 12;
    if (a==b || c==d){
        printf("출력합니다.");
    } else{
        printf("값이 서로 다르다.");
    } */
    /* //random
    // 난수 초기화를 안하면 계속 그 seed를 갖는다.
    // python에서 seed가 고정된 상태라고 생각하면 쉽다.
    // rand() % 어떤 수(범위) 0부터 시작한다.
    srand(time(NULL)); //난수 초기화
    int num = rand() % 3; // 0,1,2*/

    /*//switch case
    // 조건에 부합하는 case 문 실행 후 뒤에있는 case문들을 다 실행한다.
    // 탈출을 하도록 break문을 작성하자.
    // case는 한가지 조건만 실행된다.
    //가위0 바위1 보2
    srand(time(NULL));
    int i = rand() % 3; // 0~2 반환
    //switch (값) { case:(값1);break; case:(값2);break; }
    switch (i){
        case 0:printf("가위\n"); break;
        case 1:printf("바위\n"); break;
        case 2:printf("보\n"); break;
        default:printf("몰라요\n"); break;
    }

    // swich 이렇게도 사용이 가능하다. 밑에게 다 실행이 되고 그 지점까지 break가 걸리니까
    int age = 15;
    switch (age){
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:printf("초등학생입니다.\n"); break;
        case 14:
        case 15:
        case 16:printf("중학생입니다.\n");break;
        case 17:
        case 18:
        case 19:printf("고등학생입니다.\n");break;
        default: printf("학생이 아닌가봐요\n");break;
    }*/
    //Up&Down - 프로젝트
    srand(time(NULL));
    int num = rand() % 100 + 1;
    int answer;
    int chance = 5;
    printf("%d",num);
    while (1){
    printf("기회는 %d번 남았습니다.\n",chance--);
    printf("맞추고 싶은 숫자를 입력하세요:");
    scanf("%d", &answer);
    if (answer == num){
        printf("%d 정답입니다.\n", num);
        break;
    } else if (num > answer){
        printf("Up\n");
    } else if (num < answer){
        printf("Down\n");
    } else {
        printf("알 수 없는 오류가 발생했어요\n");
    }
    if (chance == 0){
        printf("모든 기회를 다 사용하셨다.");
        break;
    }
    }



    return 0;
}