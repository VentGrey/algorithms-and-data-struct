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
};

int main(int argc, char *argv[]) {

    return 0;
}
