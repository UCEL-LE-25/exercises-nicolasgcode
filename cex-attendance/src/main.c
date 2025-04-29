#include "load_attendance.h"
#include "manage_results.h"
#include "print_attendance.h"

int main(void) {

  int attendanceSheet[WORKSHOPS][DAYS] = {0};

  loadAttendance((int *)attendanceSheet);

  printAttendance((int *)attendanceSheet);

  resultsMenu((int *)attendanceSheet);

  return 0;
}
