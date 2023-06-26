#include <stdio.h>

/*int main(void){
    int 철수 = 1; //메모리 공간의 철수라는 변수가 존재하는 위치가 있다.
    int 영희 = 2;
    int 민수 = 3;
    printf("철수네 주소 : %d, 암호: %d\n", &철수, 철수);  // 주소를 나타내기 위해서 &표시가 있어야 한다.
    printf("철수네 주소 : %d, 암호: %d\n", &영희, 영희);
    printf("철수네 주소 : %d, 암호: %d\n", &민수, 민수);

    //미션맨

    // 첫 번째 미션 아파트의 각 집에 방문하여 문에 적힌 암호 확인.
    int *미션맨; // 포인터 변수
    미션맨 = &철수; // 지금 철수의 주소를 가진다.
    printf("미션맨이 방문하는 곳 주소 : %d, 암호: %d\n", 미션맨, *미션맨); // 주소값을 통해서 값을 알 수 있게 된다.
    미션맨 = &영희; // 지금은 영희의 주소
    printf("미션맨이 방문하는 곳 주소 : %d, 암호: %d\n", 미션맨, *미션맨);


    // 두 번째 미션: 각 암호에 3을 곱해라
    미션맨 = &철수;
    *미션맨 *= 5;
    printf("미션맨이 암호를 바꾼 곳 주소 %d, 암호: %d\n", 미션맨, *미션맨); // 메모리 값은 같다.
    // 포인터 변수는 주소값, 그 주소값에 해당하는 값을 변경도 할 수 있게 된다.

    
    //세 번째 미션? : 스파이
    // 미션맨이 바꾼 암호에서 2를 빼라!

    // 스파이(124124124)
    //             ==> (124124124) 누군가의 아파트 주소 // 두 개의 포인터 변수가 하나의 메모리 주소를 가리킬 수 있다.
    // 미션맨(124124124) 

    int *스파이 = 미션맨;
    printf("\n ... 스파이가 미션 수행하는 중 ... \n\n");
    스파이 = &철수;
    *스파이 -= 3; // 철수 = 철수 -2
    printf("스파이가 방문하는 곳 주소 : %d, 암호: %d\n",스파이, *스파이);
    printf("\n.... 철수 영희 민수는 집에 오고서는 바뀐 암호를 보고 깜놀! ...\n\n");

    // 포인터 변수는 받은 주소 값을 가지는 변수 자체가 원래의 변수에 직접 바꿀 수 있다!
    printf("철수네 주소 : %d, 암호: %d\n", &철수, 철수);  
    printf("철수네 주소 : %d, 암호: %d\n", &영희, 영희);
    printf("철수네 주소 : %d, 암호: %d\n", &민수, 민수);
    //
    printf("미션맨의 주소 %d\n", &미션맨);

    //포인터 변수는 변수의 주소를 받고 그 주소를 컨트롤 할 수 있게 하는 것.. 같다.

    
    return 0;
}*/

// 배열과 포인터의 관계
// int main(void){
//     int arr[3] = {5, 10, 15};
//     int *ptr = arr; // arr이라는 자체의 주소값을 가진다.

//     for (int i=0; i < 3; i++){

//         printf("배열 arr[%d] 의 값: %d\n", i , arr[i]);
//     }
//     for (int i=0; i < 3; i++){

//     printf("포인터 ptr[%d] 의 값: %d\n", i , ptr[i]);
//     }
//     //배열의 값도 바뀜. ptr과 arr은 아에 똑같은 녀석이다.
//     ptr[0] = 100;
//     ptr[1] = 200;
//     ptr[2] = 300;
//     for (int i=0; i < 3; i++){

//         //printf("배열 arr[%d] 의 값: %d\n", i , arr[i]);
//         printf("배열 arr[%d] 의 값: %d\n", i , *(arr + i)); //arr의 배열이 처음 시작되는 주소값를 가지고 있다., 주소로 부터 i번째에 해당하는 값을 가져오는 것이다.
//     }
//     for (int i=0; i < 3; i++){

//     //printf("포인터 ptr[%d] 의 값: %d\n", i , ptr[i]);
//     printf("포인터 ptr[%d] 의 값: %d\n", i , *(ptr+i));
//     }
//     printf("포인터 %d\n", ptr);
//     printf("포인터 %d\n", *(ptr));
//     // *(arr + i) == arr[i] 똑같은 표현
//     // arr == arr 배열의 첫번째 값의 주소와 동일 == &arr[0]
//     printf("arr 자체의 값: %d\n",arr);
//     printf("arr[0]의 주소 %d\n",&arr[0]);

//     printf("arr 자체의 값이 가지는 주소의 실제 값: %d\n",*(arr)); // *(arr + 0) 이랑 표현이 똑같다.
//     printf("arr[0]의 실제 값: %d\n",*&arr[0]);
//     // *& 는 아무것도 없는 것과 같다!!!!! 계속 써도 똑같다.(*&*&*&*&*&) 서로 상쇄가 된다.

//     return 0;
// }

//swap
// void swap(int a, int b);
// void swap_addr(int * a, int * b);

// int main(void){
//     //SWAP
//     int a = 10;
//     int b = 20;
//     printf("a의 주소 : %d\n",&a);
//     printf("b의 주소 : %d\n",&b);
//     //a와 b의 값을 바꾼다.
//     printf("Swap 함수 전 , a: %d b: %d\n",a,b);
//     swap(a,b); // a와 b의 자체를 준게 아니라 값만 던저준다.
//     printf("Swap 함수 후 , a: %d b: %d\n",a,b);

//     //값에 의한 복사 (Call by Value) -> 값만 복사한다는 의미
//     // 주소값을 넘기면? 메모리 공간안에 있는 주소값 자체를 넘기면

//     printf("(주소값 전달) Swap 함수 전 , a: %d b: %d\n",a,b);
//     swap_addr(&a,&b); // a와 b의 자체를 준게 아니라 값만 던저준다.
//     printf("(주소값 전달) Swap 함수 후 , a: %d b: %d\n",a,b);
//     return 0;
// }
// void swap(int a, int b){
//     printf("swap함수 내 a의 주소 : %d\n",&a);
//     printf("swap함수 내 b의 주소 : %d\n",&b);

//     int temp = a;
//     a = b;
//     b = temp;
//     printf("Swap 함수 내 , a: %d b: %d\n",a,b);
// }
// void swap_addr(int * a, int * b){
//     printf("(주소값의) swap함수 내 a의 주소 : %d\n",a);
//     int temp = *a;
//     *a = *b;
//     *b = temp;
//     printf("Swap 함수 내 , a: %d b: %d\n",*a,*b);
// }

//포인터로 배열 값 변경하기
//배ㅕㄹ일 때, arr2 -> 주소 자체
// void changeArray(int *ptr);
// int main(void){
//     int arr2[3] = {10, 20 ,30};
//     // changeArray(arr2);
//     changeArray(&arr2[0]);
//     for(int i=0; i<3; i++){
//         printf("%d\n",arr2[i]);
//     }
//     return 0;   
// }
// void changeArray(int *ptr){
//     ptr[2] = 50;
// }