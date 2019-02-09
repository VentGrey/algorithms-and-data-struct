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
        std::vector<int32_t> ppuntos; //Vector de enteros sin signo (32 bits)

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
                PGM(int lon, int alt):
                plon(lon),
                palt(alt),
                ppuntos(lon * alt, int32_t())
                {}

                // Si deseamos rellenar el fractal necesitamos escalar los
                // pixeles anteriormente definidos, afortunadamente
                // https://www.geeksforgeeks.org/fractals-in-cc/ existe
                // para medio-fusilarse eso
                void scale(int nlon, int nalt) {
                        ppuntos.scale(nlon * nalt, int16_t()); // Recursive :D
                        plon = nlon;
                        palt = nalt;
                }
};


//--- Namespaces
using namespace std;

//--- Prototipos

//--- MAIN
int main(int argc, char const *argv[])
{
        return 0;
}

//--- Funciones externas
