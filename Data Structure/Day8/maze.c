#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef struct maze
{
    int x;
    int y;
}off;

typedef struct{
    short int row;
    short int col;
    short int dir;
} element;
typedef struct{
    int top;
    element* pelement;          //동적 할당
    // element stack[MAX_STACK_SIZE]; //정적 할당 --> idx stack_idx;로 정적할당으로 해줘야함.
    // 정적, 동적을 혼용하지 말자.
}idx;

element stack[MAX_STACK_SIZE];
element pop(idx* pstack);
void push(idx* pstack,element position);
off move[8]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
int maze[13][17] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1},
    {1,1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,1},
    {1,0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1},
    {1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,1},
    {1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1},
    {1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1},
    {1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1},
    {1,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,1},
    {1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,1},
    {1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};
int mark[13][17]={0,};
int IsEmpty(idx* pstack){
    if (pstack->top==-1)
        return 1;
    else
        return 0;
}
void path(){
    // 미로 초기 설계
    int row, col, dir;
    int found = 0;
    int next_row, next_col;
    element position;
    idx* stack_idx = (idx*)malloc(sizeof(idx));
    memset(stack_idx,0,sizeof(idx));
    stack_idx->pelement = stack;
    stack_idx -> top = 0;
    stack_idx->pelement[0].row = 1;
    stack_idx->pelement[0].col = 1;
    stack_idx->pelement[0].dir = 1;
    
    // position = pop(stack_idx);
    // row = position.row; col = position.col; dir = position.dir;
    // printf("test: %d %d %d",row,col,dir);
    while (!IsEmpty(stack_idx) && !found){ // 스택이 안비어있을 때
        position = pop(stack_idx);
        row = position.row; col = position.col; dir = position.dir;
        //main code
        while(dir < 8 && !found){
            next_row = row + move[dir].x;
            next_col = col + move[dir].y;
            if (next_row == 11 && next_col == 15)
                found = 1; // 찾음
            else if (!maze[next_row][next_col] && !mark[next_row][next_col]){
                mark[next_row][next_col] = 1;
                position.row = row; position.col = col; position.dir = ++dir;
                push(stack_idx,position);
                row = next_row;
                col = next_col;
                dir = 0;
            }
            else
                ++dir;
        }
    }

    if (found){
        printf("< Path >\n");
        printf(" row col\n");
        for (int i = 0 ; i <= stack_idx->top;i++){
            printf("%2d %5d\n",stack_idx->pelement[i].row,stack_idx->pelement[i].col);
        }
        printf("%2d %5d\n",row,col);
        printf("< END >");
    }else{
        printf("no path found!\n");
    }
    free(stack_idx);
}
void push(idx* pstack,element position){
    pstack->top++;
    pstack->pelement[pstack->top].row = position.row;
    pstack->pelement[pstack->top].col = position.col;
    pstack->pelement[pstack->top].dir = position.dir;
    
}
element pop(idx* pstack){
    element data;
    if (IsEmpty(pstack))
        printf("Stack is Empty\n");
    else{
        data = pstack->pelement[pstack->top];
        pstack->top--;
    }
    return data;
}


int main(void){
    path();
    return 0;
}