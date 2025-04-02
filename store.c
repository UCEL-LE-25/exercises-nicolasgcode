#include <stdio.h>
#include <stdlib.h>

#define PRODUCT_A 100
#define PRODUCT_B 200
#define PRODUCT_C 300

#define TEN_PERCENT_DISC 0.1
#define TWENTY_PERCENT_DISC 0.2

void isValidQuantity(int quantity);

float calculatePrice(char op, int quantity);

int main(void)
{
    int quantity;
    char op;

    printf("Select product type (A, B o C): ");
    scanf(" %c", &op);

    printf("Enter quantity to buy: ");
    scanf("%d", &quantity);

    isValidQuantity(quantity);

    printf("Total amount: $%.2f\n", calculatePrice(op, quantity));

    return 0;
}

void isValidQuantity(int quantity)
{
    if (quantity <= 0)
    {
        printf("Error: Quantity must be greater than 0.\n");
        exit(1);
    }
}

float calculatePrice(char op, int quantity)
{
    float price = 0;
    float partialPrice = 0;

    if (op == 'A' || op == 'a')
    {
        partialPrice = PRODUCT_A * quantity;

        if (quantity > 10)
        {
            price = (partialPrice - (partialPrice * TEN_PERCENT_DISC));
            printf("Ten percent discount applied!\n");
        }
        else
        {
            price = partialPrice;
        }
    }
    else if (op == 'B' || op == 'b')
    {
        partialPrice = PRODUCT_B * quantity;

        if (quantity > 10)
        {
            price = (partialPrice - (partialPrice * TEN_PERCENT_DISC));
            printf("Ten percent discount applied!\n");
        }
        else
        {
            price = partialPrice;
        }
    }
    else if (op == 'C' || op == 'c')
    {
        partialPrice = PRODUCT_C * quantity;

        if (quantity > 20)
        {
            price = (partialPrice - (partialPrice * TWENTY_PERCENT_DISC));
            printf("Twenty percent discount applied!\n");
        }
        else
        {
            price = partialPrice;
        }
    }
    else
    {
        printf("Invalid product.\n");
    }

    return price;
}
