#include <stdio.h>
#include <stdbool.h>

bool isValidNumber(int guess);

const int RANDOM_NUMBER = 50;

int main(void){

    int guess;

    int attemps = 5;

    int won = 0;
               
        do {
            printf("Guess the number: ");
            scanf("%d", &guess);
            if (isValidNumber(guess)){
             if (guess > RANDOM_NUMBER) {
                    printf("\nToo high\n");
                    attemps--;
                    printf("Attemps left: %d", attemps);
                }else if (guess < RANDOM_NUMBER) {
                    printf("\nToo low\n");
                    attemps--;
                    printf("Attemps left: %d", attemps);
                }else {
                    printf("You won!");
                    won = 1;          
             
           }}while (attemps != 0 && won == 0);   
          }
}


bool isValidNumber(guess){
    return (guess >= 1 && guess <= 100);
}
