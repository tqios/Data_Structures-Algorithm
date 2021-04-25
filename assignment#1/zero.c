#include <stdio.h>

#define MAX_STACK_SIZE 100000
//구조체 스택 정의
typedef struct
{
    int data[MAX_STACK_SIZE];
    int top;
} StackType;
//스택 초기화 함수
void init_stack(StackType *s)
{
    s->top = -1;
}
//입력받은 인자를 스택에 저장하는 함수
void push(StackType *s, int item)
{
    s->data[++(s->top)] = item;
}
//스택에 있는 데이터를 가져오는 함수
int pop(StackType *s)
{
    if (s->top == -1) //스택이 비어있는 경우
    {
        return 0;
    }
    else //스택이 비어있지 않은 경우
    {
        return s->data[(s->top)--];
    }
}

int main(void)
{
    StackType s; //스택을 생성함
    init_stack(&s); //스택을 초기화함

    int loop, num;
    scanf("%d", &loop);
    //입력 받은 수만큼 반복
    for (int i = 0; i < loop; i++)
    {
        scanf("%d", &num);
        //입력받은 수가 0인 경우
        if (num == 0)
        {
            pop(&s); //스택의 데이터를 가져옴
        }
        //입력받은 수가 0이 아닌 경우
        else
        {
            push(&s, num); //입력받은 수를 스택에 저장함
        }
    }

    int sum = 0;
    while (s.top != -1) //스택이 빌때까지 반복함
    {
        sum = sum + pop(&s); //스택에 있는 수를 가져와 sum에 더함
    }

    printf("%d", sum);
    return 0;
}