#include "include/helpers.h"
#include <string.h>
#include <stdio.h>

char *roleToString(ROLE role)
{

  switch (role)
  {
  case TEACHER:
    return "Teacher";
    break;
  case ADMIN:
    return "Admin";
    break;
  default:
    return "Unknown";
    break;
  }
}

char *renderMenu(Session *session)
{
  static char menuDisplay[1024];

  if (session == NULL || session->currentUser == NULL)
  {
    snprintf(menuDisplay, sizeof(menuDisplay), "Logged out\n");
    return menuDisplay;
  }

  const char *roleStr = roleToString(session->currentUser->role);
  snprintf(menuDisplay, sizeof(menuDisplay), "Role: %s\n", roleStr);

  if (strcmp(roleStr, "Admin") == 0)
  {
    strcat(menuDisplay, "\n1. Load/Edit attendance\n2. Update student\n3. Delete student\n4. Delete table\n0. Go back\n");
  }
  else if (strcmp(roleStr, "Teacher") == 0)
  {
    strcat(menuDisplay, "1. Load/Edit attendance\n2. Update student\n3.Generate reports\n0. Go back\n");
  }
  else
  {
    strcat(menuDisplay, "Unknown role\n");
  }

  return menuDisplay;
}

unsigned int hashPsw(char *password)
{
  unsigned int hash = 5381;
  int c;
  while ((c = *password++))
    hash = ((hash << 5) + hash) + c;
  return hash;
}
