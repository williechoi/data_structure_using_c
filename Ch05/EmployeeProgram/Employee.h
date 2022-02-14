#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#define TRUE        1
#define FALSE       0


typedef struct _employee
{
    int number;
    char* name;
} Employee;

typedef struct _node 
{
    Employee* data;
    struct _node* next;
} Node;

typedef struct _CLL
{
    Node * tail;
    Node * cur;
    Node * before;
    int numOfData;
} CList;

typedef CList List;

void ListInit(List * plist);
void LInsert(List * plist, Employee* pemp);      // 꼬리에 노드를 추가
void LInsertFront(List* plist, Employee* pemp);  // 머리에 노드를 추가

int LFirst(List* plist, Employee* pemp);
int LNext(List* plist, Employee* pemp);
Employee* LRemove(List* plist);
int LCount(List* plist);
char* WhoIsOnDuty(List* plist, char* name, int day);

#endif
