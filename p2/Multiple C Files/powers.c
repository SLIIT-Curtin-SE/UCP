#include <stdio.h>
#include <math.h>
#include "powers.h"

int powers()
{
    static int count = 1;
    int result;
    result = pow(2, count);
    count++;

    return result;
}

