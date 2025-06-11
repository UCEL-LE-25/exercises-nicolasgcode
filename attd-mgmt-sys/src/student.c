#include "include/student.h"
#include "include/file.h"
#include "include/table.h"
#include <string.h>

void updateStudent(FILE *table, Student students[], int days, int classSize, char *filePath)
{
  int opt, id, newId;

  char newName[MAX_CHAR], newLastName[MAX_CHAR];

  printf("Ingrese ID del estudiante a editar: ");
  scanf("%d", &id);

  int found = 0;
  for (int i = 0; i < classSize; i++)
  {
    if (students[i].studentId == id)
    {
      found = 1;
      printf("What do you wish to edit? (0-Student ID | 1-Name | 2-Lastname | 3-All data)\n");
      scanf("%d", &opt);

      switch (opt)
      {
      case 0:
        printf("New student ID: ");
        scanf("%d", &newId);
        students[i].studentId = newId;
        break;
      case 1:
        printf("New name: ");
        scanf(" %49[^\n]", newName);
        strncpy(students[i].name, newName, MAX_CHAR - 1);
        break;
      case 2:
        printf("New last name: ");
        scanf(" %49[^\n]", newLastName);
        strncpy(students[i].lastName, newLastName, MAX_CHAR - 1);
        break;
      case 3:
        printf("New student ID: ");
        scanf("%d", &newId);
        students[i].studentId = newId;
        printf("New name: ");
        scanf(" %49[^\n]", newName);
        strncpy(students[i].name, newName, MAX_CHAR - 1);
        printf("New last name: ");
        scanf(" %49[^\n]", newLastName);
        strncpy(students[i].lastName, newLastName, MAX_CHAR - 1);
        break;
      default:
        printf("Invalid option. Please try again.\n");
        break;
      }
    }
    else
    {
      printf("Día inválido.\n");
    }
    break;
  }

  if (!found)
  {
    printf("ID de estudiante no encontrado.\n");
    return;
  }

  writeFile(filePath, students, classSize, days);

  printf("Archivo actualizado: %s\n", filePath);

  printTable(table);
}
