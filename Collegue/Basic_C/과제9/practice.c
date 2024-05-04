#include <stdio.h>

// get_frac(double f, int *pi, double *pd);
// int main(void){
//     double f;
//     int pi;
//     double pd;
//     printf("실수를 입력하시오: ");
//     scanf("%lf",&f);
//     get_frac(f,&pi,&pd);
//     printf("정수부는 %d입니다.\n",pi);
//     printf("정수부는 %.2lf입니다.\n",pd);
//     return 0;
// }
// get_frac(double f, int *pi, double *pd){
//     *pi = (int)f;
//     *pd = f - (int)f;
//     printf("get_frac(%.2lf)이 호출되었습니다.\n",f);
// }   

//case 2
// int main(void){
//     int arr[3];
//     for (int i=0; i< 3; i++){
//         printf("정수를 입력하시오. :");
//         scanf("%d",&arr[i]);
//     }
//     printf("====================\n");
//     printf("  주소             값 \n");
//     printf("====================\n");
//     for(int i = 0 ; i < 3; i++){
//         printf("%08X\t%3d\n",&arr[i],arr[i]);
//     }
//     return 0;
// }

//case 3
// #include <time.h>
// #include <stdlib.h>
// void array_fill(int A[], int size);
// int main(void){
//     int arr[10];
//     array_fill(arr,10);
//     printf("실행결과: ");
//     for (int i = 0 ; i < 10; i++){
//         printf("%d |", arr[i]);
//     }
//     return 0;
// }
// void array_fill(int A[], int size){
//     srand(time(NULL));
//     for(int i=0; i<size; i++){
//         A[i] = rand()%20;
//     }
// }

//case 4
// void array_copy(int a[], int b[], int size);
// int print_arr(int a[],int size);
// int main(void){
//     int a[10] = {1,2, 3, 0, 0, 0, 0, 0, 0, 0};
//     int b[10];
//     array_copy(a,b,10);
//     return 0;
// }
// void array_copy(int a[], int b[], int size){
//     for (int i = 0 ; i< size; i++){
//         b[i] = a[i];
//     }
//     print_arr(a,10);
//     print_arr(b,10);   
//     printf("배열이 복사되었음");
// }
// int print_arr(int a[],int size){
//     for (int i = 0; i< size; i++){
//         printf("%d ",a[i]);
//     }
//     printf("\n");
// }

//case 5
// int my_strlen(char *p);
// int main(void){
//     char ch[6] = {'H','E','L','L','O',0};
//     int num = my_strlen(ch);
//     printf("저장된 문자열: ");
//     for (int i = 0 ; i < num ; i++){
//         printf("%c",ch[i]);
//     }
//     printf("\n문자열의 길이: %d",num);
//     return 0;
// }
// int my_strlen(char *p){
//     int s = 0;
//     while (1){
//         if (p[s]==0){
//             return s;
//             break;
//         }
//         s++;
//     }
// }   

//case 6
// void array_print(int *A, int size);
// int main(void){
//     int arr[10] = {1, 2, 3, 4, 5, 0, 0, 0, 0, 0};
//     int arr_size = sizeof(arr) / sizeof(arr[0]);
//     array_print(arr,arr_size);
//     return 0;
// }
// void array_print(int *A, int size){
//      int i;
//     printf("A[] = {");
//     for(i=0; i<size; i++){
//         printf("%d,",A[i]);
//     }
//     printf("}\n");
// }

//case 7
// int print_arr(int a[],int size);

// int main(void){
//     int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//     int desc_arr[10];
//     // int *ptr = &arr[9];
//     for(int i = 0 ; i < 10; i++){
//         *(desc_arr + i) = *(&arr[9] - i);
//     }
//     printf("A[] = ");
//     print_arr(arr,10);   
//     printf("A[] = ");
//     print_arr(desc_arr,10);    
//     return 0;
// }

// int print_arr(int a[],int size){
//     for (int i = 0; i< size; i++){
//         printf("%d ",a[i]);
//     }
//     printf("\n");
// }
// void convert(double *grades, double *scores, int size);
// int print_arr(double a[],int size);
// int main(void){
//     double stu_arr[10] = {0.00, 0.50, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.3};
//     double scores[10];
//     convert(stu_arr,scores,10);
//     print_arr(stu_arr,10);
//     print_arr(scores,10);
//     return 0;
// }
// void convert(double *grades, double *scores, int size){
//     int num;

//     for (int i = 0 ; i < size; i++){
//         num = (grades[i] / 4.3)*100;
//         scores[i] = num;
//     }
// }

// int print_arr(double a[],int size){
//     for (int i = 0; i< size; i++){
//         printf("%.2lf ",a[i]);
//     }
//     printf("\n");
// }

//case 9
// int print_arr(int a[],int size);
// void array_copy(int *A, int *B, int size);
// int main(void){
//     int arr_a[10] = {1,2,3,0,0,0,0,0,0,0};
//     int arr_b[10];
//     array_copy(arr_a,arr_b,10);
//     printf("A[] = ");
//     print_arr(arr_a,10);
//     printf("B[] = ");
//     print_arr(arr_b,10);    
//     return 0;
// }
// void array_copy(int *A, int *B, int size){
//     for (int i = 0 ; i< size; i++){
//         *(B+i) = *(A+i);
//     }
// }
// int print_arr(int a[],int size){
//     for (int i = 0; i< size; i++){
//         printf("%d ",a[i]);
//     }
//     printf("\n");
// }

//case 10
// void array_add(int *A, int *B, int *C, int size);
// int print_arr(int a[],int size);
// int main(void){
//     int base[10] = {1,2,3,0,0,0,0,0,0,0};
//     int bonus[10] = {4,5,6,0,0,0,0,0,0,0};
//     int sum[10];
//     array_add(base,bonus,sum,10);
//     printf("A[] = ");
//     print_arr(base,10);
//     printf("B[] = ");
//     print_arr(bonus,10);  
//     printf("C[] = ");
//     print_arr(sum,10); 
//     return 0;
// }
// void array_add(int *A, int *B, int *C, int size){
//     for(int i = 0 ; i< size; i++){
//         C[i] = A[i]+B[i];
//     }
// }
// int print_arr(int a[],int size){
//     for (int i = 0; i< size; i++){
//         printf("%d ",a[i]);
//     }
//     printf("\n");
// }

//case 11
// void get_sum_diff(int x, int y, int *p_sum, int *p_diff);
// int main(void){
//     int p_sum,p_diff;
//     get_sum_diff(200,100,&p_sum,&p_diff);
//     printf("원소들의 합 = %d\n",p_sum);
//     printf("원소들의 차 = %d",p_diff);
//     return 0;
// }
// void get_sum_diff(int x, int y, int *p_sum, int *p_diff){
//     *p_sum = x+y;
//     *p_diff = x-y;
// }
