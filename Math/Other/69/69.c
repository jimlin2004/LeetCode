#include "stdio.h"
#include "math.h"

int mySqrt(int x)
{
    if (x < 2)
        return (int)x;
    double a0 = x;
    double a1 = (a0 + x / a0) / 2.0;
    while (abs(a0 - a1) >= 1.0)
    {
        a0 = a1;
        a1 = (a0 + x / a0) / 2.0;
    }
    return (int)a1;
}