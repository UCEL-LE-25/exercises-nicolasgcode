#include <stdio.h>

int main(void)
{

    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    for (int i = 1; i <= 100; i++)
    {

        if (number % 3 == 0 && number % 5 == 0)
        {
            printf("\nFizzBuz\n");
        }
        else if (number % 3 == 0)
        {
            printf("\nFizz\n");
        }
        else if (number % 5 == 0 && number % 5 == 0)
        {
            printf("\nBuzz\n");
        }
        else
        {
            printf("\n%d not divisible by 3 or 5\n", number);
        }
    }

    return 0;
}
