#include <stdio.h>
#include <stdlib.h>

#include "../include/linked_list.h"

void insert( ListNodePtr *headPtr, int value )
{
  /* Create list walker */
  ListNodePtr previousPtr = NULL;
  ListNodePtr currentPtr = *headPtr;

  /* Create the new node */
  ListNodePtr newNode = malloc(sizeof(ListNode));

  /* Should memory allocation succeed */
  if ( newNode != NULL ) {
    newNode->data = value;
    newNode->nextPtr = NULL;

    /* Walk through the list */
    while ( currentPtr != NULL && newNode->data > currentPtr->data ) {
      /* If input value is greater skip current node */
      previousPtr = currentPtr;
      currentPtr = currentPtr->nextPtr;
    }

    /* CASE 1: Insert at head of list */
    if (previousPtr == NULL ){
      newNode->nextPtr = *headPtr;
      *headPtr = newNode;
    }
    else {
      /* CASE 2: Insert new node into correct postion */
      newNode->nextPtr = currentPtr;
      previousPtr->nextPtr = newNode;
    }
  }
  else {
    printf("\nUnable to to allocate memory for insertion. Free memory space\n");
  }
}

