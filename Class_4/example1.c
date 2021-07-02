#include <stdio.h>

int main()
{
    char message[] = "taco cat";
    printf("%s\n", &message[5]); // guess: ?, correct: cat
    printf("%c\n", *message); // guess: c, co cat
    message[4] = '\0'; 
    printf("%s\n", message); // guess: taco, taco
    printf("%s\n", message + 5); // guess: cat

    return 0;
}
