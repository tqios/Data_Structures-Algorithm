#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE_SIZE 100000

int search(int node[], int num){
    for(int i=1; i<MAX_TREE_SIZE; i++){
        if(node[i]==num){
            return i;
        }
    }
    return 0;
}

void makeTree(int node[], int loop){
    int num1, num2;
    for(int i=1; i<loop; i++){
        scanf("%d %d", &num1, &num2);
        int k = search(node, num1);
        if(k==0){
            int j = search(node, num2);
            if(node[j*2] == 0){
                node[j*2] = num1;
            }
            else{
                node[j*2+1] = num1;
            }
        }
        else{
             if(node[k*2] == 0){
                node[k*2] = num2;
            }
            else{
                node[k*2+1] = num2;
            }
        }
        
    }
}

int main(void){
    int node[MAX_TREE_SIZE] = {0, };
    int loop;
    node[1] = 1;
    scanf("%d", &loop);
    makeTree(node, loop);

    for(int i=2; i<=loop; i++){
        int j = search(node, i);
        printf("%d\n",node[j/2]);
    }
    
    return 0;
}