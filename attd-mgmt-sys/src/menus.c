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
    getAllFiles();

    printf("\n1. Open table\n2. Create new table\n3. Go back\n");

    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
      char subject[50];
      printf("Enter name of the table you want to open: \n");
      scanf(" %49s", subject);
      openTable(subject);
      break;
    case 2:
      createTable();
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
  } while (opt != 3);
}

void manageTableMenu(FILE *table, char *filePath)
{

  int opt;

  do
  {
    printf("\n1. Load/Edit attendance\n2. Delete table\n3. Go back\n");

    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
      editAttendance(table, filePath);
      break;
    case 2:
      deleteFile(table, filePath);
      break;
    case 3:
      break;
    default:
      printf("Invalid option. Please try again.\n");
      break;
    }
  } while (opt != 3);
}
