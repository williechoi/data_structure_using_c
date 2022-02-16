#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void ListInit(List* plist)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    
    plist->head = newNode;
    plist->numOfData = 0;
}

void LInsert(List* plist, Data data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head->next;
    plist->head->next = newNode;

    (plist->numOfData)++;
}

Data LRemove(List* plist)
{
    Node* rptr = plist->cur;
    Data data = rptr->data;

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
    (plist->numOfData)--;

    free(rptr);
    return data;
}

int LFirst(List* plist, Data* pdata)
{
    if(plist->head->next == NULL){
        return FALSE;
    }

    plist->before = plist->head;
    plist->cur = plist->head->next;

    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List* plist, Data* pdata)
{
    if(plist->cur->next == NULL) {
        return FALSE;
    }

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}

int LCount(List* plist)
{
    return plist->numOfData;
}