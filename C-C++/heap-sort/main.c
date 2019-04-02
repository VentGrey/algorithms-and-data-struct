#include <stdio.h>


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

        // Ordenar
        while (heap[0] > 1) {
                last = heap[0];
                temp = heap[1];
                heap[1] = heap[last];
                heap[last] = temp;
                heap[0]--;
                down_adjust(heap, 1);
        }

        printf("Arreglo ordenado:\n");
        for (int i = 1; i =< n ; i++)
                printf("%d ", heap[i]);
        return 0;
}

// Functiones
void create(int heap[]) {
        int n;
        n = heap[0];
        for (int i = n/2; i>=1; i--)
                down_adjust(heap,i);
}

void down_adjust(int heap[], int i) {
       
}
