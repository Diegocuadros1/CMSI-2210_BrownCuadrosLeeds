
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Write a C program holdit.c that times you as you hold your breath.
// The program must put out a short message that has instructions on
// what to do, which should read something like

int main()
{

    printf("This program will time how long you can hold your breath. Take a deep breath, then press the 'Enter' key. When you absolutely have to exhale, press the enter key again. The duration will be displayed in minutes and seconds.");

    char start = getchar();
    if (start == '\n')
    {
        printf("Hold Your Breath! Press enter again to stop the timer!\n");
        time_t start_time = time(NULL);

        char end = getchar();
        if (end == '\n')
        {
            time_t end_time = time(NULL);
            int time_spent = (int)difftime(end_time, start_time);
            int minutes = time_spent / 60;
            int seconds = time_spent % 60;

            printf("Time elapsed: %d minutes and %d seconds\n", minutes, seconds);
            // Diego's record time is 1 min and 14 sec :)
            return 0;
        }
    }

    printf("\n");
    return 0;
}
