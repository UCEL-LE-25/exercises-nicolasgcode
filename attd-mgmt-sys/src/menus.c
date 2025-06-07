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

    printf("\n1. Test\n 2. Go back");

    scanf("%d", &opt);

    switch (opt)
    {

    case 2:
      break;
    }
  } while (opt != 2);
}
