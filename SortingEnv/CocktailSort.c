#include <stdio.h>
#include <stdilb.h>

void swap(int* a, int* b);
void cocktailSort(int* arr, int len);

int main(int argc, char* argv[]) {
	int arr_size = argc - 1;
	int* arr = (int*)malloc(sizeof(int)*arr_size);

	for (int i = 0; i < arr_size; i++) {
		arr[i] = atoi(argv[i + 1]);
	}

	printf("Before sorting : ");
	for (int i = 0; i < arr_size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	cocktailSort(arr, arr_size);

	printf("After sorting : ");
	for (int i = 0; i < arr_size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);

	return 0;
}

void swap(int* a, int* b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
void cocktailSort(int* arr, int len) {
	int start = 0;
	int end = len - 1;

	while (start < end) {
		for (int i = start; i < end; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(&arr[i], &arr[i + 1]);
			}
		}

		end--;

		for (int i = end; i > start; i--) {
			if (arr[i] < arr[i - 1]) {
				swap(&arr[i], &arr[i - 1]);
			}
		}

		start++;
	}
}