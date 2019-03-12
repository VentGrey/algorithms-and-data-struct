#include <iostream>
#include <cstdlib>


using namespace std;

// No se como hacer stacks ilimitados, por lo tanto
// mantendré el tope de elementos como 100

const int MAX = 100;

template <class T>
class Stack {
        T *arr;
        int cap;

public:
        explicit Stack(int size = MAX); // Constructores raros de C++
        void push(T);
        T pop();
        T peek();

        int top;
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

//-- Método para retornar el último valor en la pila
template <class T>
T Stack<T>::peek() {
        if(!empty()) {
                return arr[top];
        } else {
                exit(EXIT_FAILURE);
        }
}

//-- *OPCIONAL* Método para revisar el tamaño de la pila, solo se usa en
//-- empty() y en full() pero no es completamente necesario pues se puede
//-- utilizar errno para retornar errores de exceso o falta de elementos en la
//-- pila.
template <class T>
int Stack<T>::size() {
        return top + 1;
}

//-- Método para revisar si la pila está vacía
template <class T>
bool Stack<T>::empty() {
        return size() == 0;
}

//-- Método para revisar si la pila se encuentra llena
template <class T>
bool Stack<T>::full() {
        return size() == cap;
}
