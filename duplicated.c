#include <stdio.h>

int main(void) {
  int nums[5] = {1, 2, 2, 4, 5};
  int arrayLength = sizeof(nums) / sizeof(nums[0]);

  int duplicated = 0;

  for (int i = 0; i < arrayLength; i++) {

    for (int j = i + 1; j < arrayLength; j++) {
      printf("%d\n", nums[i]);
      printf("%d\n", nums[j]);
      if (nums[i] == nums[j]) {
        duplicated = 1;
      } else {
        duplicated = 0;
      }
      break;
    }
  }
  duplicated ? printf("True") : printf("False");

  return 0;
}
