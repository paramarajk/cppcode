#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

Node *Head = NULL;
Node *new_node = NULL;

void push(int num) {
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = num;
	new_node->next = Head;
	Head = new_node;
}

void pop() {
	if(Head == NULL) {
		printf("stack is empty\n");
		return;
	}
	Node *temp = Head;
	Head = Head->next;
	printf("poped element : %d\n", temp->data);
	free(temp);
}

void print() {
	if(Head == NULL) {
		printf("Stack is empty\n");
		return;
	}
	printf("Stack nodes are : \n");
	Node *temp = Head;
	while(temp != NULL) {
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	push(10);
	push(20);
	push(30);
	print();
	pop();
	pop();
	print();
	pop();
	pop();
	print();

	return 0;
}