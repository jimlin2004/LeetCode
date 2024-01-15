#include <stdio.h>

int gcd(int a, int b)
{
    return (b == 0) ? (a) : gcd(b, a % b);
}

int commonFactors(int a, int b)
{
    int g = gcd(a, b);
    int count = 1;
    for (int i = 2; i <= g; i++)
    {
        if ((g % i == 0) && (a % i == 0) && (b % i == 0))
            count++;
    }
    return count;
}