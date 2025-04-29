#include "load_map.h"
#include "index.h"
#include <stdio.h>

void loadMap(int *map) {

  for (int i = 0; i < ROWS; i++) {

    printf("\nROW %d\n", i + 1);
    for (int j = 0; j < COLS; j++) {
      printf("Enter 0, 1, or 2  for column %d: ", j + 1);
      scanf("%d", (map + i * COLS + j));
    }
  }
}
