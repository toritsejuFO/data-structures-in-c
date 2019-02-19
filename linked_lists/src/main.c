#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>

#define INSERT 1
#define DELETE 2
#define PRINTLIST 3
#define QUIT 4

#include "../include/linked_list.h"

void showMenu ();
int failSafe();

int main ( int argc, char * argv[] )
{
  int option = 0;
  int successful_option_reads, successful_value_reads;
  long to_insert, to_delete;
  ListNodePtr head = NULL;

  do {
    showMenu();
    printf("Enter option : ");
    successful_option_reads = scanf("%d", &option);

    if ( successful_option_reads != 1 ) {
      printf("\n:( Bad input, must be an acceptable integer amongst the options.\n");
      printf("\nSorry, I have to kill myself now before something bad happens.\n");
      return 1;
    }

    switch ( option ) {
      /* Handle insertion */
      case INSERT :
        printf("\nEnter value to be inserted : ");
        successful_value_reads = scanf("%ld", &to_insert);

        /* Validate input */
        if ( successful_value_reads != 1 ) return failSafe();

        if ( to_insert > INT_MAX ) {
          printf("\nSorry, value is too big.\n");
        }
        else if ( to_insert < INT_MIN ) {
          printf("\nSorry, value too small.\n");
        }
        else {
          printf("\nInserting %ld into list...\n", to_insert);
          insertItem(&head, (int) to_insert); 
        }
        break;
      
      case DELETE :
        printf("\nEnter value to be deleted : ");
        successful_value_reads = scanf("%ld", &to_delete);

        /* Validate input */
        if ( successful_value_reads != 1 ) return failSafe();

        if ( to_delete > INT_MAX ) {
          printf("\nSorry, value is too big.\n");
        }
        else if ( to_delete < INT_MIN ) {
          printf("\nSorry, value is too small.\n");
        }
        else {
          printf("\nDeleting %ld from list...\n", to_delete);
          deleteItem(&head, (int) to_delete);
        }
        break;

      case PRINTLIST :
        printf("\n");
        printList(head);
        break;

      case QUIT:
        break;

      default:
        printf("\nInvalid option, please select from the available options.\n");
    }
  } while ( option != QUIT );

  printf("\nEND\n");
  free(head);
  return 0;

}

void showMenu () {
  printf("\nOPTIONS");
  printf("\n1. Press 1 to insert into the list\n");
  printf("2. Press 2 to delete from the list\n");
  printf("3. Press 3 to print the list\n");
  printf("4. Press 4 to quit\n\n");
}

int failSafe () {
    printf("\n:( Bad input. Integers only.\n");
    printf("\nSorry, I have to kill myself now before something bad happens.\n");
    return 1;
}

