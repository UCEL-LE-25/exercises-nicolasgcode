#include "./include/date.h"

Date getTodaysDate() {
  Date date = {0, 0, 0};

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  date.year = tm.tm_year + 1900;
  date.month = tm.tm_mon + 1;
  date.day = tm.tm_mday;

  return date;
}
