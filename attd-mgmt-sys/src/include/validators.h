#pragma once
#include "typedefs.h"
#include <stdbool.h>

void pathExists(char *file_path);

void fileExists(File file);

bool userExists(char username[], char password[], Session *session);

void checkAccessLevel(User user);

void backupExists(File file);

void isNull(File file);
