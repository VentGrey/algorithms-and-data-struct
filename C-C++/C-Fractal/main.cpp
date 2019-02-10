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
        double xC = 100;
        double yC = 100;
        double tam = 10;
        int n = 255; // Dimensiones de la imágen (De nxn)
        int max = 255; // Número de iteraciones

        ofstream mandelbrot("fractal.pgm");
        // Escribir la cabecera del archivo pgm
        mandelbrot << "P2" << endl << n << " " << n << endl << tam << endl;

        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        int x0 = xC - tam/2 + tam * i/n;
                        int y0 = yC - tam/2  + tam * j/n;
                        mandelbrot << x0 << " " << y0;
                }
                mandelbrot << endl;
        }
        mandelbrot.close();

        return 0;
}

//--- Funciones externas

//-- Retornar el número de iteraciones para revisar si c = a + ib pertenece al
//-- conjunto de mandelbrot
int mand(complex<double> z0, int lim)
{
        complex<double> Z = z0;

        for (int i = 0; i < lim; i++) {
                if (abs(Z) > 2.0) {
                        return i;
                } else {
                        Z = Z * Z + z0; //FIXME: Arreglar la precedencia de op aquí.
                }

        }
        return lim;
}
