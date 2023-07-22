#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct NODE{
    char szData[64];
    struct NODE * next;
} NODE;
NODE g_head={0}; //더미 노드 생성  ///동적 할당으로 해줄 수도 있다.

int IsEmpty(){
    if (g_head.next == NULL)
        return 1;
    return 0;
}
void PrintList(void){
    NODE* p_Head = g_head.next; // g_pHead만 놓으면 g_pHeadnext는 무조건 NULL이며 스택이 아니다.;
    while(p_Head != NULL){
        printf("[%p] %s,next[%p]\n",p_Head,p_Head->szData,p_Head->next);
        p_Head = p_Head->next;
    }
    putchar('\n');
}
//새 노드 추가
int InsertAtHead(char* pszData){
    //새로운 노드 생성
    NODE* pNode = (NODE*)malloc(sizeof(NODE));
    memset(pNode,0,sizeof(NODE)); //메모리 초기화
    strcpy(pNode->szData,pszData);

    if (IsEmpty())
        g_head.next = pNode;
    else{
        pNode->next = g_head.next;
        g_head.next = pNode;
    }
    return 1;
}
int InsertAtTail(char* pszData){
    NODE* pTmp = &g_head;
    while(pTmp->next !=NULL)
        pTmp = pTmp ->next;
    //새로운 노드 생성
    NODE* pNode = (NODE*)malloc(sizeof(NODE));
    memset(pNode,0,sizeof(NODE)); //메모리 초기화
    strcpy(pNode->szData,pszData);
    pTmp->next = pNode;
    return 1;
}


void ReleaseList(void){
    printf("\nReleaseList()\n");
    NODE *pTmp = g_head.next;
    while (pTmp != NULL){
        NODE* pDelete = pTmp;
        pTmp = pTmp->next;
        printf("Delete: [%p] %s\n",pDelete,pDelete->szData);
        free(pDelete);
    }
    g_head.next = 0; //메모리가 할당되고 초기화를 안해주었기 때문에 쓰레기 값을 가지게 된다.
}
NODE* FindData(char* pszData){
    NODE* pCur = g_head.next;
    NODE* pPrev = &g_head;
    while(pCur != NULL){
        //찾은 노드의 앞 노드 주소를 반환한다.
        //더미 헤드가 존재하기 때문에 이렇게 해도 문제가 없다.
        if(strcmp(pCur->szData,pszData)==0){
            return pPrev;
        }
        pCur = pCur->next;
        pPrev = pPrev->next;
    }
    return 0;
}
int DeleteData(char* pszData){
    NODE* pPrev = FindData(pszData);
    if (pPrev != 0){
        NODE* pDelete = pPrev->next;
        pPrev->next = pDelete->next;        
        printf("DeleteData(): %s\n",pDelete->szData);
        free(pDelete);
        return 1;
    }
    return 0;
}

int main(void){
    InsertAtHead("TEST01");
    InsertAtHead("TEST02");
    InsertAtHead("TEST03");
    PrintList();

    // ReleaseList();
    DeleteData("TEST01");
    PrintList();
    DeleteData("TEST02");
    PrintList();
    DeleteData("TEST03");
    PrintList();

    puts("*** InsertAtTail() ***");
    InsertAtTail("TEST01");
    InsertAtTail("TEST02");
    InsertAtTail("TEST03");
    PrintList();
    ReleaseList();
    puts("*** PrintList() ***");
    PrintList();
    return 0;
}