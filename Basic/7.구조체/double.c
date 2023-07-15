#include <stdio.h>
//구조체 선언
struct GameInfo{
    char * name;
    int year;
    int price;
    char * company;

    struct GameInfo * friendGame; //연관 업체 게임
};
// typedef (자료형) --> 여기선 struct ~ 을 GAME_INFO로 치환하겠다.
// GameInformation 을 삭제해도 된다.
// 대신 stuct ~~이름 이 아닌 typedef로 선언한 변수로 선언해야 한다.
typedef struct GameInformation{
    char * name;
    int year;
    int price;
    char * company;

    struct GameInfo * friendGame; //연관 업체 게임
} GAME_INFO;

int main(void){
    // //[게임 출시]
    // // 이름: 나도 게임
    // // 발매년도: 2017
    // // 가격 50원
    // // 제작사: 나도회사
    // char * name = "나도게임";
    // int year = 2017;
    // int price = 50;
    // char * company = "나도회사";
    // //[또 게임 출시]
    // // 이름: 나도 게임2
    // // 발매년도: 2017
    // // 가격 100원
    // // 제작사: 너도회사
    // char * name2 = "나도게임";
    // int year2 = 2017;
    // int price2 = 100;
    // char * company2 = "너도회사";
    //이럴 때 구조체가 필요하다.

    //구조체 사용
    // 자료형           변수명
    struct GameInfo gameInfo1;
    gameInfo1.name = "나도게임";
    gameInfo1.year = 2017;
    gameInfo1.price = 50;
    gameInfo1.company = "나도회사";

    //구조체 출력
    printf("게임 명: %s\n",gameInfo1.name);
    printf("발매년도: %d\n",gameInfo1.year);
    printf("가격: %d\n",gameInfo1.price);
    printf("제작사: %s\n",gameInfo1.company);

    // 구조체 배열처럼 초기화
    struct GameInfo gameInfo2 = {"너도게임",2017,100,"너도회사"};
    printf("게임 명: %s\n",gameInfo2.name);
    printf("발매년도: %d\n",gameInfo2.year);
    printf("가격: %d\n",gameInfo2.price);
    printf("제작사: %s\n",gameInfo2.company);

    //구조체 배열 --> 똑같다.
    struct GameInfo gameArray[2]={
        {"나도게임",2017,50,"나도회사"},
        {"너도게임",2017,100,"너도회사"}
    };
    //구조체 포인터
    struct GameInfo * gamePtr;
    gamePtr = &gameInfo1;
    printf("구조체 포인터\n");
    // printf("게임 명: %s\n",(*gamePtr).name); // 괄호 유의
    // printf("발매년도: %d\n",(*gamePtr).year);
    // printf("가격: %d\n",(*gamePtr).price);
    // printf("제작사: %s\n",(*gamePtr).company);

    // 구조체 포인터에서는 .이 아닌 화살표를 사용한다.

    printf("게임 명: %s\n",gamePtr->name); 
    printf("발매년도: %d\n",gamePtr->year);
    printf("가격: %d\n",gamePtr->price);
    printf("제작사: %s\n",gamePtr->company);

    // 구조체 안의 구조체
    // 아까 포인터 였음
    
    gameInfo1.friendGame = &gameInfo2;
    printf("구조체 안의 구조체\n");
    printf("게임 명: %s\n",gameInfo1.friendGame->name); 
    printf("발매년도: %d\n",gameInfo1.friendGame->year);
    printf("가격: %d\n",gameInfo1.friendGame->price);
    printf("제작사: %s\n",gameInfo1.friendGame->company);

    // typedef
    //자료형에 별명 지정
    int i = 1;
    typedef int 정수;
    정수 k = 3;
    printf("%d",k);

    typedef struct GameInfo 게임정보;
    게임정보 game1;
    game1.name = "한글 게임";
    game1.year = 2017;

    GAME_INFO game2;
    game2.name = "한글 게임2";
    game2.year = 2017;

    struct GameInformation game3;
    game3.name = "한글 게임3";
    game3.year = 2017;
    return 0;
}