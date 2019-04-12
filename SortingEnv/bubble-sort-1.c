//-- Cabeceras
#include <stdio.h>


//-- Prototipos
void swap(int *a, int *b);



//-- Función main
int main(int argc, char *argv[])
{

    return 0;
}



//-- Funciones externas
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
