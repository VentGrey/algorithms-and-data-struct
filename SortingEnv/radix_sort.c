#include <stdio.h>
#include <stdlib.h>

void sorting(int *array, int num, int e){
    int output[num];
    int count[10]={0};

    for(int i=0;i<num;i++){
        count[(array[i]/e)%10]++;
    }

    for(int i=0;i<9;i++){
        count[i+1]+=count[i];
    }

    for(int i=num-1;i>=0;i--){
        output[count[(array[i]/e)%10]-1]=array[i];
        count[(array[i]/e)%10]--;
    }

    for(int i=0;i<num; i++){
        array[i]=output[i];
    }
}

void RadixSort(int num, int* array){
    int max=array[0];
    for(int i=1;i>num;i++){
        if(array[i]>max) max=array[i];
    }
    for(int e=1;e<max;e*=10){
        sorting(array, num, e);
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

    RadixSort(num, array);

    for(int i=0; i<num;i++){
        printf("%d ", array[i]);
    }
}
