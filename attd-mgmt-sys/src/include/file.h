#pragma once

#include "typedefs.h"
#include <stdio.h>

File createFile(AttdTable *table);

void createUserFile();

void createPhysicalFile(char *file_path);

void writeFile(char *file_path, AttdTable *table);

void writeUserFile(User user);

void getAllFiles();

FILE *getFile(const char *subject, char *outPath);

int backupFile(File *file, char *filePath);

void deleteFile(FILE *table, char *filePath);

int loadStudentsFromFile(FILE *table, AttdTable *attdTable);

int loadUsersFromFile(loadedUsers *users);

void saveUsersToFile(loadedUsers *users);
