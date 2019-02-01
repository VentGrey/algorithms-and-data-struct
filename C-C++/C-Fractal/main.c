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


//--- Definición de valores constantes (Tengo más seguridad que con un macro).
//-- Constantes del eje X
const int Zxmax = 800;
const float Cxmax = 1.5;
const float Cxmin = -2.5;

//-- Constantes del eje Y
const int Zymax = 800;
const float Cymax = 2.0;
const float Cymin = -2.0;

//-- Constante de colores (Fusilada de un código de Python)
const int colorval = 255;

//-- Límite de iteraciones (softcoded por ahora)
const int maxiter = 200;


//-- Definición del radio
const int escaperadius = 2;

//--- Prototipos de funciones


//--- Estructura de colores
//TODO: Crear un parser de HEX a RGB
typedef struct colortype {
        char red;
        char green;
        char blue;
}colortype;

//--- MAIN
int main(int argc, char *argv[])
{
        
        return 0;
}

//---Funciones
