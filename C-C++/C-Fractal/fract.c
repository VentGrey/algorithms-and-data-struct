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
        const int n = 128;
        const int m = 128;
        int iter = 10000;
        int matrix [m][n];
        int pcalc = 1000;

        // Para discretizar la función
        const double sup_real = 0.5; // Límite superior de los números reales
        const double inf_real = -1.5; // Límite inferior de los números reales
        const double sup_imag = 1.0; // Lim superior de los números imaginarios
        const double inf_imag = -1.0; // Lim inferior de los números imaginarios


        double pX = ((sup_real - inf_real) / pcalc);
        double pY = ((sup_imag - inf_imag) / pcalc);

        complex double C0, Z0;

        for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                        C0 = (inf_real + (j * pX) + (sup_real - (i * pY)) * I);
                }
        }

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
