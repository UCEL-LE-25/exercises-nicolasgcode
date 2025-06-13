#include "include/table.h"
#include "include/file.h"
#include "include/date.h"
#include "include/menus.h"
#include "include/validators.h"
#include "include/helpers.h"
#include <stdio.h>
#include <stdlib.h>

void createTable(Session *session)
{
  int opt;
  int days;
  int classSize;
  Date date = getTodaysDate();

  char subject[MAX_CHAR];

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
  scanf(" %49s", subject);

  AttdTable table;
  strncpy(table.teacher, session->currentUser->username, MAX_CHAR - 1);
  table.teacher[MAX_CHAR - 1] = '\0';
  strncpy(table.subject, subject, MAX_CHAR - 1);
  table.subject[MAX_CHAR - 1] = '\0';
  table.createdAt = date;
  table.classSize = classSize;
  table.days = days;

  loadStudents(&table);

  createFile(&table);
}

void loadStudents(AttdTable *table)
{
  int id;
  char name[MAX_CHAR];
  char lastName[MAX_CHAR];

  printf("\nPlease, provide ID, name and lastname for each student.\n");

  for (int i = 0; i < table->classSize; i++)
  {
    printf("Student %d: \n", i + 1);
    printf("ID: ");
    scanf("%d", &id);
    checkIdExists(id, table);
    table->students[i].studentId = id;

    printf("Name: ");
    scanf(" %49s", name);
    checkName(name);
    strncpy(table->students[i].name, name, MAX_CHAR - 1);

    printf("Last Name: ");
    scanf(" %49s", lastName);
    checkLastname(lastName);
    strncpy(table->students[i].lastName, lastName, MAX_CHAR - 1);

    for (int j = 0; j < table->days; j++)
    {
      table->students[i].attendance[j] = 0;
    }
  }
}

void printTable(FILE *f)
{
  char line[1024];
  int row = 0;

  rewind(f);

  while (fgets(line, sizeof(line), f))
  {
    if (strlen(line) <= 1)
      continue;

    line[strcspn(line, "\n")] = 0;

    char *token = strtok(line, ",");
    int col = 0;

    while (token)
    {
      if (row == 0)
      {
        if (col == 0)
          printf("%-12s", "StudentId");
        else if (col == 1)
          printf("%-12s", "Name");
        else if (col == 2)
          printf("%-12s", "LastName");
        else
          printf("%-4s", token);
      }
      else
      {
        if (col <= 2)
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

  clearScreen();
  printTable(table);

  manageTableMenu(table, filePath, session);

  fclose(table);
}

void editAttendance(FILE *table, AttdTable *attdTable, char *filePath)
{

  if (attdTable == NULL || attdTable->students == NULL || attdTable->classSize <= 0)
  {
    printf("No attendance data available.\n");
    return;
  }

  int id, day, newVal;
  printf("Enter the ID of the student whose attendance you want to edit: ");
  scanf("%d", &id);

  printf("Ingrese dia: (1 - %d): ", attdTable->days);
  scanf("%d", &day);

  printf("New value (0-absent | 1-present): ");
  scanf("%d", &newVal);

  int found = 0;
  for (int i = 0; i < attdTable->classSize; i++)
  {
    if (attdTable->students[i].studentId == id)
    {
      found = 1;
      if (day >= 1 && day <= attdTable->days)
      {
        attdTable->students[i].attendance[day - 1] = newVal;
        printf("Attendance updated for %s %s, day %d\n",
               attdTable->students[i].name, attdTable->students[i].lastName, day);
      }
      else
      {
        printf("Invalid day.\n");
      }
      break;
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

void printTableHeader(AttdTable *attdTable)
{
  printf("Attendance Table for %s\n", attdTable->subject);
  printf("Created on: %02d/%02d/%04d by %s\n",
         attdTable->createdAt.day,
         attdTable->createdAt.month,
         attdTable->createdAt.year, attdTable->teacher);
}
