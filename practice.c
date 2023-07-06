#include <stdio.h>
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
// double light_speed = 300000; 
// double distance = 149600000; 
// double time; 
// time = distance / light_speed; 
// time = time / 60.0; 
// printf("빛의 속도는 %fkm/s \n", light_speed);
// printf("태양과 지구와의 거리 %fkm \n", distance);
// printf("도달 시간은 %f초\n", time); 
// return 0;
int i=-3, j=2,k=0,m;
m = ++i && ++j && ++k;
printf("%d",m);
}
