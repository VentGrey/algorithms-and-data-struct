#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define	LENGTH 10

typedef int Data;

typedef struct Node {
	Data data;
	struct Node* left;
	struct Node* right;
}BSTnode;
BSTnode* make_node(Data input) {
	BSTnode* result = (BSTnode*)malloc(sizeof(BSTnode));
	result->data = input;
	result->left = NULL;
	result->right = NULL;

	return result;
}

void add_node(BSTnode* root, BSTnode* newNode) {
	while (true) {
		if (newNode->data > root->data) {
			if (root->right != NULL) {
				root = root->right;
				continue;
			}
			else {
				root->right = newNode;
				break;
			}
		}
		else if (newNode->data < root->data) {
			if (root->left != NULL) {
				root = root->left;
				continue;
			}
			else {
				root->left = newNode;
				break;
			}
		}
		else {
			printf("You can not add same data to binarysearch tree.\n");
			exit(1);
		}
	}

	
}
BSTnode* make_binary_search_tree(BSTnode* root, Data* input, int len) {
	if (len < 1) return;
	
	root = make_node(input[0]);

	BSTnode* temp;
	for (int i = 1; i < len; i++) {
		temp = make_node(input[i]);
		add_node(root, temp);
	}

	return root;
}




void inorder_trevasal(BSTnode* root) {
	if (root != NULL) {
		inorder_trevasal(root->left);
		printf("%d ", root->data);
		inorder_trevasal(root->right);
	}
}
void inorder(BSTnode* root) {
	printf("Inorder trevasal : ");
	inorder_trevasal(root);
	printf("\n");
}

void preorder_trevasal(BSTnode* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		preorder_trevasal(root->left);
		preorder_trevasal(root->right);
	}
}
void preorder(BSTnode* root) {
	printf("Preorder trevasal : ");
	preorder_trevasal(root);
	printf("\n");
}

void postorder_trevasal(BSTnode* root) {
	if (root != NULL) {
		postorder_trevasal(root->left);
		postorder_trevasal(root->right);
		printf("%d ", root->data);
	}
}
void postorder(BSTnode* root) {
	printf("Postorder trevasal : ");
	postorder_trevasal(root);
	printf("\n");
}



void destroy_node(BSTnode* node) {
	free(node);
}
void remove_node(BSTnode* root, Data target) {
	BSTnode* cur = root;
	BSTnode* parent = NULL;

	while (cur != NULL && cur->data != target) {
		parent = cur;
		if (cur->data > target) {
			cur = cur->left;
		}
		else {
			cur = cur->right;
		}
	}

	if (cur == NULL) {
		printf("The target does not exist.\n");
		exit(1);
	}

	// case 1 : target node doesn't have child node.
	if (cur->left == NULL && cur->right == NULL) {
		if (parent != NULL) {
			if (parent->left == cur) {
				parent->left = NULL;
			}
			else {
				parent->right = NULL;
			}
		}
	}
	// case 2 : target node has one child node.
	else if (cur->left == NULL || cur->right == NULL) {
		BSTnode* child;

		if (cur->left != NULL) {
			child = cur->left;
		}
		else {
			child = cur->right;
		}

		if (parent != NULL) {
			if (parent->left == cur) {
				parent->left = child;
			}
			else {
				parent->right = child;
			}
		}
	}
	// case 3 : target node has two child node.
	// replace the node with the next node(successor)
	// then handle the successor like case 1 or 2.
	else {
		BSTnode* succ_parent = cur;
		BSTnode* successor = cur->right;

		while (successor->left != NULL) {
			succ_parent = successor;
			successor = successor->left;
		}

		if (succ_parent->right == successor) {
			succ_parent->right = successor->right;
		}
		else {
			succ_parent->left = successor->right;
		}

		cur->data = successor->data;
		cur = successor;
	}

	destroy_node(cur);
}



int main(void) {
	BSTnode* root = NULL;
	Data input[LENGTH] = { 5, 2, 6, 0, 3, 1, 9, 8, 4, 7 };

	printf("Input Data : ");
	for (int i = 0; i < LENGTH; i++) {
		printf("%d ", input[i]);
	}
	printf("\n\n");

	root = make_binary_search_tree(root, input, LENGTH);

	inorder(root);
	preorder(root);
	postorder(root);

	printf("\n");

	printf("remove 7\n");
	remove_node(root, 7); // case 1

	inorder(root);
	preorder(root);
	postorder(root);

	printf("\n");

	printf("remove 6\n");
	remove_node(root, 6); // case 2

	inorder(root);
	preorder(root);
	postorder(root);

	printf("\n");

	printf("remove 2\n");
	remove_node(root, 2); // case 3

	inorder(root);
	preorder(root);
	postorder(root);

	printf("\n");

	return 0;
}
