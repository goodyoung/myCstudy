#include <stdio.h>
//case 1
// int main(void){ 
//     int days[15] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     for (int i = 0; i < 12; i++){
//         printf("%d월은 %d일까지 있습니다.\n",i+1,days[i]);
//     }
//     return 0;   
// }

//case 2 
// #include <stdlib.h>
// #include <time.h>
// #define SIZE 10
// int main(void){
//     int scores[SIZE];
//     srand((unsigned)time(NULL));
//     for(int i = 0; i < SIZE; i++)
//         scores[i] = rand();

//     int Max = scores[0];
//     int Min = scores[0];
//     for (int i = 1; i < SIZE; i++){
//         if (Max < scores[i]){
//             Max = scores[i];
//         }
//         if (Max > scores[i]){
//             Min = scores[i];
//         }
//     }
//     printf("최대값은 %d\n",Max);
//     printf("최소값은 %d",Min);

//     return 0;
// }

//case3
// int array_equal(int a[], int b[],int size){
//     int result[size];
//     for (int i = 0 ; i < size; i++){
//         if (a[i] == b[i]){
//             continue;
//         }else{
//             return 0;
//             break;
//         }
        
//     }
//     return 1;
// }
// int print_arr(int a[],int size){
//     for (int i = 0; i< size; i++){
//         printf("%d ",a[i]);
//     }
//     printf("\n");
// }
// int main(void){
//     int arr_a[10] = { 1, 2, 3, 0, 0, 0, 0, 0, 0, 0};
//     int arr_b[10] = { 0,0,0, 0, 0, 0, 0, 0, 0, 0};
//     int result;
//     print_arr(arr_a,10);
//     print_arr(arr_b,10);
//     result = array_equal(arr_a,arr_b,10);
//     if (result ==1 ){
//         printf("두 개의 배열은 같음");
//     }else{
//         printf("두 개의 배열은 다름");
//     }
//     return 0;
// }

//case 4
// int print_arr(int a[],int size){
//     for (int i = 0; i< size; i++){
//         printf("%d ",a[i]);
//     }
//     printf("\n");
// }

// int array_copy(int a[], int b[], int size){
//     for(int i = 0 ; i < size ; i++){
//         b[i] = a[i];
//     }
//     print_arr(a,10);
//     print_arr(b,10);
//     printf("배열이 복사되었음");
// }

// int main(void){
//     int arr_a[10] = { 1, 2, 3, 0, 0, 0, 0, 0, 0, 0};
//     int arr_b[10];
//     array_copy(arr_a,arr_b,10);
//     return 0;
// }

//case 5

// #include <stdlib.h>
// #include <time.h>
// #define size 10
// int main(void){
//     int arr[size]={0};
//     int num;
//     srand((unsigned)time(NULL));
//     for(int i = 0 ; i < 100; i++){
//         num = rand()%10;
//         ++arr[num];
//     }
//     int max = 0;
//     for (int i = 1 ; i < size; i++){
//         if (max < arr[i]){
//             max = i;
//         }
//     }
//     printf("가장 많이 나온 수 = %d",max);
//     return 0;
// }

//case 6
// #define ROWS 3
// #define COLS 5
// int main(void){
//     int arr[ROWS][COLS] = {{12,56, 32, 16, 98},
//                         {99, 56, 34, 41, 3},
//                         {65, 3, 87, 78, 21}};
//     //행
//     int sum = 0;
//     for (int i = 0 ; i < ROWS; i++){
//         for (int k = 0 ; k < COLS; k++){
//             sum += arr[i][k];
//         }
//         printf("%d행의 합계 : %d\n",i,sum);
//         sum = 0;
//     }
//     //열
//     for (int i = 0 ; i < COLS; i++){
//         for (int k = 0 ; k < ROWS; k++){
//             sum += arr[k][i];
//         }
//         printf("%d열의 합계 : %d\n",i,sum);
//         sum = 0;
//     }
//     return 0;
// }

//case 7
// #include <stdlib.h>
// #include <time.h>
// int main(void){
//     int school_class[5][3] ={};
//     srand(time(NULL));
//     for (int i = 0; i< 5; i++){
//         for ( int j = 0 ; j < 3; j++){
//             school_class[i][j] = rand()%101;
//         }
//     }

//     for (int i = 0; i< 3; i++){
//         int max = school_class[0][i];
//         int min = school_class[0][i];
//         for (int j = 0 ; j< 5; j++){
//             if (max < school_class[j][i])
//                 max = school_class[j][i];
//             if (min > school_class[j][i])
//                 min = school_class[j][i];
//         }
//         printf("시험 #%d의 최대점수 = %d\n",i,max);
//         printf("시험 #%d의 최대점수 = %d\n",i,min);
//     }
//     return 0;   
// }
//선택정렬
// #define SIZE 10
// int main(void){
//     int list[SIZE] = { 3, 2, 9, 7, 1, 4, 8, 0, 6, 5 };
//     for (int i = 0 ; i < SIZE-1; i++){
//         int least = i;
//         for ( int k = i+1 ; k< SIZE; k++){
//             if ( list[least]>list[k]){
//                 least = k;
//             }
//         }
//         int temp = list[i];
//         list[i] = list[least];
//         list[least] = temp;
//     }
//     printf("리스트는: ");
//     for (int i = 0 ; i < 10; i++){
//         printf("%d ", list[i]);
//     }
//     return 0;
// }

//이진 탐색
// #define SIZE 16
// int binary_search(int list[], int first, int last, int key);
// int main(void){
//     int grade[SIZE] = { 2,6,11,13,18,20,22,27,29,30,34,38,41,42,45,47 };
//     int key = 6; //찾을 값.
//     int first = 0;
//     int last = sizeof(grade) / sizeof(grade[0]) ;

//     int index = binary_search(grade,first,last,key);
//     if (index == -1){
//         printf("탐색 실패");
//     }else{
//         printf("안녕: %d %d",index, grade[index]);
//     }
//     return 0;
// }

// int binary_search(int list[], int first, int last, int key){    
//     if (first > last){
//         return -1;
//     }
//     int middle = (first + last) / 2;
//     if (list[middle] == key){
//         return middle;
//     } else if (list[middle] < key){
//         int min = middle +1;
//         return binary_search(list, min,last ,key);
//     }else{
//         int max = middle -1;
//         return binary_search(list, first,max ,key);
//     }
// }