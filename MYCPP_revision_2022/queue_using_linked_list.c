#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

Node *front = NULL;
Node *rear = NULL;
Node *new_node = NULL;

void enqueue(int num) {
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = num;
	new_node->next = NULL;
	if(rear == NULL & front == NULL) {
		front = new_node;
		rear = new_node;
	} else {
		rear->next = new_node;
		rear = new_node;
	}
}

void dequeue() {
	if(front == NULL & rear == NULL) {
		printf("dequeue : Queue is empty\n");
		return;
	}
	if(front->next == NULL) {
		Node *temp = front;
		printf("dequeued element : %d\n", temp->data);
		free(temp);
		temp = NULL;

		front = NULL;
		rear = NULL;
	} else {
		Node *temp = front;
		front = temp->next;
		printf("dequeued element : %d\n", temp->data);
		free(temp);
		temp = NULL;
	}
}

void print() {
	if(front == NULL) {
		printf("print: Queue is empty\n");
		return;
	}
	printf("print: Queue nodes are : \n");
	Node *temp = front;
	while(temp != NULL) {
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	enqueue(10);
	enqueue(20);
	enqueue(30);
	print();
	dequeue();
	dequeue();
	print();
	dequeue();
	dequeue();
	print();

	return 0;
}