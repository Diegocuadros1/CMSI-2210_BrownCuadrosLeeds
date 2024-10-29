#include <stdio.h>
#include <stdlib.h>
// Modify your C program from problem #1 to to make the program dec2hex.c which will output the 32-bit or 64-bit
//[8-digit or 16-digit] hexidecimal equivalent of its input. For this modification, you must also handle an optional
// command line argument which indicates the number of digits the output hex value will contain, either 8 or 16.
// This will be the second argument on the line and if it is omitted the program will default to 32.
// For example, running the program with dec2hex 65535 8 should produce the output string 0x0000FFFF,
// and dec2hex 65535 16 should result in the output string 0x000000000000FFFF. If asking the user
// for input, both values should be asked for. Use unsigned integers.

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        printf("Please provide an input \n");
    }

    int byte_size = 32;

    if (argc >= 3)
    {
        byte_size = atoi(argv[2]);
        if (byte_size != 8 && byte_size != 16)
        {
            printf("Digit size must be either 8 or 16\n");
            return 1;
        }
    }

    // Convert input number
    unsigned long long num = strtoull(argv[1], NULL, 10);

    // Output the hexadecimal representation with leading zeros
    if (byte_size == 8)
    {
        printf("0x%08X\n", (unsigned int)num);
    }
    else
    {
        printf("0x%016llX\n", num);
    }

    printf("\n");
    return 0;
}
