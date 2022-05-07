#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node* next;
}node;

typedef struct stack {
	node *stack;
	int top;
}Node;

void push(Node* pu, int item) {
	node* new_stack = (node*)malloc(sizeof(node));
	node* temp = pu->stack;
	new_stack->data = item;
	new_stack->next = NULL;

	if (temp == NULL) {
		temp = new_stack;
		pu->stack = temp;
		pu->top++;
	}
	else {
		temp = pu->stack;
		if (temp->next == NULL) {
			temp->next = new_stack;
			pu->top++;
		}
		else {
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = new_stack;
			pu->top++;
		}
		
	}
}

void pop(Node* po) {
	if (po->top < 0) {
		printf("stack is empty\n");
	}
	else {
		node* temp = po->stack;
		node* temp1 = temp;
		while (temp->next != NULL) {
			temp1 = temp;
			temp = temp->next;
		}
		printf("The item %d is popped from stack\n", temp->data);
		temp1->next = NULL;
		free(temp);
		po->top--;
	}
}

void print(Node* pr) {
	if (pr->top < 0) {
		printf("stack is empty\n");
	}
	else {
		node* temp = pr->stack;
		while (temp != NULL) {
			printf("%d", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main() {
	Node* ps = NULL;
	int i, ch, num;
	ps = (Node*)malloc(sizeof(Node));
	ps->top = -1;
	ps->stack = NULL;

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
			if (ps != NULL) {
				free(ps);
			}
			break;
		}
	}
	return 0;
}