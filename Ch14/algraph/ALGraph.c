#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"
#include "DLinkedList.h"

int WhoIsPrecede(int data1, int data2);

// 그래프 초기화
void GraphInit(ALGraph* pg, int nv)
{
	int i;

	pg->adjList = (List*)malloc(sizeof(List)*nv);	// 간선정보를 저장할 리스트 생성

	pg->numV = nv;	// 정점 (Vertex)의 수는 주어짐
	pg->numE = 0;	// 간선 수는 초기에 0개

	for(i=0; i<nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}
}

// 그래프 리소스 해제
void GraphDestroy(ALGraph* pg)
{
	if(pg->adjList!=NULL)
		free(pg->adjList);	// 동적으로 할당된 연결리스트 소멸
}

void AddEdge(ALGraph* pg, int fromV, int toV)
{
	// 정점 fromV의 연결리스트에 정점 toV의 정보 추가
	LInsert(&(pg->adjList[fromV]), toV);
	
	// 정점 toV의 연결리스트에 정점 fromV의 정보 추가
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

void ShowGraphEdgeInfo(ALGraph * pg)
{
	int i;
	int vx;

	for(i=0; i<pg->numV; i++)
	{
		printf("%c와 연결된 정점: ", i + 65);

		if(LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 65);

			while(LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

int WhoIsPrecede(int data1, int data2)
{
	if(data1 < data2)
		return 0;
	else
		return 1;
}