//--- Preprocesador
#include <cstdlib> // Para conversión de cadena a doble
#include <complex.h> // Biblioteca para números complejos
#include <iostream> // Basic Input Output Stream
#include <fstream> // Manejo y carga de archivos
#include <vector>     // Con suerte debería funcionar en lugar de usar arreglos
#include <string>       ///
#include <stdexcept> // Excepciones (Más bonitas que las de Java por cierto)
#include <cstdint> // Enteros de un tipo específico

//--- Clases

/* Clase principal para el manejo de imágenes
 * "p" delimiará que atributos son privados porque en C++ no se puede*/
class PGM {
        int plon;
        int palt;
        std::vector<uint32_t> ppuntos; //Vector de enteros sin signo (32 bits)

        public:


                // Constructor de longitud
                int lon() {
                        return plon;
                }

                // Constructor de altura
                int alt() {
                        return palt;
                }

                // Constructor de pixeles dentro del PGM
                int pixel() {
                        return palt * plon;
                }

                // Constructor por defecto de la clase
                // (Generará una imagen de tamaño 0,0)
                PGM():
                        plon(0),
                        palt(0)
                {}

                // Constructor con parámetros (los valores comienzan por 0)
                PGM(int lon, int alt)
                : plon(lon)
                , palt(alt)
                , ppuntos(lon * alt, uint32_t())
                {}

                // Si deseamos rellenar el fractal necesitamos escalar los
                // pixeles anteriormente definidos, afortunadamente
                // https://www.geeksforgeeks.org/fractals-in-cc/ existe
                // para medio-fusilarse eso
};


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

        ofstream mandelbrot("fractal.pgm");
        // Escribir la cabecera del archivo pgm
        mandelbrot << "P2" << endl << n << "" << n << endl << tam << endl;

        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        double x0 = xC - tam/2 + tam * i/n;
                        double y0 = yC - tam/2  + tam * j/n;

                        complex<double> z0 = complex<double>(x0, y0);
                        int black = max - mand(z0, max);
                }
        }

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
