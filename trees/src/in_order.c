#include <stdio.h>
#include <stdlib.h>

#include "../include/tree.h"

void inOrder( TreeNodePtr currentPtr )
{
  if ( currentPtr != NULL ) {
    inOrder(currentPtr->leftPtr);
    printf("%d ", currentPtr->data);
    inOrder(currentPtr->rightPtr);
  }
}

