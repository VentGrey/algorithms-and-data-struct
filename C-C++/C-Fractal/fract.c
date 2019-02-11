//--- Preprocesador
#include <stdlib.h> // Para conversión de cadena a doble
#include <complex.h> // Biblioteca para números complejos
#include <stdio.h>


//--- Prototipos
int mandelbrot(int, int, int);

//--- MAIN
int main(int argc, char const *argv[])
{

        return 0;
}

//--- Funciones externas

//-- Retornar el número de iteraciones para revisar si c = a + ib pertenece al
//-- conjunto de mandelbrot
int mandelbrot(int n, int z, int c) {
        if (n > 0) {
                return mandelbrot(n-1, pow(z, 2) + c, c);
        } else {
                return z;
        }
}
