#include <stdio.h>

void add_one( int *number )
{
    *number += 1;
}


void main()
{
    int a = 8;
    add_one(&a);
    printf("%d\n", a);
}
