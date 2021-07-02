#include <stdio.h>
#include <math.h>
#include <string.h>

#define bool int

int main( int argc, char **argv )
{
    if( argc < 2 )
    {
        printf("usage: ./parity [<text]");
        return -1;
    } 
    else if ( argc > 3 )
    {
        printf("usage: ./parity [<text]");
        return -1;
    }
    else
    {
        bool parity = 0;
        char *arg = argv[1];
        for( int j = 0; j < strlen(arg); j++ )
        {
            int input_character = (int) arg[j];
            while( input_character )
            {
                parity = !parity;
                input_character = input_character & (input_character - 1);
            }
        }
        printf("parity of %s = %s\n", arg, (parity ? "odd": "even"));
    }

    return 0;
}
