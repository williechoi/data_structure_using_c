#include <stdio.h>
#include "UsefulHeap.h"

int PriComp(int n1, int n2)
{
    return n2 - n1;         // 오름차순 정렬
    // return n1 - n2;     // 내림차순 정렬
}

void HeapSort(int arr[], int n, PriorityComp pc)
{
    Heap heap;
    int i;

    HeapInit(&heap, pc);

    // 데이터를 모두 힙에 넣는다
    for(i=0; i<n; i++)
        HInsert(&heap, arr[i]);

    // 힙에서 데이터를 모두 꺼낸다.
    for(i=0; i<n; i++)
        arr[i] = HDelete(&heap);
}

int main(void)
{
    int arr[12] = {3, 2, 1, 0, 999, 4, 8, -22, 7, 533, 23, 6};
    int i;

    HeapSort(arr, sizeof(arr)/sizeof(int), PriComp);

    for(i=0; i<12; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}