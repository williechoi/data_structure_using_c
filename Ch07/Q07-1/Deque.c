#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque * pdeq)
{
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

int DQIsEmpty(Deque * pdeq)
{
    if(pdeq->head == NULL)
        return TRUE;
    
    return FALSE;
}

void DQAddFirst(Deque* pdeq, Data data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = pdeq->head;

    if(DQIsEmpty(pdeq)){
        pdeq->tail = newNode;
    } else {
        pdeq->head->prev = newNode;
    }
    pdeq->head = newNode;
}

void DQAddLast(Deque* pdeq, Data data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    newNode->next = NULL;
    newNode->prev = pdeq->tail;

    if(DQIsEmpty(pdeq)){
        pdeq->head = newNode;
    } else {
        pdeq->tail->next = newNode;
    }
    pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque* pdeq)
{
    if(DQIsEmpty(pdeq)){
        printf("Deque Memory error!\n");
        exit(1);
    }

    Node* delNode; 
    Data retData;

    delNode = pdeq->head;
    retData = pdeq->head->data;

    pdeq->head = pdeq->head->next;

    free(delNode);
    if(pdeq->head == NULL) {
        pdeq->tail = NULL;
    } else {
        pdeq->head->prev = NULL;
    }

    return retData;
}


Data DQRemoveLast(Deque* pdeq)
{
    if(DQIsEmpty(pdeq)){
        printf("Deque Memory error!\n");
        exit(1);
    }

    Node* delNode; 
    Data retData;

    delNode = pdeq->tail;
    retData = pdeq->tail->data;

    pdeq->tail = pdeq->tail->prev;
    free(delNode);
    if(pdeq->tail == NULL) {
        pdeq->head = NULL;
    } else {
        pdeq->tail->next = NULL;
    }
    return retData;
}

Data DQGetFirst(Deque* pdeq)
{
    if(DQIsEmpty(pdeq)){
        printf("Deque Memory error!\n");
        exit(1);
    }
    return pdeq->head->data;

}

Data DQGetLast(Deque* pdeq)
{
    if(DQIsEmpty(pdeq)){
        printf("Deque Memory error!\n");
        exit(1);
    }
    return pdeq->tail->data;
}