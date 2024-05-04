#include <stdio.h>

//case1-1
// int main(void){
//     char ch;
//     printf("문자를 입력하시오 :");
//     scanf("%c",&ch);
//     switch (ch){
//         case 'a':
//         case 'i':
//         case 'e':
//         case 'o':
//         case 'u':
//         printf("모음입니다.\n");
//         break;
//         default:
//         printf("자음입니다.\n");
//         break;
//     }
//     return 0;
// }
//case1-2
// int main(void){
//     char ch;
//     printf("문자를 입력하시오 :");
//     scanf("%c",&ch);
//     if ((ch == 'a') || (ch == 'i') || (ch == 'e') || (ch == 'o') || (ch == 'u')){
//         printf("모음입니다.\n");
//     } else{
//         printf("자음입니다.\n");
//     }
//     return 0;
// }

//case 2
// int main(void){
//     int x,y,z;
//     int result = 0;
//     printf("세 개의 정수를 입력하시오:");
//     scanf("%d %d %d",&x,&y,&z);
//     if (x > y){
//         result = y;
//     }else{
//         result = x;
//     }
//     if (result > z){
//         result = z;
//     }
//     printf("제일 작은 정수는 %d입니다.",result);
//     return 0;
// }

//case 3
// int main(void){
//     int x,y;
//     printf("정수를 입력하시오: ");
//     scanf("%d",&x);
//     printf("정수를 입력하시오: ");
//     scanf("%d",&y);
//     if (x % y ==0){
//         printf("약수입니다.\n");
//     }else{
//         printf("약수가 아닙니다.\n");
//     }
//     return 0;
// }

//case 4
// #include <stdlib.h>
// #include <time.h>
// int main(void){
//     int user, com;
//     srand(time(NULL));
//     com = rand()%3 +1;

//     printf("(1: 가위 2: 바위 3: 보) 중에서 하나를 선택하시오: ");
//     scanf("%d",&user);
//     if (com == 1){
//         printf("컴퓨터는 가위를 선택하였습니다.\n");
//     }else if (com==2){
//         printf("컴퓨터는 바위를 선택하였습니다.\n");
//     }else{
//         printf("컴퓨터는 보를 선택하였습니다.\n");
//     }

//     if ((user==1 && com==2) || (user==2 && com == 3) || (user==3 && com==1)){
//         printf("사용자가 졌다\n");
//     }else if ((user==1 && com == 3) || (user==2 && com==1)|| (user==3 && com==2)){
//         printf("사용자가 이겼다.\n");
//     } else{
//         printf("비겼다.\n");
//     }

//     return 0;
// }
//case 5
// int main(void){
//     int height, age;
//     printf("키를 입력하시오(cm) : ");
//     scanf("%d",&height);
//     printf("나이를 입력하시오 : ");
//     scanf("%d",&age);

//     if(height>140 && age >= 10){
//         printf("타도 좋습니다.");
//     }else{
//         printf("죄송합니다.");
//     }
//     return 0;
// }
//case 6

// int main(void){
//     int month;
//     printf("월번호를 입력하시오(1-12):");
//     scanf("%d",&month);
//     switch (month)
//     {
//     case 1: printf("Jan"); break;
//     case 2: printf("Feb"); break;
//     case 3: printf("Mar"); break;
//     case 4: printf("Apr"); break;
//     case 5: printf("May"); break;
//     case 6: printf("Jun"); break;
//     case 7: printf("Jul"); break;
//     case 8: printf("Aug"); break;
//     case 9: printf("Sep"); break;
//     case 10: printf("Oct"); break;
//     case 11: printf("Nov"); break;
//     case 12: printf("Dec"); break;
//     default: printf("다시 입력하세요."); break;
//     }
//     return 0;
// }

//case 7

// int main(void){
//     int x,y;
//     printf("좌표(x, y):");
//     scanf("%d %d",&x,&y);
//     if(x>0 && y>0){
//         printf("1사분면");
//     }else if(x >0 && y<0) {
//         printf("4사분면");
//     }else if(x <0 && y>0) {
//         printf("2사분면");
//     }else if (x <0 && y<0){
//         printf("3사분면");
//     }else{
//         printf("원점입니다.");
//     }
//     return 0;
// }

//책 예제
// #include <math.h>
// int main(void){
//     double a, b, c, dis;
//     printf("계수 a, 계수 b, 계수 c를 차례대로 입력하시오: ");
//     scanf("%lf %lf %lf",&a,&b,&c);

//     if (a==0){
//         printf("방정식의 근은 %f입니다.\n", -c/b);
//     } else{

//         dis = b * b - 4.0 * a * c;
//         if (dis >=0){
//             printf("방정식의 근은 %.2f입니다.\n", (-b + sqrt(dis)) / (2.0 * a));
//             printf("방정식의 근은 %.2f입니다.\n", (-b - sqrt(dis)) / (2.0 * a));
//         }else{
//             printf("실근이 존재하지 않습니다.\n");
//         }
//     }

//     return 0;
// }

int main(void){
    
    return 0;
}