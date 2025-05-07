#include "operations.h"
#include "student.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void addStudents(Student students[]) {

  for (int i = 0; i < MAX_STUDENTS; i++) {

    printf("\nPlease, complete the following\n");

    printf("Name: ");
    scanf("%s", students[i].name);

    printf("Age: ");
    scanf("%d", &students[i].age);

    printf("Score: ");
    scanf("%f", &students[i].finalScore);

    if (!continueAdd()) {
      break;
    }
  }
}

void printStudents(Student students[]) {}

void calculateAvgScore(Student students[]) {}

bool continueAdd() {

  char choice;

  getchar();

  printf("\nAdd another student? (y-n): ");
  scanf("%c", &choice);

  return (choice == 'Y' || choice == 'y');
}
