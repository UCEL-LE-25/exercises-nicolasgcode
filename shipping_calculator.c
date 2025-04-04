#include <stdio.h>
#include <stdbool.h>

#define STD_CUSTOMER 500
#define PREF_CUSTOMER 400
#define ENT_CUSTOMER 1500

bool isValidWeight(int weight);

char getUserChoice(void);

void printShippingDetails(float weight, int opt, float amount);

void calculateShippingCost(int opt, float weight, float amount, float overWeight);

int main(void)
{

  int opt;
  char choice;
  float weight = 0;
  float amount = 0;
  float overWeight = 0;

  do
  {

    printf("\nSHIPPING CALCULATOR\n");
    printf("\n1. Standard customer\n2. Preferred customer\n3. Enterprise customer\n");
    printf("\nPlease, select an option: ");
    scanf("%d", &opt);

    printf("\nEnter the package weight: ");
    scanf("%f", &weight);

    if (isValidWeight(weight))
    {
      calculateShippingCost(opt, weight, amount, overWeight);
    }
    else
    {
      printf("\nInvalid weight, please enter a weight greater than 0.\n");
    }

    choice = getUserChoice();

  } while (choice != 'n' && choice != 'N');

  return 0;
}

bool isValidWeight(int weight)
{
  return (weight > 0);
}

void calculateShippingCost(int opt, float weight, float amount, float overWeight)
{
  switch (opt)
  {
  case 1:

    if (weight > 5)
    {
      overWeight = weight - 5;

      amount = STD_CUSTOMER + (100 * overWeight);
    }
    else
    {
      amount = STD_CUSTOMER;
    }

    printShippingDetails(weight, opt, amount);

    break;

  case 2:

    if (weight > 5)
    {
      overWeight = weight - 5;

      amount = PREF_CUSTOMER + (80 * overWeight);
    }
    else
    {
      amount = PREF_CUSTOMER;
    }

    printShippingDetails(weight, opt, amount);
    break;

  case 3:

    if (weight > 20)
    {
      overWeight = weight - 20;

      amount = ENT_CUSTOMER + (50 * overWeight);
    }
    else
    {
      amount = ENT_CUSTOMER;
    }

    printShippingDetails(weight, opt, amount);
    break;

  default:

    printf("\nInvalid option, please try again.\n");
    break;
  }
}

char getUserChoice()
{
  char choice;
  do
  {
    printf("Do you want to do another shipping calculation? (y/n): ");
    scanf(" %c", &choice);

    if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
    {
      printf("Invalid choice. Please choose 'y' or 'n'.\n");
    }

  } while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');

  return choice;
}

void printShippingDetails(float weight, int opt, float amount)
{
  switch (opt)
  {
  case 1:
    printf("\nCustomer type: Standard\nPackage weight: %.2f kg\nShipping amount: %.2f\n", weight, amount);
    break;

  case 2:
    printf("\nCustomer type: Preferred\nPackage weight: %.2f kg\nShipping amount: %.2f\n", weight, amount);
    break;

  case 3:
    printf("\nCustomer type: Enterprise\nPackage weight: %.2f kg\nShipping amount: %.2f\n", weight, amount);
    break;
  }
}