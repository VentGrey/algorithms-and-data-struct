//--- Preprocesador
#include <stdlib.h> // Para conversión de cadena a doble
#include <complex.h> // Biblioteca para números complejos
#include <stdio.h>
#include <math.h>

//--- Prototipos
complex double mandelbrot(int max, complex double z0, complex double c);

//--- MAIN
int main(int argc, char const *argv[])
{
        int n = 128;
        int matrix [n][n];
        return 0;
}

//--- Funciones externas

//-- Retornar el número de iteraciones para revisar si c = a + ib pertenece al
//-- conjunto de mandelbrot
complex double mandelbrot(int max, complex double z0, complex double c) {
        if (max > 0) {
                return mandelbrot(max - 1, pow(z0, 2) + c, c);
        } else {
                return z0;
        }
}
