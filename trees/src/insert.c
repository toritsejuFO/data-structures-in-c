#include <stdio.h>
#include <stdlib.h>

#include "../include/tree.h"

void insertNode( TreeNodePtr *headPtr, int value )
{
  /* Create tree walker */
  int left = 0;
  int right = 0;
  TreeNodePtr previousPtr = NULL;
  TreeNodePtr currentPtr = *headPtr;

  /* Create the new node */
  TreeNodePtr newNode = malloc(sizeof(TreeNode));

  /* Should memory allocation succeed */
  if ( newNode != NULL ) {
    newNode->data = value;
    newNode->leftPtr = NULL;
    newNode->rightPtr = NULL;

    /* Traverse tree */
    while ( currentPtr != NULL ) {
      /* If input value is greater move to the right */
      if ( value > currentPtr->data ) {
        previousPtr = currentPtr;
        left = 0; right = 1;
        currentPtr = currentPtr->rightPtr;
        // if (previousPtr->rightPtr == NULL || (value < previousPtr->rightPtr->data)) break; // Check next value
      }
      else if ( value < currentPtr->data ) {
        /* If input value is lesser move to the left */
        previousPtr = currentPtr;
        left = 1; right = 0;
        currentPtr = currentPtr->leftPtr;
        // if (previousPtr->leftPtr == NULL || (value > previousPtr->leftPtr->data)) break; // Check next value
      }
      else if ( value == currentPtr->data ) {
        previousPtr = currentPtr;
        printf("\nValue already exists. No duplicate values allowed\n");
        break;
      }
    }

    /* CASE 1: Insertion of first node in tree */
    if ( previousPtr == NULL ){
      *headPtr = newNode;
      printf("Inserted\n");
    }
    else if ( left == 0 && currentPtr == NULL ) {
      /* CASE 2: Insert new node into right postion */
      newNode->rightPtr = currentPtr;
      previousPtr->rightPtr = newNode;
      printf("Inserted\n");
    }
    else if ( right == 0 && currentPtr == NULL ) {
      /* CASE 2: Insert new node into left postion */
      newNode->leftPtr = currentPtr;
      previousPtr->leftPtr = newNode;
      printf("Inserted\n");
    }
  }
  else {
    printf("\nUnable to to allocate memory for insertion. Free memory space\n");
  }
}

