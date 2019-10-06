#include <stdio.h>
#include <stdlib.h>
#define EMPTY -1
#define TRUE (1==1)

/*
  Just set EMPTY to each element of the heap
  @param heap is the array that represents your heap
  @param size is the size of that array
*/

void initiateHeap (int *heap, int size){
	int i;
	for (i=0;i<size;i++) heap[i] = EMPTY;
	return;
}

/*
  Print the elements of the heap in the array order
  @param heap is the array that represents your heap
  @param size is the size of that array
*/

void printHeap (int *heap, int size){
	int i;
	for (i=0; i <size; i++) printf ("%d ",heap[i]);
	return;
}

/*
  Returns the position of the father of the element
  @param pos is the position of the element you want to know it's father
*/

int father (int pos){
	return (pos-1)/2;
}

/*
  Returns the position of the left son of the element
  @param pos is the position of the element you want to know it's left son
*/

int leftSon(int pos){
	return pos*2 +1;
}

/*
  Returns the position of the right son of the element
  @param pos is the position of the element you want to know it's right son
*/

int rightSon (int pos){
	return pos*2 +2;
}

/*
  Swap the elements of two positions in the heap
   @param heap is the array that represents your heap
   @param pos1 is the position of one of the elements you want to swap
   @param pos2 is the postion of the other element you want to swap
*/

void swap (int *heap, int pos1, int pos2){
	int aux;
	aux = heap[pos1];
	heap[pos1] = heap[pos2];
	heap[pos2] = aux;
	return;
}

/*
  Fixes the heap after putting a new element in it by "going up" and comparing the element with it's father until it's everything in order
  @param heap is the array that represents your heap
  @param pos is the position of the new element you put in the heap
*/

void bubbleUp (int *heap, int pos){
	int Father = father(pos);
	
	while (heap[pos] < heap[Father]){ //min heap
		swap (heap, pos, Father);
		pos = Father;
		Father = father(pos);
	}
	return;
}

/*
  Put a new element in the heap
   @param heap is the array that represents your heap
   @param size is the size of that array
   @param n is the element you want to put in the heap
*/

void putOnHeap(int *heap, int size, int n){
	int i;
	for (i=0; i < size; i++){
		if (heap[i] == EMPTY){
			heap[i] = n;
			bubbleUp (heap, i);
			return;
		}
	}
	
	printf ("Heap is full!");
	return;
}

/*
  Pull off an element of the root of the heap
   @param heap is the array that represents your heap
   @param size is the size of that array
*/

int pullOffHeap (int *heap, int size){
	int aux, i, pos=0, ls, rs;
	aux = heap[0];
	
	for (i = size-1; i>0 && heap[i]==EMPTY; i--);
	heap[0] = heap[i];
	heap[i] = EMPTY;
	
	while (TRUE){
		ls = leftSon(pos);
		rs = rightSon(pos);
		if (ls>=size) break;
		else if (heap[ls] == EMPTY) break;
		else if (rs >= size){
			if (heap[pos] > heap[ls]){
				swap (heap, pos, ls);
				pos = ls;
			}
			break;
		}else if (heap[rs]==EMPTY){
			if (heap[pos] > heap[ls]){
				swap (heap, pos, ls);
				pos = ls;
			}
			break;
		}else{
			if (heap[ls] < heap[rs]){
				swap (heap, pos, ls);
				pos = ls;
			}else{
				swap (heap, pos, rs);
				pos = rs;
			}
		}
	}
	
	return aux;
}

/*
  A little application to test the heap
*/

int main (){
	int *heap, option, a, SIZE;
	
  printf("Input the size of the heap: ");
  scanf ("%d",&SIZE);
  
  heap = (int*) malloc(SIZE*sizeof(int));
  
	initiateHeap (heap, SIZE);
	printf ("\n\nMIN HEAP\n\n1 Put number on heap\n2 Pull off heap root\n3 Print heap\n0 Close Program\n\n");
	while (TRUE){
		
		scanf ("%d", &option);
		switch (option){
			case 0:
        free(heap);
				return 0;
			case 1:
				printf ("Input the number you want to put on the heap:\n");
				scanf ("%d", &a);
				putOnHeap(heap, SIZE, a);
				break;
			case 2:
				a = pullOffHeap (heap, SIZE);
				if (a == VAZIO) printf ("Empty heap!");
				else printf ("%d pulled off!\n", a);
				break;
			case 3:
				printHeap(heap, SIZE);
				printf ("\n");
				break;
			default:
				break;
		}
	}
}
