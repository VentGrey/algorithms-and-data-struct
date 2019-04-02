#include <iostream>
#include <time.h>
#include "onemax.hpp"

using namespace std;

int main(int argc, char *argv[]) {

        srand(time(NULL));
        int m, n, gene, samp;

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
                        if
                }
        }

        return 0;
}
