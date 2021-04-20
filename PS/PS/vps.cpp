#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[50];
int top = -1;

void push(char element) {
	stack[++top] = element;
}

int pop() {
	return stack[top--];
}

int check_matching(const char* in) {
	top = -1;
	int n = strlen(in);
	char ch;

	for (int i = 0; i < n; i++) {
		ch = in[i];
		switch (ch) {
		case '(':
			push(ch);
			break;
		case')':
			if (top == -1) {
				return 0;
			}
			else {
				pop();
			}
		}
	}
	if (top != -1)
		return 0;
	return 1;
}

int main() {
	int loop;
	scanf("%d", &loop);
	
	for(int i = 0; i < loop; i++) {
		char p[50];
		int result;
		scanf("%s", p);
		result = check_matching(p);
		if (result == 1)
			printf("YES\n");
		else
			printf("NO\n");

		

	}
	return 0;
}