//-- Cabeceras
#include <stdio.h>
#include <stdlib.h>

//-- Prototipos
void swap(int *a, int *b);
void sort(int a[], int n);
void printsort(int a[], int tam);

//-- Función main
int main(int argc, char *argv[])
{
        int n = atoi(argv[1]);
        return 0;
}



//-- Funciones externas

void sort(int a[], int n)
{
        int boolean;

        for (int i = 0; i < n - 1; i++) {
                boolean = 0;
                for (int j = 0; j < n - i; j++) {
                        if (a[j] > a[j + 1]) {
                                swap(&a[j], &a[j + 1]);
                                boolean = 1;
                        }
                }
                if (boolean == 0)
                        break;
        }
}


void printsort(int a[], int tam)
{
        for (int i = 0; i < tam; i++) {
                printf("%d ", a[i]);
        }
        printf("\n");
}


// Cambio de variables con punteros
void swap(int *a, int *b)
{
        int tmp = *a;
        *a = *b;
        *b = tmp;
}
