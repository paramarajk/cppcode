#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}Node;

Node* Head1 = NULL; //list1
Node* Head2 = NULL; //list2
Node* temp = NULL;
Node* temp1 = NULL;
Node* new_node = NULL;
int len1 = 0, len2 = 0;

void insert(Node **head, int num) {
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = num;

	if (*head == NULL) {
		new_node->next = NULL;
		*head = new_node;
	}
	else {
		new_node->next = *head;
		*head = new_node;
	}
}

void combine_node(int num) {
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = num;
	new_node->next = NULL;

	temp = Head1;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new_node;

	temp = Head2;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new_node;

}

void insert_end(int num) {
	new_node = (Node*)malloc(sizeof(Node));
	new_node->next = NULL;
	new_node->data = num;
	temp = Head1;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new_node;
}

void find_intersection() {
	int dlen = 0;
	if (len1 > len2) {
		dlen = len1 - len2;
		temp = Head1;
		int i = 0;
		while (i++ < dlen) {
			temp = temp->next;
		}
		temp1 = Head2;
		while (temp->next != NULL) {
			if (temp == temp1) {
				printf("Intersection point is : %d\n", temp->data);
				return;
			}
			temp = temp->next;
			temp1 = temp1->next;
		}
		printf("Intersection point not found\n");
	}
	else {
		dlen = len2 - len1;
		temp = Head2;
		int i = 0;
		while (i++ < dlen) {
			temp = temp->next;
		}
		temp1 = Head1;
		while (temp->next != NULL) {
			if (temp == temp1) {
				printf("Intersection point is : %d\n", temp->data);
				return;
			}
			temp = temp->next;
			temp1 = temp1->next;
		}
		printf("Intersection point not found\n");
	}
}

void print() {
	printf("Printing first list\n");
	temp = Head1;
	while (temp != NULL) {
		printf("%d\t", temp->data);
		temp = temp->next;
		len1++;
	}
	printf("\nlen1 is : %d\n", len1);
	printf("Printing second list\n");
	temp = Head2;
	while (temp != NULL) {
		printf("%d\t", temp->data);
		temp = temp->next;
		len2++;
	}
	printf("\n");
	printf("len2 is : %d\n", len2);
}

int find_max(Node** Head) {
	Node* temp = *Head;
	int max = 0;
	
	while (temp != NULL) {
		if (temp->data > max) {
			max = temp->data;
		}
		temp = temp->next;
	}
	return max;
}

/*Removing duplicate from the un sorted list*/
void remove_duplicate(Node** Head, int num) {
	Node* temp = *Head;
	Node* temp1 = NULL;
	
	
	if (temp == NULL && temp->next == NULL) {
		printf("List is having single node / no node\n");
		return;
	}
	else {
		int size = find_max(*Head);
		printf("Size is : %d\n", size);
		int* count = (int*)calloc(0, size * sizeof(int));
		while (temp != NULL) {
			count[temp->data]++;
			if (count[temp->data] > 1) {
				temp1->next = temp->next;
				free(temp);
			}
			temp1 = temp;
			temp = temp->next;
		}
	}
}

int main() {
	insert(&Head1, 10);
	insert(&Head1, 20);
	insert(&Head1, 30);
	insert(&Head1, 40);
	insert(&Head1, 50);
	insert(&Head2, 100);
	insert(&Head2, 200);
	insert(&Head2, 300);
	combine_node(1);
	insert_end(2);
	insert_end(30);
	insert_end(4);
	insert_end(5);
	print();
	find_intersection();
	remove_duplicate(&Head1, 30);
	print();
	return 0;
}

