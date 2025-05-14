#include "plant.h"

void loadPlant(int opt, Company company) {
  ProdPlant *selectedPlant;

  switch (opt) {
  case 1:
    selectedPlant = &company->plant1;
    break;
  case 2:
    selectedPlant = &company->plant2;
    break;
  case 3:
    selectedPlant = &company->plant3;
    break;
  default:
    break;
  }
}
