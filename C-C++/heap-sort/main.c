#include <stdio.h>


void create(int[]);
void down_adjust(int [], int);

int main(int argc, char *argv[]) {
    int heap[30], n, last, temp;

    printf("Ingrese el número de elementos: ");
    scanf("%d", &n);

    printf("Ingrese los elementos: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &heap[i]);
    }

    heap[0] = n;
    create(heap);

    return 0;
}
