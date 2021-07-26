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

Node_t * node_create( void )
{
    Node_t *n = malloc(sizeof(Node_t));
    n->data = -1;
    n->next = malloc(sizeof(Node_t));
    n->prev = malloc(sizeof(Node_t));
}

//
// Method to create linked list with one item with the 
// data initialized to 0
//
list_t * list_create( void )
{
   // Initialize list
    list_t *list = malloc(sizeof(list_t));
    list->head = malloc(sizeof(Node_t));
    list->head = NULL;
    list->tail = malloc(sizeof(Node_t));
    list->tail = NULL;

    return list;
}

void print_list( list_t * list )
{
    Node_t *tmp_node = malloc(sizeof(Node_t));
    tmp_node = list->head;
    // printf("%ld, %d\n", sizeof( tmp_node ), tmp_node->data);
    while( tmp_node != NULL )
    {
        printf("%d -> ", tmp_node->data);
        tmp_node = tmp_node->next;
    }
    printf("\nEnd of list\n");
}

void push_start( list_t *list, int item )
{
    Node_t *first = list->head;
    Node_t *last = list->tail;

    // Create new node to push to the start of the list
    Node_t *new_n = node_create();
    new_n->data = item;
    new_n->next = first;
    new_n->prev = NULL;

    // Handle the case where the list is not defined
    if( first == NULL && last == NULL)
    {
        list->head = new_n;
        list->tail = new_n;     
        return;
    }
    // Handle the case where the list has an element already
    // inserted
    else
    {
        list->head->prev = new_n;
        list->head = new_n;
        return;
    }
}

void push_end( list_t *list, int item )
{
    Node_t *last = list->tail;
    Node_t *first = list->head;

    // Define the node that will be pushed to the end
    Node_t *new_n = node_create();
    new_n->data = item;
    new_n->next = NULL;
    new_n->prev = last;

    // Handle the case where the list is not defined
    if( first == NULL && last == NULL)
    {
        list->head = new_n;
        list->tail = new_n;     
        return;
    }
    // Handle the case where there is an item in the list
    else
    {
        list->tail->next = new_n;
        list->tail = new_n;
        return;
    }
}

int pop_start( list_t *list )
{
    Node_t *first = list->head;
    Node_t *last = list->tail;

    if( first == NULL && last == NULL )
    {
        fprintf( stderr, "No elements to pop!");
        return -1;
    }
    else 
    {
        Node_t *new_head = first->next;
        new_head->prev = NULL;
        list->head = new_head;
        int return_value = first->data;
        free(first);
        return return_value;
    }
}

int pop_end( list_t *list )
{
    Node_t *last = list->tail;
    Node_t *first = list->head;

    if( first == NULL && last == NULL )
    {
        fprintf( stderr, "No elements to pop!");
        return -1;
    }
    else
    {
        Node_t *new_tail = last->prev;
        new_tail->next = NULL;
        list->tail = new_tail;
        int return_value = last->data;
        free(last);
        return return_value;
    }
    return -1;
}

int main( int argc, char **argv )
{
    list_t *list = list_create();
    push_start( list, 5 );
    push_start( list, 6 );
    push_end( list, 7 );
    push_start( list, 4 );
    print_list( list );
    int start = pop_start( list );
    printf("First element: %d\n", start);
    print_list( list );
    int end = pop_end( list );
    printf("Last element: %d\n", end);
    print_list( list );
    return 0;
}
