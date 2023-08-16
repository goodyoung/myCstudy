#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "mylist.h"


void InitList(LIST_INFO *pListData){
    pListData->pHead = (NODE *)malloc(sizeof(NODE));
    pListData->pTail = (NODE *)malloc(sizeof(NODE));

    pListData->nSize = 0;

    memset(pListData->pHead,0,sizeof(NODE));
    memset(pListData->pTail,0,sizeof(NODE));
     
    //과거에는 g_pHead->next = g_pTail;
    pListData->pHead->next = pListData->pTail;
    pListData->pTail->prev = pListData->pHead;
}
void ReleaseList(LIST_INFO *pListData){
    NODE * pTmp = pListData->pHead;
    while(pTmp != NULL){
        NODE* pDelete = pTmp;
        pTmp = pTmp->next;
        printf("free(%p)\n",pDelete);

        free(pDelete->pData);
        free(pDelete);
    }
    pListData->pHead = NULL;
    pListData->pTail = NULL;
    pListData->nSize = 0;
    puts("ReleaseList()");
}

int InsertAtHead(LIST_INFO *pListData,void* pParam){ //void로 뭔가 넘어온다.
    NODE* pNewNode = (NODE*) malloc(sizeof(NODE));
    memset(pNewNode,0,sizeof(NODE));

    //관리 대상 자료에 관한 초기화
    pNewNode->pData = pParam;

    
    //새 노드에 대한 정의
    //연결 리스트에 관한 초기화
    pNewNode->prev = pListData->pHead;
    pNewNode->next = pListData->pHead->next;

    //앞 전 노드에 대한 정의
    pListData->pHead->next = pNewNode;
    pNewNode->next->prev = pNewNode;

    pListData->nSize++;
    return pListData->nSize;
}

int InsertAtTail(LIST_INFO *pListData,void* pParam){
    NODE* pNewNode = (NODE*) malloc(sizeof(NODE));
    memset(pNewNode,0,sizeof(NODE));

    pNewNode->pData = pParam;

    //새 노드에 대한 정의
    pNewNode->next = pListData->pTail;
    pNewNode->prev = pListData->pTail->prev;

    //앞 전 노드에 대한 정의
    pListData->pTail->prev = pNewNode;
    pNewNode->prev->next = pNewNode;

    pListData->nSize++;
    return pListData->nSize;
} 
NODE* FindNode(LIST_INFO *pListData,const char* pszKey){
    NODE* pTmp = pListData->pHead->next; //head를 빼고 데이터 중
    const char* (*pfGetKey)(void*) = NULL; 
    //while(pTmp !=g_pTail) 도 가능하다.
    while(pTmp->next != NULL){
        pfGetKey = pTmp->pData; 
        // pData는 USERDATA를 가리키고 있다.
        if (strcmp(pfGetKey(pTmp->pData),pszKey)==0)
            return pTmp;
        pTmp = pTmp->next;

    }
    return NULL;
}

int DeleteNode(LIST_INFO *pListData,const char* pszKey){

    NODE *pNode = FindNode(pListData,pszKey);

    pNode->prev->next = pNode->next;
    pNode->next->prev = pNode->prev;

    printf("DeleteNode(): %p\n",pNode);
    
    free(pNode->pData);
    free(pNode);
    pListData->nSize--; 
    return 0;
}
int GetSize(LIST_INFO *pListData){
    return pListData->nSize;
}


int GetLength(LIST_INFO *pListData){

    return GetSize(pListData);
}
int IsEmpty(LIST_INFO *pListData){
    return GetSize(pListData);
}


NODE * GetAt(LIST_INFO *pListData,int idx){
    NODE * pTmp = pListData->pHead->next;
    int count =0;
    while (pTmp->next != NULL ){
        if (idx==count){
            // printf("GetAt(): %s\n",pTmp->pData->szName);
            return pTmp;
            }
        pTmp = pTmp->next;
        count++;
    }
    return NULL;
}

int InsertAt(LIST_INFO *pListData,int idx,void* pParam ){
    //인덱스를 줘서 거기로 집어 넣어라
    NODE* pTmp = GetAt(pListData,idx);
    // printf("%p\n",pTmp);
    if (pTmp==NULL){
        printf("idx Error\n");
        return 0;
    }else{
        NODE* pNewNode = (NODE*) malloc(sizeof(NODE));
        memset(pNewNode,0,sizeof(NODE));
        // strcpy(pNewNode->szData,pszData);

        pNewNode->pData = pParam;
        // INSERT AT TAIL과 똑같이 작동한다
        pNewNode->prev = pTmp->prev;
        pNewNode->next = pTmp;

        pTmp->prev->next = pNewNode;
        pTmp->prev = pNewNode;
        return 1;
    }   
}