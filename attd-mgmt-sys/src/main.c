#include "include/menus.h"
#include "include/typedefs.h"
#include <string.h>
int main(void)
{

  Session session = {NULL};
  loadedUsers users[MAX_USERS] = {0};

  program(&session, users);
  return 0;
}
