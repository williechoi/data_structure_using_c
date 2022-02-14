#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Employee.h"

int main(void)
{
    /**
     * 원형 연결 리스트의 생성 및 초기화
     */ 
    List list;
    int i, nodeNum;
    Employee data;
    ListInit(&list);

    Employee* newEmp1 = (Employee*)malloc(sizeof(Employee));
    Employee* newEmp2 = (Employee*)malloc(sizeof(Employee));
    Employee* newEmp3 = (Employee*)malloc(sizeof(Employee));
    Employee* newEmp4 = (Employee*)malloc(sizeof(Employee));

    
    newEmp1->number = 100;
    strcpy(newEmp1->name, "Youngmi Lee");
    
    newEmp2->number = 101;
    strcpy(newEmp2->name, "SunHye Kang");
    
    newEmp3->number = 102;
    strcpy(newEmp3->name, "JungHee Min");
    
    newEmp4->number = 103;
    strcpy(newEmp1->name, "Honam Park");
    /**
     * 리스트에 5개의 데이터를 저장
     */ 
    LInsert(&list, newEmp1);
    LInsert(&list, newEmp2);
    LInsert(&list, newEmp3);
    LInsert(&list, newEmp4);
    
    /**
     * 리스트에 저장된 데이터를 3회 연속 출력
     */ 
    if(LFirst(&list, &data))
    {
        printf("%s ", data.name);

        for(i=0; i<LCount(&list)*3-1; i++)
        {
            if(LNext(&list, &data))
                printf("%d ", data.number);
        }
    }
    printf("\n");

    nodeNum = LCount(&list);

    char* name1 = "Youngmi Lee";
    char name2[30] = {0};

    strncpy(name2, WhoIsOnDuty(&list, name1, 5), sizeof(WhoIsOnDuty(&list, name1, 5)));

    printf("the person on duty is %s \n", name2);


    return 0;

}