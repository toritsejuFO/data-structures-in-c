#include <stdio.h>
#include <stdlib.h>

#include "../include/stack.h"

void pushItem( StackNodePtr *headPtr, int value )
{
  /* Create the new node */
  StackNodePtr newNode = malloc(sizeof(StackNode));

  /* Should memory allocation succeed */
  if ( newNode != NULL ) {
    newNode->data = value;
    newNode->nextPtr = *headPtr;
    *headPtr = newNode;

    printf("Pushed\n");
  }
  else {
    printf("\nUnable to to allocate memory for pushing. Free heap memory space\n");
  }
}

