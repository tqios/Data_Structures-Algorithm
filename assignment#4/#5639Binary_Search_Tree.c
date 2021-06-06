#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode *root;

//새로운 노드를 만드는 함수
TreeNode *newNode(int num)
{
    TreeNode *node;
    node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = num;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void makeTree(TreeNode *top, int *pre, int index)
{
    if (pre[index] < top->data)
    { //top의 data보다 pre[index]가 작고
        if (top->left == NULL)
        { //왼쪽 자식노드에 아무 것도 존재하지 않으면
            //노드를 생성하고 top의 왼쪽 자식노드에 연결한다
            TreeNode *node = newNode(pre[index]);
            top->left = node;
            return;
        }
        else
        { //왼쪽 자식노드가 있으면 내려가 재귀로 다시 함수를 호출한다
            top = top->left;
            makeTree(top, pre, index);
        }
    }
    else if (pre[index] > top->data)
    { //top의 data보다 pre[index]가 크고
        if (top->right == NULL)
        { //오른쪽 자식노드에 아무것도 존재하지 않으면
            //노드를 생성하고 top의 오른쪽 자식노드에 연결한다
            TreeNode *node = newNode(pre[index]);
            top->right = node;
            return;
        }
        else
        { ////오른쪽 자식노드가 있으면 내려가 재귀로 다시 함수를 호출한다
            top = top->right;
            makeTree(top, pre, index);
        }
    }
}

//후위순회 함수
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
    int index = 1;
    int x;          //입력받은 값을 저장할 변수 x
    int pre[10001]; //입력받은 값을 저장할 배열 pre
    int i = 0;      //배열의 인덱스

    while (scanf("%d", &x) != EOF)
    { //입력이 끝날때까지 반복한다 (^Z)
        ++i;
        pre[i] = x;
    }
    root = newNode(pre[1]); //루트노드 생성 - 전역변수
    for (int j = 1; j < i; j++)
    {            //입력한 노드의 개수만큼 반복
        ++index; //index를 하나씩 증가시키며 노드를 생성해 트리에 추가한다
        makeTree(root, pre, index);
    }
    postorder(root); //후위 순회로 출력
    return 0;
}