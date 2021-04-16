#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
typedef long element;
typedef struct
{
    element data[MAX_STACK_SIZE];
    long top;
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
        return s->data[(s->top--)];
}

int main(void)
{
    StackType s;

    init_stack(&s);

    long k;
    scanf("%ld", &k);

    for (long i = 0; i < k; i++)
    {
        long x;
        scanf("%ld", &x);

        if (x != 0)
        {
            push(&s, x);
        }
        else
        {
            pop(&s);
        }
    }

    long sum = 0;
    for (long i = 0; i <= s.top + 1; i++)
    {
        sum = sum + pop(&s);
    }

    printf("%d", sum);
    return 0;
}