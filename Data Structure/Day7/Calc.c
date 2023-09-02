#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    char data[100];
    struct Node* next_;
} Node;
typedef struct Stack {
    Node *top;
}Stack;
int IsEmpty(Stack* pstack){
    if (pstack->top == NULL)
        return 1;
    else
        return 0;
}
void Stackpush(Stack* pstack, char* data){
    Node *pNode = (Node*) malloc(sizeof(Node));
    memset(pNode,0,sizeof(Node));
    strcpy(pNode->data, data);
    pNode->next_ = pstack->top;
    pstack->top = pNode;
}
char* Stackpop(Stack* pstack){
    if (pstack->top == NULL)
        return 0;
    Node * pNode = pstack->top;
    char* data = pNode->data;

    pstack->top = pNode->next_;
    free(pNode);
    printf("POP DATA: %s\n",data);
    return data;
}
void Print(Stack* pstack){
    if (pstack->top == NULL)
        return;
    Node* pTmp = pstack->top;
    while (pTmp){
        printf("Data: %s\n",pTmp->data);
        pTmp = pTmp->next_;
    }
}   
int CompareOperation(char* i){
    switch (*i){
        case '*':
        case '/':
        case '%':
        case '+':
        case '-':
            return 2;
        case '(':
            return 0;
        case ')':
            return 3;
        default:
            return -1;
    }
}
int Prepare(char* op1,char* op2){
    printf("Prepare 진입!!");
    int op1_ = CompareOperation(op1);
    int op2_ = CompareOperation(op2);
    if (op1_ > op2_)
        return 1;
    else if (op1_ < op2_)
        return -1;
    else
        return 0;
}
char* Temp_pop(Stack* pstack){
    Node* pTmp = pstack->top;
    return pTmp->data; //스택의 가장 상단 데이터 꺼내기
}
char* changeFormat(Stack* pstack,char* exp){
    int length = strlen(exp);
    int count = 0;
    char * pop_value;
    char * changeValue = (char*)malloc(sizeof(char)*length);
    memset(changeValue,'0',length);
    for(int i = 0 ; i < length;i++){
        char* value = &exp[i];
        int num = CompareOperation(value);
        if (num == -1)
            changeValue[count++] = *value;
        else if (num == 0){ // 괄호일 경우
            Stackpush(pstack,value);
        }
        else if (num == 3){ // 닫는 괄호
            pop_value = Stackpop(pstack);
            if (CompareOperation(pop_value) == 3)
                break;
            changeValue[count++] = *pop_value;
        }
        else if (num == 2){
            while(!IsEmpty(pstack) && Prepare(Temp_pop(pstack),value) >= 0) ///
                changeValue[count++] = *Stackpop(pstack);
            Stackpush(pstack,value);
        }
    }
    while(!IsEmpty(pstack)){
        changeValue[count++] = *Stackpop(pstack);
    }

    printf("마지막??? %c\n",changeValue[0]);
    strcpy(exp,changeValue);
    free(changeValue);
    return exp;
}

int main(void){
    printf("***********************\n");
    Stack stack;
    stack.top = NULL;
    
    char exp[] = "A*((B+C)/D)";
    printf("First word: %s\n",exp);
    changeFormat(&stack,exp);
    printf("Second word: %s\n",exp);


    // Stackpush(&stack,"1");
    // Stackpush(&stack,"2");
    // Stackpush(&stack,"3");
    // Print(&stack);
    // Stackpop(&stack);
    // char* data = Stackpop(&stack);
    // Print(&stack);
    return 0;
}



