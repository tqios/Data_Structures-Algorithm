#include <stdio.h>
#include <stdlib.h>
//트리의 노드 구조체
typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode; 

//새로운 노드를 생성
TreeNode *NewNode(char data)
{
    TreeNode *New;
    New = (TreeNode*)malloc(sizeof(TreeNode));
    New->data = data;
    New->left = NULL;
    New->right= NULL;
    return New;
}

//트리에서 입력한 값이 있는 노드를 찾는 함수
TreeNode *search(TreeNode *node, char data)
{
    if (node != NULL) {
        if (node->data==data) { //data값과 같은 노드를 찾으면 노드 반환
            return node;
        }
        else {
            TreeNode *tmp = search(node->left,data); //왼쪽 노드로 들어가는 재귀함수
            if (tmp != NULL) {
                return tmp; 
            }
            
            return search(node->right,data);//오른쪽 노드로 들어가는 재귀함수
        }
    }
    return NULL;
}

//노드에 값을 넣음
void insert(TreeNode *node,char A,char B,char C)
{
    node->data = A;
    if (B != '.')
    {
        node->left = NewNode(B); //B값을 가지는 왼쪽 노드를 만듦
    }
    if (C != '.')
    {
        node->right = NewNode(C); //ㅊ값을 가지는 왼쪽 노드를 만듦
    }
}
 
 //전위순회 함수
void preorder(TreeNode *root)
{
    if (root != NULL){
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

//중위순회 함수
void inorder(TreeNode *root)
{
    if (root != NULL){
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}

//후위순회 함수
void postorder(TreeNode *root)
{
    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}
 
 
int main()
{
    TreeNode *node = NewNode('A'); //첫번째 노드를 만듦
    TreeNode *tmp;
    int N;
    scanf("%d", &N);
    getchar();
    //N번 반복
    for (int i = 0;i < N;i++)
    {
        char A, B, C;
        scanf("%c %c %c", &A, &B, &C);
        getchar();
        tmp = search(node, A);//A값이 있는 노드를 찾음
        if (tmp != NULL)
            insert(tmp, A, B, C);//A값이 있는 노드에 
        else{
            insert(node,A,B,C);
        }
            
    }
    preorder(node);
    printf("\n");
    inorder(node);
    printf("\n");
    postorder(node);
}
