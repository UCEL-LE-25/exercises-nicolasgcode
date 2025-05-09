#pragma once
#include "company.h"


typedef struct {
  int rrhh;
  int adm;
  int tech;
} SectorPages;

typedef struct {
  int rrhh;
  int adm;
  int tech;
} ActivePrinters;

SectorPages calculateSectorPages(Company *company);

ActivePrinters calculateActivePrinters(Company *company);

