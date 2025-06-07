#pragma once
#include "constants.h"

typedef enum { TEACHER, ADMIN } ROLE;

typedef struct {
  int year;
  int month;
  int day;
} Date;

typedef struct {
  int id;
  char username[50];
  char password[50];
  ROLE role;

} User;

typedef struct {

  User *currentUser;

} Session;

typedef struct {

  int studentId;
  char name[MAX_CHAR];
  char lastName[MAX_CHAR];
  int attendance[MAX_DAYS]; // 0: absent | 1: present
  // subject 1..n ?
} Student;

typedef struct {
  char name[MAX_CHAR];
  char location[MAX_CHAR];
  Date createdAt;
} File;

typedef struct {

  int tableId;
  int days;
  int numStudents;
  Date genDate;

  Student students[];

} AttdTable;

typedef struct {

  int tableId;
  int cols[GR_TABLE_COLS];
  int numStudents;
  Date genDate;

  Student students[];

} GrTable; // grade table

typedef struct {
  int tableId;
  int cols[ACAD_CAL_TABLE_COLS];
  char event[MAX_CHAR];
  Date date[];
} AcadCalTable; // Academic Calendar Table
