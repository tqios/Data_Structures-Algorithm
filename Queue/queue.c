#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 2000000

typedef struct _queue
{
  int front;
  int rear;
  int array[MAX_QUEUE_SIZE];
} queue;

queue *CreateCQueue()
{
  queue *q = malloc(sizeof(queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

int IsEmptyCQ(queue *q)
{
  return (q->front == q->rear);
}

int IsFullCQ(queue *q)
{
  return ((q->rear + 1) == MAX_QUEUE_SIZE);
}

void push(queue *q, int data)
{
  if (IsFullCQ(q))
  {
    return;
  }
  q->array[++(q->rear)] = data;
}

int pop(queue *q)
{
  if (IsEmptyCQ(q))
  {
    return -1;
  }
  else
  {
    return q->array[++(q->front)];
  }
}

int size(queue *q)
{
  return (q->rear - q->front);
}

int front(queue *q)
{
  if (IsEmptyCQ(q))
    return -1;
  return q->array[(q->front) + 1];
}

int back(queue *q)
{
  if (IsEmptyCQ(q))
    return -1;
  return q->array[q->rear];
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

  int loop, n;

  scanf("%d", &loop);

  for (int i = 0; i < loop; i++)
  {
    char x[10];
    scanf("%s", x);

    if (!strcmp(x, "push"))
    {
      scanf("%d", &n);
      push(q, n);
    }
    else if (!strcmp(x, "pop"))
    {
      printf("%d\n", pop(q));
    }
    else if (!strcmp(x, "size"))
    {
      printf("%d\n", size(q));
    }
    else if (!strcmp(x, "empty"))
    {
      printf("%d\n", IsEmptyCQ(q));
    }
    else if (!strcmp(x, "front"))
    {
      printf("%d\n", front(q));
    }
    else if (!strcmp(x, "back"))
    {
      printf("%d\n", back(q));
    }
    else
    {
      printf("\n");
    }
  }

  return 0;
}