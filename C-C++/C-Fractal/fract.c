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


        const int n = atoi(argv[1]);
        const int m = atoi(argv[2]);
        int iter = atoi(argv[3]);

        // Para discretizar la función
        const double sup_real = atof(argv[4]);
        // Límite superior de los números reales
        const double inf_real = atof(argv[5]);
        // Límite inferior de los números reales
        const double sup_imag = atof(argv[6]);
        // Lim superior de los números imaginarios
        const double inf_imag = atof(argv[7]);
        // Lim inferior de los números imaginarios

        if (argv[1] == 0 || argv[2] == 0) {
                printf("No se aceptan dimensiones 'cero'");
                return 0;
        }

      	if (argv[3] == 0) {
                printf("El iterador no puede ser cero");
                return 0;
      	}

      	if (argv[4] == 0 || argv[5] == 0 || argv[6] == 0 || argv[7] == 0) {
                printf("No se aceptan límites en cero");
                return 0;
        }

        int matrix [m][n];



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
        fp = fopen("mandelbrot-fractal.pgm", "w+");

        fputs("P2 \n", fp);
        fprintf(fp, "%d %d \n", n, m); //No se pasar 2 argumentos a fputs
        fputs("1 \n", fp);
        for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                        fprintf(fp, "%d ", matrix[i][j]); // Matrices tampoco
                }
                fputs("\n", fp);
        }
        /* fputs("",fp); */ //Al final esto es inútil.

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

// No pasarse de la columna 80 >:c
