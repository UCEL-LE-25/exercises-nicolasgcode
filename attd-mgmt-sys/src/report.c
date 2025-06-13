#include "include/report.h"
#include "include/table.h"
#include "include/helpers.h"
#include <stdio.h>

void generateReport(FILE *table, AttdTable *attdTable)
{
  clearScreen();
  if (attdTable == NULL || attdTable->students == NULL || attdTable->classSize <= 0 || attdTable->days <= 0)
  {
    printf("No attendance data available.\n");
    return;
  }

  printf("\nAttendance report\n");

  printf("Class size: %d\n", attdTable->classSize);
  printf("Total days: %d\n\n", attdTable->days);

  int totalPossibleAttendances = attdTable->classSize * attdTable->days;
  int totalAttendances = 0;

  for (int i = 0; i < attdTable->classSize; i++)
  {
    int studentAttendance = 0;
    for (int d = 0; d < attdTable->days; d++)
    {
      studentAttendance += attdTable->students[i].attendance[d];
    }
    totalAttendances += studentAttendance;
    float studentPercent = (float)studentAttendance / attdTable->days * 100.0f;

    printf("Student ID %d - %s %s: Attendance %d/%d (%.2f%%)\n",
           attdTable->students[i].studentId,
           attdTable->students[i].name,
           attdTable->students[i].lastName,
           studentAttendance,
           attdTable->days,
           studentPercent);
  }

  float overallPercent = (float)totalAttendances / totalPossibleAttendances * 100.0f;
  printf("\nOverall attendance: %d/%d (%.2f%%)\n\n",
         totalAttendances,
         totalPossibleAttendances,
         overallPercent);

  printTable(table);
}