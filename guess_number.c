#include <stdio.h>
#include <stdbool.h>

bool isValidNumber(int guess);

void result(int won);

const int RANDOM_NUMBER = 50;

int main(void)
{

    int guess;

    int attemps = 5;

    int won = 0;

    do
    {
        printf("\nGuess the number: ");
        scanf("%d", &guess);

        if (isValidNumber(guess))
        {
            if (guess > RANDOM_NUMBER)
            {
                printf("\nToo high\n");
                attemps--;
                printf("\nAttemps left: %d\n", attemps);
            }
            else if (guess < RANDOM_NUMBER)
            {
                printf("\nToo low\n");
                attemps--;
                printf("\nAttemps left: %d\n", attemps);
            }
            else
            {
                won = 1;
            }
        }
        else
        {
            printf("\nInvalid number, please enter a number between 1 and 100\n");
        }

    } while (attemps != 0 && won == 0);

    result(won);
}

void result(int won)
{
    won ? printf("\nYou won!\n") : printf("\nYou lost!\n");
}

bool isValidNumber(int guess)
{
    return (guess >= 1 && guess <= 100);
}
