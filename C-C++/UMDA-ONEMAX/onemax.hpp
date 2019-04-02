#include <iostream>
#include <cstdlib>
#include <time.h>

#ifndef __ONEMAX_H_
#define __ONEMAX_H_

#endif // __ONEMAX_H_

// -- Prototipos de cabecera

static float max();
static int compare();

// Funciones de cabecera

// Esta función muestra la diferencia de
static int compare(void* p1, void* p2) {
    int* arr = (int *)p1;
    int* arr1 = (int *)p2;

    int diff = arr[0] - arr1[0];
    return diff;
}

static float max() {
    return (float)rand() / (float)RAND_MAX;
}
