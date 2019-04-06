#include <iostream>
#include <time.h>
#include <stdlib.h> // Para el atoi :v

#include "onemax.hpp"

using namespace std;

int main(int argc, char *argv[]) {


        if (argc == 0) {
                cout << "Ningún argumento fue provisto...saliendo" << endl;
                return -1;
        }


        int m = atoi(argv[1]);
        int n = atoi(argv[2]);
        int gene = atoi(argv[3]);
        int samp =atoi(argv[4]);

        srand(time(NULL));


        cout << "Ingrese el número de individuos" << endl;
        cin >> m;
        cout << "Ingrese el tamaño de los individuos" << endl;
        cin >> n;

        int best = n + 1; // Un espacio extra para contar el número de 1's
        int pob[m][best];

        // Inicializar un eje de la matriz en ceros
        for (int i = 0; i < m; i++) {
                pob[i][0] = 0;
        }

        for (int i = 0; i < m; i++) {
                for (int j = 0; j < best; j++) {
                        if (max() < 0.5)
                                pob[i][j] = 1;
                        else
                                pob[i][j] = 0;
                }
        }


        // Puntero "unsafe" para la población
        int *ptr;
        ptr = &pob[0][0];

        for (int i = 0; i < m; i++) {
                for (int j = 0; j < best; j++) {
                        cout << *(ptr + i*(best) + j) << endl;
                }
                cout << endl;
        }

        cout << endl;

        return 0;
}
