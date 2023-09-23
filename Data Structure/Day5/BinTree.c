#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct NODE{
    char szData[64];
    struct NODE* left;
    struct NODE* right;
} NODE;

NODE* g_pRoot;
int g_nSize;

void ReleaseTree(NODE* pParent){
    if(pParent==NULL)
        return;
    //왼쪽 찍고, 내꺼 찍고 , 오른쪽 찍고
    ReleaseTree(pParent->left);
    ReleaseTree(pParent->right);
    printf("free(): %p,%s\n",pParent,pParent->szData);
    free(pParent);
    
    g_pRoot = NULL;
    g_nSize = 0;
    return;
}

void PrintTree(NODE* pParent){

    if(pParent==NULL)
        return;
    //왼쪽 찍고, 내꺼 찍고 , 오른쪽 찍고
    PrintTree(pParent->left);
    printf("[%p] %p, %s [%p]\n",
        pParent->left,pParent,
        pParent->szData,pParent->right);

    PrintTree(pParent->right);
    return;
}
int InsertNode(const char* pszData){ //point가 가리키는 부분을 읽기만 하지 쓰기는 안한다. so. const
    NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
    memset(pNewNode,0,sizeof(NODE));
    strcpy(pNewNode->szData,pszData);
    g_nSize++;
    if(g_pRoot == NULL){
        g_pRoot = pNewNode;
        return 1;
    }
    NODE* pTmp = g_pRoot;

    while (pTmp != NULL){
            //비교
            // 0 인경우는 생각 아직 안함.
        if(strcmp(pTmp->szData,pNewNode->szData) > 0){
            // 왼 쪽에서 오른쪽 뺴면 0보다 크면 szData가 더 작다는 얘기이다.
            //left
            if (pTmp->left == NULL){
                pTmp->left = pNewNode;
                break;
            }else{
                //기준이 바뀜
                pTmp = pTmp->left;
                continue;
            }
        }else{
            //right
            if (pTmp->right == NULL){
                pTmp->right = pNewNode;
                break;
            }else{
                pTmp = pTmp->right;
                continue;
            }
        }
    }
    return 1;
}


NODE* FindNode(const char* pszData){
    // 쉽게 구현할 수 있을 것 같다아아
    //선형 검색
    // NODE* pTmp = g_pHead->next; //head를 빼고 데이터 중
    // //while(pTmp !=g_pTail) 도 가능하다.
    // while(pTmp->next != NULL){
    //     if (strcmp(pTmp->szData,pszData)==0)
    //         return pTmp;
    //     pTmp = pTmp->next;

    // }
    return NULL;
}

int DeleteNode(const char* pszData){
    //차후 구현
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

int main(void){
    InsertNode("5번 항목");
    InsertNode("4번 항목");
    InsertNode("7번 항목");
    InsertNode("6번 항목");
    InsertNode("8번 항목");
    PrintTree(g_pRoot);
    ReleaseTree(g_pRoot);
    return 0;
}