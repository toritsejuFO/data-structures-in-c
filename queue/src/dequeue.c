#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "../include/queue.h"

long dequeueItem( QueueNodePtr *headPtr, QueueNodePtr *tailPtr )
{
  /* Create the node pointer for delete node */
  QueueNodePtr deleteNode = NULL;

  /* CASE 1: Dequeueing an empty queue */
  if ( *headPtr == NULL ){
    printf("The queue is empty. Dequeue operation was unsuccessful.\n");
    return INT_MAX + 1;
  }

  /* CASE 2: Dequeueing a populated queue */
  else {
    deleteNode = *headPtr;
    *headPtr = (*headPtr)->nextPtr;
    deleteNode->nextPtr = NULL;

    /* Update tail when last node/item is dequeued */
    if (*headPtr == NULL ) { *tailPtr = NULL; }

    /* Store dequeued value into a variable only when it is successfully dequeued */
    long dequeued_value = deleteNode->data;

    free(deleteNode);
    return dequeued_value;
  }
}

