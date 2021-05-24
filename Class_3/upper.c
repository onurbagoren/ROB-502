/*
 * In this proble, the program should capitalize its command line arguments if they are between 'a'
 * and 'z', otherwise printing the characters unmodified.
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define TO_UPPER ( 'A' - 'a' )
#define LOWER_END 'a'
#define UPPER_END 'z'

int main(int argc, char **argv)
{
    if( argc < 2 )
    {
        printf("usage: ./upper <text>");
        return -1;
    }
    else
    {
        for( int i = 1; i < argc; i++ )
        {
            // Get string values
            char *arg = argv[i];
            size_t len = strlen(arg);

            for( int j = 0; j < len; j++ )
            {
                if( arg[j] > LOWER_END && arg[j] < UPPER_END )
                {
                    arg[j] = (char)(arg[j] + TO_UPPER);
                }
            }
            printf("%s", arg);
        }
    }
    printf("\n");
    return 0;
}
