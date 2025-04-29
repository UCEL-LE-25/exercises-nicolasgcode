#include "print_map.h"
#include <stdio.h>

void printMap(int *map) {

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d", map[i], map[j]);
      printf("\n");
    }
  }
}
