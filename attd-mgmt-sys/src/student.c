#include "include/student.h"
#include "include/file.h"
#include "include/table.h"
#include "include/helpers.h"
#include "include/validators.h"
#include <ctype.h>
#include <string.h>

void updateStudent(AttdTable *attdTable, char *filePath)
{
  int opt, id, newId;

  char newName[MAX_CHAR], newLastName[MAX_CHAR];

  printf("Enter ID of student to update: ");
  scanf("%d", &id);

  int found = 0;
  for (int i = 0; i < attdTable->classSize && !found; i++)
  {
    if (attdTable->students[i].studentId == id)
    {
      found = 1;
      printf("What do you wish to edit? (0-Student ID | 1-Name | 2-Lastname | 3-All data): ");
      scanf("%d", &opt);

      switch (opt)
      {
      case 0:
        printf("New student ID: ");
        scanf("%d", &newId);
        attdTable->students[i].studentId = newId;
        break;
      case 1:
        printf("New name: ");
        scanf(" %49[^\n]", newName);
        strncpy(attdTable->students[i].name, newName, MAX_CHAR - 1);
        break;
      case 2:
        printf("New last name: ");
        scanf(" %49[^\n]", newLastName);
        strncpy(attdTable->students[i].lastName, newLastName, MAX_CHAR - 1);
        break;
      case 3:
        printf("New student ID: ");
        scanf("%d", &newId);
        attdTable->students[i].studentId = newId;
        printf("New name: ");
        scanf(" %49[^\n]", newName);
        strncpy(attdTable->students[i].name, newName, MAX_CHAR - 1);
        printf("New last name: ");
        scanf(" %49[^\n]", newLastName);
        strncpy(attdTable->students[i].lastName, newLastName, MAX_CHAR - 1);
        break;
      default:
        printf("Invalid option. Please try again.\n");
        break;
      }
    }
  }

  if (!found)
  {
    printf("Student ID not found.\n");
    return;
  }

  writeFile(filePath, attdTable);
}

void addStudent(AttdTable *attdTable, char *filePath)
{
  if (attdTable->classSize >= MAX_STUDENTS)
  {
    printf("Class is full. Cannot add more students.\n");
    return;
  }

  int id;
  char name[MAX_CHAR];
  char lastName[MAX_CHAR];

  printf("New student ID: ");
  scanf("%d", &id);
  checkIdExists(&id, attdTable);

  printf("New student name: ");
  scanf(" %49s", name);
  checkName(name);

  printf("New student last name: ");
  scanf(" %49s", lastName);
  checkLastname(lastName);

  int i = attdTable->classSize;

  attdTable->students[i].studentId = id;
  strncpy(attdTable->students[i].name, name, MAX_CHAR - 1);
  attdTable->students[i].name[MAX_CHAR - 1] = '\0';

  strncpy(attdTable->students[i].lastName, lastName, MAX_CHAR - 1);
  attdTable->students[i].lastName[MAX_CHAR - 1] = '\0';

  for (int j = 0; j < attdTable->days; j++)
  {
    attdTable->students[i].attendance[j] = 0;
  }

  attdTable->classSize++;

  writeFile(filePath, attdTable);
}

void deleteStudent(AttdTable *attdTable, char *filePath)
{
  if (attdTable->classSize == 0)
  {
    printf("No students to delete.\n");
    return;
  }

  int id;
  printf("Enter the ID of the student to delete: ");
  scanf("%d", &id);

  int found = 0;
  for (int i = 0; i < attdTable->classSize && !found; i++)
  {

    if (attdTable->students[i].studentId == id)
    {
      found = 1;
      printf("Are you sure you want to delete student with ID %d and all associated data? (y/n): ", id);
      char confirm;
      scanf(" %c", &confirm);
      confirm = tolower(confirm);
      if (confirm == 'y')
      {
        for (int j = i; j < attdTable->classSize - 1; j++)
        {
          attdTable->students[j] = attdTable->students[j + 1];
        }
        attdTable->classSize--;

        writeFile(filePath, attdTable);

        break;
      }
    }
  }
}
