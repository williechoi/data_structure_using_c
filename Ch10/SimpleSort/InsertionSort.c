#include <stdio.h>

void SimpleSort(int arr[], int n)
{
    /**
     * Insertion Sort
     */ 
    int i, j;
    int insData;

    for (i=1; i < n; i++) {
        insData = arr[i];
        for (j=i-1; j>=0; j--) {
            if (arr[j] > insData)
                arr[j+1] = arr[j];
            else
                break;
        }
        arr[j+1] = insData;
    }
    


}

int main(void)
{
    int arr[12] = {3, 2, 1, 0, 999, 4, 8, -22, 7, 533, 23, 6};
    int i;

    SimpleSort(arr, sizeof(arr)/sizeof(int));

    for(i=0; i<12; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}