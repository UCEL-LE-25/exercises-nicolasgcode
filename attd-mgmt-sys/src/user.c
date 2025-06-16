#include "include/user.h"
#include "include/constants.h"
#include "include/validators.h"
#include "include/helpers.h"
#include "include/file.h"
#include "include/menus.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
  checkDniExists(&dni, users);
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

void getAllUsers(loadedUsers *users)
{

  if (users->count > 0)
  {
    printf("\n%-20s %-20s %-20s %-10s\n", "DNI", "Username", "Password", "Role");
    printf("----------------------------------------------------------\n");
  }
  else
  {
    printf("No users found.\n");
    return;
  }

  for (int i = 0; i < users->count; i++)
  {
    User u = users->users[i];
    const char *roleStr = roleToString(u.role);

    if (roleStr == NULL)
    {
      roleStr = "Unknown";
    }

    if (strcmp(roleStr, "Admin") == 0)
    {
      printf("%-20d %-20s %-20s %s%-10s%s\n", u.dni, u.username, "********", RED, roleStr, RESET);
    }
    else if (strcmp(roleStr, "Teacher") == 0)
    {
      printf("%-20d %-20s %-20s %s%-10s%s\n", u.dni, u.username, "********", GREEN, roleStr, RESET);
    }
    else
    {
      printf("%-20d %-20s %-20s %-10s\n", u.dni, u.username, "********", roleStr);
    }
  }

  printf("\n");
}

void addUser(loadedUsers *users)
{
  if (users->count >= MAX_USERS)
  {
    printf("User limit reached.\n");
    return;
  }

  User newUser;
  int dni;
  char username[MAX_USERNAME];
  char password[MAX_PSW];

  printf("DNI: ");
  scanf("%d", &dni);
  checkDniExists(&dni, users);
  newUser.dni = dni;
  printf("Username: ");
  scanf(" %49s", username);
  checkUsernameExists(username, users);
  strncpy(newUser.username, username, MAX_USERNAME - 1);
  newUser.username[MAX_USERNAME - 1] = '\0';

  printf("Password: ");
  scanf(" %49s", password);
  checkPassword(password);
  newUser.pswHash = hashPsw(password);

  newUser.role = TEACHER;

  users->users[users->count++] = newUser;

  saveUsersToFile(users);
}

void updateUser(loadedUsers *users)
{
  int dni;
  int found = 0;
  printf("Enter the DNI of the user to edit: ");
  scanf("%d", &dni);

  for (int i = 0; i < users->count && !found; i++)
  {
    found = 1;
    if (users->users[i].dni == dni)
    {
      char newUsername[MAX_USERNAME];
      printf("New username: ");
      scanf(" %49s", newUsername);

      checkUsernameExists(newUsername, users);

      strncpy(users->users[i].username, newUsername, MAX_USERNAME - 1);
      users->users[i].username[MAX_USERNAME - 1] = '\0';

      saveUsersToFile(users);
      return;
    }
  }
}

void deleteUser(loadedUsers *users)
{
  int found = 0;

  int dni;
  printf("Enter the DNI of the user to delete: ");
  scanf("%d", &dni);

  for (int i = 0; i < users->count && !found; i++)
  {
    if (users->users[i].dni == dni)
    {
      found = 1;

      printf("Are you sure you want to delete user '%s' and all associated data? (y/n): ", users->users[i].username);
      char confirm;
      scanf(" %c", &confirm);
      confirm = tolower(confirm);
      if (confirm == 'y')
      {
        for (int j = i; j < users->count - 1; j++)
        {
          users->users[j] = users->users[j + 1];
        }

        users->count--;
        saveUsersToFile(users);
      }

      return;
    }
  }
}
