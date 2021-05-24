#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char **argv)
{
    printf("This program was given %d arguments\n", argc);
    for( int i = 0; i < argc; i++ )
    {
        char *arg = argv[i];
        printf("The %d argument is %s\n", i, arg);

        size_t len = strlen(arg); // size_t is an unsigned long integer
        for( int j = 0; j < len; j++)
            printf("%d: character %c = %d\n", j, arg[j], arg[j]); // print the position, character and then the ascii representation
    }
    return 0;
}

