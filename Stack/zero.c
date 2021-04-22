#include <stdio.h>

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
        return 0;
    }
    else
    {
        return s->data[(s->top)--];
    }
}

int main(void)
{
    StackType s;
    init_stack(&s);

    int k;
    scanf("%d", &k);

    int x;
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &x);

        if (x == 0)
        {
            pop(&s);
        }
        else
        {
            push(&s, x);
        }
    }

    int sum = 0;
    while (s.top != -1)
    {
        sum = sum + pop(&s);
    }

    printf("%d", sum);
    return 0;
}