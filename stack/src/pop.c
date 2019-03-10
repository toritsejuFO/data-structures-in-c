#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "../include/stack.h"

long popItem( StackNodePtr *headPtr )
{
  /* Create the node pointer for delete node */
  StackNodePtr deleteNode = NULL;

  /* CASE 1: Popping an empty stack */
  if ( *headPtr == NULL ){
    printf("The stack is empty. Pop operation was unsuccessful.\n");
    return INT_MAX + 1;
  }

  /* CASE 2: Popping a populated stack */
  else {
    deleteNode = *headPtr;
    *headPtr = (*headPtr)->nextPtr;
    deleteNode->nextPtr = NULL;

    /* Store popped value into a variable only when it is successfully popped */
    long popped_value = deleteNode->data;

    free(deleteNode);
    return popped_value;
  }
}

