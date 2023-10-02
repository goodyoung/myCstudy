#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100
typedef struct Node{
    struct Node *left;
    struct Node *right;
    int data;
}Node;

typedef struct {
    Node* data[MAX_SIZE];
    int top; 
} Stack;


typedef void showFunc(int data);
//////////////////////////////////////////////////////////////////////
Node *nodeInit(){
    Node* pNewNode = (Node*)malloc(sizeof(Node));
    memset(pNewNode,0,sizeof(Node));

    pNewNode->left = NULL;
    pNewNode->right = NULL;
    return pNewNode;
}
Node* getRightNode(Node * pnode){
    return pnode->right;
}
Node* getLeftNode(Node * pnode){
    return pnode->left;
}
int getData(Node * pnode){
    return pnode->data;
}
void setData(Node* pTmp, int num){
    pTmp->data = num;
}
void makeLeftTree(Node * main, Node* sub){
    if (main->left !=NULL){
        free(main->left);
    }
    main->left = sub;
}
void makeRightTree(Node * main, Node* sub){
    if (main->right !=NULL){
        free(main->right);
    }
    main->right = sub;
}
void printMiddle(Node *pNode,showFunc action){

    if (pNode ==NULL){
        return;
    }
    
    // printf("Data: %d\n",pNode->data);
    
    printMiddle(pNode->left,action);
    action(pNode->data);
    printMiddle(pNode->right,action);
}


//////////////////////////////////////////////////////////////////////
void showNodeData(int data){
    if (0<= data && data <= 9){
        printf("%d\n",data);
    }else{
        printf("%c\n",data);
    }
}

void showPrefixData(Node * pnode){
    printMiddle(pnode,showNodeData);
}

void stackPush(Stack *pstack, Node * pnode){
    pstack->top++;
    pstack->data[pstack->top] = pnode;
}
Node* stackPop(Stack *pstack){
    if (pstack->top == -1) {
        printf("스택이 비어있습니다.\n");
        return NULL; 
    }
    Node* data = pstack->data[pstack->top];
    pstack->top--;
    return data;
}
void stackInit(Stack * pstack){
    pstack->top = -1;
}

Node * makeExpTree(char exp[]){
    Stack stack;
    Node * pnode;
    int expLen = strlen(exp);
    stackInit(&stack);
    for (int i = 0 ; i<expLen; i++){
        if (exp[i] == ' ') {
            // 공백 문자는 무시
            continue;
        }
        pnode = nodeInit();
        if (isdigit(exp[i])){
            setData(pnode,exp[i]-'0');
        }else{
            makeRightTree(pnode,stackPop(&stack));
            makeLeftTree(pnode,stackPop(&stack));
            setData(pnode,exp[i]); //루트를 연산자로 실행
        }
        stackPush(&stack, pnode);
    }

    return stackPop(&stack);
}

int evaluateExpTree(Node * pnode){
    int op1,op2;
    if (getLeftNode(pnode) == NULL && getRightNode(pnode) == NULL)
        return getData(pnode);
    op1 = evaluateExpTree(getLeftNode(pnode));
    op2 = evaluateExpTree(getRightNode(pnode));
    switch (getData(pnode)){
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*': 
            return op1 * op2;
        case '/':
            return op1 / op2;
    }

    return 0;
}

//////////////////////////////////////////////////////////////////////
int main(void){
    Node * tree;
    char exps[] = "12 7 +";
    tree = makeExpTree(exps);
    int s = evaluateExpTree(tree);
    printf("결과: %d\n",s);
    showPrefixData(tree);
    return 0;
}