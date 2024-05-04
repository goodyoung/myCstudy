#include <stdio.h>

//case 1
// int main(void){
//     int temp1, temp2;
//     printf("두 개의 정수를 입력하시오:");
//     scanf("%d %d",&temp1,&temp2);
//     printf("몫:%d \n나머지: %d",temp1 / temp2,temp1 % temp2);
//     return 0;
// }
//case 2
// int main(void){
//     double temp1, temp2;
//     printf("실수를 입력하시오:");
//     scanf("%lf %lf",&temp1,&temp2);
//     printf("합:%.2lf\n차: %.2lf\n곱: %.2lf\n몫: %.2lf",temp1 + temp2,
//      temp1 - temp2, temp1*temp2, temp1 / temp2);
//     return 0;
// }

//case3
// int main(void){
//     int temp1,temp2,temp3;
//     int result;
//     printf("정수 3개를 입력하시오 :");
//     scanf("%d%d%d",&temp1,&temp2,&temp3);
//     result = temp1 > temp2 ? temp1 : temp2;
//     result = result > temp3 ? result : temp3;
//     printf("최대값은 %d입니다.",result);
//     return 0;
// }

//case4
// int main(void){
//     int heightCm;
//     printf("키를 입력하시오(cm):");
//     scanf("%d",&heightCm);
//     int inchesPerFoot = 12;
//     double cmPerInch = 2.54;
//     double heightInches = heightCm / cmPerInch;
//     int heightFeet = heightInches / inchesPerFoot;
//     double remainingInches = heightInches - (heightFeet * inchesPerFoot);
//     printf("%dcm는 %d피트 %.2lf인치입니다.\n", heightCm, heightFeet, remainingInches);
//     return 0;
// }
//case5
// int main(void){
//     int temp1;
//     int ten, one;
//     printf("정수를 입력하시오: ");
//     scanf("%d", &temp1);
//     printf("십의 자리: %d\n", temp1 / 10);
//     printf("일의 자리: %d", temp1 % 10);
//     return 0;
// }
//case6
// int main(void) {
//     int x,y;
//     printf("x좌표를 입력하시오:");
//     scanf("%d",&x);
//     printf("y좌표를 입력하시오:");
//     scanf("%d",&y);

//     (x > 0)? ((y>0) ? printf("1사분면\n"):printf("4사분면\n")):((y>0) ? printf("2사분면\n") : printf("3사분면\n"));
//     return 0;
// }

//case7
// int main(void){
//     int temp1,temp2,temp3;
//     int sum = 0;
//     printf("국어 영어 수학 점수를 입력하시오: ");
//     scanf("%d%d%d",&temp1,&temp2,&temp3);
//     sum = temp1+temp2+temp3;
//     printf("세과목의 점수의 합은 %d\n",sum);
//     printf("세과목의 점수의 평균은 %d",sum/3);
//     return 0;
// }


//책 예제
// int main(void){

//     unsigned int num;
//     printf("십진수: ");
//     scanf("%u", &num);

//     unsigned int mask = 1 << 7;
//     printf("이진수: ");

//     ((num & mask) == 0) ? printf("0") : printf("1");
//     mask = mask >> 1;
//     ((num & mask) == 0) ? printf("0") : printf("1");
//     mask = mask >> 1;
//     ((num & mask) == 0) ? printf("0") : printf("1");
//     mask = mask >> 1;
//     ((num & mask) == 0) ? printf("0") : printf("1");
//     mask = mask >> 1;
//     ((num & mask) == 0) ? printf("0") : printf("1");
//     mask = mask >> 1;
//     ((num & mask) == 0) ? printf("0") : printf("1");
//     mask = mask >> 1;
//     ((num & mask) == 0) ? printf("0") : printf("1");
//     mask = mask >> 1;
//     ((num & mask) == 0) ? printf("0") : printf("1");
//     printf("\n");
//     return 0;
// }
// 예제 2
int main(void){
    char data = 'a';
    char key = 0xff;
    char encrpted_data, orig_data;
    printf("원래의 문자=%c\n", data);
    encrpted_data = data ^ key;
    printf("암호화된 문자=%c \n", encrpted_data);
    orig_data = encrpted_data ^ key;
    printf("복원된 문자=%c\n", orig_data);
    
    return 0;
}