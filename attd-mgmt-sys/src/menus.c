#include "include/menus.h"
#include "include/helpers.h"
#include "include/user.h"
#include "include/table.h"
#include "include/file.h"
#include "include/validators.h"
#include "include/student.h"
#include "include/report.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void program(Session *session, loadedUsers *users)
{
  if (!userFileExists())
  {
    createUserFile();
  }
  loadUsersFromFile(users);
  char opt;
  printf("\nWelcome to Attendify.\n");
  printf("Already have an account? (y/n): ");
  scanf(" %c", &opt);
  opt = tolower(opt);
  opt == 'y' ? login(session, users) ? mainMenu(session)
                                     : printf("Login failed. Please try again.\n")
             : signUp(session, users);
}

void mainMenu(Session *session)
{
  int opt;

  do
  {
    printf("\n1. View tables\n2. Generate reports\n0. Exit\n");

    printf("\nSelect an option: ");
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
      tableMenu(session);
      break;
    case 2:
      char subject[MAX_CHAR];
      getAllFiles();
      printf("Enter name of the table you want to open: ");
      scanf(" %49s", subject);
      openTable(subject, session);
      break;
    }

  } while (opt != 0);
}

void tableMenu(Session *session)
{

  int opt;

  do
  {
    getAllFiles();

    printf("\n1. Open table\n2. Create new table\n0. Go back\n");

    printf("\nSelect an option: ");

    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
      char subject[50];
      printf("Enter name of the table you want to open: ");
      scanf(" %49s", subject);
      openTable(subject, session);
      break;
    case 2:
      createTable(session);
      break;
    case 0:

      break;
    default:
      printf("Invalid option. Please try again.\n");
      break;
    }
  } while (opt != 0);
}

void manageTableMenu(FILE *table, char *filePath, Session *session)
{

  int opt;

  AttdTable attdTable = {0};
  printf("Table days %d", attdTable.days);

  if (!loadStudentsFromFile(table, &attdTable))
  {
    printf("\nCouldn't load table\n");
    return;
  }

  printf("Table days %d", attdTable.days);

  do
  {
    printf("\n%s", renderMenu(session));

    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
      editAttendance(table, &attdTable, filePath);
      break;
    case 2:
      updateStudent(table, &attdTable, filePath);
      break;
    case 3:
      generateReport(&attdTable);
      break;
    case 4:
      if (checkAccessLevel(session))
      {
        deleteFile(table, filePath);
        printf("Table deleted successfully.\n");
      }
      else
      {
        printf("Access denied. Please log in with an admin account to perform delete operations.\n");
      }
      break;
    default:
      printf("Invalid option. Please try again.\n");
      break;
    }
  } while (opt != 0);
}
