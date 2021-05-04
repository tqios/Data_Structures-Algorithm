#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 2000000

typedef int element;
typedef struct{
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}Queuetype;

//큐 초기화
void init_queue(Queuetype *q){
    q->rear = -1;
    q->front = -1;
}

//큐가 가득 찰때
int is_full(Queuetype *q){
    if(q->rear == MAX_QUEUE_SIZE-1){
        return 1;
    }
    else{
        return 0;
    }
}
//큐가 비었을때
int is_empty(Queuetype *q){
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}
//큐 삽입
void push(Queuetype *q, int item){
    if(is_full(q)==1){
        return;
    }
    q->data[++(q->rear)] = item;
}
//큐 출력.
int pop(Queuetype *q){
    if(is_empty(q)==1){
        return -1;
    }
    return q->data[++(q->front)];
}

int size(Queuetype *q){
    return (q->rear)-(q->front);
}

int front(Queuetype *q){
    if(is_empty(q)){
        return -1;
    }
    return q->data[(q->front)+1];
}

int back(Queuetype *q){
    if(is_empty(q)){
        return -1;
    }
    return q->data[q->rear];
}

int main(void){
    Queuetype q;
    init_queue(&q);

    int loop, num;

    scanf("%d", &loop);

    for(int i=0; i<loop ;i++){
        char prom[10];
        scanf("%s",&prom);
        
        if (!strcmp(prom, "push")){
            scanf("%d",&num);
            push(&q, num);
        }
        else if(!strcmp(prom, "pop")){
            printf("%d\n",pop(&q));
        }
        else if(!strcmp(prom,"size")){
            printf("%d\n",size(&q));
        }
        else if(!strcmp(prom,"empty")){
            printf("%d\n",is_empty(&q));
        }
        else if(!strcmp(prom,"front")){
            printf("%d\n",front(&q));
        }
        else if(!strcmp(prom,"back")){
            printf("%d\n",back(&q));
        }
    }
}