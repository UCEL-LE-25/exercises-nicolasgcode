#include "include/validators.h"
#include "include/constants.h"
#include "include/typedefs.h"
#include <stdio.h>
#include <string.h>

User defaultUsers[] = {
    {1, "root", "admin", ADMIN},
    {2, "teacher", "12345678", TEACHER}};

bool userExists(char *username, char *password, Session *session)
{

  for (int i = 0; i < 2; i++)
  {

    if (strcmp(username, defaultUsers[i].username) == 0 &&
        strcmp(password, defaultUsers[i].password) == 0)
    {
      session->currentUser = &defaultUsers[i];
      return true;
    }
  }

  return false;
}

bool userNotNull(Session *session) { return session->currentUser != NULL; }
