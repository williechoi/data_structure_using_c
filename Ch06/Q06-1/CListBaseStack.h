#ifndef __C_LIST_BASE_STACK_H__
#define __C_LIST_BASE_STACK_H__

#include "CLinkedList.h"

#define TRUE 1
#define FALSE 0

typedef int Data;


typedef struct _listStack 
{
    List* plist;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPeek(Stack* pstack);
Data SPop(Stack* pstack);


#endif