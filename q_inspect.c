#include <stdbool.h>
#include <stdio.h>

#define MAX_REJECTED 10

bool isOkPart(float weigth, int diameter, int hardness);

bool alertMode(int consecRejections);

bool exitProgram(float weigth, int diameter, int hardness);

int main(void) {

  float weigth;
  int diameter, hardness, qualifiedParts = 0, rejectedParts = 0,
                          inspectedParts = 0, consecRejections = 0;
  bool exit;
  bool alert;

  do {
    printf("\nWELCOME TO Q-INSPECT!\n");
    printf("Enter the weight: ");
    scanf("%f", &weigth);
    printf("Enter the diameter: ");
    scanf("%d", &diameter);
    printf("Enter the hardness: ");
    scanf("%d", &hardness);

    exit = exitProgram(weigth, diameter, hardness);

    if (!exit) {
      if (isOkPart(weigth, diameter, hardness)) {
        qualifiedParts++;
        consecRejections = 0;
      } else {
        rejectedParts++;
        consecRejections++;
      }
      inspectedParts++;
    }

    alert = alertMode(consecRejections);
  } while (!alert && !exit);

  alert ? printf("\nCAUTION: ALERT MODE ACTIVATED\n")
        : printf("\nProgram terminated normally\n");

  exit ? printf("\nSee you next time!\n")
       : printf(
             "\nResults\n inspectedParts: %d\n Qualified Parts: %d\n Rejected "
             "Parts: %d\n",
             inspectedParts, qualifiedParts, rejectedParts);

  return 0;
}

bool isOkPart(float weigth, int diameter, int hardness) {
  return (weigth >= 50 && (diameter >= 10 && diameter <= 20) && hardness >= 70);
}

bool alertMode(int consecRejections) { return consecRejections > MAX_REJECTED; }

bool exitProgram(float weigth, int diameter, int hardness) {
  return (weigth == 0 && diameter == 0 && hardness == 0);
}
