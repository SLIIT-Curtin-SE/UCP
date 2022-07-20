#include <stdio.h>
#include "order.h"

void addbyValue(int a, int b)
{
    printf("We are adding by Value\n");
    a = a + b;
    printf("The value of a inside the function is %d\n", a);
}

void addbyReference(int* a, int* b)
{
    printf("We are adding by Reference\n");
    *a = *a + *b;
    printf("The value of a inside the function is %d\n", *a);
}

int main()
{
    int a = 5;
    int b = 10;
    addbyValue(a, b);
    printf("The value of a inside the main function after passing by Value %d\n", a);
    addbyReference(&a, &b);
    printf("The value of a inside the main function after passing by Reference %d\n", a);
    return 0;
}




