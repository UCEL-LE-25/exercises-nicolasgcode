#pragma once
#include "typedefs.h"
#include <stdbool.h>

void pathExists(char *file_path);

bool userFileExists();

bool userExists(loadedUsers *loaded, loginData data, Session *session);

bool checkAccessLevel(Session *session);

void checkId(int id);
void checkName(char name[]);
void checkLastname(char lastname[]);
void checkId(int id);
void checkDni(int dni);
void checkIdExists(int id, Student students[], int classSize);
void checkDniExists(int dni, loadedUsers *loaded);
void checkDni(int dni);
void checkUsernameExists(char username[], loadedUsers *loaded);
void checkUsername(char username[]);
void checkPassword(char password[]);

void backupExists(File file);

void isNull(File file);
