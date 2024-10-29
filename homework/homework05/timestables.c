#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Please provide a number");
        return 1;
    }

    int num = atoi(argv[1]);

    // Check if N is at least 2
    if (num < 2)
    {
        printf("N should be at least 2.\n");
        return 1;
    }

    // decide width of table
    int max_value = num * num;
    int width = 0;
    int temp = max_value;

    while (temp > 0)
    {
        temp = temp / 10;
        width++;
    }
    width++; // Add extra space for padding

    // Print header row
    printf("%*s", field_width, ""); // Empty top-left corner
    for (int i = 2; i <= num; i++)
    {
        printf("%*d", field_width, i);
    }
    printf("\n");

    // Print separator line
    printf("%*s", field_width, "");
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < field_width; j++)
        {
            printf("-");
        }
    }
    printf("\n");

    // Print times tables
    for (int i = 2; i <= N; i++)
    {
        printf("%*d|", field_width - 1, i); // Left column with separator
        for (int j = 2; j <= N; j++)
        {
            printf("%*d", field_width, i * j);
        }
        printf("\n");
    }

    return 0;
}
