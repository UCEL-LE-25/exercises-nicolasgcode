#include "calculations.h"

void calculateRentability(Company *company) {
  int aux, rentabilidad = 0;
  for (i = 0; i < count; i++) // CORREGIR
  {
    rentabilidad = (Precio_Venta[i] - Costo_Fabricaion[i]) * Cant_Producida[i];
    if (rentabilidad > aux) {
      aux = Precio_Venta[i];
    }
  }
  printf("Planta con mayor rentabilidad: \n", aux);
}

void calculateMargCost(Company *company) {
  int aux, margen = 0;
  for (i = 0; i < count; i++) // CORREGIR
  {
    margen = Precio_Venta[i] - Costo_Fabricaion[i];
    if (margen < aux) {
      aux = Precio_Venta[i];
    }
  }
  printf("Planta con menor margen: \n", aux);
}
