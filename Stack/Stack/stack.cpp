#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return(s->top == -1);
}

int is_full(StackType* s) {
	return(s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		return -1;
	}
	else return s->data[(s->top)--];
}

int main(void) {
	StackType s;
	
	int num;
	printf("실행할 횟수를 입력하세요\n");
	scanf("%d", &num);
	init_stack(&s);

	for (int i = 0; i < num; i++) {
		char pro[10];
		printf("명력을 입력하세요\n");
		gets_s(pro);
		char *ptr = strtok(pro, " ");
		printf("%s", ptr);
		

		if (!strcmp(ptr,"push")) {
			char *cnum = strtok(NULL, " ");
			int num = (int)cnum;
			push(&s, num);
		}
		if (!strcmp(ptr, "pop")) {
			printf("%d\n", pop(&s));
		}
		if (!strcmp(ptr, "size")) {
			printf("%d\n", (s.top + 1));
		}
		if (!strcmp(ptr, "empty")) {
			if (s.top == -1) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		if (!strcmp(ptr, "top")) {
			if (s.top == -1) {
				printf("-1\n");
			}
			else {
				int top1;
				top1 = pop(&s);
				push(&s, top1);
				printf("%d\n", top1);
			}
		}
	}

}