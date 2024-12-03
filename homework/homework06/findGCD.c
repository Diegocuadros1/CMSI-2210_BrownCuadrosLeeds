#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main(int argc, char *argv[])
{

    int a = 10;
    int b = 5;

    printf("\n \n The GCD of these two numbers is %d\n\n", gcd(a, b));
}