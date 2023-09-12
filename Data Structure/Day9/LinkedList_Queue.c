#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Data;
typedef struct Node{
    Data data;
    struct Node * next_;
}Node;
typedef struct Queue{
    Node * front;
    Node * rear;
}Queue;

void Queueinit(Queue* pqueue){
    pqueue->front = NULL;
    pqueue->rear = NULL;
}
int QisEmpty(Queue* pqueue){
    if (pqueue->front == NULL)
        return 1;
    else
        return 0;
}
void Enqueue(Queue* pqueue, Data rdata){
    Node *pNode = (Node*) malloc(sizeof(Node));
    memset(pNode,0,sizeof(Node));
    pNode->next_ = NULL;
    pNode->data = rdata;
    // strcpy(pNode->data, data);
    if (QisEmpty(pqueue)){
        pqueue->front = pNode;
        pqueue->rear = pNode;
    }else{
        pqueue->rear->next_ = pNode;
        pqueue->rear = pNode;
    }
}
Data Dequeue(Queue* pqueue){
    Node* pdata;
    Data real_data;
    if (QisEmpty(pqueue)){
        printf("Q Memory is Full!\n");
        return -1;
    }

    pdata = pqueue->front;
    real_data = pdata->data;
    pqueue->front = pqueue->front->next_;
    printf("DeQueue: %d\n",real_data);
    free(pdata);
    return real_data;
}
void PrintQ(Queue* pqueue){
    if (QisEmpty(pqueue)){
        printf("Q is Empty!!\n");
        return;
    }
    // Node *pTmp = (Node*) malloc(sizeof(Node));
    // memset(pTmp,0,sizeof(Node));
    Node * pTmp = pqueue->front;

    while(pTmp != NULL){
        printf("PrintList(): %d \n",pTmp->data);
        pTmp = pTmp->next_;
    }
}
int main(void){
    Queue q;
    // Data data;
    Queueinit(&q);
    Enqueue(&q,1);
    Enqueue(&q,2);
    Enqueue(&q,3);
    PrintQ(&q);
    Enqueue(&q,3);
    Dequeue(&q);
    PrintQ(&q);
    return 0;
}