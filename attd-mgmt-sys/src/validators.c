#include "include/validators.h"
#include "include/constants.h"
#include "include/typedefs.h"
#include "include/helpers.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool userExists(loadedUsers *loaded, loginData data, Session *session)
{
  for (int i = 0; i < loaded->count; i++)
  {
    if (strcmp(data.username, loaded->users[i].username) == 0 &&
        hashPsw(data.password) == loaded->users[i].pswHash)
    {
      session->currentUser = &loaded->users[i];
      return true;
    }
  }
  return false;
}

bool userNotNull(Session *session) { return session->currentUser != NULL; }

bool checkAccessLevel(Session *session)
{
  return session->currentUser->role == ADMIN;
}

void checkId(int *id)
{
  while (*id < 100000 || *id > 999999)
  {
    printf("\nInvalid ID.\nPlease enter a valid ID (6 digits): ");
    scanf("%d", id);
  }
}
void checkName(char *name)
{
  while (strlen(name) < 2 || strlen(name) > MAX_CHAR)
  {
    printf("\nInvalid name.\nPlease enter a valid name (2-50 characters): ");
    scanf(" %49s", name);
  }
}
void checkLastname(char *lastname)
{
  while (strlen(lastname) < 2 || strlen(lastname) > MAX_CHAR)
  {
    printf("\nInvalid last name.\nPlease enter a valid last name (2-50 characters): ");
    scanf(" %49s", lastname);
  }
}

void checkIdExists(int *id, AttdTable *table)
{
  for (int i = 0; i < table->classSize; i++)
  {
    if (table->students[i].studentId == *id)
    {
      printf("\nID already exists.\nPlease enter a different ID: ");
      scanf("%d", id);
      checkId(id);
      checkIdExists(id, table);
      return;
    }
  }
  checkId(id);
}

bool userFileExists()
{
  char file_path[1024];

  snprintf(file_path, sizeof(file_path), "%s%s.dat",
           DEFAULT_USER_FILE_PATH, USERS_FILE);

  FILE *file = fopen(file_path, "rb");
  if (file)
  {
    fclose(file);
    return true;
  }
  return false;
}

void checkDniExists(int *dni, loadedUsers *loaded)
{
  for (int i = 0; i < loaded->count; i++)
  {
    if (loaded->users[i].dni == *dni)
    {
      printf("\nDNI already exists.\nDNI: ");
      scanf("%d", dni);
      checkDni(dni);
      checkDniExists(dni, loaded);
      return;
    }
  }
}

void checkDni(int *dni)
{
  while (*dni < 10000000 || *dni > 99999999)
  {
    printf("\nInvalid DNI.\nPlease enter a valid ID (8 digits): ");
    scanf("%d", dni);
  }
}

void checkUsernameExists(char *username, loadedUsers *loaded)
{
  for (int i = 0; i < loaded->count; i++)
  {
    if (strcmp(loaded->users[i].username, username) == 0)
    {
      printf("\nUsername already exists.\nPlease enter a different username: ");
      scanf(" %49s", username);
      checkUsername(username);
      checkUsernameExists(username, loaded);
      return;
    }
  }
  checkUsername(username);
}

void checkUsername(char *username)
{
  while (strlen(username) < 3 || strlen(username) > MAX_USERNAME)
  {
    printf("\nInvalid username.\nPlease enter a valid username (3-20 characters): ");
    scanf(" %49s", username);
  }
}

void checkPassword(char *password)
{
  while (strlen(password) < 8 || strlen(password) > MAX_PSW)
  {
    printf("\nInvalid password.\nPlease enter a valid password (8-50 characters): ");
    scanf(" %49s", password);
  }
}

int isValidSubject(const char *subject)
{
  int len = strlen(subject);
  if (len < 3 || len > MAX_CHAR)
    return 0;

  for (int i = 0; i < len; i++)
  {
    if (!isalpha(subject[i]))
      return 0;
  }

  return 1;
}

void checkSubject(char *subject)
{
  while (!isValidSubject(subject))
  {
    printf("\nInvalid subject.\nOnly letters allowed (3-%d) characters, no spaces). Try again: ", MAX_CHAR);
    scanf(" %49s", subject);
  }
}

void isValidOpt(int *opt)
{
  while (*opt != 0 && *opt != 1)
  {
    printf("\nInvalid option.\nPlease, enter a valid option (0 or 1): ");
    scanf("%d", opt);
  }
}

void isValidQuantity(int *classSize)
{
  while (*classSize < 1 || *classSize > MAX_STUDENTS)
  {
    printf("\nInvalid quantity.\nPlease enter a quantity (1-%d): ", MAX_STUDENTS);
    scanf("%d", classSize);
  }
}