#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>

#define INSERT 1
#define DELETE 2
#define INORDER 3
#define PREORDER 4
#define POSTORDER 5
#define QUIT 6

#include "../include/tree.h"

void showMenu ();
int failSafe();

int main ( int argc, char * argv[] )
{
  int option = 0;
  int successful_option_reads, successful_value_reads;
  long to_insert, to_delete;
  TreeNodePtr head = NULL;

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
          printf("\nInserting node with value %ld into tree...\n", to_insert);
          insertNode(&head, (int) to_insert); 
        }
        break;
      
      // case DELETE :
      //   printf("\nEnter value to be deleted : ");
      //   successful_value_reads = scanf("%ld", &to_delete);

      //   /* Validate input */
      //   if ( successful_value_reads != 1 ) return failSafe();

      //   if ( to_delete > INT_MAX ) {
      //     printf("\nSorry, value is too big.\n");
      //   }
      //   else if ( to_delete < INT_MIN ) {
      //     printf("\nSorry, value is too small.\n");
      //   }
      //   else {
      //     printf("\nDeleting %ld from list...\n", to_delete);
      //     deleteItem(&head, (int) to_delete);
      //   }
      //   break;

      case INORDER :
        printf("\nInOrder: ");
        inOrder(head);
        printf("\n");
        break;

      // case PREORDER :
      //   printf("\n");
      //   preOrder(head);
      //   break;

      // case POSTORDER :
      //   printf("\n");
      //   postOrder(head);
      //   break;

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
  printf("3. Press 3 to taverse tree in order\n");
  printf("4. Press 4 to taverse tree preorder\n");
  printf("5. Press 5 to taverse tree postorder\n");
  printf("6. Press 6 to quit\n\n");
}

int failSafe () {
    printf("\n:( Bad input. Integers only.\n");
    printf("\nSorry, I have to kill myself now before something bad happens.\n");
    return 1;
}

