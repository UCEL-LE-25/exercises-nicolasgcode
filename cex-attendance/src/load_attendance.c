#include "load_attendance.h"

#include <stdio.h>

void loadAttendance(int *attendanceSheet) {
  for (int i = 0; i < WORKSHOPS; i++) {

    printf("\nWORKSHOP %d ATTENDANCE\n", i + 1);
    for (int j = 0; j < DAYS; j++) {
      printf("Please, enter day %d attendance: ", j + 1);
      scanf("%d", (attendanceSheet + i * DAYS + j));
    }
  }
}
