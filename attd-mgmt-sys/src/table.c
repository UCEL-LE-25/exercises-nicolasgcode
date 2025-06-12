#include "include/table.h"
#include "include/file.h"
#include "include/menus.h"
#include "include/validators.h"
#include <stdio.h>
#include <stdlib.h>

void createTable()
{
  int opt;
  int days;
  int classSize;

  char subject[50];

  printf("Select table type (0-weekly/1-biweekly): ");
  scanf("%d", &opt);
  printf("How many students are in the class? (max %d): ", MAX_STUDENTS);
  scanf("%d", &classSize);

  switch (opt)
  {
  case 0:
    days = 7;
    break;
  case 1:
    days = 15;
    break;

  default:
    printf("Invalid option. Please choose 0 for weekly or 1 for biweekly.\n");
    break;
  }

  printf("Enter subject: ");
  scanf(" %49s", &subject);

  Student *students = malloc(classSize * sizeof(Student));
  if (students == NULL)
  {
    perror("Failed to allocate memory for students");
    return;
  }

  loadStudents(students, classSize, days);

  createFile(subject, students, classSize, days);

  free(students);
}

void loadStudents(Student students[], int classSize, int days)
{
  int id;
  char name[MAX_CHAR];
  char lastName[MAX_CHAR];

  printf("\nPlease, provide ID, name and lastname for each student.\n");

  for (int i = 0; i < classSize; i++)
  {
    printf("Student %d: \n", i + 1);
    printf("ID: ");
    scanf("%d", &id);
    checkIdExists(id, students, classSize);
    students[i].studentId = id;

    printf("Name: ");
    scanf(" %49s", name);
    checkName(name);
    strncpy(students[i].name, name, MAX_CHAR - 1);

    printf("Last Name: ");
    scanf(" %49s", lastName);
    checkLastname(lastName);
    strncpy(students[i].lastName, lastName, MAX_CHAR - 1);

    for (int j = 0; j < days; j++)
    {
      students[i].attendance[j] = 0;
    }
  }
}

void printTable(FILE *f)
{

  char line[1024];
  int row = 0;

  while (fgets(line, sizeof(line), f))
  {
    line[strcspn(line, "\n")] = 0;
    char *token = strtok(line, ",");
    int col = 0;

    while (token)
    {
      if (row == 0)
      {

        if (col == 0)
          printf("%-8s", "ID");
        else if (col == 1)
          printf("%-12s", "Nombre");
        else if (col == 2)
          printf("%-12s", "Apellido");
        else
          printf("%-4s", token);
      }
      else
      {
        if (col == 0)
          printf("%-8s", token);
        else if (col == 1)
          printf("%-12s", token);
        else if (col == 2)
          printf("%-12s", token);
        else
        {

          if (strcmp(token, "1") == 0)
            printf(GREEN "%-4s" RESET, "1");
          else if (strcmp(token, "0") == 0)
            printf(RED "%-4s" RESET, "0");
          else
            printf("%-4s", token);
        }
      }

      token = strtok(NULL, ",");
      col++;
    }

    printf("\n");
    row++;
  }
}

void openTable(char *subject, Session *session)
{
  char filePath[256];
  FILE *table = getFile(subject, filePath);
  if (!table)
    return;

  printTable(table);

  manageTableMenu(table, filePath, session);

  fclose(table);
}

void editAttendance(FILE *table, Student students[], int days, int classSize, char *filePath)
{

  int id, day, newVal;
  printf("Ingrese ID del estudiante a editar: ");
  scanf("%d", &id);

  printf("Ingrese dia: (1 - %d): ", days);
  scanf("%d", &day);

  printf("Nuevo valor (1=presente, 0=ausente): ");
  scanf("%d", &newVal);

  int found = 0;
  for (int i = 0; i < classSize; i++)
  {
    if (students[i].studentId == id)
    {
      found = 1;
      if (day >= 1 && day <= days)
      {
        students[i].attendance[day - 1] = newVal;
        printf("Asistencia actualizada para %s %s, Day %d\n",
               students[i].name, students[i].lastName, day);
      }
      else
      {
        printf("Día inválido.\n");
      }
      break;
    }
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
