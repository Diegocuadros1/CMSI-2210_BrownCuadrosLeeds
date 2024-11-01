#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    int inWord = 0; // Flag to track if we're inside a word
    int wordCount = 0;
    int ch;

    while ((ch = fgetc(file)) != EOF)
    {
        if (isspace(ch))
        {
            inWord = 0; // End of a word
        }
        else if (!inWord)
        {
            inWord = 1; // Start of a new word
            wordCount++;
        }
    }

    if (ferror(file))
    {
        perror("Error reading file");
        fclose(file);
        return 1;
    }

    fclose(file);
    printf("Word count: %d\n", wordCount);
    return 0;
}
