#include<stdio.h>
#include<stdlib.h>

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
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)==(MAX_STACK_SIZE-1)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)==-1) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

element peek(StackType* s) {
	if (is_empty(s)==-1) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[s->top];
}

int main() {
	StackType s;
	init_stack(&s);
	int loop, num;
	int sum = 0;
	scanf("%d", &loop);

	for (int i = 0; i < loop; i++) {
		scanf("%d", &num);
		if (num == 0) {
			pop(&s);
		}
		else {
			push(&s, num);
		}
	}

	while (s.top != -1) {
		sum = sum + pop(&s);
	}
	printf("%d", sum);
}