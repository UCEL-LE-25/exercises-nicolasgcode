#include "include/table.h"
#include "include/file.h"
#include <stdio.h>
#include <stdlib.h>

void createTable()
{
  int opt;
  int days;
  int classSize;

  char subject[50];

  printf("Do you want your table weekly or monthly? (1-weekly/2-monthly): ");
  scanf("%d", &opt);
  printf("How many students are in the class? (max %d): ", MAX_STUDENTS);
  scanf("%d", &classSize);
  switch (opt)
  {
  case 1:
    days = 7;
    break;
  case 2:
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
  int count = 0;

  printf("Please, provide id, name and lastname for each student.\n");

  for (int i = 0; i < classSize; i++)
  {
    printf("Student %d: \n", i + 1);
    printf("ID: ");
    scanf("%d", &students[i].studentId);
    printf("Name: ");
    scanf(" %49s", students[i].name);
    printf("Last Name: ");
    scanf(" %49s", students[i].lastName);

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
    line[strcspn(line, "\n")] = 0; // eliminar salto de línea
    char *token = strtok(line, ",");
    int col = 0;

    while (token)
    {
      if (row == 0)
      {
        // Encabezado
        if (col == 0)
          printf("%-6s", "ID");
        else if (col == 1)
          printf("%-12s", "Nombre");
        else if (col == 2)
          printf("%-12s", "Apellido");
        else
          printf("%-6s", token); // Día
      }
      else
      {
        if (col == 0)
          printf("%-6s", token); // ID
        else if (col == 1)
          printf("%-12s", token); // Nombre
        else if (col == 2)
          printf("%-12s", token); // Apellido
        else
        {
          // Asistencia: 1 o 0 con color
          if (strcmp(token, "1") == 0)
            printf(GREEN "%-6s" RESET, "1");
          else if (strcmp(token, "0") == 0)
            printf(RED "%-6s" RESET, "0");
          else
            printf("%-6s", token); // por si hay error
        }
      }

      token = strtok(NULL, ",");
      col++;
    }

    printf("\n");
    row++;
  }
}
