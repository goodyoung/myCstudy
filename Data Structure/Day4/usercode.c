#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "mylist.c"

typedef struct USERDATA{
    //멤버 함수 포인터
    const char* (*GetKey)(void*);
    char szName[64]; // Key
    char szPhone[64];
}USERDATA;

const char* GetKeyFromUserData(USERDATA* pUser){
    return pUser->szName;
}

USERDATA* CreateUserData(const char* pszName, const char* pszPhone){
    USERDATA* pNewData = (USERDATA*)malloc(sizeof(USERDATA));
    memset(pNewData,0,sizeof(USERDATA));

    strcpy(pNewData->szName,pszName);
    strcpy(pNewData->szPhone,pszPhone);
    //구조체 멤버 함수 포인터 초기화
    pNewData->GetKey = GetKeyFromUserData;
    return pNewData;
}

void PrintList(LIST_INFO *pListData){
    printf("PrintList(): nSize: %d, pHead [%p], pTail[%p]\n",pListData->nSize, pListData->pHead, pListData->pTail);
    int i =0;
    NODE * pTmp = pListData->pHead;
    while(pTmp != NULL){
        if (pTmp == pListData->pHead || pTmp ==pListData->pTail)
        //puts("[Dummy]")
            printf("[%p] DUMMY [%p]\n",pTmp->prev,pTmp->next);
        //printf("[%p] %s [%p]\n",pTmp->prev,pTmp->szData,pTmp->next);
        else{
            USERDATA* pUser = pTmp->pData;
            printf("Index:%d %s\n",i,
            pUser->GetKey(pTmp->pData)); //데이터(예: USERDATA 구조체)를 가리키는 포인터를 인자로 받아
        i++;
        }
        pTmp = pTmp->next;
    }
    putchar('\n');
}
int main(void){
    LIST_INFO userList01 = {0};
    InitList(&userList01);
    USERDATA* pNewData = CreateUserData("CHS01","010-1234-1234");
    InsertAtHead(&userList01,pNewData);
    pNewData = CreateUserData("CHS02","010-1234-1234");
    InsertAtHead(&userList01,pNewData);
    pNewData = CreateUserData("CHS03","010-1234-1234");
    InsertAtHead(&userList01,pNewData);
    
    LIST_INFO userList02 = {0};
    InitList(&userList02);
    pNewData = CreateUserData("TEST01","010-1234-1234");
    InsertAtHead(&userList02,pNewData);
    pNewData = CreateUserData("TEST02","010-1234-1234");
    InsertAtHead(&userList02,pNewData);
    pNewData = CreateUserData("TEST03","010-1234-1234");
    InsertAtHead(&userList02,pNewData);

    PrintList(&userList01);
    PrintList(&userList02);

    ReleaseList(&userList01);
    ReleaseList(&userList02);    
    
    return 0;
}