#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct NODE{
    char szData[64];
    struct NODE * next;
} NODE;

NODE* g_pHead = NULL; //g_는 전역변수 이다를 의도적으로 표시.

// 연결 리스트 전체 데이터 출력
void PrintList(void){
    NODE* p_Head = g_pHead; // g_pHead만 놓으면 g_pHeadnext는 무조건 NULL이며 스택이 아니다.;
    while(p_Head != NULL){
        printf("[%p] %s,next[%p]\n",p_Head,p_Head->szData,p_Head->next);
        p_Head = p_Head->next;
    }
    putchar('\n');
}
//새 노드 추가
int InsertNexNode(char* pszData){
    //새로운 노드 생성
    NODE* pNode = (NODE*)malloc(sizeof(NODE));
    memset(pNode,0,sizeof(NODE)); //메모리 초기화
    strcpy(pNode->szData,pszData);
    // strcpy_s(pNode->szData,sizeof(pNode->szData),pszData);

    // 노드 가리키기
    if (g_pHead==NULL){
        
        g_pHead = pNode;
    }else{
        pNode->next = g_pHead; //기존 g_pHead가 가리키고 있는 주소
        g_pHead = pNode; //g_pHead가 다시 pnode를 가리켜서 insert성공
        //그림을 확인하며 한다.
    }
    return 1;
}
void ReleaseList(void){
    NODE *pTmp = g_pHead;
    while (pTmp != NULL){
        printf("전역변수 : %p\n",g_pHead);
        NODE* pDelete = pTmp;
        pTmp = pTmp->next;
        printf("Delete: [%p] %s\n",pDelete,pDelete->szData);
        free(pDelete);
    }
}



int FindData(char* pszData){
    NODE* pTmp = g_pHead;
    while(pTmp != NULL){
        if(strcmp(pTmp->szData,pszData)==0){
            return 1;
        }
        pTmp = pTmp->next;
    }
    return 0;
}
int DeleteData(char* pszData){
    NODE* pTmp = g_pHead;
    NODE* pPrev= NULL;
    while(pTmp != NULL){
        if(strcmp(pTmp->szData,pszData)==0){
            //삭제가 일어난다.
            printf("DeleteData(): %s\n",pTmp->szData);
            if (pPrev != NULL){
                pPrev->next = pTmp->next;
            }else{
                //삭제할 데이터가 첫 번째
                g_pHead = pTmp->next;    
            }

            free(pTmp);
            return 1;
        }
        pPrev = pTmp;
        pTmp = pTmp->next;
    }
    return 0;
}
int main(void){
    //List 테스트를 위한 코드
    InsertNexNode("TEST01");
    PrintList();
    InsertNexNode("TEST02");
    PrintList();
    InsertNexNode("TEST03");
    PrintList();

    if (FindData("TEST01")==1)
        printf("FindData(): TEST01 found\n");
    if (FindData("TEST02")==1)
        printf("FindData(): TEST02 found\n");
    if (FindData("TEST03")==1)
        printf("FindData(): TEST03 found\n");
    
    DeleteData("TEST01");
    DeleteData("TEST03");
    
    // ReleaseList();
    PrintList();
    return 0;
}