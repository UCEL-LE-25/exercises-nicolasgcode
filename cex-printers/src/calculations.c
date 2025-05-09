#include "calculations.h"
#include "index.h"
#include <stdio.h>

SectorPages calculateSectorPages(Company *company) {

  SectorPages sectorPages = {0, 0, 0};

  for (int i = 0; i < AVBL_PRINTERS; i++) {

    sectorPages.rrhh += company->rrhh.printers[i].pages;
    sectorPages.adm += company->adm.printers[i].pages;
    sectorPages.tech += company->tech.printers[i].pages;
  }

  return sectorPages;
}

ActivePrinters calculateActivePrinters(Company *company) {

  ActivePrinters activePrinters = {0, 0, 0};

  for (int i = 0; i < AVBL_PRINTERS; i++) {

    activePrinters.rrhh += company->rrhh.printers[i].state;
    activePrinters.adm += company->adm.printers[i].state;
    activePrinters.tech += company->tech.printers[i].state;
  }

  return activePrinters;
}
