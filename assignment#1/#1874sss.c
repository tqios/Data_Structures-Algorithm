#include <stdio.h>

#define MAX_STACK_SIZE 100000
typedef int element;
// StackType라는 스택 구조체 정의
typedef struct
{
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

//입력받은 구조체의 top변수를 -1로 초기화
void init_stack(StackType *s)
{
    s->top = -1;
}

void push(StackType *s, element item)
{
    s->data[++(s->top)] = item;
}

int r = 0; // 수열을 만들 수 있는지 여부 저장 ( 0 : YES, 1 : NO)
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
char arr[200000]; // +, -를 저장하는 배열 | 값을 모두 받은 후 출력하기 위함
int a = 0;        // arr에 +, -를 저장할 때 index를 지정해 주기 위한 변수

// arr배열에 c 문자를 추가하는 함수
void add(char *arr, char c)
{
    arr[a] = c;
    a++; // 저장할 때 마다 index 값을 증가시킨다
}

//main 함수
int main(void)
{
    //스택 선언
    StackType s;
    //top을 -1로 초기화
    init_stack(&s);

    //입력할 수열의 길이를 저장하는 변수 loop
    //스택에 push 할 때 1씩 증가하는 변수 x
    //수열을 이루는 정수를 저장하는 변수in
    int loop, x = 0, in;
    //스텍의 크기를 받음
    scanf("%d", &loop);

    //스텍의 크기만큼 반복
    for (int i = 0; i < loop; i++)
    {
        //반복할 때 마다 수열을 이루는 정수를 받는다..
        scanf("%d", &in);

        //in이 x보다 크면
        if (x < in)
        {
            //ln이 x보다 클 동안
            while (x < in)
            {
                //x를 증가시키며 push
                push(&s, ++x);
                //push를 할 때 마다 +를 arr 배열에 넣는다.
                add(&arr[0], '+');
            }
            //반복이 멈추면 pop
            pop(&s);
            //pop을 할 때 마다 -를 arr 배열에 넣는다.
            add(&arr[0], '-');
        }
        //ln이 x보다 크지 않으면
        else
        {
            //무한반복
            while (1)
            {
                //pop을 한 값을 p에 저장
                int p = pop(&s);
                //pop을 할 때 마다 arr 배열에 -을 저장
                add(&arr[0], '-');
                //pop을 한 값이 in과 같거나 스텍이 비어 pop을 했을 때 -2를 리턴하면 종료
                if ((p == in) || (p == -2))
                    break;
            }
        }
    }
    // r==0 이면 수열을 만들 수 있으므로
    if (r == 0)
    {
        //arr의 값들을 차례대로 출력
        for (int i = 0; arr[i] != '\0'; i++)
        {
            printf("%c\n", arr[i]);
        }
    }
    //그렇지 않다면 NO를 출력
    else
    {
        printf("NO");
    }

    return 0;
}
