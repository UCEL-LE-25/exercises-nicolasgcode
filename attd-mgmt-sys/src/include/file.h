#pragma once

#include "typedefs.h"
#include <stdio.h>

File createFile(char *subject, Student students[], int classSize, int days);

void createUserFile();

void createPhysicalFile(char *file_path);

void writeFile(char *file_path, Student students[], int classSize, int days);

void writeUserFile(User user);

void getAllFiles();

FILE *getFile(const char *subject, char *outPath);

int backupFile(File *file, char *filePath);

void deleteFile(FILE *table, char *filePath);

int loadStudentsFromFile(FILE *table, Student students[], int *classSize, int *days);

int loadUsersFromFile(loadedUsers *users);
