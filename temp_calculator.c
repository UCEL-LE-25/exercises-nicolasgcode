#include <stdio.h>


int temps[7] = {18, 17, 20, 23, 22, 24, 25};

int main(void){

    float acum = 0;
    float average;
    int daysAboveAverage = 0;

    for (int i=0; i < temps.size(); i++) {
        acum += temps[i];
    }

    average = acum / 7;

    for (int i = 0; i < sizeof(temps); i++) {
    
        if (temps[i] > average){
            daysAboveAverage++;
        }
    }

    printf("\nResults:\n Average temp in the last 7 days: %.2f\n Days above average temp: %d", average, daysAboveAverage);

    return 0;
}
