#include "print_map.h"
#include "index.h"
#include <stdio.h>

void printMap(int *map) {

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      int index = i * COLS + j;

      switch (map[index]) {

      case 0:
        printf(". |");
        break;

      case 1:
        printf("# |");
        break;

      case 2:
        printf("* |");
        break;
      default:
        printf("? |");
        break;
      }
    }
    printf("\n");
  }
}
