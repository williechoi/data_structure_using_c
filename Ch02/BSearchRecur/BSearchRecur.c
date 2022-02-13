#include <stdio.h>

int BSearchRecur(int ar[], int first, int last, int target)
{
    int mid;
    if(first > last){
        return -1;
    }
    mid = (first + last) / 2;
    
    if(ar[mid] == target){
        return mid;
    } else if (target > ar[mid]){
        return BSearchRecur(ar, mid+1, last, target);
    } else {
        return BSearchRecur(ar, first, mid - 1, target);
    }
}

int main(void)
{
    int arr1[] = {1, 2, 3, 4, 5, 7, 11, 35, 160};
    int idx;

    idx = BSearchRecur(arr1, 0, sizeof(arr1)/sizeof(int), 1);
    if(idx == -1){
        printf("Search Failed!\n");
    } 
    else 
    {
        printf("Target is saved at %d\n", idx);
    }

    return 0;
}