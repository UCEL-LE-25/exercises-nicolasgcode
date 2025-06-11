#pragma once
#include "typedefs.h"
#include <stdio.h>

void addStudent();

void updateStudent(FILE *table, Student students[], int classSize, int days, char *filePath);

void deleteStudent();
