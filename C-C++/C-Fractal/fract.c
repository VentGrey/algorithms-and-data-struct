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
        if (argc == 0) {
                printf("Ningún argumento fué provisto!");
                return 0;
        }
        const int n = 50;
        const int m = 50;
        int iter = 50;
        int matrix [m][n];

        // Para discretizar la función
        const double sup_real = 2.0; // Límite superior de los números reales
        const double inf_real = -2.0; // Límite inferior de los números reales
        const double sup_imag = 2.0; // Lim superior de los números imaginarios
        const double inf_imag = -2.0; // Lim inferior de los números imaginarios


        double pX = ((sup_real - inf_real) / n);
        double pY = ((sup_imag - inf_imag) / m);

        complex double C;

        for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                        C = (inf_real + (j * pX)) + ((sup_imag - (i * pY)) * I);
                        matrix[i][j] = mandelbrot(iter, C, C);
                }
        }

        FILE *fp;
        fp = fopen("mandelbrot-fractal.pgm", "w");

        fputs("P2 \n", fp);
        fprintf(fp, "%d %d \n", n, m); //No se pasar 2 argumentos a fputs
        fputs("1 \n", fp);
        for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                        fprintf(fp, "%d ", matrix[i][j]); // Matrices tampoco
                }
                fputs("\n", fp);
        }
        /* fputs("",fp); */ //Al final esto es useless, le daré seguimiento en
        // GitHub

        return 0;
}

//--- Funciones externas

//-- Retornar el número de iteraciones para revisar si c = a + ib pertenece al
//-- conjunto de mandelbrot
complex double mandelbrot(int max, complex double z0, complex double c) {
        if (max > 0) {
                return mandelbrot(max - 1, cpow(z0, 2) + c, c);
        } else if (cabs(z0) > 2) {
                return 0;
        } else {
                return 1;
        }
}
