#include <stdio.h>
#define MAX_TREE_SIZE 100001

//트리에서 특정 수의 인덱스를 찾는 함수
int search(int node[], int num){
    for(int i=1; i<MAX_TREE_SIZE; i++){ //node배열의 크기만큼 반복
        if(node[i]==num){//노드의 수와 찾으려는 수가 같을 경우
            return i;//인덱스를 반환함
        }
    }
    return 0;
}

//트리를 만드는 함수
void makeTree(int node[], int loop){
    int num1, num2;
    for(int i=1; i<loop; i++){
        scanf("%d %d", &num1, &num2);
        int k = search(node, num1);//num1을 트리에서 찾음
        if(k==0){//num1이 트리에 없는 경우
            int j = search(node, num2);//num2를 트리에서 찾음
            if(node[j*2] == 0){//왼쪽 자식노드가 비어있는 경우
                node[j*2] = num1;//왼쪽 자식노드에 넣음
            }
            else{//왼쪽 자식 노드가 비지 않은 경우
                node[j*2+1] = num1;//오른쪽 자식노드에 넣음
            }
        }
        else{//num1이 트리에 있는 경우
             if(node[k*2] == 0){//왼쪽 자식노드가 비어있는 경우
                node[k*2] = num2;//왼쪽 자식노드에 넣음
            }
            else{//왼쪽 자식 노드가 비지 않은 경우
                node[k*2+1] = num2;//오른쪽 자식노드에 넣음
            }
        }
        
    }
}

int main(void){
    int node[MAX_TREE_SIZE] = {0, }; //트리의 모든값을 0으로 초기화
    int loop;
    node[1] = 1; //첫번째 노드를 1로 초기화함
    scanf("%d", &loop);
    makeTree(node, loop);

    //2부터 각가의 부모노드를 찾아 출력
    for(int i=2; i<=loop; i++){
        int j = search(node, i); //i값을 찾음
        printf("%d\n",node[j/2]);//부모 노드를 출력함
    }
    
    return 0;
}