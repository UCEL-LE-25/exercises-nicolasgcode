#include "suite_menu.h"
#include "area_menu.h"
#include "company.h"
#include "index.h"
#include "suite.h"
#include <stdio.h>

void suiteMenu(int opt, Company *company) {

  int smOpt;

  do {

    printf("\nOPERATIONS\n\n 1. Add pages\n 2. Change state\n 4. Go back\n");

    printf("\nPlease, select an option: ");

    scanf("%d", &smOpt);

    switch (smOpt) {

    case 1:
      break;

    case 2:
      break;

    case 3:
      break;

    case 4:
      areaMenu(company);
      break;

    default:
      printf("Invalid option.");
      break;
    }

  } while (opt != 4);
}

void showSuite(int opt, Company *company) {

  Suite *selected;

  switch (opt) {

  case 1:

    selected = &company->rrhh;

    break;

  case 2:
    selected = &company->adm;
    break;

  case 3:
    selected = &company->tech;
    break;
  }

  printf("\nCURRENT SUITE\n");

  for (int i = 0; i < AVBL_PRINTERS; i++) {
    printf("Printer %d - Pages: %d, State: %d\n", i + 1,
           selected->printers[i].pages, selected->printers[i].state);
  }
}
