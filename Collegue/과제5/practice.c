#include <stdio.h>

//case 1 
// #include <stdlib.h>
// #include <unistd.h>
// int main(void){
//     int count;
//     printf("카운터의 초기값을 입력하시오(단위 : 초) : ");
//     scanf("%d",&count);
//     for(int i =count ; i > 0  ; i--){
//         printf("%d ",i);
//         sleep(1);
//     }
//     printf("\a");
//     return 0;
// }

//case 2

// int main(void){
//     int sum = 0;
//     for (int i = 0 ; i < 100; i++){
//         if (i % 3 == 0){
//                 sum += i;
//         }
//     }
//     printf("1부터 100사이의 모든 3의 배수의 합은 %d입니다.",sum);
//     return 0;
// }

//case 3
// int main(void){
//     int result = 0;
//     int num;
//     for (int i = 0 ; i < 3 ; i++){
//         printf("숫자를 입력하시오:");
//         scanf("%d",&num);
//         while (num < 0){
//             printf("숫자를 입력하시오:");
//             scanf("%d",&num);
//         }
//         result +=num;
//     }
//     printf("합계는 %d입니다.\n", result);
//     return 0;
// }
//case 4
// int main(void){
//     int num;
//     printf("정수를 입력하시오 :");
//     scanf("%d",&num);
//     printf("약수 : ");
//     for (int i = 1 ; i <= num; i++){
//         if (num % i == 0)
//             printf("%d ",i);
//     }
//     return 0;
// }

//case 5
// int main(void){
//     int r, n;
//     int result = 1;
//     printf("실수를 입력하시오 : ");
//     scanf("%d",&r);
//     printf("거듭제곱의 횟수를 입력하시오 :");
//     scanf("%d",&n);
//     for(int i = 0 ; i < n; i++){
//         result *= r;
//     }
//     printf("결과값은 %d",result);
//     return 0;
// }

//case 6
// int main(void){
//     int n;
//     int result = 0;
//     printf("n의 값을 입력하시오 : ");
//     scanf("%d",&n);
//     for (int i = 1 ; i <= n ; i++){
//         result += i*i;
//     }
//     printf("계산값은 %d입니다.",result);
//     return 0;
// }
//case 7
// int main(void){
//     char s = '*';
//     int te;
//     for (int i =1 ; i < 8 ; i++){
//         te = 8 - i;
//         for ( int j = 1 ; j < te; j ++){
//             printf(" ");
//         }
//         for (int k = 0 ; k < i; k++){
//             printf("%c",s);
//         }
//         printf("\n");
//     }
//     return 0;
// }

//case 8
// int main(void){
//     int num;
//     printf("정수를 입력하시오 :");
//     scanf("%d",&num);
//     for (int i = 0 ; i < num; i++){
//         for ( int k = 1 ; k <= i+1 ; k++){
//             printf("%d ",k);
//         }
//         printf("\n");
//     }
//     return 0 ;
// }

//case 9
// #include <stdbool.h>
// int main(void){
//     bool re = true;
//     int end = 100;
//     printf("실행결과: ");
//     for (int start = 2; start <= end; start++){

//         for(int k = 2; k < start; k++){
//             if (start % k == 0){
//                 re = false;
//             } 
//         }
//         if (re){
//             printf("%d ",start);
//         }
//         re = true;
//     }
//     return 0;
// }

//case 10
// int main(void){
//     int num;
//     while (1){
//         printf("막대의 높이(종료 : -1) : ");
//         scanf("%d",&num);
//         if (num == -1)
//             break;
//         for (int i = 0 ; i < num ; i++){
//             printf("*");
//         }
//         printf("\n");
//     }
//     return 0;
// }

//case 11
// int main(void){
//     int sum = 0 ;
//     int i = 1;
//     while(1){
//         if (sum > 10000){
//             --i;
//             sum -= i;
//             break;
//         }
//         sum += i;
//         ++i;
//     }
//     printf("1부터 %d까지의 합이 %d입니다.",i-1,sum);
//     return 0;
// }

//case 12
// int main(void){
//     int a= 0 ,b = 1 ,c;
//     int n;
//     printf("몇 번째 항까지 구할까요? ");
//     scanf("%d",&n);
//     printf("%d, ",a);
//     printf("%d, ",b);
//     for (int i = 0 ; i < n-1; i++){
//         c = a+b;
//         a = b;
//         b = c;
//         printf("%d, ",c);
//     }
//     return 0;
// }

// int main(void){
//     // printf("%x\n",0x20 << 2);
//     int i = 0x10;
//     for (; i; i >> 1){
//         printf("%d\n",i);
//     }
//     return 0;
// }