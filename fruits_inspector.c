#include <stdbool.h>
#include <stdio.h>

#define MAX_PLANTS 4
#define MAX_FRUITS 2

bool isMatch(int pressureSensor, int colorSensor);

int main(void) {
  int ripeFruits = 0;
  int inspected = 0;
  int pressureSensor;
  int colorSensor;

  do {

    printf("\nFRUIT INSPECTOR\n");
    printf("\nEnter pressure sensor value: (1-ok/0-not ok)\n");
    scanf("%d", &pressureSensor);
    printf("\nEnter color sensor value: (1-ok/0-not ok)\n");
    scanf("%d", &colorSensor);

    if (isMatch(pressureSensor, colorSensor)) {
      ripeFruits++;
      inspected++;
    } else {
      inspected++;
    }

  } while (inspected < MAX_PLANTS && ripeFruits < MAX_FRUITS);

  printf("\nInspection results:\n Inspected: %d\n Ripe fruits: %d\n", inspected,
         ripeFruits);

  return 0;
}

bool isMatch(int pressureSensor, int colorSensor) {

  return (pressureSensor == 1 && colorSensor == 1);
}
