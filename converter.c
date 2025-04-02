#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#define TO_MILIMETERS 10
#define TO_METERS 0.01

typedef struct
{
    float value;
    int opt;
} InputData;

InputData mainMenu(void);

char getUserChoice();

void unitConverter();

void clearScreen();

int main(void)
{
    unitConverter();

    return 0;
}

InputData mainMenu(void)
{
    int opt;
    float value = 0;
    InputData data;

    printf("\nUnit Converter\n");
    printf("\nEnter value in centimeters: ");
    scanf("%f", &value);
    printf("\nOperations:\n 1) Convert to millimiters\n 2) Convert to meters\n 3) Exit\n");
    printf("\nChoose an option: ");
    scanf("%d", &opt);

    data.opt = opt;
    data.value = value;

    return data;
}

void unitConverter()
{

    char choice;

    do
    {
        clearScreen();

        InputData data = mainMenu();

        switch (data.opt)
        {
        case 1:
            printf("Value in millimiters: %.2f\n", (data.value * TO_MILIMETERS));
            break;

        case 2:
            printf("Value in meters: %.2f\n", (data.value * TO_METERS));
            break;

        case 3:
            exit(1);
            break;

        default:
            printf("Invalid option");
            break;
        }

        choice = getUserChoice();

    } while (choice != 'n' && choice != 'N');

    clearScreen();
}

char getUserChoice()
{
    char choice;
    do
    {
        printf("Do you want to do another conversion? (y/n): ");
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