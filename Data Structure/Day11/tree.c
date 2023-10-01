#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{
    struct Node *left;
    struct Node *right;
    int data;
}Node;


typedef void showFunc(int data);
Node *nodeInit(){
    Node* pNewNode = (Node*)malloc(sizeof(Node));
    memset(pNewNode,0,sizeof(Node));

    pNewNode->left = NULL;
    pNewNode->right = NULL;
    return pNewNode;
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
    action(pNode->data);
    printMiddle(pNode->left,action);
    printMiddle(pNode->right,action);
}
void showIntData(int num){
    printf("%d ",num);
}

int main(void){
    Node * n1 = nodeInit();
    Node * n2 = nodeInit();
    Node * n3 = nodeInit();
    Node * n4 = nodeInit();

    setData(n1,1);
    setData(n2,2);
    setData(n3,3);
    setData(n4,4);

    makeLeftTree(n1,n2);
    makeRightTree(n1,n3);
    makeLeftTree(n2,n4);

    printMiddle(n1,showIntData);
    return 0;
}