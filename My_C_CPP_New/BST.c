/*
Binary search tree (BST),
Insert function is used to insert the elements:
sudo code :
	if root -> NULL , then inserting using Get New node function
	else if num <= root-data , then calling recursively insert function , and storing that address as root-left
	else calling recursively insert function , and storing that address as root-right

Traversal technique:-
we are having two types of traversal
1) Breath-first
2) Depth-first

1) Breath-first means , we are visting the nodes level by level , its called level-order traversal
example root-> root-left-> root-right-> root-left-left-> root-left-right-> root-right-left-> root-right-right ....
for this approach we will use the queues for pushing the address and based on above order.

2) Depth-first , its subdivided into three , they are
	a) pre-order  -> visiting the node by folowing order : {<root> <left> <right>}
	b) in-order   -> visiting the node by folowing order : {<left> <root> <right>}
	c) post-order -> visiting the node by folowing order : {<left> <right> <root>}
	Note : In all above technique , we are first visting the left node before visiting right node.

Searching node from the tree:-
sudo code:
	if root -> NULL, then return node is not present
	else if num < root-data, the calling recursively search function, upto finding the node from left sub tree,
	else calling recursively search function, upto finding the node from right sub tree.

Find minimum element from left subtree of root node:-
sudo code:
	if root -> NULL, then return 0
	if root-left != NULL, root - root->left, while root-left != NULL, inside root - root-left,
	print root-data

Deletion technique:-
1) deleting leaf node from the left sub-tree or right sub-tree of root
sudo code:
	a) search the node, find parent of node as well, then make it parent of left/righ is NULL based on situation,
	   free the actual node using free in c/delete in c++


2) deleting node having one child from the left sub-tree or right sub-tree of root
sudo code:
	a) search node, find parent of node as well, then make it parent of left.right to node of child(right/left),
	   free the actual node using free in c/delete in c++

3) deleting node having two child from the left sub-tree or right sub-tree of root
sudo code:
	a) search node, find parent of node as well, then find the smallest node of actual node, and replace this smallest
	   value to actual node, and delete the smallest node from exiting position using the logic of one-child/leaf .

*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}BST_node;

BST_node* root = NULL;
BST_node* new_node = NULL;
BST_node* temp = NULL;

BST_node* queue[SIZE];
int front = -1, rear = -1;

BST_node* Getnewnode(BST_node* root, int num) {
	root = (BST_node*)malloc(sizeof(BST_node));
	root->data = num;
	root->left = NULL;
	root->right = NULL;
	return root;
}

BST_node* Insert(BST_node* root, int num) {
	if (root == NULL) {
		root = Getnewnode(root, num);
	}
	else if (num <= root->data) {
		root->left = Insert(root->left, num);
	}
	else {
		root->right = Insert(root->right, num);
	}
	return root;
}

/*Queue implementation for level order traversal*/
void enque(BST_node *root) {
	if (rear == SIZE - 1) {
		printf("Queue is full\n");
	}
	else {
		if (front == -1) {
			front++;
			rear++;
		}
		queue[rear++] = root;
	}
}

void dequeue() {
	if (rear == -1) {
		printf("ERROR, Queue is empty\n");
	}
	else {
		front++;
		if (front == rear) {
			front = -1;
			rear = -1;
		}
	}
}

int queue_empty() {
	if (front == -1 && rear == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

/*Breath first technique*/
/*level order traversal*/
void level_order(BST_node* root) {
	if (root == NULL) return;

	enque(root);
	while (!queue_empty()) {
		printf("%d\t", queue[front]->data);
		if (queue[front]->left != NULL) enque(queue[front]->left);
		if (queue[front]->right != NULL) enque(queue[front]->right);
		dequeue();
	}
}

/*Depth first technique*/
/*Pre-order: <root><left><right>*/
void pre_order(BST_node* root) {
	if (root == NULL) return;

	printf("%d\t", root->data);
	pre_order(root->left);
	pre_order(root->right);
}

/*In-order: <left><root><right>*/
void in_order(BST_node* root) {
	if (root == NULL) return;

	in_order(root->left);
	printf("%d\t", root->data);
	in_order(root->right);
}

/*Post-order: <left><right><root>*/
void post_order(BST_node* root) {
	if (root == NULL) return;

	post_order(root->left);
	post_order(root->right);
	printf("%d\t", root->data);
}

/*Search node from tree*/
int search_node(BST_node* root, int num) {
	if (root == NULL) return;

	if (root->data == num) return 1;
	else if (num < root->data) search_node(root->left, num);
	else search_node(root->right, num);
}

/*Finding small node from trees*/
int small_node(BST_node* root) {
	if (root == NULL) return;

	while(root->left != NULL) {
		root = root->left;
	}
	return root->data;
}

/*Counding the number of nodes form tree*/
static int count = 0;
int count_node(BST_node* root) {
	if (root != NULL) {
		count_node(root->left);
		count++;
		count_node(root->right);
	}
	return count;
}

/*Counting leaf node from the tree*/
static l_count = 0;
int leaf_count(BST_node* root) {

	if (!root) 
		return 0;
	if (!root->left && !root->right) {
		l_count++;
		return;
	}
	if (root->left) {
		leaf_count(root->left);
	}
	if (root->right) {
		leaf_count(root->right);
	}

	return l_count;
}

/*Get level of given nodes from tree*/
static int level_cnt = 0;
int level_count(BST_node* node, int num, int level) {
	if (!root)
		return 0;
	if (root->data == num)
		return level;
	level = level_count(root->left, num, level + 1);
	if (level != 0)
		return 0;

	
}

int main() {
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 12);
	root = Insert(root, 35);
	root = Insert(root, 55);
	root = Insert(root, 5);
	root = Insert(root, 3);
	root = Insert(root, 7);
	root = Insert(root, 24);
	root = Insert(root, 26);

	/*Depth first technique, pre-order*/
	printf("\nPreorder\n");
	pre_order(root);

	printf("\nInorder\n");
	in_order(root);
	
	printf("\nPostorder\n");
	post_order(root);

	/*Breath first technique*/
	printf("\nLevelorder\n");
	level_order(root);

	/*Searching node from tree*/
	int num = 15;
	if (search_node(root, num)) {
		printf("\nNode %d is found in three\n", num);
	}
	else {
		printf("\nNode %d is not found in tree\n", num);
	}

	/*Finding the smallest node from the tree*/
	printf("Snamllest node from the tree: %d\n", small_node(root));

	/*Counting no of nodes from tree*/
	printf("No of nodes from tree : %d\n", count_node(root));

	/*Counting leaf nodes from tree*/
	printf("Leaf nodes from trees : %d\n", leaf_count(root));
	
	printf("\n");
	return 0;
}