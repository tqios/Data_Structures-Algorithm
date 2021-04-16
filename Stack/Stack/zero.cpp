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
		fprintf(stderr,"���� ���� ����\n");
	}
	else return s->data[(s->top)--];
}

int main(void) {
	StackType s;
	init_stack(&s)
	int loop;
	printf("�󸶳� �ݺ� �ϰڽ��ϱ�?");
	scanf("%d", &loop);

	for (int i = 0; i < loop; i++) {
		int num;
		scanf("%d", &num);
		if (num == 0) {
			pop(&s);
		}
		else {
			push(&s, num);
		}

	}
}