#include "include/student.h"
#include "include/file.h"
#include "include/table.h"
#include "include/helpers.h"
#include <string.h>

void updateStudent(FILE *table, AttdTable *attdTable, char *filePath)
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

  printf("Updated file: %s\n", filePath);

  clearScreen();

  printTable(table);
}
