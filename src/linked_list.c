#include <stdio.h>
#include <stdlib.h>

#include "../include/linked_list.h"

void printList( ListNodePtr currentPtr )
{
  if ( currentPtr == NULL ) {
    printf("List is empty");
  }
  else {
    printf("HEAD-->");

    while ( currentPtr != NULL ) {
      printf("%d-->", currentPtr->data);
      currentPtr = currentPtr->nextPtr;
    }

    printf("NULL\n");
  }

}

