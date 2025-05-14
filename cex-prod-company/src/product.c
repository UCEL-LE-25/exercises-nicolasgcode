#include "plant.h"

void loadProduct(ProdPlant selectedPlant) {

  for (int i = 0; i < AVBL_PRODUCTS; i++) {
    printf("Enter product %d units: ", i + 1);
    scanf("%d", &selectedPlant->product[i].units);
  }
}
