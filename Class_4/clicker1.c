#include <stdio.h>

int main()
{
    char a = 'a';
    int b = 100;
    char c[40] = {0};
    for( int i = 0; i < 39; i++ )
    {
        c[i] = 'a' + i;
        printf("%c, %c\n", c[i], c[i+1]);
    }
    char *d = c;
    return 0;
}
