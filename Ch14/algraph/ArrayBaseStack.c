#include <stdio.h>
#include "ArrayBaseStack.h"
#include <stdlib.h>

void StackInit(Stack* pstack)
{
    pstack->topIndex = -1;
}

int SIsEmpty(Stack* pstack)
{
    if(pstack->topIndex == -1){
        return TRUE;
    }
    return FALSE;
}

void SPush(Stack* pstack, Data data){
    (pstack->topIndex)++;
    pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack* pstack)
{

    if(SIsEmpty(pstack)){
        printf("Cannot pop an item from an empty stack!");
        exit(-1);
    }
    
    int rIdx;
    rIdx = pstack->topIndex;
    (pstack->topIndex)--;
    return pstack->stackArr[rIdx];
}

Data Speek(Stack* pstack)
{
    if(SIsEmpty(pstack)){
        printf("Cannot pop an item from an empty stack!");
        exit(-1);
    }
    
    return pstack->stackArr[pstack->topIndex];
}


