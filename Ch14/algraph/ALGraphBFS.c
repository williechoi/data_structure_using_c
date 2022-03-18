#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphDFS.h"
#include "DLinkedList.h"
#include "CircularQueue.h"

int WhoIsPrecede(int data1, int data2);

// 그래프 초기화
void GraphInit(ALGraph* pg, int nv)
{
	int i;

	pg->adjList = (List*)malloc(sizeof(List)*nv);		// 간선정보를 저장할 리스트 생성
	pg->visitInfo = (int*)malloc(sizeof(int)*pg->numV);	// 정점의 수를 길이로 하여 배열 할당
	memset(pg->visitInfo, 0, sizeof(int)*pg->numV);		// 배열의 모든 요소를 0으로 초기화

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
		free(pg->adjList);		// 동적으로 할당된 연결리스트 소멸

	if(pg->visitInfo != NULL)
		free(pg->visitInfo);	// 할당된 배열의 소멸
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

int VisitVertex(ALGraph* pg, int visitV)
{
	if(pg->visitInfo[visitV] == 0) {	// visitV에 처음 방문일 때 
		pg->visitInfo[visitV] = 1;		// visitV에 방문한 것으로 기록
		printf("%c > ", visitV + 65);	// 방문한 정점의 이름을 출력
		return TRUE;					// 방문성공!
	}
	return FALSE;						// 방문실패!
}

void BFShowGraphVertex(ALGraph* pg, int startV)
{
	Queue queue;
	int visitV = startV;
	int nextV;

	QueueInit(&queue);			// DFS를 위한 스택 초기화
	
	VisitVertex(pg, visitV);	// 시작 정점 방문
	

	// visitV에 담긴 정점과 연결된 정점의 방문을 시도하는 while문
	while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		if(VisitVertex(pg, nextV) == TRUE) { 	// 방문에 성공했다면
			Enqueue(&queue, nextV);				// nextV에 방문했으니 queue에 저장
		}			
			
		while(LNext(&(pg->adjList[visitV]),&nextV)==TRUE) {	
			if(VisitVertex(pg, nextV) == TRUE) {
				Enqueue(&queue, nextV);			// nextV에 방문했으니 queue에 저장
			}
		}

		if(QIsEmpty(&queue) == TRUE)		// Queue가 비면 BFS 종료
			break;
		else
			visitV = Dequeue(&queue);		// 큐에서 하나 꺼내어 while문 다시 시작
	}

	// 이후의 탐색을 위해 탐색정보 초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);

}