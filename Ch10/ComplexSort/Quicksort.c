#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
    // left: pivot의 위치
    int pivot = arr[left];
    int low = left + 1;
    int high = right;

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
    int arr[12] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    int i;

    QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);

    for(i=0; i<12; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}