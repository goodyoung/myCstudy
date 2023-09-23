#include <stdio.h>
#define HeapLen 10
typedef char HData;
typedef int priorityComp(HData h1,HData h2);

typedef struct Heap{ //힙을 나타내는 구조체
    priorityComp* comp;
    int numofData; //힙의 개수는 마지막 노드의 번호와 같다.
    HData heapArr[HeapLen];
}Heap;

void HeapInit(Heap * ph,priorityComp pc){
    ph->numofData = 0;
    ph->comp = pc;
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
int DataPriorityComp(char ch1, char ch2){
    return ch2-ch1;
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
        if (ph->comp(ph->heapArr[getLeftChildIdx(idx)],ph->heapArr[getRightChildIdx(idx)]) < 0)
            return getRightChildIdx(idx);
        else
            return getLeftChildIdx(idx);
    }
}
void heapInsert(Heap * ph, HData data){
    int idx = ph->numofData +1;
    while(idx != 1){
        if(ph->comp(data,ph->heapArr[getParentIdx(idx)] > 0)){
            ph->heapArr[idx] = ph->heapArr[getParentIdx(idx)]; // 마지막노드가 될 위치에 부모의 데이터 복사
            idx = getParentIdx(idx);
        }else{ // 부모 노드의 우선 순위가 더 높은 경우
            break;
        }
    }
    ph->heapArr[idx] = data;
    ph->numofData++;
}
HData HDelete(Heap * ph){
    HData tmpData = ph->heapArr[1];
    HData tmpElem = ph->heapArr[ph->numofData];

    int parentIdx = 1; //마지막 노드가 위치해야 하는 인덱스 (처음에는 루트로 가야하니 1이다.)
    int childIdx;
    while(1){
        childIdx = getCompareIdx(ph,parentIdx);
        if ((!childIdx) || (ph->comp(tmpElem,ph->heapArr[childIdx])))// 마지막 노드와 자식 노드를 비교
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
        printf("Index: %d, Data: %c\n",s,ph->heapArr[s]);
        s++;
    }
}
int main(void){
    //이 자체가 우선순위 큐이며 힙이다.
    Heap heap;
    priorityComp *pc =  DataPriorityComp;
    HeapInit(&heap,pc);

    heapInsert(&heap,'A');
    heapInsert(&heap,'B');
    heapInsert(&heap,'C');
    heapInsert(&heap,'D');
    HDelete(&heap);
    heapInsert(&heap,'E');
    heapInsert(&heap,'F');
    printHeap(&heap);

    return 0;
}