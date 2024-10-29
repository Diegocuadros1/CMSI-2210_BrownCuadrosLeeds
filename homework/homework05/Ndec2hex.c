#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        printf("Please provide an number input");
        printf("8 or 16 bits?");
    }
    int num = atof(argv[1]);
    int num2 = atof(argv[2]);

    char binary[33];
    binary[32] = '\0';

    for (int i = 32; i >= 0; i--)
    {
        binary[i] = (num & 1) ? '1' : '0';
        num = num >> 1;
    }
//chatGPT add something here to check for if the length shoule be 8 or 16 bits and pad with 0's accordingly

    for (int j = 0; j < 33; j++)
    {
        printf("%c", binary[j]);
    }

    printf("\n");
    return 0;
}
