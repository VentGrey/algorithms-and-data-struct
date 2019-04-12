#include <stdio.h>
#include <time.h>


void create();
void down_adjust();

int main(int argc, char *argv[]) {
        //Iniciar la medición de tiempo de ejecución
        clock_t begin = clock();

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

        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tiempo total de ejecución en CPU: %lf", time_spent);
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
       int j,temp,n,flag=1;
	n=heap[0];

	while(2*i<=n && flag==1)
	{
		j=2*i;    //j points to left child
		if(j+1<=n && heap[j+1] > heap[j])
			j=j+1;
		if(heap[i] > heap[j])
			flag=0;
		else
		{
			temp=heap[i];
			heap[i]=heap[j];
			heap[j]=temp;
			i=j;
		}
	}

}
