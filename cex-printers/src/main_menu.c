#include "main_menu.h"
#include "area_menu.h"
#include "company.h"
#include "generate_reports.h"
#include <stdio.h>

void mainMenu(Company *company) {

  int opt;

  do {

    printf(
        "\nPRINTER MGMT SYS\n\n 1. Manage printers\n 2. Sector activity \n 3. "
        "Active printers \n 4. Exit");

    printf("\nPlease, select an option: ");

    scanf("%d", &opt);

    switch (opt) {

    case 1:
      areaMenu(company);
      break;

    case 2:
      printSectorActivity(company);
      break;

    case 3:
      printActivePrinters(company);
      break;

    case 4:
      printf("\nProgram terminated.\n");
      break;

    default:
      printf("\nInvalid option.\n");
      break;
    }

  } while (opt != 4);
}
