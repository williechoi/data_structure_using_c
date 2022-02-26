#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
    int fIdx = left;
    int rIdx = mid + 1;
    int i;

    // 병합할 결과를 담을 배열 sortArr 동적 할당
    int* sortArr = (int*)malloc(sizeof(int)*(right+1));
    int sIdx = left;

    // 병합할 두 영역의 데이터를 비교하여, 
    // 정렬 순서대로 sortArr에 하나씩 옮겨 담는다.
    while(fIdx <= mid && rIdx <= right)
    {
        if(arr[fIdx]<=arr[rIdx]) {
            sortArr[sIdx] = arr[fIdx++];
        } else {
            sortArr[sIdx] = arr[rIdx++];
        }
        sIdx++;
    }

    if(fIdx > mid) { 
        // 배열의 앞부분이 모두 sortArr에 옮겨담겼다면
        // 배열의 뒷부분에 남은 데이터를 sortArr에 옮긴다.
        for(i=rIdx; i<=right; i++, sIdx++) { 
            sortArr[sIdx] = arr[i];
        }
    } else {    
        // 배열의 뒷부분이 sortArr에 옮겨담겼다면
        // 배열의 앞부분에 남은 데이터를 sortArr에 옮겨담는다.
        for(i=fIdx; i<=mid; i++, sIdx++) {
            sortArr[sIdx] = arr[i];
        }
    }

    for(i=left; i<=right; i++) {
        arr[i] = sortArr[i];
    }
    
    free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
    int mid;

    if(left < right)
    {
        mid = (left + right) / 2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);

        MergeTwoArea(arr, left, mid, right);
    }

}

int main(void)
{
    int arr[12] = {3, 2, 1, 0, 999, 4, 8, -22, 7, 533, 23, 6};
    int i;

    MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);

    for(i=0; i<12; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}