#include "include/menus.h"
#include "include/helpers.h"
#include "include/user.h"
#include "include/validators.h"
#include <stdio.h>
#include <string.h>

void loginMenu(Session *session)
{

  login(session) ? mainMenu(session)
                 : printf("Login failed. Please try again.\n");
}

void mainMenu(Session *session)
{
  int opt;

  do
  {

    printf("\n%s", renderMenu(session));

    printf("\nSelect an option: ");
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
      tableMenu(session);
      break;
    }

  } while (opt != 3);
}

void tableMenu(Session *session)
{

  int opt;

  do
  {

    printf("\n1. View tables\n2. Create new table\n3. Update existing table\n4. Delete table\n5. Go back\n");

    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    default:
      printf("Invalid option. Please try again.\n");
      break;
    }
  } while (opt != 2);
}
