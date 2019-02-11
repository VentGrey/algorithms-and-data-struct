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
        const double sup_real = 0.5;
        const double inf_real = -1.5;
        const double sup_imag = 1.0;
        const double inf_imag = -1.0;

        double puntoX = ((sup_real - inf_real) / pcalc);
        double puntoY = ((sup_imag - inf_imag) / pcalc);

        if (argc <= 0) {
                printf("No se proporcionaron argumentos, saliendo...");
                return 0;
        }

        for(int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
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
