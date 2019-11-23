#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            next = NULL;
        }
};

class LinkedList {
    private:
        Node *header;
        Node *tail;
        int size;

    public:
        LinkedList() {
            header = NULL;
            tail = NULL;
            size = 0;
        }

        int getSize() {
            return size;
        }

        void append(int data) {
            // Crear un nuevo nodo
            Node *n = new Node(data);

            // Si la lista está vacía
            if (header == NULL) {
                header = n;
                tail = n;
            } else {
                tail -> next = n;
                tail = n;
            }

            size++;
        }

        void prepend(int data) {
            Node *n = new Node(data);

            // Si la lista está vacía
            if (header == NULL) {
                header = n;
                tail = n;
            } else {
                Node *tmp = header;
                header = n;
                n -> next = tmp;
            }

            size++;
        }

        void toString() {
            Node *tmp = header;

            while (tmp != NULL) {
                cout << tmp -> data << " ";
                tmp = tmp -> next;
            }
            cout << endl;
        }

        void removeFirst() {
            if (header != NULL) {
                Node *tmp = header;
                header = header -> next;
                delete tmp;
                size--;
            }
        }
};



int main(int argc, char *argv[]) {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.prepend(10);
    list.toString();
    list.removeFirst();
    list.toString();

    return 0;
}
