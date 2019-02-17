#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/linked_list.h"

void menu ();

int main ( int argc, char * argv[] )
{
  int option;
  ListNodePtr head = NULL;
  menu();

  printf("Enter option : ");
  scanf("%d", &option);

  while ( true ) {
    if ( option == 1 ) {
      printf("Insert is not available right now\n");
    }
    else if ( option == 2 ) {
      printf("Delete is not available right now\n");
    }
    else if ( option == 3 ) {
      printList(head);
    }
    else if ( option == 4 ) break;

    menu();
    
    printf("Enter option : ");
    scanf("%d", &option);
  }

}

void menu () {
  printf("\n1. Press 1 to insert into the list\n");
  printf("2. Press 2 to delete from the list\n");
  printf("3. Press 3 to print the list\n");
  printf("4. Press 4 to quit\n\n");
}
