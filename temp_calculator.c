#include <stdio.h>

int temps[7] = {18, 17, 20, 23, 22, 24, 25};

int length = sizeof(temps) / sizeof(temps[0]); // Calculate the length of the array - Apparently this is the way to do it in C, working with bytes and etc.

int main(void)
{

    float acum = 0;
    float average;
    int daysAboveAverage = 0;

    for (int i = 0; i < length; i++)
    {
        acum += temps[i];
    }

    average = acum / length;

    for (int i = 0; i < length; i++)
    {

        if (temps[i] > average)
        {
            daysAboveAverage++;
        }
    }

    printf("\nResults:\n *Average temp in the last 7 days: %.2f\n *Days above average temp: %d", average, daysAboveAverage);

    return 0;
}
