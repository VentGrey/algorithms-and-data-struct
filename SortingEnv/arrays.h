#ifndef __ARRAYS_H_
#define __ARRAYS_H_

#include <stdio.h>

void printarr(int *arr);


void printarr(int *arr)
{
        int n = sizeof(arr);

        for (int i = 0; i < n; i++)
                printf("%i ", arr[i]);
        printf("\n");
}

#endif // __ARRAYS_H_
