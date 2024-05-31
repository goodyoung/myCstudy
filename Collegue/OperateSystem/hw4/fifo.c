#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// 이중 연결 리스트 구조체 정의
typedef struct {
    Node* head;
    Node* tail;
    int capacity;
    int size;
} FIFO;

// 이중 연결 리스트 초기화 함수
void initFIFO(FIFO* list, int capacity) {
    list->head = NULL;
    list->tail = NULL;
    list->capacity = capacity;
    list->size = 0;
}

// 이중 연결 리스트에서 맨 앞 노드를 제거하는 함수
void FIFO_FrontPop(FIFO* list) {
    // 리스트가 비어있는 경우
    if (list->head == NULL) {
        printf("List is empty, cannot pop %d\n",list->capacity);
        return; // 노드가 없으므로 -1 반환
    }

    // 맨 앞 노드와 그 다음 노드 찾기
    Node* firstNode = list->head;
    Node* nextNode = firstNode->next;

    // 리스트에서 노드 제거
    if (nextNode != NULL) {
        nextNode->prev = NULL;
        list->head = nextNode;
    } else {
        // 리스트에 노드가 하나만 있을 때
        list->head = NULL;
        list->tail = NULL;
    }

    free(firstNode); // 노드 메모리 해제
    list->size--; // 리스트 크기 감소
    return; 
}

// MISS 일 때 
void FIFO_Append(FIFO* list, int data) {
    if (list->size == list->capacity) {
        // FULL 일 경우

        FIFO_FrontPop(list);
    }
    // 맨 앞 제거 후 뒤에 넣기
    // 새로운 Node 생성
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) { printf("Memory allocation failed\n"); return; }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (list->head == NULL) {
        // 리스트가 비어있을 경우
        list->head = newNode;
        list->tail = newNode;
    } else {
        // 리스트가 비어있지 않은 경우
        newNode->prev = list->tail; // newNode 연결
        list->tail->next = newNode; // tail 뒤에 부착
        list->tail = newNode;
    }
    list->size++;
}

int FIFO_CheckTable(FIFO* list, int pid) {
    if (list->size == 0) // 리스트가 비어있다면
        return 0;
    Node* current;
    for (current = list->head; current != NULL; current = current->next) {
        if (current->data == pid) {
            return 1; // Table에 data가 있다면
        }
    }
    return 0; // Table에 data가 없다면
}
