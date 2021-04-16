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
		fprintf(stderr, "���� ��ȭ ����\n");
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
	printf("������ Ƚ���� �Է��ϼ���\n");
	scanf("%d", &num);
	init_stack(&s);

	for (int i = 0; i < num; i++) {
		char pro[10];
		printf("����� �Է��ϼ���\n");
		scanf("%s",pro);

		if (!strcmp(pro,"push")) {
			int pushnum;
			printf("������ ���ڸ� �Է��ϼ���\n");
			scanf("%d", &pushnum);
			push(&s, pushnum);
		}
		if (!strcmp(pro, "pop")) {
			printf("%d\n", pop(&s));
		}
		if (!strcmp(pro, "size")) {
			printf("%d\n", (s.top + 1));
		}
		if (!strcmp(pro, "empty")) {
			if (s.top == -1) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		if (!strcmp(pro, "top")) {
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