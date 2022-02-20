#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue* pq)
{
    pq->front = 0;
    pq->rear = 0;
}

int NextPosIdx(int pos) // return next index of a queue
{
    if(pos == QUE_LEN - 1)
        return 0;
    else
        return pos+1;
}

int QIsEmpty(Queue* pq)
{
    if(pq->front == pq->rear)
        return TRUE;
    
    return FALSE;
}

void Enqueue(Queue* pq, Data data)
{
    if(NextPosIdx(pq->rear) == pq->front)
    {
        printf("Queue memory Error!");
        exit(-1);
    }
    pq->rear = NextPosIdx(pq->rear);
    pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue* pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    pq->front = NextPosIdx(pq->front);
    return pq->queArr[pq->front];
}

Data QPeek(Queue* pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }
    
    return pq->queArr[NextPosIdx(pq->front)];
}
