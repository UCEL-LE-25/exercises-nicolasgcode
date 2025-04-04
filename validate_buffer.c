#include <stdio.h>
#include <string.h>

int main(void) {
  char msg[] = "C check";
  char buffer[10];

  if ((strlen(msg)) < sizeof(buffer) - 1) {

    strcpy(buffer, msg);
    printf("%s\n", buffer);

  } else {

    printf("Not enough space");
  }

  return 0;
}
