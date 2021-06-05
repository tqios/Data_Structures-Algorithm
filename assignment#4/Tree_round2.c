#include <stdio.h>
#include <stdlib.h>

//Node를 구성하는 구조체 정의
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

//노드를 만드는 함수
TreeNode* NewNode(int data) {
    TreeNode *New;
    New = (TreeNode*)malloc(sizeof(TreeNode));
    New->data = data;
    New->left = NULL;
    New->right = NULL;
    return New;
}

//배열의 특정값 인덱스를 찾는 함수
int find(int list[], int data) {
    for (int i = 0; i < 100001; i++) {//배열의 크기만큼 반복
        if (list[i] == data) {//data값과 일치하면 인덱스 반환
            return i;
        }
    }
    return -1;
}
//중위순회, 후위순회를 이용하여 Tree를 만드는 함수
TreeNode *maketree(TreeNode* node, int *pend, int instart, int inend, int in[], int post[],int index) {
    // 가운데 찾음
    // 루트에 저장
    if (instart <= inend && index!=-1) {
        int top = post[(*pend)--];//post의 맨 뒤값이 루트의 부모노드
        node = NewNode(top); //top값을 넣은 노드를 만듦
        int index = find(in, top);//in배열에서 top의 인덱스를 찾음
        
        node->right = maketree(node->right, pend, index + 1, inend, in, post,index);//오른쪽 반복
        node->left = maketree(node->left, pend, instart, index - 1, in, post,index);//왼쪽 반복
    }
    return node;
}


//전위순회 함수
void preorder(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(void) {
    int loop;
    scanf("%d", &loop);
    int in[100001], post[100001];
    //중위순회 입력받음
    for (int i = 0; i < loop; i++) {
        scanf("%d", &in[i]);
    }
    //후위순회 입력받음
    for (int i = 0; i < loop; i++) {
        scanf("%d", &post[i]);
    }

    
    TreeNode* root = NULL;
    int index =0;
    int pend = loop-1;
    root = maketree(root, &pend, 0, loop - 1, in, post,index); //트리를 만듦
    preorder(root);
    return 0;
}