
//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}Node;

Node* Head = NULL;
Node* temp = NULL;
Node* new_node = NULL;

void insert(int num) {
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = num;
	
	temp = Head;
	if (temp == NULL) {
		new_node->next = NULL;
		Head = new_node;
	}
	else {
		new_node->next = Head;
		Head = new_node;
	}
}

void display(Node *temp) {
	if (temp == NULL) return;

	printf("%d\t", temp->data);
	display(temp->next);
}

int length(Node* temp) {
	if (temp == NULL) return 0;

	return (1 + length(temp->next));
}

Node* reverse(Node* node) {
	if (node == NULL) return NULL;
	if (node->next == NULL) {
		Head = node;
		return node;
	}

	Node* node1 = reverse(node->next);
	node1->next = node;
	node->next = NULL;
	return node;
}

void print() {
	temp = Head;
	printf("Print func called\n");
	while (temp != NULL) {
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	insert(100);
	insert(200);
	insert(400);
	insert(10);
	printf("The lenth of list : %d\n", length(Head));
	display(Head);
	printf("\n");
	reverse(Head);
	print();

	return 0;
}