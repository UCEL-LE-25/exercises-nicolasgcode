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
    strcat(menuDisplay, "1. View tables\n2. Generate reports\n3. Delete tables\n4. Exit\n");
  }
  else if (strcmp(roleStr, "Teacher") == 0)
  {
    strcat(menuDisplay, "1. View tables\n2. Generate reports\n3. Exit\n");
  }
  else
  {
    strcat(menuDisplay, "Unknown role\n");
  }

  return menuDisplay;
}
