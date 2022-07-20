#include <stdio.h>

int main(void)
{
    int num1;
    int num2;

    printf("Enter the first integer:");
    scanf("%d", &num1);

    printf("Enter the second integer:");
    scanf("%d", &num2);
    
    if (num1 % num2 == 0)
    {
        printf("Divisible\n");
    }
    else
    {
        printf("Not Divisible\n");
    }
    return 0;
}