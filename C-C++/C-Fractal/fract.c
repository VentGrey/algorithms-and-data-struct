//--- Preprocesador
#include <cstdlib> // Para conversión de cadena a doble
#include <complex> // Biblioteca para números complejos
#include <iostream>
#include <fstream>

int n = 128;

//--- Namespaces
using namespace std;

//--- Prototipos
int mand(complex<double> z0, int lim);

//--- MAIN
int main(int argc, char const *argv[])
{
        // El fractal estará centrado en...
        double tam = 255;
        int max = 255; // Número de iteraciones

        ofstream mandelbrot("fractal.pgm");
        // Escribir la cabecera del archivo pgm
        mandelbrot << "P2\n" << n << " " << n << endl << tam << endl;
        return 0;
}

//--- Funciones externas

//-- Retornar el número de iteraciones para revisar si c = a + ib pertenece al
//-- conjunto de mandelbrot
int mandelbrot(int n, int z, int c) {
        if (n > 0) {
                return mandelbrot(n-1, pow(z, 2) + c, c);
        } else {
                return z;
        }
}
