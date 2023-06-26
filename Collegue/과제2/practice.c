#include <stdio.h>

//case 1
/*int main(void){
    float temp;
    scanf("%f",&temp);
    printf("소수점 표현 방법은: %.2f \n 지수 표현 방법은: %e",temp,temp);
    return 0;    
}*/

//case 2
// int main(void){
//     int temp;
//     scanf("%x",&temp);
//     printf("8진수: %#o 16진수: %#x",temp,temp);
//     return 0;
// }

//case 3

// int main(void){
//     int x = 10;
//     int y = 20;
//     printf("값 변환 전 x의 값은 %d y의 값은 %d\n",x,y);
//     int temp;
//     temp = x;
//     x = y;
//     y = temp;
//     printf("값 변환 후 x의 값은 %d y의 값은 %d",x,y);
//     return 0;
// }

//case 4

//  #define SQMETER_PER_PYEONG 3.3058
//  //double 자료형을 선택하였다.
//  int main(void){
//     double user, result;
//     scanf("%lf", &user);
//     result = SQMETER_PER_PYEONG * user;
//     printf("변환된 값은 %lfm^2 입니다.", result);
//     return 0;
// }

//case 5

// int main(void){
//     int mas;
//     char charvalue;
//     scanf("%d",&mas);
//     charvalue = (char)mas;
//     printf("%c", charvalue);
//     return 0;
// }

//case 6
// int main(void){

//     char te = 'a';
//     printf("%c\n", te+1);
//     printf("%c\n", te+2);
//     printf("%c", te+3);
//     return 0;
// }

//case 7
// int main(void){
//     printf("\a");
//     printf("화재가 발생했습니다.");
//     printf("\a");
//     return 0;
// }



//책 예제
#include <limits.h>

// int main(void){
//     short mon = SHRT_MAX;
//     unsigned short mon2 = USHRT_MAX;
//     printf("%d %d\n", mon, mon2);

//     mon += 1;

//     mon2 += 1;
//     printf("%d %d", mon, mon2);

//     return 0;
// }
// int main(void){
//     int id, pass;
//     printf("id: ____\b\b\b\b");
                    //     scanf("%d",&id);
//     printf("password: ____\b\b\b\b");
//     scanf("%d",&pass);
//     printf("\a입력된 아이디는: \"%d\"이고 입력된 비밀번호는: \"%d\"입니다.",id,pass);
//     return 0;
// }

int main(void)
{
double light_speed = 300000; 
double distance = 149600000; 
double time; 
time = distance / light_speed; 
time = time / 60.0; 
printf("빛의 속도는 %fkm/s \n", light_speed);
printf("태양과 지구와의 거리 %fkm \n", distance);
printf("도달 시간은 %f초\n", time); 
return 0;
}



