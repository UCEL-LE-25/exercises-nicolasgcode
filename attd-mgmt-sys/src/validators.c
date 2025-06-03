#include "include/validators.h"
#include "include/constants.h"
#include "include/helpers.h"
#include "include/typedefs.h"
#include <stdio.h>
#include <string.h>

void userExists(char *username, char *password) {

  User *users = DEFAULT_USERS;
  User authenticatedUser;

  int userFound = 0;

  for (int i = 0; i < 2 && !userFound; i++) {

    if (strcmp(username, users[i].username) == 0 &&
        strcmp(password, users[i].password) == 0) {
      authenticatedUser = setCurrentSession(users[i]);
      userFound = 1;
    }
  }

  userFound ? printf("Welcome! Logged in as: %s", authenticatedUser.username)
            : printf("User not found!");
}
