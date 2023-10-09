#include <stdio.h>
#define MAX_TBL 1000
enum SlotState {EMPTY, DELETE, INUSE};

typedef struct _empInfo{
    int empNum;
    int age;
}EmpInfo;

typedef int KEY;
typedef EmpInfo* VALUE;
typedef int Hashfunc(KEY key);



typedef struct _Slot{
    KEY key;
    VALUE val;
    enum SlotState enState;
}Slot;

typedef struct _table {
    Slot tbl[MAX_TBL];
    Hashfunc* hf; //함수 포인터
}Table;

void TBLInit(Table * pt, Hashfunc * f){
    //모든 슬롯의 상태를 EMPTY로 설정하고 해쉬 함수 등록
    for(int i = 0 ; i < MAX_TBL; i++){
        (pt->tbl[i]).enState = EMPTY;
    }
    pt->hf = f;
}
void TBLInsert(Table * pt, KEY k, VALUE v){
    int hv = pt->hf(k); // 키를 받아 해쉬 함수를 돌려서 인덱스 값을 얻어온다
    pt->tbl[hv].val = v;
    pt->tbl[hv].key = k;
    pt->tbl[hv].enState = INUSE;
}

VALUE TBLDelete(Table* pt, KEY k){
    int hv = pt->hf(k);
    if (pt->tbl[hv].enState != INUSE){
        return NULL;
    }else{
        pt->tbl[hv].enState = INUSE;
        VALUE v = pt->tbl[hv].val;
        return v;
    }
}

VALUE TBLSearch(Table * pt, KEY k){
    int hv = pt->hf(k);
    if (pt->tbl[hv].enState != INUSE){
        return NULL;
    }else{
        VALUE v = pt->tbl[hv].val;
        return v;
    }
}

int getHashKey(int num){
    return num % MAX_TBL;
}
int main(void){
    // EmpInfo empArr[1000];
    EmpInfo em;
    em.empNum = 100;
    em.age = 20;

    // empArr[em.empNum] = em; //키를 근거로 데이터 저장
    // em = empArr[100] //키를 근거로 데이터 접근

    Table pt;
    int (*hf)(int num);
    hf = getHashKey;
    TBLInit(&pt,hf);
    TBLInsert(&pt,2020001,&em);
    VALUE s = TBLSearch(&pt,2020001);
    printf("%d",s->empNum);
    return 0;
}