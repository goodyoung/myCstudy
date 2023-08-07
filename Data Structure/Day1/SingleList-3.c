#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct NODE{
    char szData[64];
    struct NODE * next;
} NODE;
NODE g_head={0}; //더미 노드 생성  ///동적 할당으로 해줄 수도 있다.
NODE* g_pTail = 0; //tail 포인터
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

    if (IsEmpty()){
        //리스트에 추가된 첫 번째 데이터 처리
        g_head.next = pNode;
        g_pTail = pNode;
    }
    else{
        pNode->next = g_head.next;
        g_head.next = pNode;
    }
    return 1;
}
int InsertAtTail(char* pszData){
    //새로운 노드 생성
    NODE* pNode = (NODE*)malloc(sizeof(NODE));
    memset(pNode,0,sizeof(NODE)); //메모리 초기화
    strcpy(pNode->szData,pszData);
    if (IsEmpty())
        //리스트에 추가된 첫 번째 데이터 처리
        g_head.next = pNode;
    else
        g_pTail->next = pNode; //마지막 노드가 가리키고 있는 값을 변경

    g_pTail = pNode;
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
    g_pTail = 0;
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

        if (pDelete == g_pTail)
            g_pTail = 0;
        free(pDelete);
        return 1;
    }
    return 0;
}
void PushData(char *pszData){
    InsertAtHead(pszData);
}
int PopData(NODE* pPopNode){
    NODE* sp = g_head.next;
    if (IsEmpty())
        return 0;
    memcpy(pPopNode, sp,sizeof(NODE)); //메모리 카피
    g_head.next = sp->next;
    free(sp);
    return 0;
}
void Enqueue(char* pszData){
    InsertAtTail(pszData);
}
int Dequeue(NODE* pPopdata){
    NODE* sp = g_head.next;
    if (IsEmpty())
        return 0;
    memcpy(pPopdata, sp,sizeof(NODE)); //메모리 카피
    g_head.next = sp->next;
    free(sp);
    return 1;
}
int main(void){
    printf("%p\n",&g_head);
    printf("%p\n",g_head.next);
    printf("%s\n",g_head.szData);
    // InsertAtHead("TEST01");
    // InsertAtHead("TEST02");
    // InsertAtHead("TEST03");
    // PrintList();

    // // ReleaseList();
    // DeleteData("TEST01");
    // PrintList();
    // DeleteData("TEST02");
    // PrintList();
    // DeleteData("TEST03");
    // PrintList();

    // puts("*** InsertAtTail() ***");
    // InsertAtTail("TEST01");
    // InsertAtTail("TEST02");
    // InsertAtTail("TEST03");
    // PrintList();
    // ReleaseList();
    // puts("*** PrintList() ***");
    // PrintList();
    //Stack 테스트를 위한 코드;
    printf("*** STACK ***\n");
    PushData("TEST01");
    PushData("TEST02");
    PushData("TEST03");
    NODE s_node = {0};
    PopData(&s_node);
    printf("Pop: %s\n",s_node.szData);
    PopData(&s_node);
    printf("Pop: %s\n",s_node.szData);
    PopData(&s_node);
    printf("Pop: %s\n",s_node.szData);
    //Queue 테스트를 위한 코드
    printf("*** Queue ***\n");
    Enqueue("TEST01");
    Enqueue("TEST02");
    Enqueue("TEST03");
    NODE q_node = {0};
    Dequeue(&q_node);
    printf("Pop: %s\n",q_node.szData);
    Dequeue(&q_node);
    printf("Pop: %s\n",q_node.szData);
    Dequeue(&q_node);
    printf("Pop: %s\n",q_node.szData);

    if (Dequeue(&q_node)==0)
        puts("Empty");
    
    Enqueue("TEST01");
    Enqueue("TEST02");
    Enqueue("TEST03");
    PrintList();
    ReleaseList();
    return 0;
}