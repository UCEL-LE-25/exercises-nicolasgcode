#include "manage_results.h"
#include "load_attendance.h"
#include <stdio.h>

#include "count_attendance.h"

void resultsMenu(int *attendanceSheet) {

  int opt;

  do {

    printf("\nMANAGE RESULTS\n 1. Generate attendance report\n 2. To be "
           "implemented\n 3. To be implemented\n 4. Exit");

    printf("\nPlease, select an option: ");
    scanf("%d", &opt);

    switch (opt) {
    case 1:
      printAttendanceReport(attendanceSheet);
      break;
    case 4:
      printf("\nProgram terminated.\n");
      break;
    default:
      printf("Invalid option");
      break;
    }

  } while (opt != 4);
}

void printAttendanceReport(int *attendanceSheet) {

  Attendance attendance = countAttendance(attendanceSheet);

  printf("\nATTENDANCE PER WORKSHOP\n WORKSHOP 1 ATTENDANCE: %d\n WORKSHOP 2 "
         "ATTENDANCE: %d\n WORKSHOP 3 "
         "ATTENDANCE: %d\n",
         attendance.workshop1, attendance.workshop2, attendance.workshop3);

  printf("\nAVERAGE ATTENDANCE PER WORKSHOP\n WORKSHOP 1 AVG ATTENDANCE: "
         "%d\n WORKSHOP 2 AVG ATTENDANCE: "
         "%d\n WORKSHOP 3 AVG "
         "ATTENDANCE: %d\n",
         attendance.workshop1 / DAYS, attendance.workshop2 / DAYS,
         attendance.workshop3 / DAYS);

  printf("\nOVERALL ATTENDANCE: %d\n",
         attendance.workshop1 + attendance.workshop2 + attendance.workshop3);

  printf("OVERALL AVERAGE ATTENDANCE: %d\n",
         (attendance.workshop1 + attendance.workshop2 + attendance.workshop3) /
             DAYS);
}
