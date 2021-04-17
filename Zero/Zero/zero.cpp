#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

int top = -1;
int stack[1000001];

void push(int i) {
	stack[++top] = i;
}

int pop() {
	return stack[top--];
}

int main(){
	int loop, num;
	int sum = 0;

    scanf("%d", &loop);

    for (int i = 0; i < loop; i++) {
	    scanf("%d", &num);
	    if (num == 0) {
		    pop();
	    }
	    else {
		    push(num);
	    }
    }

    while (top != -1) {
	    sum = sum + pop();
    }
    printf("%d", sum);
}