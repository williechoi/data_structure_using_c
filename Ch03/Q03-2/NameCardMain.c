#include <stdio.h>
#include <stdlib.h>
#include "NameCard.h"
#include "ArrayList.h"

int main(void)
{
    NameCard* pNameCard;
    List list;
    NameCard* pdata;
    char* gname = "Hyungsuk Choi";
    char* cname = "Suok Ahn";
    char* dname = "Eonjin Choi";
    char* phone_num = "010-4805-0090";

    ListInit(&list);
    
    printf("insert three different cards...");
    
    pNameCard = MakeNameCard("Hyungsuk Choi", "010-3258-5790");
    LInsert(&list, pNameCard);
    pNameCard = MakeNameCard("Suok Ahn", "010-4805-0091");
    LInsert(&list, pNameCard);
    pNameCard = MakeNameCard("Eonjin Choi", "010-5257-7243");
    LInsert(&list, pNameCard);
    printf("----------------------------------\n");
    printf("print specific name based on input\n");
    printf("----------------------------------\n");
    if(LFirst(&list, &pdata)){
        if(NameCompare(pdata, gname) == 0){
            ShowNameCardInfo(pdata);
        }

        while(LNext(&list, &pdata))
        {
            if(NameCompare(pdata, gname) == 0){
                ShowNameCardInfo(pdata);
            }
        }
    }
    printf("--------------------------\n");
    printf("show all cards in the list\n");
    printf("--------------------------\n");
    if(LFirst(&list, &pdata)){
        ShowNameCardInfo(pdata);

        while(LNext(&list, &pdata))
        {
            ShowNameCardInfo(pdata);
        }
    }
    printf("----------------------------\n");
    printf("change phone number");
    printf("----------------------------\n");
    if(LFirst(&list, &pdata)){
        if(NameCompare(pdata, cname) == 0){
            ChangePhoneNum(pdata, phone_num);
        }

        while(LNext(&list, &pdata))
        {
            if(NameCompare(pdata, cname) == 0){
                ChangePhoneNum(pdata, phone_num);
            }
        }
    }
    printf("--------------------------\n");
    printf("show all cards in the list\n");
    printf("--------------------------\n");
    if(LFirst(&list, &pdata)){
        ShowNameCardInfo(pdata);

        while(LNext(&list, &pdata))
        {
            ShowNameCardInfo(pdata);
        }
    }
    printf("--------------------------\n");
    printf("delete a card\n");
    printf("--------------------------\n");
    if(LFirst(&list, &pdata)){
        if(NameCompare(pdata, dname) == 0){
            pNameCard = LRemove(&list);
            free(pNameCard);
        }

        while(LNext(&list, &pdata))
        {
            if(NameCompare(pdata, dname) == 0){
                pNameCard = LRemove(&list);
                free(pNameCard);
            }
        }
    }
    printf("--------------------------\n");
    printf("show all cards in the list\n");
    printf("--------------------------\n");
    if(LFirst(&list, &pdata)){
        ShowNameCardInfo(pdata);

        while(LNext(&list, &pdata))
        {
            ShowNameCardInfo(pdata);
        }
    }
    printf("========== program end ======\n");

    return 0;
}
