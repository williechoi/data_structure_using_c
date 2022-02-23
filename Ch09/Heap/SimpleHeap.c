#include "SimpleHeap.h"
#include <stdio.h>
#include <stdlib.h>

void HeapInit(Heap* ph)
{
    ph->numOfData = 0;
}

int HIsEmpty(Heap* ph)
{
    if(ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

int GetParentIDX(int idx)
{
    return idx/2;
}

int GetLChildIDX(int idx)
{
    return idx*2;
}

int GetRChildIDX(int idx)
{
    return idx*2 + 1;
}

int GetHiPriChildIDX(Heap* ph, int idx)
{
    int lchldidx = GetLChildIDX(idx);
    int rchldidx = GetRChildIDX(idx);
    
    if(ph->numOfData < lchldidx){
        /**
         * idx가 말단 노드인 경우 (자식 노드 존재 x)
         */ 
        return 0;
    } else if(ph->numOfData < rchldidx) {
        /**
         * 자식 노드가 하나만 있는 경우 (왼쪽)
         */ 
        return lchldidx;
    } else {
        if((ph->heapArr[lchldidx]).pr < (ph->heapArr[rchldidx]).pr){
            return lchldidx;
        } else {
            return rchldidx;
        }
    }
}

/**
 * 힙에 데이터 저장
 */ 
void HInsert(Heap * ph, HData data, Priority pr)
{
    int idx = ph->numOfData + 1;
    HeapElem nelem = {pr, data};
    
    while(idx != 1){
        if(pr < (ph->heapArr[GetParentIDX(idx)].pr)){
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        } else {
            break;
        }
    }
    ph->heapArr[idx] = nelem;
    ph->numOfData++;
}

/**
 * 힙에 데이터 삭제
 */ 
HData HDelete(Heap* ph)
{
    if(HIsEmpty(ph)){
        printf("Heap Error!");
        exit(-1);
    }

    HData retData = (ph->heapArr[1]).data;
    HeapElem lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1;
    int childIdx;

    while(1){
        childIdx = GetHiPriChildIDX(ph, parentIdx);
        if(childIdx == 0)
            break;

        // 마지막 노드와 우선순위 비교
        // 마지막 노드의 우선순위가 높다면 반복문 탈출
        if(lastElem.pr <= (ph->heapArr[childIdx]).pr)
            break;

        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }

    // 반복문을 탈출할 경우 parentIdx에는 마지막 노드의 위치정보가 저장됨
    ph->heapArr[parentIdx] = lastElem;  // 최종 저장
    ph->numOfData--;
    return retData;

}