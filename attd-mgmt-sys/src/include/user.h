#pragma once

#include "./typedefs.h"
#include <stdbool.h>

bool login(Session *session, loadedUsers *users);
void signUp(Session *session, loadedUsers *users);
void logout(Session *session);
void getAllUsers(loadedUsers *users);
void addUser();
void updateUser();
void deleteUser();
User createDefaultUser();
