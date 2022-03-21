#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphKruskal.h"
#include "DLinkedList.h"
#include "ArrayBaseStack.h"

int WhoIsPrecede(int data1, int data2);

int PQWeightComp(Edge d1, Edge d2)
{
	return d1.weight - d2.weight;
}


void RemoveWayEdge(ALGraph* pg, int fromV, int toV)
{
	int edge;
	if(LFirst(&(pg->adjList[fromV]), &edge)){
		if(edge == toV) {
			LRemove(&(pg->adjList[fromV]));
			return;
		}
	}

	while(LNext(&(pg->adjList[fromV]), &edge)) {
		if(edge == toV) {
			LRemove(&(pg->adjList[fromV]));
			return;
		}
	}
}
void RemoveEdge(ALGraph* pg, int fromV, int toV)
{
	RemoveWayEdge(pg, fromV, toV);
	RemoveWayEdge(pg, toV, fromV);
	(pg->numE)--;
}

void RecoverEdge(ALGraph* pg, int fromV, int toV, int weight) {
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	(pg->numE)++;
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


int IsConnVertex(ALGraph* pg, int v1, int v2)
{
	Stack stack;
	int visitV = v1;
	int nextV;

	StackInit(&stack);			// DFS를 위한 스택 초기화
	VisitVertex(pg, visitV);	// 시작 정점 방문
	SPush(&stack, visitV);		// 시작 정점의 정보를 스택으로

	// visitV에 담긴 정점과 연결된 정점의 방문을 시도하는 while문
	while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		// visitV와 연결된 정점의 정보가 nextV에 담긴 상태에서 진행
		int visitFlag = FALSE;
		
		// 정점을 돌아다니는 도중에 목표를찾는 다면 TRUE를 반환
		if(nextV == v2) { 	
			// 함수를 반환하기 전에 초기화 진행
			memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
			return TRUE;
		} 
		
		if(VisitVertex(pg, nextV) == TRUE) {
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = FALSE;
		} else {	// 방문에 성공하지 못했다면 연결된 다른 정점 찾기
			while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {	
				// 정점을 돌아다니는 중에 목표를 찾았다면  TRUE를 반환한다.	
				if(nextV == v2) {
					// 함수를 반환하기 전에 초기화 진행
					memset(pg->visitInfo, 0, sizeof(int)*pg->numV);

					// 목표를 찾았으니 TRUE 반환
					return TRUE;
				}
				
				if(VisitVertex(pg, nextV) == TRUE) {
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if(visitFlag == FALSE)	// 추가로 방문한 정점이 없다면
		{
			// 스택이 비었을 경우 탐색의 시작점으로 되돌아온 것
			if(SIsEmpty(&stack)==TRUE)	// 시작점으로 돌아왔다!
				break;
			else
				visitV = SPop(&stack); 	// 길을 되돌아간다.

		}

	}

	// 이후의 탐색을 위해 탐색정보 초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	
	// 여기까지 왔다는 것은 목표를 찾지 못했다는 것!
	return FALSE;

}

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

	PQueueInit(&(pg->pqueue), PQWeightComp);
}

// 그래프 리소스 해제
void GraphDestroy(ALGraph* pg)
{
	if(pg->adjList!=NULL)
		free(pg->adjList);		// 동적으로 할당된 연결리스트 소멸

	if(pg->visitInfo != NULL)
		free(pg->visitInfo);	// 할당된 배열의 소멸
}

void AddEdge(ALGraph* pg, int fromV, int toV, int weight)
{
	Edge edge = {fromV, toV, weight};
	// 정점 fromV의 연결리스트에 정점 toV의 정보 추가
	LInsert(&(pg->adjList[fromV]), toV);
	
	// 정점 toV의 연결리스트에 정점 fromV의 정보 추가
	LInsert(&(pg->adjList[toV]), fromV);

	pg->numE += 1;

	PEnqueue(&(pg->pqueue), edge);
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

void ConKruskalMST(ALGraph* pg)
{
	Edge recvEdge[20];
	Edge edge;
	int eidx = 0;
	int i;

	// MST가 형성 될 때까지 아래의 while문을 반복
	while(pg->numE+1 > pg->numV) // MST 간선의 수 + 1 == 정점의 수
	{
		// 우선순위 Queue에서 가중치가 가장 높은 간선의 정보를 꺼냄
		edge = PDequeue(&(pg->pqueue));
		
		// 우선순위 Queue에서 꺼낸 간선을 실제 그래프에서 삭제
		RemoveEdge(pg, edge.v1, edge.v2);

		// 간선을 삭제하고 나서도 두 정점을 연결하는 경로가 있는지 확인
		if(!IsConnVertex(pg, edge.v1, edge.v2)) {
			// 없다면 삭제한 간선 복원
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);

			// 복원한 간선 정도 별도 저장
			recvEdge[eidx++] = edge;
		}
	}

	// 삭제된 간선의 정보를 우선순위 큐에 다시 저장하기 위한 반복문
	for(i=0; i<eidx; i++)
		PEnqueue(&(pg->pqueue), recvEdge[i]);
}

void ShowGraphEdgeWeightInfo(ALGraph* pg)
{
	PQueue copyPQ  = pg->pqueue;
	Edge edge;

	while(!PQIsEmpty(&copyPQ))
	{
		edge = PDequeue(&copyPQ);
		printf("(%c-%c), w: %d \n", edge.v1 + 65, edge.v2 + 65, edge.weight);
	}
}


