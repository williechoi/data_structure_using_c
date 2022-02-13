#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

int WhoIsPrecede(Point* d1, Point* d2)
{
	if(d1->xpos < d2->xpos) 
    {
		return 0;
    }
	else if ((d1->xpos == d2->xpos) && (d1->ypos < d2->ypos))
    {
        return 0;
    } 
    else 
    {
		return 1;
    }
}

int main(void)
{
    List list;
    Point compPos;
    Point *ppos;

    ListInit(&list);
    SetSortRule(&list, WhoIsPrecede);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 1);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 2);
    LInsert(&list, ppos);

    printf("the number of current data points: %d \n", LCount(&list));

    if(LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);

        while(LNext(&list, &ppos))
            ShowPointPos(ppos);
    }
    printf("\n\n");

    compPos.xpos = 2;
    compPos.ypos = 0;

    if(LFirst(&list, &ppos))
    {
        if(PointComp(ppos, &compPos) == 1)
        {
            ppos = LRemove(&list);
            free(ppos);
        }

        while(LNext(&list, &ppos))
        {
            if(PointComp(ppos, &compPos) == 1)
            {
                ppos = LRemove(&list);
                free(ppos);
            }
        }
    }

    printf("The number of current data points: %d \n", LCount(&list));

    if(LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);

        while(LNext(&list, &ppos))
            ShowPointPos(ppos);
    }
    printf("\n\n");

    return 0;

}