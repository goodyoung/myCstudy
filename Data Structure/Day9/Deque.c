#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Data;
typedef struct Node{
    Data data;
    struct Node * prev_;
    struct Node * next_;
}Node;
typedef struct Deque{
    Node* head;
    Node* tail;
}Deque;
void DequeInit(Deque * pdeque){
    pdeque->head = NULL;
    pdeque->tail = NULL;
}
int IsEmpty(Deque * pdeque){
    if (pdeque->head == NULL)
        return 1;
    else
        return 0;
}

void Headqueue(Deque * pdeque,Data data){
    Node *pTmp = (Node*) malloc(sizeof(Node));
    memset(pTmp,0,sizeof(Node));
    pTmp -> data = data;

    
    pTmp->next_ = pdeque->head;
    pTmp->prev_ = NULL;

    if (IsEmpty(pdeque)){    
        pdeque->tail = pTmp;
    }else{
        pdeque->head->prev_ = pTmp;
    }    
    pdeque->head = pTmp;
}

void Tailqueue(Deque * pdeque,Data data){
    Node *pTmp = (Node*) malloc(sizeof(Node));
    memset(pTmp,0,sizeof(Node));
    pTmp -> data = data;
    pTmp->prev_ = pdeque->tail;
    pTmp->next_ = NULL;
    if (IsEmpty(pdeque))
        pdeque->head = pTmp;
    else{
        pdeque->tail->next_ = pTmp;
    }
    pdeque->tail = pTmp;
}
Data HeadDequeue(Deque* pdeque){
    if (IsEmpty(pdeque))
        return -1;
    Node* pTmp = pdeque->head;
    Data pData = pTmp->data;
    pdeque->head = pdeque->head->next_;
    free(pTmp);
    if (IsEmpty(pdeque)){
        pdeque->tail = NULL;
    }else{
        pdeque->head->prev_ = NULL;
    }
    return pData;
}
Data TailDequeue(Deque* pdeque){
    if (IsEmpty(pdeque))
        return -1;
    Node* pTmp = pdeque->tail;
    Data pData = pTmp->data;
    pdeque->tail = pdeque->tail->prev_;
    free(pTmp);
    if (IsEmpty(pdeque)){
        pdeque->head = NULL;
    }else{
        pdeque->tail->next_ = NULL;
    }
    return pData;
}
void PrintDeque(Deque* pdeque){
    if (IsEmpty(pdeque)){
        printf("Deque is Empty!!\n");
        return;
    }
    Node * pTmp;
    pTmp = pdeque->head;
    while(pTmp != NULL){
        printf("%d ",pTmp->data);
        pTmp = pTmp->next_;
    }
    puts("\n");
}
int main(void){
    Deque deque;
    DequeInit(&deque);
    Headqueue(&deque,1);
    Headqueue(&deque,2);
    Tailqueue(&deque,4);
    PrintDeque(&deque);
    Tailqueue(&deque,3);
    Tailqueue(&deque,4);

    Headqueue(&deque,2);
    Headqueue(&deque,3);
    PrintDeque(&deque);
}