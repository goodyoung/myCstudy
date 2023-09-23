#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// #define SIZE 100001

typedef struct Node{
    int data;
    struct Node * next;
}Node;

int primeNum, nodeNum;
Node * g_pHead = NULL;

void nodeInit(Node * pNode){
    g_pHead = NULL;
    primeNum = 0;
    nodeNum = 0;
}
int duplicateNum(int number){
    Node * pTmp = g_pHead;
    if (pTmp ==NULL)
        return 1;
    while (pTmp !=NULL){
        if (pTmp->data == number)
            return 0; // duplicated
        pTmp = pTmp->next;
    }
    return 1;
}
int isPrime(int number){
    if (number <=1) //0과 1은 소수가 아님
        return 1;
    //동적 할당
    int *sieve = (int *)malloc((number + 1) * sizeof(int));
    memset(sieve,0,sizeof(int));

    // int a[SIZE] = { 0 };	

    for (int i = 2; i <= sqrt(number); i++) {	// 최대값의 제곱근까지 반복
        if (sieve[i] == 0) {		
            for (int j = 2; i * j <= number; j++) {	// 자신을 제외한 i의 배수 제거
                sieve[i * j] = 1;
            }
        }
    }

    // printf("%d",sieve[number]);
    return sieve[number]; //0이면 소수이다.
}
int insertNode(int number){
    //중복 확인
    if (duplicateNum(number)){
        Node* pTmp = (Node*)malloc(sizeof(Node));
        pTmp->data = number;
        
        if (g_pHead == NULL){
            g_pHead = pTmp;
        }else{
            pTmp->next = g_pHead;
            g_pHead = pTmp;
        }

        //소수 판별
        if (!isPrime(number-1) || !isPrime(number+1)){
            primeNum++;
        }
        //개수 저장
        nodeNum++; // 중복되지 않은 노드 개수
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
        printf("Delete Data: %d\n",pDelete->data);
        pTmp = pTmp->next;
        free(pDelete);
    }
}
int main(void){

    int data;
    FILE* fp = fopen("test.txt", "r");
    if (fp == NULL) {
    perror("File opening failed");
    return 1;
    }
    primeNum = 0;
    nodeNum = 0;

    while (fscanf(fp, "%d", &data) != EOF) {
        // 데이터를 Linked List에 추가
        // printf("%d\n",data);
        // printf("%d\n",data);
        insertNode(data);
    }
    fclose(fp);
    printf("%d, %d",primeNum,nodeNum);
    releaseNode();
    return 0;
}