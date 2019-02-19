#include <stdio.h>
#include <stdlib.h>

#include "../include/linked_list.h"

void deleteItem( ListNodePtr *headPtr, int value )
{
  /* Create list walker */
  ListNodePtr previousPtr = NULL;
  ListNodePtr currentPtr = *headPtr;

  /* Create the node pointer for delete node */
  ListNodePtr deleteNode = NULL;

  /* Walk through the list */
  while ( currentPtr != NULL && value != currentPtr->data ) {
    /* If input value is not equal and we are not at end of list skip current node */
    previousPtr = currentPtr;
    currentPtr = currentPtr->nextPtr;
  }

  /* CASE 1: Deletion from an empty list */
  if (previousPtr == NULL && currentPtr == NULL ){
    printf("The list is empty. Delete operation for %d was unsuccessful.\n", value);
  }

  /* CASE 2: Deletion of first/only element in list */
  else if (previousPtr == NULL && value == currentPtr->data ) {
    deleteNode = currentPtr;
    *headPtr = currentPtr->nextPtr;
    deleteNode->nextPtr = NULL;
    free(deleteNode);
    printf("Deleted\n");
  }

  /* Deletion of a non-existent element in list */
  else if ( previousPtr != NULL && currentPtr == NULL ) {
    printf("The element to be deleted was not found in this list. Print list to see existing values.\n");
  }

  else { /* CASE 3: Delete from middle/end of list */
    deleteNode = currentPtr;
    previousPtr->nextPtr = currentPtr->nextPtr;
    deleteNode->nextPtr = NULL;
    free(deleteNode);
    printf("Deleted\n");
  }
}

