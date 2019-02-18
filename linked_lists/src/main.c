#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "../include/linked_list.h"

void menu ();

int main ( int argc, char * argv[] )
{
  int option, value;
  ListNodePtr head = NULL;

  menu();

  printf("Enter option : ");
  scanf("%d", &option);

  while ( true ) {
    /* Handle insertion */
    if ( option == 1 ) {
      printf("\nEnter value to be inserted : ");
      scanf("%d", &value);

      /* Insert value if it is not greater than an integer */
      if ( value > INT_MAX ) {
        printf("\nSorry, value is too big.\n");
      }
      else if ( value < INT_MIN ) {
        printf("\nSorry, value too small.\n");
      }
      else {
        printf("\nInserting %d into list...\n", value);
        insert(&head, value); 
      }
    }
    else if ( option == 2 ) {
      printf("\nDelete is not available right now\n");
    }
    else if ( option == 3 ) {
      printf("\n");
      printList(head);
    }
    else if ( option == 4 ) break;

    menu();
    
    printf("Enter option : ");
    scanf("%d", &option);
  }

  free(head);
  return 0;

}

void menu () {
  printf("\n1. Press 1 to insert into the list\n");
  printf("2. Press 2 to delete from the list\n");
  printf("3. Press 3 to print the list\n");
  printf("4. Press 4 to quit\n\n");
}
