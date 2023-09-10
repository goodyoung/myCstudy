#include <stdio.h>
#define MAX_LEN 6
typedef int Data;
typedef struct Queue{
    int front;
    int rear;
    Data queArr[MAX_LEN];
} Queue;


void Queueinit(Queue* pqueue){
    //서로 같은 곳을 바라보고 있다.
    pqueue->front = 0;
    pqueue->rear = 0;
}
int QisEmpty(Queue* pqueue){
    // front 와 rear가 같으면 비어있다.
    if (pqueue->front == pqueue->rear){
        return 1;
    }else
        return 0;
}
int NextIdx(int pos){
    if (pos == MAX_LEN -1){
        return 0; // 현재가 마지막이다.
    }
    else{
        return pos +1;
    }
}
void Enqueue(Queue* pqueue, Data data){
    printf("Enqueue!!\n");
    int next = NextIdx(pqueue->rear);
    if (next == pqueue->front){
        printf("Memory Full!!\n");
        return;
    }
    pqueue->rear = next;
    pqueue->queArr[pqueue->rear] = data;
    printf("Front: %d Rear: %d\n",pqueue->front, pqueue->rear);
}
Data Dequeue(Queue* pqueue){
    printf("Dequeue!!\n");
    if (QisEmpty(pqueue))
        return -1;
    pqueue->front = NextIdx(pqueue->front);
    Data data = pqueue->queArr[pqueue->front];
    return data;
}
void Qprint(Queue* pqueue){
    if (QisEmpty(pqueue))
        printf("Queue is Empty");
    else{
        int i = NextIdx(pqueue->front);
        while( i != NextIdx(pqueue->rear)){
            printf("%d ",pqueue->queArr[i]);
            i = NextIdx(i);
        }
    }
    putchar('\n');
}

int main(void){
    Queue queue;
    Queueinit(&queue);
    Enqueue(&queue,1);
    Enqueue(&queue,2);
    Enqueue(&queue,3);
    Enqueue(&queue,4);
    Dequeue(&queue);
    Enqueue(&queue,5);
    Qprint(&queue);
    Enqueue(&queue,6);
    Qprint(&queue);
    Dequeue(&queue);
    
    return 0;
}