#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "ListBaseStack.h"


int EvalRPNExp(char exp[])
{
    Stack stack;
    int i;
    int num1, num2, opnum; 
    int expLen = strlen(exp);
    char tok;

    StackInit(&stack);

    for (i=0; i< expLen; i++)
    {
        tok = exp[i];
        if(isdigit(tok)){
            SPush(&stack, atoi(&tok));
        } else {
            num2 = SPop(&stack);    // 두번째 피연산자
            num1 = SPop(&stack);    // 첫번째 피연산자

            switch(tok){
                case '+':
                    opnum = num1 + num2;
                    break;
                case '-':
                    opnum = num1 - num2;
                    break;
                case '*':
                    opnum = num1 * num2;
                    break;
                case '/':
                    if(num2 == 0){
                        printf("Divided by zero Error\n");
                        exit(-1);
                    }

                    opnum = num1 / num2;
                    break;
            }
            SPush(&stack, opnum);
        }
    }

    int finalRes = SPop(&stack);
    return finalRes;
}