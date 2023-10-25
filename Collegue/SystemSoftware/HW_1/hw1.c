#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


#define SIZE 100001

typedef struct Node{
    double decimal;
    int data;
    struct Node * next;
}Node;


int primeNum=0, nodeNum=0;
Node * g_pHead = NULL; //노드 헤드
int isPrime[SIZE]; // 대부분의 소수 판별 배열
// 노드 배열
int nodeArr[SIZE]; // 대부분의 노드 배열
int* largeArr; //큰 수 배열 
double* decimalArr; //소수 배열


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


int isLargePrime(int num) { //큰 수 소수 판별
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


void insertNodeInit(Node* pTmp){ //노드 삽입
    if (g_pHead == NULL){
        g_pHead = pTmp;
    }else{
        pTmp->next = g_pHead;
        g_pHead = pTmp;
    }
    nodeNum++;
}


int insertDecimalNode(double decimal, int size){ //소수 노드일 경우
    //중복 확인
    for (int i = 0; i < size; i++) {
        if (decimalArr[i]==decimal){
            return 0;
        }
    }
    Node* pTmp = (Node*)malloc(sizeof(Node));
    pTmp->decimal = decimal;
    //노드 삽입
    insertNodeInit(pTmp);
    return 1;
}


int insertLargeNode(int numbers, int size){ //큰 수 노드일 경우
    //중복 확인
    for (int i = 0; i < size; i++) {
        if (largeArr[i]==numbers){
            return 0;
        }
    }
    Node* pTmp = (Node*)malloc(sizeof(Node));
    pTmp->data = numbers;
    //노드 삽입
    insertNodeInit(pTmp);
    //소수 판별
    if (isLargePrime(numbers-1) || isLargePrime(numbers+1)){ // 소수이면: 1
        primeNum++;
    }
    return 1;
}


int insertNode(int number){ //대부분의 수 노드일 경우
    //중복 확인
    if (!nodeArr[number]){
        Node* pTmp = (Node*)malloc(sizeof(Node));
        pTmp->data = number;
        //노드 삽입
        insertNodeInit(pTmp);
        //소수 판별
        if  ((number > 0) && (!isPrime[number - 1] || !isPrime[number + 1])){
            primeNum++;
        }
        //노드 방문
        nodeArr[number] = 1;
        return 1;
    }else{
        return 0;
    }
}

void releaseNode(){ // 메모리 전부 해제
    Node * pTmp = g_pHead;
    while (pTmp != NULL){
        Node *pDelete = pTmp;
        pTmp = pTmp->next;
        free(pDelete);
    }
}

int main(void){
    //큰 수 & 소수 배열 할당
    largeArr = (int*)malloc(sizeof(int) * SIZE);
    decimalArr= (double*)malloc(sizeof(double) * SIZE);

    //큰 수 & 소수 배열 사이즈
    int size_large=0;
    int size_decimal = 0;

    //대부분의 수 배열 초기화
    memset(nodeArr, 0, sizeof(nodeArr)); 

    // 대부분의 수 소수 판별
    calculatePrimes(); 

    //파일 오픈
    FILE* fp = fopen("input.txt", "r");
    char line[100];
    //받는 숫자가 부동소수점일 수도 있어서
    //부동소수점 판별이 필요함
    //문자열 -> double -> 소수점 뒷자리 확인

    while (fgets(line, sizeof(line), fp)) {
        
        
        double number = strtod(line, NULL); // 문자열을 부동소수점 숫자로 변환

        // 정수 부분과 소수 부분을 분리
        double integer, fractional;
        fractional = modf(number, &integer);

        if (fractional == 0.0) {
            // 부동소수점 부분이 없으면 정수로 취급
            if (number <= SIZE){ // 대부분의 수일 경우
                insertNode((int)number);
            }
            else{
                if (insertLargeNode((int)number,size_large)){ //큰 수일 경우
                    largeArr[size_large] = (int)number;
                    size_large++;
                }
            }
        }else {
            if (insertDecimalNode(number,size_decimal)){ // 소수일 경우
                decimalArr[size_decimal] = number;
                size_decimal++;
            }
        }
    }

    fclose(fp);
    printf("Only one count : %d\nNear prime count : %d",nodeNum,primeNum);
    releaseNode();
    return 0;
}