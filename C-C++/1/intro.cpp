#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Input File Stream
ifstream f("data.in"); // f es el identificador de los datos de entrada.

//Output File Stream
ofstream g("data.out"); // g es el identificador de los datos de salida.

int main() { 
        int x, y, sum; // Ejemplo burdo con 3 variables

        f >> x >> y; 
        // En el archivo f leer el primer valor y asignarlo a X, después el
        //segundo valor y asignarlo a y.

        sum = x + y; // Sumar los 2 valores leidos.

        g << sum; // Escribir en el archivo el valor de suma


        return 0;
}