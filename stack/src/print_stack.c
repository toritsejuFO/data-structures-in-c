#include <stdio.h>
#include <stdlib.h>

#include "../include/stack.h"

void printStack( StackNodePtr currentPtr )
{
  if ( currentPtr == NULL ) {
    printf("Stack is empty.\n");
  }
  printf("TOP\n");

  while ( currentPtr != NULL ) {
    printf("[ %d ]\n", currentPtr->data);
    currentPtr = currentPtr->nextPtr;
  }

  printf("BOTTOM\n");
}

