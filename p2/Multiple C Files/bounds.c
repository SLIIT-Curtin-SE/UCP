#include <stdio.h>
#include "macros.h"
#ifndef POWERS_H
#define POWERS_H
#endif

int checkBounds(int low, int high, int value);
int powers();

int main(void)
{
    int low = 1;
    int high = 31;
    int value;
    int result;

    printf("%s", "Please enter a value to represent the iterations: ");
    scanf("%d", &value);
    
    result = checkBounds(low, high, value);
    if (result == TRUE)
    {
        int x;
        int returnVal;
        for (x=0; x < value; x++)
        {
            returnVal = powers();
            printf("%d", returnVal);
            printf("%s", "\n");
        }
    }
    else 
    {
        printf("%s", "Program will crash if we try to run this many times!\n");
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