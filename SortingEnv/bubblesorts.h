#ifndef __BUBBLESORTS_H_
#define __BUBBLESORTS_H_

#include < stdio.h >
#include < stdbool.h >


// -- prototyped
void bubble(int *arr);
void bubble_imp(int *arr);

// -- functions
void bubble(int *arr)
{
        int n = sizeof(arr);
        for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                                int tmp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = tmp;
                        }
                }
        }
}

void bubble_imp()
{

}

#endif // __BUBBLESORTS_H_
