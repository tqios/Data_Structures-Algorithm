#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int top = -1;
char stack[100];

void push(char item) {
	stack[++top] = item;
}

char pop() {
	return stack[top--];
}

int check_matching(const char* in) {
	int n = strlen(in);
	char ch, open_ch;
	for (int i = 0; i < n; i++) {
		ch = in[i];
		switch (ch) {
		case '(': case'{': case'[':
			push(ch);
			break;
		case')': case'}': case']':
			if (top == -1) {
				return 0;
			}
			else {
				open_ch = pop();
				if ((open_ch == '(' && ch != ')') || (open_ch == '{' && ch != '}') || (open_ch == '[' && ch != ']')) {
					return 0;
				}
			}
			break;
		}
	}
	if (top != -1) {
		return 0;
	}
	return 1;
}

int main() {
	int num = 0;

	while (num == 0) {
		top = -1;
		char p[100];
		//fgets(p, sizeof(p), stdin); //출력 초과 .에서 멈추지 않음
		//gets_s(p); // 컴파일 에러 gcc에 함수 미포함
		//scanf("%s", &p) //공백 미포함
		scanf("%[.]s",&p); //yes yes yes .....

		if (check_matching(p) == 1) {
			printf("yes\n");
		}

		else {
			printf("no\n");
		}
		if (!strcmp(p, ".")) {
			num = 1;
		}

	};


	return 0;
}