#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 100
typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType *s) {
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
		printf("���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		printf("���� ��� ����\n");
		exit(1);
	}
	else return s->data[(s->top--)];
}

int check_matching( const char in[]) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);
	init_stack(&s);

	for (i = 0; i < n; i++) {
		ch = in[i];
		switch (ch){
		case'(': case'{': case'[':
			push(&s, ch);
			break;
		case')': case'}': case']':
			if (is_empty(&s)) return 0;
			else {
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}')) {
					return 0;
				}
				break;
			}
		
		}
	}
	if (!is_empty(&s))return 0;
	return 1;

}

int main(void) {
	
	
	if (check_matching("{ A[(i + 1)] = 0; }") == 1)
		printf("��ȣ�˻� ����\n");
	else
		printf("��ȣ�˻� ����\n");
	return 0;
}