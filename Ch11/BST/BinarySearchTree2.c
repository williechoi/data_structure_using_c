#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree3.h"
#include "BinarySearchTree2.h"


void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode* bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode** pRoot, BSTData data)
{
	BTreeNode* pNode = NULL;	// parent node
	BTreeNode* cNode = *pRoot;  // current node
	BTreeNode* nNode = NULL;	// new Node

	// find where to add a new node
	while(cNode != NULL)
	{
		if(data == GetData(cNode))
			return;		// does not allow duplicates
		
		pNode = cNode;
		if(GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	// create a new node and save data to it
	nNode = MakeBTreeNode();	// create a new node
	SetData(nNode, data);		// save data

	// add new node as pnode's child

	if(pNode != NULL) { // if new node is not a root node:
		if(data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	} else { // if new node is a root node:
		*pRoot = nNode;
	}
}

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
	BTreeNode* cNode = bst;		// current node
	BSTData cd;					// current data

	while(cNode != NULL){
		cd = GetData(cNode);

		if(target == cd)
			return cNode;
		else if (target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	return NULL;	// no data 
}

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	BTreeNode* pVRoot = MakeBTreeNode();	// virtual root node
	BTreeNode* pNode = pVRoot;				// parent node
	BTreeNode* cNode = *pRoot;				// current node
	BTreeNode* dNode;						// delete node


	// 루트 노드를 pVRoot가 가리키는 노드의 오른쪽 자식 노드가 되게 함.
	ChangeRightSubTree(pVRoot, *pRoot);

	// 삭제 대상인 노드의 탐색
	while(cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;
		if(target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if(cNode == NULL)	// 삭제 대상이 존재하지 않는다면
		return NULL;

	dNode = cNode;	// 삭제 대상을 dNode가 가리키게 함.

	// 삭제 대상이 단말 노드인 경우
	if(GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {
		if(GetLeftSubTree(pNode)==dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	
	// 삭제 대상이 하나의 자식노드를 가지는 경우
	} else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) {
		BTreeNode * dcNode;		// 삭제 대상의 자식 노드 가리킴

		if(GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		if(GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	
	// 삭제 대상이 두 개의 자식노드를 갖는 경우
	} else {
		BTreeNode* mNode = GetRightSubTree(dNode);	// 대체 노드를 가리킴
		BTreeNode* mpNode = dNode;					// 대체 노드의 부모 노드를 가리킴
		int delData;

		// 삭제 대상의 대체 노드를 찾는다.
		while(GetLeftSubTree(mNode) != NULL) {
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		// 대체 노드에 저장된 값을 삭제할 노드에 대입한다.
		delData = GetData(dNode);			// 대입 전 데이터 백업
		SetData(dNode, GetData(mNode));		// 대입

		// 대체 노드의 부모 노드와 자식 노드를 연결한다
		if(GetLeftSubTree(mpNode)==mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData);	// 백업 데이터 복원
	}

	// 삭제된 노드가 루트 노드인 경우에 대한 추가적 처리
	if(GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);	// 루트 노드의 변경 반영

	free(pVRoot);	// 가상 루트 노드의 소멸
	return dNode;	// 삭제 대상 반환
}