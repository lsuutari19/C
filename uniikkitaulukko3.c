#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ARR_LEN (100)


int arrShuffle(const int orig[], int new[], size_t len);
int makeArray(int arr[], size_t len);

int arrShuffle(const int orig[], int new[], size_t len) {
    
    // shuffle array
    for(int j=0; j<20; j++) {
        int randInd = (rand() % 20);
        int temp = orig[j];
        orig[j] = orig[randInd];
        orig[randInd] = temp;
    }
    
    for(int k=0;k<20;k++) {
        printf("%d\n", arr[k]);
    }
}

int makeArray(int arr[], size_t len) {
    // make array of 1-20
    for(int i=0; i < 20; i++) {
        arr[i] = i + 1;
    }
    return arr;
}

int main() {
    int arr[ARR_LEN];
    srand(time(NULL));
    makeArray(arr, ARR_LEN);
    orgArr = makeArray();

//    arrShuffle(orgArr);
    free(orgArr);
    return 0;
}