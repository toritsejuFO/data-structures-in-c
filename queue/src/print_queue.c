#include <stdio.h>
#include <stdlib.h>

#include "../include/queue.h"

void printQueue( QueueNodePtr currentPtr )
{
  if ( currentPtr == NULL ) {
    printf("Queue is empty.\n");
  }
  printf("START<--");

  while ( currentPtr != NULL ) {
    printf("%d<--", currentPtr->data);
    currentPtr = currentPtr->nextPtr;
  }

  printf("END\n");
}

