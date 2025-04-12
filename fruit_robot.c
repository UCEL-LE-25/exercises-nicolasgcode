#include <stdbool.h>
#include <stdio.h>

#define MAX_BATTERY 100

void mainMenu(void);
void menuActions(int opt);
int manageBattery(int opt);
int checkBatteryRange(int batteryToUpdate);

int main(void) {

  mainMenu();

  return 0;
}

void mainMenu(void) {
  int opt;

  printf("\nFRUIT ROBOT\n");
  printf(
      "\n1. Pick up fruit\n2. Charge battery\n3. On hold\n4. Shutdown robot");
  printf("\nSelect an option: ");

  scanf("%d", &opt);

  menuActions(opt);
}

void menuActions(int opt) {
  do {

    switch (opt) {
    case 1:
      manageBattery(opt);
      break;
    case 2:
      manageBattery(opt);
      break;
    case 3:
      manageBattery(opt);
    case 4:
      break;
    }

  } while (opt != 4 && currentBattery > 0);
}

int checkBatteryRange(int batteryToUpdate) {
  int currentBattery;
  if (0 < batteryToUpdate && batteryToUpdate < MAX_BATTERY) {

    currentBattery = batteryToUpdate;

    return currentBattery;

  } else {

    printf("No se pudo realizar la operacion");
  }
}

int manageBattery(int opt) {

  int initialBattery = MAX_BATTERY;
  int currentBattery = 0;
  int batteryToUpdate = 0;

  switch (opt) {
  case 1:
    batteryToUpdate = initialBattery - 20;
    currentBattery = checkBatteryRange(batteryToUpdate);
    break;

  case 2:
    batteryToUpdate = initialBattery + 30;
    currentBattery = checkBatteryRange(batteryToUpdate);
    break;

  case 3:
    batteryToUpdate = initialBattery - 10;
    currentBattery = checkBatteryRange(batteryToUpdate);
    break;

    printf("Current battery: %d", currentBattery);

    return currentBattery;
  }
}
