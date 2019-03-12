#include <iostream>
#include "stack.hpp"
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {

}


//-- Función para revisar la precedencia de operadores
int prec(char op) {

        switch(op) {
        case '^': return 3; // Precedencia 3
        case '~': return 3;

        case '*': return 2; // Precedencia 2
        case '/': return 2;

        case '+': return 1; // Precedencia 1
        case '-': return 1;

        default: exit(EXIT_FAILURE); // Error de entrada
        }
}

int operate(int x, int y, char op) {
        switch (op) {
                case '^': return pow(x,y);
                case '~': return pow(x, 1.0/y);
                case '*': return x * y;
                case '/': return x / y;
                case '+': return x + y;
                case '-': return x - y;
                default: cout << "Operando no reconocido"; exit(EXIT_FAILURE);
  }
}

int eval(string elements) {
        Stack<int> valores;
        Stack<char> ops;

        for (int i = 0; i < elements.length(); i++) {
                if (elements[i] == ' ') {
                        continue;
                } else if (elements[i] == '(') {
                        ops.push(elements[i]);
                } else if (isdigit(elements[i])) {
                        int tmp = 0;
                        while (i < elements.length() && isdigit(elements[i])) {
                                // Me pasé de los 3 niveles -.- el código es
                                // basura ahora.

                                tmp = (tmp * 10) + (elements[i]-'0');
                                i++;
                        }
                        valores.push(tmp);
                } else if (elements[i] == ')') {
                        while (!ops.empty() && ops.peek() != '(') {
                                int a = valores.peek();
                                valores.pop();
                                int b = valores.peek();
                                valores.pop();
                                char op = ops.peek();
                                ops.pop();

                                valores.push(operate(a, b, op));
                        }
                        ops.pop();
                } else {
                        while(!ops.empty() && prec(ops.peek())
                              >= prec(elements[i])) {
                                int a = valores.peek();
                                valores.pop();
                                int b = valores.peek();
                                valores.pop();
                                char op = ops.peek();
                                ops.pop();

                                valores.push(operate(a, b, op));
                        }
                        ops.push(elements[i]);
                }
        }

        while (!ops.empty()) {
                int a = valores.peek();
                valores.pop();
                int b = valores.peek();
                valores.pop();
                char op = ops.peek();
                ops.pop();

                valores.push(operate(a, b, op));
        }
        return valores.peek();
}

