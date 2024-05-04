#include <stdio.h>
//case 1
// #define gets(s) gets_s(s)
// int main(void){
//     char ch[10];
//     char temp[10];
//     printf("문자열을 입력하시오 :");
//     fgets(ch, sizeof(ch), stdin);
//     //(ch,sizeof(ch));
//     int s=0;
//     for(int i = 10-1 ; i >= 0 ; i--){
//         temp[s] = ch[i];
//         s++;
//     }
//     printf("역순 문자열 : ");
//     for (int i = 0; i < s; i++) {
//         printf("%c", temp[i]);
//     }

//     return 0;
// }

//case 2 
// #include <string.h>
// #include <ctype.h>


// #define gets(s) gets_s(s)
// int main(void){
//     char ch[20];

//     printf("문자열을 입력하시오 :");
//     fgets(ch, sizeof(ch), stdin);
//     printf("공백 제거 문자열 = ");
//     int num = strlen(ch);
//     for(int i = 0 ; i < num; i++){
//         if (isspace(ch[i]) == 0)!= 0{
//             printf("%c",ch[i]);
//         }
//     }
//     return 0;
// }
//case 3
// #include <string.h>
// void chars(char ch[],char tem[],int size);
// int main(void){
//     char ch[20];
//     char tem[20];
//     printf("문자열을 입력하시오 :");
//     fgets(ch, sizeof(ch), stdin);
//     printf("제거할 문자 : ");
//     scanf("%c",&tem);
//     int num = strlen(ch);
//     printf("결과 문자열 = ");
//     chars(ch,tem,num);
//     return 0;
// }

// void chars(char ch[],char tem[],int size){

//         for (int i = 0 ; i < size; i++){
//         if ((ch[i] == tem) == 0 ){
//             printf("%c",ch[i]);
//         }
//     }
// }

//case 4
// #include <string.h>
// #define gets(s) gets_s(s)
// int str_chr(char *s, char c);
// int main(void){
//     char ch[20];
//     char tem;

//     printf("문자열을 입력하시오 :");
//     fgets(ch, sizeof(ch), stdin);
//     printf("문자를 입력하시오 : ");
//     scanf("%c",&tem);

//     str_chr(ch,tem);
//     return 0;
// }
// int str_chr(char *s, char c){
//     int num = strlen(s);
//     char *ptr = strchr(s,c);
//     int count = 0;
//     while (ptr != NULL)
//     {  
//         ptr = strchr(ptr + 1, c);
//         count++;
//     }
//     printf("%c의 개수 : %d",c,count);
// }

//case 5
// #include <string.h>
// #include <ctype.h>
// #define gets(s) gets_s(s)
// int main(void){
//     char ch[20];
//     char temp[20];
//     char alap[30];
//     int result[30];
//     int counts=0;
//     printf("문자열을 입력하시오 :");
//     fgets(ch, sizeof(ch), stdin);  
    
//     int nums = strlen(ch);
//     for(int i = 0 ; i < nums; i++){
//         printf("%c",ch[i]);
//         if (isspace(ch[i]) == 0)!= 0{{

// }
//             temp[counts] = ch[i];
//             counts++;
//         }
//     }

//     int num = strlen(temp);

//     for(int i = 0 ; i< 25; i ++){
//         alap[i] = i+97;
//     }

//     for(int i = 0 ; i< 25; i ++){
//         int count=0;
//         for (int k = 0 ; k < num; k++){
//             if(temp[k]==alap[i]){
//                 count++;
//             }
//         }
//         result[i] = count;
//     } 

//     for(int i = 0 ; i< 25; i ++){
//         printf("%c : %d ",alap[i],result[i]);
//     }
//     return 0;
// }

//case 6
// #include <string.h>
// #include <ctype.h>
// #define gets(s) gets_s(s)
// int main(void){
//     char ch[20];
//     char temp[20];
//     char alap[30];
//     int nc=0, lc=0, bc=0;
//     printf("문자열을 입력하시오 :");
//     fgets(ch, sizeof(ch), stdin);  


//     for (int i = 0; ch[i]; i++)
//     {
//         if ((ch[i] >= '0') && (ch[i] <= '9'))
//         {
//             nc++;
//         }
//         else if ((ch[i] >= 'a') && (ch[i] <= 'z')|| (ch[i] >= 'A') && (ch[i] <= 'Z'))
//         {
//             lc++;
//         }
//         else
//         {
//             bc++;
//         }
//     }
//     printf("문자열 안의 알파벳 문자의 개수 : %d\n",lc);
//     printf("문자열 안의 숫자의 개수 : %d\n",nc);
//     printf("문자열 안의 기타 문자의 개수 : %d\n",bc-1);
// }

// case 7 
// #include <string.h>
// #include <ctype.h>
// #define gets(s) gets_s(s)
// int main(void){
//     char ch[20];
//     int count=0;
//     printf("문자열을 입력하시오 :");
//     fgets(ch, sizeof(ch), stdin);  
    
//     int nums = strlen(ch);
//     for(int i = 0 ; i < nums; i++){
//         printf("%c",ch[i]);
//         if (isspace(ch[i]) != 0)!= 0{{

// }
//             count++;
//         }
//     }
//     printf("단어의 수는 %d입니다.",count);
//     return 0;
// }

//case 8
// #include <string.h>
// #include <ctype.h>
// #define gets(s) gets_s(s)
// int chars(char ch[],int size);
// int main(void){
//     char ch[20];
//     char temp[20];
//     int count=0;
//     printf("문자열을 입력하시오 :");
//     fgets(ch, sizeof(ch), stdin); 
//     int nums = strlen(ch);
//     int num = chars(ch,nums-1);

//     if (num ==1){
//         printf("회문입니다.");
//     }else{
//         printf("회문이 아닙니다.");
//     }
//     return 0;
// }
// int chars(char ch[],int size){
//     for(int i = 0 ; i < size/2 ; i++){
//         if(ch[i]!=ch[size-1-i]){
//             return 0;
//         }
//     }
//     return 1;
// }

//case 9
// #include <string.h>
// #include <ctype.h>
// int main(void){
//     char ch[100];
//     char *token[100];
//     printf("문자열을 입력하시오: ");
//     fgets(ch, sizeof(ch), stdin);     
    
//     ch[strlen(ch)-1] = '\0'; //NULL;

//     token[0] = strtok(ch," ");
//     int i = 0 ;
//     while( token[i] != NULL){
        
//         token[i+1] = strtok(NULL," ");
//         i++;
//     }
//     for (int j =i-1; j >=0;j--){
//         printf("%s ",token[j]);
//     }
//     return 0;
    
// }
// #include <stdio.h>
// void f(void);

// int i;
// int main(void){

// for(i = 0;i < 3; i++){
//     printf("*");
//     f();
//     printf("%d",i);
// }
//     return 0;
// }

// void f(void){
//     printf("%d",i);
//     for(i = 0;i < 5; i++)
//     printf("#");
// }
// int sum(int n ){
//     printf("%d\n",n);
//     if(n<1) return 2;
//     else return (2*sum(n-1) + 1);
// }
// int main(void){
//     int num = sum(5);
//     printf("%d",num);
// }
// #include <string.h>
// int main(void){
//     char *p;
//     char s[]="HELLO";
//     p = s+2 ;//+ strlen(s)-1;
//     printf("%lu",sizeof(s));
//     while(p >=s){
//         printf("%s \n",p);
//         p--;
//     }
// }