#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y)
{
    printf("...in gcd, x: %d and y: %d\n", x, y);
    return (y == 0) ? x : gcd(y, x % y);
}

int main(int argc, char *argv[])
{

    int num1 = 0;
    int num2 = 0;

    if (argc < 3)
    {
        printf("\n\n Sorry, you must enter two numbers space delimited \n \n");
        printf(" enter: ");
        scanf("%d %d", &num1, &num2);
    }
    else
    {
        num1 = atol(argv[1]);
        num2 = atol(argv[2]);
    }

    printf("\n \n The GCD of these two numbers is %d\n\n", gcd(num1, num2));
    exit(0);
}
