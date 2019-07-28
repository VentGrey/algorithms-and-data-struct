#include <stdio.h>
#include <stdlib.h>

int Sorting(int *array, int left, int right){
    int low= left+1, high =right;
    int pivot = array[left];
    int temp;
    while(1){
        while(low<right && array[low]<pivot) low++;
        while(high>left && array[high]>=pivot) high--;

        if(high>low){
            temp=array[low];
            array[low]=array[high];
            array[high]=temp;
        }
        else break;
    }
    array[left]=array[high];
    array[high]=pivot;
    return high;
}

void QuickSort(int *array, int left, int right){
    if(left<right){
        int mid=Sorting(array, left, right);

        QuickSort(array, left, mid-1);
        QuickSort(array, mid+1,right);
    }
}

int main()
{
    int num;
    scanf("%d", &num);

    int *array= (int*)malloc(sizeof(int)*num);
    for(int i=0;i<num;i++){
        scanf("%d", &array[i]);
    }

    QuickSort(array, 0, num-1);

    for(int i=0;i<num;i++){
        printf("%d ", array[i]);
    }
}
