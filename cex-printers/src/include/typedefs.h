#pragma once
#include "index.h"

typedef struct {
  int pages;
  int state;
} Printer;

typedef struct {
  Printer printers[AVBL_PRINTERS];
} Suite;

typedef struct {
  Suite rrhh;
  Suite adm;
  Suite tech;
} Company;

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


