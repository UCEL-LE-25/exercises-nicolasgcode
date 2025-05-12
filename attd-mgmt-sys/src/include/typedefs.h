#pragma once
#include "constants.h"

typedef struct {
  int year;
  int month;
  int day;
} Date;

typedef struct {

  int studentId;
  char name[MAX_CHAR];
  char lastName[MAX_CHAR];
  int attendance[MAX_DAYS]; //0: absent | 1: present
  //subject 1..n ?
} Student;

typedef struct {

  int tableId;
  int days;
  int numStudents;

  Student students[];

} AttdTable;

typedef struct {

  int tableId;
  int cols[GR_TABLE_COLS];
  int numStudents;

  Student students[];

} GrTable; // grade table

typedef struct {
  int tableId;
  int cols[ACAD_CAL_TABLE_COLS];
  Date date[];
  char event[MAX_CHAR];
} AcadCalTable; // Academic Calendar Table
