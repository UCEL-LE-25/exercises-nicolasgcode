#pragma once
#include "typedefs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createTable();

void updateTable();

void deleteTable();

void loadDates();

void loadStudents(Student students[], int classSize, int days);

void openTable(char *subject);

void loadEvents();

void editAttendance(FILE *table, Student students[], int classSize, int days, char *filePath);

void printTable(FILE *f);
