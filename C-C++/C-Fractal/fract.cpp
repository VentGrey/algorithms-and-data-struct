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
        // El fractal estará centrado en...
        double tam = 255;
        int n = 128; // Dimensiones de la imagen (n)
        int m = 128; // Dimensiones de la imagen (m)
        int max = 255; // Número de iteraciones

        int matrix [m][n];
        ofstream mandelbrot("fractal.pgm");
        // Escribir la cabecera del archivo pgm
        mandelbrot << "P2\n" << n << " " << n << endl << tam << endl;
        return 0;
}

//--- Funciones externas

//-- Retornar el número de iteraciones para revisar si c = a + ib pertenece al
//-- conjunto de mandelbrot
int mand(complex<double> z0, int max)
{
        complex<double> Z = z0;

        for (int i = 0; i < max; i++) {
                if (abs(Z) > 2.0) {
                        return i;
                } else {
                        Z = Z * Z + z0;
                }

        }
        return max;
}
