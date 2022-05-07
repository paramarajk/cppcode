

//BST 


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node* left;
	struct node* right;
	int data;
}BST_node;

BST_node* root = NULL;
BST_node* new_node = NULL;
BST_node* temp = NULL;

BST_node* insertnode(BST_node *root, int num) {
	root = (BST_node*)malloc(sizeof(BST_node));
	root->data = num;
	root->right = NULL;
	root->left = NULL;
	return root;
}

BST_node* insert(BST_node *root, int num) {
	if (root == NULL) {
		root = insertnode(root, num);
	} 
	else if (num <= root->data) {
		root->left = insert(root->left, num);
	} 
	else {
		root->right = insert(root->right, num);
	}
	return root;
}


//Depth first technique
//pre-order technique <root><left><right>
void pre_order(BST_node *root) {
	if(root == NULL) return;

	printf("%d\t", root->data);
	pre_order(root->left);
	pre_order(root->right);
}

//in-order <left><root><right>
void in_order(BST_node *root) {
	if(root == NULL) return;

	in_order(root->left);
	printf("%d\t", root->data);
	in_order(root->right);
}

//post-order <left><right><root>
void post_order(BST_node *root) {
	if(root == NULL) return;

	post_order(root->left);
	pre_order(root->right);
	printf("%d\t", root->data);
}

//finding smallest node from tree
int small_node(BST_node *root) {
	if (root == NULL) return 0;

	while(root->left != NULL) {
		root = root->left;
	}
	return root->data;
}


int main() {
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 5);
	root = insert(root, 8);
	root = insert(root, 30);
	
	//calling pre-order
	printf("pre_order\n");
	pre_order(root);
	printf("\n");

	//calling in-order
	printf("in_order\n");
	in_order(root);
	printf("\n");

	//calling post-order
	printf("post_order\n");
	post_order(root);
	printf("\n");

	//finding smallest node
	printf("\nsmallest node from tree : %d\n", small_node(root));

	return 0;
}