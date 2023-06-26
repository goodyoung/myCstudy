#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//물고기 6마리

//물고기는 시간이 지날수록 점점 커져서 나중에는 냠냠
int level;
int arrayFish[6];
int * cursor; //1번 물고기한테 물을 줄지, 누구한테 물을 줄지?

void initData();
void printfFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();
int main(void){
    long startTime = 0; //게임 시작 시간
    long totalElapsedTime = 0;// 총 경과 시간
    long prevElapsedTime = 0; // 직전 경과 시간? (최근에 물을 준 시간 간격)

    int num; //몇 번 어항에 물을 줄 것인지. 사용자 입력
    initData();
    cursor = arrayFish; // cursor[0],[1] 이처럼 똑같이 사용 가능하다.
    startTime = clock();

    while (1)
    {
        printfFishes();
        // getchar(); //임시로 사용자 입력 대기
        printf("몇 번 어항에 물을 주시겠어요?");
        scanf("%d", &num);

        //입력값 체크
        if (num < 1 | num > 6){
            printf("입력값이 잘못되었습니다.\n");
            continue;
        }
        // printf("%ld",(double)(clock()-startTime) / CLOCKS_PER_SEC);
        double test = (clock()-startTime);
        totalElapsedTime = (double)(clock()-startTime) / CLOCKS_PER_SEC; //현시각 - 시작 시간 -> 경과시간 // clocks->초 단위로 바꿔줌
        printf("dasasdasd %ld",totalElapsedTime);
        printf("총 경과시간 : %ld 초\n",totalElapsedTime);
        //직전에 물 준 시간 (마지막으로 물 준 시간) 이후로 흐른 시간
        prevElapsedTime = totalElapsedTime - prevElapsedTime;
        printf("최근 경과 시간: %ld 초\n", prevElapsedTime);

        //어항의 물을 감소 [증발]
        decreaseWater(prevElapsedTime);
        // 사용자가 입력한 어항에 물을 준다.
        // 1. 어항의 물이 0이면? 물을 주지 않는다... 이미 물고기가 ,, 죽음
        if (cursor[num-1] <= 0 ){
            printf("%d번 물고기는 이미 죽었습니다.. 물을 주지 않습니다.\n",num);
        }
        // 2. 어항의 물이 0이 아닌 경우? 물을 준다. 100을 넘지 않는지 체크
        else if (cursor[num-1] + 1 <= 100){
            //물을 준다.
            printf("%dqjs djgkddp anfdmf wnqslek.\n\n",num);
            cursor[num-1] += 1;
        }
        //레벨업을 할 건지 확인 (레벨업은 20초마다 한번씩 수행)

        if (totalElapsedTime / 20 > level -1){
            level ++;
            printf(" *** 축 레벨업! 기존 &d 레벨에서 %d 레벨로 업그레이드 ***\n\n",level-1,level);
            // 최종 레벨 :5
            if (level == 5){

                printf("\n\n축하합니다. 최고 레벨을 달성하였습니다. 게임을 종료합니다.");
                exit(0);
            }
        }
        // 모든 물고기가 죽었는지 확인
        if (checkFishAlive() == 0){
            //물고기 모두 죽음..
            printf("모든 물고기가 죽었다..\n");
            exit(0);
        } else{
            //최소 한마리 물고기는 살아있다.
            printf("물고기가 아직 살아 있어요!\n");
        }
        prevElapsedTime = totalElapsedTime;




    }
    return 0;
}

void initData(){
    level = 1;
    for (int i=0; i<6;i++){

        arrayFish[i] = 100;
    }
}
void printfFishes(){
    printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n",1,2,3,4,5,6);
    for(int i =0; i< 6; i++){
        printf(" %4d ", arrayFish[i]); //간격이 같다.
    }
    printf("\n\n");
}
//어항 물 감소
void decreaseWater(long elapsedTime){
    for(int i = 0 ; i < 6; i++){
        arrayFish[i] -= (level * 3 * (int)elapsedTime); // 3: 난이도 조절을 위한 값
        if (arrayFish[i] < 0){
            arrayFish[i] = 0;
        }
    }

}
int checkFishAlive(){
    for(int i=0; i <6 ; i++){
        if (arrayFish[i] > 0){
            return 1;
        }
    }
    return 0;
}