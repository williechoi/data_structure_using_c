#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
    List list;
    int data;
    int sum = 0;
    ListInit(&list);

    for(int i=1; i<=9; i++)
    {
        LInsert(&list, i);
    }
    
    printf("List Items: ");
    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        while(LNext(&list, &data))
        {
            printf("%d ", data);
        }
    }

    printf("\n\n");
    if(LFirst(&list, &data))
    {
        sum = data;
        while(LNext(&list, &data))
        {
            sum += data;
        }
    }
    printf("Sum of List data is: %d\n", sum);

    if(LFirst(&list, &data))
    {
        if((data % 2 == 0) || (data % 3 == 0)) LRemove(&list);
        while(LNext(&list, &data))
        {
            if((data % 2 == 0) || (data % 3 == 0)) LRemove(&list);
        }
    }
    
    printf("List Items: ");
    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        while(LNext(&list, &data))
        {
            printf("%d ", data);
        }
    }

    printf("\n\n");
    return 0;

}