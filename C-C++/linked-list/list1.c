#include <stdio.h>
#include <stdlib.h>

typedef	struct {
	int data; // Change data type at will
	struct Node *next;
}Nodo;

// Init as Null so C doesn't fill them with garbage

Node *first = NULL;
Nodo *last = NULL;

void add(Node *node)
{

        node -> next = NULL;

        // If our list is empty then our first value will be the node itself.
	if (first == NULL) {
		first = node;
		last = node;
	} else {
	        last -> next = node;
	        last = node;
	}
}

int main (int argc, char *argv[])
{
	
	return 0;
}

