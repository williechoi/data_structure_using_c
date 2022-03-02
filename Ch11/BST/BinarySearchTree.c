#include <stdio.h>
#include "BinaryTree2.h"
#include "BinarySearchTree.h"


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