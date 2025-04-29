#include "print_attendance.h"
#include "load_attendance.h"

#include <stdio.h>

void printAttendance(int *attendanceSheet) {

  printf("\nATTENDANCE SHEET PER DAY\n");
  printf("----------------------------------------------");

  for (int i = 0; i < WORKSHOPS; i++) {

    printf("\nWORKSHOP %d |", i + 1);
    for (int j = 0; j < DAYS; j++) {

      printf("%4d  |", *(attendanceSheet + i * DAYS + j));
    }

    printf("\n");
  }

  printf("----------------------------------------------\n");
}
