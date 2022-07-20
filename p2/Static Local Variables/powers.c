#include <stdio.h>
#include <math.h>

int powers()
{
    static int count = 1;
    int result;
    result = pow(2, count);
    count++;

    return result;

}

int main (void)
{
    int returnVal;
    printf("Calling the function once ");
    returnVal = powers();
    printf("%d", returnVal);
    printf("\n");

    printf("Calling the function twice ");
    returnVal = powers();
    printf("%d", returnVal);
    printf("\n");

    printf("Calling the function thrice ");
    returnVal = powers();
    printf("%d", returnVal);
    printf("\n");

    return 0;
}
