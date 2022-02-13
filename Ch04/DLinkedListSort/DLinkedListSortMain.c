#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2)
{
	if(d1 < d2)
		return 0;
	else
		return 1;
}

int PrintMenu(void)
{
	int nInput;
	printf("Please Select the Command: [1] Add Item, [2] Remove Item, [3] Print Item, [4] Count Item, [5] Exit ");
	scanf("%d", &nInput);
	return nInput;
}

void LPrint(List* plist)
{
	int data;
	printf("Current List elements: ");
	if(LFirst(plist, &data))
	{
		printf("%d ", data);

		while(LNext(plist, &data)){
			printf("%d ", data);
		}
	}
	printf("\n");
}


int main(void)
{
	/*** ArrayList를 초기화합니다. ***/
	List list;
	int data;
	ListInit(&list);
	int nMenu = 0;
	int nItem = 0;

	SetSortRule(&list, WhoIsPrecede);

	printf("Linked List Program Starts!\n");

	while((nMenu = PrintMenu()) != 5) {
		switch (nMenu)
		{
			case 1:
				printf("What number do you want to add? -> ");
				scanf("%d", &nItem);
				LInsert(&list, nItem);
				LPrint(&list);
				break;
			case 2:
				printf("What number do you want to remove? -> ");
				scanf("%d", &nItem);
				LRemove(&list);
				LPrint(&list);
				break;
			case 3:
				LPrint(&list);
				break;
			case 4:
				printf("The number of data in the list: %d\n", LCount(&list));
				break;
			default:
				printf("Unknown Command. Please Try Again!\n");
				break;
		}

	}
	return 0;
}