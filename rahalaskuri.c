#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int pay;
    int one;
    int two;
    int five;
    int ten;
    int twenty;
    int fifty;
    int hundred;
    int twohund;
    int fivehund;
} workers;


int addWorker(workers *t);



int addWorker(workers *t) {
    char buffer[MAX_SIZE];

    printf("Anna tyontekijan palkka > ");
    fgets(buffer, sizeof(buffer), stdin);
    t->pay = atoi(buffer);
    return 0;
}


int main() {
    int numOfWorkers = 5, wage=0, fiveH, twoH, oneH, fif, twe, ten, five, two, one;
    int coins[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    workers work[MAX_SIZE] = {{}};

    for(int i = 0; i < numOfWorkers; i++) {
        addWorker( &work[i]);
    }
    printf("\n      %5d %5d %5d %5d %5d %5d %5d %5d %5d\n", 500, 200, 100, 50, 20, 10, 5, 2, 1);

    for(int j = 0; j < numOfWorkers; j++) {
        wage = work[j].pay;
        do {
            while(wage >= 500) {
                work[j].fivehund += 1;
                coins[0] += 1;
                wage -= 500;
            }
            while(wage >= 200) {
                work[j].twohund += 1;
                coins[1] += 1;
                wage -= 200;
            }
            while(wage >= 100) {
                work[j].hundred += 1;
                coins[2] += 1;
                wage -= 100;
            }
            while(wage >= 50) {
                work[j].fifty += 1;
                coins[3] += 1;
                wage -= 50;
            }
            while(wage >= 20) {
                work[j].twenty += 1;
                coins[4] += 1;
                wage -= 20;
            }
            while(wage >= 10) {
                work[j].ten += 1;
                coins[5] += 1;
                wage -= 10;
            }
            while(wage >= 5) {
                work[j].five += 1;
                coins[6] += 1;
                wage -= 5;
            }
            while(wage >= 2) {
                work[j].two += 1;
                coins[7] += 1;
                wage -= 2;
            }
            while(wage >= 1) {
                work[j].one += 1;
                coins[8] += 1;
                wage -= 1;
            }
            printf("%5d %5d %5d %5d %5d %5d %5d %5d %5d %5d\n",work[j].pay, work[j].fivehund, work[j].twohund, work[j].hundred, work[j].fifty, work[j].twenty, work[j].ten, work[j].five, work[j].two, work[j].one);

            break;
        } while (1);    
    }
    printf("      ");
    for(int j=0; j<9; j++) {
        printf("%5d ",coins[j]);
    }
    return 0;
}

