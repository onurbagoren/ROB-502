#include <stdio.h>
#include <stdlib.h> // defines size_t

#define bool int

typedef struct vector
{
    size_t size;        // number of elements present in the vector
    size_t capacity;    // number of elements that can be put in
                        // the data array
    int *data;          // data array
} vector_t;

vector_t vector_create( void )
{
    vector_t new_vector;

    // Define parameters
    new_vector.size = 0;
    new_vector.capacity = 10;
    new_vector.data = malloc(sizeof(int*) *  new_vector.capacity );
   
    return new_vector;
}

void print_vector( vector_t *vec )
{
    for( unsigned int i = 0; i < vec->size; i++ )
    {
        printf("%d\n", vec->data[i]);
    }
}

void vector_append( vector_t *vec, int value )
{
    // Resize if size and capacity are the same
    if( vec->size == vec->capacity )
    {
        vec->capacity *= 2;
        vec->data = realloc( vec->data, sizeof( *vec->data ) *vec->capacity);
    }
    
    vec->data[ vec->size ] = value;
    vec->size++;
}

int golomb_number( int index )
{
    if( index == 1 )
        return 1;
    return 1 + golomb_number( index - golomb_number( golomb_number( index - 1 ) ) );
}

void golomb_sequence( vector_t *vec, int max_number )
{
    for( int i = max_number; i > 0; i-- )
        vector_append( vec, golomb_number( i ) );
    print_vector(vec); 
}

int main( int argc, char **argv )
{
    vector_t vec = vector_create();
    
    if( argc != 2 )
    {
        printf("Plrease run the application as ./problem1.c <MAX_NUMBER>\n");
        return 1;
    }

    golomb_sequence( &vec, atoi(argv[1]) );

    return 0;
}
