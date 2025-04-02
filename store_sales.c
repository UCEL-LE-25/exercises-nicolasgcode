#include <stdio.h>

int main(void)
{

    float amount = 0;
    int salesCounter = 0;
    float sale = 0;

    printf("\nPlease, enter your sales: ");
    scanf("%f", &sale);

    while (sale > 0)
    {

        amount += sale;
        salesCounter++;

        printf("\nPlease, enter your sales: ");
        scanf("%f", &sale);
    }

    printf("\nAmount of registered sales: $%.2f\nDays with sales: %d\nAverage sales per day: $%.2f\n", amount, salesCounter, amount / salesCounter);

    return 0;
}