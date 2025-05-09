#include "suite_menu.h"
#include "area_menu.h"
#include "company.h"
#include "index.h"
#include "manage_printers.h"
#include "suite.h"
#include <stdio.h>

void suiteMenu(Company *company, Suite *suite) {

  int opt;

  do {

    printf("\nOPERATIONS\n\n 1. Add pages\n 2. Change state\n 3. Go back\n");

    printf("\nPlease, select an option: ");

    scanf("%d", &opt);

    switch (opt) {

    case 1:
      addPages(suite);
      break;

    case 2:
      changeState(suite);
      break;

    case 3:
      areaMenu(company);
      break;

    default:
      printf("Invalid option.");
      break;
    }

  } while (opt != 3);
}

void showSuite(int opt, Company *company) {

  Suite *suite;

  switch (opt) {

  case 1:

    suite = &company->rrhh;

    break;

  case 2:
    suite = &company->adm;
    break;

  case 3:
    suite = &company->tech;
    break;
  }

  printSuite(suite);
  suiteMenu(company, suite);
}
