#include "list.h"
#include <stdlib.h>
#include <string.h>

Node* create_node(Book* book) {
    Node* node = (Node *) malloc(sizeof (Node));
    strncpy(node -> book.title, book -> title, 50);
    strncpy(node -> book.author, book -> author, 50);
    strncpy(node -> book.isbn, book -> isbn, 13);
    node -> nex = NULL;
    return node;
}
