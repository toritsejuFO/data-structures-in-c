#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef QUEUE_H
#define QUEUE_H

struct queueNode {
  int data;
  struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef struct queueNode *QueueNodePtr;

void enqueueItem( QueueNodePtr *headPtr, int value );
long dequeueItem( QueueNodePtr *headPtr );
void printQueue( QueueNodePtr currentPtr );

#endif // QUEUE_H

