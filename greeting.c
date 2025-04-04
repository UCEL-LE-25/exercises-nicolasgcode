#include <stdio.h>
#include <string.h>

int main(void) {

  char origin[7] = "Hola, ";
  char greeting[15];

  strcpy(greeting, origin);

  strcat(greeting, "Mundo\n");

  printf("%s", greeting);

  return 0;
}
