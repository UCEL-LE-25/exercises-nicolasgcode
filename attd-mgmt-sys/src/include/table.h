#pragma once
#include "typedefs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createTable();

void loadStudents(AttdTable *table);

void openTable(char *subject, Session *session);

void editAttendance(AttdTable *attdTable, char *filePath);

void printTableHeader(AttdTable *attdTable);

void printTable(FILE *table);
