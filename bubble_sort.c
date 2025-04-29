#include <stdio.h>

void bubbleSort(int nums[], int arrayLength);

int main(void) {
  int nums[8] = {14, 20, 8, 26, 29, 40, 35, 7};
  int arrayLength = sizeof(nums) / sizeof(nums[0]);

  bubbleSort(nums, arrayLength);

  for (int i = 0; i < arrayLength; i++) {
    printf("%d\n", nums[i]);
  }
  return 0;
}

void bubbleSort(int nums[], int arrayLength) {
  int i, j, aux;

  for (i = 0; i < arrayLength; i++) {
    for (j = 0; j < arrayLength - 1; j++) {
      if (nums[j] > nums[j + 1]) {
        aux = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = aux;
      }
    }
  }
}
