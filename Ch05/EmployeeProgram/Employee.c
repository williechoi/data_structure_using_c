#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

void ListInit(List * plist)
{
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
}

void LInsertFront(List* plist, Employee* pemp)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = pemp;

    if(plist->tail == NULL) {
        plist->tail = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }

    (plist->numOfData)++;
}

void LInsert(List * plist, Employee* pemp)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = pemp;

    if(plist->tail==NULL) {
        plist->tail = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode;
    }

    (plist->numOfData)++;
}

int LFirst(List* plist, Employee * pemp)
{
    if(plist->tail == NULL) { // 저장된 노드가 없다면
        return FALSE;
    }

    plist->before = plist->tail;
    plist->cur = plist->tail->next;

    pemp = plist->cur->data;  // cur이 가리키는 노드의 데이터 반환
    return TRUE;
}

int LNext(List* plist, Employee * pemp)
{
    if(plist->tail == NULL) {
        return FALSE;
    }

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    pemp = plist->cur->data;
    return TRUE;

}

Employee* LRemove(List* plist)
{
    Node *rpos = plist->cur;
    Employee* rdata = rpos->data;

    if(rpos == plist->tail)
    {
        if(plist->tail == plist->tail->next)
            plist->tail = NULL;
        else
            plist->tail = plist->before;
    }

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    free(rpos);
    (plist->numOfData)--;
    return rdata;
}

int LCount(List* plist)
{
    return plist->numOfData;
}

char* WhoIsOnDuty(List* plist, char* name, int day)
{   
    int nodeNum, i;
    Employee* temp;
    Employee* whoiswho;
    nodeNum = LCount(plist);

    if(nodeNum < 1){
        return NULL;
    }

    while(1)
    {
        LFirst(plist, temp);
        if(strcmp(temp->name, name)==0)
            break;
        
        for(i=0; i<nodeNum-1; i++)
        {
            LNext(plist, temp);
            if(strcmp(temp->name, name)==0)
                break;
        }
        exit(1);
    }
    for(i=0; i<day; i++)
    {
        LNext(plist, whoiswho);
    }

    return whoiswho->name;
}