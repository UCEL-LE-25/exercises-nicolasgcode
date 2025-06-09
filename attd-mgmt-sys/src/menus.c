#include "include/menus.h"
#include "include/helpers.h"
#include "include/user.h"
#include "include/table.h"
#include "include/file.h"
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
      getAllFiles();
      break;
    case 2:
      createTable();
      break;
    case 3:
      char subject[50];
      printf("Enter name of table to search: \n");
      scanf(" %49s", subject);
      getFile(subject);
      break;
    case 4:
      break;
    case 5:
      break;
    default:
      printf("Invalid option. Please try again.\n");
      break;
    }
  } while (opt != 5);
}
