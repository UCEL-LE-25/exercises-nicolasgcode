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

void loadEvents();

void printTable(FILE *f);
