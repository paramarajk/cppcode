#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int stack1[MAX], stack2[MAX], top = -1, top1 = -1;

void push(int num) {
	if (top >= MAX) {
		printf("stack is full\n");
	}
	else {
		top++;
		if (top == 0 && ++top1 == 0) {
			stack1[top] = num;
			stack2[top1] = num;
		}
		else if (num < stack2[top1]) {
			top1++;
			stack1[top] = num;
			stack2[top1] = num;
		}
		else {
			stack1[top] = num;
		}
	}
}

void pop() {
	if (top == -1) {
		printf("Stack is empty, not able to pop elements from stack\n");
	}
	else {
		if (stack1[top] == stack2[top1]) {
			stack1[top] = 0;
			stack2[top1] = 0;
			top1--;
		}
		else {
			stack1[top] = 0;
		}
		top--;
	}
}

int Findmin() {
	return stack2[top1];
}

int main() {
	int num, ch;
	while (1) {
		printf("Enter choicer: 1/push, 2/pop, 3/Findmin, 0/Exit\n");
		scanf("%d", &ch);
		if (ch == 1) {
			printf("Enter number to be push into stack\n");
			scanf("%d", &num);
			push(num);
		}
		else if (ch == 2) {
			printf("pop func called\n");
			pop();
		}
		else if (ch == 3) {
			printf("Findmin func called\n");
			printf("Minimum elemet from stack is : %d\n", Findmin());
		}
		else if (ch == 0) {
			return;
		}
	}
	return 0;
}