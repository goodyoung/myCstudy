#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct NODE{
    char szData[64];
    struct NODE* prev;
    struct NODE* next;
} NODE;

NODE* g_pHead, *g_pTail;
int g_nSize;

void InitList(void){
    g_pHead = (NODE *)malloc(sizeof(NODE));
    g_pTail = (NODE *)malloc(sizeof(NODE));

    g_nSize = 0;


    memset(g_pHead,0,sizeof(NODE));
    memset(g_pTail,0,sizeof(NODE));
    strcpy(g_pHead->szData,"DUMMY HEAD");
    strcpy(g_pTail->szData,"DUMMY TAIL");
    g_pHead->next = g_pTail;
    g_pTail->prev = g_pHead;
}

void ReleaseList(void){
    NODE * pTmp = g_pHead;
    while(pTmp != NULL){
        NODE* pDelete = pTmp;
        pTmp = pTmp->next;
        printf("free(%p)\n",pDelete);
        free(pDelete);
    }
    g_pHead = NULL;
    g_pTail = NULL;
    g_nSize = 0;
    puts("ReleaseList()");
}

void PrintList(void){
    printf("PrintList(): g_nSize: %d, g_pHead [%p], g_pTail[%p]\n",g_nSize, g_pHead, g_pTail);
    NODE * pTmp = g_pHead;
    while(pTmp != NULL){
        printf("[%p] %p, %s [%p]\n",pTmp->prev,pTmp,pTmp->szData,pTmp->next);
        // printf("[%p] %s [%p]\n",pTmp->prev,pTmp->szData,pTmp->next);
        pTmp = pTmp->next;
    }
}
int InsertAtHead(const char* pszData){ //point가 가리키는 부분을 읽기만 하지 쓰기는 안한다. so. const
    NODE* pNewNode = (NODE*) malloc(sizeof(NODE));

    memset(pNewNode,0,sizeof(NODE));

    strcpy(pNewNode->szData,pszData);
    //새 노드에 대한 정의
    pNewNode->prev = g_pHead;
    pNewNode->next = g_pHead->next;

    //앞 전 노드에 대한 정의
    g_pHead->next = pNewNode;
    pNewNode->next->prev = pNewNode;
    // g_pHead->next->prev = pNewNode;

    g_nSize++;
    return g_nSize;
}

int InsertAtTail(const char* pszData){
    NODE* pNewNode = (NODE*) malloc(sizeof(NODE));

    memset(pNewNode,0,sizeof(NODE));

    strcpy(pNewNode->szData,pszData);
    //새 노드에 대한 정의
    pNewNode->next = g_pTail;
    pNewNode->prev = g_pTail->prev;

    //앞 전 노드에 대한 정의
    g_pTail->prev = pNewNode;
    pNewNode->prev->next = pNewNode;

    g_nSize++;
    return g_nSize;
}
NODE* FindNode(const char* pszData){
    NODE* pTmp = g_pHead->next; //head를 빼고 데이터 중
    //while(pTmp !=g_pTail) 도 가능하다.
    while(pTmp->next != NULL){
        if (strcmp(pTmp->szData,pszData)==0)
            return pTmp;
        pTmp = pTmp->next;

    }
    return NULL;
}

int DeleteNode(const char* pszData){

    NODE *pNode = FindNode(pszData);

    pNode->prev->next = pNode->next;
    pNode->next->prev = pNode->prev;

    printf("DeleteNode(): %p\n",pNode);

    free(pNode);
    g_nSize--; 
    return 0;
}
int GetSize(void){
    return g_nSize;
}


int GetLength(void){

    return GetSize();
}
int IsEmpty(void){
    return GetSize();
}


NODE * GetAt(int idx){
    NODE * pTmp = g_pHead->next;
    int count =0;
    while (pTmp->next != NULL ){
        if (idx==count){
            printf("GetAt(): %s\n",pTmp->szData);
            return pTmp;
            }
        pTmp = pTmp->next;
        count++;
    }
    return NULL;
}

int InsertAt(int idx,const char* pszData){
    //인덱스를 줘서 거기로 집어 넣어라
    NODE* pTmp = GetAt(idx);
    // printf("%p\n",pTmp);
    if (pTmp==NULL){
        printf("idx Error\n");
        return 0;
    }else{
        NODE* pNewNode = (NODE*) malloc(sizeof(NODE));
        memset(pNewNode,0,sizeof(NODE));
        strcpy(pNewNode->szData,pszData);

        // INSERT AT TAIL과 똑같이 작동한다
        pNewNode->prev = pTmp->prev;
        pNewNode->next = pTmp;

        pTmp->prev->next = pNewNode;
        pTmp->prev = pNewNode;
        printf("InsertAt(): %p %s\n",pNewNode,pNewNode->szData);
        
        return 1;
        
    }
    
}




int main(void){
    InitList();
    InsertAtHead("TEST01");
    InsertAtHead("TEST02");
    InsertAtHead("TEST03");

    InsertAt(0,"TEST AT 00");
    PrintList();
    InsertAt(2,"TEST AT 02");
    PrintList();
    InsertAt(4,"TEST AT 04");
    PrintList();
    InsertAt(10,"TEST AT 10");
    PrintList();
    NODE * pNode = GetAt(3);
    if (pNode)
        printf("GetAt(%d): %s\n",3,pNode->szData);
    printf("FindNode(): [%p]\n",FindNode("TEST01"));

    DeleteNode("TEST01");
    DeleteNode("TEST02");
    DeleteNode("TEST03");
    PrintList();
    ReleaseList();
    return 0;
}