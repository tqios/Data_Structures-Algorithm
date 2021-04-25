#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//stack 정의
char stack[50];
int top = -1;

//입력 받은 문자를 stack에 저장
void push(char element)
{
    stack[++top] = element;
}

//stack의 top에 있는 문자를 불러오는 함수
int pop()
{
    return stack[top--];
}

//올바른 괄호 문자열인지 확인하는 함수
//올바르면 1, 올바르지 않으면 0을 return
int check_matching(char *in)
{
    //괄호 문자열의 주소가 들어오면 top을 -1로 초기화
    top = -1;
    int l = strlen(in); //괄호 문자열의 길이를 l에 저장
    char ch;            //문자열의 문자를 하나씩 불러와 저장할 변수 선언

    //loop번 괄호 문자열을 받고 YES or NO를 출력
    for (int i = 0; i < l; i++)
    {

        ch = in[i];
        //괄호 문자열의 문자를 반복으로 i를 증가하며 하나씩 ch 변수에 저장
        switch (ch)
        {
        //ch가 ( 이면 push로 스텍에 ( 를 넣는다
        case '(':
            push(ch);
            break;
        //ch가 )일때
        case ')':
            //스텍이 비어있으면 0을 return
            if (top == -1)
            {
                return 0;
            } //스텍이 비어있지 않으면 pop함수를 실행
            else
            {
                pop();
            }
        }
    } // for
    // 괄호문자열에 대한 검사가 끝난 뒤 스텍이 비어있지 않으면
    if (top != -1)
        return 0; // 0을 return
    // 비어어있으면 올바른 괄호 문자열이므로 1을 return
    return 1;
}
//main 함수
int main()
{
    int loop;
    //loop : 입력 데이터의 수를 저장하는 변수
    scanf("%d", &loop);
    //몇 개의 문자열을 입력할 것인지 입력받는다.

    //loop번 반복하여 실행
    for (int i = 0; i < loop; i++)
    {
        char p[50]; //괄호 문자열을 저장하는 변수 p
        //괄호 문자열의 길이는 50 이하이므로 크기가 50인 배열 선언
        scanf("%s", p); //p를 입력받는다

        //check_matching 함수에 입력받은 괄호문자열이 저장된 배열 p를 넣는다.
        //check_matching으로부터 return된 값이 1이면 올바르다
        if (check_matching(p) == 1)
            printf("YES\n");
        //올바르면 YES를 출력
        else
            printf("NO\n");
        //그렇지 않으면 NO를 출력
    }
    return 0;
}