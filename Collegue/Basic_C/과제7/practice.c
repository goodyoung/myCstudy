#include <stdio.h>
//case1-1
// int sum(int num1, int num2);
// int sub(int num1, int num2);
// int div(int num1, int num2);
// int mul(int num1, int num2);
// int main(void){
//     int num1, num2;
//     char ch;

//     while(1){
//         printf("두 개의 수와 연산자를 입력하시오 :(종료: 000)\n");
//         scanf("%d %c %d",&num1,&ch,&num2);
//     if (num1==0 && num2==0){
//         break;
//     } else{
//     switch (ch)
//     {
//     case '+':
//         sum(num1,num2);
//         break;
//     case '-':
//         sub(num1,num2);
//         break;
//     case '/':
//         div(num1,num2);
//         break;
//     case '*':
//         mul(num1,num2);
//         break;
//     }
//     }
//     }
//     return 0;
// }
// int sum(int num1, int num2){
//     static int count=1;
//     printf("연산 결과: %d\n",num1+num2);
//     printf("덧셈은 총 %d번 실행되었습니다.\n",count);
//     count++;
// }
// int sub(int num1, int num2){
//     static int count=1;
//     printf("연산 결과: %d\n",num1-num2);
//     printf("뺄셈은 총 %d번 실행되었습니다.\n",count);
//     count++;
// }
// int div(int num1, int num2){
//     static int count=1;
//     printf("연산 결과: %d\n",num1/num2);
//     printf("나눗셈은 총 %d번 실행되었습니다.\n",count);
//     count++;
// }
// int mul(int num1, int num2){
//     static int count=1;
//     printf("연산 결과: %d\n",num1*num2);
//     printf("곱셈은 총 %d번 실행되었습니다.\n",count);
//     count++;
// }
//case 1-2
// static int count_sum=1,count_sub=1,count_mul=1,count_div=1;
// int sum(int num1, int num2);
// int sub(int num1, int num2);
// int div(int num1, int num2);
// int mul(int num1, int num2);
// int main(void){
//     int num1, num2;
//     char ch;

//     while(1){
//         printf("두 개의 수와 연산자를 입력하시오 :(종료: 000)\n");
//         scanf("%d %c %d",&num1,&ch,&num2);
//     if (num1==0 && num2==0){
//         break;
//     } else{
//     switch (ch)
//     {
//     case '+':
//         sum(num1,num2);
//         break;
//     case '-':
//         sub(num1,num2);
//         break;
//     case '/':
//         div(num1,num2);
//         break;
//     case '*':
//         mul(num1,num2);
//         break;
//     }
//     }
//     }
//     return 0;
// }
// int sum(int num1, int num2){
//     printf("연산 결과: %d\n",num1+num2);
//     printf("덧셈은 총 %d번 실행되었습니다.\n",count_sum);
//     count_sum++;
// }
// int sub(int num1, int num2){
//     printf("연산 결과: %d\n",num1-num2);
//     printf("뺄셈은 총 %d번 실행되었습니다.\n",count_sub);
//     count_sub++;
// }
// int div(int num1, int num2){
//     printf("연산 결과: %d\n",num1/num2);
//     printf("나눗셈은 총 %d번 실행되었습니다.\n",count_div);
//     count_div++;
// }
// int mul(int num1, int num2){
//     printf("연산 결과: %d\n",num1*num2);
//     printf("곱셈은 총 %d번 실행되었습니다.\n",count_mul);
//     count_mul++;
// }
//case2
// #include <time.h>
// #include <stdlib.h>
// int get_dice_face();
// int main(void){
//     srand(time(NULL));
//     for (int i =0; i<100;i++){
//         get_dice_face();
//     }
//     return 0;
// }
// int get_dice_face(){
//     static int count = 0;
//     static int count1 = 0,count2 = 0,count3 = 0,count4 = 0,count5 = 0,count6=0;
    
//     int num;
//     num = rand() % 6 +1;
//     switch (num)
//     {
//     case 1:
//         count1++;
//         break;
//     case 2:
//         count2++;
//         break;
//     case 3:
//         count3++;
//         break;
//     case 4:
//         count4++;
//         break;
//     case 5:
//         count5++;
//         break;
//     case 6:
//         count6++;
//         break;
//     }
//     count++;
//     if (count==100){
//         printf("1 -> %d\n",count1);
//         printf("2 -> %d\n",count2);
//         printf("3 -> %d\n",count3);
//         printf("4 -> %d\n",count4);
//         printf("5 -> %d\n",count5);
//         printf("6 -> %d\n",count6);
//     }

//     return 0;
// }

//case 3
// int sum(int num);
// int main(void){
//     int num,result;
//     printf("정수를 입력하시오: ");
//     scanf("%d",&num);
//     result = sum(num);
//     printf("1부터 %d까지의 합=%d",num,result);
//     return 0;
// }
// int sum(int num){
//     if (num<=1){
//         return 1;
//     }else{
//         return num+sum(num-1);
//     }
// }

//case 4
// int check(int pass);
// int main(void){
//     int password = 1234;
//     check(password);
//     return 0;
// }
// int check(int pass){
//     static int count=0;
//     int num;
//     while(1){
//         if (count >= 3){
//             printf("로그인 시도 횟수 초과\n");
//             break;
//         }else{
//             printf("비밀번호: ");
//             scanf("%d",&num);
//             if (num == pass){
//                 printf("\n로그인에 성공하셨습니다.\n");
//                 break;
//             }
//         }
//         count++;
//     }
// }

//case 5
// #include <time.h>
// #include <stdlib.h>
// int get_random();

// int main(void){
//     for(int i =0;i<3;i++){
//         get_random();
//     }
//     return 0;
// }
// int get_random(){
//     static int inited;
//     int num;
//     if (inited==0){
//         printf("초기화를 시작합니다.\n");
//         srand(time(NULL));
//         inited++;
//     }else{
//         num = rand();
//         printf("%d\n",num);
//     }
//     return 0;
// }
//case 6
// int show_digit(int num);
// int main(void){
//     int num;
//     printf("정수를 입력하시오 :");
//     scanf("%d",&num);

//     show_digit(num);

//     return 0;
// }

// int show_digit(int num){
//     int s,b;
//     s = num/10;
//     b = num%10;
//     if (s == 0){
//         printf("%d ",num);
//         return num;
//     }else{
//         show_digit(s);
//         printf("%d ",b);
//     }
// }