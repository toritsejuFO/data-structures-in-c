#include <stdio.h>
#include <stdlib.h>

#ifndef STACK_H
#define STACK_H

struct stackNode {
  int data;
  struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef struct stackNode *StackNodePtr;

void pushItem( StackNodePtr *headPtr, int value );
void popItem( StackNodePtr *headPtr );
void printStack( StackNodePtr currentPtr );

#endif // STACK_H

