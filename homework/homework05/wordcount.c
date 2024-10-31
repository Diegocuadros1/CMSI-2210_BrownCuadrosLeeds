#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // Ensure exactly one argument is provided (the filename)
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }

    // Open the file in read mode
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        exit(1);
    }

    int count = 0;     // Word count
    int inWord = 0;    // Flag to track if currently inside a word
    int c;             // Character read from file

    // Read the file character by character
    while ((c = fgetc(fp)) != EOF) {
        if (isspace(c)) { // If the character is whitespace, we're not in a word
            inWord = 0;
            count ++;

        } else if (inWord != 0) { // Transition from whitespace to a word character
            inWord = 1;

        }
        // If already in a word and character is not whitespace, continue
    }

    printf("Number of words: %d\n", count);

    return 0;
}