#include <stdio.h>

#include "load_map.h"
#include "print_map.h"

int main(void) {

  int map[5][5] = {0};

  loadMap((int *)map);

  printMap((int *)map);

  return 0;
}
