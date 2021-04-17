#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



#define MAX_STACK_SIZE 100
int data[MAX_STACK_SIZE];
int top = -1;


void push(int item) {
	data[++top] = item;
}

int pop() {
	if (top == -1) {
		return -1;
	}
	else
		return data[top--];
}

int main(void) {
	
	int loop, num;
	printf("실행할 횟수를 입력하세요\n");
	scanf("%d", &loop);

	for (int i = 0; i < loop; i++) {
		char pro[10];
		printf("명력을 입력하세요\n");
		scanf("%s", &pro);
		

		if (!strcmp(pro,"push")) {
			printf("저장할 수를 입력하세요");
			scanf("%d", &num);
			push(num);
		}
		if (!strcmp(pro, "pop")) {
			printf("%d\n", pop());
		}
		if (!strcmp(pro, "size")) {
			printf("%d\n", (top + 1));
		}
		if (!strcmp(pro, "empty")) {
			if (top == -1) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		if (!strcmp(pro, "top")) {
			if (top == -1) {
				printf("-1\n");
			}
			else {
				int top1;
				top1 = pop();
				push(top1);
				printf("%d\n", top1);
			}
		}
	}

}