#include "stdio.h"
#include "macros.h"

int checkBounds(int low, int high, int value);

int main(void)
{
    int low;
    int high;
    int value;
    int result;

    printf("%s", "Please enter a lower bound: ");
    scanf("%d", &low);

    printf("%s", "Please enter a upper bound: ");
    scanf("%d", &high);

    printf("%s", "Please enter a value to test boundaries: ");
    scanf("%d", &value);
    
    result = checkBounds(low, high, value);
    if (result == TRUE)
    {
        printf("%s", "Value within bounds!\n");
    }
    else 
    {
        printf("%s", "Value not within bounds!\n");
    }
    return 0;
}

int checkBounds(int low, int high, int value)
{
    int result = FALSE;

    if (low <= value)
    {
        if (high >= value)
        {
            result = TRUE;
        }
    }
    return result;
}