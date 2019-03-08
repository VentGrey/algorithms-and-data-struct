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
        
}
