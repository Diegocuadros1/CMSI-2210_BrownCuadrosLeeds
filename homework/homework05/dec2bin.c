#include <stdio.h>
#include <stdlib.h>
// Write a C program, dec2bin.c to convert a base-10 number to its
// 32-bit binary value equivalent. You may take the base-10 number in
//  from the command line, or you may prompt the user for the number and
// read in her response [your option]. Your output should be a string of
// binary digits which correspond to the base-10 value. For example, running the
//  program with dec2bin 65535 [or just dec2bin if asking the user] should
//  produce the output string 00000000000000001111111111111111. Use unsigned integers.

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        printf("Please provide an input\n");
        return 1;
    }
    int num = atof(argv[1]);

    char binary[33];
    binary[32] = '\0';

    for (int i = 32; i >= 0; i--)
    {
        binary[i] = (num & 1) ? '1' : '0';
        num = num >> 1;
    }

    for (int j = 1; j < 33; j++)
    {
        printf("%c", binary[j]);
    }

    printf("\n");
    return 0;
}
