#include "include/report.h"
#include <stdio.h>

void generateReport(AttdTable *attdTable)
{
  if (attdTable == NULL)
  {
    printf("Error: attdTable is NULL\n");
    return;
  }
  if (attdTable->subject == NULL)
  {
    printf("Error: attdTable->subject is NULL\n");
    return;
  }
  if (attdTable == NULL || attdTable->students == NULL || attdTable->classSize <= 0)
  {
    printf("No attendance data available.\n");
    return;
  }
}