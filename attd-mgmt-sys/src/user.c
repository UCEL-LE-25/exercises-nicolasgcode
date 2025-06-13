#include "include/user.h"
#include "include/constants.h"
#include "include/validators.h"
#include "include/helpers.h"
#include "include/file.h"
#include "include/menus.h"
#include <stdio.h>
#include <string.h>

void signUp(Session *session, loadedUsers *users)
{
  clearScreen();

  User user;
  user.role = TEACHER;
  int dni;
  char username[MAX_USERNAME];
  char password[MAX_PSW];

  printf("Please, create your account.\n");
  printf("DNI: ");
  scanf("%d", &dni);
  checkDniExists(dni, users);
  user.dni = dni;
  printf("Username: ");
  scanf("%s", username);
  checkUsernameExists(username, users);
  strncpy(user.username, username, MAX_USERNAME - 1);
  printf("Password: ");
  scanf("%s", password);
  checkPassword(password);
  user.pswHash = hashPsw(password);

  writeUserFile(user);

  printf("Account created successfully for user: %s\n", user.username);
  program(session, users);
}

bool login(Session *session, loadedUsers *users)
{
  clearScreen();

  printf("\nPlease, log in\n\n");

  loginData data;

  do
  {

    printf("Username: ");
    scanf("%s", data.username);
    printf("Password: ");
    scanf("%s", data.password);

  } while (!userExists(users, data, session));

  return true;
}

void logout(Session *session)
{
  session->currentUser = NULL;
  printf("Logged out.");
}

User createDefaultUser()
{
  User root;
  root.dni = 0;
  strncpy(root.username, "root", MAX_CHAR);
  root.pswHash = hashPsw("admin");
  root.role = ADMIN;

  return root;
}