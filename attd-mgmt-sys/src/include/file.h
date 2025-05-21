#pragma once

#include "typedefs.h"

File createFile(char *name);

void writeFile();

void readFile(File *file, char *file_path);

int backupFile(File *file, char *file_path);

void deleteFile();
