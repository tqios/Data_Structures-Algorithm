//성공
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

int r = 0;
element pop(StackType *s)
{
    if (s->top == -1)
    {
        r = 1;
        return -2;
    }
    else
        return s->data[(s->top)--];
}
char arr[200000];
int a = 0;

void add(char *arr, char c)
{
    arr[a] = c;
    a++;
}

int main(void)
{
    StackType s;

    init_stack(&s);

    int k, x = 0, n;
    scanf("%d", &k);

    for (int i = 0; i < k; i++)
    {
        scanf("%d", &n);

        if (x < n)
        {
            while (x < n)
            {
                push(&s, ++x);
                add(&arr[0], '+');
            }
            pop(&s);
            add(&arr[0], '-');
        }
        else
        {
            int p = pop(&s);
            add(&arr[0], '-');
            while (1)
            {
                if (p == n)
                {
                    break;
                }
                if (p == -2)
                {
                    break;
                }
                p = pop(&s);
                add(&arr[0], '-');
            }
        }
    }

    if (r == 0)
    {
        for (int i = 0; arr[i] != '\0'; i++)
        {
            printf("%c\n", arr[i]);
        }
    }
    else
    {
        printf("NO");
    }

    return 0;
}