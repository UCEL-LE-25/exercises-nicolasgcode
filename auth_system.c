#include <stdio.h>
#include <stdbool.h>

#define ID 2468
#define PWS 432

bool isValidId(int id);

void isAuth(int access);

int main(void)
{

    int attemps = 1;
    int access = 0;
    int id;
    int psw;

    do
    {
        printf("\nAUTH SYSTEM\n");
        printf("\nPlease, enter your ID: ");
        scanf("%d", &id);

        if (isValidId(id))
        {

            printf("\nPlease, enter your password: ");
            scanf("%d", &psw);

            if (id != ID || psw != PWS)
            {
                printf("\nInvalid credentials, please try again...\n");
                attemps++;
            }
            else
            {
                access = 1;
            }
        }
        else
        {
            printf("\nThe id provided is not in the range of 1000 and 9999, please try again.\n");
        }

    } while (attemps <= 3 && access == 0);

    isAuth(access);

    return 0;
}

bool isValidId(int id)
{
    return (id >= 1000 && id <= 9999);
}

void isAuth(int access)
{
    access ? printf("\nAccess granted!\n") : printf("\nAccess denied!\n");
}
