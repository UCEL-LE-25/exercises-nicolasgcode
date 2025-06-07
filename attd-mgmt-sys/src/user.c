#include "include/user.h"
#include "include/constants.h"
#include "include/validators.h"
#include <stdio.h>
#include <string.h>

bool login(Session *session)
{

  char username[MAX_CHAR];

  char password[MAX_CHAR];

  do
  {

    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

  } while (!userExists(username, password, session));

  return true;
}

void logout(Session *session)
{
  session->currentUser = NULL;
  printf("Logged out.");
}
