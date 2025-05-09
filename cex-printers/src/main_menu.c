#include "main_menu.h"
#include "area_menu.h"
#include "company.h"
#include <stdio.h>

void mainMenu(Company *company) {

  int opt;

  do {

    printf("\nPRINTER MGMT SYS\n\n 1. Manage printers\n 2. \n 3. \n 4. Exit\n");

    printf("\nPlease, select an option: ");

    scanf("%d", &opt);

    switch (opt) {

    case 1:
      areaMenu(company);
      break;

    case 2:
      break;

    case 3:
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
