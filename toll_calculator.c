#include <stdio.h>
#include <unistd.h>

#define BIKE_TOLL 100
#define CAR_TOLL 200
#define TRUCK_TOLL 300
#define NIGHT_SHIFT_CHARGE 0.1

void mainMenu(void);

void tollCalculator(char opt);

char getUserChoice(void);

void clearScreen(void);

int main(void)
{
    mainMenu();

    return 0;
}

void mainMenu(void)
{
    int opt;

    printf("\nToll calculator\n");
    printf("\nVehicle types:\n 1) Car\n 2) Bike\n 3) Truck\n 4) Exit\n");
    printf("\nSelect an option: ");
    scanf("%d", &opt);

    tollCalculator(opt);
}

void tollCalculator(char opt)

{

    char choice;
    char shift;
    float amount = 0;

    do
    {
        clearScreen();

        switch (opt)
        {
        case 1:
            printf("Amount: $%d\n", CAR_TOLL);
            break;

        case 2:
            printf("Amount: $%d\n", BIKE_TOLL);
            break;

        case 3:
            printf("Enter the shift: ");
            scanf(" %c", &shift);

            if (shift == 'n' || shift == 'N')
            {
                amount = TRUCK_TOLL + (TRUCK_TOLL * NIGHT_SHIFT_CHARGE);
                printf("Amount: $%.2f\n", amount);
            }
            else
            {
                amount = TRUCK_TOLL;
                printf("Amount: $%.2f\n", amount);
            }

            break;

        case 4:

            break;

        default:
            printf("Invalid option");
            break;
        }

        choice = getUserChoice();

    } while (choice != 'n' && choice != 'N' && opt != 4);

    clearScreen();
}

char getUserChoice()
{
    char choice;
    do
    {
        printf("Do you want to do another toll calculation? (y/n): ");
        scanf(" %c", &choice);

        if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
        {
            printf("Invalid choice. Please choose 'y' or 'n'.\n");
        }

    } while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');

    return choice;
}

void clearScreen()
{
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}
