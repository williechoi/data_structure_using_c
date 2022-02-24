#include <stdio.h>

void SimpleSort(int arr[], int n)
{
    /**
     * Selection Sort
     */ 
    int i, j;
    int maxIdx;
    int temp;

    for (i=0; i < n; i++) {
        maxIdx = i;
        for (j=i+1; j<n; j++) {
            if (arr[j] < arr[maxIdx]) {
                maxIdx = j;
            }
            if (i != maxIdx) {
                temp = arr[i];
                arr[i] = arr[maxIdx];
                arr[maxIdx] = temp;
            }
        }
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