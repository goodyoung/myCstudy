#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define LIST_LEN 100
typedef int LData;
typedef struct __ArrayList {
    LData arr[LIST_LEN];
    int numofData; //데이터 수
    int curPosition; //데이터 참조 위치
} ArrayList;



void ListInit(ArrayList* plist){
    plist->numofData = 0;
    plist-> curPosition = -1; //-1; // -1은 아무것도 참조 안함.
}
void LInsert(ArrayList* plist,LData data){
    // 리스트 삽입
    if (plist->numofData > LIST_LEN){
        puts("배열이 꽉참");
        return;
    }else{
        plist->arr[plist->numofData] = data;
        plist->numofData++;
    }
}

int LFirst(ArrayList* plist, LData* pdata){
    if (!plist->numofData)
        return FALSE;
    plist->curPosition = 0;
    *pdata = plist->arr[0];
    return TRUE;
}
int LNext(ArrayList* plist, LData* pdata){
    if (plist->curPosition >= plist->numofData -1)
        return FALSE;
    plist->curPosition ++;
    *pdata = plist->arr[plist->curPosition];
    return TRUE;
}
LData LRemove(ArrayList* plist){
    int prev = plist->curPosition;
    int prev_num = plist->numofData;
    LData data = plist->arr[prev];
    for (int i=prev;i<(prev_num-1);i++){
        plist->arr[i] = plist->arr[i+1];
    }
    plist->numofData--;
    plist->curPosition--;
    return data;
}
int LCount(ArrayList* plist){
    return plist->numofData;
}
void LPrint(ArrayList* plist){
    if (!plist->numofData)
        return;
    int num = plist->numofData;
    int g_num = 0;
    for(int i=g_num;i<num;i++){
        printf("Data: %d\n",plist->arr[i]);
        g_num++;
    }
}
int main(void){
    int data;
    ArrayList list;
    ListInit(&list);
    LInsert(&list,11);
    LInsert(&list,22);
    LInsert(&list,22);
    LInsert(&list,22);
    LInsert(&list,22);
    LInsert(&list,22);
    LInsert(&list,111);
    LInsert(&list,111);
    LInsert(&list,111);
    printf("현재 데이터의 수: %d \n",LCount(&list));
    LPrint(&list);
    while (LNext(&list,&data))
        printf("%d ",data);
    // if (LFirst(&list,&data)){
    //     printf("%d ",data);
    //     while (LNext(&list,&data)){
    //         printf("%d ",data);
    //     }
    // }
    if (LFirst(&list,&data)){
        if (data == 22){
            LRemove(&list);
        }
        while (LNext(&list,&data)){
            if (data == 22){
                LRemove(&list);
            }
        }
    }
    LPrint(&list);
    LFirst(&list,&data);
    while (LNext(&list,&data))
        printf("%d ",data);
    printf("\n");
    LPrint(&list);
    return 0;
}