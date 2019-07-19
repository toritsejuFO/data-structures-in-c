#include <stdio.h>
#include <stdlib.h>

#ifndef TREE_H
#define TREE_H

struct treeNode {
  struct treeNode *leftPtr;
  int data;
  struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef struct treeNode *TreeNodePtr;

void insertNode( TreeNodePtr *headPtr, int value );
void deleteNode( TreeNodePtr *headPtr, int value );
void inOrder( TreeNodePtr currentPtr );
void preOrder( TreeNodePtr currentPtr );
void postOrder( TreeNodePtr currentPtr );

#endif TREE_H
