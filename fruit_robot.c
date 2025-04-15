#include <stdio.h>

#define MAX_BATTERY 100

int mainMenu();
void program(int *battery);
void manageBattery(int opt, int *battery);
void checkBatteryRange(int *battery, int batteryToUpdate);

int main(void) {

  int battery = MAX_BATTERY;

  program(&battery);

  return 0;
}

int mainMenu() {
  int opt;

  printf("\nFRUIT ROBOT\n");
  printf(
      "\n1. Pick up fruit\n2. Charge battery\n3. On hold\n4. Shutdown robot");
  printf("\nSelect an option: ");
  scanf("%d", &opt);

  return opt;
}

void program(int *battery) {
  int opt;
  do {

    opt = mainMenu();

    switch (opt) {
    case 1:
    case 2:
    case 3:
      manageBattery(opt, battery);
      printf("\nCurrent battery: %d\n", *battery);
      break;
    case 4:
      break;
    default:
      printf("\nInvalid option\n");
      break;
    }

  } while (opt != 4 && *battery > 0);
}

void checkBatteryRange(int *battery, int batteryToUpdate) {
  if (batteryToUpdate >= 0 && batteryToUpdate <= MAX_BATTERY) {

    *battery = batteryToUpdate;

  } else {

    printf("\nInvalid operation\n");
  }
}

void manageBattery(int opt, int *battery) {
  int batteryToUpdate = 0;

  switch (opt) {
  case 1:
    batteryToUpdate = *battery - 20;
    checkBatteryRange(battery, batteryToUpdate);
    break;

  case 2:
    batteryToUpdate = *battery + 30;
    checkBatteryRange(battery, batteryToUpdate);
    break;

  case 3:
    batteryToUpdate = *battery - 10;
    checkBatteryRange(battery, batteryToUpdate);
    break;
  default:
    break;
  }
}
