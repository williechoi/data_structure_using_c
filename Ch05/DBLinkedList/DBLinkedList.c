#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List *plist)
{
    plist->head = NULL;
    plist->numOfData = 0;
}

void LInsert(List* plist, Data data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head;
    if(plist->head != NULL)
        plist->head->prev = newNode;    // 두번째 이후의 노드를 추가할 때만 실행

    newNode->prev = NULL;
    plist->head = newNode;

    (plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)  // 첫번째 노드의 데이터 조회
{
    if(plist->head == NULL)
        return FALSE;

    plist->cur = plist->head;   // 커서를 헤드로 옮긴다.
    *pdata = plist->cur->data;  // 커서의 데이터를 옮겨 담는다.

    return TRUE;

}

int LNext(List* plist, Data *pdata) // 첫번째가 아닌 노드의 데이터 조회
{
    if(plist->cur->next == NULL)
    {
        return FALSE;
    }

    plist->cur = plist->cur->next;  // 커서를 오른쪽으로 이동시키고
    *pdata = plist->cur->data;      // 이동한 커서의 데이터를 옮겨 담는다.

    return TRUE;
}

int LPrevious(List* plist, Data *pdata)
{
    if(plist->cur->prev == NULL)
    {
        return FALSE;
    }

    plist->cur = plist->cur->prev;  // 커서를 왼쪽으로 이동시키고
    *pdata = plist->cur->data;      // 이동한 커서의 노드에 위치한 데이터를 옮겨담는다.

    return TRUE;
}

int LCount(List* plist)
{
    return plist->numOfData;
}