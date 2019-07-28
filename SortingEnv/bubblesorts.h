#ifndef __BUBBLESORTS_H_
#define __BUBBLESORTS_H_

#include <stdio.h>
#include <stdbool.h>


// -- prototyped
void bubble(float arr[]);
void bubble_imp(float arr[]);

// -- functions
void bubble(float arr[])
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

void bubble_imp(float arr[])
{
        int tmp = 0;

        for (int i = 0; i < (int) sizeof(arr); i++) {
                bool swap = false;
                for (int j = 0; j < (int) sizeof(arr); j++) {
                        if (arr[j] > arr[j + 1]) {
                                tmp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = tmp;
                                swap = true;
                        }
                }
                if (!swap)
                        break;
        }
}

void bubble_flag(int arr[], int n)
{

        bool sorted = false;
        int tmp = 0;
        int comps = n -1;

        while (!sorted) {
                sorted = true;
                for (int i = 0; i < comps; i++) {
                        if (arr[i] > arr[i + 1]) {
                                tmp = arr[i];
                                arr[i] = arr[i + 1];
                                arr[i + 1] = tmp;
                                sorted = false;
                        }
                }
                comps --;
        }

}

#endif // __BUBBLESORTS_H_
