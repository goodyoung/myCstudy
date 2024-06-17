#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Page 구조체 정의
typedef struct Page {
    int data;
    int page_number;
    int referenced;
    int modified;
    struct Page* next;
    struct Page* prev;
} Page;

// 이중 연결 리스트의 구조인 NRU 구조체 정의
typedef struct {
    Page* head;
    Page* tail;
    int capacity;
    int size;
} NRU;

// NRU 구조체 초기화 함수
void initNRU(NRU* list, int capacity) {
    list->head = NULL;
    list->tail = NULL;
    list->capacity = capacity;
    list->size = 0;
}

// NRU구조체에 특정 data가 있는지 체크
int NRU_checkTable(NRU* list, int pid, char* mode) {
    Page* current;
    current = list->head;// head pointer 가져오기

    while (current != NULL) {
        if (current->data == pid) {
            // NRU구조체에 data가 있다면
            
            // bit 변경
            if (strcmp(mode,"read") == 0){
                // mode가 read이면
                if (current->referenced == 0 && current->modified == 0)
                    current->referenced = 1;
                else if (current->referenced == 0 && current->modified == 1)
                    current->referenced = 1;                
            } else { // mode가 write이면
                if (current->referenced == 0 && current->modified == 0){
                    current->referenced = 1;
                    current->modified = 1;
                } else if (current->referenced == 0 && current->modified == 1){
                    current->referenced = 1;
                } else if (current->referenced == 1 && current->modified == 0){
                    current->modified = 1;
                }
            }

            // pysical frame에 data가 있다면 -> HIT -> LRU로 변경해야함
            

            Page* pTemp = current; // 현재 처리 중인 노드를 pTemp 포인터에 할당

            // 현재 데이터를 tail로 이동
            if ( pTemp != list->tail){ // 현재 page가 tail이 아니라면
                if (pTemp->prev != NULL)
                    pTemp->prev->next = pTemp->next; // 현재 노드의 이전 노드가 존재하면, 이전 노드의 next를 현재 노드의 next로 설정
                else
                    // 현재 노드(pTemp)가 리스트의 head 노드라면
                    list->head = pTemp->next;

                if (pTemp->next != NULL) {
                    pTemp->next->prev = pTemp->prev; // 현재 노드의 다음 노드가 존재하면, pTemp의 다음 노드의 prev를 현재 노드의 prev로 설정

                    list->tail->next = pTemp; // list의 tail 노드의 next를 현재 노드로 설정, 현재 노드를 맨 뒤에 붙이기
                    pTemp->prev = list->tail; // 현재 노드의 prev를 리스트의 tail 노드로 설정
                    pTemp->next = NULL; // 현재 노드가 tail이어서 현재 노드의 next를 NULL로 설정

                    list->tail = pTemp; // 리스트의 tail을 현재 노드로 변경
                }
            }
            return 1; // pysical frame에 data가 있다면 -> HIT
        }
        // NRU구조체에 data가 없다면
        current = current->next; // 다음 page로 이동
    }
    return 0; // pysical frame에 data가 없다면 -> FAULT
}

// Page의 class를 확인하는 함수
Page* checkClass(NRU* list){
    Page* current = list->head;
    int class0, class1, class2, class3;
    Page *pTemp_0 = NULL, *pTemp_1 = NULL, *pTemp_2 = NULL, *pTemp_3 = NULL; // 0,1,2,3 class를 반환하기 위한 Page 자료형 선언
    
    class0 = class1 = class2 = class3 = 0; // 변수 초기화

    while (current != NULL) {
        /*
        동일한 class의 Page가 여러개 일 때 LRU 이므로 head로 부터 scan하여
        각 class에 해당하면 class0,1,2,3의 flag를 두어 다음 번 scan에는 해당 class를 탐지 하지 않게 함
        */ 
        if (class0 && class1 && class2 && class3) // 값이 다 있으면
            break;
        if (!class0 && current->referenced == 0 && current->modified == 0){ // 0,0이면 class 0
            class0 = 1;
            pTemp_0 = current;
        } else if (!class1 && current->referenced == 0 && current->modified == 1){ // 0,1이면 class 1
            class1 = 1;
            pTemp_1 = current;
        } else if (!class2 && current->referenced == 1 && current->modified == 0){ // 1,0이면 class 2
            class2 = 1;
            pTemp_2 = current;
        } else if (!class3 && current->referenced == 1 && current->modified == 1){ // 1,1이면 class 3
            class3 = 1;
            pTemp_3 = current;
        }
        current = current->next;
    }
    
    // 0번 page가 evict하기에 제일 우선순위가 높음
    // 따라서 class 0번 부터 있으면 바로 해당 page 반환하기
    if (class0)
        return pTemp_0;
    else if (class1)
        return pTemp_1;
    else if (class2)
        return pTemp_2;
    else if (class3)
        return pTemp_3;
    else // 아무것도 없을 경우 (비어있을 때)
        return list->head; // NULL
    
}

// MISS 일 때
void NRU_Append(NRU* list, int pid, char * mode) {
    // 새로운 Page 생성
    Page* newPage = (Page*)malloc(sizeof(Page));
    if (newPage == NULL) { printf("Memory allocation failed\n"); return; }
    // 새로운 Page 값 초기화
    newPage->data = pid;
    newPage->next = NULL;
    newPage->prev = NULL;
    newPage->referenced = 0; // referenced 0으로 초기화

    if (strcmp(mode,"read") == 0) // mode가 read이면 modified bit를 0으로 초기화
        newPage->modified = 0;
    else // write이면 modified bit를 1으로 초기화
        newPage->modified = 1;

    if (list->size == list->capacity) {
        // FULL 일 경우
        // class 체크
        Page* pTemp = checkClass(list); // list에서 class가 가장 작은 것을 가져온다.

        // pTemp 페이지를 리스트에서 제거
        if (pTemp->prev)
            // 이전 페이지의 다음 포인터를 pTemp의 다음 페이지로 설정
            pTemp->prev->next = pTemp->next; 
        else 
            // pTemp가 리스트의 헤드일 경우
            // 리스트의 헤드를 pTemp의 다음 페이지로 설정
            list->head = pTemp->next;
        
        if (pTemp->next) 
            // 다음 페이지의 이전 포인터를 pTemp의 이전 페이지로 설정
            pTemp->next->prev = pTemp->prev;
        else
            // 리스트의 꼬리를 pTemp의 이전 페이지로 설정
            list->tail = pTemp->prev;

        // 새 Page LRU에 맞게 맨 뒤로 붙이기
        list->tail->next = newPage;
        newPage->prev = list->tail;
        newPage->next = NULL;
        list->tail = newPage;

        free(pTemp); // 메모리 해제
    }else{
        // FULL이 아니면
        // list의 맨 뒤에 붙이기
        if (list->head == NULL) {
            // 리스트가 비어있을 경우
            list->head = newPage;
            list->tail = newPage;
        } else {
            // 리스트가 비어있지 않은 경우
            newPage->prev = list->tail; // newPage 연결
            list->tail->next = newPage; // tail 뒤에 부착
            list->tail = newPage; // tail pointer를 newPage로 이동
        }
        list->size++; // 사이즈 증가
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