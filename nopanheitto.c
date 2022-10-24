#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand(void);
void printResult(int *array);

void printResult(int *array) {
    
    printf("Summa	Lukumaara\n");
    for(int j=2; j <= 12; j++) {
        if(j < 10) {
            printf("     %d        %d\n", j, array[j]);
        } else {
            printf("    %d        %d\n", j, array[j]);
        }
        
    }
    printf("YHTEENSA:    36000");

}



int main() {
    time_t t;
    int arr[13]= { 0 }, randnum1, randnum2, randsum;

    srand(time(NULL));
    for(int i=1; i <= 36000; i++) {

        // generate number between 1-6 twice
        randnum1 = (rand() % 6) + 1;
        randnum2 = (rand() % 6) + 1;

        randsum = randnum1 + randnum2;
//        printf("%d\n", randsum);
        arr[randsum] += 1;
    }
    printResult(arr);
    
}