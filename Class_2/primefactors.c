#include <stdio.h>
#include <math.h>

void prime_factors(int number)
{
    // Factorize by two until the number is no longer even
    while(number % 2 == 0)
    {
        printf("2\n");
        number = number / 2;
    }

    // Now the number is odd and odd prime factors can be calculated
    for( int i = 3; i < sqrt(number); i += 2 )
    {
        while( number % i == 0 )
        {
            printf("%d\n", i);
            number = number / i;
        }
    }
    
    // If number is still larger than 2 after the odd prime divisions.
    if( number > 2 )
    {
        printf("%d\n", number);
    }
}

int main(void)
{
    int user_input;
    printf("Enter a number to factorize: \n");
    scanf("%d", &user_input);
    prime_factors(user_input);
    return 0;
}
