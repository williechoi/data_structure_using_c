#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

int EvalInfixExp(char exp[])
{
    int len = strlen(exp);
    int ret;
    char * expcpy = (char*)malloc(sizeof(char)*len + 1);    // 문자열 저장공간 마련
    strcpy(expcpy, exp);                                    // exp를 expcpy에 복사

    ConvToRPNExp(expcpy);                                   // 후위 표기법 수식으로 변환
    ret = EvalRPNExp(expcpy);                               // 변환된 수식 계산

    free(expcpy);                                           // 문자열 저장공간 해제
    return ret;                                             // 계산결과 반환

}