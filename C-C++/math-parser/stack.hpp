#include <iostream>
#include <cerrno>
#include <cstdlib>


using namespace std;

// No se como hacer stacks ilimitados, por lo tanto
// mantendré el tope de elementos como 100

const int MAX = 100;

template <class T>
class Stack {
        T *arr;
        int top;
        int cap;

public:
        Stack(int size = MAX); // Constructores raros de C++
        void push(T);
        T pop();
        T peek();

        int size();
        bool empty(), full();
};

//-- Constructores
template <class T>
Stack<T>::Stack(int size) {
        arr = new T[size];
        cap = size;
        top = -1;
}

//-- Método push
template <class T>
void Stack<T>::push(T t) {
        if (full()) {
                cout << "¡No queda espacio en la pila! saliendo..." << endl;
                exit(EXIT_FAILURE); //www.cplusplus.com/reference/cstdlib/exit/
        }

        cout << "Elemento insertado correctamente" << endl;
        arr[top++] = t;
}

//-- Método pop
template <class T>
T Stack<T>::pop() {
        if (empty()) {
                cout << "¡Acceso ilegal! saliendo..." << endl;
                exit(EXIT_FAILURE);
        }

        cout << "Eliminando elemento" << peek() << endl;
        arr[top--];
}
