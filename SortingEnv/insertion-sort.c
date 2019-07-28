#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b);
void insertion_sort(int* arr, int length);

int main(int argc ,char* argv[]) {

	int arr_size = argc - 1;
	int* arr = (int*)malloc(sizeof(int)*arr_size);

	for (int i = 0; i < arr_size; i++) {
		arr[i] = atoi(argv[i + 1]);
	}

	printf("Before Sorting : ");
	for (int i = 0; i < arr_size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n\n");

	insertion_sort(arr, arr_size);

	printf("After Sorting : ");
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

void insertion_sort(int* arr, int length) {
	int temp = 0;
	int j = 0;

	for (int i = 1; i < length; i++) {
		temp = arr[i];

		for (j = i - 1; j >= 0; j--) {
			if (temp < arr[j]) {
				arr[j + 1] = arr[j];
			}
			else {
				arr[j + 1] = temp;
				break;
			}
		}

		if (j < 0) {
			arr[0] = temp;
		}
	}
}