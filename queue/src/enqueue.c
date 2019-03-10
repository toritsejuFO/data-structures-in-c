#include <stdio.h>
#include <stdlib.h>

#include "../include/queue.h"

void enqueueItem( QueueNodePtr *headPtr, int value )
{
  /* Create queue crawler and tracker */
  QueueNodePtr previousPtr = NULL;
  QueueNodePtr currentPtr = *headPtr;

  /* Create the new node */
  QueueNodePtr newNode = malloc(sizeof(QueueNode));

  /* Should memory allocation succeed */
  if ( newNode != NULL ) {
    newNode->data = value;
    newNode->nextPtr = NULL;

    while ( currentPtr != NULL ) {
      previousPtr = currentPtr;
      currentPtr = currentPtr->nextPtr;
    }
    
    /* CASE 1: Empty queue; Enqueuing first item */
    if ( previousPtr == NULL && currentPtr == NULL ) {
      *headPtr = newNode;
    }
    else { /* CASE 2: Queue with items; Enqueueing at end */
      previousPtr->nextPtr = newNode;
    }
    
    printf("Enqueued\n");
  }
  else {
    printf("\nUnable to to allocate memory for enqueueing. Free heap memory space\n");
  }
}

