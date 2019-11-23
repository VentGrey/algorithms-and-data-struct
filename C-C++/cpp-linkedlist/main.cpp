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

        ~LinkedList() {
            Node *next;

            while (header != NULL) {
                next = header -> next;
                delete header;
                header = next;
            }
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

        void removeLast() {
            if (header -> next == NULL) {
                removeFirst();
            } else if (header != NULL) {
                Node *cur = header;
                Node *prev;

                while (cur -> next != NULL) {
                    prev = cur;
                    cur = cur -> next;
                }

                tail = prev;
                prev -> next = NULL;
                delete cur;
                size--;
            }
        }

        void removeAt(int pos) {
            if (pos > size || pos < 1) {
                return;
            } else if (pos == 1) {
                removeFirst();
            } else if (pos == size) {
                removeLast();
            } else if (header != NULL) {
                Node *cur = header;
                Node *prev;

                for (int i = 1; i < pos; i ++) {
                    prev = cur;
                    cur = cur -> next;
                }
                prev -> next = cur -> next;
                delete cur;
                size--;
            }
        }

        void insertAt(int pos, int data) {
            if (pos > size + 1 || pos < 1) {
                return;
            } else if (pos == 1) {
                prepend(data);
            } else if (pos == size + 1) {
                append(data);
            } else if (header != NULL) {
                Node *n = new Node(data);
                Node *cur = header;
                Node *prev;

                for (int i = 1; i < pos; i++) {
                    prev = cur;
                    cur = cur -> next;
                }

                prev -> next = n;
                n -> next = cur;

                size++;
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
    //list.removeFirst();
    //list.toString();
    list.removeLast();
    list.toString();

    return 0;
}
