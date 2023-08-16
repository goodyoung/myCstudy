#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//함수 원형 선언!!
int InsertAtHead(void* pParam);
int InsertAtTail(void* pParam);

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


typedef struct NODE{

    //관리 대상 자료
    // char szData[64]; //이걸 가지고 관리 하겠다.
    void* pData;
    
    
    
    //이 GetKey함수를 USERDATA에 옮기는게 나을까?

    //자료구조
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
    // strcpy(g_pHead->szData,"DUMMY HEAD");
    // strcpy(g_pTail->szData,"DUMMY TAIL");
    g_pHead->next = g_pTail;
    g_pTail->prev = g_pHead;
}

void ReleaseList(void){
    NODE * pTmp = g_pHead;
    while(pTmp != NULL){
        NODE* pDelete = pTmp;
        pTmp = pTmp->next;
        printf("free(%p)\n",pDelete);

        free(pDelete->pData);
        free(pDelete);
    }
    g_pHead = NULL;
    g_pTail = NULL;
    g_nSize = 0;
    puts("ReleaseList()");
}

void PrintList(void){
    printf("PrintList(): g_nSize: %d, g_pHead [%p], g_pTail[%p]\n",g_nSize, g_pHead, g_pTail);
    int i =0;
    NODE * pTmp = g_pHead;
    while(pTmp != NULL){
        if (pTmp == g_pHead || pTmp ==g_pTail)
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
//pParam: 호출자가 메모리를 동적 할당 + 값 설정까지 해서 전달
int InsertAtHead(void* pParam){ //void로 뭔가 넘어온다.
    NODE* pNewNode = (NODE*) malloc(sizeof(NODE));
    memset(pNewNode,0,sizeof(NODE));

    //관리 대상 자료에 관한 초기화
    pNewNode->pData = pParam;

    
    //새 노드에 대한 정의
    //연결 리스트에 관한 초기화
    pNewNode->prev = g_pHead;
    pNewNode->next = g_pHead->next;

    //앞 전 노드에 대한 정의
    g_pHead->next = pNewNode;
    pNewNode->next->prev = pNewNode;
    // g_pHead->next->prev = pNewNode;

    g_nSize++;
    return g_nSize;
}

int InsertAtTail(void* pParam){
    NODE* pNewNode = (NODE*) malloc(sizeof(NODE));
    memset(pNewNode,0,sizeof(NODE));

    pNewNode->pData = pParam;


    // strcpy(pNewNode->szData,pszData);
    //새 노드에 대한 정의
    pNewNode->next = g_pTail;
    pNewNode->prev = g_pTail->prev;

    //앞 전 노드에 대한 정의
    g_pTail->prev = pNewNode;
    pNewNode->prev->next = pNewNode;

    g_nSize++;
    return g_nSize;
}
NODE* FindNode(const char* pszKey){
    NODE* pTmp = g_pHead->next; //head를 빼고 데이터 중
    const char* (*pfGetKey)(void*) = NULL; 
    //while(pTmp !=g_pTail) 도 가능하다.
    while(pTmp->next != NULL){
        pfGetKey = pTmp->pData; 
        // pData는 USERDATA를 가리키고 있다.
        if (strcmp(pfGetKey(pTmp->pData),pszKey)==0) 
                        //특정 자료에 의존성이 있는 어떤 자료에 직접 접근하는 것이 아니라
                        //GetKey가 GetKeyFromUserData으로 초기화 되었다고 가정한다면 pData의 이름을 반환한다.
                        //어떤 오브젝트에 대한 주소를 집어 넣어서 그것의 멤버 접근.
                        //cpp의 dispointer : 객체 자신을 가리키는 포인터

            return pTmp;
        pTmp = pTmp->next;

    }
    return NULL;
}

int DeleteNode(const char* pszKey){

    NODE *pNode = FindNode(pszKey);

    pNode->prev->next = pNode->next;
    pNode->next->prev = pNode->prev;

    printf("DeleteNode(): %p\n",pNode);
    
    free(pNode->pData);
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
            // printf("GetAt(): %s\n",pTmp->pData->szName);
            return pTmp;
            }
        pTmp = pTmp->next;
        count++;
    }
    return NULL;
}

int InsertAt(int idx,void* pParam ){
    //인덱스를 줘서 거기로 집어 넣어라
    NODE* pTmp = GetAt(idx);
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
        // printf("InsertAt(): %p %s\n",pNewNode,pNewNode->pParam);
        
        return 1;
    }
    
}




int main(void){
    InitList();
    USERDATA* pNewData = NULL;
    pNewData = CreateUserData("Ho-sung","010-1234-1234");
    // 이 Create함수를 호출하면 UserData구조체에 정보를 넣어줌과 동시에 그게 객체화 되어서 만들어져서 구조체 데이터 덩어리가 리턴된다.
    // 그래서 메인함수에선 연결리스트 부분, USERDATA 구조체 인스턴스 관리하는 부분하고 
    // 이 두가지를 합성하여 관리체계를 main함수에서 관리하도록 한다.
    InsertAtHead(pNewData);
    pNewData = CreateUserData("Test","010-1111-1124");
    InsertAtHead(pNewData);

    PrintList();
    ReleaseList();
    return 0;
}