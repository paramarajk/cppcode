#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node* next;
}Node;

Node* Head = NULL;
Node* Head1 = NULL;
Node* new_node = NULL;
Node* temp = NULL;

int len = 0, len1 = 0, len2 = 0;

void insert(char val) {
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = val;
	
	temp = Head;
	if (temp == NULL) {
		new_node->next = NULL;
		Head = new_node;
	}
	else {
		new_node->next = temp;
		Head = new_node;
	}
}

void print(Node **Head) {
	temp = *Head;
	len = 0;
	if (temp == NULL) {
		printf("List is empty\n");
		return;
	}
	else {
		while (temp != NULL) {
			printf("%c\t", temp->data);
			temp = temp->next;
			len++;
		}
		printf("\n");
	}
}

void split_list() {
	Node* fp = Head;
	Node* sp = Head;
	while (fp->next != NULL) {
		fp = fp->next->next;
		sp = sp->next;
	}
	Head1 = sp->next;
	sp->next = NULL;
}


void reverse(Node **Head) {
	
	Node* pre_node = *Head;
	Node* cur_node = (*Head)->next;
	*Head = (*Head)->next;

	pre_node->next = NULL;
	while (*Head != NULL) {
		*Head = (*Head)->next;
		cur_node->next = pre_node;

		pre_node = cur_node;
		cur_node = *Head;
	}
	*Head = pre_node;
}

void check_palindrome() {
	if (len1 == len2) {
		temp = Head;
		while (temp->next != NULL) {
			if (temp->data != Head1->data) {
				printf("Not palindrome\n");
				return;
			}
			temp = temp->next;
		}
	}
	else {
		temp = Head1;
		while (temp->next != NULL) {
			if (temp->data != Head->data) {
				printf("Not palindrome\n");
				return;
			}
			temp = temp->next;
		}
	}
	printf("List is palindrome\n");
}

int main() {
	insert('m');
	insert('a');
	insert('d');
	insert('a');
	insert('m');
	print(&Head);
	split_list();
	print(&Head);
	len1 = len;
	print(&Head1);
	len2 = len;
	reverse(&Head1);
	check_palindrome();
	
	return 0;
}