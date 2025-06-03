#include "include/helpers.h"

char *roleToString(ROLE role) {

  switch (role) {
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

User setCurrentSession(User user) {
  User authenticatedUser = user;

  return authenticatedUser;
}
