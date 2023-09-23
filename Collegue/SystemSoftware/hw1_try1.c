// Linked list를 C언어를 이용하여 구현한 프로그램을 작성하시오.
// - 입력파일에서(input.txt) 데이터를 입력 받아서 linked list에 삽입한다. (input.txt는 첨부파일로 있음)
// - Linked list에는 중복된 데이터가 존재하면 안 된다. 
// - Linked list가 완성되면 총 node의 수를 출력한다. (중복되지 않는 데이터의 수)
// - 1을 빼거나 더했을 때 소수인 정수의 개수를 구한다.
// - 입력의 대부분은 0 <= n <= 10 ** 5 인 정수 n이다.

// * 입력
// 없음

// input.txt는 문제에 포함되어 있고, 동일한 디렉토리에 존재한다고 가정한다.
// fp=fopen("input.txt", "r");
// 위와 같은 식으로 접근하면 됩니다.

// * 출력
// Only one count : 36868
// Near prime count : 17982

// 위와 동일하게(대소문자 구분) 출력되어야 한다.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int num;
    struct Node * left;
    struct Node * right;
}Node;

Node * g_pRoot;

void initNode(Node * pnode){
    g_pRoot = NULL;
}
// int isEmpty(Node * pnode){
//     if (g_pRoot == NULL)
//         return 1;
//     else
//         return 0;
// }
int compareNum(int data1, int data2){
    if (data1 > data2){
        return 1;
    }else{
        return 0;
    }
}

int insertNode(int number){
    Node* pTmp = (Node*)malloc(sizeof(Node));
    memset(pTmp,0,sizeof(Node)); //메모리 초기화
    pTmp->num = number;
    // 중복된 데이터가 존재하면 안된다!!
    //1을 더하거나 뺐을 때  소수인 정수의 개수 -> global 변수??
    if (g_pRoot == NULL){ // root가 널이면
        g_pRoot = pTmp;
        // g_pRoot->left = NULL;
        // g_pRoot->right = NULL;
        return 1;
    }
    Node* pNode = g_pRoot;

    while (pNode != NULL){
        if (compareNum(pNode->num,number)){ // 1이면 
            if(pNode->left == NULL){
                pNode->left = pTmp;
                break;
            }else{
                pNode = pNode->left;
                continue;
            }
        }else{
            if (pNode->right == NULL){
                pNode->right = pTmp;
                break;
            }else{
                pNode = pNode->right;
                continue;
            }
        }
    }

}
void printNode(Node * pnode){
    if (pnode == NULL)
        return;
    printNode(pnode->left);
    printf("[%p] %p, %d [%p]\n",
        pnode->left,pnode,
        pnode->num,pnode->right);
    printNode(pnode->right);
}


int main(void){
    insertNode(4);
    insertNode(2);
    insertNode(5);
    printNode(g_pRoot);
    return 0;   
}