#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack* pstack)
{
    pstack->head = NULL;
}

int SIsEmpty(Stack* pstack)
{
    if(pstack->head == NULL){
        return TRUE;
    }
    return FALSE;
}

void SPush(Stack* pstack, Data data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    newNode->data = data;
    newNode->next = pstack->head;
    
    pstack->head = newNode;
}

Data SPop(Stack* pstack)
{
    Node* rpos;
    Data rdata;

    if(SIsEmpty(pstack)) {
        printf("Stack Memory Error!");
        exit(-1);
    }

    rpos = pstack->head;
    pstack->head = rpos->next;
    rdata = rpos->data;
    
    free(rpos);
    return rdata;
}

Data SPeek(Stack* pstack)
{
    if(SIsEmpty(pstack)){
        printf("Stack Memory Error!");
        exit(-1);
    }

    return pstack->head->data;
}