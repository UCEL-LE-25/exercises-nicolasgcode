#pragma once

#include "./typedefs.h"
#include <stdbool.h>

bool login(Session *session, loadedUsers *users);
void signUp(Session *session, loadedUsers *users);
void logout(Session *session);
User createDefaultUser();
