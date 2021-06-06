#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode *root;

TreeNode *newNode(int num)
{
    TreeNode *node;
    node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = num;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void makeTreeC(TreeNode *top, int *pre, int index)
{
    if (pre[index] < top->data)
    {
        if (top->left == NULL)
        {
            TreeNode *node = newNode(pre[index]);
            top->left = node;
            return;
        }
        else
        {
            top = top->left;
            makeTreeC(top, pre, index);
        }
    }
    else if (pre[index] > top->data)
    {
        if (top->right == NULL)
        {
            TreeNode *node = newNode(pre[index]);
            top->right = node;
            return;
        }
        else
        {
            top = top->right;
            makeTreeC(top, pre, index);
        }
    }
}

void postorder(TreeNode *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\n", root->data);
    }
}
int main(void)
{
    int index = 2;
    int x;          //입력받은 값을 저장할 변수 x
    int pre[10001]; //입력받은 값을 저장할 배열 pre
    int i = 1;      //배열의 인덱스, 1부터 시작

    while (scanf("%d", &x) != EOF)
    { //입력이 끝날때까지 반복한다 (^Z)
        pre[i] = x;
        i++;
    }
    root = newNode(pre[1]); //루트노드 생성
    for (int j = 1; j < i - 1; j++)
    {
        makeTreeC(root, pre, index);
        index++;
    }
    postorder(root);
    return 0;
}