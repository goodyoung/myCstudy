#include <stdio.h>
//1
int main(void){
    float year_money, result;
    printf("연봉을 입력하세요:");
    scanf("%f", &year_money);
    result = 1000000000 / year_money;
    printf("%.2f", result);
    return 0;
}

//2
/*int main(void){
    float mile, meter;
    printf("마일 단위 거리를 입력하시오:");
    scanf("%f",&mile);
    meter = 1609*mile;
    printf("미터로 변환 된 값입니다. %f",meter);
    return 0;
}*/

//3
/*int main(void){
    float temp, result;
    printf("화씨 온도를 입력하세요: ");
    scanf("%f",&temp);
    result = (temp - 32);
    result = result*5/9;
    printf("%f",result);
    return 0;
}*/

//4
/*int main(void){
    float x,result;
    printf("x의 값을 입력하세요");
    scanf("%f",&x);
    result = 3*x*x + 7*x + 11;
    printf("%f",result);
    return 0;
}*/

//5
/*int main(void){
    double weight, result;
    printf("몸무게를 입력하세요: ");
    scanf("%lf",&weight);
    result = weight * 0.83;
    printf("%lf",result);
    return 0;
}*/