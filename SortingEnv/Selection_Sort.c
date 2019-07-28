#include <stdio.h>
#include <stdlib.h>

void Selection_Sort (int *array, int num){
    int max=0;
    int temp=0;
    for(int i=num-1;i>=0;i--){
        max= i;
        for(int j=0;j<i;j++){
            if(array[j]>array[max]){
                max=j;
            }
        }
        temp=array[i];
        array[i]=array[max];
        array[max]=temp;
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    int *array= (int*)malloc(sizeof(int)*num);

    for(int i=0; i<num;i++){
        scanf("%d", &array[i]);
    }

    Selection_Sort(array, num);

    for(int i=0; i<num;i++){
        printf("%d ", array[i]);
    }

    return 0;
}
