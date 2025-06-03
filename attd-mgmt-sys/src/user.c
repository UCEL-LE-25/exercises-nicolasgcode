#include "include/user.h"
#include "include/constants.h"
#include "include/validators.h"
#include <stdio.h>

void login() {

  char username[MAX_CHAR];

  char password[MAX_CHAR];

  // do-while menu here

  printf("Username: ");
  scanf("%s", username);
  printf("Password: ");
  scanf("%s", password);

  userExists(username, password);
}

void logout() {

  // TBI - clear authenticated user - prob set to some empty user or null
  // TBI - return to login menu
}
