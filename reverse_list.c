#include <stdio.h>

int main(void) {
  int numbers[4] = {0, 1, 2, 3};
  int reversedList[4];

  int arrayLength = sizeof(numbers) / sizeof(numbers[0]);

  for (int i = arrayLength - 1; i >= 0; i--) {

    for (int j = 0; j < arrayLength; i++) {

      reversedList[j] = numbers[i];
    }
  }

  for (int x = 0; x < arrayLength; x++) {
    printf("Reversed list:%d\n", reversedList[x]);
  }

  return 0;
}
