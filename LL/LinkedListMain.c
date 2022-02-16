#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


void mainloop(List* plist)
{
    char ch;
    int nInput, data;
    int idx;
    int isFound;

    while(1) {
        printf("===============================================================================\n");
        printf("메뉴를 입력하세요. (1) 새로운 값 입력, (2) 리스트 조회, (3) 특정 값 조회, (4) 특정 값 삭제, (5) 종료\n");

        scanf("%c%*c", &ch);
        fflush(stdin);
        
        switch(ch)
        {
            case '1':
                printf("새로운 값을 입력하세요 > ");
                scanf("%d%*c", &nInput);
                fflush(stdin);
                LInsert(plist, nInput);
                printf("새로운 값이 입력되었습니다. 리스트에는 총 %d개의 원소가 존재합니다.\n", LCount(plist));
                break;
            case '2':
                if(plist->numOfData == 0) {
                    printf("현재 리스트가 비어있습니다. \n");
                    continue;
                }
                printf("전체 리스트를 조회합니다. \n");

                LFirst(plist, &data);
                printf("%d ", data);
                while(LNext(plist, &data)) {
                    printf("%d ", data);
                }
                printf("\n리스트에는 총 %d개의 원소가 존재합니다.\n", LCount(plist));
                break;
            case '3':
                if(plist->numOfData == 0) {
                    printf("현재 리스트가 비어있습니다. \n");
                    continue;
                }
                printf("조회하고자 하는 값을 입력하세요 > ");
                scanf("%d%*c", &nInput);
                fflush(stdin);
                idx = 1;
                isFound = FALSE;

                LFirst(plist, &data);                
                if(nInput == data) {
                    printf("%d의 위치는 %d입니다.\n", nInput, idx);
                    isFound = TRUE;
                }
                while(LNext(plist, &data)) {
                    idx++;
                    if(nInput == data) {
                        printf("%d의 위치는 %d입니다.\n", nInput, idx);
                        isFound = TRUE;
                    }
                }

                if(!isFound) {
                    printf("값을 찾지 못했습니다.\n");
                }
                break;
            case '4':
                printf("삭제하고자 하는 값을 입력하세요 > ");
                scanf("%d%*c", &nInput);
                fflush(stdin);
                
                idx = 1;
                isFound = FALSE;

                LFirst(plist, &data);                
                if(nInput == data) {
                    printf("%d의 위치는 %d입니다.\n", nInput, idx);
                    isFound = TRUE;
                    LRemove(plist);
                }
                
                while(LNext(plist, &data)) {
                    idx++;
                    if(nInput == data) {
                        printf("%d의 위치는 %d입니다.\n", nInput, idx);
                        isFound = TRUE;
                        LRemove(plist);
                    }
                }
                
                (isFound) ? printf("모두 삭제하였습니다.\n") : printf("해당 값이 리스트에 존재하지 않습니다.\n");
                printf("리스트에는 총 %d개의 원소가 존재합니다.\n", LCount(plist));
                break;
            
            case '5':
                printf("프로그램을 종료합니다.\n");
                return;

            default:
                printf("알 수 없는 값입니다. 다시 입력하세요.\n");
                break;
        }
    }
}


int main(void)
{
    /**
     * 리스트의 생성, 초기화
     */ 
    List list;
    ListInit(&list);

    /**
     * 메인 루프
     */ 
    mainloop(&list);
    
    return 0;
}