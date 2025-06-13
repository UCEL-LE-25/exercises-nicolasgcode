#pragma once
#include "typedefs.h"
#include <stdbool.h>

void pathExists(char *file_path);

bool userFileExists();

bool userExists(loadedUsers *loaded, loginData data, Session *session);

bool checkAccessLevel(Session *session);

void checkId(int *id);
void checkName(char name[]);
void checkLastname(char lastname[]);
void checkDni(int *dni);
void checkIdExists(int *id, AttdTable *table);
void checkDniExists(int *dni, loadedUsers *loaded);
void checkUsernameExists(char username[], loadedUsers *loaded);
void checkUsername(char username[]);
void checkPassword(char password[]);
int isValidSubject(const char *subject);
void isValidOpt(int *opt);
void isValidQuantity(int *classSize);

void checkSubject(char *subject);

void backupExists(File file);

void isNull(File file);
