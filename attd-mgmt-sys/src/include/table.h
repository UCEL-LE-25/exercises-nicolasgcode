#pragma once
#include "typedefs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createTable();

void updateTable();

void deleteTable();

void loadDates();

void loadStudents(AttdTable *table);

void openTable(char *subject, Session *session);

void loadEvents();

void editAttendance(FILE *table, AttdTable *attdTable, char *filePath);

void printTable(FILE *f);
