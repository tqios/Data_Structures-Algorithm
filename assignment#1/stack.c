#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100000
typedef int element;
//구조체 스택 정의
typedef struct
{
  element data[MAX_STACK_SIZE];
  int top;
} StackType;

//스택을 초기화 하는 함수
void init_stack(StackType *s)
{
  s->top = -1;
}

//입력받은 인자를 스택에 저장하는 함수
void push(StackType *s, element item)
{
  s->data[++(s->top)] = item;
}
 //스택에 저장되어 있는 데이터를 불러오는 함수
element pop(StackType *s)
{
  if (s->top == -1) //스택이 비어있을 경우
  {
    return -1;
  }
  else
    return s->data[(s->top)--];
}

int main(void)
{
  StackType s; //스택을 생성함

  init_stack(&s); //스택 초기화

  int loop, num;
  scanf("%d", &loop);
//loop 만큼 반복
  for (int i = 0; i < loop; i++)
  {
    //명령을 임력받음
    char prom[10];
    scanf("%s", &prom);

    //명령이 push인 경우
    if (!strcmp("push", prom))
    {
      scanf("%d", &num);
      push(&s, num);//입력받은 수를 스택에 저장
    }
    //명령이 pop인 경우
    else if (!strcmp("pop", prom))
    {
      printf("%d\n", pop(&s)); //스택에서 데이터를 가져와 출력함
    }
    //명령이 size인 경우
    else if (!strcmp("size", prom))
    {
      printf("%d\n", (s.top + 1));
    }
    //명령이 empty인 경우
    else if (!strcmp("empty", prom))
    {
      if (s.top == -1) //스택이 비었을 경우
      {
        printf("1\n");
      }
      else //스택이 비지 않았을 경우
      {
        printf("0\n");
      }
    }
    //명령이 top인 경우
    if (!strcmp("top", prom))
    {
      if (s.top == -1) //스택이 비었을 경우
      {
        printf("-1\n");
      }
      else //스택이 비지 않았을 경우
      {
        printf("%d\n", s.data[s.top]); //스택 맨 위의 값을 출력함
      }
    }
  }
  return 0;
}