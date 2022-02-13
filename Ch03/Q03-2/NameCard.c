#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

NameCard* MakeNameCard(char* name, char* phone)
{
    NameCard* namecard;
    
    namecard = (NameCard*)malloc(sizeof(NameCard));
    strncpy(namecard->name, name, strlen(name));
    strncpy(namecard->phone, phone, strlen(phone));
    
    return namecard;
}

void ShowNameCardInfo(NameCard* pcard)
{
    printf("name: %s, phone: %s \n", pcard->name, pcard->phone);
}

int NameCompare(NameCard * pcard, char* name)
{
    if(strcmp(pcard->name, name) == 0)
        return 0;
    else
        return -1;

}

void ChangePhoneNum(NameCard * pcard, char* phone)
{
    strncpy(pcard->phone, phone, strlen(phone));
}