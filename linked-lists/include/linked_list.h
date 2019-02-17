#include <stdio.h>
#include <stdlib.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct listNode {
  int data;
  struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef struct listNode *ListNodePtr;

void printList( ListNodePtr currentPtr );

#endif // LINKED_LIST_H

