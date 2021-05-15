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
//큐안에 있는 데이터의 개수를 반환하는
int size(Queuetype *q){
    return (q->rear)-(q->front);
}
//맨 앞값을 반환하는 함수
int front(Queuetype *q){
    if(is_empty(q)){
        return -1;
    }
    return q->data[(q->front)+1];
}
//마지막 값을 반환하는 함수
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

    scanf("%d", &loop);//반복할 횟수를 입력

    for(int i=0; i<loop ;i++){
        char prom[10];
        scanf("%s",&prom);//명령을 입력
        //명령이 push인 경우
        if (!strcmp(prom, "push")){
            scanf("%d",&num);
            push(&q, num);
        }
        //명령이 pop인 경우
        else if(!strcmp(prom, "pop")){
            printf("%d\n",pop(&q));
        }
        //명령이 size인 경우
        else if(!strcmp(prom,"size")){
            printf("%d\n",size(&q));
        }
        //명령이 empty인 경우
        else if(!strcmp(prom,"empty")){
            printf("%d\n",is_empty(&q));
        }
        //명령이 front인 경우
        else if(!strcmp(prom,"front")){
            printf("%d\n",front(&q));
        }
        //명령이 back인 경우
        else if(!strcmp(prom,"back")){
            printf("%d\n",back(&q));
        }
    }
}