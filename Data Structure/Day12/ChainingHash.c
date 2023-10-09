#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_TBL 1000

typedef struct _empInfo{
    int empNum;
    int age;
}EmpInfo;

typedef int KEY;
typedef EmpInfo* VALUE;
typedef int Hashfunc(KEY key);

typedef struct Slot{
    KEY key;
    VALUE val;
}Slot;

typedef struct Node{
    //노드에서 데이터가 슬롯인것이다!!
    Slot * sl;
    struct Node* next;
}Node;

typedef struct List{
    Node* head;
}List;

typedef struct _table {
    List tbl[MAX_TBL];
    Hashfunc* hf; //함수 포인터
}Table;

int isEmpty(List * plist){
    if (plist->head == NULL){
        return 1;
    }
    return 0;
}

void nodeInit(List * plist){
    plist->head = (Node *)malloc(sizeof(Node));
    memset(plist->head,0,sizeof(Node));
    plist->head->sl = (Slot *)malloc(sizeof(Slot));
    memset(plist->head->sl, 0, sizeof(Slot));
    plist->head->next = NULL;
}

void nodeInsert(List * plist, KEY k, VALUE v){
    Node * pTmp = (Node *)malloc(sizeof(Node));

    pTmp->sl = (Slot *)malloc(sizeof(Slot));
    pTmp->sl->key = k;
    pTmp->sl->val = v;
    pTmp->next = NULL;

    if (isEmpty(plist)){
        plist->head = pTmp;
    }else{
        Node* cur = plist->head;
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = pTmp;
    }
}
VALUE nodeSearch(List * plist, KEY k){
    Node* cur = plist->head;
    if (isEmpty(plist)){
        return NULL;
    }else{
        while(cur != NULL){
            if (cur->sl->key == k){
                return cur->sl->val;
            }
            cur = cur->next;
        }
    }
    return NULL;
}
VALUE nodeDelete(List* plist,KEY k){
    Node* prev;
    if (isEmpty(plist)){
        return NULL;
    }else{
            Node* cur = plist->head;
            while(cur != NULL){
                if (cur->sl->key == k){
                    if (prev == NULL) {
                        plist->head = cur->next;
                    } else {
                        prev->next = cur->next;
                    }

                    VALUE val = cur->sl->val;
                    free(cur->sl); // 슬롯 메모리 해제
                    free(cur);     // 노드 메모리 해제
                    return val;
                }
                prev = cur;
                cur = cur->next;
            }

        }
        return NULL;
    }



void TBLInit(Table * pt, Hashfunc * f){
    //모든 슬롯의 상태를 EMPTY로 설정하고 해쉬 함수 등록
    for(int i = 0 ; i < MAX_TBL; i++){
        nodeInit(&pt->tbl[i]);
    }
    pt->hf = f;
}


void TBLInsert(Table * pt, KEY k, VALUE v){
    int hv = pt->hf(k); // 키를 받아 해쉬 함수를 돌려서 인덱스 값을 얻어온다
    if (nodeSearch(&pt->tbl[hv],k) != NULL){
        printf("키 중복 오류 발생");
        return;
    }else{
        nodeInsert(&pt->tbl[hv],k,v);
    }
    
    //테이블에 저장되는 데이터의 키 값은 유일해야 한다
    // 해시값은 중복되어도 상관 없지만 키 값은 유일해야한다.
}

VALUE TBLDelete(Table* pt, KEY k){
    int hv = pt->hf(k);
    return nodeDelete(&pt->tbl[hv],k);
}
VALUE TBLSearch(Table* pt, KEY k){
    int hv = pt->hf(k);
    return nodeSearch(&pt->tbl[hv],k);
}

int getHashKey(int num){
    return num % MAX_TBL;
}

int main(void) {
    Table pt;
    int (*hf)(int num);
    hf = getHashKey;
    TBLInit(&pt, hf);

    // 데이터 추가 예제
    EmpInfo em1;
    em1.empNum = 2020001;
    em1.age = 25;
    TBLInsert(&pt, em1.empNum, &em1);

    EmpInfo em2;
    em2.empNum = 2020002;
    em2.age = 30;
    TBLInsert(&pt, em2.empNum, &em2);

    EmpInfo em3;
    em3.empNum = 2020003;
    em3.age = 35;
    TBLInsert(&pt, em3.empNum, &em3);

    // 데이터 검색 예제
    int searchKey = 2020002;
    VALUE found = TBLSearch(&pt, searchKey);
    if (found != NULL) {
        printf("Employee Number: %d, Age: %d\n", found->empNum, found->age);
    } else {
        printf("Employee not found.\n");
    }

    // 데이터 삭제 예제
    int deleteKey = 2020001;
    VALUE deleted = TBLDelete(&pt, deleteKey);
    if (deleted != NULL) {
        printf("Deleted Employee Number: %d, Age: %d\n", deleted->empNum, deleted->age);
    } else {
        printf("Employee not found for deletion.\n");
    }

    return 0;
}