#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

TreeNode *NewNode(char data)
{
    TreeNode *New;
    New = (TreeNode*)malloc(sizeof(TreeNode));
    New->data = data;
    New->left = NULL;
    New->right= NULL;
    return New;
}
TreeNode *search(TreeNode *node, char data)
{
    if (node != NULL) {
        if (node->data==data) {
            return node;
        }
        else {
            TreeNode *tmp = search(node->left,data);
            if (tmp != NULL) {
                return tmp; 
            }
            
            return search(node->right,data);
        }
    }
    return NULL;
}
void insert(TreeNode *node,char A,char B,char C)
{
    node->data = A;
    if (B != '.')
    {
        node->left = NewNode(B);
    }
    if (C != '.')
    {
        node->right = NewNode(C);
    }
}
 
void preorder(TreeNode *root)
{
    if (root != NULL){
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode *root)
{
    if (root != NULL){
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}

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
    TreeNode *node = NewNode('A');
    TreeNode *tmp;
    int N;
    scanf("%d", &N);
    //getchar();
    for (int i = 0;i < N;i++)
    {
        char A, B, C;
        scanf("%c %c %c", &A, &B, &C);
        getchar();
        tmp = search(node, A);
        if (tmp != NULL)
            insert(tmp, A, B, C);
        else
        insert(node,A,B,C);
    }
    preorder(node);
    printf("\n");
    inorder(node);
    printf("\n");
    postorder(node);
}
