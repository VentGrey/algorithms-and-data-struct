#include <stdio.h>
#include <stdlib.h>

void Sorting(int *array, int left, int mid, int right){
    int num[right-left];
    int first=left, second=mid+1, i=0;

    while(first<=mid && second<=right){
        if(array[first]<=array[second]){
            num[i++]=array[first++];
        }
        else{
            num[i++]=array[second++];
        }
    }
    if(first>mid){
        while(second<=right){
            num[i++]=array[second++];
        }
    }
    else{
        while(first<=mid){
            num[i++]=array[first++];
        }
    }
    for(int e=0;e<=(right-left);e++){
        array[left+e]=num[e];
    }
}

void Merge_Sort(int *array, int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        Merge_Sort(array, left, mid);
        Merge_Sort(array, mid+1, right);
        Sorting(array, left, mid, right);
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

    Merge_Sort(array, 0, num-1);

    for(int i=0;i<num;i++){
        printf("%d ", array[i]);
    }
}
