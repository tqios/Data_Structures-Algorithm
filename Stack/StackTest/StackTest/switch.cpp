#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
    char a[1] = { 'abc' };
    char b[1] = { 'def' };
	strcpy(a, b);

    printf(a);


}