#include "suite.h"
#include <stdio.h>

void printSuite(Suite *suite) {

  printf("\nSUITE\n");

  for (int i = 0; i < AVBL_PRINTERS; i++) {
    printf("Printer %d - Pages: %d, State: %d\n", i + 1,
           suite->printers[i].pages, suite->printers[i].state);
  }
}
