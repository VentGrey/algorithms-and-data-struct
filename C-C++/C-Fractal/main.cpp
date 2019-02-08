/**
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *   Coding Style:  Linux Kernel 4.x + Mozilla Coding Guidelines.
 *
 *    Description:  Un programa en C++ que genera un Fractal de Mandelbrot.
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
 *       Revision:  23
 *       Compiler:  gcc-8+
 *
 *        License: BSD Clause 3 - Revisited
 *
 *         Author:  Omar Jair Purata Funes (VentGrey), omarpurataf@gmail.com
 *   Organization:  Universidad de Guanajuato + Future Lab
 *
 * ============================================================================
 */

//--- Preprocesador
#include <cstdlib> // Para conversión de cadena a doble
#include <complex.h> // Biblioteca para números complejos
#include <iostream>
#include <fstream>

//--- Namespaces
using namespace std;

//--- Prototipos
int mand(complex<double> z0, int lim);

//--- MAIN
int main(int argc, char const *argv[])
{
        if (argc > 2) {
                cout << "Faltan operandos en el programa" << endl;
                cout << "Pruebe 'fract -h' para mas información" << endl;
                return 1;
        } else if (std::string(argv[0]) == "-h") {
                cout << "Modo de empleo: fract [X0] [Y0] [SIZE]" << endl;
                cout << "Estados de salida:" << endl;
                cout << "0 -- Todo fue bien" << endl;
                cout << "1 -- Problema menor" << endl;
                cout << "2 -- Problema mayor" << endl;
                return 0;

        }

        // El fractal estará centrado en...
        double xC = atof(argv[0]);
        double yC = atof(argv[1]);
        double tam = atof(argv[2]);

        int n = 200; // Dimensiones de la imágen (De nxn)
        int max = 255; // Número de iteraciones


        return 0;
}

//--- Funciones externas
int mand(complex<double> z0, int lim)
{
        complex<double> Z = z0;

        for (int i = 0; i < lim; i++) {
                if (abs(Z) > 2.0) return i;
                Z = Z * Z + z0; //FIXME: Arreglar la precedencia de op aquí.
        }
        return lim;
}
