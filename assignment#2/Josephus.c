#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int front;
    int rear;
    int capacity;
    int *array;
} queue;

queue *CreateCQueue()
{
    queue *q = (queue *)malloc(sizeof(queue));
    if (!q)
        return NULL;
    q->capacity = 1;
    q->front = q->rear = -1;
    q->array = (int *)malloc(q->capacity * sizeof(int));
    if (!q->array)
        return NULL;
    return q;
}

int IsEmptyCQ(queue *q)
{
    return (q->front == -1);
}

int IsFullCQ(queue *q)
{
    return ((q->rear + 1) % q->capacity == q->front);
}

int CQsize(queue *q)
{
    return (q->capacity - q->front + q->rear + 1) % q->capacity;
}

void ResizeCQ(queue *q)
{
    int size = q->capacity;
    q->capacity = q->capacity * 2;
    q->array = (int *)realloc(q->array, q->capacity * sizeof(int));

    if (!q->array)
    {
        return;
    }
    if (q->front > q->rear)
    {
        for (int i = 0; i < q->front; i++)
        {
            q->array[i + size] = q->array[i];
        }
        q->rear = q->rear + size;
    }
}

void EnCQ(queue *q, int data)
{
    if (IsFullCQ(q))
    {
        ResizeCQ(q);
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = data;
    if (q->front == -1)
        q->front = q->rear;
}

int DeCQ(queue *q)
{
    int data = 0;
    if (IsEmptyCQ(q))
    {
        //printf("CQueue is Empty\n");
        return 0;
    }
    else
    {
        data = q->array[q->front];
        if (q->front == q->rear)
            q->front = q->rear = -1;
        else
            q->front = (q->front + 1) % q->capacity;
    }
    return data;
}

void DelCQ(queue *q)

{
    if (q)
    {
        if (q->array)
        {
            free(q->array);
        }
        free(q);
    }
}

int main(void)
{
    queue *q = CreateCQueue();

    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    for (int i = 1; i <= n; i++)
    {
        EnCQ(q, i);
    }
    int list[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < k; j++)
        {
            EnCQ(q, DeCQ(q));
        }
        list[i] = DeCQ(q);
    }

    DelCQ(q);
    printf("<");
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d, ", list[i]);
    }
    printf("%d", list[n - 1]);
    printf(">");

    return 0;
}