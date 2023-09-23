#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define SIZE 100001

typedef struct Node{
    double decimal;
    int data;
    struct Node * next;
}Node;


int primeNum=0, nodeNum=0;
Node * g_pHead = NULL;

int isPrime[SIZE];
int nodeArr[SIZE];
int* largeArr; 
double* decimalArr;

void calculatePrimes() {
    memset(isPrime, 0, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0; // 0과 1은 소수가 아님

    for (int i = 2; i <= sqrt(SIZE); i++) {
        if (isPrime[i] == 0) {
            for (int j = i * i; j < SIZE; j += i) {
                isPrime[j] = 1;
            }
        }
    }
}
int isLargePrime(int num) {
    if (num <= 1)
        return 0; // 1 이하의 숫자는 소수가 아님
    if (num <= 3)
        return 1; // 2와 3은 소수
    if (num % 2 == 0 || num % 3 == 0) 
        return 0; // 2 또는 3으로 나누어지면 소수가 아님

    // 5부터 시작하여 6씩 증가하면서 소수 여부를 검사
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}
int insertDecimalNode(double decimal, int size){
    for (int i = 0; i < size; i++) {
        if (decimalArr[i]==decimal){
            return 0;
        }
    }
    Node* pTmp = (Node*)malloc(sizeof(Node));
    pTmp->decimal = decimal;
    
    if (g_pHead == NULL){
        g_pHead = pTmp;
    }else{
        pTmp->next = g_pHead;
        g_pHead = pTmp;
    }
    nodeNum++;
    return 1;

}
int insertLargeNode(int numbers, int size){
    for (int i = 0; i < size; i++) {
        if (largeArr[i]==numbers){
            return 0;
        }
    }
    Node* pTmp = (Node*)malloc(sizeof(Node));
    pTmp->data = numbers;
    
    if (g_pHead == NULL){
        g_pHead = pTmp;
    }else{
        pTmp->next = g_pHead;
        g_pHead = pTmp;
    }

    if (isLargePrime(numbers-1) || isLargePrime(numbers+1)){ // 소수이면: 1
        primeNum++;
    }
    nodeNum++;
    return 1;

}
int insertNode(int number){
    //중복 확인
    if (!nodeArr[number]){
        Node* pTmp = (Node*)malloc(sizeof(Node));
        pTmp->data = number;
        
        if (g_pHead == NULL){
            g_pHead = pTmp;
        }else{
            pTmp->next = g_pHead;
            g_pHead = pTmp;
        }
        //소수 판별
        if  ((number > 0) && (!isPrime[number - 1] || !isPrime[number + 1])){
            primeNum++;
        }
        //개수 저장
        nodeNum++; // 중복되지 않은 노드 개수
        nodeArr[number] = 1;
        return 1;
    }else{
        return 0;
    }

}
void printNode(){
    Node * pTmp = g_pHead;
    while (pTmp !=NULL){
        printf("Data: %d\n",pTmp->data);
        pTmp = pTmp->next;
    }
}
void releaseNode(){
    Node * pTmp = g_pHead;
    while (pTmp != NULL){
        Node *pDelete = pTmp;
        // printf("Delete Data: %d\n",pDelete->data);
        pTmp = pTmp->next;
        free(pDelete);
    }
}

int main(void){
    memset(nodeArr, 0, sizeof(nodeArr));
    char line[100];
    int data;

    largeArr = (int*)malloc(sizeof(int) * SIZE);
    decimalArr= (double*)malloc(sizeof(double) * SIZE);
    int size_large=0;
    int size_decimal = 0;
    FILE* fp = fopen("input.txt", "r");

    //prime
    calculatePrimes();

    while (fgets(line, sizeof(line), fp)) {
        
        double number = strtod(line, NULL); // 문자열을 부동소수점 숫자로 변환

        // 정수 부분과 소수 부분을 분리
        double integerPart, fractionalPart;
        fractionalPart = modf(number, &integerPart);

        if (fractionalPart == 0.0) {
            // 부동소수점 부분이 없으면 정수로 간주
            if (number <= SIZE){
                insertNode((int)number);
            }
            else{
                if (insertLargeNode((int)number,size_large)){
                    largeArr[size_large] = (int)number;
                    size_large++;
                }
            }
        }else {
            if (insertDecimalNode(number,size_decimal)){
                decimalArr[size_decimal] = number;
                size_decimal++;
            }
        }
    }

    //부동소수점 처리를 어떻게 할 지 잘 모르겠다...
    fclose(fp);
    printf("Only one count : %d\nNear prime count : %d",nodeNum,primeNum);
    releaseNode();
    return 0;
}