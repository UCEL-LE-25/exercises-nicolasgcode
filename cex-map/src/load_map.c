#include "load_map.h"
#include <stdio.h>

void loadMap(int *map) {

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("Enter 0, 1, or 2  for row %d column %d value: ", i + 1, j + 1);
      scanf("%d", &map[j]);
    }
  }
}
