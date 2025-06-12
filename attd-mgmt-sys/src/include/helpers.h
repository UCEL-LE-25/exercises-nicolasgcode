#pragma once
#include "typedefs.h"

char *roleToString(ROLE role);

char *renderMenu(Session *session);

unsigned int hashPsw(char *password);
