#pragma once

#include "typedefs.h"

File createFile(char *subject, int id);

void createPhysicalFile(char *file_path);

void writeFile(File *file);

void readFile(File *file, char *file_path);

int backupFile(File *file, char *file_path);

void deleteFile();
