#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 10  //static stack size

typedef struct stack {
	int stack[MAX];
	int top;
}Node;

void push(Node* pu, int item) {
	if (pu->stack[pu->top] == MAX - 1) {
		printf("Stack is full\n");
	}
	else {
		pu->top++;
		pu->stack[pu->top] = item;
	}
}

void pop(Node* po) {
	if (po->stack[po->top] < 0) {
		printf("stack is empty\n");
	}
	else {
		printf("The item %d is popped from stack\n", po->stack[po->top--]);
	}
}

void print(Node* pr) {
	if (pr->stack[pr->top] == -1) {
		printf("stack is empty\n");
	}
	else {
		int i = pr->top;
		while (i >= 0) {
			printf("%d\t", pr->stack[i--]);
		}
		printf("\n");
	}
}

int main() {
	Node* ps = NULL;
	int i, ch, num;
	ps = (Node*)malloc(sizeof(Node));
	ps->top = -1;

	while (1) {
		printf("Enter choice 1/Push, 2/Pop, 3/Print, 4/exit\n");
		scanf("%d", &ch);
		switch (ch) {
		case 1:
			printf("Enter no for push operation\n");
			scanf("%d", &num);
			push(ps, num);
			break;
		case 2:
			pop(ps);
			break;
		case 3:
			print(ps);
			break;
		default:
			printf("Exiting from program\n");
			break;
		}
		if (ch == 0) {
			free(ps);
			break;;
		}
	}
	return 0;
}