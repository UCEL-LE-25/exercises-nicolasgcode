#include "area_menu.h"
#include "main_menu.h"
#include "suite_menu.h"

#include <stdio.h>

void areaMenu(Company *company) {

  int opt;

  do {
    printf("\nSELECT AN AREA\n\n 1. RRHH\n 2. ADM \n 3. TECH \n 4. Go back\n");

    printf("\nPlease, select an option: ");

    scanf("%d", &opt);

    switch (opt) {

    case 1:
      showSuite(opt, company);
      break;

    case 2:
      showSuite(opt, company);
      break;

    case 3:
      showSuite(opt, company);
      break;

    case 4:
      mainMenu(company);
      break;

    default:
      printf("Invalid option.");
      break;
    }

  } while (opt != 4);
}
