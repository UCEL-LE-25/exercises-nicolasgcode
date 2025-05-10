#include "manage_printers.h"
#include "suite.h"
#include <stdio.h>

void addPages(Suite *suite) {

  int opt;
  int pages;
  printf("Select printer: (1, 2, 3 or 4): ");
  scanf("%d", &opt);

  if (isActive(opt, suite)) {
    if (isValidOpt(opt)) {
      printf("Enter number of pages to add: ");
      scanf("%d", &pages);

      if (isValidQuantity(pages)) {

        suite->printers[opt - 1].pages += pages;
        printSuite(suite);

      } else {
        printf("\nQuantity must be greater than 0\n");
      }
    } else {
      printf("\nInvalid option. Try again.\n");
    }
  } else {
    printf("\nPlease, activate printer before adding pages.\n");
  }
}

void changeState(Suite *suite) {

  int opt;
  int state;
  printf("Select printer: (1, 2, 3 or 4): ");
  scanf("%d", &opt);

  if (isValidOpt(opt)) {
    printf("Enter state (0-1): ");
    scanf("%d", &state);

    if (isValidState(state)) {

      suite->printers[opt - 1].state = state;
      printSuite(suite);

    } else {
      printf("\nState must be 1 - Active or 0 - Inactive\n");
    }
  } else {
    printf("\nInvalid option. Try again.\n");
  }
}

bool isValidOpt(int opt) { return (opt > 0 && opt >= 1 && opt <= 4); }

bool isValidQuantity(int pages) { return pages > 0; }

bool isValidState(int state) { return (state == 0 || state == 1); }

bool isActive(int opt, Suite *suite) {
  return suite->printers[opt - 1].state == 1;
}
