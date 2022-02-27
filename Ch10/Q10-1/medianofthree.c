#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int FindMedian(int arr[], int left, int right)
{
    int samples[3] = {left, (left+right)/2, right};

    if(arr[samples[0]] > arr[samples[1]])
        Swap(samples, 0, 1);
    
    if(arr[samples[1]] > arr[samples[2]])
        Swap(samples, 1, 2);
    
    if(arr[samples[0]] > arr[samples[1]])
        Swap(samples, 0, 1);

    return samples[1];
}

int Partition(int arr[], int left, int right)
{
    // left: pivot의 위치
    int pIdx = FindMedian(arr, left, right);
    int pivot = arr[pIdx];
    int low = left + 1;
    int high = right;

    Swap(arr, left, pIdx);

    printf("피벗: %d \n", pivot);

    while(low <= high){
        while(pivot >= arr[low] && low <= right)
            low++;      // low를 오른쪽으로 이동

        while(pivot <= arr[high] && high >= (left+1))
            high--;     // high를 왼쪽으로 이동

        if(low <= high)
            Swap(arr, low, high);
    }

    Swap(arr, left, high);  // pivot과 high가 가리키는 대상을 교환.
    return high;            // 옮겨진 pivot의 위치정보 리턴.
}

void QuickSort(int arr[], int left, int right)
{
    if(left <= right){
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot-1);
        QuickSort(arr, pivot+1, right);
    }
}


int main(void)
{
    // int arr[12] = {3, 2, 1, 0, 999, 4, 8, -22, 7, 533, 23, 6};
    // int arr[12] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    int arr[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int i;

    QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);

    for(i=0; i<15; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}