#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 1000000

typedef struct
{
    int front;
    int rear;
    int array[MAX_QUEUE_SIZE];
} queue;

queue *CreateCQueue()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void push(queue *q, int data)
{
    q->array[++(q->rear)] = data;
}

int pop(queue *q)
{

    return q->array[++(q->front)];
}

int size(queue *q)
{
    return (q->rear - q->front);
}

void DelCQ(queue *q)
{
    if (q)
    {
        free(q);
    }
}

int main(void)

{
    queue *q = CreateCQueue();

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        push(q, i);
    }
    while (size(q) != 1)
    {
        pop(q);
        push(q, pop(q));
    }
    printf("%d", pop(q));
    DelCQ(q);

    return 0;
}