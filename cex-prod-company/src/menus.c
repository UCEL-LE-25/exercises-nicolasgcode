#include "menus.h"
#include <stdio.h>
#include <stdlib.h>

void operarPlanta(Company *company) {
  printf("Seleccione planta:\n");
  printf("------------------\n");
  printf("1. Planta 1\n");
  printf("2. Planta 2\n");
  printf("3. Planta 3\n");
  int opt;
  scanf("%d", &opt);
  switch (opt) {
  case 1:
  case 2:
  case 3:
    loadPlant(opt, company);
    break;
  default:
    printf("Planta no válida.\n");
  }
}

void mostrarReporte(Company *company) {
  printf("Seleccione que mostrar del reporte:\n");
  printf("----------------------------------------\n");
  printf("1. Planta con mayor rentabilidad\n");
  printf("2. Planta con menor margen 2\n");
  printf("3. Promedios 3\n");
  int planta;
  scanf("%d", &planta);
  switch (planta) {
  case 1:
    rentabilidad();
    break;
  case 2:
    margencost();
    break;
  case 3:
    printf("Mostrando reporte de Planta 3\n");
    break;
  default:
    printf("Planta no válida.\n");
  }
}

void mainMenu(Company *company) {
  int opcion;

  do {
    printf("\n--- Menú ---\n");
    printf("1. Operar planta\n");
    printf("2. Mostrar Reporte\n");
    printf("3. Resultados\n");
    printf("4. Salir\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opt);

    switch (opt) {
    case 1:
      operarPlanta();
      break;
    case 2:
      mostrarReporte();
      break;
    case 3:
      printf("Saliendo del programa...\n");
      break;
    default:
      printf("Opción inválida. Intente de nuevo.\n");
    }
  } while (opcion != 3);
}
