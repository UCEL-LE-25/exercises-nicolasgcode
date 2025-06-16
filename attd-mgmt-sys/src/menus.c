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
  clearScreen();
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
  opt == 'y' ? login(session, users) ? tableMenu(session, users)
                                     : printf("Login failed. Please try again.\n")
             : signUp(session, users);
}

void tableMenu(Session *session, loadedUsers *users)
{

  int opt;

  do
  {
    clearScreen();

    printf("\nWelcome %s\n", session->currentUser->username);
    printf("Role: %s\n\n", roleToString(session->currentUser->role));

    getAllFiles();

    strcmp(roleToString(session->currentUser->role), "Admin") == 0
        ? printf("\n1. Open table\n2. Create new table\n3. Manage users\n0. Exit\n")
        : printf("\n1. Open table\n2. Create new table\n0. Exit\n");

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
    case 3:
      if (checkAccessLevel(session))
      {
        manageUsersMenu(users);
      }
      else
      {
        printf("Access denied. Please log in with an admin account to manage users.\n");
      }
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
  clearScreen();

  int opt;

  AttdTable attdTable;

  if (!loadStudentsFromFile(table, &attdTable))
  {
    printf("\nCouldn't load table\n");
    return;
  }

  do
  {
    clearScreen();
    printTable(table);
    printf("\n%s", renderMenu(session));
    printf("\nSelect an option: ");

    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
      editAttendance(&attdTable, filePath);
      break;
    case 2:
      addStudent(&attdTable, filePath);
      break;
    case 3:
      updateStudent(&attdTable, filePath);
      break;
    case 4:
      deleteStudent(&attdTable, filePath);
      break;
    case 5:
      if (checkAccessLevel(session))
      {
        deleteFile(table, filePath);
      }
      else
      {
        generateReport(table, &attdTable);
      }
      break;

    default:
      printf("Invalid option. Please try again.\n");
      break;
    }
  } while (opt != 0);
}

void manageUsersMenu(loadedUsers *users)
{

  int opt;

  do
  {
    clearScreen();

    getAllUsers(users);
    printf("Manage Users\n");
    printf("\n1. Add User\n2. Edit User\n3. Delete User\n0. Back\n");
    printf("\nSelect an option: ");
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
      addUser(users);
      break;
    case 2:
      updateUser(users);
      break;
    case 3:
      deleteUser(users);
      break;
    case 0:
      return;
    default:
      printf("Invalid option. Please try again.\n");
      break;
    }
  } while (opt != 0);
}
