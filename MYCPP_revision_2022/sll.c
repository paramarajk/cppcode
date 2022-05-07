//single linked list:-
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node *next;
	int data;
}Node;

Node *Head = NULL;
Node *temp = NULL;
Node *temp1 = NULL;
Node *new_node = NULL;

int Count_Node(Node **Head) {
	temp = *Head;
	int count = 0;
	if(temp == NULL) {
		return 0;
	} else {
		while(temp != NULL) {
			count++;
			temp = temp->next;
		}
		return count;
	}
}

void insert_begin(Node **Head, int num) {
	temp = *Head;
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = num;
	if(temp == NULL) {
		new_node->next = NULL;
		*Head = new_node;
	} else {
		new_node->next = *Head;
		*Head = new_node;
	}
}

void insert_end(Node **Head, int num) {
	temp = *Head;
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = num;
	new_node->next = NULL;
	if (temp == NULL) {
		printf("List is empty can't insert node at end.....!!!\n");
	} else {
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new_node;
	}
}

void insert_mid(Node **Head, int num, int pos, int count) {
	temp = *Head;
	int current_pos = 0;
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = num;
	if(temp == NULL | pos >= count) {
		printf("List is empty / enter correct position, we can't insert node at mid...!!!\n");
	} else {
		while(temp->next != NULL) {
			current_pos++;
			if(current_pos == pos) {
				new_node->next = temp->next;
				temp->next = new_node;	
			}
			temp = temp->next;
		}
	}
}

void delete_begin(Node **Head) {
	temp = *Head;
	if(temp == NULL) {
		printf("List is empty , we can't delete from empty list...!!!!\n");
	} else if (temp->next == NULL) {
		free(temp);
		temp = NULL;
		*Head = NULL;
	} else {
		*Head = (*Head)->next;
		free(temp);
		temp = NULL;
	}
}

void delete_end(Node **Head) {
	temp = *Head;
	if(temp == NULL) {
		printf("List is empty, we can't delete from empty list...!!!\n");
	} else {
		while(temp->next != NULL) {
			temp1 = temp;
			temp = temp->next;
		}
		temp1->next = NULL;
		free(temp);
		temp = NULL;	
	}	
}

void print(Node **Head) {
	temp = *Head;
	if(temp == NULL) {
		printf("List is empty...!!!\n");
		return;
	}
	printf("List having below values...\n");
	while(temp != NULL) {
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void delete_complete_list(Node **Head) {
	temp = *Head;
	if(temp == NULL) {
		printf("List is empty...!!!\n");
	} else {
		while(temp != NULL) {
			temp1 = temp;
			temp = temp->next;
			free(temp);
			temp = NULL;
		}
		*Head = NULL;
		printf("Cleared all the elements from list...!!!\n");
	}
}

void reverse(Node **Head) {
	Node *pre_node = *Head;
	Node *cur_node = (*Head)->next;
	*Head = (*Head)->next;

	pre_node->next = NULL;
	while(*Head != NULL) {
		*Head = (*Head)->next;
		cur_node->next = pre_node;
		pre_node = cur_node;
		cur_node = *Head;
	}
	*Head = pre_node;
}

int main() {
	print(&Head);
	insert_begin(&Head, 10);
	print(&Head);
	delete_complete_list(&Head);
	insert_begin(&Head, 20);
	insert_end(&Head, 30);
	insert_end(&Head, 40);
	insert_end(&Head, 50);
	print(&Head);
	delete_begin(&Head);
	delete_end(&Head);
	print(&Head);
	int count = Count_Node(&Head);
	printf("Count is : %d\n", count);
	insert_mid(&Head, 35, 1, count);
	print(&Head);
	reverse(&Head);
	print(&Head);
	delete_complete_list(&Head);
	print(&Head);


	return 0;
}