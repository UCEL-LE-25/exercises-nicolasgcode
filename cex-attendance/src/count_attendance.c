#include "count_attendance.h"
#include "load_attendance.h"

Attendance countAttendance(int *attendanceSheet) {

  Attendance attendance = {0, 0, 0};

  for (int i = 0; i < WORKSHOPS; i++) {

    int breakConsecutive = 0;
    int row = i;

    for (int j = 0; j < DAYS && !breakConsecutive; j++) {
      int index = i * DAYS + j;

      switch (row) {

      case 0:
        if (attendanceSheet[index] > 0) {

          attendance.workshop1 += attendanceSheet[index];
        } else {
          attendance.workshop1 = 0;
          breakConsecutive = 1;
        }
        break;

      case 1:
        if (attendanceSheet[index] > 0) {
          attendance.workshop2 += attendanceSheet[index];
        } else {

          attendance.workshop2 = 0;
          breakConsecutive = 1;
        }
        break;

      case 2:
        if (attendanceSheet[index] > 0) {

          attendance.workshop3 += attendanceSheet[index];
        } else {

          attendance.workshop3 = 0;
          breakConsecutive = 1;
        }
        break;
      }
    }
  }

  return attendance;
}
