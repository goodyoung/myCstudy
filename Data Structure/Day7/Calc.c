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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int IsEmpty(Stack* pstack){
    if (pstack->top == NULL)
        return 1;
    else
        return 0;
}
void Stackpush(Stack* pstack, void* data){
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
    if (pstack->top == NULL){
        printf("Stack is NULL");
        return;
    }
    Node* pTmp = pstack->top;
    while (pTmp){
        printf("Print(): DATA: %s\n",pTmp->data);
        pTmp = pTmp->next_;
    }
    printf("\n");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    printf("**********CHANGEFORMAT**********\n");
    int length = strlen(exp);
    int count = 0;
    char * pop_value;
    char * changeValue = (char*)malloc(sizeof(char)*(length+1));
    memset(changeValue,0,length+1);
    for(int i = 0 ; i < length;i++){
        char value = exp[i];
        int num = CompareOperation(&value);
        if (num == -1) // 문자일 경우
            changeValue[count++] = value;
        else if (num == 0){ // 괄호일 경우
            Stackpush(pstack,&value);
        }
        else if (num == 3){ // 닫는 괄호
            while (1){
            pop_value = Stackpop(pstack);
            printf("asdasdasdasdasdadas%c\n",*pop_value);
            if (CompareOperation(pop_value) == 0)
                break;
            else
                changeValue[count++] = *pop_value;
            printf("괄호일 경우, pop: %s\n",pop_value);
            }
        }
        else if (num == 2){
            while(!IsEmpty(pstack) && Prepare(Temp_pop(pstack),&value) >= 0) ///
                changeValue[count++] = *Stackpop(pstack);
            Stackpush(pstack,&value);
        }
        Print(pstack);
    }
    while(!IsEmpty(pstack)){
        changeValue[count++] = *Stackpop(pstack);
    }

    strcpy(exp,changeValue);
    free(changeValue);
    return exp;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char* postfix(Stack* pstack, char * exp){
    printf("**********POSTFIX**********\n");
    int tot;
    int length = strlen(exp);
    for (int i = 0; i< length ; i++){
        char value = exp[i];
        int num = CompareOperation(&value);
        if (num==-1){
            Stackpush(pstack,&value);
        }else{
            // stack 순서에 따라 반대로
            char ex2 = *Stackpop(pstack) - '0'; // 아스키 값을 빼서 숫자로 변환
            char ex1 = *Stackpop(pstack) - '0';
            switch(value){
                case '*':
                    tot = ex1*ex2;
                    break;
                case '/':
                    tot = ex1/ex2;
                    break;
                case '%':
                    tot = ex1%ex2;
                    break;
                case '+':
                    tot = ex1+ex2;
                    break;
                case '-':
                    tot = ex1-ex2;
                    break;
            }
            tot += '0';
            printf("Calc Result: %d\n",tot);
            Stackpush(pstack,&tot);
        }
    }
    return Stackpop(pstack);
}


int main(void){
    printf("***********************\n");
    Stack stack;
    stack.top = NULL;

    // char exp[] = "A*((B+C)/D)";
    char exp[] = "8/((3+2)-1)";
    printf("First word: %s\n",exp);
    changeFormat(&stack,exp);
    printf("Second word: %s\n",exp);
    char result_num = *postfix(&stack,exp) - '0';
    printf("***********************\n");
    printf("계산 결과는 : %d입니다.\n",result_num);
    // Stackpush(&stack,"112");
    // Stackpush(&stack,"212");
    // Stackpush(&stack,"312");
    // Print(&stack);
    // Stackpop(&stack);
    // Stackpop(&stack);
    // char* data = Stackpop(&stack);
    // Print(&stack);
    return 0;
}

