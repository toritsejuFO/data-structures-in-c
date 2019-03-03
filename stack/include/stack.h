#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef STACK_H
#define STACK_H

struct stackNode {
  int data;
  struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef struct stackNode *StackNodePtr;
typedef union popRet PopRet;

void pushItem( StackNodePtr *headPtr, int value );
long popItem( StackNodePtr *headPtr );
void printStack( StackNodePtr currentPtr );

#endif // STACK_H

