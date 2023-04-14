#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void){
    //배열 선언
    int subway_array[3];
    subway_array[0] = 30;
    subway_array[1] = 40;
    subway_array[2] = 50;

    // 값 설정 방법
    // 값은 초기화를 반드시 해야함
    // 배열 크기는 항상 상수로 선언 arr[(항상 숫자로 쓰기)]
    // 배열에 하나라도 선언 하고 그 외의 값은 0으로 들어간다.

    // int arr[] = {1,2}; // arr[2]
    // float arr_f[5] = {1.0f,2.0f,3.0f};

    /*int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    for (int i = 0 ; i< 10; i++){
        printf("%d\n",arr[i]);
    }*/

    //문자 vs 문자열

    // char c = 'A';
    // printf("%c\n", c);
    // 문자열 끝에는 "끝"을 의미하는 NULL문자 '\0'이 포함되어야 함
    // 문자열 보다 하나 더 크게 문자열 배열을 생성해줘야한다.
    // char str[6] = "coding"; //  [c][o][d][i][n][g]

    // printf("%s\n", str);


    /*char str[] = "coding";
    printf("%s\n", str);
    // sizeof  %d하면 오류 나고 %lu를 사용하면 괜찮다.
    printf("%lu\n", sizeof(str)); // size가 7이 나온다.

    for (int i = 0 ; i < sizeof(str); i++){
        printf("%c\n", str[i]);
    }


    // 영어 한글자: 1byte
    // 한글 1글자: 2byte
    // 한 글집
    // En gl ish
    char kor[] = "나도코딩";
    printf("%s\n", kor);
    printf("%lu\n", sizeof(kor)); // 배열 크기가 14가 나온다. 4*2 = 8 + 1*/

    
    
    /*char c_array[10] = {'c','o','d','i','n','g'};

    printf("%s\n",c_array);

    for (int i = 0; i < sizeof(c_array); i++){
        printf("%c\n", c_array[i]);
    }
    // coding이라는 문자열은 출력되고 남는 공간이 생긴다.

    // %d로 문자열을 출력하면 ASCII코드 값이 출력된다.

    //ASCII코드
    // 7bit , 총 128개 코드 (0~127)
    printf("%c\n", 'a');
    printf("%d\n", 'a');

    //참고2: 0~127사이의 아스키코드 정수값에 해당하는 문자 확인

    for (int i = 0; i< 128; i++){
        printf("아스키코드 정수 %d : %c\n", i, i);
    }*/

    srand(time(NULL));
    printf("\n\n === 아빠는 대머리 게임 === \n\n");
    int answer;
    int treatment = rand() % 4; //발모제 선택(0~3)

    int cntShowBottle = 0; //이번 게임에 보여줄 병 개수
    int prevCntShowBottle = 0; //앞 게임에 보여준 병 개수
    // 서로 보여주는 병 개수를 다르게 하여 정답률 향상 (처음엔 2개 -> 다음엔 3개)

    // 3번의 기회 (3번의 발모제 투여 시도한다.)
    for (int i =0 ; i<3; i++){
        int bottle[4] = {0,0,0,0}; // 4개의 병

        do {
            cntShowBottle = rand() % 2 + 2;
        } while (cntShowBottle == prevCntShowBottle);
        prevCntShowBottle = cntShowBottle;
        int isIncluded = 0; // 보여줄 병 중에 발모제가 포함되어있냐 (1: 포함되어 있다.)
        printf("\n%d번째 시도 입니다.\n", i+1);

        for (int j =0; j < cntShowBottle ; j++){
            int choice = rand() % 4; // 0~3
            // 아직 선택되지 않은 병이면 선택 처리

            if (bottle[choice] ==0){
                bottle[choice] = 1;
                if (choice == treatment){
                    isIncluded = 1; // 포함되었다 선언
                }
            } // 이미 선택된 병이면 중복이므로 다시 선택하게 한다. 
            else
            {
                j--; // j값을 줄여줘서 다시 한 번 처리하게 한다.
            }
        }
        // 사용자에게 문제 표시
        for (int k = 0; k< 4; k++){
            if (bottle[k] == 1){
                printf("%d ", k+1);
            }
        }
        printf("물약을 머리에 바릅니다. \n\n");

        if (isIncluded == 1){
            printf(" >> 성공! 머리가 났어요!");
        }
        else
        {
            printf("실패 머리가 나지 않았습니다.");
        }
        printf("\n ... 계속 하려면 아무키나 누르세요 ...");
        getchar(); // 사용자가 어떤 키를 입력하면 다음을 실행하도록 하는 함수?
    }

    printf("\n\n발모제는 몇 번일까요?");
    scanf("%d", &answer);

    if (answer == treatment+1){
        printf("정답입니다.\n");
    } else{
        printf("땡 틀렸어요! 정답은 %d입니다.\n", treatment+1);
    }
    return 0;
}