#include "list.h"
#include <stdlib.h>
#include <string.h>

Node* create_node(Book* book) {
    Node* node = (Node *) malloc(sizeof(Node));
    strncpy(node -> book.title, book -> title, 50);
    strncpy(node -> book.author, book -> author, 50);
    strncpy(node -> book.isbn, book -> isbn, 13);
    node -> nex = NULL;
    return node;
}

void destroy_node(Node* node) {
        free(node);
}

void start_node(List* list, Book* book) {
        Node* node = create_node(book);
        node -> nex = list -> head;
        list -> head = node;
}

void end_node(List* list, Book* book) {
        Node* node = create_node(book);
        if (list -> head == NULL) {
                list -> head = node;
        } else {
                Node* pointer = list -> head;
                while (pointer -> nex) {
                        pointer = pointer -> nex;
                }
                pointer -> nex = node;
        }
}

void before_node(int n, List* list, Book* book) {
        Node* node = create_node(book);
        if (list -> head == NULL) {
                list -> head = node;
        } else {
                Node* pointer = list -> head;
                int position = 0;
                while (position < n && pointer -> nex) {
                        pointer = pointer -> nex;
                        position++;
                }
                node -> nex = pointer -> nex;
                pointer -> nex = node;
        }
}

Book* fetch(int n, List* list) {
        if (list -> head == NULL) {
                return NULL;
        } else {
                Node* pointer = list -> head;
                int position = 0;
                while (position < n && pointer -> nex) {
                        pointer = pointer -> nex;
                        position++;
                }
                if (position != n) {
                        return NULL;
                } else {
                        return &pointer -> book;
                }
        }
}
