#include <stdio.h>
#include "BinaryTree.h"

/**
 * Inorder Traverse: 중위 순회
 */
void InorderTraverse(BTreeNode* bt) 
{
    if(bt == NULL)
        return;

    InorderTraverse(bt->left);
    printf("%d > ", bt->data);
    InorderTraverse(bt->right);
}

void PreorderTraverse(BTreeNode* bt)
{
    if(bt == NULL)
        return;

    printf("%d > ", bt->data);
    PreorderTraverse(bt->left);
    PreorderTraverse(bt->right);
}

void PostorderTraverse(BTreeNode* bt)
{
    if(bt == NULL)
        return;

    PostorderTraverse(bt->left);
    PostorderTraverse(bt->right);
    printf("%d > ", bt->data);
    
}

int main(void)
{
    BTreeNode *bt1 = MakeBTreeNode();
    BTreeNode *bt2 = MakeBTreeNode();
    BTreeNode *bt3 = MakeBTreeNode();
    BTreeNode *bt4 = MakeBTreeNode();
    BTreeNode *bt5 = MakeBTreeNode();
    BTreeNode *bt6 = MakeBTreeNode();
    BTreeNode *bt7 = MakeBTreeNode();
    BTreeNode *bt8 = MakeBTreeNode();
    BTreeNode *bt9 = MakeBTreeNode();
    BTreeNode *bt10 = MakeBTreeNode();

    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    SetData(bt5, 5);
    SetData(bt6, 6);
    SetData(bt7, 7);
    SetData(bt8, 8);
    SetData(bt9, 9);
    SetData(bt10, 10);

    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);
    MakeRightSubTree(bt2, bt5);
    MakeLeftSubTree(bt3, bt6);
    MakeRightSubTree(bt3, bt7);
    MakeLeftSubTree(bt4, bt8);
    MakeRightSubTree(bt4, bt9);
    MakeLeftSubTree(bt5, bt10);
    


    InorderTraverse(bt1);
    puts("\n=======================");
    PreorderTraverse(bt1);
    puts("\n=======================");
    PostorderTraverse(bt1);

    return 0;
}