#include <stdio.h>

int main( void )
{
    FILE *f = fopen("file", "r");
    char line[128];
    fgets( line, 128, f );
    printf("firs line is: %s\n", line);
    return 0;
}
