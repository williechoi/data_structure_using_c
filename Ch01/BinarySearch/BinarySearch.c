#include <stdio.h>

int BSearch(int ar[], int len, int target)
{
    int first = 0;
    int last = len - 1;
    int mid;

    while (first <= last)
    {
        mid = (first+last) / 2;
        printf("next index is %d\n", mid);

        if(target == ar[mid])
        {
            return mid;
        }
        else
        {   
            if(target < ar[mid])
                last = mid - 1;
            else
                first = mid + 1;
        }
    }
    return -1;
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15, 225};
    int idx;

    printf("The Size of the array is %d\n", sizeof(arr)/sizeof(int));

    idx = BSearch(arr, sizeof(arr)/sizeof(int), 7);
    if(idx == -1)
    {
        printf("Search failed!\n");
    }
    else
    {
        printf("Target is saved at %d\n", idx);
    }

    idx = BSearch(arr, sizeof(arr)/sizeof(int), 12);
    if(idx == -1)
    {
        printf("Search Failed!\n");
    }
    else 
    {
        printf("Target is saved at %d\n", idx);
    }
    return 0;

}
