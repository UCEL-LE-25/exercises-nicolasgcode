#include "program.h"
#include "operations.h"
#include "student.h"
#include <stdio.h>

void program(Student *students[]) {

  int opt;

  printf("\nSTUDENT MGMT SYS\n 1. Add students\n 2. Students list\n 3. "
         "Calculate score average\n 4. Exit\n");
  printf("Please, select an option: ");
  scanf("%d", &opt);

  switch (opt) {

  case 1:
    addStudents(students);
    break;

  case 2:
    break;

  case 3:
    break;

  case 4:
    printf("Program terminated.");
    break;

  default:
    printf("Invalid option.");
    break;
  }
}
