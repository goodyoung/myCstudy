#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 노드 구조체 정의
typedef struct Page {
    int data;
    int page_number;
    int referenced;
    int modified;
    struct Page* next;
    struct Page* prev;
} Page;

// 이중 연결 리스트 구조체 정의
typedef struct {
    Page* head;
    Page* tail;
    int capacity;
    int size;
} NRU;

// 이중 연결 리스트 초기화 함수
void initNRU(NRU* list, int capacity) {
    list->head = NULL;
    list->tail = NULL;
    list->capacity = capacity;
    list->size = 0;
}

// 이중 연결 리스트 출력 함수
void printDoublyLinkedList(NRU* list) {
    Page* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n\n---------------------------------\n\n");
}

// data있는지 체크
int NRU_checkTable(NRU* list, int pid, char* mode) {
    Page* current;
    
    current = list->head;
    while (current != NULL) {
        if (current->data == pid) {
            
            Page* pTemp = current;

            // Bit 변경
            if (strcmp(mode,"read") == 0){
                if (current->referenced == 0 && current->modified == 0)
                    current->referenced = 1;
                else if (current->referenced == 0 && current->modified == 1)
                    current->referenced = 1;
                
            }else{ // write
                if (current->referenced == 0 && current->modified == 0){
                    current->referenced = 1;
                    current->modified = 1;
                } else if (current->referenced == 0 && current->modified == 1){
                    current->referenced = 1;
                } else if (current->referenced == 1 && current->modified == 0){
                    current->modified = 1;
                }
            }

            // Table에 data가 있다면 -> HIT -> LRU로 변경해야함
            // 현재 데이터 tail로 이동
            if ( pTemp != list->tail){
                if (pTemp->prev != NULL) {
                    pTemp->prev->next = pTemp->next;
                } else {
                    // pTemp가 head인 경우
                    list->head = pTemp->next;
                }
                if (pTemp->next != NULL) {
                    pTemp->next->prev = pTemp->prev;

                    list->tail->next = pTemp;
                    pTemp->prev = list->tail;
                    pTemp->next = NULL;

                    list->tail = pTemp;
                }
            }
            return 1; 
        }
        current = current->next;
    }
    return 0; // Table에 data가 없다면 -> FAULT
}
Page* checkClass(NRU* list){
    Page* current = list->head;
    int class0, class1, class2, class3;
    Page *pTemp_0 = NULL, *pTemp_1 = NULL, *pTemp_2 = NULL, *pTemp_3 = NULL;
    
    class0 = class1 = class2 = class3 = 0;

    while (current != NULL) {
        // 동일한 class의 Page가 여러개 일 때 LRU 이므로 
        // if (class0 && class1 && class2 && class3) // 값이 다 있으면
        //     break;
        if (!class0 && current->referenced == 0 && current->modified == 0){
            class0 = 1;
            pTemp_0 = current;
        } else if (!class1 && current->referenced == 0 && current->modified == 1){
            class1 = 1;
            pTemp_1 = current;
        } else if (!class2 && current->referenced == 1 && current->modified == 0){
            class2 = 1;
            pTemp_2 = current;
        } else if (!class3 && current->referenced == 1 && current->modified == 1){
            class3 = 1;
            pTemp_3 = current;
        }
        current = current->next;
    }
    if (class0){
        return pTemp_0;
    }else if (class1){
        return pTemp_1;
    }else if (class2){
        return pTemp_2;
    }else if (class3){
        return pTemp_3;
    }else{ // 아무것도 없을 경우 (비어있을 때)
        return list->head; // NULL
    }
}

// 이중 연결 리스트 출력 함수
void NRU_Append(NRU* list, int pid, char * mode) {
    // 새로운 Node 생성
    Page* newNode = (Page*)malloc(sizeof(Page));
    if (newNode == NULL) { printf("Memory allocation failed\n"); return; }
    newNode->data = pid;
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->referenced = 0;
    if (strcmp(mode,"read") == 0)
        newNode->modified = 0;
    else
        newNode->modified = 1;

    Page* current = list->head;

    if (list->size == list->capacity) {
        // FULL 일 경우
        // class 체크
        Page* pTemp = checkClass(list); // class가 가장 작은 것을 가져온다.
        // printf("NRU %d REF: %d %d\n",pTemp->data, pTemp->referenced, pTemp->referenced);
        // printf("HEAD REF %d %d\n",list->head->referenced, list->head->referenced);
        if (pTemp->prev) {
            pTemp->prev->next = pTemp->next;
        } else {
            list->head = pTemp->next;
        }
        if (pTemp->next) {
            pTemp->next->prev = pTemp->prev;
        } else{
            list->tail = pTemp->prev;
        }

        // 새 노드 LRU에 맞게 맨 뒤로 붙이기
        list->tail->next = newNode;
        newNode->prev = list->tail;
        newNode->next = NULL;
        list->tail = newNode;

        free(pTemp); // 메모리 해제
    }else{
        // 뒤에 붙이기
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
}

void freeNRU(NRU *list) {
    // 리스트가 비어있을 경우
    if (list == NULL) return;
    // 리스트에서 노드를 하나씩 해제
    Page *current = list->head;
    while (current != NULL) {
        Page *temp = current;
        current = current->next;
        free(temp); // 각 노드 메모리 해제
    }
}