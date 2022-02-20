#include <stdio.h>
#include "Deque.h"

int main(void)
{
    Deque deq;
    DequeInit(&deq);

    DQAddFirst(&deq, 1);
    DQAddFirst(&deq, 3);
    DQAddLast(&deq, 9);
    DQAddFirst(&deq, 11);
    DQAddLast(&deq, 15);

    while(!DQIsEmpty(&deq))
        printf("%d ", DQRemoveFirst(&deq));

    printf("\n");
    DQAddFirst(&deq, 31);
    DQAddFirst(&deq, 7);
    DQAddLast(&deq, 1);
    DQAddFirst(&deq, 2);
    DQAddLast(&deq, 5);

    while(!DQIsEmpty(&deq))
        printf("%d ", DQRemoveLast(&deq));

    return 0;
}