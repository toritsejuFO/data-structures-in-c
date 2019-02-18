#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>

#include "../include/linked_list.h"

void show_menu ();

int main ( int argc, char * argv[] )
{
  int option = 0;
  long value;
  ListNodePtr head = NULL;

  do {
    show_menu();
    printf("Enter option : ");
    int successful_option_reads = scanf("%d", &option);

    if ( successful_option_reads != 1 ) {
      printf("\n:( Bad input, must be an acceptable integer amongst the options.\n");
      printf("\nSorry, I have to kill myself now before something bad happens.\n");
      return 1;
    }

    switch ( option ) {
      /* Handle insertion */
      case 1 :
        printf("\nEnter value to be inserted : ");
        int successful_value_reads = scanf("%ld", &value);

        /* Validate input */
        if ( successful_value_reads != 1 ) {
          printf("\n:( Bad input. Integers only.\n");
          printf("\nSorry, I have to kill myself now before something bad happens.\n");
          return 1;
        }

        if ( value > INT_MAX ) {
          printf("\nSorry, value is too big.\n");
        }
        else if ( value < INT_MIN ) {
          printf("\nSorry, value too small.\n");
        }
        else {
          printf("\nInserting %ld into list...\n", value);
          insert(&head, value); 
        }
        break;
      
      case 2 :
        printf("\nDelete is not available right now\n");
        break;

      case 3 :
        printf("\n");
        printList(head);
        break;

      case 4:
        break;

      default:
        printf("\nInvalid option, please select from the available options.\n");
    }
  } while ( option != 4 );

  printf("\nEND\n");
  free(head);
  return 0;

}

void show_menu () {
  printf("\n1. Press 1 to insert into the list\n");
  printf("2. Press 2 to delete from the list\n");
  printf("3. Press 3 to print the list\n");
  printf("4. Press 4 to quit\n\n");
}
