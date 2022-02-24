#include <stdio.h>

void BubbleSort(int arr[], int n)
{
    int i, j;
    int temp;

    for(i=0; i < n; i++){
        for(j=i+1; j < n; j++){
            if(arr[i] > arr[j]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int main(void)
{
    int arr[12] = {3, 2, 1, 0, 999, 4, 8, -22, 7, 533, 23, 6};
    int i;

    BubbleSort(arr, sizeof(arr)/sizeof(int));

    for(i=0; i<12; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}