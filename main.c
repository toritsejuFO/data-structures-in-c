#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

int main ( int argc, char * argv[] )
{
  ListNodePtr head = NULL;
  ListNodePtr newNode = malloc(sizeof(ListNode));

  newNode->data = 5;
  newNode->nextPtr = NULL;

  head = newNode;

  ListNodePtr current = head;
  printList(current);
}

