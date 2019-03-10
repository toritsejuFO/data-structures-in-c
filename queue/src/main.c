#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define ENQUEUE 1
#define DEQUEUE 2
#define PRINTQUEUE 3
#define QUIT 4

#include "../include/queue.h"

void showMenu ();
int failSafe();

int main ( int argc, char * argv[] )
{
  int option = 0;
  int successful_option_reads, successful_value_reads;
  long to_enqueue, dequeued_value;
  QueueNodePtr head = NULL;

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
      case ENQUEUE :
        printf("\nEnter value to be enqueued into the queue : ");
        successful_value_reads = scanf("%ld", &to_enqueue);

        /* Validate input */
        if ( successful_value_reads != 1 ) return failSafe();

        if ( to_enqueue > INT_MAX ) {
          printf("\nSorry, value is too big.\n");
        }
        else if ( to_enqueue < INT_MIN ) {
          printf("\nSorry, value is too small.\n");
        }
        else {
          printf("\nEnqueueing %ld into queue...\n", to_enqueue);
          enqueueItem(&head, (int) to_enqueue); 
        }
        break;
      
      case DEQUEUE :
        dequeued_value = dequeueItem(&head);
        /*
        * Enqueuing only allows INTEGERS. Hence if we get +1 above the max integer,
        * Which is what 'dequeueItem' will return incase of an a NULL headPtr,
        * Which is also a LONG, we then know that the stack is empty.
        */
        if ( dequeued_value != (INT_MAX + 1) ) {
          printf("\nDequeueing %ld from the queue...\n", dequeued_value);
          printf("Dequeued\n");
        }
        break;

      case PRINTQUEUE :
        printf("\n");
        printQueue(head);
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
  printf("\n1. Press 1 to enqueue into the queue\n");
  printf("2. Press 2 to dequeue from the queue\n");
  printf("3. Press 3 to print the queue\n");
  printf("4. Press 4 to quit\n\n");
}

int failSafe () {
    printf("\n:( Bad input. Integers only.\n");
    printf("\nSorry, I have to kill myself now before something bad happens.\n");
    return 1;
}

