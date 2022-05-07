#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int data;
	struct node* next;
}Node;

Node* Head = NULL;
Node* cur_node = NULL;

void insert_begin(int num) {
	cur_node = (Node*)malloc(sizeof(Node));
	cur_node->data = num;
	if (Head == NULL) {
		cur_node->next = NULL;
		Head = cur_node;
	}
	else {
		cur_node->next = Head;
		Head = cur_node;
	}
}

void insert_end(int num) {
	if (Head == NULL) {
		printf("List is empty, we cant inset at end, exiting from here...\n");
	} else {
		Node* temp = Head;
		cur_node = (Node*)malloc(sizeof(Node));
		cur_node->data = num;
		cur_node->next = NULL;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = cur_node;
	}
}

void display() {
	Node* temp = Head;
	while (temp != NULL) {
		if (temp->next != NULL) {
			printf("%d <->\t", temp->data);
		}
		else {
			printf("%d\n", temp->data);
		}	
		temp = temp->next;
	}
}

void delete_begin() {
	if (Head == NULL) {
		printf("List is empty, returning...\n");
	}
	else {
		Node* temp = Head;
		Head = temp->next;
		printf("%d is deleting from begin of list\n", temp->data);
		free(temp);
	}
}

void delete_end() {
	if (Head == NULL) {
		printf("List is empty, returning...\n");
	}
	else {
		Node* temp = Head;
		Node* ptemp = Head;
		while (temp->next != NULL) {
			ptemp = temp;
			temp = temp->next;
		}
		ptemp->next = NULL;
		printf("%d is deleting from end of list\n", temp->data);
		free(temp);
	}
}

void clear_nodes() {
	if (Head == NULL) {
		printf("List is empty, returning....\n");
	}
	else {
		Node* temp = Head;
		Node* ptemp = Head;
		while (temp != NULL) {
			ptemp = temp;
			temp = temp->next;
			printf("%d is deleting from list\n", ptemp->data);
			free(ptemp);
		}
		Head = NULL;
	}
}

int main() {
	insert_begin(10);
	insert_end(100);
	insert_end(200);
	insert_end(300);
	insert_end(400);
	insert_end(500);
	display();
	delete_begin();
	display();
	clear_nodes();
	clear_nodes();
	return 0;
}