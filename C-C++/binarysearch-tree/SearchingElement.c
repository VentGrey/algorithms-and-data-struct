#include <stdio.h>

typedef int Key;

typedef struct _BSTNode
{
	Key key;
	struct _BSTNode * left_child;
	struct _BSTNode * right_child;
} BSTNode;

BSTNode* Search(BSTNode* root, Key key)
{
	if (root == NULL || root->key == key) return root;
	else if (root->key > key)
		return Search(root->left_child, key);
	else
		return Search(root->right_child, key);
}