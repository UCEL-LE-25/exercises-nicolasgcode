#include "generate_reports.h"
#include "calculations.h"
#include <stdio.h>

void printSectorActivity(Company *company) {

  SectorPages results = calculateSectorPages(company);

  printf(
      "\nRRHH printed %d pages\nADM printed %d pages\nTECH printed %d pages\n",
      results.rrhh, results.adm, results.tech);

  if (results.rrhh == 0 && results.adm == 0 && results.tech == 0) {
    printf("\nNo pages have been printed yet\n");
  } else {

    if (results.rrhh >= results.adm && results.rrhh >= results.tech)
      printf("\nRRHH printed the most pages: %d\n", results.rrhh);
    else if (results.adm >= results.tech)
      printf("\nADM printed the most pages: %d\n", results.adm);
    else
      printf("\nTECH printed the most pages: %d\n", results.tech);
  }
}

void printActivePrinters(Company *company) {

  ActivePrinters results = calculateActivePrinters(company);

  printf("\nRRHH active printers: %d\nADM active printers: %d\nTECH active "
         "printers: %d\n",
         results.rrhh, results.adm, results.tech);
}
