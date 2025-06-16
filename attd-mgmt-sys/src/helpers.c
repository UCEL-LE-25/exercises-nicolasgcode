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

  if (session == NULL || session->currentUser == NULL)
  {
    return "Logged out\n";
  }

  const char *roleStr = roleToString(session->currentUser->role);

  if (strcmp(roleStr, "Admin") == 0)
  {
    return "\n1. Load/Edit attendance\n2. Add student\n3. Update student\n4. Delete student\n5. Delete table\n0. Go back\n";
  }
  else if (strcmp(roleStr, "Teacher") == 0)
  {
    return "1. Load/Edit attendance\n2. Add student\n3. Update student\n4. Delete student\n5. Generate reports\n0. Go back\n";
  }
  else
  {
    return "Unknown role\n";
  }
}

unsigned int hashPsw(char *password)
{
  unsigned int hash = 5381;
  int c;
  while ((c = *password++))
    hash = ((hash << 5) + hash) + c;
  return hash;
}

void clearScreen()
{
  printf("\033[2J\033[H");
}
