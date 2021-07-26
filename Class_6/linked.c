#include <stdio.h>
#include <stdlib.h>

//
// Inplementing a doubly linked list
//

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node_t;

typedef struct linked_list
{
    Node_t *head;
    Node_t *tail;
} list_t;

list_t * list_create( void )
{
   // Initializing data to 0 instead of NULL
   // TODO: ability to set data to NULL
   Node_t *new_n;
   new_n->data = 0;
   new_n->next = NULL;
   new_n->prev = NULL;

   // Initialize list
   list_t *list;
   list->head = new_n;
   list->tail = new_n; 

   return list;
}

int get_list_length( list_t *list )
{

    return -1;
}

void push_start( list_t *list, int item )
{
    
}

void push_end( list_t *list, int item )
{


}

int pop_start( list_t *list )
{

    return -1;
}

int pop_end( list_t *list )
{

    return -1;
}

int main( int argc, char **argv )
{


    return 0;
}
