#include <stdio.h>

int main(void) {

  int nums[4] = {3, 1, 5, 6};
  int length = (sizeof(nums) / sizeof nums[0]);

  int target = 7;

  for (int i = 0; i < length; i++) {

    for (int j = i + 1; j < length; j++) {
      if (nums[i] + nums[j] == target) {
        printf("[%d, %d]\n", i, j);
      } else {
      }
    }
  }

  return 0;
}
