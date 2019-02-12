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
        const int n = 100;
        const int m = 100;
        int iter = 100;
        int matrix [m][n];

        // Para discretizar la función
        const double sup_real = 1.5; // Límite superior de los números reales
        const double inf_real = -1.5; // Límite inferior de los números reales
        const double sup_imag = 1.0; // Lim superior de los números imaginarios
        const double inf_imag = -1.0; // Lim inferior de los números imaginarios


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
        fprintf(fp, "%d %d \n", n, m);
        fputs("1 \n", fp);
        for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                        fprintf(fp, "%d ", matrix[i][j]);
                }
                fputs("\n", fp);
        }
        /* fputs("",fp); */

        return 0;
}

//--- Funciones externas

//-- Retornar el número de iteraciones para revisar si c = a + ib pertenece al
//-- conjunto de mandelbrot
complex double mandelbrot(int max, complex double z0, complex double c) {
        if (max > 0) {
	  return mandelbrot(max - 1, cpow(z0, 2) + c, c);
        }
	else if (cabs(z0) > 2) {
	  return 0;
        }
	else {
	  return 1;
        }
}
