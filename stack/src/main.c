#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define PUSH 1
#define POP 2
#define PRINTSTACK 3
#define QUIT 4

#include "../include/stack.h"

void showMenu ();
int failSafe();

int main ( int argc, char * argv[] )
{
  int option = 0;
  int successful_option_reads, successful_value_reads;
  long to_push, popped_value;
  StackNodePtr head = NULL;

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
      case PUSH :
        printf("\nEnter value to be pushed onto the stack : ");
        successful_value_reads = scanf("%ld", &to_push);

        /* Validate input */
        if ( successful_value_reads != 1 ) return failSafe();

        if ( to_push > INT_MAX ) {
          printf("\nSorry, value is too big.\n");
        }
        else if ( to_push < INT_MIN ) {
          printf("\nSorry, value is too small.\n");
        }
        else {
          printf("\nPushing %ld onto stack...\n", to_push);
          pushItem(&head, (int) to_push); 
        }
        break;
      
      case POP :
        popped_value = popItem(&head);
        /*
        * Pushing only allows INTEGERS. Hence if we get +1 above that,
        * Which is what 'popItem' will return incase of an a NULL headPtr,
        * Which is also a LONG, we then know that the stack is empty.
        */
        if ( popped_value != (INT_MAX + 1) ) {
          printf("\nPopping %ld from the stack...\n", popped_value);
          printf("Popped\n");
        }
        break;

      case PRINTSTACK :
        printf("\n");
        printStack(head);
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
  printf("\n1. Press 1 to push onto the stack\n");
  printf("2. Press 2 to pop the stack\n");
  printf("3. Press 3 to print the stack\n");
  printf("4. Press 4 to quit\n\n");
}

int failSafe () {
    printf("\n:( Bad input. Integers only.\n");
    printf("\nSorry, I have to kill myself now before something bad happens.\n");
    return 1;
}

