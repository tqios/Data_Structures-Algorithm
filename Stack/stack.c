#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
typedef int element;
{
  element data[MAX_STACK_SIZE];
  int top;
} StackType;

void init_stack(StackType *s)
{
  s->top = -1;
}

int is_empty(StackType *s)
{
  return (s->top == -1);
}

int is_full(StackType *s)
{
  return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item)
{
  if (is_full(s))
  {
    fprintf(stderr, "스택 포화 에러\n");
    return;
  }
  else
    s->data[++(s->top)] = item;
}

element pop(StackType *s)
{
  if (is_empty(s))
  {
    return -1;
  }
  else
    return s->data[(s->top)--];
}

int main(void)
{
  StackType s;

  init_stack(&s);

  int n;
  scanf("%d", &n);
  char arr[2];

  for (int i = 0; i < n; i++)
  {
    char input[10];
    scanf("%s", &input);
    char *ptr, *ptr1, *a, *b;
    ptr = strtok(input, " ");
    a = ptr;
    ptr = strtok(NULL, " ");
    b = ptr;

    if (strcmp("push", a) == 0)
    {
      push(&s, (int)b);
    }
    else if (strcmp("pop", input) == 0)
    {
      printf("%d\n", pop(&s));
    }
    else if (strcmp("size", input) == 0)
    {
      printf("%d\n", (s.top + 1));
    }
    else if (strcmp("empty", input) == 0)
    {
      if (s.top == -1)
      {
        printf("1\n");
      }
      else
      {
        printf("0\n");
      }
    }
    if (!strcmp("top", input))
    {
      if (s.top == -1)
      {
        printf("-1\n");
      }
      else
      {
        int top1;
        top1 = pop(&s);
        push(&s, top1);
        printf("%d\n", top1);
      }
    }
  }
}
