#include <stdio.h>
#include <string.h>

int main(void) {

  char text[100];
  int vocals = 0;

  printf("Enter a text: ");
  fgets(text, sizeof(text), stdin);

  for (int i = 0; i < strlen(text); i++) {

    if (text[i] == 'A' || text[i] == 'a' || text[i] == 'E' || text[i] == 'e' ||
        text[i] == 'I' || text[i] == 'i' || text[i] == 'O' || text[i] == 'o' ||
        text[i] == 'U' || text[i] == 'u') {
      vocals++;
    } else {
      vocals = 0;
    }
  }

  printf("%d", vocals);

  return 0;
}
