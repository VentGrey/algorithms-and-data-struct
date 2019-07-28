#include <stdio.h>
#include <stdlib.h>

void Sorting(int* array, int first, int gap, int num){
    int key;
    for(int i= first+gap; i<num; i+=gap){
        key=array[i];
        for(j=i-gap;j>first&&key<array[j];j-=gap){
            array[j+gap]=array[gap];
        }
        array[j+gap]=key;
    }
}

void Shell_Sort(int* array, int num){
    for(int k=num/2;k>0;k/=2){
        if(k%2==0) k++;

        for(int i=0;i<k;i++){
            Sorting(array,i,k,num);
        }
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    int *array=(int*)malloc(sizeof(int)*num);
    for(int i=0;i<num;i++){
        scanf("%d", &array[i]);
    }
    printf("\n");

    Shell_Sort(array, num)

    for(int i=0;i<num;i++){
        printf("%d ", array[i]);
    }
}
