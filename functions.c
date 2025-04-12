#include <stdio.h>

void findMax(int numbers[], int arrayLenght, int *maxValue);

int main(void) {
  int maxValue = 0;
  int numbers[5] = {1, 2, 3, 4, 5};
  int arrayLenght = sizeof(numbers) / sizeof(numbers[0]);

  findMax(numbers, arrayLenght, &maxValue);

  printf("Max value: %d", &maxValue);

  return 0;
}

void findMax(int numbers[], int arrayLenght, int *maxValue) {

  for (int i = 0; i < arrayLenght; i++)

    if (numbers[i] > *maxValue) {
      *maxValue = numbers[i];
    }
}
