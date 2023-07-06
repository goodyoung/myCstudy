#include <stdio.h>
//case 1
// int even(int n);
// int absolute(int n);
// int sign(int n);

// int main(void){
//     int n,k;
//     printf("정수를 입력하시오 :");
//     scanf("%d",&n);
//     k = even(n);
//     printf("even()의 결과 : %d\n",k);
//     k = absolute(n);
//     printf("absolute()의 결과 : %d\n",k);
//     k = sign(n);
//     printf("sign()의 결과 : %d\n",k);
//     return 0;
// }
// int even(int n){
//     if (n % 2 == 0){
//         return 1;
//     } else{
//         return 0;
//     }
// }
// int absolute(int n){
//     if (n >= 0){
//         return n;
//     }else{
//         return -n;
//     }
// }
// int sign(int n){
//     if (n < 0){
//         return -1;
//     }else if (n==0){
//         return 0;
//     }else{
//         return 1;
//     }
// }

//case2
// int is_multiple(int n, int m);
// int main(void){
//     int m,n,k;
//     printf("첫 번째 정수를 입력하시오 : ");
//     scanf("%d",&m);
//     printf("두 번째 정수를 입력하시오 : ");
//     scanf("%d",&n);
//     k = is_multiple(m,n);
//     if (k==0){
//         printf("%d은 %d의 배수가 아닙니다.\n",n,m);
//     }else{
//         printf("%d은 %d의 배수가 입니다.\n",n,m);
//     }
//     return 0;
// }
// int is_multiple(int n, int m){
//     if (n%m==0){
//         return 1;
//     }else{
//         return 0;
//     }
// }

//case 3
// double get_bigger(double a, double b);
// int main(void){
//     double a,b,result;
//     printf("두 개의 실수를 입력하시오 :");
//     scanf("%lf %lf",&a,&b);
//     result = get_bigger(a,b);
//     printf("큰 수는 %.2lf입니다.",result);
//     return 0;
// }
// double get_bigger(double a, double b){
//     if (a>b){
//         return a;
//     }else{
//         return b;
//     }
// }

//case 4
// char check_alpha(char ch);
// int main(void){
//     char ch;
//     printf("문자를 입력하시오 :");
//     scanf("%c",&ch);
//     check_alpha(ch);
//     return 0;
// }
// char check_alpha(char ch){
//     if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
//         printf("%c는 알파벳문자입니다.\n",ch);
//     }else{
//         printf("%c는 알파벳문자가 아닙니다.\n",ch);
//     }
//     return 0;
// }

//case 5
// double  f_to_c(double f);
// int main(void){
//     double temp,result;
//     printf("화씨 온도를 입력하시오 :");
//     scanf("%lf",&temp);
//     result = f_to_c(temp);
//     printf("화씨온도 %lf도는 섭씨온도로 %lf도입니다.",temp,result);
//     return 0;
// }
// double f_to_c(double f){
//     double c;
//     c = 5.0/9.0*(f-32.0);
//     return c;
//  }

//case 6
// double cal_area(double radius);

// int main(void){
//     double r,width;
//     printf("원의 반지름을 입력하시오 : ");
//     scanf("%lf",&r);
//     width = cal_area(r);
//     printf("원의 면적은 %lf입니다.",width);
//     return 0;
// }
// double cal_area(double radius){
//     return 3.14*radius*radius;
// }
//case 7

// int is_leap(int year);
// int main(void){
//     int year;
//     printf("연도를 입력하시오 :");
//     scanf("%d",&year);
//     is_leap(year);
//     return 0;
// }
// int is_leap(int year){
//     if ((year%4 ==0 && year%100 !=0) || (year%400==0)){
//         printf("윤년입니다.");
//     }
//     return 0;
// }

//case 8
// int get_tax(int income);
// int main(void){
//     int tax,re;
//     printf("소득을 입력하시오(만원) :");
//     scanf("%d",&tax);
//     re = get_tax(tax);
//     printf("소득세는 %d만원입니다.",re);
//     return 0;
// }
// int get_tax(int income){
//     int ou,wu;
//     if (income > 1000){
//         wu = income / 1000;
//         wu *= 1000;
//         ou = income % 1000;
//         ou = ou * 8 / 100;
//         wu = wu * 10 / 100;
//         return ou + wu;
//     }
// }
//case 9
// #include <time.h>
// #include <stdlib.h>
// int randint();
// int main(void){
//     printf("실행 결과: ");
//     srand(time(NULL));
//     for (int i = 0 ; i < 10; i++){
//         randint();
//     }
//     return 0;
// }
// int randint(){
//      //난수 초기화
//     int num = rand() % 90 +11;
//     printf("%d ",num);
//     return 0;
// }

//case 10
// # include <math.h>
// double get_distance(double x1, double y1, double x2, double y2);
// int main(void){
//     double x1, y1, x2, y2;
//     double result;
//     printf("첫 번째 점의 좌표를 입력하시오 : ");
//     scanf("%lf %lf", &x1,&y1);
//     printf("두 번째 점의 좌표를 입력하시오 : ");
//     scanf("%lf %lf", &x2,&y2);
//     result = get_distance(x1,y1,x2,y2);
//     printf("두 점 사이의 거리는 %lf입니다.",result);
//     return 0;
// }
// double get_distance(double x1, double y1, double x2, double y2){
//     double d,a,b,d2;
//     a = (x1-x2)*(x1-x2);
//     b = (y1-y2)*(y1-y2);
//     d2 = a+b;
//     d = sqrt(d2);
//     return d;
// }

//case 11
#include <stdbool.h>
int is_prime(int a);

int main(void){
    int a;
    printf("정수를 입력하시오: ");
    scanf("%d",&a);
    printf("입력받은 정수로부터 소수는: ");
    is_prime(a);
    printf("입니다.");
    return 0;
}
int is_prime(int a){
    bool re = true;
    for (int i=2; i <= a; i++){
        for (int k=2; k < i; k++){
            if (i %k ==0){
                re = false;
            }
        }
        if (re){
            printf("%d ",i);
        }
        re = true;
    }
    return 0;
}