#ifndef list_h
#define list_h

#include <stdio.h>
#include "book.h"

typedef struct Node {
        Book book;
        struct Node* nex;
} Node;


typedef struct List {
        Node* head;
} List;

#endif /* List.h */
