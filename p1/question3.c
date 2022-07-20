#include <stdio.h>

int factorial (int n);

int main ( void )
{
    int input;
    int sum;

    do
    {
        printf("Please enter an integer: ");
        scanf("%d", &input);
        if (input >= 0)
        {
            sum = factorial(input);   
            printf("%d", sum);
            printf("\n");
        }
        
    } while (input >= 0);
    printf("Goodbye!");
    return 0;
}

int factorial (int n)
{
    int sum;
    sum = n;
    do
    {
        n = n -1;
        sum = sum * n;
    } while (n > 1);
    return sum;
}
