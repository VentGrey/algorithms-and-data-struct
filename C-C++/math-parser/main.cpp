#include <iostream>
using namespace std;

typedef enum {
        // Números
        num,
        // Paréntesis
        par_izq,
        par_der,
        // Operando (Ordenados por precedencia)
        mult, divi,
        sum, res,
}operando;

operando op;

//-- Prototipos
void siguiente();
void err(string msg);
int ok(operando o);

//-- main
int main(int argc, char* argv[]) {

}

//-- Funciones externas
int ok(operando o) {
        if (op == 0) {
                siguiente();
                return 1;
        }
}
