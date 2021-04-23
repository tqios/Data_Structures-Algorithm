#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100000
typedef int element;
typedef struct
{
  element data[MAX_STACK_SIZE];
  int top;
} StackType;

void init_stack(StackType *s)
{
  s->top = -1;
}

void push(StackType *s, element item)
{
  s->data[++(s->top)] = item;
}

element pop(StackType *s)
{
  if (s->top == -1)
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

  int n, x;
  scanf("%d", &n);
  fgetc(stdin);

  for (int i = 0; i < n; i++)
  {
    char input[10];
    scanf("%s", &input);
    fgetc(stdin);

    if (strcmp("push", input) == 0)
    {
      scanf("%d", &x);
      fgetc(stdin);
      push(&s, x);
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
        printf("%d\n", s.data[s.top]);
      }
    }
  }
  return 0;
}