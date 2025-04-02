#include <stdio.h>

int main(void){
    
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    for(int i=1; i <= 100; i++){

        if (number %3 == 0 && number %5 == 0) {
            printf("FizzBuz");
        }else if (number %3 == 0) {
            printf("Fizz");
        }else if (number %5 == 0 && number %5 == 0) {
            printf("Buz");

        }
    }

    return 0;
}
