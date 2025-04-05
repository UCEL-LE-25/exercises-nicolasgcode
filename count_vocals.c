#include <ctype.h>
#include <stdio.h>
#include <string.h>

typedef struct {

  int vowels;
  int consonants;
} Category;

Category classifyLetters(char text[]);

int main(void) {

  char text[100];

  printf("Enter a text: ");
  fgets(text, sizeof(text), stdin);

  Category category = classifyLetters(text);

  printf("\nThe given text has:\n %d Vowels\n %d Consonants\n", category.vowels,
         category.consonants);

  return 0;
}

Category classifyLetters(char text[]) {

  int textLength = strlen(text);

  Category category = {0, 0};

  for (int i = 0; i < textLength; i++) {

    if (isalpha(text[i])) {
      if (text[i] == 'A' || text[i] == 'a' || text[i] == 'E' ||
          text[i] == 'e' || text[i] == 'I' || text[i] == 'i' ||
          text[i] == 'O' || text[i] == 'o' || text[i] == 'U' ||
          text[i] == 'u') {
        category.vowels++;

      } else {

        category.consonants++;
      }
    }
  }

  return category;
}
