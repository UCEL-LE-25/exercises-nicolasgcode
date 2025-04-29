#include "index.h"
#include "load_map.h"
#include "print_map.h"
#include <stdio.h>

int main(void) {

  int map[COLS][ROWS] = {0};

  loadMap((int *)map);

  printMap((int *)map);

  return 0;
}
