#include <stdio.h>
#define STACK_LEN 5
typedef int Data;
typedef struct ArrayStack{
    Data stackArr[STACK_LEN];
    int topIndex;
} ArrayStack;
void StackInit(ArrayStack* arr){
    arr->topIndex = -1;
}
int IsEmpty(ArrayStack* arr){
    if (arr->topIndex == -1)
        return 1;
    else
        return 0;
}
void StackPush(ArrayStack* arr,Data pData){
    arr -> topIndex += 1;
    arr -> stackArr[arr->topIndex] = pData;
    printf("Current: %d ---- %d\n", arr->topIndex, pData);
}
Data StackPop(ArrayStack* arr){
    if (IsEmpty(arr))
        return 0;
    Data pop_data = arr -> stackArr[arr->topIndex];
    arr-> topIndex -=1;
    return pop_data;
}
void PrintStack(ArrayStack* arr){
    if (IsEmpty(arr))
        return ;
    for (int i = 0 ; i <= arr->topIndex;i++){
        printf("Stack Data: %d\n",arr->stackArr[i]);
    }
}
int main(void){
    int data;
    ArrayStack list;
    StackInit(&list);
    StackPush(&list,1);
    StackPush(&list,2);
    StackPush(&list,3);
    StackPush(&list,4);
    PrintStack(&list);
    return 0;
}