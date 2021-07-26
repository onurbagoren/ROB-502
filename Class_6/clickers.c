#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct collection{
    int a;
    int b;
    char *c;
} coll_t;

int main()
{
    // char message[] = "taco cat";
    // message[3] = '\0';

    // printf("%s\n", message); // tac

    // printf("%ld, %ld\n", sizeof("hello!"), strlen("hello!"));
    
    int vals[] = {5, 10, 15, 20};
    printf("%ld\n", &vals[2] - &vals[0] );
    printf("%ld, %ld\n", sizeof(vals), sizeof(vals[0]));


    char *msg = malloc(strlen("Walking in the park"));
    printf("%s\n", msg);
    strcpy(msg, "Walking in the park");
    printf("%s\n", msg);
    free(msg);
    msg = NULL;


    int *arr = malloc(sizeof(*arr) * 10);
    realloc(arr, sizeof(*arr) * 20);
    arr[0] = 10;
    free(arr);
    printf("%ld\n", sizeof(arr));
}
