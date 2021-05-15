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
    scanf("%d",&N);//카드의 수를 입력받음
    //카드의 수만큼 반복함
    for(int i=1; i<=N;i++){
        enqueue(&q,i);//카드를 하나씩 큐에 집어넣음
    }
    //카드가 한장 남을때까지 반복
   while(size(&q)!=1){
        dequeue(&q);//하나를 버림
        num = dequeue(&q);
        enqueue(&q, num);//하나를 꺼내서 맨뒤에 집어넣음
    }
    printf("%d",dequeue(&q));//마지막 남은 카드를 출력함
    return 0;
}