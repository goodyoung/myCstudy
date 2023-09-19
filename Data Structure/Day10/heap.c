#include <stdio.h>
#define HeapLen 10
typedef char HData;
typedef int Priority;
typedef struct HeapElem{ //우선순위 큐와 관련이 있는 구조체
    Priority pr; // 값이 작을수록 높은 우선순위라고 구현
    HData data;
}HeapElem;
typedef struct Heap{ //힙을 나타내는 구조체
    int numofData; //힙의 개수는 마지막 노드의 번호와 같다.
    HeapElem heapArr[HeapLen];
}Heap;
void HeapInit(Heap * ph){
    ph->numofData = 0;
}
int isEmpty(Heap * ph){
    if (ph->numofData ==0)
        return 1;
    else
        return 0;
}
int getParentIdx(int idx){
    return idx /2 ;
}
int getLeftChildIdx(int idx){
    return idx * 2;
}
int getRightChildIdx(int idx){
    return getLeftChildIdx(idx) + 1;
}
int getCompareIdx(Heap * ph, int idx){
    if (getLeftChildIdx(idx) > ph->numofData){
        // printf("자식 노드가 없습니다.\n");
        return 0;
    }
    else if (getLeftChildIdx(idx) == ph->numofData){
        // printf("좌측 자식 노드만 존재합니다.\n");
        return getLeftChildIdx(idx);
    }else{
        if(ph->heapArr[getLeftChildIdx(idx)].pr > ph->heapArr[getRightChildIdx(idx)].pr)
            //우선순위가 큰 곳의 idx를 보내준다.
            return getRightChildIdx(idx);
        else
            return getLeftChildIdx(idx);
    }
}
void heapInsert(Heap * ph, HData data, Priority pr){
    int idx = ph->numofData +1;
    HeapElem nelem = {pr,data};
    while(idx != 1){
        if(pr < (ph->heapArr[getParentIdx(idx)].pr)){ //새 노드의 우선순위가 높은 경우
            ph->heapArr[idx] = ph->heapArr[getParentIdx(idx)]; // 마지막노드가 될 위치에 부모의 데이터 복사
            idx = getParentIdx(idx);
        }else{ // 부모 노드의 우선 순위가 더 높은 경우
            break;
        }
    }
    ph->heapArr[idx] = nelem;
    ph->numofData++;
}
HData HDelete(Heap * ph){
    HData tmpData = ph->heapArr[1].data;
    HeapElem tmpElem = ph->heapArr[ph->numofData];

    int parentIdx = 1; //마지막 노드가 위치해야 하는 인덱스 (처음에는 루트로 가야하니 1이다.)
    int childIdx;
    while(1){
        childIdx = getCompareIdx(ph,parentIdx);
        if ((!childIdx) || (tmpElem.pr <= ph->heapArr[childIdx].pr)) // 마지막 노드와 자식 노드를 비교
            //마지막 노드가 우선순위가 더 높으면 break
            break;
        //자식 노드가 우선 순위가 더 높다면 자식 노드가 부모 노드 위치로 이동
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }
    ph->heapArr[parentIdx] = tmpElem;
    ph->numofData--;
    return tmpData;
}
void printHeap(Heap * ph){
    if (isEmpty(ph)){
        printf("노드가 없습니다!\n");
        return;
    }
    int max = ph->numofData;
    int s = 1;
    while (s != max+1){
        printf("Index: %d, Data: %c\n",s,ph->heapArr[s].data);
        s++;
    }
}
int main(void){
    Heap heap;
    HeapInit(&heap);

    heapInsert(&heap,'A',1);
    heapInsert(&heap,'B',2);
    heapInsert(&heap,'C',3);
    heapInsert(&heap,'D',4);
    heapInsert(&heap,'E',5);
    heapInsert(&heap,'F',3);
    printHeap(&heap);
    // printf("%c \n",HDelete(&heap));


    // while(!isEmpty(&heap))
    //     printf("%c \n",HDelete(&heap));

    return 0;
}