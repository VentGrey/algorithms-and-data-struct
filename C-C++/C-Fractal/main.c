/*
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
 *        Version:  1.0
 *        Created:  31/01/19 14:23:32
 *       Revision:  1
 *       Compiler:  gcc-6+ or clang-6+
 *
 *         Author:  Omar Jair Purata Funes (VentGrey), omarpurataf@gmail.com
 *   Organization:  Universidad de Guanajuato + Future Lab
 *
 * ============================================================================
 */

//--- Preprocesador
#include <stdio.h>


//--- Definición de valores constantes (Tengo más seguridad que con un macro).
//-- Constantes del eje X
//-- Podría declarar todo en una línea, pero sinceramente que flojera
const int xmax = 800;
const int 
