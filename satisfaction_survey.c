#include <stdio.h>

int main(void)
{

    int people;
    int score;
    int unsatisfied = 0;
    int neutral = 0;
    int satisfied = 0;

    do
    {
        printf("Enter the number of people: ");
        scanf("%d", &people);
    } while (people < 1);

    for (int i = 0; i < people; i++)
    {
        printf("Enter score 1-5: ");
        scanf("%d", &score);

        if (score >= 1 && score <= 2)
        {
            unsatisfied++;
        }
        else if (score == 3)
        {
            neutral++;
        }
        else if (score >= 4 && score <= 5)
        {
            satisfied++;
        }
        else
        {
            printf("\nInvalid score\n");
        }
    }

    printf("\nResults:\n Satisfied people: %d\n Neutral people: %d\n Unsatisfied people: %d\n", satisfied, neutral, unsatisfied);

    return 0;
}
