#pragma once
#include "constants.h"

typedef enum
{
  TEACHER,
  ADMIN
} ROLE;

typedef struct
{
  int year;
  int month;
  int day;
} Date;

typedef struct
{
  int dni;
  char username[50];
  unsigned int pswHash;
  ROLE role;

} User;

typedef struct
{
  char username[MAX_CHAR];
  char password[MAX_CHAR];

} loginData;

typedef struct
{
  User users[MAX_USERS];
  int count;
} loadedUsers;

typedef struct
{

  User *currentUser;

} Session;

typedef struct
{

  int studentId;
  char name[MAX_CHAR];
  char lastName[MAX_CHAR];
  int attendance[MAX_DAYS]; // 0 - absent, 1 - present

} Student;

typedef struct
{
  char name[MAX_CHAR];
  char location[MAX_CHAR];
  Date createdAt;
} File;
