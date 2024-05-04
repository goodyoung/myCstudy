//기초컴퓨터프로그래밍 기말과제

// #include <stdio.h>
// #define SIZE 6
// // 성적관리 프로그램
// int total(int kor, int eng, int mat);
// double average(int tot);
// void print_title(void);
// char get_grade(double *avg);

// int main(void){
//     double total_result[SIZE];
//     printf("세과목의 점수 입력 : ");
//     scanf("%lf %lf %lf",&total_result[0],&total_result[1],&total_result[2]);
//     total_result[3] = total(total_result[0],total_result[1],total_result[2]);
//     total_result[4] = average(total_result[3]);
    

//     print_title();
//     for (int i = 0 ; i < SIZE-1; i++){
//         printf("%.1lf ",total_result[i]);
//     }
//     printf("%c ",get_grade(total_result));
//     return 0;
// }

// int total(int kor, int eng, int mat){
//     int sum = kor + eng + mat;
//     return sum;
// }
// double average(int tot){
//     return (double) tot/3;
// }

// void print_title(void){
//     printf("=========< 성적표 >=========\n");
//     printf("--------------------------------\n");
//     printf("국어 영어 수학 총점 평균 학점\n");
//     printf("--------------------------------\n");
// }
// char get_grade(double *avg){
//     if ((avg[4] >= 90)){
//         return 'A';
//     }else if (avg[4] >= 80){
//         return 'B';
//     }else if (avg[4] >= 70){
//         return 'C';
//     }else{
//         return 'D';
//     }
// }


// 함수를 사용한 사칙연산 프로그램

#include <stdio.h>
double add(double num1,double num2); //덧셈 함수
double sub(double num1,double num2); //뺄셈 함수
double mul(double num1,double num2); //곱셈 함수
double div(double num1,double num2); //나눗셈 함수
void menu_disp(); //메뉴를 보여주는 함수
void res_disp(double); //결과를 보여주는 함수
int main(void){
    int num;
    double user_num1,user_num2;
    double result;
    menu_disp();
    scanf("%d",&num);
    printf("두 개의 숫자를 입력하세요 : ");
    scanf("%lf %lf",&user_num1,&user_num2);
    switch (num)
    {
    case (1):
        result = add(user_num1,user_num2);
        break;
    case (2):
        result = sub(user_num1,user_num2);
        break;
    case (3):
        result = mul(user_num1,user_num2);
        break;
    case (4):
        result = div(user_num1,user_num2);
        break;
    }
    res_disp(result);
    return 0;
}
double add(double num1,double num2){
    return num1 + num2;
}
double sub(double num1,double num2){
    return num1 - num2;
}
double mul(double num1,double num2){
    return num1 * num2;
}
double div(double num1,double num2){
    return num1 / num2;
}
void menu_disp(){
    printf("1. 덧셈(addition)\n2. 뺄셈(subtraction)\n3. 곱셈(multiplication)\n4. 나눗셈(division)\n>>원하는 메뉴를 선택하세요 : ");
    return;
}

void res_disp(double num){
    printf("결과값은 %lf입니다.",num);
}