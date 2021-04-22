#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 50
typedef char element;
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
        return s->data[(s->top--)];
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        StackType s;
        init_stack(&s);

        char ps[50];
        scanf("%s", ps);

        int x = 0;

        for (int j = 0; j < strlen(ps); j++)
        {
            if (ps[j] == '(')
            {
                push(&s, '(');
            }
            else
            {
                if (s.top == -1)
                {
                    printf("NO\n");
                    x++;
                    break;
                }
                else
                {
                    pop(&s);
                }

                if (j == strlen(ps) - 1 && s.top == -1)
                {
                    printf("YES\n");
                    x++;
                }
            }
        }
        if (x == 0)
        {
            printf("NO\n");
        }
    }

    return 0;
}