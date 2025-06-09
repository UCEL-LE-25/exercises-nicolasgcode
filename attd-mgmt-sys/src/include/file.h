#pragma once

#include "typedefs.h"

File createFile(char *subject, Student students[], int classSize, int days);

void createPhysicalFile(char *file_path);

void writeFile(char *file_path, Student students[], int classSize, int days);

void getAllFiles();
void getFile(const char *subject);

int backupFile(File *file, char *file_path);

void deleteFile();
