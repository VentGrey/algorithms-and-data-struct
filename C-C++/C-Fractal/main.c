/**
 * ============================================================================
 *
 *       Filename:  main.c
 *
 *   Coding Style:  Linux Kernel 4.x + Mozilla Coding Guidelines.
 *
 *    Description:  Un programa en C que genera un Fractal de Mandelbrot.
 *
 *        Sources: La información y el código creado fueron posibles gracias a
 *                 las siguientes fuentes de información:
 *
 *                Tutorial de WikiHow:
 *       - https://es.wikihow.com/dibujar-el-conjunto-de-Mandelbrot-manualmente
 *
 *                 Tutorial con Java
 *       - https://underc0de.org/foro/java/conjunto-de-mandelbrot-(fractal)/
 *
 *                 Comparación de datos de Pascal
 *       - https://en.wikipedia.org/wiki/Comparison_of_Pascal_and_C
 *
 *                  Un super código en pascal que no recuerdo de dónde me lo
 *                  fusilé pero que debería de jalar si lo migro y documento
 *
 *        Version:  1.0
 *        Created:  31/01/19 14:23:32
 *       Revision:  1
 *       Compiler:  gcc-6+ or clang-6+
 *
 *        License: BSD Clause 3 - Revisited
 *
 *         Author:  Omar Jair Purata Funes (VentGrey), omarpurataf@gmail.com
 *   Organization:  Universidad de Guanajuato + Future Lab
 *
 * ============================================================================
 */

//--- Preprocesador
#include <stdio.h>
#include <math.h> //Ni se para que voy a ocupar esto pero no vaya a ser
#include <complex.h> /* Biblioteca para números complejos */

//--- Prototipos
int mand(double complex z0, int lim);


//--- MAIN
int main(int argc, char *argv[])
{
        double xc = 500;
        double yc = 500;
        double size = 200;

        int n = 512;
        int max = 255;


        return 0;
}

//--- Funciones externas
int mand(double complex z0, int lim)
{
        double complex Z = z0;
        for (int i = 0; i < lim; i++) {
                if (cabs(Z) > 2.0) return i;
                Z = Z * Z + z0;
        }
        return lim;
}
