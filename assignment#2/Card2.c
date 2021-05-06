#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 1000000

typedef int element;
typedef struct{
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}QueueType;

void init_queue(QueueType *q){
    q->rear = -1;
    q->front = -1;
}

int is_full(QueueType *q){
    if(q->rear==MAX_QUEUE_SIZE-1)
        return 1;
    else
        return 0;
}

int is_empty(QueueType *q){
    if(q->front==q->rear)
        return 1;
    else
        return 0;
}

void enqueue(QueueType *q, element item){
    if(is_full(q)==1){
        return;
    }
    q->data[++(q->rear)] = item;
}

int dequeue(QueueType *q){
    if(is_empty(q)==1){
        return -1;
    }
    return q->data[++(q->front)];
}

int size(QueueType *q){
    return (q->rear)-(q->front);
}

int main(void){
    QueueType q;
    init_queue(&q);

    int N, num;
    scanf("%d",&N);
    for(int i=1; i<=N;i++){
        enqueue(&q,i);
    }

   while(size(&q)!=1){
        dequeue(&q);
        num = dequeue(&q);
        enqueue(&q, num);
    }
    printf("%d",dequeue(&q));
    return 0;
}