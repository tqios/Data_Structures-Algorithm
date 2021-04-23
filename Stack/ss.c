//실패
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
int r = 0; // 수열을 만들 수 있는지 없는지 여부 저장 ( 0 : YES, 1 : NO)
element p; // pop의 값을 저장하는 변수

element pop(StackType *s)
{
  if (s->top == -1)
  {
    r = 1;
    p = -2;
    return p;
  }
  else
  {
    p = s->data[(s->top)--];
    return p;
  }
}

char arr[200000]; // +, -를 저장하는 배열 | 값을 모두 받은 후 출력하기 위함
//정수가 100000까지 입력받으므로 이를 push하고 pop할 때 마다 +,-를 저장해야 하므로 100000의 두배인 200000를 배열의 크기로 지정
int a = 0; // arr에 +, -를 저장할 때 index를 지정해 주기 위한 변수

// arr배열에 c 문자를 추가하는 함수
void add(char *arr, char c)
{
  arr[a] = c;
  a++; // 저장할 때 마다 index 값을 증가시킨다
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
      while (1)
      {
        pop(&s);
        add(&arr[0], '-');
        if (p == n)
        {
          break;
        }
        if (p == -2)
        {
          break;
        }
      }
      //else 안의 코드를 간단히 하고싶음
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