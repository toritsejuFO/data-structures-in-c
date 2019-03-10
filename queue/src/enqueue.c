#include <stdio.h>
#include <stdlib.h>

#include "../include/queue.h"

void enqueueItem( QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int value )
{
  /* Create the new node */
  QueueNodePtr newNode = malloc(sizeof(QueueNode));

  /* Should memory allocation succeed */
  if ( newNode != NULL ) {
    newNode->data = value;
    newNode->nextPtr = NULL;
    
    /* CASE 1: Empty queue; Enqueuing first item; Enqueuing at head */
    if ( *headPtr == NULL ) {
      *headPtr = newNode;
    }
    else { /* CASE 2: Queue with items; Enqueueing at end */
      (*tailPtr)->nextPtr = newNode;
    }

    /* Set tail to point to last enqueued node always */
    *tailPtr = newNode;
    printf("Enqueued\n");
  }
  else {
    printf("\nUnable to to allocate memory for enqueueing. Free heap memory space\n");
  }
}

